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
//
// ATTR_LIBREF
//
const ::Utils::XStr Library::ATTR_LIBREF ("libref");

//
// Library
//
Library::Library (xercesc::DOMElement * folder, bool validate)
: Folder (folder, validate)
{
  if (validate)
  {
    static const ::Utils::XStr kindname ("RootFolder");
    const ::Utils::XStr kind (this->kind (), false);

    if (kind != kindname)
      throw Invalid_Cast ();
  }
}

//
// attach
//
void Library::attach (xercesc::DOMElement * e, bool validate)
{
  // First, pass control to the base class.
  Folder::attach (e, validate);

  if (validate)
  {
    // Validate the element at this level now.
    static const ::Utils::XStr kindname ("RootFolder");
    const ::Utils::XStr kind (this->kind (), false);

    if (kind != kindname)
      throw Invalid_Cast ();
  }
}

//
// xme_to_libref
//
::Utils::XStr Library::xme_to_libref (const ::Utils::XStr & xmefile)
{
  ::Utils::XStr libref ("MGA=");
  libref.append (xmefile);

  size_t length = xmefile.size ();
  libref[length - 3] = xercesc::chLatin_m;
  libref[length - 2] = xercesc::chLatin_g;
  libref[length - 1] = xercesc::chLatin_a;

  return libref;
}

}
}
