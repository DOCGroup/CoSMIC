#ifndef MOBIES_CROSSLINKS_H
#define MOBIES_CROSSLINKS_H
// header file CrossLinks.h generated from diagram CrossLinks
// generated on Wed Jun 23 02:05:39 2004

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif

namespace PICML
{ 
	 class  Property;
	 class  invoke;
	 class  ComponentAssembly;
	 class  emit;
	 class  PublishConnector;
	 class  Component;
	 class  OutEventPort;
	 class  ProvidedRequestPort;
	 class  RequiredRequestPort;
	 class  InEventPort;
	 class  Port;
};
namespace PICMLCadena_Xchange_embedded_EIProperties
{ 
	 class  RootContainer;
};
namespace cadena_scenario
{ 
	 class  FRConnection;
	 class  ESSConnection;
	 class  EventSink;
	 class  EventSource;
	 class  Receptacle;
	 class  Facet;
	 class  ComponentPort;
	 class  Property;
	 class  ComponentInstance;
	 class  Scenario;
};


namespace CrossLinks {


	  void Initialize();

	  void Initialize(const Uml::Diagram &dgr);
	extern  Udm::UdmDiagram diagram;

}

#endif //MOBIES_CROSSLINKS_H
