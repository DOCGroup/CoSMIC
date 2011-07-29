// -*- C++ -*-

//=============================================================================
/**
 * @file      Library.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_LIBRARY_H_
#define _GAME_XME_LIBRARY_H_

#include "Folder.h"

namespace GAME
{
namespace XME
{
// Forward decl.
class Project;

/**
 * @class Library
 *
 * Base class for all the objects
 */
class GAME_XME_Export Library : public Folder
{
  friend class Project;

public:
  /// Default constructor.
  Library (void);

  /**
   * Initializing constructor
   *
   * @param[in]     obj       The source object.
   */
  Library (xercesc::DOMElement * folder, bool validate);

  /**
   * Copy constructor
   *
   * @param[in]     obj       The source object
   */
  Library (const Library & library);

  /// Destructor.
  ~Library (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const Library & operator = (const Library & library);

  /// Get the reference location of the library.
  const XMLCh * libref (void) const;

  virtual void attach (xercesc::DOMElement * e, bool validate = true);

  static GAME::Xml::String xme_to_libref (const GAME::Xml::String & xme);

  /// Get the collection of attached libraries.
  size_t attached_libraries (std::vector <Library> & libs);

protected:
  Library (const GAME::Xml::String & location, xercesc::DOMElement * parent);

private:
  Library (xercesc::DOMElement * libnode,
           const GAME::Xml::String & libpath,
           bool validate = true);

  static const GAME::Xml::String ATTR_LIBREF;
};

}
}

#if defined (__GAME_INLINE__)
#include "Library.inl"
#endif

#endif  // !defined _GAME_XME_FOLDER_H_
