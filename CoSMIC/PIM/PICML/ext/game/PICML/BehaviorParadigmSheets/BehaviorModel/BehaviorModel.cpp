// $Id$

#include "StdAfx.h"
#include "BehaviorModel.h"

#if !defined (__GAME_INLINE__)
#include "BehaviorModel.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/Variable.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Finish.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryInputAction.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/Transition.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchTransition.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopTransition.h"
#include "PICML/BehaviorParadigmSheets/Terminals/Terminal.h"
#include "PICML/BehaviorParadigmSheets/Terminals/TerminalTransition.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/Effect.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/InputEffect.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/TerminalEffect.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BehaviorModel_Impl::metaname ("BehaviorModel");

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
  // get_BehaviorInputActions
  //
  size_t BehaviorModel_Impl::get_BehaviorInputActions (std::vector <BehaviorInputAction> & items) const
  {
    return this->children (items);
  }

  //
  // get_BehaviorInputActions
  //
  ::GAME::Mga::Iterator <BehaviorInputAction> BehaviorModel_Impl::get_BehaviorInputActions (void) const
  {
    return this->children <BehaviorInputAction> ();
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
  // get_ActionBases
  //
  size_t BehaviorModel_Impl::get_ActionBases (std::vector <ActionBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_ActionBases
  //
  ::GAME::Mga::Iterator <ActionBase> BehaviorModel_Impl::get_ActionBases (void) const
  {
    return this->children <ActionBase> ();
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
  // get_StateBases
  //
  size_t BehaviorModel_Impl::get_StateBases (std::vector <StateBase> & items) const
  {
    return this->children (items);
  }

  //
  // get_StateBases
  //
  ::GAME::Mga::Iterator <StateBase> BehaviorModel_Impl::get_StateBases (void) const
  {
    return this->children <StateBase> ();
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
}

