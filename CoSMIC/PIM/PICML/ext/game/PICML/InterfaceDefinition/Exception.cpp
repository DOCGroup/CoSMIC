// $Id$

#include "stdafx.h"
#include "Exception.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/NamedTypes/Member.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Exception_Impl::metaname = "Exception";

  //
  // Exception_Impl
  //
  Exception_Impl::Exception_Impl (void)
  {
  }

  //
  // Exception_Impl
  //
  Exception_Impl::Exception_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Exception_Impl
  //
  Exception_Impl::~Exception_Impl (void)
  {
  }

  //
  // accept
  //
  void Exception_Impl::accept (Visitor * v)
  {
    v->visit_Exception (this);
  }

  //
  // _create
  //
  Exception Exception_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object <Exception> (parent, Exception_Impl::metaname);
  }

  //
  // _create
  //
  Exception Exception_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object <Exception> (parent, Exception_Impl::metaname);
  }

  //
  // get_Members
  //
  size_t Exception_Impl::get_Members (std::vector <Member> & items) const
  {
    return this->children (items);
  }

  //
  // parent_File
  //
  File Exception_Impl::parent_File (void) const
  {
    return ::GAME::Mga::get_parent <File> (this->object_.p);
  }

  //
  // parent_Package
  //
  Package Exception_Impl::parent_Package (void) const
  {
    return ::GAME::Mga::get_parent <Package> (this->object_.p);
  }
}

