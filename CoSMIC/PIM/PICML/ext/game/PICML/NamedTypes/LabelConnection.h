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

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LabelConnection_Impl;
  typedef LabelConnection_Impl * LabelConnection_in;
  typedef ::GAME::Mga::Smart_Ptr <LabelConnection_Impl> LabelConnection;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    LabelConnection_Impl (void);

    /// Initializing constructor
    LabelConnection_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~LabelConnection_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static LabelConnection _create (const SwitchedAggregate_in parent);
    ///@}

    /// Get the src Member connection point.
    Member src_Member (void);

    /// Get the dst Label connection point.
    Label dst_Label (void);

    /**
     * @name Parent Methods
     */
    ///@{
    SwitchedAggregate parent_SwitchedAggregate (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
