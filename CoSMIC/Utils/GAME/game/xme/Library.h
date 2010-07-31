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

  static ::Utils::XStr xme_to_libref (const ::Utils::XStr & xme);

protected:
  Library (const ::Utils::XStr & location, xercesc::DOMElement * parent);

private:
  Library (xercesc::DOMElement * libnode,
           const ::Utils::XStr & libpath,
           bool validate = true);

  static const ::Utils::XStr ATTR_LIBREF;
};

}
}

#if defined (__GAME_INLINE__)
#include "Library.inl"
#endif

#endif  // !defined _GAME_XME_FOLDER_H_
