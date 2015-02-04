// $Id$

#include "StdAfx.h"
#include "HasOperations.h"

#if !defined (__GAME_INLINE__)
#include "HasOperations.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/NoInheritable.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/NamedTypes/Enum.h"
#include "PICML/NamedTypes/Alias.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/Collection.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/OperationTypes/TwowayOperation.h"
#include "PICML/OperationTypes/OnewayOperation.h"
#include "PICML/InterfaceDefinition/Constant.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string HasOperations_Impl::metaname ("HasOperations");

  //
  // is_abstract
  //
  const bool HasOperations_Impl::is_abstract = true;

  //
  // get_SwitchedAggregates
  //
  size_t HasOperations_Impl::get_SwitchedAggregates (std::vector <SwitchedAggregate> & items) const
  {
    return this->children (items);
  }

  //
  // get_SwitchedAggregates
  //
  ::GAME::Mga::Collection_T <SwitchedAggregate> HasOperations_Impl::get_SwitchedAggregates (void) const
  {
    return this->children <SwitchedAggregate> ();
  }

  //
  // get_Enums
  //
  size_t HasOperations_Impl::get_Enums (std::vector <Enum> & items) const
  {
    return this->children (items);
  }

  //
  // get_Enums
  //
  ::GAME::Mga::Collection_T <Enum> HasOperations_Impl::get_Enums (void) const
  {
    return this->children <Enum> ();
  }

  //
  // get_Aliass
  //
  size_t HasOperations_Impl::get_Aliass (std::vector <Alias> & items) const
  {
    return this->children (items);
  }

  //
  // get_Aliass
  //
  ::GAME::Mga::Collection_T <Alias> HasOperations_Impl::get_Aliass (void) const
  {
    return this->children <Alias> ();
  }

  //
  // get_PortTypes
  //
  size_t HasOperations_Impl::get_PortTypes (std::vector <PortType> & items) const
  {
    return this->children (items);
  }

  //
  // get_PortTypes
  //
  ::GAME::Mga::Collection_T <PortType> HasOperations_Impl::get_PortTypes (void) const
  {
    return this->children <PortType> ();
  }

  //
  // get_Aggregates
  //
  size_t HasOperations_Impl::get_Aggregates (std::vector <Aggregate> & items) const
  {
    return this->children (items);
  }

  //
  // get_Aggregates
  //
  ::GAME::Mga::Collection_T <Aggregate> HasOperations_Impl::get_Aggregates (void) const
  {
    return this->children <Aggregate> ();
  }

  //
  // get_Collections
  //
  size_t HasOperations_Impl::get_Collections (std::vector <Collection> & items) const
  {
    return this->children (items);
  }

  //
  // get_Collections
  //
  ::GAME::Mga::Collection_T <Collection> HasOperations_Impl::get_Collections (void) const
  {
    return this->children <Collection> ();
  }

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
  ::GAME::Mga::Collection_T <Exception> HasOperations_Impl::get_Exceptions (void) const
  {
    return this->children <Exception> ();
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
  ::GAME::Mga::Collection_T <TwowayOperation> HasOperations_Impl::get_TwowayOperations (void) const
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
  ::GAME::Mga::Collection_T <OnewayOperation> HasOperations_Impl::get_OnewayOperations (void) const
  {
    return this->children <OnewayOperation> ();
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
  ::GAME::Mga::Collection_T <Constant> HasOperations_Impl::get_Constants (void) const
  {
    return this->children <Constant> ();
  }
}

