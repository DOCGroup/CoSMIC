// -*- C++ -*-

//==============================================================================
/**
 *  @file        Reference_Class_Definition.h
 *
 *  $Id$
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_EXTENSION_CLASSES_REFERENCE_CLASS_DEFINITION_H_
#define _GAME_EXTENSION_CLASSES_REFERENCE_CLASS_DEFINITION_H_

#include "FCO_Class_Definition.h"

/**
 * @class Reference_Class_Definition
 *
 * Class definition for the Reference model element.
 */
class Reference_Class_Definition :
  public FCO_Class_Definition
{
public:
  /// Default constructor.
  Reference_Class_Definition (void);

  /// Destructor.
  virtual ~Reference_Class_Definition (void);

  /// Build the class definition.
  virtual void build (GAME::Mga::FCO_in fco);

  // Generate the class definition.
  virtual void generate_definition (const Generation_Context & ctx);

protected:
  /// Get the include objects for this class definition. The include
  /// statement for these model elements will appear in the source
  /// file.
  virtual void get_includes (std::set <GAME::Mga::Atom> & includes);

private:
  void generate_refers_to_method (const Generation_Context &, GAME::Mga::Atom_in);

  /// Collection of element this type references.
  std::set <GAME::Mga::Atom> refers_to_;
};

#if defined (__GAME_INLINE__)
#include "Reference_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _GAME_EXTENSION_CLASSES_REFERENCE_CLASS_DEFINITION_H_
