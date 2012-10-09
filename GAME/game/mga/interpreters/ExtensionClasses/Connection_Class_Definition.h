// -*- C++ -*-

//==============================================================================
/**
 *  @file        Connection_Class_Definition.h
 *
 *  $Id$
 *
 *  @author      James H. Hill
 */
//==============================================================================

#ifndef _GAME_EXTENSION_CLASSES_CONNECTION_CLASS_DEFINITION_H_
#define _GAME_EXTENSION_CLASSES_CONNECTION_CLASS_DEFINITION_H_

#include "FCO_Class_Definition.h"
#include "game/mga/Atom.h"

// Forward decl.
class FCO_Class_Definition;

/**
 * @class Connection_Class_Definition
 *
 * Class definition for a Connection model element.
 */
class Connection_Class_Definition :
  public FCO_Class_Definition
{
public:
  /// Default constructor.
  Connection_Class_Definition (void);

  /// Destructor.
  virtual ~Connection_Class_Definition (void);

  /// Build the class definition for the FCO element.
  virtual void build (GAME::Mga::FCO_in fco);

  // Generate the definition for this model element.
  virtual void generate_definition (const Generation_Context & ctx);

private:
  /// Source model element for the connection.
  FCO_Class_Definition * src_;

  /// Destination model element for the connection.
  FCO_Class_Definition * dst_;
};

#if defined (__GAME_INLINE__)
#include "Connection_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _CONNECTION_CLASS_DEFINITION_H_
