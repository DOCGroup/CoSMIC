// -*- C++ -*-

//============================================================================
/**
 * @file    LoopTransition.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_LOOPTRANSITION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_LOOPTRANSITION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LoopTransition_Impl;
  typedef LoopTransition_Impl * LoopTransition_in;
  typedef ::GAME::Mga::Smart_Ptr < LoopTransition_Impl > LoopTransition;

  // Forward decl.
  class Visitor;

  /**
   * @class LoopTransition_Impl
   *
   * Implementation for the LoopTransition model element.
   */
  class PICML_Export LoopTransition_Impl :
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
    static LoopTransition _create (const BehaviorModel_in parent, LoopState_in src, ActionBase_in dst);
    ///@}

    // Default constructor.
    LoopTransition_Impl (void);

    // Initializing constructor.
    LoopTransition_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~LoopTransition_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BehaviorModel parent_BehaviorModel (void);
    ///@}
    LoopState src_LoopState (void) const;
    ActionBase dst_ActionBase (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "LoopTransition.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_LOOPTRANSITION
