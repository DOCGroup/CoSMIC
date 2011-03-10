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

#include "game/mga/Reference.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventPort.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OutEventPort_Impl;
  typedef OutEventPort_Impl * OutEventPort_in;
  typedef ::GAME::Mga::Smart_Ptr <OutEventPort_Impl> OutEventPort;

  // Forward decl.
  class Visitor;

  class PICML_Export OutEventPort_Impl :
    public virtual EventPort_Impl,
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
    OutEventPort_Impl (void);

    /// Initializing constructor
    OutEventPort_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~OutEventPort_Impl (void);

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

    /// Set the value of out_event_port_type
    void out_event_port_type (const std::string & val);

    /// Get the value of out_event_port_type
    std::string out_event_port_type (void) const;

    /// Set the value of single_destination
    void single_destination (bool val);

    /// Get the value of single_destination
    bool single_destination (void) const;
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
    EventType refers_to_EventType (void) const;
    ///@}
  };
}

#endif
