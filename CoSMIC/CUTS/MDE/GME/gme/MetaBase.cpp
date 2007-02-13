// $Id$

#include "MetaBase.h"

namespace GME
{
  //
  // MetaBase
  //
  MetaBase::MetaBase (void)
  {

  }

  //
  // MetaBase
  //
  MetaBase::MetaBase (IMgaMetaBase * meta)
  : metabase_ (meta)
  {

  }

  //
  // MetaBase
  //
  MetaBase::MetaBase (const MetaBase & meta)
    : metabase_ (meta.metabase_)
  {

  }

  //
  // ~MetaBase
  //
  MetaBase::~MetaBase (void)
  {

  }

  //
  // name
  //
  std::string MetaBase::name (void) const
  {
    CComBSTR bstr;
    VERIFY_HRESULT (this->metabase_->get_Name (&bstr));

    CW2A tempstr (bstr);
    return tempstr.m_psz;
  }

  //
  // displayed_name
  //
  std::string MetaBase::displayed_name (void) const
  {
    CComBSTR bstr;
    VERIFY_HRESULT (this->metabase_->get_DisplayedName (&bstr));

    CW2A tempstr (bstr);
    return tempstr.m_psz;
  }

  //
  // attach
  //
  void MetaBase::attach (IMgaMetaBase * metabase)
  {
    this->metabase_.Attach (metabase);
  }

  //
  // operator =
  //
  const MetaBase & MetaBase::operator = (const MetaBase & metabase)
  {
    if (this != &metabase)
      this->metabase_ = metabase.metabase_;

    return *this;
  }

  //
  // operator IMgaMetaBase *
  //
  MetaBase::operator IMgaMetaBase * (void) const
  {
    return this->metabase_.p;
  }
}
