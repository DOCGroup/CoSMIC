// -*- C++ -*-

//============================================================================
/**
 * @file    QueryInput.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_QUERYINPUT_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_QUERYINPUT_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class QueryInput_Impl;
  typedef QueryInput_Impl * QueryInput_in;
  typedef ::GAME::Mga::Smart_Ptr <QueryInput_Impl> QueryInput;

  // Forward decl.
  class Visitor;

  class PICML_Export QueryInput_Impl :
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
    QueryInput_Impl (void);

    /// Initializing constructor
    QueryInput_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~QueryInput_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static QueryInput _create (const TopLevelBehavior_in parent);
    ///@}

    /// Get the src QueryInputBase connection point.
    QueryInputBase src_QueryInputBase (void);

    /// Get the dst QueryInputAction connection point.
    QueryInputAction dst_QueryInputAction (void);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelBehavior parent_TopLevelBehavior (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
