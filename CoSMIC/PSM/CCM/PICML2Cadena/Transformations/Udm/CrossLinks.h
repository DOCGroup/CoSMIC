#ifndef MOBIES_CROSSLINKS_H
#define MOBIES_CROSSLINKS_H
// header file CrossLinks.h generated from diagram CrossLinks
// generated on Fri Jun 25 22:48:28 2004

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif

namespace PICML
{ 
	 class  Property;
	 class  Port;
	 class  InEventPort;
	 class  RequiredRequestPort;
	 class  ProvidedRequestPort;
	 class  OutEventPort;
	 class  Component;
	 class  PublishConnector;
	 class  emit;
	 class  ComponentAssembly;
	 class  invoke;
};
namespace PICMLCadena_Xchange_embedded_EIProperties
{ 
	 class  RootContainer;
};
namespace cadena_scenario
{ 
	 class  ComponentInstance;
	 class  Scenario;
	 class  Property;
	 class  ComponentPort;
	 class  Facet;
	 class  Receptacle;
	 class  EventSource;
	 class  EventSink;
	 class  FRConnection;
	 class  ESSConnection;
};


namespace CrossLinks {


	  void Initialize();

	  void Initialize(const Uml::Diagram &dgr);
	extern  Udm::UdmDiagram diagram;

}

#endif //MOBIES_CROSSLINKS_H
