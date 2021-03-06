#include "StdAfx.h"
#include "TopLevelBehavior.h"

#if !defined (__GAME_INLINE__)
#include "TopLevelBehavior.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/MultiInput.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/QueryInput.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/WorkerType.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/Input.h"
#include "PICML/BehaviorParadigmSheets/InputHooks/Environment.h"
#include "PICML/BehaviorParadigmSheets/InputHooks/ApplicationTask.h"
#include "PICML/BehaviorParadigmSheets/InputHooks/PeriodicEvent.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TopLevelBehavior_Impl::metaname ("TopLevelBehavior");

  //
  // is_abstract
  //
  const bool TopLevelBehavior_Impl::is_abstract = true;

  //
  // has_Environment
  //
  bool TopLevelBehavior_Impl::has_Environment (void) const
  {
    return this->children <Environment> ().count () == 1;
  }

  //
  // get_Environment
  //
  Environment TopLevelBehavior_Impl::get_Environment (void) const
  {
    return this->children <Environment> ().first ();
  }

  //
  // get_MultiInputs
  //
  size_t TopLevelBehavior_Impl::get_MultiInputs (std::vector <MultiInput> & items) const
  {
    return this->children (items);
  }

  //
  // get_MultiInputs
  //
  ::GAME::Mga::Collection_T <MultiInput> TopLevelBehavior_Impl::get_MultiInputs (void) const
  {
    return this->children <MultiInput> ();
  }

  //
  // get_QueryInputs
  //
  size_t TopLevelBehavior_Impl::get_QueryInputs (std::vector <QueryInput> & items) const
  {
    return this->children (items);
  }

  //
  // get_QueryInputs
  //
  ::GAME::Mga::Collection_T <QueryInput> TopLevelBehavior_Impl::get_QueryInputs (void) const
  {
    return this->children <QueryInput> ();
  }

  //
  // get_WorkerTypes
  //
  size_t TopLevelBehavior_Impl::get_WorkerTypes (std::vector <WorkerType> & items) const
  {
    return this->children (items);
  }

  //
  // get_WorkerTypes
  //
  ::GAME::Mga::Collection_T <WorkerType> TopLevelBehavior_Impl::get_WorkerTypes (void) const
  {
    return this->children <WorkerType> ();
  }

  //
  // get_Inputs
  //
  size_t TopLevelBehavior_Impl::get_Inputs (std::vector <Input> & items) const
  {
    return this->children (items);
  }

  //
  // get_Inputs
  //
  ::GAME::Mga::Collection_T <Input> TopLevelBehavior_Impl::get_Inputs (void) const
  {
    return this->children <Input> ();
  }

  //
  // get_ApplicationTasks
  //
  size_t TopLevelBehavior_Impl::get_ApplicationTasks (std::vector <ApplicationTask> & items) const
  {
    return this->children (items);
  }

  //
  // get_ApplicationTasks
  //
  ::GAME::Mga::Collection_T <ApplicationTask> TopLevelBehavior_Impl::get_ApplicationTasks (void) const
  {
    return this->children <ApplicationTask> ();
  }

  //
  // get_PeriodicEvents
  //
  size_t TopLevelBehavior_Impl::get_PeriodicEvents (std::vector <PeriodicEvent> & items) const
  {
    return this->children (items);
  }

  //
  // get_PeriodicEvents
  //
  ::GAME::Mga::Collection_T <PeriodicEvent> TopLevelBehavior_Impl::get_PeriodicEvents (void) const
  {
    return this->children <PeriodicEvent> ();
  }
}

