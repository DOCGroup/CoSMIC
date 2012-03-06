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

///////////////////////////////////////////////////////////////////////////////
// Impl_Factory


//
// set_next
//
void Impl_Factory::set_next (Impl_Factory * n)
{
  n->next_ = this->next_;
  this->next_ = n;
}

//
// remove
//
void Impl_Factory::remove (Impl_Factory * n)
{
  if (this->next_ == n)
  {
    // Remove this link from the chain.
    this->next_ = n->next_;
    n->next_ = 0;
  }
  else if (0 != this->next_)
  {
    // Go to the next link in the chain.
    this->next_->remove (n);
  }
}

///////////////////////////////////////////////////////////////////////////////
// Default_Impl_Factory

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
: factory_methods_ (7, 0),
  meta_factory_methods_ (11, 0)
{
  // Insert the creation methods.
  this->factory_methods_[OBJTYPE_MODEL] = &allocate_impl <Model_Impl>;
  this->factory_methods_[OBJTYPE_ATOM] = &allocate_impl <Atom_Impl>;
  this->factory_methods_[OBJTYPE_REFERENCE] = &allocate_impl <Reference_Impl>;
  this->factory_methods_[OBJTYPE_CONNECTION] = &allocate_impl <Connection_Impl>;
  this->factory_methods_[OBJTYPE_SET] = &allocate_impl <Set_Impl>;
  this->factory_methods_[OBJTYPE_FOLDER] = &allocate_impl <Folder_Impl>;

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

///////////////////////////////////////////////////////////////////////////////
// Impl_Factory_Base

//
// allocate
//
Object_Impl * Impl_Factory_Base::allocate (IMgaObject * ptr)
{
  if (0 != this->next_)
    return this->next_->allocate (ptr);

  throw Exception ("failed to allocate object implementation");
}

//
// allocate
//
RegistryNode_Impl * Impl_Factory_Base::allocate (IMgaRegNode * ptr)
{
  if (0 != this->next_)
    return this->next_->allocate (ptr);

  throw Exception ("failed to allocate registry implementation");
}

//
// allocate
//
Component_Impl * Impl_Factory_Base::allocate (IMgaComponent * ptr)
{
  if (0 != this->next_)
    return this->next_->allocate (ptr);

  throw Exception ("failed to allocate component implementation");
}

//
// allocate
//
ComponentEx_Impl * Impl_Factory_Base::allocate (IMgaComponentEx * ptr)
{
  if (0 != this->next_)
    return this->next_->allocate (ptr);

  throw Exception ("failed to allocate extended component implementation");
}

//
// allocate
//
Attribute_Impl * Impl_Factory_Base::allocate (IMgaAttribute * ptr)
{
  if (0 != this->next_)
    return this->next_->allocate (ptr);

  throw Exception ("failed to allocate attribute implementation");
}

//
// allocate
//
ConnectionPoint_Impl * Impl_Factory_Base::allocate (IMgaConnPoint * ptr)
{
  if (0 != this->next_)
    return this->next_->allocate (ptr);

  throw Exception ("failed to allocate connection point implementation");
}

//
// allocate
//
Meta::Base_Impl * Impl_Factory_Base::allocate (IMgaMetaBase * ptr)
{
  if (0 != this->next_)
    return this->next_->allocate (ptr);

  throw Exception ("failed to allocate meta object implementation");
}

//
// allocate
//
Meta::Constraint_Impl * Impl_Factory_Base::allocate (IMgaConstraint * ptr)
{
  if (0 != this->next_)
    return this->next_->allocate (ptr);

  throw Exception ("failed to allocate constraint implementation");
}

//
// allocate
//
Meta::ConnectionPoint_Impl * Impl_Factory_Base::allocate (IMgaMetaConnJoint * ptr)
{
  if (0 != this->next_)
    return this->next_->allocate (ptr);

  throw Exception ("failed to allocate meta connection joint implementation");
}


}
}
