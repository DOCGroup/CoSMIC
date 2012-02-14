
//=============================================================================
/**
 *  @file         Document.h
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================


#ifndef _GAME_XML_DOCUMENT_H_
#define _GAME_XML_DOCUMENT_H_

#include "xercesc/dom/DOM.hpp"
#include "Fragment.h"
#include <memory>

namespace GAME
{
namespace Xml
{
class Fragment;

/**
 * @class Document
 */
class GAME_XML_Export Document
{
public:
  /// Default constructor
  Document (xercesc::DOMImplementation * impl);

  /// Destructor.
  virtual ~Document (void);

  int create (const String & ns, const String & root);

  /// Close the document.
  void close (void);

  /// Get the underlying implementation.
  xercesc::DOMDocument * operator -> (void) const;

  /// Get the underlying implementation.
  xercesc::DOMImplementation * impl (void) const;

  /// Get the underlying document.
  xercesc::DOMDocument * doc (void) const;

  /// Get the root element fore the document.
  Fragment & root (void);
  const Fragment & root (void) const;

protected:
  /// The document's implementation
  xercesc::DOMImplementation * impl_;

  /// Contained document.
  xercesc::DOMDocument * doc_;

  /// The fragment for the root part of the document.
  std::auto_ptr <Fragment> root_;
};

/**
 * @class LS_Document
 */
class GAME_XML_Export LS_Document : public Document
{
public:
  /// Default constructor.
  LS_Document (void);

  /// Destructor.
  virtual ~LS_Document (void);
};

}
}

#if defined (__GAME_INLINE__)
#include "Document.inl"
#endif

#endif  // !defined _GAME_XML_DOCUMENT_H_
