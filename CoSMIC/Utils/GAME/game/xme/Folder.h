// -*- C++ -*-

//=============================================================================
/**
 * @file      Folder.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_FOLDER_H_
#define _GAME_XME_FOLDER_H_

#include "Model.h"

namespace GAME
{
namespace XME
{
// Forward decl.
class Project;

/**
 * @class Folder
 *
 * Base class for all the objects
 */
class GAME_XME_Export Folder : public Object
{
public:
  friend class Project;

  /**
   * Create a new folder
   *
   * @param[in]       parent          Parent of the new folder
   * @param[in]       kind            Type folder's type
   */
  static Folder _create (Folder parent, const GAME::Xml::String & kind);

  static Folder _narrow (const Object & obj);

  /// Default constructor.
  Folder (void);

  /**
   * Initializing constructor
   *
   * @param[in]     obj       The source object.
   */
  Folder (xercesc::DOMElement * folder, bool validate);

  /**
   * Copy constructor
   *
   * @param[in]     obj       The source object
   */
  Folder (const Folder & folder);

  /// Destructor.
  ~Folder (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const Folder & operator = (const Folder & folder);

  /**
   * Attached to the specified element. This object will take
   * ownership of the element, and manage its resources.
   *
   * @param[in]     obj       Source object to attach.
   */
  void attach (xercesc::DOMElement * obj, bool validate = true);

  /**
   * Get all the child folders for this folder.
   *
   * @param[out]    coll      Child folders
   * @return        Number of folders in collection
   */
  size_t children (std::vector <Folder> & folders);

  /**
   * @overload
   *
   * @param[in]     metaname          Metaname of the child folders.
   */
  size_t children (const GAME::Xml::String & metaname, std::vector <Folder> & coll);

  size_t children (std::vector <FCO> & coll);
  size_t children (const GAME::Xml::String & metaname, std::vector <FCO> & coll);

  size_t children (std::vector <Atom> & coll);
  size_t children (const GAME::Xml::String & metaname, std::vector <Atom> & coll);

  size_t children (std::vector <Model> & coll);
  size_t children (const GAME::Xml::String & metaname, std::vector <Model> & coll);

  /**
   * Reset the relative id counter. This method should only be
   * invoked if you know what you are doing.
   *
   * @param[in]     value             New value of the counter
   */
  void relid_counter (size_t value);

  /**
   * Get the current value of the relative id counter
   *
   * @return        Relative id counter value
   */
  size_t relid_counter (void) const;

  /// The XML tagname for this element.
  static const GAME::Xml::String TAGNAME;

protected:
  /**
   * Initializing constructor. This constructor creates the actual
   * DOMElement that represents the folder object.
   */
  Folder (xercesc::DOMElement * parent,
          const GAME::Xml::String & kind,
          size_t relid);

  Folder (xercesc::DOMElement * parent);

private:
  /// Help method for initializing the counter.
  void initialize_counter (void);

  /// The relative id counter for its children.
  size_t counter_;

  static const GAME::Xml::String ATTR_CHILDRELIDCNTR;
  static const GAME::Xml::String NO_CHILDREN;
};

}
}

#if defined (__GAME_INLINE__)
#include "Folder.inl"
#endif

#endif  // !defined _GAME_XME_FOLDER_H_
