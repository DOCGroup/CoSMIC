// $Id$

#include "stdafx.h"
#include "mga.h"

#include "Impl_Factory.h"

#if !defined (__GAME_INLINE__)
#include "Impl_Factory.inl"
#endif

#include "Atom.h"
#include "Model.h"
#include "Folder.h"
#include "Reference.h"
#include "Set.h"
#include "Functional_T.h"
#include "RegistryNode.h"
#include "Component.h"
#include "ComponentEx.h"
#include "Attribute.h"
#include "Connection.h"

#include "MetaAspect.h"
#include "MetaAtom.h"
#include "MetaAttribute.h"
#include "MetaConnection.h"
#include "MetaConstraint.h"
#include "MetaFolder.h"
#include "MetaModel.h"
#include "MetaPart.h"
#include "MetaReference.h"
#include "MetaRole.h"
#include "MetaSet.h"

#include <assert.h>

namespace GAME
{
namespace Mga
{

//
// allocate_meta_impl
//
template <typename T>
static Meta::Base_Impl * allocate_meta_impl (IMgaMetaBase * ptr)
{
  CComPtr <typename T::interface_type> temp;
  VERIFY_HRESULT (ptr->QueryInterface (&temp));

  return new T (temp);
}

//
// Default_Impl_Factory
//
Default_Impl_Factory::Default_Impl_Factory (void)
: impl_ (0)
{
  // Insert the creation methods.
  this->factory_methods_.resize (7, 0);
  this->factory_methods_[OBJTYPE_MODEL] = &allocate_impl <Model_Impl>;
  this->factory_methods_[OBJTYPE_ATOM] = &allocate_impl <Atom_Impl>;
  this->factory_methods_[OBJTYPE_REFERENCE] = &allocate_impl <Reference_Impl>;
  this->factory_methods_[OBJTYPE_CONNECTION] = &allocate_impl <Connection_Impl>;
  this->factory_methods_[OBJTYPE_SET] = &allocate_impl <Set_Impl>;
  this->factory_methods_[OBJTYPE_FOLDER] = &allocate_impl <Folder_Impl>;

  this->meta_factory_methods_.resize (11, 0);
  this->meta_factory_methods_[OBJTYPE_MODEL] = &allocate_meta_impl <Meta::Model_Impl>;
  this->meta_factory_methods_[OBJTYPE_ATOM] = &allocate_meta_impl <Meta::Atom_Impl>;
  this->meta_factory_methods_[OBJTYPE_REFERENCE] = &allocate_meta_impl <Meta::Reference_Impl>;
  this->meta_factory_methods_[OBJTYPE_CONNECTION] = &allocate_meta_impl <Meta::Connection_Impl>;
  this->meta_factory_methods_[OBJTYPE_SET] = &allocate_meta_impl <Meta::Set_Impl>;
  this->meta_factory_methods_[OBJTYPE_FOLDER] = &allocate_meta_impl <Meta::Folder_Impl>;
  this->meta_factory_methods_[OBJTYPE_ASPECT] = &allocate_meta_impl <Meta::Aspect_Impl>;
  this->meta_factory_methods_[OBJTYPE_ROLE] = &allocate_meta_impl <Meta::Role_Impl>;
  this->meta_factory_methods_[OBJTYPE_ATTRIBUTE] = &allocate_meta_impl <Meta::Attribute_Impl>;
  this->meta_factory_methods_[OBJTYPE_PART] = &allocate_meta_impl <Meta::Part_Impl>;
}

//
// allocate
//
Object_Impl * Default_Impl_Factory::allocate (IMgaObject * ptr)
{
  if (0 == ptr)
    return 0;

  if (0 != this->impl_)
  {
    // Try and create an implementation using the installed
    // implementation factory. If we fail to create an implementation,
    // then we must fallback to the fundamental implementatations.
    Object_Impl * impl = this->impl_->allocate (ptr);

    if (0 != impl)
      return impl;
  }

  // Locate the factory method for this type.
  objtype_enum type;
  VERIFY_HRESULT (ptr->get_ObjType (&type));
  FACTORY_METHOD fm = this->factory_methods_[type];

  // Debug assertion.
  assert (fm != 0);

  return fm (ptr);
}

//
// allocate
//
Meta::Base_Impl * Default_Impl_Factory::allocate (IMgaMetaBase * ptr)
{
  if (0 == ptr)
    return 0;

  // Locate the factory method for this type.
  objtype_enum type;
  VERIFY_HRESULT (ptr->get_ObjType (&type));

  META_FACTORY_METHOD mfm = this->meta_factory_methods_[type];

  // Debug assertion.
  assert (mfm != 0);

  return mfm (ptr);
}

//
// allocate
//
RegistryNode_Impl * Default_Impl_Factory::allocate (IMgaRegNode * ptr)
{
  return 0 != ptr ? new RegistryNode_Impl (ptr) : 0;
}

//
// allocate
//
Component_Impl * Default_Impl_Factory::allocate (IMgaComponent * ptr)
{
  return 0 != ptr ? new Component_Impl (ptr) : 0;
}

//
// allocate
//
ComponentEx_Impl * Default_Impl_Factory::allocate (IMgaComponentEx * ptr)
{
  return 0 != ptr ? new ComponentEx_Impl (ptr) : 0;
}

//
// allocate
//
Attribute_Impl * Default_Impl_Factory::allocate (IMgaAttribute * ptr)
{
  return 0 != ptr ? new Attribute_Impl (ptr) : 0;
}

//
// allocate
//
Meta::Constraint_Impl * Default_Impl_Factory::allocate (IMgaConstraint * ptr)
{
  return 0 != ptr ? new Meta::Constraint_Impl (ptr) : 0;
}

//
// allocate
//
ConnectionPoint_Impl * Default_Impl_Factory::allocate (IMgaConnPoint * ptr)
{
  return 0 != ptr ? new ConnectionPoint_Impl (ptr) : 0;
}

//
// allocate
//
Meta::ConnectionPoint_Impl * Default_Impl_Factory::allocate (IMgaMetaConnJoint * ptr)
{
  return 0 != ptr ? new Meta::ConnectionPoint_Impl (ptr) : 0;
}

}
}
