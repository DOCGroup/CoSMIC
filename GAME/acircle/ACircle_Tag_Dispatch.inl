// $Id:$
#include "Utils/UDM/visit.h"

namespace ACircle_Tag_Dispatch {

  namespace impl {
  
      /// vist all UDM
      template<typename T, typename Visitor>
      void visit_all (const T& o, Visitor & v, udm_tag)
      {
        Udm::visit_all <PICML::Constant> (o, v);
        Udm::visit_all <PICML::Alias> (o, v);
        Udm::visit_all <PICML::Collection> (o, v);
        Udm::visit_all <PICML::Exception> (o, v);
        Udm::visit_all <PICML::Aggregate> (o, v);
        Udm::visit_all <PICML::SwitchedAggregate> (o, v);
        Udm::visit_all <PICML::ValueObject> (o, v);
        Udm::visit_all <PICML::Attribute> (o, v);

        Udm::visit_all <PICML::TemplatePackageInstance> (o, v);

        Udm::visit_all <PICML::OnewayOperation> (o, v);
        Udm::visit_all <PICML::TwowayOperation> (o, v);
        
        Udm::visit_all <PICML::PortType> (o, v);
        Udm::visit_all <PICML::Event> (o, v);
        Udm::visit_all <PICML::Object> (o, v);
        
        Udm::visit_all <PICML::ManagesComponent> (o, v);
        Udm::visit_all <PICML::Component> (o, v);
        Udm::visit_all <PICML::ComponentFactory> (o, v);
        Udm::visit_all <PICML::ConnectorObject> (o, v);
        Udm::visit_all <PICML::Boxed> (o, v);
        
        Udm::visit_all <PICML::Package> (o, v);
      }
    } // impl namespace
} // ACircle namespace

