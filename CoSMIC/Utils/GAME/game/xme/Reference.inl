// -*- C++ -*-
// $Id$

namespace GME
{
namespace XME
{
//
// Reference
//
GME_INLINE
Reference::Reference (void)
: FCO (0, Object_Type::OT_REFERENCE)
{

}

//
// Reference
//
GME_INLINE
Reference::Reference (const Reference & atom)
: FCO (atom),
  refers_to_ (atom.refers_to_)
{

}

//
// Reference
//
GME_INLINE
Reference::
Reference (xercesc::DOMElement * ref)
: FCO (ref, Object_Type::OT_REFERENCE)
{
  // need to get referenced element
}

//
// Reference
//
GME_INLINE
Reference::
Reference (xercesc::DOMElement * ref, bool validate)
: FCO (ref, false)
{
  if (validate && !(this->type_ & Object_Type::OT_REFERENCE))
    throw Invalid_Cast ();
}

//
// Reference
//
GME_INLINE
Reference::~Reference (void)
{

}

//
// operator =
//
GME_INLINE
const Reference & Reference::operator = (const Reference & ref)
{
  this->obj_ = ref.obj_;
  this->refers_to_ = ref.refers_to_;
  return *this;
}

//
// refers_to
//
GME_INLINE
FCO Reference::refers_to (void) const
{
  return this->refers_to_;
}

//
// _narrow
//
GME_INLINE
Reference Reference::_narrow (const Object & obj)
{
  if ((obj.type () & Object_Type::OT_REFERENCE))
    return obj.ptr ();

  throw Invalid_Cast ();
}

}
}
