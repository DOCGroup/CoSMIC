// -*- C++ -*-

//============================================================================
/**
 * @file    RequiredRequestPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_REQUIREDREQUESTPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_REQUIREDREQUESTPORT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/MultiOutputBase.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequiredRequestPort_Impl;
  typedef RequiredRequestPort_Impl * RequiredRequestPort_in;
  typedef ::GAME::Mga::Smart_Ptr < RequiredRequestPort_Impl > RequiredRequestPort;

  // Forward decl.
  class Visitor;

  /**
   * @class RequiredRequestPort_Impl
   *
   * Implementation for the RequiredRequestPort model element.
   */
  class PICML_Export RequiredRequestPort_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual ObjectPort_Impl,
    public virtual MultiOutputBase_Impl
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
    static RequiredRequestPort _create (const PortType_in parent);
    static RequiredRequestPort _create (const ConnectorObject_in parent);
    static RequiredRequestPort _create (const Component_in parent);
    static RequiredRequestPort _create (const ConnectedComponent_in parent);
    static RequiredRequestPort _create (const Path_in parent);
    ///@}

    // Default constructor.
    RequiredRequestPort_Impl (void);

    // Initializing constructor.
    RequiredRequestPort_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~RequiredRequestPort_Impl (void);

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

    /// Set the value of multiple_connections
    void multiple_connections (bool val);

    /// Get the value of multiple_connections
    bool multiple_connections (void) const;

    /// Set the value of AsyncCommunication
    void AsyncCommunication (bool val);

    /// Get the value of AsyncCommunication
    bool AsyncCommunication (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Provideable_is_nil (void) const;
    Provideable refers_to_Provideable (void) const;
    void refers_to_Provideable (Provideable_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "RequiredRequestPort.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_REQUIREDREQUESTPORT
