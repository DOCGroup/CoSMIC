// $Id$

#include "StdAfx.h"
#include "ObjectByValue.h"

#if !defined (__GAME_INLINE__)
#include "ObjectByValue.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InheritableTypes/SupportsInterfaces.h"
#include "PICML/InheritableTypes/PrivateFlag.h"
#include "PICML/InheritableTypes/MakeMemberPrivate.h"
#include "PICML/OperationTypes/FactoryOperation.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ObjectByValue_Impl::metaname ("ObjectByValue");

  //
  // get_Members
  //
  size_t ObjectByValue_Impl::get_Members (std::vector <Member> & items) const
  {
    return this->children (items);
  }

  //
  // get_Members
  //
  ::GAME::Mga::Iterator <Member> ObjectByValue_Impl::get_Members (void) const
  {
    return this->children <Member> ();
  }

  //
  // get_PrivateFlags
  //
  size_t ObjectByValue_Impl::get_PrivateFlags (std::vector <PrivateFlag> & items) const
  {
    return this->children (items);
  }

  //
  // get_PrivateFlags
  //
  ::GAME::Mga::Iterator <PrivateFlag> ObjectByValue_Impl::get_PrivateFlags (void) const
  {
    return this->children <PrivateFlag> ();
  }

  //
  // get_MakeMemberPrivates
  //
  size_t ObjectByValue_Impl::get_MakeMemberPrivates (std::vector <MakeMemberPrivate> & items) const
  {
    return this->children (items);
  }

  //
  // get_MakeMemberPrivates
  //
  ::GAME::Mga::Iterator <MakeMemberPrivate> ObjectByValue_Impl::get_MakeMemberPrivates (void) const
  {
    return this->children <MakeMemberPrivate> ();
  }

  //
  // get_FactoryOperations
  //
  size_t ObjectByValue_Impl::get_FactoryOperations (std::vector <FactoryOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_FactoryOperations
  //
  ::GAME::Mga::Iterator <FactoryOperation> ObjectByValue_Impl::get_FactoryOperations (void) const
  {
    return this->children <FactoryOperation> ();
  }
}

