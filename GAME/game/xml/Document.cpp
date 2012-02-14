// $Id$

#include "Document.h"

#if !defined (__GAME_INLINE__)
#include "Document.inl"
#endif

namespace GAME
{
namespace Xml
{

//
// create
//
int Document::create (const String & ns, const String & root)
{
  // Close the exising document.
  this->close ();

  // Create a new document.
  this->doc_ = this->impl_->createDocument (ns, root, 0);

  Fragment * fragment = 0;
  ACE_NEW_RETURN (fragment,
                  Fragment (this->doc_->getDocumentElement ()),
                  -1);
  this->root_.reset (fragment);

  // Set the XML version number.
  if (this->doc_)
    this->doc_->setXmlVersion (String ("1.0"));

  return 0;
}

//
// close
//
void Document::close (void)
{
  if (0 == this->doc_)
    return;

  // Make sure we release the old document.
  this->doc_->release ();
  this->doc_ = 0;

  // Reset the fragment
  this->root_.reset (0);
}

//
// LS_Document
//
LS_Document::LS_Document (void)
: Document (0)
{
  using namespace xercesc;

  // Get the LS DOM implementation.
  static const XMLCh LS[3] = {chLatin_L, chLatin_S, chNull};
  this->impl_ = DOMImplementationRegistry::getDOMImplementation (LS);
}

//
// ~LS_Document
//
LS_Document::~LS_Document (void)
{

}

}
}
