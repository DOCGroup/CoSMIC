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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EventSinkDelegate_Impl;
  typedef EventSinkDelegate_Impl * EventSinkDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < EventSinkDelegate_Impl > EventSinkDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class EventSinkDelegate_Impl
   *
   * Implementation for the EventSinkDelegate model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static EventSinkDelegate _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    EventSinkDelegate_Impl (void);

    // Initializing constructor.
    EventSinkDelegate_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~EventSinkDelegate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
    InEventPortDelegate src_InEventPortDelegate (void) const;
    InEventPortEnd dst_InEventPortEnd (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "EventSinkDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EVENTSINKDELEGATE
