// -*- C++ -*-

//============================================================================
/**
 * @file    sub_groupdata_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_GROUPDATAQOSPOLICY_SUB_GROUPDATA_CONNECTION_H_
#define _DQML_STANDARD_GROUPDATAQOSPOLICY_SUB_GROUPDATA_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class sub_groupdata_Connection_Impl;
  typedef sub_groupdata_Connection_Impl * sub_groupdata_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < sub_groupdata_Connection_Impl > sub_groupdata_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class sub_groupdata_Connection_Impl
   *
   * Implementation for the sub_groupdata_Connection model element.
   */
  class DQML_Export sub_groupdata_Connection_Impl :
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
    static sub_groupdata_Connection _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    sub_groupdata_Connection_Impl (void);

    // Initializing constructor.
    sub_groupdata_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~sub_groupdata_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    Subscriber src_Subscriber (void) const;
    GroupDataQosPolicy dst_GroupDataQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "sub_groupdata_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_GROUPDATAQOSPOLICY_SUB_GROUPDATA_CONNECTION
