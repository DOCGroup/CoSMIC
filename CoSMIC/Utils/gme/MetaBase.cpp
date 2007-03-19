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
  // name
  //
  void MetaBase::name (const std::string & name)
  {
    CComBSTR bstr (name.length (), name.c_str ());
    VERIFY_HRESULT (this->metabase_->put_Name (bstr));
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
  // displayed_name
  //
  void MetaBase::displayed_name (const std::string & name)
  {
    CComBSTR bstr (name.length (), name.c_str ());
    VERIFY_HRESULT (this->metabase_->put_DisplayedName (bstr));
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

  //
  // operator ==
  //
  bool MetaBase::operator == (const std::string & name) const
  {
    return this->name () == name;
  }

  //
  // operator ==
  //
  bool MetaBase::operator == (const MetaBase & meta) const
  {
    return this->metabase_ == meta.metabase_;
  }

  //
  // refid
  //
  long MetaBase::refid (void) const
  {
    long refid;
    VERIFY_HRESULT (this->metabase_->get_MetaRef (&refid));

    return refid;
  }

  //
  // refid
  //
  void MetaBase::refid (long refid)
  {
    VERIFY_HRESULT (this->metabase_->put_MetaRef (refid));
  }

  //
  // type
  //
  objtype_enum MetaBase::type (void) const
  {
    objtype_enum type;
    VERIFY_HRESULT (this->metabase_->get_ObjType (&type));

    return type;
  }

  //
  // destroy
  //
  void MetaBase::destroy (void)
  {
    VERIFY_HRESULT (this->metabase_->Delete ());
    this->metabase_.Release ();
  }

  //
  // registry_value
  //
  std::string MetaBase::
  registry_value (const std::string & path) const
  {
    CComBSTR bstrval;
    CComBSTR bstrpath (path.length (), path.c_str ());

    VERIFY_HRESULT (this->metabase_->get_RegistryValue (bstrpath, &bstrval));

    CW2A tempstr (bstrval);
    return tempstr.m_psz;
  }

  //
  // registry_value
  //
  void MetaBase::registry_value (const std::string & path,
                                 const std::string & value)
  {
    CComBSTR bstrpath (path.length (), path.c_str ());
    CComBSTR bstrval (value.length (), value.c_str ());

    VERIFY_HRESULT (this->metabase_->put_RegistryValue (bstrpath, bstrval));
  }

  //
  // impl
  //
  IMgaMetaBase * MetaBase::impl (void) const
  {
    return this->metabase_;
  }

  //
  // operator bool
  //
  MetaBase::operator bool (void) const
  {
    return this->metabase_.p != 0;
  }
}
