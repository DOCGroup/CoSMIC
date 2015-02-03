// $Id$

#include "StdAfx.h"
#include "ObjectByValue.h"

#if !defined (__GAME_INLINE__)
#include "ObjectByValue.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/PrivateFlag.h"
#include "PICML/OperationTypes/FactoryOperation.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/ArrayMember.h"
#include "PICML/InheritableTypes/MakeMemberPrivate.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/File.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ObjectByValue_Impl::metaname ("ObjectByValue");

  //
  // is_abstract
  //
  const bool ObjectByValue_Impl::is_abstract (1);

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
  ::GAME::Mga::Collection_T <PrivateFlag> ObjectByValue_Impl::get_PrivateFlags (void) const
  {
    return this->children <PrivateFlag> ();
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
  ::GAME::Mga::Collection_T <FactoryOperation> ObjectByValue_Impl::get_FactoryOperations (void) const
  {
    return this->children <FactoryOperation> ();
  }

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
  ::GAME::Mga::Collection_T <Member> ObjectByValue_Impl::get_Members (void) const
  {
    return this->children <Member> ();
  }

  //
  // get_ArrayMembers
  //
  size_t ObjectByValue_Impl::get_ArrayMembers (std::vector <ArrayMember> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArrayMembers
  //
  ::GAME::Mga::Collection_T <ArrayMember> ObjectByValue_Impl::get_ArrayMembers (void) const
  {
    return this->children <ArrayMember> ();
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
  ::GAME::Mga::Collection_T <MakeMemberPrivate> ObjectByValue_Impl::get_MakeMemberPrivates (void) const
  {
    return this->children <MakeMemberPrivate> ();
  }
}

