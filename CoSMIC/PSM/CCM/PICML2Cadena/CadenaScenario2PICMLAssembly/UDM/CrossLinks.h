#ifndef MOBIES_CROSSLINKS_H
#define MOBIES_CROSSLINKS_H
// header file CrossLinks.h generated from diagram CrossLinks
// generated on Fri Jun 18 06:06:50 2004

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif

namespace PICML
{ 
	 class  Property;
	 class  invoke;
	 class  emit;
	 class  ComponentAssembly;
	 class  PublishConnector;
	 class  Port;
	 class  ProvidedRequestPort;
	 class  RequiredRequestPort;
	 class  OutEventPort;
	 class  InEventPort;
	 class  Component;
};
namespace PICMLCadena_Xchange_embedded_EIProperties
{ 
	 class  RootContainer;
};
namespace cadena_scenario
{ 
	 class  FRConnection;
	 class  Property;
	 class  ESSConnection;
	 class  ComponentInstance;
	 class  ComponentPort;
	 class  Receptacle;
	 class  EventSource;
	 class  Facet;
	 class  EventSink;
	 class  Scenario;
};


namespace CrossLinks {


	  void Initialize();

	  void Initialize(const Uml::Diagram &dgr);
	extern  Udm::UdmDiagram diagram;

}

#endif //MOBIES_CROSSLINKS_H
