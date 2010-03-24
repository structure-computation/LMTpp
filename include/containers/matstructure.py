# matstructure = {
#     'Diag' : {
#         'val' : [ ('line==column','','data[line]',''),('','','','') ],
#     }
#     'Sym' : {
#         'val' : [ 
#             ('I1>=I2','unsigned ri=I1/alignement;','data[ri*(ri+1)/2*alignement*alignement + (I1 % alignement)*(ri+1)*alignement + I2]',''),
#             ('','unsigned ri=I1/alignement;','data[ri*(ri+1)/2*alignement*alignement + (I2 % alignement)*(ri+1)*alignement + I1]','') 
#         ],
#     }
#     'Herm' : {
#         'val' : [ 
#             ('I1>=I2','unsigned ri=I1/alignement;','data[ri*(ri+1)/2*alignement*alignement + (I1 % alignement)*(ri+1)*alignement + I2]',''),
#             ('','unsigned ri=I1/alignement;','data[ri*(ri+1)/2*alignement*alignement + (I2 % alignement)*(ri+1)*alignement + I1]','cond') 
#         ],
#     }
#     'TriUpper' : {
#         'val' : [ 
#             ('line<=column','unsigned ri=I1/alignement;','data[ri*(ri+1)/2*alignement*alignement + (I1 % alignement)*(ri+1)*alignement + I2]',''),
#             ('','','','') 
#         ],
#     }
#     'TriLower' : {
#     }
# }
class MatStructure:
    def __init__(self,cond='',index=''):
        self.cond = cond
        self.index = index

matstructure = {}
matstructure['Diag'] = [
    MatStructure( cond='line==column' ),
]
