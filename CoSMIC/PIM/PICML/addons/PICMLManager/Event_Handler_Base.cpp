// $Id$

#include "StdAfx.h"
#include "Event_Handler_Base.h"
#include "PICMLManager_Impl.h"

#include "game/GAME.h"
#include "game/be/Event_Handler.h"
#include "game/dialogs/Selection_List_Dialog_T.h"
#include "game/utils/modelgen.h"
#include "game/utils/Point.h"

#include "Utils/Utils.h"

#include "boost/bind.hpp"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

#include <algorithm>
#include <sstream>
#include <functional>

static const long EVENTMASK =
   OBJEVENT_CREATED | OBJEVENT_ATTR |
   OBJEVENT_RELATION |  OBJEVENT_SELECT |
   OBJEVENT_SETINCLUDED | OBJEVENT_SETEXCLUDED |
   OBJEVENT_DESTROYED | OBJEVENT_LOSTCHILD;

namespace PICML
{
namespace MI
{

//
// Event_Handler_Base
//
Event_Handler_Base::Event_Handler_Base (unsigned long mask)
: Event_Handler_Impl (mask)
{

}

//
// ~Event_Handler_Base
//
Event_Handler_Base::~Event_Handler_Base (void)
{

}

//
// set_property_type
//
void Event_Handler_Base::
set_property_type (GAME::Model_in prop, const GAME::FCO_in type)
{
  GAME::Meta::FCO metafco = type->meta ();
  GAME::FCO real_type = type;

  // We need to remove all the mask of this alias. Only then can
  // we really set the property's type.
  while (metafco->name () == "Alias")
  {
    GAME::Reference alias = GAME::Reference::_narrow (real_type);
    real_type = alias->refers_to ();
    metafco = real_type->meta ();
  }

  std::string metaname = metafco->name ();
  if (metaname == "Aggregate" || metaname == "Collection")
  {
    GAME::Reference complex;
    std::vector <GAME::Reference> complex_refs;

    // We are working with a predefined type, or an Enum.
    if (0 == prop->children ("ComplexTypeReference", complex_refs))
      complex = GAME::Reference::impl_type::_create (prop, "ComplexTypeReference");
    else
      complex = complex_refs.front ();
\
    // Set the reference for the type. This will force the
    // add-on to make sure each member is set correct.
    complex->refers_to (type);
  }
  else
  {
    GAME::Reference datavalue;
    std::vector <GAME::Reference> datavalues;

    // We are working with a predefined type, or an Enum.
    if (0 == prop->children ("DataValue", datavalues))
      datavalue = GAME::Reference::impl_type::_create (prop, "DataValue");
    else
      datavalue = datavalues.front ();

    // Set the name of the data type and its reference.
    const std::string propname = prop->name ();
    if (datavalue->name () != propname)
      datavalue->name (propname);

    // Get the current data type.
    GAME::FCO current = datavalue->refers_to ();

    if (current.is_nil () || (current != type))
      datavalue->refers_to (type);
  }
}

}
}