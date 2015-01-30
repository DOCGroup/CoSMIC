// -*- C++ -*-

//============================================================================
/**
 * @file    sub_presqos_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_PRESENTATIONQOSPOLICY_SUB_PRESQOS_CONNECTION_H_
#define _DQML_STANDARD_PRESENTATIONQOSPOLICY_SUB_PRESQOS_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class sub_presqos_Connection_Impl;
  typedef sub_presqos_Connection_Impl * sub_presqos_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < sub_presqos_Connection_Impl > sub_presqos_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class sub_presqos_Connection_Impl
   *
   * Implementation for the sub_presqos_Connection model element.
   */
  class DQML_Export sub_presqos_Connection_Impl :
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
    static sub_presqos_Connection _create (const DDSQoS_in parent, Subscriber_in src, PresentationQosPolicy_in dst);
    ///@}

    // Default constructor.
    sub_presqos_Connection_Impl (void);

    // Initializing constructor.
    sub_presqos_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~sub_presqos_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    Subscriber src_Subscriber (void) const;
    PresentationQosPolicy dst_PresentationQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "sub_presqos_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_PRESENTATIONQOSPOLICY_SUB_PRESQOS_CONNECTION
