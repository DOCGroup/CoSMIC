// $Id$

#include "StdAfx.h"
#include "Operation.h"

#if !defined (__GAME_INLINE__)
#include "Operation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/Worker.h"
#include "PICML/OperationTypes/ReturnType.h"
#include "PICML/OperationTypes/ParameterType.h"
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
  // _create (const Worker_in)
  //
  Operation Operation_Impl::_create (const Worker_in parent)
  {
    return ::GAME::Mga::create_object < Operation > (parent, Operation_Impl::metaname);
  }

  //
  // accept
  //
  void Operation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Operation (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
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
    return this->children <ReturnType> ().item ();
  }

  //
  // get_ParameterTypes
  //
  size_t Operation_Impl::get_ParameterTypes (std::vector <ParameterType> & items) const
  {
    return this->children (items);
  }

  //
  // get_ParameterTypes
  //
  ::GAME::Mga::Iterator <ParameterType> Operation_Impl::get_ParameterTypes (void) const
  {
    return this->children <ParameterType> ();
  }
}

