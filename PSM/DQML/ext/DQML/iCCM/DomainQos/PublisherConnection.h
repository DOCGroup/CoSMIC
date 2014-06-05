// -*- C++ -*-

//============================================================================
/**
 * @file    PublisherConnection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_DOMAINQOS_PUBLISHERCONNECTION_H_
#define _DQML_ICCM_DOMAINQOS_PUBLISHERCONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class PublisherConnection_Impl;
  typedef PublisherConnection_Impl * PublisherConnection_in;
  typedef ::GAME::Mga::Smart_Ptr < PublisherConnection_Impl > PublisherConnection;

  // Forward decl.
  class Visitor;

  /**
   * @class PublisherConnection_Impl
   *
   * Implementation for the PublisherConnection model element.
   */
  class DQML_Export PublisherConnection_Impl :
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
    static PublisherConnection _create (const Participant_in parent);
    ///@}

    // Default constructor.
    PublisherConnection_Impl (void);

    // Initializing constructor.
    PublisherConnection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PublisherConnection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Participant parent_Participant (void);
    ///@}
    DataWriterQos src_DataWriterQos (void) const;
    PublisherQos dst_PublisherQos (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "PublisherConnection.inl"
#endif

#endif  // !defined _DQML_ICCM_DOMAINQOS_PUBLISHERCONNECTION
