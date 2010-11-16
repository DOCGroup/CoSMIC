// -*- C++ -*-
// $Id$

#include "XME_Utils.h"
#include "Registry.h"

namespace GAME
{
namespace XME
{
//
// FCO
//
GAME_INLINE
FCO::FCO (void)
: Object (0, Object_Type::OT_FCO)
{

}

//
// FCO
//
GAME_INLINE
FCO::FCO (const FCO & fco)
: Object (fco)
{

}

//
// FCO
//
GAME_INLINE
FCO::FCO (xercesc::DOMElement * fco,  bool validate)
: Object (fco, false)
{
  if (validate && !(this->type_ & Object_Type::OT_FCO))
    throw Invalid_Cast ();
}

//
// FCO
//
GAME_INLINE
FCO::FCO (xercesc::DOMElement * fco, int type)
: Object (fco, type)
{

}

//
// FCO
//
GAME_INLINE
FCO::
FCO (xercesc::DOMElement * parent,
     const GAME::Xml::String & tagname,
     const GAME::Xml::String & id,
     const GAME::Xml::String & kind,
     const GAME::Xml::String & role,
     size_t relid)
: Object (parent, tagname, id, kind, relid)
{
  this->obj_->setAttribute (ATTR_ROLE, kind);
}

//
// ~FCO
//
GAME_INLINE
FCO::~FCO (void)
{

}

//
// operator =
//
GAME_INLINE
const FCO & FCO::operator = (const FCO & fco)
{
  this->obj_ = fco.obj_;
  this->type_ = fco.type_;

  return *this;
}

//
// attributes
//
GAME_INLINE
size_t FCO::attributes (std::vector <Attribute> & attrs) const
{
  return Utils::get_children (this->obj_, attrs);
}

}
}
