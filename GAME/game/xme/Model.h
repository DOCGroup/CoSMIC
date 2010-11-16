// -*- C++ -*-

//=============================================================================
/**
 * @file      Model.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_MODEL_H_
#define _GAME_XME_MODEL_H_

#include "Atom.h"
#include "Reference.h"
#include "Connection.h"

namespace GAME
{
namespace XME
{
/**
 * @class Model
 *
 * Base class for all the objects
 */
class GAME_XME_Export Model : public FCO
{
public:
  /**
   * Create a new model
   *
   * @param[in]       parent          Parent of the new folder
   * @param[in]       kind            Type folder's type
   */
  static Model _create (Model parent, const GAME::Xml::String & kind);

  /**
   * Create a new model
   *
   * @param[in]       parent          Parent of the new folder
   * @param[in]       kind            Type folder's type
   */
  static Model _create (Folder parent, const GAME::Xml::String & kind);

  /**
   * Narrow an object to an model.
   *
   * @param[in]       obj             Source object
   * @return          The atom version of the object
   */
  static Model _narrow (const Object & obj);

  /// Default constructor.
  Model (void);

  /**
   * Initializing constructor
   *
   * @param[in]     obj       The source object.
   */
  Model (xercesc::DOMElement * folder, bool validate);

  /**
   * Copy constructor
   *
   * @param[in]     obj       The source object
   */
  Model (const Model & folder);

  /// Destructor.
  virtual ~Model (void);

  /**
   * Assignment operator
   *
   * @param[in]     obj       The right side of the operator
   */
  const Model & operator = (const Model & folder);

  /**
   * Attached to the specified element. This object will take
   * ownership of the element, and manage its resources.
   *
   * @param[in]     obj       Source object to attach.
   */
  void attach (xercesc::DOMElement * obj, bool validate = true);

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

  size_t children (std::vector <FCO> & atoms);
  size_t children (const GAME::Xml::String & metaname, std::vector <FCO> & coll);

  size_t children (std::vector <Atom> & atoms);
  size_t children (const GAME::Xml::String & metaname, std::vector <Atom> & coll);

  size_t children (std::vector <Model> & coll);
  size_t children (const GAME::Xml::String & metaname, std::vector <Model> & coll);

  size_t children (std::vector <Reference> & coll);
  size_t children (const GAME::Xml::String & metaname, std::vector <Reference> & coll);

  size_t children (std::vector <Connection> & coll);
  size_t children (const GAME::Xml::String & metaname, std::vector <Connection> & coll);

  /// The XML tagname for this element.
  static const GAME::Xml::String TAGNAME;

protected:
  /// Initializing constructor. This constructor creates the actual
  /// DOMElement that represents the folder object.
  Model (xercesc::DOMElement * parent,
         const GAME::Xml::String & kind,
         size_t relid);

  Model (xercesc::DOMElement * folder);

private:
  template <typename T>
  static Model create_impl (T parent, const GAME::Xml::String & kind);

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
#include "Model.inl"
#endif

#endif  // !defined _GAME_XME_MODEL_H_
