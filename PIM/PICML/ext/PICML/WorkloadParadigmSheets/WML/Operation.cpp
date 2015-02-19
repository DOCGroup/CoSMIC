// $Id$

#include "StdAfx.h"
#include "Operation.h"

#if !defined (__GAME_INLINE__)
#include "Operation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/Worker.h"
#include "PICML/OperationTypes/ParameterType.h"
#include "PICML/OperationTypes/InParameter.h"
#include "PICML/OperationTypes/OutParameter.h"
#include "PICML/OperationTypes/InoutParameter.h"
#include "PICML/OperationTypes/ReturnType.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionType.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Operation_Impl::metaname ("Operation");

  //
  // is_abstract
  //
  const bool Operation_Impl::is_abstract = false;

  //
  // _create (const Worker_in)
  //
  Operation Operation_Impl::_create (const Worker_in parent)
  {
    return ::GAME::Mga::create < Operation > (parent, Operation_Impl::metaname);
  }

  //
  // accept
  //
  void Operation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Operation (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Worker
  //
  Worker Operation_Impl::parent_Worker (void)
  {
    return Worker::_narrow (this->parent ());
  }

  //
  // has_ReturnType
  //
  bool Operation_Impl::has_ReturnType (void) const
  {
    return this->children <ReturnType> ().count () == 1;
  }

  //
  // get_ReturnType
  //
  ReturnType Operation_Impl::get_ReturnType (void) const
  {
    return this->children <ReturnType> ().first ();
  }

  //
  // get_InParameters
  //
  size_t Operation_Impl::get_InParameters (std::vector <InParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_InParameters
  //
  ::GAME::Mga::Collection_T <InParameter> Operation_Impl::get_InParameters (void) const
  {
    return this->children <InParameter> ();
  }

  //
  // get_OutParameters
  //
  size_t Operation_Impl::get_OutParameters (std::vector <OutParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_OutParameters
  //
  ::GAME::Mga::Collection_T <OutParameter> Operation_Impl::get_OutParameters (void) const
  {
    return this->children <OutParameter> ();
  }

  //
  // get_InoutParameters
  //
  size_t Operation_Impl::get_InoutParameters (std::vector <InoutParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_InoutParameters
  //
  ::GAME::Mga::Collection_T <InoutParameter> Operation_Impl::get_InoutParameters (void) const
  {
    return this->children <InoutParameter> ();
  }
}

