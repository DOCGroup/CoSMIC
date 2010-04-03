// -*- C++ -*-
// $Id$

namespace GME
{
namespace XME
{
//
// FCO
//
GME_INLINE
FCO::FCO (void)
: Object (0, Object_Type::OT_FCO)
{

}

//
// FCO
//
GME_INLINE
FCO::FCO (const FCO & fco)
: Object (fco)
{

}

//
// FCO
//
GME_INLINE
FCO::FCO (xercesc::DOMElement * fco,  bool validate)
: Object (fco, false)
{
  if (validate && !(this->type_ & Object_Type::OT_FCO))
    throw Invalid_Cast ();
}

//
// FCO
//
GME_INLINE
FCO::FCO (xercesc::DOMElement * fco, int type)
: Object (fco, type)
{

}

//
// FCO
//
GME_INLINE
FCO::
FCO (xercesc::DOMElement * parent,
     const ::Utils::XStr & tagname,
     const ::Utils::XStr & id,
     const ::Utils::XStr & kind,
     const ::Utils::XStr & role,
     size_t relid)
: Object (parent, tagname, id, kind, relid)
{
  this->obj_->setAttribute (ATTR_ROLE, kind);
}

//
// ~FCO
//
GME_INLINE
FCO::~FCO (void)
{

}

//
// operator =
//
GME_INLINE
const FCO & FCO::operator = (const FCO & fco)
{
  this->attach (fco.obj_);
  return *this;
}

}
}
