// $Id$

namespace GME
{
namespace Meta
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
  Model::Model (IMgaMetaModel * meta)
    : FCO (meta)
  {

  }

  //
  // Model
  //
  GME_INLINE
  Model::Model (const Model & meta)
    : FCO (meta)
  {

  }

  //
  // ~Model
  //
  GME_INLINE
  Model::~Model (void)
  {

  }

  //
  // operator =
  //
  GME_INLINE
  const Model & Model::operator = (const Model & meta)
  {
    FCO::attach (meta);
    return *this;
  }

  //
  // operator IMgaMetaModel *
  //
  GME_INLINE
  Model::operator IMgaMetaModel * (void) const
  {
    return this->impl ();
  }
}
}
