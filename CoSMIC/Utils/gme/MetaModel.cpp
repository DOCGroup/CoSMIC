// $Id$

#include "stdafx.h"
#include "MetaModel.h"

#if !defined (__GME_INLINE__)
#include "MetaModel.inl"
#endif

#include "MetaRole.h"

namespace GME
{
namespace Meta
{
  //
  // impl
  //
  IMgaMetaModel * Model::impl (void) const
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
  Role Model::role (const std::string & name) const
  {
    CComPtr <IMgaMetaRole> tempptr;
    CComBSTR bstr (name.c_str ());

    VERIFY_HRESULT (this->impl ()->get_RoleByName (bstr, &tempptr));

    return tempptr.p;
  }

  //
  // _narrow
  //
  Model Model::_narrow (Base & meta)
  {
    CComPtr <IMgaMetaModel> model;
    VERIFY_HRESULT (meta.impl ()->QueryInterface (&model));

    return model.p;
  }
}
}
