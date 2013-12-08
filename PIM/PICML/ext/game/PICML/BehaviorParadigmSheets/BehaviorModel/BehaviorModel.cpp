// $Id$

#include "StdAfx.h"
#include "BehaviorModel.h"

#if !defined (__GAME_INLINE__)
#include "BehaviorModel.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/TerminalEffect.h"
#include "PICML/BehaviorParadigmSheets/Terminals/Terminal.h"
#include "PICML/BehaviorParadigmSheets/Terminals/TerminalTransition.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/State.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/WhileState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/DoWhileState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/ForState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchState.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Finish.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/MultiInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/InputAction.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/InputEffect.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopTransition.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/Variable.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/RequestAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/OutputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Action.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryInputAction.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchTransition.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/Transition.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/Effect.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BehaviorModel_Impl::metaname ("BehaviorModel");

  //
  // get_TerminalEffects
  //
  size_t BehaviorModel_Impl::get_TerminalEffects (std::vector <TerminalEffect> & items) const
  {
    return this->children (items);
  }

  //
  // get_TerminalEffects
  //
  ::GAME::Mga::Iterator <TerminalEffect> BehaviorModel_Impl::get_TerminalEffects (void) const
  {
    return this->children <TerminalEffect> ();
  }

  //
  // get_Terminals
  //
  size_t BehaviorModel_Impl::get_Terminals (std::vector <Terminal> & items) const
  {
    return this->children (items);
  }

  //
  // get_Terminals
  //
  ::GAME::Mga::Iterator <Terminal> BehaviorModel_Impl::get_Terminals (void) const
  {
    return this->children <Terminal> ();
  }

  //
  // get_TerminalTransitions
  //
  size_t BehaviorModel_Impl::get_TerminalTransitions (std::vector <TerminalTransition> & items) const
  {
    return this->children (items);
  }

  //
  // get_TerminalTransitions
  //
  ::GAME::Mga::Iterator <TerminalTransition> BehaviorModel_Impl::get_TerminalTransitions (void) const
  {
    return this->children <TerminalTransition> ();
  }

  //
  // get_States
  //
  size_t BehaviorModel_Impl::get_States (std::vector <State> & items) const
  {
    return this->children (items);
  }

  //
  // get_States
  //
  ::GAME::Mga::Iterator <State> BehaviorModel_Impl::get_States (void) const
  {
    return this->children <State> ();
  }

  //
  // get_WhileStates
  //
  size_t BehaviorModel_Impl::get_WhileStates (std::vector <WhileState> & items) const
  {
    return this->children (items);
  }

  //
  // get_WhileStates
  //
  ::GAME::Mga::Iterator <WhileState> BehaviorModel_Impl::get_WhileStates (void) const
  {
    return this->children <WhileState> ();
  }

  //
  // get_DoWhileStates
  //
  size_t BehaviorModel_Impl::get_DoWhileStates (std::vector <DoWhileState> & items) const
  {
    return this->children (items);
  }

  //
  // get_DoWhileStates
  //
  ::GAME::Mga::Iterator <DoWhileState> BehaviorModel_Impl::get_DoWhileStates (void) const
  {
    return this->children <DoWhileState> ();
  }

  //
  // get_ForStates
  //
  size_t BehaviorModel_Impl::get_ForStates (std::vector <ForState> & items) const
  {
    return this->children (items);
  }

  //
  // get_ForStates
  //
  ::GAME::Mga::Iterator <ForState> BehaviorModel_Impl::get_ForStates (void) const
  {
    return this->children <ForState> ();
  }

  //
  // get_BranchStates
  //
  size_t BehaviorModel_Impl::get_BranchStates (std::vector <BranchState> & items) const
  {
    return this->children (items);
  }

  //
  // get_BranchStates
  //
  ::GAME::Mga::Iterator <BranchState> BehaviorModel_Impl::get_BranchStates (void) const
  {
    return this->children <BranchState> ();
  }

  //
  // get_Finishs
  //
  size_t BehaviorModel_Impl::get_Finishs (std::vector <Finish> & items) const
  {
    return this->children (items);
  }

  //
  // get_Finishs
  //
  ::GAME::Mga::Iterator <Finish> BehaviorModel_Impl::get_Finishs (void) const
  {
    return this->children <Finish> ();
  }

  //
  // get_MultiInputActions
  //
  size_t BehaviorModel_Impl::get_MultiInputActions (std::vector <MultiInputAction> & items) const
  {
    return this->children (items);
  }

  //
  // get_MultiInputActions
  //
  ::GAME::Mga::Iterator <MultiInputAction> BehaviorModel_Impl::get_MultiInputActions (void) const
  {
    return this->children <MultiInputAction> ();
  }

  //
  // get_InputActions
  //
  size_t BehaviorModel_Impl::get_InputActions (std::vector <InputAction> & items) const
  {
    return this->children (items);
  }

  //
  // get_InputActions
  //
  ::GAME::Mga::Iterator <InputAction> BehaviorModel_Impl::get_InputActions (void) const
  {
    return this->children <InputAction> ();
  }

  //
  // get_InputEffects
  //
  size_t BehaviorModel_Impl::get_InputEffects (std::vector <InputEffect> & items) const
  {
    return this->children (items);
  }

  //
  // get_InputEffects
  //
  ::GAME::Mga::Iterator <InputEffect> BehaviorModel_Impl::get_InputEffects (void) const
  {
    return this->children <InputEffect> ();
  }

  //
  // get_LoopTransitions
  //
  size_t BehaviorModel_Impl::get_LoopTransitions (std::vector <LoopTransition> & items) const
  {
    return this->children (items);
  }

  //
  // get_LoopTransitions
  //
  ::GAME::Mga::Iterator <LoopTransition> BehaviorModel_Impl::get_LoopTransitions (void) const
  {
    return this->children <LoopTransition> ();
  }

  //
  // get_Variables
  //
  size_t BehaviorModel_Impl::get_Variables (std::vector <Variable> & items) const
  {
    return this->children (items);
  }

  //
  // get_Variables
  //
  ::GAME::Mga::Iterator <Variable> BehaviorModel_Impl::get_Variables (void) const
  {
    return this->children <Variable> ();
  }

  //
  // get_RequestActions
  //
  size_t BehaviorModel_Impl::get_RequestActions (std::vector <RequestAction> & items) const
  {
    return this->children (items);
  }

  //
  // get_RequestActions
  //
  ::GAME::Mga::Iterator <RequestAction> BehaviorModel_Impl::get_RequestActions (void) const
  {
    return this->children <RequestAction> ();
  }

  //
  // get_QueryActions
  //
  size_t BehaviorModel_Impl::get_QueryActions (std::vector <QueryAction> & items) const
  {
    return this->children (items);
  }

  //
  // get_QueryActions
  //
  ::GAME::Mga::Iterator <QueryAction> BehaviorModel_Impl::get_QueryActions (void) const
  {
    return this->children <QueryAction> ();
  }

  //
  // get_OutputActions
  //
  size_t BehaviorModel_Impl::get_OutputActions (std::vector <OutputAction> & items) const
  {
    return this->children (items);
  }

  //
  // get_OutputActions
  //
  ::GAME::Mga::Iterator <OutputAction> BehaviorModel_Impl::get_OutputActions (void) const
  {
    return this->children <OutputAction> ();
  }

  //
  // get_Actions
  //
  size_t BehaviorModel_Impl::get_Actions (std::vector <Action> & items) const
  {
    return this->children (items);
  }

  //
  // get_Actions
  //
  ::GAME::Mga::Iterator <Action> BehaviorModel_Impl::get_Actions (void) const
  {
    return this->children <Action> ();
  }

  //
  // get_QueryInputActions
  //
  size_t BehaviorModel_Impl::get_QueryInputActions (std::vector <QueryInputAction> & items) const
  {
    return this->children (items);
  }

  //
  // get_QueryInputActions
  //
  ::GAME::Mga::Iterator <QueryInputAction> BehaviorModel_Impl::get_QueryInputActions (void) const
  {
    return this->children <QueryInputAction> ();
  }

  //
  // get_BranchTransitions
  //
  size_t BehaviorModel_Impl::get_BranchTransitions (std::vector <BranchTransition> & items) const
  {
    return this->children (items);
  }

  //
  // get_BranchTransitions
  //
  ::GAME::Mga::Iterator <BranchTransition> BehaviorModel_Impl::get_BranchTransitions (void) const
  {
    return this->children <BranchTransition> ();
  }

  //
  // get_Transitions
  //
  size_t BehaviorModel_Impl::get_Transitions (std::vector <Transition> & items) const
  {
    return this->children (items);
  }

  //
  // get_Transitions
  //
  ::GAME::Mga::Iterator <Transition> BehaviorModel_Impl::get_Transitions (void) const
  {
    return this->children <Transition> ();
  }

  //
  // get_Effects
  //
  size_t BehaviorModel_Impl::get_Effects (std::vector <Effect> & items) const
  {
    return this->children (items);
  }

  //
  // get_Effects
  //
  ::GAME::Mga::Iterator <Effect> BehaviorModel_Impl::get_Effects (void) const
  {
    return this->children <Effect> ();
  }
}
