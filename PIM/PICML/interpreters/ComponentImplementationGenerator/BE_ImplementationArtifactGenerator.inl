// -*- C++ -*-
// $Id$

namespace PICML_BE
{

inline
ImplementationArtifactGenerator::
ImplementationArtifactGenerator (PICML::ImplementationArtifacts_in artifact_folder)
: artifact_folder_ (artifact_folder)
{

}

inline
ImplementationArtifactGenerator::~ImplementationArtifactGenerator (void)
{

}

inline 
PICML::ImplementationArtifact ImplementationArtifactGenerator::svnt_artifact (void) const
{
  return this->svnt_artifact_;
}

inline
PICML::ImplementationArtifact ImplementationArtifactGenerator::impl_artifact (void) const
{
  return this->impl_artifact_;
}

}
