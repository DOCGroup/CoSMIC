// -*- C++ -*-
namespace DQML
{
  //
  // HistoryQosPolicy_Impl
  //
  GAME_INLINE HistoryQosPolicy_Impl::HistoryQosPolicy_Impl (void)
  {
  }

  //
  // HistoryQosPolicy_Impl
  //
  GAME_INLINE HistoryQosPolicy_Impl::HistoryQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~HistoryQosPolicy_Impl
  //
  GAME_INLINE HistoryQosPolicy_Impl::~HistoryQosPolicy_Impl (void)
  {
  }

  //
  // history_kind
  //
  GAME_INLINE void HistoryQosPolicy_Impl::history_kind (const std::string & val)
  {
    static const std::string attr_name ("history_kind");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // history_kind
  //
  GAME_INLINE std::string HistoryQosPolicy_Impl::history_kind (void) const
  {
    static const std::string attr_name ("history_kind");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // history_depth
  //
  GAME_INLINE void HistoryQosPolicy_Impl::history_depth (long val)
  {
    static const std::string attr_name ("history_depth");
    this->attribute (attr_name)->int_value (val);
  }

  //
  // history_depth
  //
  GAME_INLINE long HistoryQosPolicy_Impl::history_depth (void) const
  {
    static const std::string attr_name ("history_depth");
    return this->attribute (attr_name)->int_value ();
  }
}

