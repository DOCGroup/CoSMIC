// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // EntityFactoryQosPolicy_Impl
  //
  GAME_INLINE EntityFactoryQosPolicy_Impl::EntityFactoryQosPolicy_Impl (void)
  {
  }

  //
  // EntityFactoryQosPolicy_Impl
  //
  GAME_INLINE EntityFactoryQosPolicy_Impl::EntityFactoryQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~EntityFactoryQosPolicy_Impl
  //
  GAME_INLINE EntityFactoryQosPolicy_Impl::~EntityFactoryQosPolicy_Impl (void)
  {
  }

  //
  // autoenable_created_entities
  //
  GAME_INLINE void EntityFactoryQosPolicy_Impl::autoenable_created_entities (bool val)
  {
    static const std::string attr_name ("autoenable_created_entities");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // autoenable_created_entities
  //
  GAME_INLINE bool EntityFactoryQosPolicy_Impl::autoenable_created_entities (void) const
  {
    static const std::string attr_name ("autoenable_created_entities");
    return this->attribute (attr_name)->bool_value ();
  }
}

