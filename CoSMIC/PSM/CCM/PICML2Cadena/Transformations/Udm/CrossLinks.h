#ifndef MOBIES_CROSSLINKS_H
#define MOBIES_CROSSLINKS_H
// header file CrossLinks.h generated from diagram CrossLinks
// generated on Fri Oct 08 20:10:51 2004

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif

namespace PICML
{ 
	 class  ComponentAssembly;
	 class  emit;
	 class  PublishConnector;
	 class  invoke;
	 class  Property;
	 class  InEventPort;
	 class  RequiredRequestPort;
	 class  ProvidedRequestPort;
	 class  OutEventPort;
	 class  Component;
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
