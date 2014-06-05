// -*- C++ -*-

//============================================================================
/**
 * @file    dw_ownership_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_OWNERSHIPQOSPOLICY_DW_OWNERSHIP_CONNECTION_H_
#define _DQML_STANDARD_OWNERSHIPQOSPOLICY_DW_OWNERSHIP_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class dw_ownership_Connection_Impl;
  typedef dw_ownership_Connection_Impl * dw_ownership_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < dw_ownership_Connection_Impl > dw_ownership_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class dw_ownership_Connection_Impl
   *
   * Implementation for the dw_ownership_Connection model element.
   */
  class DQML_Export dw_ownership_Connection_Impl :
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
    static dw_ownership_Connection _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    dw_ownership_Connection_Impl (void);

    // Initializing constructor.
    dw_ownership_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~dw_ownership_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    DataWriter src_DataWriter (void) const;
    OwnershipQosPolicy dst_OwnershipQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "dw_ownership_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_OWNERSHIPQOSPOLICY_DW_OWNERSHIP_CONNECTION
