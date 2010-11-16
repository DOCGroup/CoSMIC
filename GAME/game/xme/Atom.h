// -*- C++ -*-

//=============================================================================
/**
 * @file      Atom.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_ATOM_H_
#define _GAME_XME_ATOM_H_

#include "FCO.h"

namespace GAME
{
namespace XME
{
// Forward decl.
class Folder;

// Forward decl.
class Model;

/**
 * @class Atom
 *
 * Base class for all the objects
 */
class GAME_XME_Export Atom : public FCO
{
public:
  /**
   * Create a new folder
   *
   * @param[in]       parent          Parent of the new folder
   * @param[in]       kind            Type folder's type
   */
  static Atom _create (Folder parent, const GAME::Xml::String & kind);

  /**
   * Create a new folder
   *
   * @param[in]       parent          Parent of the new folder
   * @param[in]       kind            Type folder's type
   */
  static Atom _create (Model parent, const GAME::Xml::String & kind);

  /**
   * Narrow an object to an atom.
   *
   * @param[in]       obj             Source object
   * @return          The atom version of the object
   */
  static Atom _narrow (const Object & obj);

  /// Default constructor.
  Atom (void);

  /**
   * Initializing constructor
   *
   * @param[in]     obj       The source object.
   */
  Atom (xercesc::DOMElement * atom, bool validate);

  /**
   * Copy constructor
   *
   * @param[in]     obj       The source object
   */
  Atom (const Atom & atom);

  /// Destructor.
  ~Atom (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const Atom & operator = (const Atom & atom);

  /// The XML tagname for this element.
  static const GAME::Xml::String TAGNAME;

protected:
  /// Initializing constructor. This constructor creates the actual
  /// DOMElement that represents the folder object.
  Atom (xercesc::DOMElement * parent,
        const GAME::Xml::String & kind,
        size_t relid);

  Atom (xercesc::DOMElement * parent);

private:
  /// Implementation of the creation method.
  template <typename T>
  static Atom create_impl (T parent, const GAME::Xml::String & kind);
};

}
}

#if defined (__GAME_INLINE__)
#include "Atom.inl"
#endif

#endif  // !defined _GAME_XME_ATOM_H_
