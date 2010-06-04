// $Id$

#include "stdafx.h"
#include "MetaModel.h"

#if !defined (__GAME_INLINE__)
#include "MetaModel.inl"
#endif

#include "MetaRole.h"

namespace GAME
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

  VERIFY_HRESULT_THROW_EX (meta.impl ()->QueryInterface (&model),
                           GAME::Invalid_Cast ());

  return model.p;
}

//
// children
//
size_t Model::
children (std::vector <GAME::Meta::FCO> & fcos) const
{
  // Get a pointer to all the legal folders.
  CComPtr <IMgaMetaFCOs> metas;
  VERIFY_HRESULT (this->impl ()->get_DefinedFCOs (&metas));

  return get_children (metas, fcos);
}

//
// aspect
//
Aspect Model::aspect (const std::string & name) const
{
  CComBSTR bstr (name.length (), name.c_str ());
  CComPtr <IMgaMetaAspect> aspect;

  VERIFY_HRESULT (this->impl ()->get_AspectByName (bstr, &aspect));
  return Aspect (aspect);
}

//
// aspects
//
size_t Model::aspects (std::vector <Aspect> & aspects) const
{
  // Get a pointer to all the legal folders.
  CComPtr <IMgaMetaAspects> temp;
  VERIFY_HRESULT (this->impl ()->get_Aspects (&temp));

  return get_children (temp, aspects);
}

}
}
