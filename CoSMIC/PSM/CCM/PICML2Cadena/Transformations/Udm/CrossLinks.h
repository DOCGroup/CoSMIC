#ifndef MOBIES_CROSSLINKS_H
#define MOBIES_CROSSLINKS_H
// header file CrossLinks.h generated from diagram CrossLinks
// generated on Tue Aug 10 16:33:38 2004

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif

namespace PICML
{ 
	 class  ComponentAssembly;
	 class  invoke;
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
