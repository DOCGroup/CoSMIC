// $Id$

#include "stdafx.h"
#include "Mga.h"

#include "Set.h"
#include "Model.h"
#include "MetaRole.h"
#include "MetaModel.h"
#include "Visitor.h"

namespace GAME
{
//
// Set
//
Set::Set (void)
{

}

//
// Set
//
Set::Set (IMgaSet * set)
  : FCO (set)
{

}

//
// Set
//
Set::Set (const Set & set)
  : FCO (set)
{

}

//
// ~Set
//
Set::~Set (void)
{

}

//
// clear
//
void Set::clear (void)
{
  VERIFY_HRESULT (this->impl ()->RemoveAll ());
}

//
// insert
//
void Set::insert (const FCO & fco)
{
  VERIFY_HRESULT (this->impl ()->AddMember (fco.impl ()));
}

//
// remove
//
void Set::remove (const FCO & fco)
{
  VERIFY_HRESULT (this->impl ()->RemoveMember (fco.impl ()));
}

//
// insert
//
bool Set::contains (const FCO & fco)
{
  VARIANT_BOOL is_member;
  VERIFY_HRESULT (this->impl ()->get_IsMember (fco.impl (), &is_member));

  return is_member == VARIANT_TRUE ? true : false;
}

//
// members
//
size_t Set::members (std::vector <GAME::FCO> & members) const
{
  // Get all the members in the set.
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_Members (&fcos));

  return get_children (fcos, members);
}

//
// impl
//
IMgaSet * Set::impl (void) const
{
  if (this->set_.p == this->object_.p)
    return this->set_.p;

  if (this->set_.p != 0)
    this->set_.Release ();

  VERIFY_HRESULT (this->object_.QueryInterface (&this->set_));
  return this->set_;
}

//
// impl
//
const Set & Set::operator = (const Set & set)
{
  if (this != &set)
    this->object_ = set.object_;

  return *this;
}

//
// _narrow
//
Set Set::_narrow (GAME::Object & object)
{
  CComPtr <IMgaSet> set;

  VERIFY_HRESULT_THROW_EX (object.impl ()->QueryInterface (&set),
                           GAME::Invalid_Cast ());

  return set.p;
}

//
// _create
//
Set Set::_create (Model & parent, const std::string & type)
{
  Meta::Role role = parent.meta ().role (type);
  return Set::_create (parent, role);
}

//
// _create
//
Set Set::_create (Model & parent, const Meta::Role & type)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent.impl ()->CreateChildObject (type, &child));

  return Set::_narrow (FCO (child));
}

//
// attach
//
void Set::attach (IMgaSet * set)
{
  FCO::attach (set);
}

//
// accept
//
void Set::accept (GAME::Visitor & visitor)
{
  visitor.visit_Set (*this);
}

}
