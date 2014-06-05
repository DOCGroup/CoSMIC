// -*- C++ -*-

//============================================================================
/**
 * @file    dp_sub_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_MAIN_DP_SUB_CONNECTION_H_
#define _DQML_STANDARD_MAIN_DP_SUB_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class dp_sub_Connection_Impl;
  typedef dp_sub_Connection_Impl * dp_sub_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < dp_sub_Connection_Impl > dp_sub_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class dp_sub_Connection_Impl
   *
   * Implementation for the dp_sub_Connection model element.
   */
  class DQML_Export dp_sub_Connection_Impl :
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
    static dp_sub_Connection _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    dp_sub_Connection_Impl (void);

    // Initializing constructor.
    dp_sub_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~dp_sub_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    DomainParticipant src_DomainParticipant (void) const;
    Subscriber dst_Subscriber (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "dp_sub_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_MAIN_DP_SUB_CONNECTION
