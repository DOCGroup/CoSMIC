// $Id$

#include "StdAfx.h"
#include "Exception.h"

#if !defined (__GAME_INLINE__)
#include "Exception.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/NamedTypes/Member.h"
#include "PICML/NamedTypes/ArrayMember.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/TemplatePackageAlias.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "PICML/InterfaceDefinition/File.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Exception_Impl::metaname ("Exception");

  //
  // is_abstract
  //
  const bool Exception_Impl::is_abstract = false;

  //
  // _create (const HasOperations_in)
  //
  Exception Exception_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create < Exception > (parent, Exception_Impl::metaname);
  }

  //
  // _create (const Package_in)
  //
  Exception Exception_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create < Exception > (parent, Exception_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  Exception Exception_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create < Exception > (parent, Exception_Impl::metaname);
  }

  //
  // accept
  //
  void Exception_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Exception (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_HasOperations
  //
  HasOperations Exception_Impl::parent_HasOperations (void)
  {
    return HasOperations::_narrow (this->parent ());
  }

  //
  // parent_Package
  //
  Package Exception_Impl::parent_Package (void)
  {
    return Package::_narrow (this->parent ());
  }

  //
  // parent_File
  //
  File Exception_Impl::parent_File (void)
  {
    return File::_narrow (this->parent ());
  }

  //
  // get_Members
  //
  size_t Exception_Impl::get_Members (std::vector <Member> & items) const
  {
    return this->children (items);
  }

  //
  // get_Members
  //
  ::GAME::Mga::Collection_T <Member> Exception_Impl::get_Members (void) const
  {
    return this->children <Member> ();
  }

  //
  // get_ArrayMembers
  //
  size_t Exception_Impl::get_ArrayMembers (std::vector <ArrayMember> & items) const
  {
    return this->children (items);
  }

  //
  // get_ArrayMembers
  //
  ::GAME::Mga::Collection_T <ArrayMember> Exception_Impl::get_ArrayMembers (void) const
  {
    return this->children <ArrayMember> ();
  }
}

