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
: forward_declaration_ (false),
  idl_file_generator_ (NULL)
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
            PICML::Visitor & visitor,
            bool forward_declaration)
{
  this->forward_declaration_ = forward_declaration;
  
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
  this->idl_order_proc_.visit_file (object, this->forward_declaration_);

  if (this->forward_declaration_)
  {
    this->idl_order_proc_.process_forward_declaration ();
    this->set_file_generator (reinterpret_cast<IDL_File_Generator *>(&visitor));
  }
  else
  {
    container_.clear ();
    this->idl_order_proc_.topological_sort (container_);
    this->visit_file_package (container_, visitor);
  }
}

//
// no_foward_declaration
//
bool IDL_File_Dependency_Processor::
no_forward_declaration (const Udm::Object o)
{
  return this->idl_order_proc_.no_forward_declaration (o);
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
  for (IDL_File_Ordering_Processor::VECTOR_IT it = container.rbegin (); it != container.rend (); it++)
  {
    o = boost::get (IDL_File_Ordering_Processor::Udm_Object (), this->idl_order_proc_.graph (), (*it));
    
    if (o.GetParent ().type () != PICML::File::meta)
      continue;
    else if (o.type () == PICML::Constant::meta)
      PICML::Constant::Cast (o).Accept (visitor);
    else if (o.type () == PICML::Alias::meta)
      PICML::Alias::Cast (o).Accept (visitor);
    else if (o.type () == PICML::Collection::meta)
      PICML::Collection::Cast (o).Accept (visitor);
    else if (o.type () == PICML::Exception::meta)
      PICML::Exception::Cast (o).Accept (visitor);
    else if (o.type () == PICML::Aggregate::meta)
      PICML::Aggregate::Cast (o).Accept (visitor);
    else if (o.type () == PICML::SwitchedAggregate::meta)
     PICML::SwitchedAggregate::Cast (o).Accept (visitor);
    else if (o.type () == PICML::ValueObject::meta)
     PICML::ValueObject::Cast (o).Accept (visitor);
    else if (o.type () == PICML::TemplatePackageInstance::meta)
      PICML::TemplatePackageInstance::Cast (o).Accept (visitor);
    else if (o.type () == PICML::Event::meta)
      PICML::Event::Cast (o).Accept (visitor);
    else if (o.type () == PICML::Object::meta)
      PICML::Object::Cast (o).Accept (visitor);
    else if (o.type () == PICML::PortType::meta)
      PICML::PortType::Cast (o).Accept (visitor);
    else if (o.type () == PICML::Component::meta)
      PICML::Component::Cast (o).Accept (visitor);
    else if (o.type () == PICML::ComponentFactory::meta)
      PICML::ComponentFactory::Cast (o).Accept (visitor);
    else if (o.type () == PICML::ConnectorObject::meta)
      PICML::ConnectorObject::Cast (o).Accept (visitor);
    else if (o.type () == PICML::Package::meta)
      PICML::Package::Cast (o).Accept (visitor);
    else if (o.type () == PICML::Boxed::meta)
      PICML::Boxed::Cast (o).Accept (visitor);
  }
}

//
// forward_declaration
//
bool IDL_File_Dependency_Processor::
forward_declaration (void)
{
  return this->idl_order_proc_.forward_declaration ();
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
// clear
//
void IDL_File_Dependency_Processor::
clear (void)
{
  return this->idl_order_proc_.clear ();
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
// visit_template_module
//
void IDL_File_Dependency_Processor::
visit_template_module (bool visit_template_module)
{
  this->idl_order_proc_.visit_template_module (visit_template_module);
}

//
// visit_all_forward_declaration
//
void IDL_File_Dependency_Processor::
visit_all_forward_declaration (const PICML::Package & package)
{
  if (this->idl_file_generator_)
    this->idl_order_proc_.visit_all (package, *(this->idl_file_generator_), true);
}

//
// set_file_generator
//
void IDL_File_Dependency_Processor::
set_file_generator (IDL_File_Generator * idl_file_generator)
{
  this->idl_file_generator_ = idl_file_generator;
}

}; // namespace IDL_GENERATOR
