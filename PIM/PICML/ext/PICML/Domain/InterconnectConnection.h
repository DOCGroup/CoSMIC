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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InterconnectConnection_Impl;
  typedef InterconnectConnection_Impl * InterconnectConnection_in;
  typedef ::GAME::Mga::Smart_Ptr < InterconnectConnection_Impl > InterconnectConnection;

  // Forward decl.
  class Visitor;

  /**
   * @class InterconnectConnection_Impl
   *
   * Implementation for the InterconnectConnection model element.
   */
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

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static InterconnectConnection _create (const Domain_in parent, Node_in src, Interconnect_in dst);
    ///@}

    // Default constructor.
    InterconnectConnection_Impl (void);

    // Initializing constructor.
    InterconnectConnection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~InterconnectConnection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Domain parent_Domain (void);
    ///@}
    Node src_Node (void) const;
    Interconnect dst_Interconnect (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "InterconnectConnection.inl"
#endif

#endif  // !defined _PICML_DOMAIN_INTERCONNECTCONNECTION
