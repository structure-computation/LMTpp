temperature = Variable( unknown=True, nb_der=0, default_value='0.0', unit='K' )
Q = Variable( default_value='0.0', unit='K/s' )
Qs = Variable( interpolation='nodal', default_value='0.0', unit='K/s' )

density = Variable( interpolation='global', default_value='3160.0', unit='kg/m^3' )
heat_capacity = Variable( interpolation='global', default_value='1100.0', unit='J/kg/K' )
thermal_conductivity = Variable( interpolation='global', default_value='1.5', unit='W/m/K' )

H  = Variable( interpolation='skin_elementary', default_value='0.0', unit='W/m^2/K' )
t0 = Variable( interpolation='global', default_value='0', unit='K' )

H2 = Variable( interpolation='elementary', nb_dim=[3], default_value='0.0', unit='W/m^2/K' )
H3 = Variable( interpolation='elementary', nb_dim=[3], default_value='0.0', unit='W/m^2/K' )
#epslopigh = Variable( interpolation='gauss', default_value='500', nb_dim=[6], unit='K' )

TOTO = Variable( interpolation='elementary', T="float", default_value='0.0', unit='W/m^2/K' )

left_time_integration  = 0
right_time_integration = 1


#
def formulation():
  #sys.stderr.write( str( epslopigh.expr ) )
  
  a = thermal_conductivity.expr / ( density.expr * heat_capacity.expr ) # 'a' est la diffusivite thermique en m^2/s (ici a=4.3153e-07 m^2/s)
  # k = heat_capacity.expr*thermal_conductivity.expr #
  t,te = temperature.expr, temperature.test

  res = dot( a * grad(t), grad(te) ) + ( t.diff(time) - Q.expr ) * te * 0
  
  return res * dV + H.expr * ( t - t0.expr ) * te * dS - Qs.expr * te * dN
  
  
  
# ).subs( time, time_steps[0] )
#  + ( pos.expr[2] ) * ( pos.expr[0] < 1e-6 ) * te * dS + 
# therm_penalty = Variable( interpolation='global', default_value='1e6', unit='1' )
# contact_temperature = ISVariable( default_value='600', unit='K' )
# #
# def IS_contact_formulation(): return therm_penalty.expr * temperature.test * ( temperature.expr - contact_temperature.expr )
# def elem_contact_formulation(ve): return number(0)



