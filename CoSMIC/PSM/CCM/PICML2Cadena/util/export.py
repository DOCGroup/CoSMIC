import os
import sys

print ' ' #puts a newline

#fetch needed environment variables
gre_fullpathname = os.environ['GREAT_PATH'].rstrip('\\')+'\\bin\\GRE.exe'  #maybe not necessary because GReAT puts it into PATH
integration_picml2cadena_fullpath = os.environ['PICML2CADENA_PATH']

#everything was set up correctly?
if (integration_picml2cadena_fullpath=='') :
    print 'FATAL ERROR: PICML2CADENA_PATH environment variable not found!\nPlease set it to your PICML2Cadena path.\nExiting.'
    sys.exit(-1)

#let's see if the user is looking for troubles...
if (integration_picml2cadena_fullpath.find(' ')!=-1) : print 'Warning: To avoid troubles, put the PICML2Cadena directory in a path without whitespaces.\n\
Current value is:\n'+integration_picml2cadena_fullpath+'\nGoing ahead...\n'

integration_udm_fullpath = integration_picml2cadena_fullpath.rstrip('\\')+'\\Transformations\\Udm\\'  #this works regardless if the PICML2CADENA_PATH ends in '\' or not


#fetching parameters. Expected first the PICML mga file and then the cadena_scenario xml file

#Looking for help?
if ('--help' in sys.argv or '-h' in sys.argv) :
    print '''Extensive help:

Installation:
Please set environment variable PICML2CADENA_PATH pointing to your PICML2Cadena path. Whether ends with backslash or not is irrelevant
Putting the directory of export.py and import.py in PATH could also be handy.

Launching:
export.py ConfigFile_of_Transformation.mga PICMLMgaFile.mga CadenaScenarioXMLFile.xml [-d | -dv] : performs export
-d  : output debug information
-dv : outputs more debug information
The filenames can be relative or absolute. GRE will be invoked with absolute filenames in any case, as this avoids problems.

Use ``export.py --help'' to get this extensive help'''
    sys.exit(0)

#Bad invocation?
if (len(sys.argv)<4) :
    print 'Usage: '+sys.argv[0]+' ConfigFile_of_Transformation.mga PICMLMgaFile.mga CadenaScenarioXMLFile.xml [-d | -dv]\nOr'+sys.argv[0]+' --help for extensive help'
    sys.exit(0)

#Tries:
#print gre_fullpathname
#print integration_udm_fullpath
#print len(sys.argv)  #Like this you access to argv and its length. Length of argv is like in C.
#print os.path.abspath('goofy') #very useful!!

quotes = '\"'
space = ' '
greinvocationcommand = 'gre.exe' + \
                       space + quotes+os.path.abspath(sys.argv[1])+quotes + \
                       space + quotes+os.path.abspath(sys.argv[2])+quotes
if ('-dv' in sys.argv) : greinvocationcommand += ' -dv'
elif ('-d' in sys.argv) : greinvocationcommand += ' -d'

print 'Invoking GRE.exe with the following commandline:\n\
_______________________________________________________________________________\n',\
greinvocationcommand,'\n\
-------------------------------------------------------------------------------\n'
os.system(greinvocationcommand)

#Another way to do it is:
#(childstdin, childstdouterr) = os.popen4(greinvocationcommand)
#for line in childstdouterr.readlines() : print line,  #trailing comma avoids extra newline


