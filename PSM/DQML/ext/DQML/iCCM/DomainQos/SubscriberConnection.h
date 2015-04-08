// -*- C++ -*-

//============================================================================
/**
 * @file    SubscriberConnection.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_DOMAINQOS_SUBSCRIBERCONNECTION_H_
#define _DQML_ICCM_DOMAINQOS_SUBSCRIBERCONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class SubscriberConnection_Impl;
  typedef SubscriberConnection_Impl * SubscriberConnection_in;
  typedef ::GAME::Mga::Smart_Ptr < SubscriberConnection_Impl > SubscriberConnection;

  // Forward decl.
  class Visitor;

  /**
   * @class SubscriberConnection_Impl
   *
   * Implementation for the SubscriberConnection model element.
   */
  class DQML_Export SubscriberConnection_Impl :
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
    static SubscriberConnection _create (const Participant_in parent, DataReaderQos_in src, SubscriberQos_in dst);
    ///@}

    // Default constructor.
    SubscriberConnection_Impl (void);

    // Initializing constructor.
    SubscriberConnection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~SubscriberConnection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Participant parent_Participant (void);
    ///@}
    DataReaderQos src_DataReaderQos (void) const;
    SubscriberQos dst_SubscriberQos (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "SubscriberConnection.inl"
#endif

#endif  // !defined _DQML_ICCM_DOMAINQOS_SUBSCRIBERCONNECTION
