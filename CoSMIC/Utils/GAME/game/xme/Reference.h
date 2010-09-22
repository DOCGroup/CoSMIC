// -*- C++ -*-

//=============================================================================
/**
 * @file      Reference.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_REFERENCE_H_
#define _GAME_XME_REFERENCE_H_

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
 * @class Reference
 *
 * Base class for all the objects
 */
class GAME_XME_Export Reference : public FCO
{
public:
  /**
   * Create a new folder
   *
   * @param[in]       parent          Parent of the new folder
   * @param[in]       kind            Type folder's type
   */
  static Reference _create (Folder parent, const GAME::Xml::String & kind);

  /**
   * Create a new folder
   *
   * @param[in]       parent          Parent of the new folder
   * @param[in]       kind            Type folder's type
   */
  static Reference _create (Model parent, const GAME::Xml::String & kind);

  /**
   * Narrow an object to an atom.
   *
   * @param[in]       obj             Source object
   * @return          The atom version of the object
   */
  static Reference _narrow (const Object & obj);

  /// Default constructor.
  Reference (void);

  /**
   * Initializing constructor
   *
   * @param[in]     obj       The source object.
   */
  Reference (xercesc::DOMElement * ref, bool validate);

  /**
   * Copy constructor
   *
   * @param[in]     obj       The source object
   */
  Reference (const Reference & atom);

  /// Destructor.
  ~Reference (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const Reference & operator = (const Reference & atom);

  /**
   * Get the FCO that this object references.
   *
   * @return        Referenced FCO
   */
  FCO refers_to (void) const;

  /**
   * Set the FCO this object references
   *
   * @param[in]     fco       Target FCO
   */
  void refers_to (const FCO & fco);

  /// Reset the reference. This will remove the current FCO
  /// that this object references.
  void reset (void);

  /// The XML tagname for this element.
  static const GAME::Xml::String TAGNAME;

  /// Test if the reference is null.
  bool is_null (void) const;

  /// Refresh the state of the reference. This will relocate the
  /// referred object and store it, or set the point to null of it
  /// no longer exists.
  void refresh (void);

protected:
  /**
   * Initializing constructor. This constructor creates the actual
   * DOMElement that represents the folder object.
   */
  Reference (xercesc::DOMElement * parent,
             const GAME::Xml::String & kind,
             size_t relid);

  Reference (xercesc::DOMElement * ref);

private:
  /// Helper method that locates referenced object in document.
  void get_reference (void) const;

  /// Implementation of the creation method.
  template <typename T>
  static Reference create_impl (T parent, const GAME::Xml::String & kind);

  /// FCO that this object references.
  mutable FCO refers_to_;

  /// XML attributes for this element.
  static const GAME::Xml::String ATTR_REFERRED;
  static const GAME::Xml::String NULL_REFERENCE;

};

}
}

#if defined (__GAME_INLINE__)
#include "Reference.inl"
#endif

#endif  // !defined _GAME_XME_ATOM_H_
