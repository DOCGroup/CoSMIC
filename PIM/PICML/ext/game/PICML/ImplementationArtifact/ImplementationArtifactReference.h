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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationArtifactReference_Impl;
  typedef ImplementationArtifactReference_Impl * ImplementationArtifactReference_in;
  typedef ::GAME::Mga::Smart_Ptr < ImplementationArtifactReference_Impl > ImplementationArtifactReference;

  // Forward decl.
  class Visitor;

  /**
   * @class ImplementationArtifactReference_Impl
   *
   * Implementation for the ImplementationArtifactReference model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static ImplementationArtifactReference _create (const ImplementationContainer_in parent);
    static ImplementationArtifactReference _create (const StubProject_in parent);
    static ImplementationArtifactReference _create (const ServantProject_in parent);
    static ImplementationArtifactReference _create (const ExecutorProject_in parent);
    static ImplementationArtifactReference _create (const ArtifactContainer_in parent);
    ///@}

    // Default constructor.
    ImplementationArtifactReference_Impl (void);

    // Initializing constructor.
    ImplementationArtifactReference_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ImplementationArtifactReference_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ImplementationContainer parent_ImplementationContainer (void);
    StubProject parent_StubProject (void);
    ServantProject parent_ServantProject (void);
    ExecutorProject parent_ExecutorProject (void);
    ArtifactContainer parent_ArtifactContainer (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ArtifactDependsOn connection.
    size_t dst_ArtifactDependsOn (std::vector <ArtifactDependsOn> & items) const;

    /// Get the dst MonolithprimaryArtifact connection.
    size_t dst_MonolithprimaryArtifact (std::vector <MonolithprimaryArtifact> & items) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ImplementationArtifact_is_nil (void) const;
    ImplementationArtifact get_ImplementationArtifact (void) const;
    void set_ImplementationArtifact (ImplementationArtifact_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ImplementationArtifactReference.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONARTIFACT_IMPLEMENTATIONARTIFACTREFERENCE
