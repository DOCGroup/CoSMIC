// -*- C++ -*-

//============================================================================
/**
 * @file    BehaviorModel.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_BEHAVIORMODEL_BEHAVIORMODEL_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_BEHAVIORMODEL_BEHAVIORMODEL_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BehaviorModel_Impl;
  typedef BehaviorModel_Impl * BehaviorModel_in;
  typedef ::GAME::Mga::Smart_Ptr < BehaviorModel_Impl > BehaviorModel;

  /**
   * @class BehaviorModel_Impl
   *
   * Implementation for the BehaviorModel model element.
   */
  class PICML_Export BehaviorModel_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    BehaviorModel_Impl (void);

    // Initializing constructor.
    BehaviorModel_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~BehaviorModel_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_TerminalEffects (std::vector <TerminalEffect> & items) const;
    ::GAME::Mga::Iterator <TerminalEffect> get_TerminalEffects (void) const;

    size_t get_Terminals (std::vector <Terminal> & items) const;
    ::GAME::Mga::Iterator <Terminal> get_Terminals (void) const;

    size_t get_TerminalTransitions (std::vector <TerminalTransition> & items) const;
    ::GAME::Mga::Iterator <TerminalTransition> get_TerminalTransitions (void) const;

    size_t get_States (std::vector <State> & items) const;
    ::GAME::Mga::Iterator <State> get_States (void) const;

    size_t get_WhileStates (std::vector <WhileState> & items) const;
    ::GAME::Mga::Iterator <WhileState> get_WhileStates (void) const;

    size_t get_DoWhileStates (std::vector <DoWhileState> & items) const;
    ::GAME::Mga::Iterator <DoWhileState> get_DoWhileStates (void) const;

    size_t get_ForStates (std::vector <ForState> & items) const;
    ::GAME::Mga::Iterator <ForState> get_ForStates (void) const;

    size_t get_BranchStates (std::vector <BranchState> & items) const;
    ::GAME::Mga::Iterator <BranchState> get_BranchStates (void) const;

    size_t get_Finishs (std::vector <Finish> & items) const;
    ::GAME::Mga::Iterator <Finish> get_Finishs (void) const;

    size_t get_MultiInputActions (std::vector <MultiInputAction> & items) const;
    ::GAME::Mga::Iterator <MultiInputAction> get_MultiInputActions (void) const;

    size_t get_InputActions (std::vector <InputAction> & items) const;
    ::GAME::Mga::Iterator <InputAction> get_InputActions (void) const;

    size_t get_InputEffects (std::vector <InputEffect> & items) const;
    ::GAME::Mga::Iterator <InputEffect> get_InputEffects (void) const;

    size_t get_LoopTransitions (std::vector <LoopTransition> & items) const;
    ::GAME::Mga::Iterator <LoopTransition> get_LoopTransitions (void) const;

    size_t get_Variables (std::vector <Variable> & items) const;
    ::GAME::Mga::Iterator <Variable> get_Variables (void) const;

    size_t get_RequestActions (std::vector <RequestAction> & items) const;
    ::GAME::Mga::Iterator <RequestAction> get_RequestActions (void) const;

    size_t get_QueryActions (std::vector <QueryAction> & items) const;
    ::GAME::Mga::Iterator <QueryAction> get_QueryActions (void) const;

    size_t get_OutputActions (std::vector <OutputAction> & items) const;
    ::GAME::Mga::Iterator <OutputAction> get_OutputActions (void) const;

    size_t get_Actions (std::vector <Action> & items) const;
    ::GAME::Mga::Iterator <Action> get_Actions (void) const;

    size_t get_QueryInputActions (std::vector <QueryInputAction> & items) const;
    ::GAME::Mga::Iterator <QueryInputAction> get_QueryInputActions (void) const;

    size_t get_BranchTransitions (std::vector <BranchTransition> & items) const;
    ::GAME::Mga::Iterator <BranchTransition> get_BranchTransitions (void) const;

    size_t get_Transitions (std::vector <Transition> & items) const;
    ::GAME::Mga::Iterator <Transition> get_Transitions (void) const;

    size_t get_Effects (std::vector <Effect> & items) const;
    ::GAME::Mga::Iterator <Effect> get_Effects (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "BehaviorModel.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_BEHAVIORMODEL_BEHAVIORMODEL
