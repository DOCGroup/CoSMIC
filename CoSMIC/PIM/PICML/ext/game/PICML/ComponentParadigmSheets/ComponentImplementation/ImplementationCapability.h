// -*- C++ -*-

//============================================================================
/**
 * @file    ImplementationCapability.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_IMPLEMENTATIONCAPABILITY_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_IMPLEMENTATIONCAPABILITY_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationCapability_Impl;
  typedef ImplementationCapability_Impl * ImplementationCapability_in;
  typedef ::GAME::Mga::Smart_Ptr <ImplementationCapability_Impl> ImplementationCapability;

  // Forward decl.
  class Visitor;

  class PICML_Export ImplementationCapability_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ImplementationCapability_Impl (void);

    /// Initializing constructor
    ImplementationCapability_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~ImplementationCapability_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ImplementationCapability _create (const ComponentImplementationContainer_in parent);
    ///@}

    /// Get the src ComponentImplementation connection point.
    ComponentImplementation src_ComponentImplementation (void);

    /// Get the dst Capability connection point.
    Capability dst_Capability (void);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentImplementationContainer parent_ComponentImplementationContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
