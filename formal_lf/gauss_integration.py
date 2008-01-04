from LMT.include.codegen import *
import math

V = symbol("V")

gauss_points = {}

gauss_points[1] = [
  ( 1.0, { V : 1.0/2.0 } ),
]
gauss_points[3] = [
  ( 1.0/2.0, { V : (1.0-sqrt(1.0/3.0))/2.0 } ),
  ( 1.0/2.0, { V : (1.0+sqrt(1.0/3.0))/2.0 } ),
]
gauss_points[5] = [
  ( 8.0/18.0, { V : 1.0/2.0 } ),
  ( 5.0/18.0, { V : (1.0-sqrt(3.0/5.0))/2.0 } ),
  ( 5.0/18.0, { V : (1.0+sqrt(3.0/5.0))/2.0 } ),
]
s = math.sqrt(6.0/5.0)*2.0
#d = 1.0/s/6.0
gauss_points[7] = [
  ( (18.0+sqrt(30.0))/36.0, { V : (1.0+sqrt((3.0-s)/7.0))/2.0 } ),
  ( (18.0+sqrt(30.0))/36.0, { V : (1.0-sqrt((3.0-s)/7.0))/2.0 } ),
  ( (18.0-sqrt(30.0))/36.0, { V : (1.0+sqrt((3.0+s)/7.0))/2.0 } ),
  ( (18.0-sqrt(30.0))/36.0, { V : (1.0-sqrt((3.0+s)/7.0))/2.0 } ),
]
#s = math.sqrt(6.0/5.0)*2.0
#d = 1.0/s/6.0
#gauss_points[7] = [
  #( (1.0+d)/4.0, { V : (1.0+sqrt((3.0-s)/7.0))/2.0 } ),
  #( (1.0+d)/4.0, { V : (1.0-sqrt((3.0-s)/7.0))/2.0 } ),
  #( (1.0-d)/4.0, { V : (1.0+sqrt((3.0+s)/7.0))/2.0 } ),
  #( (1.0-d)/4.0, { V : (1.0-sqrt((3.0+s)/7.0))/2.0 } ),
#]
gauss_points[9] = [
  ( 128.0/225.0, { V : 1.0/2.0 } ),
  ( number("0.478628670499366468")/2.0, { V : (1.0+number("0.538469310105683"))/2.0 } ),
  ( number("0.478628670499366468")/2.0, { V : (1.0-number("0.538469310105683"))/2.0 } ),
  ( number("0.236926885056189")/2.0, { V : (1.0+number("0.906179845938664"))/2.0 } ),
  ( number("0.236926885056189")/2.0, { V : (1.0-number("0.906179845938664"))/2.0 } ),
]
gauss_points[11] = [ 
  ( number("0.467913934572691")/2.0, { V : (1.0+number("0.238619186083197"))/2.0 } ),
  ( number("0.467913934572691")/2.0, { V : (1.0-number("0.238619186083197"))/2.0 } ),
  ( number("0.360761573048139")/2.0, { V : (1.0+number("0.661209386466265"))/2.0 } ),
  ( number("0.360761573048139")/2.0, { V : (1.0-number("0.661209386466265"))/2.0 } ),
  ( number("0.171324492379170")/2.0, { V : (1.0+number("0.932469514203152"))/2.0 } ),
  ( number("0.171324492379170")/2.0, { V : (1.0-number("0.932469514203152"))/2.0 } ),
]

def gauss_integration(expr,order,var,beg,end):
  if type(expr) is float or type(expr) is int: expr = number(expr)
  res = 0.0
  expr = expr.subs(EM( { var : V*(end-beg)+beg } ))
  k = min( filter(lambda x:x>=order,gauss_points.keys()) )
  for w,p in gauss_points[k]:
    mp = {}
    for k,v in p.items():
        if type(v) is float or type(v) is int: mp[k] = number(v)
        else: mp[k] = v
    res += w * expr.subs(EM(mp))
  return res
