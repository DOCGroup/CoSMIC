// $Id$

#include "stdafx.h"
#include "Operation.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/Worker.h"
#include "PICML/OperationTypes/ReturnType.h"
#include "PICML/OperationTypes/ParameterType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Operation_Impl::metaname = "Operation";

  //
  // Operation_Impl
  //
  Operation_Impl::Operation_Impl (void)
  {
  }

  //
  // Operation_Impl
  //
  Operation_Impl::Operation_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Operation_Impl
  //
  Operation_Impl::~Operation_Impl (void)
  {
  }

  //
  // accept
  //
  void Operation_Impl::accept (Visitor * v)
  {
    v->visit_Operation (this);
  }

  //
  // _create
  //
  Operation Operation_Impl::_create (const Worker_in parent)
  {
    return ::GAME::Mga::create_object <Operation> (parent, Operation_Impl::metaname);
  }

  //
  // get_ReturnType
  //
  ReturnType Operation_Impl::get_ReturnType (void) const
  {
    // Get the collection of children.
    std::vector <ReturnType> items;
    this->children (items);

    return !items.empty () ? items.front () : ReturnType ();
  }

  //
  // get_ParameterTypes
  //
  size_t Operation_Impl::get_ParameterTypes (std::vector <ParameterType> & items) const
  {
    return this->children (items);
  }

  //
  // parent_Worker
  //
  Worker Operation_Impl::parent_Worker (void) const
  {
    return ::GAME::Mga::get_parent <Worker> (this->object_.p);
  }
}

