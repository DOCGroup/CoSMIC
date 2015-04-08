// -*- C++ -*-
namespace PICML
{
  //
  // ComponentServantArtifact_Impl
  //
  GAME_INLINE ComponentServantArtifact_Impl::ComponentServantArtifact_Impl (void)
  {
  }

  //
  // ComponentServantArtifact_Impl
  //
  GAME_INLINE ComponentServantArtifact_Impl::ComponentServantArtifact_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentServantArtifact_Impl
  //
  GAME_INLINE ComponentServantArtifact_Impl::~ComponentServantArtifact_Impl (void)
  {
  }

  //
  // EntryPoint
  //
  GAME_INLINE void ComponentServantArtifact_Impl::EntryPoint (const std::string & val)
  {
    static const std::string attr_name ("EntryPoint");
    this->attribute (attr_name)->string_value (val);
  }

  //
  // EntryPoint
  //
  GAME_INLINE std::string ComponentServantArtifact_Impl::EntryPoint (void) const
  {
    static const std::string attr_name ("EntryPoint");
    return this->attribute (attr_name)->string_value ();
  }
}

