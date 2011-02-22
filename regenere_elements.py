
# script pour regenerer les fichier element_....h pour les elements courants (ceux definis dans formulations)
import os, sys
beg_elem_str = "element_"
for n in os.listdir( "formulations" ):
    l = n.find( beg_elem_str )
    if l != 0:
        continue
    e = n.rfind( ".py" )
    if e != len( n ) - 3:
        continue
    name_elem = n[ l + len( beg_elem_str ) : e ]
    print name_elem
    os.system( "export PYTHONPATH=`pwd`/..; python make_elem.py " + str( name_elem ) + " > include/mesh/element_" + str( name_elem ) + ".h" )