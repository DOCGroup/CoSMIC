// $Id$

#include "Library.h"

#if !defined (__GAME_INLINE__)
#include "Library.inl"
#endif

#include "Project.h"
#include "Library_Importer.h"

namespace GAME
{
namespace XME
{
const ::Utils::XStr Library::ATTR_LIBREF ("libref");

//
// Library
//
Library::
Library (xercesc::DOMElement * libnode, 
         const ::Utils::XStr & libpath, 
         bool validate)
: Folder (libnode, validate)
{
  ::Utils::XStr libref ("MGA=");
  libref.append (libpath);

  size_t length = libref.size ();
  libref[length - 3] = xercesc::chLatin_m;
  libref[length - 2] = xercesc::chLatin_g;
  libref[length - 1] = xercesc::chLatin_a;

  this->obj_->setAttribute (ATTR_LIBREF, libref);
}


}
}
