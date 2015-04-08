// -*- C++ -*-
namespace PICML
{
  //
  // CommonPortAttrs_Impl
  //
  GAME_INLINE CommonPortAttrs_Impl::CommonPortAttrs_Impl (void)
  {
  }

  //
  // CommonPortAttrs_Impl
  //
  GAME_INLINE CommonPortAttrs_Impl::CommonPortAttrs_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~CommonPortAttrs_Impl
  //
  GAME_INLINE CommonPortAttrs_Impl::~CommonPortAttrs_Impl (void)
  {
  }

  //
  // optional
  //
  GAME_INLINE void CommonPortAttrs_Impl::optional (bool val)
  {
    static const std::string attr_name ("optional");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // optional
  //
  GAME_INLINE bool CommonPortAttrs_Impl::optional (void) const
  {
    static const std::string attr_name ("optional");
    return this->attribute (attr_name)->bool_value ();
  }

  //
  // exclusiveUser
  //
  GAME_INLINE void CommonPortAttrs_Impl::exclusiveUser (bool val)
  {
    static const std::string attr_name ("exclusiveUser");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // exclusiveUser
  //
  GAME_INLINE bool CommonPortAttrs_Impl::exclusiveUser (void) const
  {
    static const std::string attr_name ("exclusiveUser");
    return this->attribute (attr_name)->bool_value ();
  }

  //
  // exclusiveProvider
  //
  GAME_INLINE void CommonPortAttrs_Impl::exclusiveProvider (bool val)
  {
    static const std::string attr_name ("exclusiveProvider");
    this->attribute (attr_name)->bool_value (val);
  }

  //
  // exclusiveProvider
  //
  GAME_INLINE bool CommonPortAttrs_Impl::exclusiveProvider (void) const
  {
    static const std::string attr_name ("exclusiveProvider");
    return this->attribute (attr_name)->bool_value ();
  }
}

