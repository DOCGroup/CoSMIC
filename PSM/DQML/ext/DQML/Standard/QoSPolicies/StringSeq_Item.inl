// -*- C++ -*-
namespace DQML
{
  //
  // StringSeq_Item_Impl
  //
  GAME_INLINE StringSeq_Item_Impl::StringSeq_Item_Impl (void)
  {
  }

  //
  // StringSeq_Item_Impl
  //
  GAME_INLINE StringSeq_Item_Impl::StringSeq_Item_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~StringSeq_Item_Impl
  //
  GAME_INLINE StringSeq_Item_Impl::~StringSeq_Item_Impl (void)
  {
  }

  //
  // value
  //
  GAME_INLINE void StringSeq_Item_Impl::value (const std::string & val)
  {
    static const std::string attr_name ("value");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // value
  //
  GAME_INLINE std::string StringSeq_Item_Impl::value (void) const
  {
    static const std::string attr_name ("value");
    return this->attribute (attr_name)->string_value ();
  }
}

