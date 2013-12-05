// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // Node_Impl
  //
  GAME_INLINE Node_Impl::Node_Impl (void)
  {
  }

  //
  // Node_Impl
  //
  GAME_INLINE Node_Impl::Node_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Node_Impl
  //
  GAME_INLINE Node_Impl::~Node_Impl (void)
  {
  }

  //
  // label
  //
  GAME_INLINE void Node_Impl::label (const std::string & val)
  {
    static const std::string attr_name ("label");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // label
  //
  GAME_INLINE std::string Node_Impl::label (void) const
  {
    static const std::string attr_name ("label");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // operatingSystem
  //
  GAME_INLINE void Node_Impl::operatingSystem (const std::string & val)
  {
    static const std::string attr_name ("operatingSystem");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // operatingSystem
  //
  GAME_INLINE std::string Node_Impl::operatingSystem (void) const
  {
    static const std::string attr_name ("operatingSystem");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // architecture
  //
  GAME_INLINE void Node_Impl::architecture (const std::string & val)
  {
    static const std::string attr_name ("architecture");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // architecture
  //
  GAME_INLINE std::string Node_Impl::architecture (void) const
  {
    static const std::string attr_name ("architecture");
    return this->attribute (attr_name)->string_value ();
  }
}

