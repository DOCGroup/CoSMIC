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

/**
 * @class Object_Class_Definition
 *
 * Class definition for all object types in GME.
 */
class Object_Class_Definition :
  public Class_Definition
{
public:
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

protected:
  /// Get the include objects for this class definition. The include
  /// statement for these model elements will appear in the source
  /// file.
  virtual void get_includes (std::set <GAME::Mga::Atom> & includes);

  /// Base class connection for this object.
  std::set <GAME::Mga::Atom> base_classes_;

  /// Parent elements for this model element.
  std::set <GAME::Mga::Atom> parents_;
  std::set <GAME::Mga::Atom> base_parents_;

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
  void get_parents (GAME::Mga::FCO_in, std::set <GAME::Mga::Atom> & parents);

  // Helper function that generates the elements factory method.
  void generate_factory_method (const Generation_Context &, GAME::Mga::Atom_in);
};

#if defined (__GAME_INLINE__)
#include "Object_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _GAME_EXTENSION_CLASSES_OBJECT_CLASS_DEFINITION_H_
