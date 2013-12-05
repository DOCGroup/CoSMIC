// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // PartitionQosPolicy_Impl
  //
  GAME_INLINE PartitionQosPolicy_Impl::PartitionQosPolicy_Impl (void)
  {
  }

  //
  // PartitionQosPolicy_Impl
  //
  GAME_INLINE PartitionQosPolicy_Impl::PartitionQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PartitionQosPolicy_Impl
  //
  GAME_INLINE PartitionQosPolicy_Impl::~PartitionQosPolicy_Impl (void)
  {
  }

  //
  // partition_name
  //
  GAME_INLINE void PartitionQosPolicy_Impl::partition_name (const std::string & val)
  {
    static const std::string attr_name ("partition_name");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // partition_name
  //
  GAME_INLINE std::string PartitionQosPolicy_Impl::partition_name (void) const
  {
    static const std::string attr_name ("partition_name");
    return this->attribute (attr_name)->string_value ();
  }
}

