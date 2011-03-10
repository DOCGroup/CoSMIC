// -*- C++ -*-

//============================================================================
/**
 * @file    EventSinkDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EVENTSINKDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EVENTSINKDELEGATE_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EventSinkDelegate_Impl;
  typedef EventSinkDelegate_Impl * EventSinkDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr <EventSinkDelegate_Impl> EventSinkDelegate;

  // Forward decl.
  class Visitor;

  class PICML_Export EventSinkDelegate_Impl :
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
    EventSinkDelegate_Impl (void);

    /// Initializing constructor
    EventSinkDelegate_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~EventSinkDelegate_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /// Get the src InEventPortDelegate connection point.
    InEventPortDelegate src_InEventPortDelegate (void);

    /// Get the dst InEventPortEnd connection point.
    InEventPortEnd dst_InEventPortEnd (void);

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
