// -*- C++ -*-

//============================================================================
/**
 * @file    dr_ownership_Connection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_OWNERSHIPQOSPOLICY_DR_OWNERSHIP_CONNECTION_H_
#define _DQML_STANDARD_OWNERSHIPQOSPOLICY_DR_OWNERSHIP_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class dr_ownership_Connection_Impl;
  typedef dr_ownership_Connection_Impl * dr_ownership_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < dr_ownership_Connection_Impl > dr_ownership_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class dr_ownership_Connection_Impl
   *
   * Implementation for the dr_ownership_Connection model element.
   */
  class DQML_Export dr_ownership_Connection_Impl :
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
    static dr_ownership_Connection _create (const DDSQoS_in parent);
    ///@}

    // Default constructor.
    dr_ownership_Connection_Impl (void);

    // Initializing constructor.
    dr_ownership_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~dr_ownership_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    DataReader src_DataReader (void) const;
    OwnershipQosPolicy dst_OwnershipQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "dr_ownership_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_OWNERSHIPQOSPOLICY_DR_OWNERSHIP_CONNECTION
