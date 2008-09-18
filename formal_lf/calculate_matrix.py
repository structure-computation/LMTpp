from LMT.include.codegen import *
import sys

def calculate_matrix( expr, unknown_symbols, unknown_test_symbols, subs={}, allow_surtension_coefficient=False, assume_non_linear=False, test=True, dont_want_to_add_KUn=False, use_subs_instead_of_diff = False ):
    M = []
    V = []

    # simplify(expr)
    linear = True
    if assume_non_linear:
        linear = False
    subs_lin = dict(zip(unknown_symbols     ,[number(0.0)]*len(unknown_symbols)))
    subs_tes = dict(zip(unknown_test_symbols,[number(0.0)]*len(unknown_symbols)))
    if test==False:
        unknown_test_symbols = unknown_symbols
    
    # if use_subs_instead_of_diff, substitution of vars (expr en test) with 0 and ones
    if use_subs_instead_of_diff:
        for test_unk in unknown_test_symbols:
            pM = []
            dexpr = expr.subs( test_unk, 1 ).subs_with_test(EM( subs_tes ))
            for expr_unk in unknown_symbols:
                m = dexpr.subs( expr_unk, 1 ).subs_with_test(EM( subs_lin )).subs_with_test(EM( subs ))
                pM.append( m )
            M.append( pM )
            if linear:
                V.append( dexpr.subs_with_test(EM( subs_lin )).subs_with_test(EM( subs )) )
            else:
                V.append( dexpr.subs_with_test(EM( subs )) )
    else: # -> differenciation
        for i in unknown_test_symbols:
            pM = []
            dexpr = expr.diff( i ).subs_with_test(EM( subs_tes ))
            # 
            for j in unknown_symbols:
                m = dexpr.diff(j).subs_with_test(EM(subs))
                pM.append( m )
                if assume_non_linear==False:
                    linear &= not ( m.subs_with_test(EM( subs_lin ))-m )
            M.append( pM )
            V.append( dexpr.subs_with_test(EM(subs)) )
    
        # for non linearities
        if linear:
            for i in range(len(unknown_test_symbols)):
                V[i] = - V[i].subs_with_test(EM( subs_lin ))
        else:
            if allow_surtension_coefficient:
                sur = symbol('surtension_coefficient','S_c')
            else:
                sur = 1
            for i in range(len(unknown_test_symbols)):
                V[i] = - V[i] * sur
                if dont_want_to_add_KUn == False:
                    for j in range(len(unknown_symbols)):
                        V[i] += M[i][j] * unknown_symbols[j]
                        
    return { 'M':matrix( M ), 'V':vector( V ), 'U':unknown_symbols }


def write_matrix( f, M, V, symmetric, indices, offsets, assemble_mat, assemble_vec, use_asm, asmout = None, asm_fname = "" ):
  cw = Write_code('T')
  for i in range(M.nb_rows()):
    if assemble_mat:
      for j in range(i*symmetric,M.nb_cols()):
        if M[i,j]:
          cw.add( M[i,j], 'f.matrices(Number<0>())(indices['+str(indices[i])+']+'+str(offsets[i])+',indices['+str(indices[j])+']+'+str(offsets[j])+')', Write_code.Add )
    if assemble_vec:
      if V[i]:
        cw.add( V[i], 'f.sollicitation[indices['+str(indices[i])+']+'+str(offsets[i])+']', Write_code.Add )
  if use_asm:
    f.write( cw.asm_caller( asm_fname ) )
    #
    asmout.write( 'global %s\n' % asm_fname )
    asmout.write( '%s:\n' % asm_fname )
    asmout.write( cw.to_asm() )
  else:
    f.write( cw.to_string() )


# 
def solve_iteration( residual, unknown_symbols, unknown_test_symbols, subs={}, allow_surtension_coefficient=False, assume_non_linear=False, dont_want_to_add_KUn=False, use_subs_instead_of_diff = False ):
    MV = calculate_matrix( residual, unknown_symbols, unknown_test_symbols, subs, allow_surtension_coefficient, assume_non_linear, dont_want_to_add_KUn, use_subs_instead_of_diff = self.use_subs_instead_of_diff )
    return MV['M'].inverse() * MV['V']
    