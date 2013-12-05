// -*- C++ -*-

//============================================================================
/**
 * @file    top_deadline_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DEADLINEQOSPOLICY_TOP_DEADLINE_CONNECTION_H_
#define _DQML_STANDARD_DEADLINEQOSPOLICY_TOP_DEADLINE_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class top_deadline_Connection_Impl;
  typedef top_deadline_Connection_Impl * top_deadline_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < top_deadline_Connection_Impl > top_deadline_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class top_deadline_Connection_Impl
   *
   * Implementation for the top_deadline_Connection model element.
   */
  class DQML_Export top_deadline_Connection_Impl :
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
    static top_deadline_Connection _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    top_deadline_Connection_Impl (void);

    // Initializing constructor.
    top_deadline_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~top_deadline_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    Topic src_Topic (void) const;
    DeadlineQosPolicy dst_DeadlineQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "top_deadline_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_DEADLINEQOSPOLICY_TOP_DEADLINE_CONNECTION
