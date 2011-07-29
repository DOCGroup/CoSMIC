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
const GAME::Xml::String Library::ATTR_LIBREF ("libref");

//
// Library
//
Library::Library (xercesc::DOMElement * folder, bool validate)
: Folder (folder, validate)
{
  if (validate)
  {
    static const GAME::Xml::String kindname ("RootFolder");
    const GAME::Xml::String kind (this->kind (), false);

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
    static const GAME::Xml::String kindname ("RootFolder");
    const GAME::Xml::String kind (this->kind (), false);

    if (kind != kindname)
      throw Invalid_Cast ();
  }
}

//
// xme_to_libref
//
GAME::Xml::String Library::xme_to_libref (const GAME::Xml::String & xmefile)
{
  GAME::Xml::String libref ("MGA=");
  libref.append (xmefile);

  size_t length = libref.length ();
  libref[length - 3] = xercesc::chLatin_m;
  libref[length - 2] = xercesc::chLatin_g;
  libref[length - 1] = xercesc::chLatin_a;

  return libref;
}

//
// attached_libraries
//
size_t Library::attached_libraries (std::vector <Library> & libs)
{
  static const GAME::Xml::String metaname ("RootFolder");
  std::vector <Folder> temp;

  if (this->children (metaname, temp))
  {
    std::vector <Folder>::iterator
      iter = temp.begin (), iter_end = temp.end ();

    for (; iter != iter_end; ++ iter)
      libs.push_back (Library (iter->ptr (), true));
  }

  return libs.size ();
}

}
}
