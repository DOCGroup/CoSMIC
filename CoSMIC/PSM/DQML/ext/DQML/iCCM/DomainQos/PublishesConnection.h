// -*- C++ -*-

//============================================================================
/**
 * @file    PublishesConnection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_DOMAINQOS_PUBLISHESCONNECTION_H_
#define _DQML_ICCM_DOMAINQOS_PUBLISHESCONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class PublishesConnection_Impl;
  typedef PublishesConnection_Impl * PublishesConnection_in;
  typedef ::GAME::Mga::Smart_Ptr < PublishesConnection_Impl > PublishesConnection;

  // Forward decl.
  class Visitor;

  /**
   * @class PublishesConnection_Impl
   *
   * Implementation for the PublishesConnection model element.
   */
  class DQML_Export PublishesConnection_Impl :
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
    static PublishesConnection _create (const Domain_in parent);
    ///@}

    // Default constructor.
    PublishesConnection_Impl (void);

    // Initializing constructor.
    PublishesConnection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PublishesConnection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    DataWriterQos src_DataWriterQos (void) const;
    DataReaderQos dst_DataReaderQos (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "PublishesConnection.inl"
#endif

#endif  // !defined _DQML_ICCM_DOMAINQOS_PUBLISHESCONNECTION
