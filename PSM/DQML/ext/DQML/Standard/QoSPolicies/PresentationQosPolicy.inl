// -*- C++ -*-
// $Id$

namespace DQML
{
  //
  // PresentationQosPolicy_Impl
  //
  GAME_INLINE PresentationQosPolicy_Impl::PresentationQosPolicy_Impl (void)
  {
  }

  //
  // PresentationQosPolicy_Impl
  //
  GAME_INLINE PresentationQosPolicy_Impl::PresentationQosPolicy_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PresentationQosPolicy_Impl
  //
  GAME_INLINE PresentationQosPolicy_Impl::~PresentationQosPolicy_Impl (void)
  {
  }

  //
  // access_scope
  //
  GAME_INLINE void PresentationQosPolicy_Impl::access_scope (const std::string & val)
  {
    static const std::string attr_name ("access_scope");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // access_scope
  //
  GAME_INLINE std::string PresentationQosPolicy_Impl::access_scope (void) const
  {
    static const std::string attr_name ("access_scope");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // coherent_access
  //
  GAME_INLINE void PresentationQosPolicy_Impl::coherent_access (bool val)
  {
    static const std::string attr_name ("coherent_access");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // coherent_access
  //
  GAME_INLINE bool PresentationQosPolicy_Impl::coherent_access (void) const
  {
    static const std::string attr_name ("coherent_access");
    return this->attribute (attr_name)->bool_value ();
  }

  //
  // ordered_access
  //
  GAME_INLINE void PresentationQosPolicy_Impl::ordered_access (bool val)
  {
    static const std::string attr_name ("ordered_access");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // ordered_access
  //
  GAME_INLINE bool PresentationQosPolicy_Impl::ordered_access (void) const
  {
    static const std::string attr_name ("ordered_access");
    return this->attribute (attr_name)->bool_value ();
  }
}

