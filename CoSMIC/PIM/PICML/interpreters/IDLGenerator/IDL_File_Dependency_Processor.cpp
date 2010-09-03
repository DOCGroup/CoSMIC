// $Id$

#include "StdAfx.h"

#include "IDL_File_Dependency_Processor.h"
#include "Utils/UDM/visit.h"

namespace IDL_GENERATOR
{
//
// IDL_File_Dependency_Processor
//
IDL_File_Dependency_Processor::IDL_File_Dependency_Processor (void)
{
}

//
// ~IDL_File_Dependency_Processor
//
IDL_File_Dependency_Processor::~IDL_File_Dependency_Processor (void)
{
}

//
// visit_file
//
void IDL_File_Dependency_Processor::
visit_file (const Udm::Object & object,
            PICML::Visitor & visitor)
{
  this->visit_file_package (object,
                            visitor);
}

//
// visit_file_package
//
void IDL_File_Dependency_Processor::
visit_file_package (const Udm::Object & object,
                    PICML::Visitor & visitor)
{
  this->idl_order_proc_.visit_file (object);
  
  IDL_File_Ordering_Processor::CONTAINER my_container;
  
  this->idl_order_proc_.topological_sort (my_container);
  
  this->visit_file_package (my_container, visitor);
}

//
// visit_file_package
//
void IDL_File_Dependency_Processor::
visit_file_package (const IDL_File_Ordering_Processor::CONTAINER & container,
                    PICML::Visitor & visitor)
{
  Udm::Object o;
  // visit the objects in dependency order
  for (IDL_File_Ordering_Processor::VECTOR_IT it = container.rbegin (); it != container.rend(); it++)
  {
    o = boost::get(IDL_File_Ordering_Processor::Udm_Object (), this->idl_order_proc_.graph (), (*it));
    
    if (Udm::IsDerivedFrom (o.type (), PICML::Constant::meta))
      PICML::Constant::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::Alias::meta))
      PICML::Alias::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::Collection::meta))
      PICML::Collection::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::Exception::meta))
      PICML::Exception::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::Aggregate::meta))
      PICML::Aggregate::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::SwitchedAggregate::meta))
     PICML::SwitchedAggregate::Cast (o).Accept (visitor);
     
    if (Udm::IsDerivedFrom (o.type (), PICML::ValueObject::meta))
     PICML::ValueObject::Cast (o).Accept (visitor);
     
    if (Udm::IsDerivedFrom (o.type (), PICML::TemplatePackageInstance::meta))
      PICML::TemplatePackageInstance::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::Event::meta))
      PICML::Event::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::Object::meta))
      PICML::Object::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::PortType::meta))
      PICML::PortType::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::Component::meta))
      PICML::Component::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::ComponentFactory::meta))
      PICML::ComponentFactory::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::ConnectorObject::meta))
      PICML::ConnectorObject::Cast (o).Accept (visitor);
      
    if (Udm::IsDerivedFrom (o.type (), PICML::Package::meta))
      PICML::Package::Cast (o).Accept (visitor);
  }
}

//
// visit_file_package
//
bool IDL_File_Dependency_Processor::
has_children(void)
{
  IDL_File_Ordering_Processor::CONTAINER my_container;
  
  this->idl_order_proc_.topological_sort (my_container);
  
  return (my_container.empty () == false);
}

//
// visit_template_module
//
bool IDL_File_Dependency_Processor::
visit_template_module (void)
{
  return this->idl_order_proc_.visit_template_module ();
}

//
// visit_all
//
void IDL_File_Dependency_Processor::
visit_all (const Udm::Object & o,
           PICML::Visitor & visitor)
{
  this->idl_order_proc_.visit_all (o, visitor);
}

//
// clear
//
void IDL_File_Dependency_Processor::
clear (void)
{
  this->idl_order_proc_.clear ();
}

//
// visit_template_module
//
void IDL_File_Dependency_Processor::
visit_template_module (bool visit_template_module)
{
  this->idl_order_proc_.visit_template_module (visit_template_module);
}

}; // namespace IDL_GENERATOR
