// $Id$

#include "stdafx.h"
#include "Model.h"
#include "Folder.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "MetaFolder.h"

namespace GME
{
  //
  // Model
  //
  Model::Model (void)
  {

  }

  //
  // Model
  //
  Model::Model (IMgaModel * model)
    : _base_type (model)
  {

  }

  //
  // Model
  //
  Model::Model (const Model & model)
    : _base_type (model)
  {

  }

  //
  // ~Model
  //
  Model::~Model (void)
  {

  }

  //
  // operator =
  //
  const Model & Model::operator = (const Model & model)
  {
    if (this != &model)
      this->object_ = model.object_;

    return *this;
  }

  //
  // meta
  //
  Meta::Model Model::meta (void) const
  {
    return Meta::Model::_narrow (FCO::meta ());
  }

  //
  // _narrow
  //
  Model Model::_narrow (const GME::Object & object)
  {
    CComPtr <IMgaModel> model;
    VERIFY_HRESULT (object.impl ()->QueryInterface (&model));

    return model.p;
  }

  //
  // _create
  //
  Model Model::_create (const std::string & role, Model & parent)
  {
    CComPtr <IMgaFCO> child;
    Meta::Role metarole = parent.meta ().role (role);

    VERIFY_HRESULT (
      parent.impl ()->CreateChildObject (metarole, &child));

    return Model::_narrow (FCO (child));
  }

  //
  // _create
  //
  Model Model::_create (const std::string & role, Folder & parent)
  {
    // Get the meta information about the role.
    Meta::FCO metafco = parent.meta ().fco (role);

    // Create the new child element.
    CComPtr <IMgaFCO> child;

    VERIFY_HRESULT (
      parent.impl ()->CreateRootObject (metafco.impl (), &child));

    return Model::_narrow (FCO (child));
  }
}
