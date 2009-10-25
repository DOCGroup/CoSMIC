// $Id$

#include "stdafx.h"
#include "Model.h"

#if !defined (__GME_INLINE__)
#include "Model.inl"
#endif

#include "Folder.h"
#include "Atom.h"
#include "Reference.h"
#include "Set.h"
#include "MetaFolder.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "Visitor.h"

namespace GME
{
  //
  // operator =
  //
  const Model & Model::operator = (const Model & model)
  {
    if (this != &model)
      this->object_ = model.object_;

    return *this;
  }

  //
  // meta
  //
  Meta::Model Model::meta (void) const
  {
    return Meta::Model::_narrow (FCO::meta ());
  }

  //
  // _narrow
  //
  Model Model::_narrow (const GME::Object & object)
  {
    CComPtr <IMgaModel> model;

    VERIFY_HRESULT_THROW_EX (object.impl ()->QueryInterface (&model),
                             GME::Invalid_Cast ());

    return model.p;
  }

  //
  // _create
  //
  Model Model::_create (const std::string & role, Model & parent)
  {
    CComPtr <IMgaFCO> child;
    Meta::Role metarole = parent.meta ().role (role);

    VERIFY_HRESULT (parent.impl ()->CreateChildObject (metarole, &child));

    return Model::_narrow (FCO (child));
  }

  //
  // _create
  //
  Model Model::_create (const std::string & role, Folder & parent)
  {
    CComPtr <IMgaFCO> child;
    Meta::FCO metafco = parent.meta ().child (role);

    VERIFY_HRESULT (parent.impl ()->CreateRootObject (metafco.impl (), &child));

    return Model::_narrow (FCO (child));
  }

  //
  // accept
  //
  void Model::accept (Visitor & visitor)
  {
    visitor.visit_Model (*this);
  }

  //
  // children
  //
  size_t Model::children (GME::Collection_T <FCO> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

    // Determine how many folders there are.
    children.attach (fcos.Detach ());
    return children.size ();
  }

  //
  // children
  //
  size_t Model::
  children (const std::string & type, GME::Collection_T <GME::Atom> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    // Determine how many folders there are.
    children.attach (fcos.Detach ());
    return children.size ();
  }

  //
  // children
  //
  size_t Model::
  children (const std::string & type, GME::Collection_T <GME::Model> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    // Determine how many folders there are.
    children.attach (fcos.Detach ());
    return children.size ();
  }

  //
  // children
  //
  size_t Model::
  children (const std::string & type, GME::Collection_T <GME::Reference> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    // Determine how many folders there are.
    children.attach (fcos.Detach ());
    return children.size ();
  }

  //
  // children
  //
  size_t Model::
  children (const std::string & type, GME::Collection_T <GME::Set> & children) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    // Determine how many folders there are.
    children.attach (fcos.Detach ());
    return children.size ();
  }

  //
  // impl
  //
  IMgaModel * Model::impl (void) const
  {
    if (this->model_.p == this->object_.p)
      return this->model_.p;

    if (this->model_.p != 0)
      this->model_.Release ();

    VERIFY_HRESULT (this->object_.QueryInterface (&this->model_));
    return this->model_.p;
  }

  //
  // attach
  //
  void Model::attach (IMgaModel * model)
  {
    VERIFY_HRESULT (model->QueryInterface (&this->object_));
  }
}
