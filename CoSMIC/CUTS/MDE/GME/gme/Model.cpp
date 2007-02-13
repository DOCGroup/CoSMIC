// $Id$

#include "Model.h"

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
}
