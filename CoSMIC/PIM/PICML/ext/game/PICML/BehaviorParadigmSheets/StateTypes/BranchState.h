// -*- C++ -*-

//============================================================================
/**
 * @file    BranchState.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_BRANCHSTATE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_BRANCHSTATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BranchState_Impl;
  typedef BranchState_Impl * BranchState_in;
  typedef ::GAME::Mga::Smart_Ptr < BranchState_Impl > BranchState;

  // Forward decl.
  class Visitor;

  /**
   * @class BranchState_Impl
   *
   * Implementation for the BranchState model element.
   */
  class PICML_Export BranchState_Impl :
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

    /**
     * @name Factory Methods
     */
    ///@{
    static BranchState _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    BranchState_Impl (void);

    // Initializing constructor.
    BranchState_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~BranchState_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src BranchTransition connection.
    size_t src_BranchTransition (std::vector <BranchTransition> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "BranchState.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_BRANCHSTATE
