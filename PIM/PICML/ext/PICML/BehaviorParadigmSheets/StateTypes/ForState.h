// -*- C++ -*-

//============================================================================
/**
 * @file    ForState.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_FORSTATE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_FORSTATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ForState_Impl;
  typedef ForState_Impl * ForState_in;
  typedef ::GAME::Mga::Smart_Ptr < ForState_Impl > ForState;

  // Forward decl.
  class Visitor;

  /**
   * @class ForState_Impl
   *
   * Implementation for the ForState model element.
   */
  class PICML_Export ForState_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual LoopState_Impl
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
    static ForState _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    ForState_Impl (void);

    // Initializing constructor.
    ForState_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ForState_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of InitialCondition
    void InitialCondition (const std::string & val);

    /// Get the value of InitialCondition
    std::string InitialCondition (void) const;

    /// Set the value of IncrementExpr
    void IncrementExpr (const std::string & val);

    /// Get the value of IncrementExpr
    std::string IncrementExpr (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ForState.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_FORSTATE
