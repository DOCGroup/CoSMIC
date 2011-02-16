// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Reference.h"

#if !defined (__GAME_INLINE__)
#include "Reference.inl"
#endif

#include "Functional_T.h"
#include "Model.h"
#include "Visitor.h"
#include "Exception.h"
#include "MetaRole.h"
#include "MetaModel.h"
#include "MetaReference.h"

namespace GAME
{
namespace Mga
{

//
// _create
//
Reference Reference_Impl::
_create (const Model_in parent, const std::string & type)
{
  return create_object <Reference> (parent, type);
}

//
// _create
//
Reference Reference_Impl::
_create (const Model_in parent, const Meta::Role_in role)
{
  return create_object <Reference> (parent, role);
}

//
// meta
//
Meta::Reference Reference_Impl::meta (void) const
{
  Meta::FCO metafco = FCO_Impl::meta ();
  return Meta::Reference::_narrow (metafco.get ());
}

//
// refers_to
//
FCO Reference_Impl::refers_to (void) const
{
  CComPtr <IMgaFCO> fco;
  VERIFY_HRESULT (this->impl ()->get_Referred (&fco));

  return fco.p;
}

//
// refers_to
//
void Reference_Impl::refers_to (const FCO_in fco)
{
  VERIFY_HRESULT (this->impl ()->put_Referred (fco->impl ()));
}

//
// impl
//
IMgaReference * Reference_Impl::impl (void) const
{
  if (this->ref_.p == this->object_.p)
    return this->ref_.p;

  if (this->ref_.p != 0)
    this->ref_.Release ();

  VERIFY_HRESULT (this->object_.QueryInterface (&this->ref_));
  return this->ref_.p;
}

//
// accept
//
void Reference_Impl::accept (Visitor * v)
{
  v->visit_Reference (this);
}

}
}
