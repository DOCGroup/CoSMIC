// -*- C++ -*-
// $Id$

namespace GAME
{
namespace XME
{
//
// Library
//
GAME_INLINE
Library::Library (void)
{

}

//
// Library
//
GAME_INLINE
Library::
Library (const GAME::Xml::String & location, xercesc::DOMElement * parent)
: Folder (parent)
{
  this->ptr ()->setAttribute (ATTR_LIBREF, location);
}


//
// Library
//
GAME_INLINE
Library::Library (xercesc::DOMElement * libnode,
                  const GAME::Xml::String & libpath,
                  bool validate)
: Folder (libnode, validate)
{
  this->obj_->setAttribute (ATTR_LIBREF, xme_to_libref (libpath));
}

//
// Library
//
GAME_INLINE
Library::Library (const Library & lib)
: Folder (lib)
{

}

//
// ~Library
//
GAME_INLINE
Library::~Library (void)
{

}

//
// operator =
//
GAME_INLINE
const Library & Library::operator = (const Library & library)
{
  Folder::operator = (library);
  return *this;
}

//
// libref
//
GAME_INLINE
const XMLCh * Library::libref (void) const
{
  return this->ptr ()->getAttribute (ATTR_LIBREF);
}

}
}
