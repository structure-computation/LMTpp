pressure = Variable( unknown=True, nb_der=2, default_value='0.0', unit='Pa' )
flow = Variable( interpolation='der_nodal', default_value='0.0', unit='1/s' )

permeability = Variable( interpolation='global', default_value='2e-10', unit='m^3*s/kg' )
inv_biot = Variable( interpolation='global', default_value='7.4074e-11', unit='1/Pa' )
coeff_biot = Variable( interpolation='global', default_value='0.78', unit='1' )

sigma = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='N/m^2' )
epsilon = Variable( interpolation='der_nodal', default_value='0', nb_dim=[dim*(dim+1)/2], unit='1', nb_der=2 )


def formulation():
  H = matrix( [[permeability*(i==j) for i in range(dim)] for j in range(dim)] )
  m = mul( H, grad( pressure.expr ) )
  res = dot( m, grad( pressure.test ) )
  res += pressure.expr.diff(time) * inv_biot.expr * pressure.test
  
  treps = sum([ epsilon.diff(time)[i] for i in range(dim)])
  
  res += coeff_biot.expr * pressure.test * treps
  return res * dV
