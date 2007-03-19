// $Id$

#include "Model.h"
#include "Folder.h"

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
  MetaModel Model::meta (void) const
  {
    return MetaModel::_narrow (FCO::meta ());
  }

  //
  // _narrow
  //
  Model Model::_narrow (FCO & fco)
  {
    CComPtr <IMgaModel> model;
    VERIFY_HRESULT (fco.impl ()->QueryInterface (&model));

    return model.p;
  }

  //
  // _create
  //
  Model Model::_create (const std::string & role, Model & parent)
  {
    CComPtr <IMgaFCO> child;
    MetaRole metarole = parent.meta ().role (role);

    VERIFY_HRESULT (
      parent.impl ()->CreateChildObject (metarole, &child));

    return Model::_narrow (FCO (child));
  }

  //
  // _create
  //
  Model Model::_create (const std::string & role, Folder & parent)
  {
    CComPtr <IMgaFCO> child;
    //MetaRole metarole = parent.meta ().role (role);

    //VERIFY_HRESULT (
    //  parent.impl ()->CreateChildObject (metarole, &child));

    return Model::_narrow (FCO (child));
  }
}
