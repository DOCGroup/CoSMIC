// -*- C++ -*-

//============================================================================
/**
 * @file    dr_topic_Connection.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_MAIN_DR_TOPIC_CONNECTION_H_
#define _DQML_STANDARD_MAIN_DR_TOPIC_CONNECTION_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Connection.h"

namespace DQML
{
  // Forward decl. and type definitions
  class dr_topic_Connection_Impl;
  typedef dr_topic_Connection_Impl * dr_topic_Connection_in;
  typedef ::GAME::Mga::Smart_Ptr < dr_topic_Connection_Impl > dr_topic_Connection;

  // Forward decl.
  class Visitor;

  /**
   * @class dr_topic_Connection_Impl
   *
   * Implementation for the dr_topic_Connection model element.
   */
  class DQML_Export dr_topic_Connection_Impl :
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
    static dr_topic_Connection _create (const DDSQoS_in parent, DataReader_in src, Topic_in dst);
    ///@}

    // Default constructor.
    dr_topic_Connection_Impl (void);

    // Initializing constructor.
    dr_topic_Connection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~dr_topic_Connection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}
    DataReader src_DataReader (void) const;
    Topic dst_Topic (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "dr_topic_Connection.inl"
#endif

#endif  // !defined _DQML_STANDARD_MAIN_DR_TOPIC_CONNECTION
