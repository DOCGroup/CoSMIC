// -*- C++ -*-

//============================================================================
/**
 * @file    ImplementationCapability.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_IMPLEMENTATIONCAPABILITY_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_IMPLEMENTATIONCAPABILITY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationCapability_Impl;
  typedef ImplementationCapability_Impl * ImplementationCapability_in;
  typedef ::GAME::Mga::Smart_Ptr < ImplementationCapability_Impl > ImplementationCapability;

  // Forward decl.
  class Visitor;

  /**
   * @class ImplementationCapability_Impl
   *
   * Implementation for the ImplementationCapability model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ImplementationCapability _create (const ComponentImplementationContainer_in parent, ComponentImplementation_in src, Capability_in dst);
    ///@}

    // Default constructor.
    ImplementationCapability_Impl (void);

    // Initializing constructor.
    ImplementationCapability_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ImplementationCapability_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentImplementationContainer parent_ComponentImplementationContainer (void);
    ///@}
    ComponentImplementation src_ComponentImplementation (void) const;
    Capability dst_Capability (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ImplementationCapability.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_IMPLEMENTATIONCAPABILITY
