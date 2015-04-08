#include "StdAfx.h"
#include "Find_Forward_Decls.h"
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

template <typename BASE>
struct derives_from
{
public:
template <typename T>
bool operator () (const T & derived) const
{
  try
  {
    BASE base = BASE::_narrow (derived);
    return true;
  }
  catch (GAME::Mga::Exception &)
  {
    return false;
  }
}
};

//
// Find_Forward_Decls
//
Find_Forward_Decls::
Find_Forward_Decls (IDL_File_Dependency_Processor & depends_graph,
                    bool visit_template_module)
: depends_graph_ (depends_graph),
  has_component_ (false),
  has_typesupport_ (false),
  has_ami4ccm_ (false),
  visit_template_module_ (visit_template_module)
{

}

//
// ~Find_Forward_Decls
//
Find_Forward_Decls::~Find_Forward_Decls (void)
{

}

//
// clear
//
void Find_Forward_Decls::clear (void)
{
  this->fwd_decls_.clear ();
  this->includes_.clear ();

  this->has_component_ = false;
  this->has_typesupport_ = false;
  this->has_ami4ccm_ = false;
}

//
// has_component
//
bool Find_Forward_Decls::has_component (void) const
{
  return this->has_component_;
}

//
// has_typesupport
//
bool Find_Forward_Decls::has_typesupport (void) const
{
  return this->has_typesupport_;
}

//
// has_ami4ccm
//
bool Find_Forward_Decls::has_ami4ccm (void) const
{
  return this->has_ami4ccm_;
}

//
// fwd_decls
//
const Find_Forward_Decls::fwd_decls_t &
Find_Forward_Decls::fwd_decls (void) const
{
  return this->fwd_decls_;
}

//
// includes
//
const Find_Forward_Decls::includes_t & Find_Forward_Decls::includes (void) const
{
  return this->includes_;
}

//
// visit_File
//
void Find_Forward_Decls::visit_File (PICML::File_in file)
{
  this->current_file_ = file;
  // the state of the dependency processor is cleared on each request
  this->depends_graph_.clear ();
  // determine forward declaration kind exists in package
  this->depends_graph_.visit_file (file, *this);
}

//
// visit_Package
//
void Find_Forward_Decls::visit_Package (PICML::Package_in package)
{
  GAME::Mga::Collection_T <PICML::TemplateParameter> params = package->children <PICML::TemplateParameter> ();

  if (!params.size () || (params.size () && this->visit_template_module_))
    this->depends_graph_.visit_package (package, *this);
}

//
// visit_TemplatePackageAlias
//
void Find_Forward_Decls::
visit_TemplatePackageInstance (PICML::TemplatePackageInstance_in a)
{
  PICML::File file = this->get_file (a->get_PackageType ()->refers_to_Package ());

  if (this->current_file_ != file)
    this->includes_.insert (file);

  visit_all () (a->children <PICML::TemplateParameterValue> (), this);

  // We all need to visit the contents of the template package
  // instance's type. This will determine what other things
  // we need to include.
  PICML::Package package = a->get_PackageType ()->refers_to_Package ();

  Find_Forward_Decls inner_fwd (this->depends_graph_, true);

  try
  {
    package->accept (&inner_fwd);
  }
  catch (...)
  {

  }

  this->has_component_ |= inner_fwd.has_component ();
}

//
// visit_Alias
//
void Find_Forward_Decls::visit_Alias (PICML::Alias_in a)
{
  this->visit_MemberType (a->refers_to_MemberType ());
}

//
// visit_Constant
//
void Find_Forward_Decls::visit_Constant (PICML::Constant_in c)
{
  PICML::ConstantType t = c->refers_to_ConstantType ();

  if (t->meta ()->name () == PICML::Enum::impl_type::metaname)
    t->accept (this);
}

//
// visit_Collection
//
void Find_Forward_Decls::
visit_Collection (PICML::Collection_in c)
{
  this->visit_MemberType (c->refers_to_MemberType ());
}

//
// visit_Exception
//
void Find_Forward_Decls::
visit_Exception (PICML::Exception_in e)
{
  visit_all () (e->get_Members (), this);
}

//
// visit_Member
//
void Find_Forward_Decls::visit_Member (PICML::Member_in m)
{
  this->visit_MemberType (m->refers_to_MemberType ());
}

//
// visit_Aggregate
//
void Find_Forward_Decls::visit_Aggregate (PICML::Aggregate_in a)
{
  visit_all () (a->get_Members (), this);

  // All we need is one aggregate to have a key for the
  // entire file to need type support.
  this->has_typesupport_ |= a->has_Key ();
}

//
// visit_SwitchedAggregate
//
void Find_Forward_Decls::
visit_SwitchedAggregate (PICML::SwitchedAggregate_in s)
{
  visit_all () (s->get_Members (), this);
}

/**
 * @struct is_async_receptacle_t
 */
struct is_async_receptacle_t
{
  bool operator () (PICML::RequiredRequestPort & p) const
  {
    return p->AsyncCommunication ();
  }
};

//
// visit_Object
//
void Find_Forward_Decls::visit_Object (PICML::Object_in o)
{
  // Determine if this object has ami4ccm support. If so, then
  // we need to make sure this file is marked as ami4ccm.
  this->has_ami4ccm_ |= o->SupportsAsync ();

  // Visit the remaining elements in the object.
  visit_all () (o->get_Inheritss (), this);
  visit_all () (o->get_Aggregates (), this);
  visit_all () (o->get_SwitchedAggregates (), this);
  visit_all () (o->get_Aliass (), this);
  visit_all () (o->get_Constants (), this);
  visit_all () (o->get_Enums (), this);
  visit_all () (o->get_Collections (), this);
  visit_all () (o->get_Exceptions (), this);
  visit_all () (o->get_OnewayOperations (), this);
  visit_all () (o->get_TwowayOperations (), this);
  visit_all () (o->get_ReadonlyAttributes (), this);
}

//
// visit_Event
//
void Find_Forward_Decls::visit_Event (PICML::Event_in e)
{
  this->has_component_ = true;
  this->visit_ObjectByValue (e);
}

//
// visit_ValueObject
//
void Find_Forward_Decls::visit_ValueObject (PICML::ValueObject_in v)
{
  this->visit_ObjectByValue (v);
}

//
// visit_ValueObject
//
void Find_Forward_Decls::
visit_ObjectByValue (PICML::ObjectByValue_in v)
{
  visit_all () (v->get_Members (), this);
  visit_all () (v->get_Aggregates (), this);
  visit_all () (v->get_SwitchedAggregates (), this);
  visit_all () (v->get_Aliass (), this);
  visit_all () (v->get_Constants (), this);
  visit_all () (v->get_Enums (), this);
  visit_all () (v->get_Collections (), this);
  visit_all () (v->get_Exceptions (), this);
  visit_all () (v->get_PortTypes (), this);
  visit_all () (v->get_FactoryOperations (), this);
  visit_all () (v->get_OnewayOperations (), this);
  visit_all () (v->get_TwowayOperations (), this);
}

//
// visit_FactoryOperation
//
void Find_Forward_Decls::
visit_FactoryOperation (PICML::FactoryOperation_in op)
{
  for (PICML::ParameterType param : op->children <PICML::ParameterType> ())
    this->visit_MemberType (param->refers_to_MemberType ());
}

//
// visit_ExtendedPort
//
void Find_Forward_Decls::
visit_ExtendedPort (PICML::ExtendedPort_in p)
{
  visit_all () (p->refers_to_PortType ()->get_ProvidedRequestPorts (), this);
  visit_all () (p->refers_to_PortType ()->get_RequiredRequestPorts (), this);
}

//
// visit_ReadonlyAttribute
//
void Find_Forward_Decls::
visit_ReadonlyAttribute (PICML::ReadonlyAttribute_in r)
{
  this->visit_MemberType (r->get_AttributeMember ()->refers_to_MemberType ());
}

//
// visit_OnewayOperation
//
void Find_Forward_Decls::
visit_OnewayOperation (PICML::OnewayOperation_in op)
{
  for (PICML::ParameterType param : op->children <PICML::ParameterType> ())
    this->visit_MemberType (param->refers_to_MemberType ());
}

//
// visit_TwowayOperation
//
void Find_Forward_Decls::
visit_TwowayOperation (PICML::TwowayOperation_in op)
{
  for (PICML::ParameterType param : op->children <PICML::ParameterType> ())
    this->visit_MemberType (param->refers_to_MemberType ());
}

//
// visit_Component
//
void Find_Forward_Decls::visit_Component (PICML::Component_in c)
{
  this->has_component_ = true;

  visit_all () (c->get_ReadonlyAttributes (), this);
  visit_all () (c->get_ExtendedPorts (), this);
  visit_all () (c->get_InEventPorts (), this);
  visit_all () (c->get_OutEventPorts (), this);
  visit_all () (c->get_ProvidedRequestPorts (), this);
  visit_all () (c->get_RequiredRequestPorts (), this);
}

//
// visit_ConnectorObject
//
void Find_Forward_Decls::
visit_ConnectorObject (PICML::ConnectorObject_in c)
{
  this->has_component_ = true;

  visit_all () (c->get_ExtendedPorts (), this);
  visit_all () (c->get_ReadonlyAttributes (), this);
  visit_all () (c->get_ProvidedRequestPorts (), this);
  visit_all () (c->get_RequiredRequestPorts (), this);
}

//
// visit_ComponentFactory
//
void Find_Forward_Decls::
visit_ComponentFactory (PICML::ComponentFactory_in f)
{
  visit_all () (f->get_Aggregates (), this);
  visit_all () (f->get_SwitchedAggregates (), this);
  visit_all () (f->get_Aliass (), this);
  visit_all () (f->get_Constants (), this);
  visit_all () (f->get_Enums (), this);
  visit_all () (f->get_Collections (), this);
  visit_all () (f->get_Exceptions (), this);
  visit_all () (f->get_PortTypes (), this);
  visit_all () (f->get_ReadonlyAttributes (), this);
  visit_all () (f->get_FactoryOperations (), this);
  visit_all () (f->get_LookupOperations (), this);
  visit_all () (f->get_OnewayOperations (), this);
  visit_all () (f->get_TwowayOperations (), this);
}

//
// visit_RequiredRequestPort
//
void Find_Forward_Decls::
visit_RequiredRequestPort (PICML::RequiredRequestPort_in p)
{
  PICML::Provideable provides = p->refers_to_Provideable ();

  if (provides->meta ()->name () == PICML::Object::impl_type::metaname)
    this->visit_NamedType (PICML::Object::_narrow (provides));
}

//
// visit_ProvidedRequestPort
//
void Find_Forward_Decls::
visit_ProvidedRequestPort (PICML::ProvidedRequestPort_in p)
{
  PICML::Provideable provides = p->refers_to_Provideable ();

  if (provides->meta ()->name () == PICML::Object::impl_type::metaname)
    this->visit_NamedType (PICML::Object::_narrow (provides));
}

//
// visit_InEventPort
//
void Find_Forward_Decls::
visit_InEventPort (PICML::InEventPort_in p)
{
  PICML::EventType t = p->refers_to_EventType ();

  if (t->meta ()->name () == PICML::Event::impl_type::metaname)
    this->visit_NamedType (PICML::Event::_narrow (t));
}

//
// visit_OutEventPort
//
void Find_Forward_Decls::
visit_OutEventPort (PICML::OutEventPort_in p)
{
  PICML::EventType t = p->refers_to_EventType ();

  if (t->meta ()->name () == PICML::Event::impl_type::metaname)
    this->visit_NamedType (PICML::Event::_narrow (t));
}

//
// visit_TemplateParameterValue
//
void Find_Forward_Decls::
visit_TemplateParameterValue (PICML::TemplateParameterValue_in tpv)
{
  PICML::TemplateParameterValueType t = tpv->refers_to_TemplateParameterValueType ();

  if (t->meta ()->name () == PICML::Exception::impl_type::metaname)
    this->visit_Exception (PICML::Exception::_narrow (t));
  else
    this->visit_MemberType (PICML::MemberType::_narrow (t));
}

//
// visit_Boxed
//
void Find_Forward_Decls::
visit_Boxed (PICML::Boxed_in b)
{
  this->visit_MemberType (b->refers_to_MemberType ());
}

//
// visit_MemberType
//
void Find_Forward_Decls::
visit_MemberType (PICML::MemberType_in m)
{
  if (derives_from <PICML::NamedType> () (m))
    this->visit_NamedType (PICML::NamedType::_narrow (m));
}

//
// visit_NamedType
//
void Find_Forward_Decls::visit_NamedType (PICML::NamedType_in n)
{
  PICML::File file = this->get_file (n);

  if (this->current_file_ != file)
    this->includes_.insert (file);

  // THIS IS TODO

  // Determine if we need to forward declare this object. This is
  // the case if we are not in the current object is not able to
  // see us (i.e., we are not in a namespace above the current object).
}

//
// get_file
//
PICML::File Find_Forward_Decls::get_file (const GAME::Mga::Object_in obj)
{
  GAME::Mga::Object parent = obj->parent ();

  while (parent->meta ()->name () != PICML::File::impl_type::metaname)
    parent = parent->parent ();

  return parent;
}
