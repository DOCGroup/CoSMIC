#ifndef MOBIES_CROSSLINKS_H
#define MOBIES_CROSSLINKS_H
// header file CrossLinks.h generated from diagram CrossLinks
// generated on Mon Jun 14 01:27:11 2004

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif

namespace PICML
{ 
	 class  PublishConnector;
	 class  ComponentAssembly;
	 class  emit;
	 class  invoke;
	 class  OutEventPort;
	 class  ProvidedRequestPort;
	 class  Component;
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
	 class  ESSConnection;
	 class  FRConnection;
	 class  EventSink;
	 class  EventSource;
	 class  Receptacle;
	 class  Facet;
	 class  ComponentPort;
	 class  ComponentInstance;
};


namespace CrossLinks {


	  void Initialize();

	  void Initialize(const Uml::Diagram &dgr);
	extern  Udm::UdmDiagram diagram;

}

#endif //MOBIES_CROSSLINKS_H
