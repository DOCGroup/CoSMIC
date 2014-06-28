// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // ReaderLifespanQosPolicy_Impl
  //
  GAME_INLINE ReaderLifespanQosPolicy_Impl::ReaderLifespanQosPolicy_Impl (void)
  {
  }

  //
  // ReaderLifespanQosPolicy_Impl
  //
  GAME_INLINE ReaderLifespanQosPolicy_Impl::ReaderLifespanQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ReaderLifespanQosPolicy_Impl
  //
  GAME_INLINE ReaderLifespanQosPolicy_Impl::~ReaderLifespanQosPolicy_Impl (void)
  {
  }

  //
  // duration
  //
  GAME_INLINE void ReaderLifespanQosPolicy_Impl::duration (double val)
  {
    static const std::string attr_name ("duration");
    this->attribute (attr_name)->double_value (val);
  }

  //
  // duration
  //
  GAME_INLINE double ReaderLifespanQosPolicy_Impl::duration (void) const
  {
    static const std::string attr_name ("duration");
    return this->attribute (attr_name)->double_value ();
  }

  //
  // use_lifespan
  //
  GAME_INLINE void ReaderLifespanQosPolicy_Impl::use_lifespan (bool val)
  {
    static const std::string attr_name ("use_lifespan");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // use_lifespan
  //
  GAME_INLINE bool ReaderLifespanQosPolicy_Impl::use_lifespan (void) const
  {
    static const std::string attr_name ("use_lifespan");
    return this->attribute (attr_name)->bool_value ();
  }
}

