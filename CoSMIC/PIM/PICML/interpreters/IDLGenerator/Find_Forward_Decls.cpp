// $Id$

#include "StdAfx.h"
#include "Find_Forward_Decls.h"
#include "Utils/UDM/visit.h"

//
// Find_Forward_Decls
//
Find_Forward_Decls::Find_Forward_Decls (void)
: has_component_ (false)
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
}

//
// has_component
//
bool Find_Forward_Decls::has_component (void) const
{
  return this->has_component_;
}

//
// fwd_decls
//
const Find_Forward_Decls::fwd_decls_t & Find_Forward_Decls::fwd_decls (void) const
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
// Visit_File
//
void Find_Forward_Decls::Visit_File (const PICML::File & file)
{
  this->current_file_ = file;
  this->Visit_FilePackage (file);
}

//
// Visit_Package
//
void Find_Forward_Decls::Visit_Package (const PICML::Package & package)
{
  std::vector <PICML::TemplateParameter> params = package.TemplateParameter_kind_children ();

  if (params.empty ())
    this->Visit_FilePackage (package);
}

//
// Visit_FilePackage
//
void Find_Forward_Decls::Visit_FilePackage (const Udm::Object & fp)
{
  Udm::visit_all <PICML::Constant> (fp, *this);
  Udm::visit_all <PICML::Alias> (fp, *this);
  Udm::visit_all <PICML::Collection> (fp, *this);
  Udm::visit_all <PICML::Exception> (fp, *this);
  Udm::visit_all <PICML::Aggregate> (fp, *this);
  Udm::visit_all <PICML::SwitchedAggregate> (fp, *this);
  Udm::visit_all <PICML::ValueObject> (fp, *this);

  Udm::visit_all <PICML::TemplatePackageInstance> (fp, *this);

  Udm::visit_all <PICML::Event> (fp, *this);
  Udm::visit_all <PICML::Object> (fp, *this);
  Udm::visit_all <PICML::PortType> (fp, *this);
  Udm::visit_all <PICML::Component> (fp, *this);
  Udm::visit_all <PICML::ComponentFactory> (fp, *this);
  Udm::visit_all <PICML::ConnectorObject> (fp, *this);

  Udm::visit_all <PICML::Package> (fp, *this);
}

//
// Visit_TemplatePackageAlias
//
void Find_Forward_Decls::
Visit_TemplatePackageInstance (const PICML::TemplatePackageInstance & a)
{
  PICML::PackageType t = a.PackageType_child ();
  PICML::File file = this->get_file (t.ref ());

  if (this->current_file_ != file)
    this->includes_.insert (file);

  Udm::visit_all <PICML::TemplateParameterValue> (a, *this);
}

//
// Visit_Alias
//
void Find_Forward_Decls::Visit_Alias (const PICML::Alias & a)
{
  this->Visit_MemberType (a.ref ());
}

//
// Visit_Constant
//
void Find_Forward_Decls::Visit_Constant (const PICML::Constant & c)
{
  PICML::ConstantType t = c.ref ();

  if (t.type () == PICML::Enum::meta)
    PICML::Enum::Cast (t).Accept (*this);
}

//
// Visit_Collection
//
void Find_Forward_Decls::
Visit_Collection (const PICML::Collection & c)
{
  this->Visit_MemberType (c.ref ());
}

//
// Visit_Exception
//
void Find_Forward_Decls::
Visit_Exception (const PICML::Exception & e)
{
  Udm::visit_all <PICML::Member> (e, *this);
}

//
// Visit_Member
//
void Find_Forward_Decls::Visit_Member (const PICML::Member & m)
{
  this->Visit_MemberType (m.ref ());
}

//
// Visit_Aggregate
//
void Find_Forward_Decls::Visit_Aggregate (const PICML::Aggregate & a)
{
  Udm::visit_all <PICML::Member> (a, *this);
}

//
// Visit_SwitchedAggregate
//
void Find_Forward_Decls::
Visit_SwitchedAggregate (const PICML::SwitchedAggregate & s)
{
  Udm::visit_all <PICML::Member> (s, *this);
}

//
// Visit_Object
//
void Find_Forward_Decls::Visit_Object (const PICML::Object & o)
{
  Udm::visit_all <PICML::Inherits> (o, *this);

  Udm::visit_all <PICML::Aggregate> (o, *this);
  Udm::visit_all <PICML::SwitchedAggregate> (o, *this);
  Udm::visit_all <PICML::Alias> (o, *this);
  Udm::visit_all <PICML::Constant> (o, *this);
  Udm::visit_all <PICML::Enum> (o, *this);
  Udm::visit_all <PICML::Collection> (o, *this);
  Udm::visit_all <PICML::Exception> (o, *this);

  Udm::visit_all <PICML::OnewayOperation> (o, *this);
  Udm::visit_all <PICML::TwowayOperation> (o, *this);

  Udm::visit_all <PICML::ReadonlyAttribute> (o, *this);
}

//
// Visit_Event
//
void Find_Forward_Decls::Visit_Event (const PICML::Event & e)
{
  this->has_component_ = true;
  this->Visit_ObjectByValue (e);
}

//
// Visit_ValueObject
//
void Find_Forward_Decls::Visit_ValueObject (const PICML::ValueObject & v)
{
  this->Visit_ObjectByValue (v);
}

//
// Visit_ValueObject
//
void Find_Forward_Decls::
Visit_ObjectByValue (const PICML::ObjectByValue & v)
{
  Udm::visit_all <PICML::Aggregate> (v, *this);
  Udm::visit_all <PICML::SwitchedAggregate> (v, *this);
  Udm::visit_all <PICML::Alias> (v, *this);
  Udm::visit_all <PICML::Constant> (v, *this);
  Udm::visit_all <PICML::Enum> (v, *this);
  Udm::visit_all <PICML::Collection> (v, *this);
  Udm::visit_all <PICML::Exception> (v, *this);
  Udm::visit_all <PICML::PortType> (v, *this);
  Udm::visit_all <PICML::FactoryOperation> (v, *this);

  Udm::visit_all <PICML::OnewayOperation> (v, *this);
  Udm::visit_all <PICML::TwowayOperation> (v, *this);
}

//
// Visit_FactoryOperation
//
void Find_Forward_Decls::
Visit_FactoryOperation (const PICML::FactoryOperation & op)
{
  std::vector <PICML::ParameterType> params = op.ParameterType_kind_children ();

  std::for_each (params.begin (),
                 params.end (),
                 boost::bind (&Find_Forward_Decls::Visit_MemberType, this,
                              boost::bind (&PICML::ParameterType::ref, _1)));
}

//
// Visit_ExtendedPort
//
void Find_Forward_Decls::
Visit_ExtendedPort (const PICML::ExtendedPort & p)
{
  PICML::TemplatePackageInstanceDecl decl = p.srcTemplatePackageInstanceDecl ();

  if (decl != Udm::null)
    decl.Accept (*this);

  Udm::visit_all <PICML::ProvidedRequestPort> (p, *this);
  Udm::visit_all <PICML::RequiredRequestPort> (p, *this);
}

//
// Visit_TemplatePackageInstanceDecl
//
void Find_Forward_Decls::
Visit_TemplatePackageInstanceDecl (const PICML::TemplatePackageInstanceDecl & decl)
{
  PICML::TemplatePackageInstanceRef ref = decl.srcTemplatePackageInstanceDecl_end ();
  PICML::File file = this->get_file (ref.ref ());

  if (this->current_file_ != file)
    this->includes_.insert (file);
}

//
// Visit_ReadonlyAttribute
//
void Find_Forward_Decls::
Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & r)
{
  PICML::AttributeMember m = r.AttributeMember_child ();
  this->Visit_MemberType (m.ref ());
}

//
// Visit_OnewayOperation
//
void Find_Forward_Decls::
Visit_OnewayOperation (const PICML::OnewayOperation & op)
{
  std::vector <PICML::ParameterType> params = op.ParameterType_kind_children ();

  std::for_each (params.begin (),
                 params.end (),
                 boost::bind (&Find_Forward_Decls::Visit_MemberType, this,
                              boost::bind (&PICML::ParameterType::ref, _1)));
}

//
// Visit_TwowayOperation
//
void Find_Forward_Decls::
Visit_TwowayOperation (const PICML::TwowayOperation & op)
{
  std::vector <PICML::ParameterType> params = op.ParameterType_kind_children ();

  std::for_each (params.begin (),
                 params.end (),
                 boost::bind (&Find_Forward_Decls::Visit_MemberType, this,
                              boost::bind (&PICML::ParameterType::ref, _1)));
}

//
// Visit_Component
//
void Find_Forward_Decls::Visit_Component (const PICML::Component & c)
{
  this->has_component_ = true;

  Udm::visit_all <PICML::ObjectPort> (c, *this);
  Udm::visit_all <PICML::EventPort> (c, *this);
  Udm::visit_all <PICML::ExtendedPort> (c, *this);
  Udm::visit_all <PICML::ReadonlyAttribute> (c, *this);
}

//
// Visit_ConnectorObject
//
void Find_Forward_Decls::
Visit_ConnectorObject (const PICML::ConnectorObject & c)
{
  this->has_component_ = true;

  Udm::visit_all <PICML::ObjectPort> (c, *this);
  Udm::visit_all <PICML::ExtendedPort> (c, *this);
  Udm::visit_all <PICML::ReadonlyAttribute> (c, *this);
}

//
// Visit_ComponentFactory
//
void Find_Forward_Decls::
Visit_ComponentFactory (const PICML::ComponentFactory & f)
{
  Udm::visit_all <PICML::Aggregate> (f, *this);
  Udm::visit_all <PICML::SwitchedAggregate> (f, *this);
  Udm::visit_all <PICML::Alias> (f, *this);
  Udm::visit_all <PICML::Constant> (f, *this);
  Udm::visit_all <PICML::Enum> (f, *this);
  Udm::visit_all <PICML::Collection> (f, *this);
  Udm::visit_all <PICML::Exception> (f, *this);
  Udm::visit_all <PICML::PortType> (f, *this);
  Udm::visit_all <PICML::ReadonlyAttribute> (f, *this);

  Udm::visit_all <PICML::FactoryOperation> (f, *this);
  Udm::visit_all <PICML::LookupOperation> (f, *this);

  Udm::visit_all <PICML::OnewayOperation> (f, *this);
  Udm::visit_all <PICML::TwowayOperation> (f, *this);
}

//
// Visit_RequiredRequestPort
//
void Find_Forward_Decls::
Visit_RequiredRequestPort (const PICML::RequiredRequestPort & p)
{
  PICML::Provideable provides = p.ref ();

  if (provides.type () == PICML::Object::meta)
    this->Visit_NamedType (PICML::Object::Cast (provides));
}

//
// Visit_ProvidedRequestPort
//
void Find_Forward_Decls::
Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & p)
{
  PICML::Provideable provides = p.ref ();

  if (provides.type () == PICML::Object::meta)
    this->Visit_NamedType (PICML::Object::Cast (provides));
}

//
// Visit_InEventPort
//
void Find_Forward_Decls::
Visit_InEventPort (const PICML::InEventPort & p)
{
  PICML::EventType t = p.ref ();

  if (t.type () == PICML::Event::meta)
    this->Visit_NamedType (PICML::Event::Cast (t));
}

//
// Visit_OutEventPort
//
void Find_Forward_Decls::
Visit_OutEventPort (const PICML::OutEventPort & p)
{
  PICML::EventType t = p.ref ();

  if (t.type () == PICML::Event::meta)
    this->Visit_NamedType (PICML::Event::Cast (t));
}

//
// Visit_TemplateParameterValue
//
void Find_Forward_Decls::
Visit_TemplateParameterValue (const PICML::TemplateParameterValue & tpv)
{
  this->Visit_MemberType (tpv.ref ());
}

//
// Visit_MemberType
//
void Find_Forward_Decls::
Visit_MemberType (const PICML::MemberType & m)
{
  if (Udm::IsDerivedFrom (m.type (), PICML::NamedType::meta))
    this->Visit_NamedType (PICML::NamedType::Cast (m));
}

//
// Visit_NamedType
//
void Find_Forward_Decls::Visit_NamedType (const PICML::NamedType & n)
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
PICML::File Find_Forward_Decls::get_file (const Udm::Object & obj)
{
  Udm::Object parent = obj.GetParent ();

  while (parent.type () != PICML::File::meta)
    parent = parent.GetParent ();

  return PICML::File::Cast (parent);
}

//
// is_visible
//
bool Find_Forward_Decls::is_visible (const Udm::Object & ref)
{
  return true;
}
