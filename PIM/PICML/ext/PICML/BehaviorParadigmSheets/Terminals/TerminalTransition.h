// -*- C++ -*-

//============================================================================
/**
 * @file    TerminalTransition.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TERMINALS_TERMINALTRANSITION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TERMINALS_TERMINALTRANSITION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TerminalTransition_Impl;
  typedef TerminalTransition_Impl * TerminalTransition_in;
  typedef ::GAME::Mga::Smart_Ptr < TerminalTransition_Impl > TerminalTransition;

  // Forward decl.
  class Visitor;

  /**
   * @class TerminalTransition_Impl
   *
   * Implementation for the TerminalTransition model element.
   */
  class PICML_Export TerminalTransition_Impl :
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
    static TerminalTransition _create (const BehaviorModel_in parent, State_in src, Terminal_in dst);
    ///@}

    // Default constructor.
    TerminalTransition_Impl (void);

    // Initializing constructor.
    TerminalTransition_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~TerminalTransition_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BehaviorModel parent_BehaviorModel (void);
    ///@}
    State src_State (void) const;
    Terminal dst_Terminal (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "TerminalTransition.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TERMINALS_TERMINALTRANSITION
