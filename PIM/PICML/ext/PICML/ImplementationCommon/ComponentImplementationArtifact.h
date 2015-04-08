// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentImplementationArtifact.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_COMPONENTIMPLEMENTATIONARTIFACT_H_
#define _PICML_IMPLEMENTATIONCOMMON_COMPONENTIMPLEMENTATIONARTIFACT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentImplementationArtifact_Impl;
  typedef ComponentImplementationArtifact_Impl * ComponentImplementationArtifact_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentImplementationArtifact_Impl > ComponentImplementationArtifact;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentImplementationArtifact_Impl
   *
   * Implementation for the ComponentImplementationArtifact model element.
   */
  class PICML_Export ComponentImplementationArtifact_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual ImplementationArtifactReference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentImplementationArtifact _create (const ImplementationContainer_in parent);
    static ComponentImplementationArtifact _create (const ArtifactContainer_in parent);
    static ComponentImplementationArtifact _create (const ExecutorProject_in parent);
    static ComponentImplementationArtifact _create (const ServantProject_in parent);
    static ComponentImplementationArtifact _create (const StubProject_in parent);
    ///@}

    // Default constructor.
    ComponentImplementationArtifact_Impl (void);

    // Initializing constructor.
    ComponentImplementationArtifact_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ComponentImplementationArtifact_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of EntryPoint
    void EntryPoint (const std::string & val);

    /// Get the value of EntryPoint
    std::string EntryPoint (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ImplementationArtifact_is_nil (void) const;
    ImplementationArtifact refers_to_ImplementationArtifact (void) const;
    void refers_to_ImplementationArtifact (ImplementationArtifact_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentImplementationArtifact.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONCOMMON_COMPONENTIMPLEMENTATIONARTIFACT
