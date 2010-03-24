pressure = Variable( unknown=True, nb_der=1, default_value='380e6', unit='Pa' )
flow = Variable( interpolation='der_nodal', default_value='0.0', unit='1/s' )

permeability = Variable( interpolation='global', default_value='2e-10', unit='m^3*s/kg' )
inv_biot = Variable( interpolation='global', default_value='7.4074e-11', unit='1/Pa' ) # 7.4074e-11
coeff_biot = Variable( interpolation='global', default_value='0.78', unit='1' )

sigma = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='N/m^2' )
tr_epsilon = Variable( interpolation='der_nodal', default_value='0', unit='1', nb_der=1 )

def formulation():
  H = matrix( [[permeability*(i==j) for i in range(dim)] for j in range(dim)] )
  
  res = dot( mul( H, grad( pressure.expr ) ), grad( pressure.test ) )
  res += pressure.expr.diff(time) * inv_biot.expr * pressure.test
  
  res += coeff_biot.expr * pressure.test * tr_epsilon.expr
  return res * dV
