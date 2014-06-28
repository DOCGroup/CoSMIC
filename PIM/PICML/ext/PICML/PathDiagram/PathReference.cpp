// $Id$

#include "StdAfx.h"
#include "PathReference.h"

#if !defined (__GAME_INLINE__)
#include "PathReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/CriticalPath.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PathReference_Impl::metaname ("PathReference");

  //
  // _create (const ComponentImplementationContainer_in)
  //
  PathReference PathReference_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < PathReference > (parent, PathReference_Impl::metaname);
  }

  //
  // accept
  //
  void PathReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PathReference (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer PathReference_Impl::parent_ComponentImplementationContainer (void)
  {
    return ComponentImplementationContainer::_narrow (this->parent ());
  }

  //
  // dst_CriticalPath
  //
  size_t PathReference_Impl::dst_CriticalPath (std::vector <CriticalPath> & items) const
  {
    return this->in_connections <CriticalPath> (items);
  }

  //
  // Path_is_nil
  //
  bool PathReference_Impl::Path_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_Path
  //
  void PathReference_Impl::set_Path (Path_in item)
  {
    this->refers_to (item);
  }

  //
  // get_Path
  //
  Path PathReference_Impl::get_Path (void) const
  {
    return Path::_narrow (this->refers_to ());
  }
}

