OCMLConfiguratorLibrary: (DLL Project)
	Contains the OCMLConfigurator user interface code. 

OCMLConfiguratorInterpreter: (GME Interpreter)
        Contains the interpreter registered with the PICML metamodel
        which displays the OCMLConfigurator GUI and sets the 
        ImplementationArtifact's configuration attribute.  

TAOServiceConfExporter: (DLL Project)
	Contains the library code which reads receives the XML values and
	exports the corresponding svc.conf.xml file.

TAOServiceConfExportInterpreter: (GME Interpreter)
	Contains the interpreter registered with the PICML metamodel which
	exports TAO ORB svc.conf.xml file according to the given values.

Configurator:  Obsolete

Common: Common files for the interpreters.

OCML_Interpreter: Interpreter for the OCML metamodel.
