// -*- C++ -*-

//============================================================================
/**
 * @file    dw_lifespan_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_LIFESPANQOSPOLICY_DW_LIFESPAN_CONNECTION_H_
#define _DQML_STANDARD_LIFESPANQOSPOLICY_DW_LIFESPAN_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class dw_lifespan_Connection_Impl;
  typedef dw_lifespan_Connection_Impl * dw_lifespan_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < dw_lifespan_Connection_Impl > dw_lifespan_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class dw_lifespan_Connection_Impl
   *
   * Implementation for the dw_lifespan_Connection model element.
   */
  class DQML_Export dw_lifespan_Connection_Impl :
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
    static dw_lifespan_Connection _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    dw_lifespan_Connection_Impl (void);

    // Initializing constructor.
    dw_lifespan_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~dw_lifespan_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    DataWriter src_DataWriter (void) const;
    LifespanQosPolicy dst_LifespanQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "dw_lifespan_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_LIFESPANQOSPOLICY_DW_LIFESPAN_CONNECTION
