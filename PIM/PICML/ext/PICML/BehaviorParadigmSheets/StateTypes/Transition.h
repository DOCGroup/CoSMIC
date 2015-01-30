// -*- C++ -*-

//============================================================================
/**
 * @file    Transition.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_TRANSITION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_TRANSITION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Transition_Impl;
  typedef Transition_Impl * Transition_in;
  typedef ::GAME::Mga::Smart_Ptr < Transition_Impl > Transition;

  // Forward decl.
  class Visitor;

  /**
   * @class Transition_Impl
   *
   * Implementation for the Transition model element.
   */
  class PICML_Export Transition_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static Transition _create (const BehaviorModel_in parent, State_in src, ActionBase_in dst);
    ///@}

    // Default constructor.
    Transition_Impl (void);

    // Initializing constructor.
    Transition_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~Transition_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    BehaviorModel parent_BehaviorModel (void);
    ///@}
    State src_State (void) const;
    ActionBase dst_ActionBase (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "Transition.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_TRANSITION
