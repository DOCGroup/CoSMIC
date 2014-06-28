// -*- C++ -*-
// $Id$

namespace PICML
{
  //
  // ImplementationArtifact_Impl
  //
  GAME_INLINE ImplementationArtifact_Impl::ImplementationArtifact_Impl (void)
  {
  }

  //
  // ImplementationArtifact_Impl
  //
  GAME_INLINE ImplementationArtifact_Impl::ImplementationArtifact_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ImplementationArtifact_Impl
  //
  GAME_INLINE ImplementationArtifact_Impl::~ImplementationArtifact_Impl (void)
  {
  }

  //
  // UUID
  //
  GAME_INLINE void ImplementationArtifact_Impl::UUID (const std::string & val)
  {
    static const std::string attr_name ("UUID");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // UUID
  //
  GAME_INLINE std::string ImplementationArtifact_Impl::UUID (void) const
  {
    static const std::string attr_name ("UUID");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // label
  //
  GAME_INLINE void ImplementationArtifact_Impl::label (const std::string & val)
  {
    static const std::string attr_name ("label");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // label
  //
  GAME_INLINE std::string ImplementationArtifact_Impl::label (void) const
  {
    static const std::string attr_name ("label");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // location
  //
  GAME_INLINE void ImplementationArtifact_Impl::location (const std::string & val)
  {
    static const std::string attr_name ("location");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // location
  //
  GAME_INLINE std::string ImplementationArtifact_Impl::location (void) const
  {
    static const std::string attr_name ("location");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // artifactVersion
  //
  GAME_INLINE void ImplementationArtifact_Impl::artifactVersion (const std::string & val)
  {
    static const std::string attr_name ("artifactVersion");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // artifactVersion
  //
  GAME_INLINE std::string ImplementationArtifact_Impl::artifactVersion (void) const
  {
    static const std::string attr_name ("artifactVersion");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // operatingSystem
  //
  GAME_INLINE void ImplementationArtifact_Impl::operatingSystem (const std::string & val)
  {
    static const std::string attr_name ("operatingSystem");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // operatingSystem
  //
  GAME_INLINE std::string ImplementationArtifact_Impl::operatingSystem (void) const
  {
    static const std::string attr_name ("operatingSystem");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // configuration
  //
  GAME_INLINE void ImplementationArtifact_Impl::configuration (const std::string & val)
  {
    static const std::string attr_name ("configuration");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // configuration
  //
  GAME_INLINE std::string ImplementationArtifact_Impl::configuration (void) const
  {
    static const std::string attr_name ("configuration");
    return this->attribute (attr_name)->string_value ();
  }

  //
  // architecture
  //
  GAME_INLINE void ImplementationArtifact_Impl::architecture (const std::string & val)
  {
    static const std::string attr_name ("architecture");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // architecture
  //
  GAME_INLINE std::string ImplementationArtifact_Impl::architecture (void) const
  {
    static const std::string attr_name ("architecture");
    return this->attribute (attr_name)->string_value ();
  }
}

