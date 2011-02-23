from LMT.include.codegen import *

#
time = symbol("time","t")
system_time = symbol("syst_time","t_s")

symbols = []
time_steps = []
for i in range(16):
  symbols.append( symbol( "symbols[%i]"%i, "S_{%i}"%i ) )
  time_steps.append( symbol( "f.time_steps[%i]"%i, "T_{%i}"%i  ) )

# 
class Pol_extr:
  def __init__(self,order,assume_constant_time_step=False):
    self.assume_constant_time_step = assume_constant_time_step
    self.order = order
    
  def form(self):
    if self.order==0:
      return symbols[0]
    t = time_steps
    s = symbols
    not_ass = not self.assume_constant_time_step
    # lagrange extrapolation
    res = 0
    gact_time = t[0]
    for i in range(self.order+1):
      fact = number(1)
      act_time = t[0]
      for j in range(self.order+1):
        if i!=j:
          fact *= time-act_time
        act_time -= t[j * not_ass ]
      fact /= fact.subs(EM( { time : gact_time } ))
      res += fact * s[i]
      gact_time -= t[i*not_ass]
    return res

#
class Cos_extr:
   pass
