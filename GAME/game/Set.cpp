// $Id$

#include "stdafx.h"
#include "Mga.h"

#include "Set.h"

#if !defined (__GAME_INLINE__)
#include "Set.inl"
#endif

#include "Model.h"
#include "Collection_T.h"
#include "Exception.h"
#include "Visitor.h"

#include "MetaRole.h"
#include "MetaModel.h"
#include "MetaSet.h"


namespace GAME
{

//
// _create
//
Set Set_Impl::_create (const Model_in parent, const std::string & type)
{
  Meta::Role role = parent->meta ()->role (type);
  return Set_Impl::_create (parent, role.get ());
}

//
// _create
//
Set Set_Impl::_create (const Model_in parent, const Meta::Role_in type)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent->impl ()->CreateChildObject (type->impl (), &child));

  CComPtr <IMgaSet> mga_set;
  VERIFY_HRESULT (child.QueryInterface (&mga_set));

  return mga_set.p;
}

//
// clear
//
void Set_Impl::clear (void)
{
  VERIFY_HRESULT (this->impl ()->RemoveAll ());
}

//
// insert
//
void Set_Impl::insert (const FCO_in fco)
{
  VERIFY_HRESULT (this->impl ()->AddMember (fco->impl ()));
}

//
// remove
//
void Set_Impl::remove (const FCO_in fco)
{
  VERIFY_HRESULT (this->impl ()->RemoveMember (fco->impl ()));
}

//
// insert
//
bool Set_Impl::contains (const FCO_in fco)
{
  VARIANT_BOOL is_member;
  VERIFY_HRESULT (this->impl ()->get_IsMember (fco->impl (), &is_member));

  return is_member == VARIANT_TRUE ? true : false;
}

//
// members
//
size_t Set_Impl::members (std::vector <GAME::FCO> & members) const
{
  // Get all the members in the set.
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_Members (&fcos));

  return get_children (fcos.p, members);
}

//
// impl
//
IMgaSet * Set_Impl::impl (void) const
{
  if (this->set_.p == this->object_.p)
    return this->set_.p;

  if (this->set_.p != 0)
    this->set_.Release ();

  VERIFY_HRESULT (this->object_.QueryInterface (&this->set_));
  return this->set_;
}

//
// accept
//
void Set_Impl::accept (Visitor * v)
{
  v->visit_Set (this);
}

//
// meta
//
Meta::Set Set_Impl::meta (void) const
{
  return Meta::Set::_narrow (FCO_Impl::meta ());
}

}
