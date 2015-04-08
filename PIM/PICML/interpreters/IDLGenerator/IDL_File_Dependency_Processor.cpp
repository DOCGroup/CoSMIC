#include "StdAfx.h"

#include "IDL_File_Dependency_Processor.h"

struct visit_all
{
public:
template <typename T>
void operator () (T & collection, PICML::Visitor * visitor) const
{
  for (auto item : collection)
    item->accept (visitor);
}
};

//
// IDL_File_Dependency_Processor
//
IDL_File_Dependency_Processor::IDL_File_Dependency_Processor (void)
: forward_declaration_ (false),
  idl_file_generator_ (0)
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
visit_file (const GAME::Mga::Object & object,
            PICML::Visitor & visitor,
            bool forward_declaration)
{
  this->forward_declaration_ = forward_declaration;
  this->visit_file_package (object, visitor);
}

//
// visit_file_package
//
void IDL_File_Dependency_Processor::
visit_file_package (const GAME::Mga::Object_in object, PICML::Visitor & visitor)
{
  this->idl_order_proc_.visit_file (object, this->forward_declaration_);

  if (this->forward_declaration_)
  {
    this->idl_order_proc_.process_forward_declaration ();
    this->file_generator (reinterpret_cast<IDL_File_Generator *>(&visitor));
  }
  else
  {
    this->container_.clear ();
    this->idl_order_proc_.topological_sort (this->container_);
    this->visit_file_package (this->container_, visitor);
  }
}

//
// no_foward_declaration
//
bool IDL_File_Dependency_Processor::
no_forward_declaration (const GAME::Mga::Object_in o)
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
  GAME::Mga::Object o;

  // visit the objects in dependency order
  for (IDL_File_Ordering_Processor::VECTOR_IT it = container.rbegin (); it != container.rend (); it++)
  {
    o = boost::get (IDL_File_Ordering_Processor::Object (), this->idl_order_proc_.graph (), (*it));

    if (o->parent ()->meta ()->name () != PICML::File::impl_type::metaname)
      continue;
    else if (o->meta ()->name () == PICML::Constant::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::Alias::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::Collection::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::Exception::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::Aggregate::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::SwitchedAggregate::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::ValueObject::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::TemplatePackageInstance::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::Event::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::Object::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::PortType::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::Component::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::ComponentFactory::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::ConnectorObject::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::Package::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::Boxed::impl_type::metaname)
      o->accept (&visitor);
    else if (o->meta ()->name () == PICML::Enum::impl_type::metaname)
      o->accept (&visitor);
  }
}

//
// forward_declaration
//
bool IDL_File_Dependency_Processor::forward_declaration (void)
{
  return this->idl_order_proc_.forward_declaration ();
}

//
// visit_template_module
//
bool IDL_File_Dependency_Processor::visit_template_module (void)
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
// visit_package
//
void IDL_File_Dependency_Processor::
visit_package (const PICML::Package & p, PICML::Visitor & visitor)
{
  visit_all () (p->get_Constants (), &visitor);
  visit_all () (p->get_Aliass (), &visitor);
  visit_all () (p->get_Collections (), &visitor);
  visit_all () (p->get_Exceptions (), &visitor);
  visit_all () (p->get_Enums (), &visitor);
  visit_all () (p->get_Aggregates (), &visitor);
  visit_all () (p->get_SwitchedAggregates (), &visitor);
  visit_all () (p->get_ValueObjects (), &visitor);
  visit_all () (p->get_TemplatePackageInstances (), &visitor);
  visit_all () (p->get_PortTypes (), &visitor);
  visit_all () (p->get_Events (), &visitor);
  visit_all () (p->get_Objects (), &visitor);
  visit_all () (p->get_ManagesComponents (), &visitor);
  visit_all () (p->get_Components (), &visitor);
  visit_all () (p->get_ComponentFactorys (), &visitor);
  visit_all () (p->get_ConnectorObjects (), &visitor);
  visit_all () (p->get_Boxeds (), &visitor);
  visit_all () (p->get_Packages (), &visitor);
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
visit_all_forward_declaration (PICML::Package_in package)
{
  if (this->idl_file_generator_)
    this->idl_order_proc_.visit_package (package, this->idl_file_generator_);
}

//
// file_generator
//
void IDL_File_Dependency_Processor::
file_generator (IDL_File_Generator * idl_file_generator)
{
  this->idl_file_generator_ = idl_file_generator;
}
