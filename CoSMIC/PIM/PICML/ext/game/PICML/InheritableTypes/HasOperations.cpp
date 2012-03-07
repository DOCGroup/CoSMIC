// $Id$

#include "StdAfx.h"
#include "HasOperations.h"

#if !defined (__GAME_INLINE__)
#include "HasOperations.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/InterfaceDefinition/Constant.h"
#include "PICML/NamedTypes/NoInheritable.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/OperationTypes/TwowayOperation.h"
#include "PICML/OperationTypes/OnewayOperation.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string HasOperations_Impl::metaname ("HasOperations");

  //
  // get_Exceptions
  //
  size_t HasOperations_Impl::get_Exceptions (std::vector <Exception> & items) const
  {
    return this->children (items);
  }

  //
  // get_Exceptions
  //
  ::GAME::Mga::Iterator <Exception> HasOperations_Impl::get_Exceptions (void) const
  {
    return this->children <Exception> ();
  }

  //
  // get_Constants
  //
  size_t HasOperations_Impl::get_Constants (std::vector <Constant> & items) const
  {
    return this->children (items);
  }

  //
  // get_Constants
  //
  ::GAME::Mga::Iterator <Constant> HasOperations_Impl::get_Constants (void) const
  {
    return this->children <Constant> ();
  }

  //
  // get_NoInheritables
  //
  size_t HasOperations_Impl::get_NoInheritables (std::vector <NoInheritable> & items) const
  {
    return this->children (items);
  }

  //
  // get_NoInheritables
  //
  ::GAME::Mga::Iterator <NoInheritable> HasOperations_Impl::get_NoInheritables (void) const
  {
    return this->children <NoInheritable> ();
  }

  //
  // get_TwowayOperations
  //
  size_t HasOperations_Impl::get_TwowayOperations (std::vector <TwowayOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_TwowayOperations
  //
  ::GAME::Mga::Iterator <TwowayOperation> HasOperations_Impl::get_TwowayOperations (void) const
  {
    return this->children <TwowayOperation> ();
  }

  //
  // get_OnewayOperations
  //
  size_t HasOperations_Impl::get_OnewayOperations (std::vector <OnewayOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_OnewayOperations
  //
  ::GAME::Mga::Iterator <OnewayOperation> HasOperations_Impl::get_OnewayOperations (void) const
  {
    return this->children <OnewayOperation> ();
  }
}

