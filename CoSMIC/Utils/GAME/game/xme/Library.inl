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
Library (const ::Utils::XStr & location, xercesc::DOMElement * parent)
: Folder (parent)
{
  this->ptr ()->setAttribute (ATTR_LIBREF, location);
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

}
}
