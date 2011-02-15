// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Model.h"

#if !defined (__GAME_INLINE__)
#include "Model.inl"
#endif

#include "Folder.h"
#include "Atom.h"
#include "Reference.h"
#include "Connection.h"
#include "Set.h"
#include "MetaFolder.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "Visitor.h"

namespace GAME
{
namespace Mga
{

//
// meta
//
Meta::Model Model_Impl::meta (void) const
{
  Meta::FCO metafco = FCO_Impl::meta ();
  return Meta::Model::_narrow (metafco.get ());
}

//
// _create
//
Model Model_Impl::
_create (const Model_in parent, const std::string & type)
{
  Meta::Role role = parent->meta ()->role (type);
  return Model_Impl::_create (parent, role.get ());
}

//
// _create
//
Model Model_Impl::
_create (const Model_in parent, const Meta::Role_in role)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent->impl ()->CreateChildObject (role->impl (), &child));

  CComPtr <IMgaModel> mga_model;
  VERIFY_HRESULT (child.QueryInterface (&mga_model));

  return mga_model.p;
}

//
// _create
//
Model Model_Impl::
_create (const Folder_in parent, const std::string & type)
{
  Meta::FCO meta = parent->meta ()->child (type);
  return Model_Impl::_create (parent, meta.get ());
}

//
// _create
//
Model Model_Impl::
_create (const Folder_in parent, const Meta::FCO_in meta)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent->impl ()->CreateRootObject (meta->impl (), &child));

  CComPtr <IMgaModel> mga_model;
  VERIFY_HRESULT (child.QueryInterface (&mga_model));

  return mga_model.p;
}

//
// accept
//
void Model_Impl::accept (Visitor * v)
{
  v->visit_Model (this);
}

//
// impl
//
IMgaModel * Model_Impl::impl (void) const
{
  if (this->model_.p == this->object_.p)
    return this->model_.p;

  if (this->model_.p != 0)
    this->model_.Release ();

  VERIFY_HRESULT (this->object_.QueryInterface (&this->model_));
  return this->model_.p;
}

//
// attach
//
void Model_Impl::attach (IMgaModel * model)
{
  VERIFY_HRESULT (model->QueryInterface (&this->object_));
}

}
}
