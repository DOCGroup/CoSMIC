// -*- C++ -*-

//============================================================================
/**
 * @file    LoopState.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_LOOPSTATE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_LOOPSTATE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LoopState_Impl;
  typedef LoopState_Impl * LoopState_in;
  typedef ::GAME::Mga::Smart_Ptr < LoopState_Impl > LoopState;

  /**
   * @class LoopState_Impl
   *
   * Implementation for the LoopState model element.
   */
  class PICML_Export LoopState_Impl :
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

    // Default constructor.
    LoopState_Impl (void);

    // Initializing constructor.
    LoopState_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~LoopState_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of LoopingCondition
    void LoopingCondition (const std::string & val);

    /// Get the value of LoopingCondition
    std::string LoopingCondition (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src LoopTransition connection.
    size_t src_of_LoopTransition (std::vector <LoopTransition> & items) const;
    GAME::Mga::Collection_T <LoopTransition> src_of_LoopTransition (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "LoopState.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_LOOPSTATE
