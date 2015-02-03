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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class QueryInput_Impl;
  typedef QueryInput_Impl * QueryInput_in;
  typedef ::GAME::Mga::Smart_Ptr < QueryInput_Impl > QueryInput;

  // Forward decl.
  class Visitor;

  /**
   * @class QueryInput_Impl
   *
   * Implementation for the QueryInput model element.
   */
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


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static QueryInput _create (const TopLevelBehavior_in parent, QueryInputBase_in src, QueryInputAction_in dst);
    ///@}

    // Default constructor.
    QueryInput_Impl (void);

    // Initializing constructor.
    QueryInput_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~QueryInput_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelBehavior parent_TopLevelBehavior (void);
    ///@}
    QueryInputBase src_QueryInputBase (void) const;
    QueryInputAction dst_QueryInputAction (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "QueryInput.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_QUERYINPUT
