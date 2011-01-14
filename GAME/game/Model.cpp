// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Model.h"

#if !defined (__GAME_INLINE__)
#include "Model.inl"
#endif

#include "Exception.h"
#include "Collection_T.h"

#include "Folder.h"
#include "Atom.h"
#include "Reference.h"
#include "Connection.h"
#include "Set.h"
#include "MetaFolder.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "Visitor.h"

namespace GAME
{
//
// meta
//
Meta::Model Model_Impl::meta (void) const
{
  Meta::FCO metafco = FCO_Impl::meta ();
  return Meta::Model::_narrow (metafco.get ());
}

//
// _create
//
Model Model_Impl::
_create (const Model_in parent, const std::string & type)
{
  Meta::Role role = parent->meta ()->role (type);
  return Model_Impl::_create (parent, role.get ());
}

//
// _create
//
Model Model_Impl::
_create (const Model_in parent, const Meta::Role_in role)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent->impl ()->CreateChildObject (role->impl (), &child));

  CComPtr <IMgaModel> mga_model;
  VERIFY_HRESULT (child.QueryInterface (&mga_model));

  return mga_model.p;
}

//
// _create
//
Model Model_Impl::
_create (const Folder_in parent, const std::string & type)
{
  Meta::FCO meta = parent->meta ()->child (type);
  return Model_Impl::_create (parent, meta.get ());
}

//
// _create
//
Model Model_Impl::
_create (const Folder_in parent, const Meta::FCO_in meta)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent->impl ()->CreateRootObject (meta->impl (), &child));

  CComPtr <IMgaModel> mga_model;
  VERIFY_HRESULT (child.QueryInterface (&mga_model));

  return mga_model.p;
}

//
// accept
//
void Model_Impl::accept (Visitor * v)
{
  v->visit_Model (this);
}

//
// children
//
size_t Model_Impl::children (std::vector <FCO> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const std::string & type, std::vector <FCO> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const Meta::Aspect_in apsect, std::vector <FCO> & children) const
{
  // Let's get the list of children.
  std::vector <FCO> temp;
  this->children (temp);

  std::vector <FCO>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO_Impl is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!(*iter)->part (apsect).is_nil ())
      children.push_back (*iter);
  }

  return children.size ();
}

//
// children
//
size_t Model_Impl::
children (std::vector <Atom> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const std::string & type, std::vector <Atom> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const Meta::Aspect_in apsect, std::vector <Atom> & children) const
{
  // Let's get the list of children.
  std::vector <Atom> temp;
  this->children (temp);

  std::vector <Atom>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO_Impl is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!(*iter)->part (apsect).is_nil ())
      children.push_back (*iter);
  }

  return children.size ();
}

//
// children
//
size_t Model_Impl::children (std::vector <Model> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const std::string & type, std::vector <Model> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const Meta::Aspect_in apsect, std::vector <Model> & children) const
{
  // Let's get the list of children.
  std::vector <Model> temp;
  this->children (temp);

  std::vector <Model>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO_Impl is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!(*iter)->part (apsect).is_nil ())
      children.push_back (*iter);
  }

  return children.size ();
}

//
// children
//
size_t Model_Impl::
children (std::vector <Connection> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const std::string & type, std::vector <Connection> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const Meta::Aspect_in apsect, std::vector <Connection> & children) const
{
  // Let's get the list of children.
  std::vector <Connection> temp;
  this->children (temp);

  std::vector <Connection>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO_Impl is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!(*iter)->part (apsect).is_nil ())
      children.push_back (*iter);
  }

  return children.size ();
}

//
// children
//
size_t Model_Impl::children (std::vector <Reference> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const std::string & type, std::vector <Reference> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const Meta::Aspect_in apsect, std::vector <Reference> & children) const
{
  // Let's get the list of children.
  std::vector <Reference> temp;
  this->children (temp);

  std::vector <Reference>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO_Impl is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!(*iter)->part (apsect).is_nil ())
      children.push_back (*iter);
  }

  return children.size ();
}

//
// children
//
size_t Model_Impl::
children (std::vector <Set> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const std::string & type, std::vector <Set> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return iter_to_collection (fcos.p, children);
}

//
// children
//
size_t Model_Impl::
children (const Meta::Aspect_in apsect, std::vector <Set> & children) const
{
  // Let's get the list of children.
  std::vector <Set> temp;
  this->children (temp);

  std::vector <Set>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO_Impl is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!(*iter)->part (apsect).is_nil ())
      children.push_back (*iter);
  }

  return children.size ();
}

//
// impl
//
IMgaModel * Model_Impl::impl (void) const
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
void Model_Impl::attach (IMgaModel * model)
{
  VERIFY_HRESULT (model->QueryInterface (&this->object_));
}

}
