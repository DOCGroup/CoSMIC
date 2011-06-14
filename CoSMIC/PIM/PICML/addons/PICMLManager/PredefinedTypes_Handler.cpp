// $Id$

#include "StdAfx.h"
#include "PredefinedTypes_Handler.h"

#include "game/mga/modelgen.h"
#include "game/mga/Atom.h"
#include "game/mga/RootFolder.h"
#include "game/mga/Transaction.h"

#include "boost/bind.hpp"
#include <functional>

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_CREATED;

//
// PredefinedTypes_Handler
//
PredefinedTypes_Handler::PredefinedTypes_Handler (void)
: GAME::Mga::Event_Handler_Impl (mask)
{

}

//
// ~PredefinedTypes_Handler
//
PredefinedTypes_Handler::~PredefinedTypes_Handler (void)
{

}

//
// handle_object_created
//
int PredefinedTypes_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  GAME::Mga::Folder predefined_types = GAME::Mga::Folder::_narrow (obj);

  static const char * metanames [] =
  {
    "Boolean",
    "Byte",
    "Char",
    "WideChar",
    "String",
    "WideString",
    "ShortInteger",
    "LongInteger",
    "LongLongInteger",
    "UnsignedShortInteger",
    "UnsignedLongInteger",
    "UnsignedLongLongInteger",
    "FloatNumber",
    "DoubleNumber",
    "LongDoubleNumber",
    "GenericObject",
    "GenericValue",
    "GenericValueObject",
    0
  };

  for (const char ** ptr = metanames; *ptr != 0; ++ ptr)
  {
    GAME::Mga::Atom predefined_type;
    if (GAME::create_if_not <GAME::Mga_t> (predefined_types, *ptr, predefined_type,
        GAME::contains <GAME::Mga_t> (boost::bind (std::equal_to <std::string> (),
                                      *ptr,
                                      boost::bind (&GAME::Mga::Atom::impl_type::name,
                                                   boost::bind (&GAME::Mga::Atom::get, _1))))))
    {
      predefined_type->name (*ptr);
    }
  }

  return 0;
}

}
}
