// -*- C++ -*-

//============================================================================
/**
 * @file    BridgeConnection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DOMAIN_BRIDGECONNECTION_H_
#define _PICML_DOMAIN_BRIDGECONNECTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BridgeConnection_Impl;
  typedef BridgeConnection_Impl * BridgeConnection_in;
  typedef ::GAME::Mga::Smart_Ptr < BridgeConnection_Impl > BridgeConnection;

  // Forward decl.
  class Visitor;

  /**
   * @class BridgeConnection_Impl
   *
   * Implementation for the BridgeConnection model element.
   */
  class PICML_Export BridgeConnection_Impl :
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
    static BridgeConnection _create (const Domain_in parent);
    ///@}

    // Default constructor.
    BridgeConnection_Impl (void);

    // Initializing constructor.
    BridgeConnection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~BridgeConnection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
    Interconnect src_Interconnect (void) const;
    Bridge dst_Bridge (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "BridgeConnection.inl"
#endif

#endif  // !defined _PICML_DOMAIN_BRIDGECONNECTION
