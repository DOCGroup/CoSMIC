// -*- C++ -*-

//============================================================================
/**
 * @file    DoWhileState.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_DOWHILESTATE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_DOWHILESTATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DoWhileState_Impl;
  typedef DoWhileState_Impl * DoWhileState_in;
  typedef ::GAME::Mga::Smart_Ptr < DoWhileState_Impl > DoWhileState;

  // Forward decl.
  class Visitor;

  /**
   * @class DoWhileState_Impl
   *
   * Implementation for the DoWhileState model element.
   */
  class PICML_Export DoWhileState_Impl :
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
    static DoWhileState _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    DoWhileState_Impl (void);

    // Initializing constructor.
    DoWhileState_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~DoWhileState_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DoWhileState.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_DOWHILESTATE
