// $Id$

#include "FCO.h"

#if !defined (__GME_INLINE__)
#include "FCO.inl"
#endif

namespace GME
{
namespace XME
{
const ::Utils::XStr FCO::ATTR_ROLE ("role");

//
// attach
//
void FCO::attach (xercesc::DOMElement * fco, bool validate)
{
  // Pass control to the base class.
  Object::attach (fco, false);

  // Validate the concrete type.
  if (validate && !(this->type_ & Object_Type::OT_FCO))
    throw Invalid_Cast ();
}
}
}
