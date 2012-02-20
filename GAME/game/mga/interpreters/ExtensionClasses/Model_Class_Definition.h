// -*- C++ -*-

//==============================================================================
/**
 *  @file        Model_Class_Definition.h
 *
 *  $Id$
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_EXTENSION_CLASSES_MODEL_CLASS_DEFINITION_H_
#define _GAME_EXTENSION_CLASSES_MODEL_CLASS_DEFINITION_H_

#include "FCO_Class_Definition.h"

/**
 * @class Model_Class_Definition
 *
 * INSERT CLASS DESCRIPTION HERE
 */
class Model_Class_Definition :
  public FCO_Class_Definition
{
public:
  /// Default constructor.
  Model_Class_Definition (void);

  /// Destructor.
  virtual ~Model_Class_Definition (void);

  /// Build the class definition for the FCO element.
  virtual void build (GAME::Mga::FCO_in fco);

  // Generate the definition for this model element.
  virtual void generate_definition (const Generation_Context &);

protected:
  /// Get the include objects for this class definition. The include
  /// statement for these model elements will appear in the source
  /// file.
  virtual void get_includes (std::set <GAME::Mga::Atom> & includes);

private:
  // Generate method for an optional containment element.
  void generate_optional_definition (const Generation_Context & ,
                                     GAME::Mga::Atom_in);

  // Generate method for an single containment element.
  void generate_single_definition (const Generation_Context & ctx,
                                   GAME::Mga::Atom_in item);

  // Generate method for an multiple containment element.
  void generate_multiple_definition (const Generation_Context & ctx,
                                     GAME::Mga::Atom_in item);

  /// Collection of multiple child elements.
  std::set <GAME::Mga::Atom> multiple_;

  /// Collection of single child elements.
  std::set <GAME::Mga::Atom> single_;

  /// Collection of optional child elements
  std::set <GAME::Mga::Atom> optional_;
};

#if defined (__GAME_INLINE__)
#include "Model_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _GAME_EXTENSION_CLASSES_MODEL_CLASS_DEFINITION_H_
