// -*- C++ -*-

//============================================================================
/**
 * @file    dw_dstOrder_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DESTINATIONORDERQOSPOLICY_DW_DSTORDER_CONNECTION_H_
#define _DQML_STANDARD_DESTINATIONORDERQOSPOLICY_DW_DSTORDER_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class dw_dstOrder_Connection_Impl;
  typedef dw_dstOrder_Connection_Impl * dw_dstOrder_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < dw_dstOrder_Connection_Impl > dw_dstOrder_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class dw_dstOrder_Connection_Impl
   *
   * Implementation for the dw_dstOrder_Connection model element.
   */
  class DQML_Export dw_dstOrder_Connection_Impl :
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
    static dw_dstOrder_Connection _create (const DDSQoS_in parent, DataWriter_in src, DestinationOrderQosPolicy_in dst);
    ///@}

    // Default constructor.
    dw_dstOrder_Connection_Impl (void);

    // Initializing constructor.
    dw_dstOrder_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~dw_dstOrder_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    DataWriter src_DataWriter (void) const;
    DestinationOrderQosPolicy dst_DestinationOrderQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "dw_dstOrder_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_DESTINATIONORDERQOSPOLICY_DW_DSTORDER_CONNECTION
