// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Model.h"

#if !defined (__GAME_INLINE__)
#include "Model.inl"
#endif

#include "Atom.h"
#include "Folder.h"
#include "Functional_T.h"
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
// _create
//
Model Model_Impl::_create (const Model_in parent, const std::string & type)
{
  return create_object <Model> (parent, type);
}

//
// _create
//
Model Model_Impl::_create (const Model_in parent, const Meta::Role_in role)
{
  return create_object <Model> (parent, role);
}

//
// _create
//
Model Model_Impl::
_create (const Folder_in parent, const std::string & type)
{
  return create_root_object <Model> (parent, type);
}

//
// _create
//
Model Model_Impl::
_create (const Folder_in parent, const Meta::FCO_in metafco)
{
  return create_root_object <Model> (parent, metafco);
}

//
// meta
//
Meta::Model Model_Impl::meta (void) const
{
  Meta::FCO metafco = FCO_Impl::meta ();
  return Meta::Model::_narrow (metafco.get ());
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
