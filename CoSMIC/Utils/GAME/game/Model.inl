// -*- C++ -*-
// $Id$

namespace GME
{
  //
  // Model
  //
  GME_INLINE
  Model::Model (void)
  {

  }

  //
  // Model
  //
  GME_INLINE
  Model::Model (IMgaModel * model)
    : FCO (model)
  {

  }

  //
  // Model
  //
  GME_INLINE
  Model::Model (const Model & model)
    : FCO (model)
  {

  }

  //
  // ~Model
  //
  GME_INLINE
  Model::~Model (void)
  {

  }
}
