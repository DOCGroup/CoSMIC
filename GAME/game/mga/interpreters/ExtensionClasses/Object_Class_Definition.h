// -*- C++ -*-

//==============================================================================
/**
 *  @file        Object_Class_Definition.h
 *
 *  $Id$
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_EXTENSION_CLASSES_OBJECT_CLASS_DEFINITION_H_
#define _GAME_EXTENSION_CLASSES_OBJECT_CLASS_DEFINITION_H_

#include "Class_Definition.h"
#include <set>

class Base_Class_Locator;

// Forward decl.
class Object_Class_Definition;

/// Type definition for unique object class definitions.
typedef std::set <Object_Class_Definition *> Unique_Object_Class_Definitions;

/**
 * @class Object_Class_Definition
 *
 * Class definition for all object types in GME.
 */
class Object_Class_Definition : public Class_Definition
{
public:
  friend class Base_Class_Locator;

  /// Default constructor.
  Object_Class_Definition (void);

  /// Destructor.
  virtual ~Object_Class_Definition (void);

  /// Build the class definition for the object.
  virtual void build (GAME::Mga::FCO_in fco);

  /**
   * Generate the class definition.
   *
   * @param[in]       hfile           Target header file stream
   * @param[in]       sfile           Target source file stream
   * @param[in]       ifile           Target inline file stream
   */
  void generate (const Generation_Context & ctx);

  /**
   * Template method that allows subclasses to generate their portion
   * of a class definition. This method cannot be called via the a pointer
   * to Class_Definition. Instead, it is called by this classes implementation
   * of the generate () method.
   *
   * @param[in]       hfile           Target header file stream
   * @param[in]       sfile           Target source file stream
   * @param[in]       ifile           Target inline file stream
   */
  virtual void generate_definition (const Generation_Context & ctx) = 0;

  /// Test if the object is abstract.
  bool is_abstract (void) const;

  /// Test if the object is in the root folder.
  bool in_root_folder (void) const;

  /// Compute the path of the object.
  std::string compute_path (std::string separator, bool trailing) const;

  /// Get the name of the object class definition.
  const std::string & name (void) const;

  /// Get the name of the generated class.
  const std::string & classname (void) const;

  /// Get the metaname of the object (i.e., Atom, Model, Folder, etc.)
  const std::string & metaname (void) const;

  /// Get the class definitions Mga object
  GAME::Mga::FCO_in get_object (void) const;

  /// Get the list of base classes.
  const std::set <Object_Class_Definition *> & base_classes (void) const;

  /// Get the list of the derived classes.
  const std::set <Object_Class_Definition *> & derived_classes (void) const;

  /// Get the list of parent classes.
  const std::set <Object_Class_Definition *> & parents (void) const;

  /// Add a new parent object to this class definition.
  void insert_parent (Object_Class_Definition * parent);
  void insert_dependency (Object_Class_Definition * object);

protected:
  /// Base class connection for this object.
  Unique_Object_Class_Definitions base_classes_;

  /// Derived class for this object.
  Unique_Object_Class_Definitions derived_classes_;

  /// Parent elements for this model element.
  Unique_Object_Class_Definitions parents_;

  /// Collection of source include files.
  Unique_Object_Class_Definitions source_includes_;

  /// The object is in the root folder.
  bool in_root_folder_;

  /// The object is abstract.
  bool is_abstract_;

  /// The name of the element.
  std::string name_;

  /// The class name for the model element.
  std::string classname_;

  /// The default base class for this model element.
  std::string default_base_classname_;

  /// Metaname definition for the element.
  std::string metaname_;

  /// The class definitions corresponding object.
  GAME::Mga::FCO obj_;

private:
  /// Helper method that generates the elements factory method.
  void generate_parent_method (const Generation_Context &, Object_Class_Definition *);
};

#if defined (__GAME_INLINE__)
#include "Object_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _GAME_EXTENSION_CLASSES_OBJECT_CLASS_DEFINITION_H_
