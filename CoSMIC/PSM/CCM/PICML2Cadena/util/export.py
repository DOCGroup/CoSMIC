import os
import sys

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


#fetching commandline parameters. Expected first the transformation configuration file,
#then the PICML mga file and then the cadena_scenario xml file

#looking for help?
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

#bad invocation?
if (len(sys.argv)<4) :
    print 'Usage: export.py ConfigFile_of_Transformation.mga PICMLMgaFile.mga CadenaScenarioXMLFile.xml [-d | -dv]\n\
Or: export.py --help for extensive help'
    sys.exit(0)

quotes = '\"'
space = ' '
if ('-dv' in sys.argv) : debugflag = ' -dv'
elif ('-d' in sys.argv) : debugflag = ' -d'
else : debugflag = ''

purifiedparams = []
for el in sys.argv :
    if (el!='-d' and el!='-dv') : purifiedparams.append(el)

greinvocationcommand = 'gre.exe' + \
                       space + quotes+os.path.abspath(purifiedparams[1])+quotes + \
                       space + quotes+os.path.abspath(purifiedparams[2])+quotes + \
                       debugflag

print 'Invoking GRE.exe with the following commandline:\n\
_______________________________________________________________________________\n',\
greinvocationcommand,'\n\
-------------------------------------------------------------------------------\n'
os.system(greinvocationcommand)


