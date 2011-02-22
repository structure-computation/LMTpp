from include.codegen import *

class CD_IS:
  """Contact data with implicit shape """
  def __init__(self):
    self.imp_node = Vector([symbol('cd.imp_node[%i]'%i) for i in range(16)])
    
