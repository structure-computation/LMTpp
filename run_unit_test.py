# -*- coding: utf-8 -*-
import os, stat, time

def create_html_link( href, text ):
    return '<a href="' + href + '" > ' + text + ' </a>'

def create_html_image( href, alt='' ):
    return '<img src="' + href + '" alt="' + alt + '"> '

def extract_function( s ):
    i = s.find( '(' )
    if (i >=0):
        j = s.find( ')', i+1 )
        if (j >=0):
            return s[0: j+1]
        else:
            return '??????'
    else:
        return '??????'

def extract_leaf( s ):
    i = s.rfind( '/' )
    if (i >= 0):
        return s[i+1: ]
    else:
        return s

class Tests:
    def __init__( self, namefile_html, title_web_page, list_dir_include = [] ):
        self.res = True
        self.html = file( namefile_html, "w" )
        self.html.write('<!DOCTYPE html PUBLIC "-//W3C//DTDXHTML 1.0 Strict//EN" "DTD/xhtml1-strict.dtd">\n<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr">\n<head>\n<META HTTP-EQUIV="CONTENT-TYPE" CONTENT="text/html; charset=utf-8">\n<title>' + title_web_page + '</title>\n</head>\n<body text="#000000" bgcolor="#ffffff" link="#0000cc" vlink="#551a8b" >\n' )
        self.icon = [ 'red.png', 'green.png' ] 
        self.command = 'metil_comp --comp-dir tests/compilation '
        for dir in list_dir_include:
            self.command += ' -I' + dir + ' '

    def __del__( self ):
        self.html.write('\n<br>\n<br>\n<br>\n<br>\n<br>\n<br>\n<br>\n</body>\n</html>\n\n' )

    def find_and_exec( self, directory ):
        for filename_ in os.listdir( directory ):
            filename = directory + "/" + filename_
            if stat.S_ISDIR( os.stat( filename )[ stat.ST_MODE ] ):
                self.find_and_exec( filename )
            elif filename[-4:] == ".cpp": 
                filename_log = filename[:-4] + ".log"
                filename_log_cerr = filename[:-4] + ".log_cerr"
                os.system( "rm -rf tests/compilation" )
                cmd = self.command + filename + " > " + filename_log + " 2> " + filename_log_cerr
                local_res = os.system( cmd )
                print filename, local_res
                if (local_res == 0): # compilation réussie
                    entree = open( filename_log, 'r' )
                    tokens = entree.read().split()
                    nb_tokens = len ( tokens )
                    k = 0
                    while ( k < nb_tokens ):
                        if (tokens[k] == '__UNIT_TESTING_REPORT__'):
                            self.html.write( '\t<tr>\n\t\t<td>' + create_html_link( filename, filename ) + ' </td> <td> ' + create_html_image( self.icon[1], 'OK' ) + ' </td> <td> ' +  extract_function( tokens[k+1] ) + ' </td> ' )
                            ### Nous cherchons ensuite le token >=>=>=> sur la ligne puis sur les lignes suivantes
                            k = k + 2
                            while ( k < nb_tokens ):
                                if (tokens[k] == '>=>=>=>' ):
                                    if ( tokens[k+1] == 'OK' ):
                                        j = 1
                                    else:
                                        j = 0
                                    self.res &= j
                                    self.html.write( '<td>' + create_html_image( self.icon[j], tokens[k+1] ) + '</td> <td> ' + create_html_link( filename_log, filename_log ) + ' </td> <td> ' + create_html_link( filename_log_cerr, filename_log_cerr ) + ' </td>\n\t</tr>\n' )
                                    k = k + 1
                                    break
                                k = k + 1
                        k = k + 1
                    entree.close()
                else: # echec de la compilation
                    self.html.write( '\t<tr>\n\t\t<td>' + create_html_link( filename, filename ) + ' </td> <td> ' + create_html_image( self.icon[0], 'FAIL' ) +  ' </td> <td> </td> <td> </td> <td> ' + create_html_link( filename_log, filename_log ) + ' </td> <td> ' + create_html_link( filename_log_cerr, filename_log_cerr ) + ' </td>\n\t</tr>\n' )
                    self.res = False

    def run( self, directory ):
        self.html.write('\n\n<table border=1>\n\t<caption> Results </caption>\n\t<tr>\n\t\t<th> Source File Test </th> <th> Compilation </th> <th> Test </th> <th> Result </th> <th> Log File </th> <th> Log Cerr File </th>\n\t</tr>\n' )
        self.find_and_exec( directory )
        self.html.write( '</table>\n<br>\n' )
        self.html.write( '<br> Date : ' + time.asctime() + '\n<br>\n' )
        self.html.write( '<br> Global Result '+ create_html_image( self.icon[ self.res ], str(self.res ))+'\n<br>' )
    
t = Tests( "report_test__LMT++.html", "report unit test for LMT++", ['include/', '/usr/include/', '/usr/include/libxml2/'] )

#os.system( "git pull" )
t.run( "tests" )
if t.res:
    print " Unit tests Succeeded :-)"
    #os.system( "ssh pasquier@romanee;cd /u/multi/lmtpp;git pull" )
else:
    print " Unit tests has failed :-( ... "
    ### ENVOI d'un courrier en cas d'erreur ###
    import smtplib
    fromaddr = 'cellog.lmt@gmail.com'
    toaddrs  = 'raphael.pasquier@lmt.ens-cachan.fr,hugo.leclerc@lmt.ens-cachan.fr'
    msg = 'Unit tests crash !'
    
    # Credentials (if needed)
    uti = 'cellog.lmt'
    mdp = 'laboratoire'
    
    # The actual mail send
    server = smtplib.SMTP( 'smtp.gmail.com:587' )
    server.starttls()
    server.login( uti, mdp )
    server.sendmail( fromaddr, toaddrs, msg )
    server.quit()
    

exit( t.res == 0 )

