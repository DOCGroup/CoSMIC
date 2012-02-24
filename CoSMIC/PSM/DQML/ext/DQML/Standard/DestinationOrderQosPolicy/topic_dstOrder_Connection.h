// -*- C++ -*-

//============================================================================
/**
 * @file    topic_dstOrder_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DESTINATIONORDERQOSPOLICY_TOPIC_DSTORDER_CONNECTION_H_
#define _DQML_STANDARD_DESTINATIONORDERQOSPOLICY_TOPIC_DSTORDER_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class topic_dstOrder_Connection_Impl;
  typedef topic_dstOrder_Connection_Impl * topic_dstOrder_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < topic_dstOrder_Connection_Impl > topic_dstOrder_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class topic_dstOrder_Connection_Impl
   *
   * Implementation for the topic_dstOrder_Connection model element.
   */
  class DQML_Export topic_dstOrder_Connection_Impl :
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
    static topic_dstOrder_Connection _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    topic_dstOrder_Connection_Impl (void);

    // Initializing constructor.
    topic_dstOrder_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~topic_dstOrder_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    Topic src_Topic (void) const;
    DestinationOrderQosPolicy dst_DestinationOrderQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "topic_dstOrder_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_DESTINATIONORDERQOSPOLICY_TOPIC_DSTORDER_CONNECTION