// -*- C++ -*-
// $Id$

namespace GAME
{
  //
  // Model
  //
  GAME_INLINE
  Model::Model (void)
  {

  }

  //
  // Model
  //
  GAME_INLINE
  Model::Model (IMgaModel * model)
    : FCO (model)
  {

  }

  //
  // Model
  //
  GAME_INLINE
  Model::Model (const Model & model)
    : FCO (model)
  {

  }

  //
  // ~Model
  //
  GAME_INLINE
  Model::~Model (void)
  {

  }
}
