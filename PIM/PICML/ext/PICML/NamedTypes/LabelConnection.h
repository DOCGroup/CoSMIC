// -*- C++ -*-

//============================================================================
/**
 * @file    LabelConnection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_LABELCONNECTION_H_
#define _PICML_NAMEDTYPES_LABELCONNECTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LabelConnection_Impl;
  typedef LabelConnection_Impl * LabelConnection_in;
  typedef ::GAME::Mga::Smart_Ptr < LabelConnection_Impl > LabelConnection;

  // Forward decl.
  class Visitor;

  /**
   * @class LabelConnection_Impl
   *
   * Implementation for the LabelConnection model element.
   */
  class PICML_Export LabelConnection_Impl :
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
    static LabelConnection _create (const SwitchedAggregate_in parent, Member_in src, Label_in dst);
    ///@}

    // Default constructor.
    LabelConnection_Impl (void);

    // Initializing constructor.
    LabelConnection_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~LabelConnection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    SwitchedAggregate parent_SwitchedAggregate (void);
    ///@}
    Member src_Member (void) const;
    Label dst_Label (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "LabelConnection.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_LABELCONNECTION
