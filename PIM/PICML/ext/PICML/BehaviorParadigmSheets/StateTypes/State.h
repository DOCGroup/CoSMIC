// -*- C++ -*-

//============================================================================
/**
 * @file    State.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_STATE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_STATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class State_Impl;
  typedef State_Impl * State_in;
  typedef ::GAME::Mga::Smart_Ptr < State_Impl > State;

  // Forward decl.
  class Visitor;

  /**
   * @class State_Impl
   *
   * Implementation for the State model element.
   */
  class PICML_Export State_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual StateBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static State _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    State_Impl (void);

    // Initializing constructor.
    State_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~State_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src TerminalTransition connection.
    size_t src_of_TerminalTransition (std::vector <TerminalTransition> & items) const;
    GAME::Mga::Collection_T <TerminalTransition> src_of_TerminalTransition (void) const;

    /// Get the src Transition connection.
    size_t src_of_Transition (std::vector <Transition> & items) const;
    GAME::Mga::Collection_T <Transition> src_of_Transition (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "State.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_STATE
