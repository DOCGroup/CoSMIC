#ifndef MOBIES_CROSSLINKS_H
#define MOBIES_CROSSLINKS_H
// header file CrossLinks.h generated from diagram CrossLinks
// generated on Tue May 11 01:39:25 2004

#ifndef MOBIES_UDMBASE_H
#include "UdmBase.h"
#endif

namespace PICML
{ 
	 class  RequestPort;
	 class  EventPort;
	 class  ProvidedRequestPort;
	 class  RequiredRequestPort;
	 class  OutEventPort;
	 class  InEventPort;
	 class  Port;
};
namespace cadena_scenario
{ 
	 class  EventSource;
	 class  EventSink;
	 class  Receptacle;
	 class  Facet;
	 class  ComponentPort;
};


namespace CrossLinks {

	typedef Udm::Object Object;


	  void Initialize();

	  void Initialize(const Uml::Diagram &dgr);
	extern  Udm::UdmDiagram diagram;

}

#endif //MOBIES_CROSSLINKS_H
