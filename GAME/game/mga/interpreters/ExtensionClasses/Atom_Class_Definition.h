// -*- C++ -*-

//==============================================================================
/**
 *  @file        Atom_Class_Definition.h
 *
 *  $Id$
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_EXTENSION_CLASSES_ATOM_CLASS_DEFINITION_H_
#define _GAME_EXTENSION_CLASSES_ATOM_CLASS_DEFINITION_H_

#include "FCO_Class_Definition.h"

/**
 * @class Atom_Class_Definition
 *
 * Class definition for an Atom model element.
 */
class Atom_Class_Definition :
  public FCO_Class_Definition
{
public:
  /// Default constructor.
  Atom_Class_Definition (void);

  /// Destructor.
  virtual ~Atom_Class_Definition (void);
};

#if defined (__GAME_INLINE__)
#include "Atom_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _GAME_EXTENSION_CLASSES_ATOM_CLASS_DEFINITION_H_
