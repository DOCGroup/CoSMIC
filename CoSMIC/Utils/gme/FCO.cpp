// $Id$

#include "FCO.h"
#include "Model.h"

namespace GME
{
  //
  // FCO
  //
  FCO::FCO (void)
  {

  }

  //
  // FCO
  //
  FCO::FCO (IMgaFCO * fco)
    : Object (fco)
  {

  }

  //
  // FCO
  //
  FCO::FCO (const FCO & fco)
    : Object (fco)
  {

  }

  //
  // ~FCO
  //
  FCO::~FCO (void)
  {

  }

  //
  // is_instance
  //
  bool FCO::is_instance (void) const
  {
    VARIANT_BOOL instance;
    VERIFY_HRESULT (this->impl ()->get_IsInstance (&instance));

    return instance == VARIANT_TRUE ? true : false;
  }

  //
  // is_primary_derived
  //
  bool FCO::is_primary_derived (void) const
  {
    VARIANT_BOOL primary;
    VERIFY_HRESULT (this->impl ()->get_IsPrimaryDerived (&primary));

    return primary == VARIANT_TRUE ? true : false;
  }

  //
  // operator =
  //
  const FCO & FCO::operator = (const FCO & fco)
  {
    if (this != &fco)
      this->object_ = fco.object_;

    return *this;
  }

  //
  // attach
  //
  void FCO::attach (IMgaFCO * fco)
  {
    Object::attach (fco);
  }

  //
  // impl
  //
  IMgaFCO * FCO::impl (void) const
  {
    if (this->fco_.p == this->object_.p)
      return this->fco_.p;

    if (this->fco_.p)
      this->fco_.Release ();

    VERIFY_HRESULT (this->object_.QueryInterface (&this->fco_));
    return this->fco_.p;
  }

  //
  // operator IMgaFCO *
  //
  FCO::operator IMgaFCO * (void) const
  {
    return this->impl ();
  }

  //
  // meta
  //
  MetaFCO FCO::meta (void) const
  {
    CComPtr <IMgaMetaFCO> meta;
    VERIFY_HRESULT (this->impl ()->get_Meta (&meta));

    return meta.p;
  }

  //
  // meta
  //
  MetaRole FCO::metarole (void) const
  {
    CComPtr <IMgaMetaRole> meta;
    VERIFY_HRESULT (this->impl ()->get_MetaRole (&meta));

    return meta.p;
  }

  //
  // archetype
  //
  FCO FCO::archetype (void) const
  {
    CComPtr <IMgaFCO> fco;
    VERIFY_HRESULT (this->impl ()->get_ArcheType (&fco));

    return fco.p;
  }

  //
  // is_subtype
  //
  bool FCO::is_subtype (void) const
  {
    return this->basetype ();
  }

  //
  // basetype
  //
  FCO FCO::basetype (void) const
  {
    // This will fail if the object is not a subtype.
    CComPtr <IMgaFCO> fco;
    VERIFY_HRESULT (this->impl ()->get_BaseType (&fco));

    return fco.p;
  }

  //
  // instance_type
  //
  FCO FCO::instance_type (void) const
  {
    CComPtr <IMgaFCO> fco;
    VERIFY_HRESULT (this->impl ()->get_Type (&fco));

    return fco.p;
  }

  //
  // create_subtype
  //
  FCO FCO::create_subtype (Model & parent)
  {
    CComPtr <IMgaFCO> child;
    MetaRole metarole = this->metarole ();

    VERIFY_HRESULT (
      parent.impl ()->DeriveChildObject (
      this->impl (), metarole, VARIANT_FALSE, &child));

    return child.p;
  }

  //
  // create_instance
  //
  FCO FCO::create_instance (Model & parent)
  {
    CComPtr <IMgaFCO> child;
    MetaRole metarole = this->metarole ();

    VERIFY_HRESULT (
      parent.impl ()->DeriveChildObject (
      this->impl (), metarole, VARIANT_TRUE, &child));

    return child.p;
  }

  //
  // _create
  //
  FCO FCO::_create (const std::string & role, Model & parent)
  {
    CComPtr <IMgaFCO> child;
    MetaRole metarole = parent.meta ().role (role);

    VERIFY_HRESULT (
      parent.impl ()->CreateChildObject (metarole, &child));

    return child.p;
  }

  //
  // _narrow
  //
  FCO FCO::_narrow (const Object & object)
  {
    CComPtr <IMgaFCO> fco;
    VERIFY_HRESULT (object.impl ()->QueryInterface (&fco));

    return fco.p;
  }

  //
  // registry_value
  //
  std::string FCO::registry_value (const std::string & path) const
  {
    CComBSTR bstrvalue;
    CComBSTR bstrpath (path.length (), path.c_str ());

    VERIFY_HRESULT (this->impl ()->get_RegistryValue (bstrpath, &bstrvalue));

    CW2A tempstr (bstrvalue);
    return tempstr.m_psz;
  }

  //
  // registry_value
  //
  void FCO::
  registry_value (const std::string & path, const std::string & value)
  {
    CComBSTR bstrpath (path.length (), path.c_str ());
    CComBSTR bstrvalue (value.length (), value.c_str ());

    VERIFY_HRESULT (this->impl ()->put_RegistryValue (bstrpath, bstrvalue));
  }

  //
  // attributes
  //
  size_t FCO::attributes (Collection_T <Attribute> & attrs) const
  {
    IMgaAttributes * coll = 0;
    VERIFY_HRESULT (this->impl ()->get_Attributes (&coll));

    attrs.attach (coll);
    return attrs.items ().size ();
  }
}
