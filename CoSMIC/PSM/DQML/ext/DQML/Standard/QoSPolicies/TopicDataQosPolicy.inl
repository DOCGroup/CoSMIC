// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // TopicDataQosPolicy_Impl
  //
  GAME_INLINE TopicDataQosPolicy_Impl::TopicDataQosPolicy_Impl (void)
  {
  }

  //
  // TopicDataQosPolicy_Impl
  //
  GAME_INLINE TopicDataQosPolicy_Impl::TopicDataQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TopicDataQosPolicy_Impl
  //
  GAME_INLINE TopicDataQosPolicy_Impl::~TopicDataQosPolicy_Impl (void)
  {
  }

  //
  // topic_value
  //
  GAME_INLINE void TopicDataQosPolicy_Impl::topic_value (const std::string & val)
  {
    static const std::string attr_name ("topic_value");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // topic_value
  //
  GAME_INLINE std::string TopicDataQosPolicy_Impl::topic_value (void) const
  {
    static const std::string attr_name ("topic_value");
    return this->attribute (attr_name)->string_value ();
  }
}

