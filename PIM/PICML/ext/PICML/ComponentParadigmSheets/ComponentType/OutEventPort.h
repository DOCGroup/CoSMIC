// -*- C++ -*-

//============================================================================
/**
 * @file    OutEventPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_OUTEVENTPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_OUTEVENTPORT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentType/EventPort.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/SingleOutputBase.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OutEventPort_Impl;
  typedef OutEventPort_Impl * OutEventPort_in;
  typedef ::GAME::Mga::Smart_Ptr < OutEventPort_Impl > OutEventPort;

  // Forward decl.
  class Visitor;

  /**
   * @class OutEventPort_Impl
   *
   * Implementation for the OutEventPort model element.
   */
  class PICML_Export OutEventPort_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual EventPort_Impl,
    public virtual SingleOutputBase_Impl
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
    static OutEventPort _create (const Component_in parent);
    static OutEventPort _create (const ConnectedComponent_in parent);
    static OutEventPort _create (const Path_in parent);
    ///@}

    // Default constructor.
    OutEventPort_Impl (void);

    // Initializing constructor.
    OutEventPort_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~OutEventPort_Impl (void);

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

    /// Set the value of single_destination
    void single_destination (bool val);

    /// Get the value of single_destination
    bool single_destination (void) const;

    /// Set the value of out_event_port_type
    void out_event_port_type (const std::string & val);

    /// Get the value of out_event_port_type
    std::string out_event_port_type (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool EventType_is_nil (void) const;
    EventType get_EventType (void) const;
    void set_EventType (EventType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "OutEventPort.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_OUTEVENTPORT
