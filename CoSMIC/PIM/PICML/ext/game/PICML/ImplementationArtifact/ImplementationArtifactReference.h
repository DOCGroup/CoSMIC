// -*- C++ -*-

//============================================================================
/**
 * @file    ImplementationArtifactReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONARTIFACT_IMPLEMENTATIONARTIFACTREFERENCE_H_
#define _PICML_IMPLEMENTATIONARTIFACT_IMPLEMENTATIONARTIFACTREFERENCE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationArtifactReference_Impl;
  typedef ImplementationArtifactReference_Impl * ImplementationArtifactReference_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationArtifactReference_Impl> ImplementationArtifactReference;

  // Forward decl.
  class Visitor;

  class PICML_Export ImplementationArtifactReference_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ImplementationArtifactReference_Impl (void);

    /// Initializing constructor
    ImplementationArtifactReference_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ImplementationArtifactReference_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ImplementationArtifactReference _create (const ArtifactContainer_in parent);
    ///@}
    size_t in_ArtifactDependsOn_connections (std::vector <ArtifactDependsOn> & conns) const;

    /**
     * @name Parent Methods
     */
    ///@{
    ArtifactContainer parent_ArtifactContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ImplementationArtifact refers_to_ImplementationArtifact (void) const;
    ///@}
  };
}

#endif
