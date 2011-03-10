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

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BridgeConnection_Impl;
  typedef BridgeConnection_Impl * BridgeConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <BridgeConnection_Impl> BridgeConnection;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    BridgeConnection_Impl (void);

    /// Initializing constructor
    BridgeConnection_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~BridgeConnection_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static BridgeConnection _create (const Domain_in parent);
    ///@}

    /// Get the src Interconnect connection point.
    Interconnect src_Interconnect (void);

    /// Get the dst Bridge connection point.
    Bridge dst_Bridge (void);

    /**
     * @name Parent Methods
     */
    ///@{
    Domain parent_Domain (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
