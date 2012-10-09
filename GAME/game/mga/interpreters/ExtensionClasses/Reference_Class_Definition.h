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

  /// Insert a new class definition in the refers to collection.
  void insert_refers_to (Object_Class_Definition * def);

private:
  void generate_refers_to_method (
    const Generation_Context &,
    Object_Class_Definition *);

  /// Collection of element this type references.
  std::set <Object_Class_Definition *> refers_to_;
};

#if defined (__GAME_INLINE__)
#include "Reference_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _GAME_EXTENSION_CLASSES_REFERENCE_CLASS_DEFINITION_H_
