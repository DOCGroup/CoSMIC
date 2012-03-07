// $Id$

#include "StdAfx.h"
#include "TwowayOperation.h"

#if !defined (__GAME_INLINE__)
#include "TwowayOperation.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/OperationTypes/HasExceptions.h"
#include "PICML/OperationTypes/InoutParameter.h"
#include "PICML/OperationTypes/OutParameter.h"
#include "PICML/OperationTypes/ReturnType.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TwowayOperation_Impl::metaname ("TwowayOperation");

  //
  // _create (const HasOperations_in)
  //
  TwowayOperation TwowayOperation_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create_object < TwowayOperation > (parent, TwowayOperation_Impl::metaname);
  }

  //
  // _create (const HasExceptions_in)
  //
  TwowayOperation TwowayOperation_Impl::_create (const HasExceptions_in parent)
  {
    return ::GAME::Mga::create_object < TwowayOperation > (parent, TwowayOperation_Impl::metaname);
  }

  //
  // accept
  //
  void TwowayOperation_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TwowayOperation (this);
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
  bool TwowayOperation_Impl::has_ReturnType (void) const
  {
    return this->children <ReturnType> ().count () == 1;
  }

  //
  // get_ReturnType
  //
  ReturnType TwowayOperation_Impl::get_ReturnType (void) const
  {
    return this->children <ReturnType> ().item ();
  }

  //
  // get_InoutParameters
  //
  size_t TwowayOperation_Impl::get_InoutParameters (std::vector <InoutParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_InoutParameters
  //
  ::GAME::Mga::Iterator <InoutParameter> TwowayOperation_Impl::get_InoutParameters (void) const
  {
    return this->children <InoutParameter> ();
  }

  //
  // get_OutParameters
  //
  size_t TwowayOperation_Impl::get_OutParameters (std::vector <OutParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_OutParameters
  //
  ::GAME::Mga::Iterator <OutParameter> TwowayOperation_Impl::get_OutParameters (void) const
  {
    return this->children <OutParameter> ();
  }
}

