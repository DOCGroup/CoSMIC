// -*- C++ -*-

//============================================================================
/**
 * @file    InterconnectConnection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DOMAIN_INTERCONNECTCONNECTION_H_
#define _PICML_DOMAIN_INTERCONNECTCONNECTION_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InterconnectConnection_Impl;
  typedef InterconnectConnection_Impl * InterconnectConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <InterconnectConnection_Impl> InterconnectConnection;

  // Forward decl.
  class Visitor;

  class PICML_Export InterconnectConnection_Impl :
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
    InterconnectConnection_Impl (void);

    /// Initializing constructor
    InterconnectConnection_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~InterconnectConnection_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static InterconnectConnection _create (const Domain_in parent);
    ///@}

    /// Get the src Node connection point.
    Node src_Node (void);

    /// Get the dst Interconnect connection point.
    Interconnect dst_Interconnect (void);

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
