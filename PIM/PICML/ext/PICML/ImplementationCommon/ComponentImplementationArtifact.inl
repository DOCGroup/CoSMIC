// -*- C++ -*-
namespace PICML
{
  //
  // ComponentImplementationArtifact_Impl
  //
  GAME_INLINE ComponentImplementationArtifact_Impl::ComponentImplementationArtifact_Impl (void)
  {
  }

  //
  // ComponentImplementationArtifact_Impl
  //
  GAME_INLINE ComponentImplementationArtifact_Impl::ComponentImplementationArtifact_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentImplementationArtifact_Impl
  //
  GAME_INLINE ComponentImplementationArtifact_Impl::~ComponentImplementationArtifact_Impl (void)
  {
  }

  //
  // EntryPoint
  //
  GAME_INLINE void ComponentImplementationArtifact_Impl::EntryPoint (const std::string & val)
  {
    static const std::string attr_name ("EntryPoint");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // EntryPoint
  //
  GAME_INLINE std::string ComponentImplementationArtifact_Impl::EntryPoint (void) const
  {
    static const std::string attr_name ("EntryPoint");
    return this->attribute (attr_name)->string_value ();
  }
}

