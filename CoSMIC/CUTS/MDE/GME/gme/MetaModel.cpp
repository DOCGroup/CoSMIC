// $Id$

#include "MetaModel.h"

#if !defined (__GME_INLINE__)
#include "MetaModel.inl"
#endif

namespace GME
{
  //
  // impl
  //
  IMgaMetaModel * MetaModel::impl (void) const
  {
    // Optimize for the quick path.
    if (this->metamodel_.p == this->metabase_.p)
      return this->metamodel_;

    // So, we have to actually initalize the <meta_fco_>.
    if (this->metamodel_)
      this->metamodel_.Release ();

    VERIFY_HRESULT (this->metabase_.QueryInterface (&this->metamodel_));
    return this->metamodel_;
  }

  //
  // role
  //
  MetaRole MetaModel::role (const std::string & role) const
  {
    CComPtr <IMgaMetaRole> tempptr;
    CComBSTR bstr_role (role.length (), role.c_str ());

    VERIFY_HRESULT (this->impl ()->get_RoleByName (bstr_role, &tempptr));

    return tempptr.p;
  }

  //
  // _narrow
  //
  MetaModel MetaModel::_narrow (MetaBase & meta)
  {
    CComPtr <IMgaMetaModel> model;
    VERIFY_HRESULT (meta.impl ()->QueryInterface (&model));

    return model.p;
  }
}
