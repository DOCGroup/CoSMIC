// -*- C++ -*-

//==============================================================================
/**
 *  @file        FCO_Class_Definition.h
 *
 *  $Id$
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_EXTENSION_CLASSES_FCO_CLASS_DEFINITION_H_
#define _GAME_EXTENSION_CLASSES_FCO_CLASS_DEFINITION_H_

#include "Object_Class_Definition.h"

/**
 * @class FCO_Class_Definition
 *
 * Class definition for a FCO element.
 */
class FCO_Class_Definition : public Object_Class_Definition
{
public:
  /// Default constructor.
  FCO_Class_Definition (void);

  /// Destructor.
  virtual ~FCO_Class_Definition (void);

  /// Build the class definition for the FCO element.
  virtual void build (GAME::Mga::FCO_in fco);

  // Generate the class definition.
  virtual void generate_definition (const Generation_Context & ctx);

private:
  void generate_attribute (const Generation_Context & ctx,
                           GAME::Mga::Atom_in item);

  void generate_connection_point (const Generation_Context & ctx,
                                  std::pair < std::string, FCO_Class_Definition * > & item);

  /// Attribute connections for this object.
  std::set <GAME::Mga::Atom> attributes_;

  /// Source connection points for the element.
  std::set < std::pair <std::string, FCO_Class_Definition *> > src_connpoints_;

  /// Destination connection points for the element.
  std::set < std::pair <std::string, FCO_Class_Definition *> > dst_connpoints_;
};

#if defined (__GAME_INLINE__)
#include "FCO_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _GAME_EXTENSION_CLASSES_FCO_CLASS_DEFINITION_H_
