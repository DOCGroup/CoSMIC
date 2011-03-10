// $Id$

#include "stdafx.h"
#include "HasOperations.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/InterfaceDefinition/Constant.h"
#include "PICML/OperationTypes/OnewayOperation.h"
#include "PICML/NamedTypes/NoInheritable.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/OperationTypes/TwowayOperation.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string HasOperations_Impl::metaname = "HasOperations";

  //
  // HasOperations_Impl
  //
  HasOperations_Impl::HasOperations_Impl (void)
  {
  }

  //
  // HasOperations_Impl
  //
  HasOperations_Impl::HasOperations_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~HasOperations_Impl
  //
  HasOperations_Impl::~HasOperations_Impl (void)
  {
  }

  //
  // get_Constants
  //
  size_t HasOperations_Impl::get_Constants (std::vector <Constant> & items) const
  {
    return this->children (items);
  }

  //
  // get_OnewayOperations
  //
  size_t HasOperations_Impl::get_OnewayOperations (std::vector <OnewayOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_NoInheritables
  //
  size_t HasOperations_Impl::get_NoInheritables (std::vector <NoInheritable> & items) const
  {
    return this->children (items);
  }

  //
  // get_Exceptions
  //
  size_t HasOperations_Impl::get_Exceptions (std::vector <Exception> & items) const
  {
    return this->children (items);
  }

  //
  // get_TwowayOperations
  //
  size_t HasOperations_Impl::get_TwowayOperations (std::vector <TwowayOperation> & items) const
  {
    return this->children (items);
  }
}

