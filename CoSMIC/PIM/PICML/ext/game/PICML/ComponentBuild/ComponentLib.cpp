// $Id$

#include "stdafx.h"
#include "ComponentLib.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ComponentBuild/ExtResourceConn.h"
#include "PICML/ComponentBuild/Project.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentLib_Impl::metaname = "ComponentLib";

  //
  // ComponentLib_Impl
  //
  ComponentLib_Impl::ComponentLib_Impl (void)
  {
  }

  //
  // ComponentLib_Impl
  //
  ComponentLib_Impl::ComponentLib_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ComponentLib_Impl
  //
  ComponentLib_Impl::~ComponentLib_Impl (void)
  {
  }

  //
  // ORBServices
  //
  void ComponentLib_Impl::ORBServices (const std::string & val)
  {
    static const std::string attr_ORBServices ("ORBServices");
    this->attribute (attr_ORBServices)->string_value (val);
  }

  //
  // ORBServices
  //
  std::string ComponentLib_Impl::ORBServices (void) const
  {
    static const std::string attr_ORBServices ("ORBServices");
    return this->attribute (attr_ORBServices)->string_value ();
  }

  //
  // sharedname
  //
  void ComponentLib_Impl::sharedname (const std::string & val)
  {
    static const std::string attr_sharedname ("sharedname");
    this->attribute (attr_sharedname)->string_value (val);
  }

  //
  // sharedname
  //
  std::string ComponentLib_Impl::sharedname (void) const
  {
    static const std::string attr_sharedname ("sharedname");
    return this->attribute (attr_sharedname)->string_value ();
  }

  //
  // libraryexport
  //
  void ComponentLib_Impl::libraryexport (const std::string & val)
  {
    static const std::string attr_libraryexport ("libraryexport");
    this->attribute (attr_libraryexport)->string_value (val);
  }

  //
  // libraryexport
  //
  std::string ComponentLib_Impl::libraryexport (void) const
  {
    static const std::string attr_libraryexport ("libraryexport");
    return this->attribute (attr_libraryexport)->string_value ();
  }

  //
  // in_ExtResourceConn_connections
  //
  size_t ComponentLib_Impl::in_ExtResourceConn_connections (std::vector <ExtResourceConn> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_Project
  //
  Project ComponentLib_Impl::parent_Project (void) const
  {
    return ::GAME::Mga::get_parent <Project> (this->object_.p);
  }
}

