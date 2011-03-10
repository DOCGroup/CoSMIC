// $Id$

#include "stdafx.h"
#include "ObjectByValue.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/InheritableTypes/PrivateFlag.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/OperationTypes/FactoryOperation.h"
#include "PICML/InheritableTypes/MakeMemberPrivate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ObjectByValue_Impl::metaname = "ObjectByValue";

  //
  // ObjectByValue_Impl
  //
  ObjectByValue_Impl::ObjectByValue_Impl (void)
  {
  }

  //
  // ObjectByValue_Impl
  //
  ObjectByValue_Impl::ObjectByValue_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ObjectByValue_Impl
  //
  ObjectByValue_Impl::~ObjectByValue_Impl (void)
  {
  }

  //
  // abstract
  //
  void ObjectByValue_Impl::abstract (bool val)
  {
    static const std::string attr_abstract ("abstract");
    this->attribute (attr_abstract)->bool_value (val);
  }

  //
  // abstract
  //
  bool ObjectByValue_Impl::abstract (void) const
  {
    static const std::string attr_abstract ("abstract");
    return this->attribute (attr_abstract)->bool_value ();
  }

  //
  // get_PrivateFlags
  //
  size_t ObjectByValue_Impl::get_PrivateFlags (std::vector <PrivateFlag> & items) const
  {
    return this->children (items);
  }

  //
  // get_Members
  //
  size_t ObjectByValue_Impl::get_Members (std::vector <Member> & items) const
  {
    return this->children (items);
  }

  //
  // get_FactoryOperations
  //
  size_t ObjectByValue_Impl::get_FactoryOperations (std::vector <FactoryOperation> & items) const
  {
    return this->children (items);
  }

  //
  // get_MakeMemberPrivates
  //
  size_t ObjectByValue_Impl::get_MakeMemberPrivates (std::vector <MakeMemberPrivate> & items) const
  {
    return this->children (items);
  }
}

