// -*- C++ -*-

//============================================================================
/**
 * @file    EventSourceDelegate.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EVENTSOURCEDELEGATE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EVENTSOURCEDELEGATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EventSourceDelegate_Impl;
  typedef EventSourceDelegate_Impl * EventSourceDelegate_in;
  typedef ::GAME::Mga::Smart_Ptr < EventSourceDelegate_Impl > EventSourceDelegate;

  // Forward decl.
  class Visitor;

  /**
   * @class EventSourceDelegate_Impl
   *
   * Implementation for the EventSourceDelegate model element.
   */
  class PICML_Export EventSourceDelegate_Impl :
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
    static EventSourceDelegate _create (const ComponentAssembly_in parent, OutEventPortEnd_in src, OutEventPortDelegate_in dst);
    ///@}

    // Default constructor.
    EventSourceDelegate_Impl (void);

    // Initializing constructor.
    EventSourceDelegate_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~EventSourceDelegate_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}
    OutEventPortEnd src_OutEventPortEnd (void) const;
    OutEventPortDelegate dst_OutEventPortDelegate (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "EventSourceDelegate.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_EVENTSOURCEDELEGATE
