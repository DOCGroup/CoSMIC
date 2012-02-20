// -*- C++ -*-

//============================================================================
/**
 * @file    dw_deadline_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DEADLINEQOSPOLICY_DW_DEADLINE_CONNECTION_H_
#define _DQML_STANDARD_DEADLINEQOSPOLICY_DW_DEADLINE_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class dw_deadline_Connection_Impl;
  typedef dw_deadline_Connection_Impl * dw_deadline_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < dw_deadline_Connection_Impl > dw_deadline_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class dw_deadline_Connection_Impl
   *
   * Implementation for the dw_deadline_Connection model element.
   */
  class DQML_Export dw_deadline_Connection_Impl :
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
    static dw_deadline_Connection _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    dw_deadline_Connection_Impl (void);

    // Initializing constructor.
    dw_deadline_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~dw_deadline_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    DataWriter src_DataWriter (void) const;
    DeadlineQosPolicy dst_DeadlineQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "dw_deadline_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_DEADLINEQOSPOLICY_DW_DEADLINE_CONNECTION
