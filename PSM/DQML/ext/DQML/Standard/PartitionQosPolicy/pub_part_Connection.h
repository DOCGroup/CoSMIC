// -*- C++ -*-

//============================================================================
/**
 * @file    pub_part_Connection.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_PARTITIONQOSPOLICY_PUB_PART_CONNECTION_H_
#define _DQML_STANDARD_PARTITIONQOSPOLICY_PUB_PART_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class pub_part_Connection_Impl;
  typedef pub_part_Connection_Impl * pub_part_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < pub_part_Connection_Impl > pub_part_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class pub_part_Connection_Impl
   *
   * Implementation for the pub_part_Connection model element.
   */
  class DQML_Export pub_part_Connection_Impl :
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
    static pub_part_Connection _create (const DDSQoS_in parent, Publisher_in src, PartitionQosPolicy_in dst);
    ///@}

    // Default constructor.
    pub_part_Connection_Impl (void);

    // Initializing constructor.
    pub_part_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~pub_part_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    Publisher src_Publisher (void) const;
    PartitionQosPolicy dst_PartitionQosPolicy (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "pub_part_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_PARTITIONQOSPOLICY_PUB_PART_CONNECTION
