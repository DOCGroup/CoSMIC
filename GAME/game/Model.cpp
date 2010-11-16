// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "Model.h"

#if !defined (__GAME_INLINE__)
#include "Model.inl"
#endif

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
Model Model::_narrow (const Object & object)
{
  CComPtr <IMgaModel> model;

  VERIFY_HRESULT_THROW_EX (object.impl ()->QueryInterface (&model),
                           Invalid_Cast ());

  return model.p;
}

//
// _create
//
Model Model::_create (Model parent, const std::string & type)
{
  Meta::Role role = parent.meta ().role (type);
  return Model::_create (parent, role);
}

//
// _create
//
Model Model::_create (Model parent, const Meta::Role & role)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent.impl ()->CreateChildObject (role, &child));

  return Model::_narrow (FCO (child));
}

//
// _create
//
Model Model::_create (Folder parent, const std::string & type)
{
  Meta::FCO meta = parent.meta ().child (type);
  return Model::_create (parent, meta);
}

//
// _create
//
Model Model::_create (Folder parent, const Meta::FCO & meta)
{
  CComPtr <IMgaFCO> child;
  VERIFY_HRESULT (parent.impl ()->CreateRootObject (meta.impl (), &child));

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
size_t Model::children (std::vector <FCO> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return get_children (fcos, children);
}

//
// children
//
size_t Model::
children (const std::string & type, std::vector <FCO> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return get_children (fcos, children);
}

//
// children
//
size_t Model::
children (const Meta::Aspect & apsect, std::vector <FCO> & children) const
{
  // Let's get the list of children.
  std::vector <FCO> temp;
  this->children (temp);

  std::vector <FCO>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!iter->part (apsect).is_nil ())
      children.push_back (*iter);
  }

  return children.size ();
}

//
// children
//
size_t Model::
children (std::vector <Atom> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return get_children (fcos, children);
}

//
// children
//
size_t Model::
children (const std::string & type, std::vector <Atom> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return get_children (fcos, children);
}

//
// children
//
size_t Model::
children (const Meta::Aspect & apsect, std::vector <Atom> & children) const
{
  // Let's get the list of children.
  std::vector <Atom> temp;
  this->children (temp);

  std::vector <Atom>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!iter->part (apsect).is_nil ())
      children.push_back (*iter);
  }

  return children.size ();
}

//
// children
//
size_t Model::
children (std::vector <Model> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return get_children (fcos, children);
}

//
// children
//
size_t Model::
children (const std::string & type, std::vector <Model> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return get_children (fcos, children);
}

//
// children
//
size_t Model::
children (const Meta::Aspect & apsect, std::vector <Model> & children) const
{
  // Let's get the list of children.
  std::vector <Model> temp;
  this->children (temp);

  std::vector <Model>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!iter->part (apsect).is_nil ())
      children.push_back (*iter);
  }

  return children.size ();
}

//
// children
//
size_t Model::
children (std::vector <Connection> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return get_children (fcos, children);
}

//
// children
//
size_t Model::
children (const std::string & type, std::vector <Connection> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return get_children (fcos, children);
}

//
// children
//
size_t Model::
children (const Meta::Aspect & apsect, std::vector <Connection> & children) const
{
  // Let's get the list of children.
  std::vector <Connection> temp;
  this->children (temp);

  std::vector <Connection>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!iter->part (apsect).is_nil ())
      children.push_back (*iter);
  }

  return children.size ();
}

//
// children
//
size_t Model::
children (const std::string & type, std::vector <Set> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return get_children (fcos, children);
}

//
// children
//
size_t Model::children (std::vector <Reference> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->impl ()->get_ChildFCOs (&fcos));

  return get_children (fcos, children);
}

//
// children
//
size_t Model::
children (const std::string & type, std::vector <Reference> & children) const
{
  CComPtr <IMgaFCOs> fcos;
  CComBSTR bstr (type.length (), type.c_str ());
  VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

  return get_children (fcos, children);
}

//
// children
//
size_t Model::
children (const Meta::Aspect & apsect, std::vector <Reference> & children) const
{
  // Let's get the list of children.
  std::vector <Reference> temp;
  this->children (temp);

  std::vector <Reference>::const_iterator
    iter = temp.begin (), iter_end = temp.end ();

  // Determine what FCO is part of the specified aspect.
  for (; iter != iter_end; ++ iter)
  {
    if (!iter->part (apsect).is_nil ())
      children.push_back (*iter);
  }

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
