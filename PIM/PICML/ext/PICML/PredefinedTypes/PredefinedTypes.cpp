// $Id$

#include "StdAfx.h"
#include "PredefinedTypes.h"

#if !defined (__GAME_INLINE__)
#include "PredefinedTypes.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PredefinedTypes/PredefinedType.h"
#include "PICML/PredefinedTypes/CharType.h"
#include "PICML/PredefinedTypes/Char.h"
#include "PICML/PredefinedTypes/WideChar.h"
#include "PICML/PredefinedTypes/StringType.h"
#include "PICML/PredefinedTypes/WideString.h"
#include "PICML/PredefinedTypes/String.h"
#include "PICML/PredefinedTypes/IntegerType.h"
#include "PICML/PredefinedTypes/UnsignedIntegerType.h"
#include "PICML/PredefinedTypes/UnsignedShortInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongLongInteger.h"
#include "PICML/PredefinedTypes/SignedIntegerType.h"
#include "PICML/PredefinedTypes/LongLongInteger.h"
#include "PICML/PredefinedTypes/LongInteger.h"
#include "PICML/PredefinedTypes/ShortInteger.h"
#include "PICML/PredefinedTypes/FloatingPointType.h"
#include "PICML/PredefinedTypes/LongDoubleNumber.h"
#include "PICML/PredefinedTypes/DoubleNumber.h"
#include "PICML/PredefinedTypes/FloatNumber.h"
#include "PICML/PredefinedTypes/TypeKind.h"
#include "PICML/PredefinedTypes/TypeEncoding.h"
#include "PICML/PredefinedTypes/GenericValue.h"
#include "PICML/PredefinedTypes/GenericValueObject.h"
#include "PICML/PredefinedTypes/GenericObject.h"
#include "PICML/PredefinedTypes/Boolean.h"
#include "PICML/PredefinedTypes/Byte.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PredefinedTypes_Impl::metaname ("PredefinedTypes");

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  PredefinedTypes PredefinedTypes_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <PredefinedTypes> (parent, PredefinedTypes_Impl::metaname);
  }

  //
  // accept
  //
  void PredefinedTypes_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PredefinedTypes (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder PredefinedTypes_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_PredefinedTypes
  //
  size_t PredefinedTypes_Impl::get_PredefinedTypes (std::vector <PredefinedType> & items) const
  {
    return this->children (items);
  }

  //
  // get_PredefinedTypes
  //
  ::GAME::Mga::Collection_T <PredefinedType> PredefinedTypes_Impl::get_PredefinedTypes (void) const
  {
    return this->children <PredefinedType> ();
  }
}

