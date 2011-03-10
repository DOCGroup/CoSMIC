// $Id$

#include "stdafx.h"
#include "TwowayOperation.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/OperationTypes/OutParameter.h"
#include "PICML/OperationTypes/ReturnType.h"
#include "PICML/OperationTypes/InoutParameter.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TwowayOperation_Impl::metaname = "TwowayOperation";

  //
  // TwowayOperation_Impl
  //
  TwowayOperation_Impl::TwowayOperation_Impl (void)
  {
  }

  //
  // TwowayOperation_Impl
  //
  TwowayOperation_Impl::TwowayOperation_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TwowayOperation_Impl
  //
  TwowayOperation_Impl::~TwowayOperation_Impl (void)
  {
  }

  //
  // accept
  //
  void TwowayOperation_Impl::accept (Visitor * v)
  {
    v->visit_TwowayOperation (this);
  }

  //
  // get_OutParameters
  //
  size_t TwowayOperation_Impl::get_OutParameters (std::vector <OutParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_ReturnType
  //
  ReturnType TwowayOperation_Impl::get_ReturnType (void) const
  {
    // Get the collection of children.
    std::vector <ReturnType> items;
    this->children (items);

    return !items.empty () ? items.front () : ReturnType ();
  }

  //
  // get_InoutParameters
  //
  size_t TwowayOperation_Impl::get_InoutParameters (std::vector <InoutParameter> & items) const
  {
    return this->children (items);
  }
}

