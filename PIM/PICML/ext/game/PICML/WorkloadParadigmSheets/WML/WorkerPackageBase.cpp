// $Id$

#include "StdAfx.h"
#include "WorkerPackageBase.h"

#if !defined (__GAME_INLINE__)
#include "WorkerPackageBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/Worker.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerPackageBase_Impl::metaname ("WorkerPackageBase");

  //
  // get_Workers
  //
  size_t WorkerPackageBase_Impl::get_Workers (std::vector <Worker> & items) const
  {
    return this->children (items);
  }

  //
  // get_Workers
  //
  ::GAME::Mga::Collection_T <Worker> WorkerPackageBase_Impl::get_Workers (void) const
  {
    return this->children <Worker> ();
  }
}

