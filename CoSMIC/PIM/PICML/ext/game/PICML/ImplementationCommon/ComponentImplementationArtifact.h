// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentImplementationArtifact.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_COMPONENTIMPLEMENTATIONARTIFACT_H_
#define _PICML_IMPLEMENTATIONCOMMON_COMPONENTIMPLEMENTATIONARTIFACT_H_

#include "game/mga/Reference.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentImplementationArtifact_Impl;
  typedef ComponentImplementationArtifact_Impl * ComponentImplementationArtifact_in;
  typedef ::GAME::Mga::Smart_Ptr <ComponentImplementationArtifact_Impl> ComponentImplementationArtifact;

  // Forward decl.
  class Visitor;

  class PICML_Export ComponentImplementationArtifact_Impl :
    public virtual ImplementationArtifactReference_Impl,
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
    ComponentImplementationArtifact_Impl (void);

    /// Initializing constructor
    ComponentImplementationArtifact_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ComponentImplementationArtifact_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
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
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
