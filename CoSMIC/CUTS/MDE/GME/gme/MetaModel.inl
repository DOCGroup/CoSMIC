// -*- C++ -*-
// $Id$

namespace GME
{
  //
  // MetaModel
  //
  GME_INLINE
  MetaModel::MetaModel (void)
  {

  }

  //
  // MetaModel
  //
  GME_INLINE
  MetaModel::MetaModel (IMgaMetaModel * meta)
    : MetaFCO (meta)
  {

  }

  //
  // MetaModel
  //
  GME_INLINE
  MetaModel::MetaModel (const MetaModel & meta)
    : MetaFCO (meta)
  {

  }

  //
  // ~MetaModel
  //
  GME_INLINE
  MetaModel::~MetaModel (void)
  {

  }

  //
  // operator =
  //
  GME_INLINE
  MetaModel & MetaModel::operator = (const MetaModel & meta)
  {
    MetaFCO::attach (meta);
    return *this;
  }

  //
  // operator IMgaMetaModel *
  //
  GME_INLINE
  MetaModel::operator IMgaMetaModel * (void) const
  {
    return this->impl ();
  }
}
