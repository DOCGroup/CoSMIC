#include "StdAfx.h"
#include "PathReference.h"

#if !defined (__GAME_INLINE__)
#include "PathReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/PathDiagram/Path.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/CriticalPath.h"
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
  // is_abstract
  //
  const bool PathReference_Impl::is_abstract = false;

  //
  // _create (const ComponentImplementationContainer_in)
  //
  PathReference PathReference_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create < PathReference > (parent, PathReference_Impl::metaname);
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
  // dst_of_CriticalPath
  //
  size_t PathReference_Impl::dst_of_CriticalPath (std::vector <CriticalPath> & items) const
  {
    return this->in_connections <CriticalPath> (items);
  }

  //
  // has_dst_of_CriticalPath
  //
  bool PathReference_Impl::has_dst_of_CriticalPath (void) const
  {
    return this->in_connections <CriticalPath> ("dst").count () == 1;
  }

  //
  // dst_of_CriticalPath
  //
  CriticalPath PathReference_Impl::dst_of_CriticalPath (void) const
  {
    return this->in_connections <CriticalPath> ("dst").first ();
  }

  //
  // Path_is_nil
  //
  bool PathReference_Impl::Path_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_Path
  //
  void PathReference_Impl::refers_to_Path (Path_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_Path
  //
  Path PathReference_Impl::refers_to_Path (void) const
  {
    return Path::_narrow (this->refers_to ());
  }
}

