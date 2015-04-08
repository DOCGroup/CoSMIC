// -*- C++ -*-

//============================================================================
/**
 * @file    Terminal.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TERMINALS_TERMINAL_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TERMINALS_TERMINAL_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Terminal_Impl;
  typedef Terminal_Impl * Terminal_in;
  typedef ::GAME::Mga::Smart_Ptr < Terminal_Impl > Terminal;

  // Forward decl.
  class Visitor;

  /**
   * @class Terminal_Impl
   *
   * Implementation for the Terminal model element.
   */
  class PICML_Export Terminal_Impl :
    public virtual ::GAME::Mga::Atom_Impl
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
    static Terminal _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    Terminal_Impl (void);

    // Initializing constructor.
    Terminal_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~Terminal_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BehaviorModel parent_BehaviorModel (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src TerminalEffect connection.
    size_t src_of_TerminalEffect (std::vector <TerminalEffect> & items) const;
    bool has_src_of_TerminalEffect (void) const;
    TerminalEffect src_of_TerminalEffect (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst TerminalTransition connection.
    size_t dst_of_TerminalTransition (std::vector <TerminalTransition> & items) const;
    GAME::Mga::Collection_T <TerminalTransition> dst_of_TerminalTransition (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Terminal.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TERMINALS_TERMINAL
