// $Id$

namespace GAME
{
namespace Meta
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
  Model::Model (IMgaMetaModel * meta)
    : FCO (meta)
  {

  }

  //
  // Model
  //
  GAME_INLINE
  Model::Model (const Model & meta)
    : FCO (meta)
  {

  }

  //
  // ~Model
  //
  GAME_INLINE
  Model::~Model (void)
  {

  }

  //
  // operator =
  //
  GAME_INLINE
  const Model & Model::operator = (const Model & meta)
  {
    FCO::attach (meta);
    return *this;
  }

  //
  // operator IMgaMetaModel *
  //
  GAME_INLINE
  Model::operator IMgaMetaModel * (void) const
  {
    return this->impl ();
  }
}
}
