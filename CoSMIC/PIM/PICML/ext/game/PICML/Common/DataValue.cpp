// $Id$

#include "stdafx.h"
#include "DataValue.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/Common/SimpleType.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string DataValue_Impl::metaname = "DataValue";

  //
  // DataValue_Impl
  //
  DataValue_Impl::DataValue_Impl (void)
  {
  }

  //
  // DataValue_Impl
  //
  DataValue_Impl::DataValue_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~DataValue_Impl
  //
  DataValue_Impl::~DataValue_Impl (void)
  {
  }

  //
  // accept
  //
  void DataValue_Impl::accept (Visitor * v)
  {
    v->visit_DataValue (this);
  }

  //
  // Value
  //
  void DataValue_Impl::Value (const std::string & val)
  {
    static const std::string attr_Value ("Value");
    this->attribute (attr_Value)->string_value (val);
  }

  //
  // Value
  //
  std::string DataValue_Impl::Value (void) const
  {
    static const std::string attr_Value ("Value");
    return this->attribute (attr_Value)->string_value ();
  }

  //
  // refers_to_SimpleType
  //
  SimpleType DataValue_Impl::refers_to_SimpleType (void) const
  {
    return ::GAME::Mga::get_refers_to <SimpleType> (this);
  }
}

