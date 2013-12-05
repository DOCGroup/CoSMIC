// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ObjectByValue_Impl
  //
  GAME_INLINE ObjectByValue_Impl::ObjectByValue_Impl (void)
  {
  }

  //
  // ObjectByValue_Impl
  //
  GAME_INLINE ObjectByValue_Impl::ObjectByValue_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ObjectByValue_Impl
  //
  GAME_INLINE ObjectByValue_Impl::~ObjectByValue_Impl (void)
  {
  }

  //
  // abstract
  //
  GAME_INLINE void ObjectByValue_Impl::abstract (bool val)
  {
    static const std::string attr_name ("abstract");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // abstract
  //
  GAME_INLINE bool ObjectByValue_Impl::abstract (void) const
  {
    static const std::string attr_name ("abstract");
    return this->attribute (attr_name)->bool_value ();
  }
}

