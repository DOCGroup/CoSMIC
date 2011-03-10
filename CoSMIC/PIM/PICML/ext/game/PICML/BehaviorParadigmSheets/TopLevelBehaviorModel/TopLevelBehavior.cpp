// $Id$

#include "stdafx.h"
#include "TopLevelBehavior.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/QueryInput.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/WorkerType.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/Input.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/MultiInput.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TopLevelBehavior_Impl::metaname = "TopLevelBehavior";

  //
  // TopLevelBehavior_Impl
  //
  TopLevelBehavior_Impl::TopLevelBehavior_Impl (void)
  {
  }

  //
  // TopLevelBehavior_Impl
  //
  TopLevelBehavior_Impl::TopLevelBehavior_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TopLevelBehavior_Impl
  //
  TopLevelBehavior_Impl::~TopLevelBehavior_Impl (void)
  {
  }

  //
  // get_QueryInputs
  //
  size_t TopLevelBehavior_Impl::get_QueryInputs (std::vector <QueryInput> & items) const
  {
    return this->children (items);
  }

  //
  // get_WorkerTypes
  //
  size_t TopLevelBehavior_Impl::get_WorkerTypes (std::vector <WorkerType> & items) const
  {
    return this->children (items);
  }

  //
  // get_Inputs
  //
  size_t TopLevelBehavior_Impl::get_Inputs (std::vector <Input> & items) const
  {
    return this->children (items);
  }

  //
  // get_MultiInputs
  //
  size_t TopLevelBehavior_Impl::get_MultiInputs (std::vector <MultiInput> & items) const
  {
    return this->children (items);
  }
}

