// -*- C++ -*-

//=============================================================================
/**
 * @file      Class_Definition.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_CLASS_DEFINITION_H_
#define _EXTENSION_CLASSES_CLASS_DEFINITION_H_

#include <ostream>
#include "game/mga/FCO.h"

class Generation_Context
{
public:
  Generation_Context (std::ostream & hfile, std::ostream & ifile, std::ostream & sfile)
    : hfile_ (hfile),
      ifile_ (ifile),
      sfile_ (sfile),
      pch_basename_ ("StdAfx"),
      inline_ ("GAME_INLINE"),
      inline_guard_ ("__GAME_INLINE__")
  {

  }

  std::ostream & hfile_;

  std::ostream & ifile_;

  std::ostream & sfile_;

  std::string pch_basename_;

  std::string inline_;

  std::string inline_guard_;

  std::string export_macro_;
  std::string export_filename_;
};

/**
 * @class Class_Definition
 *
 * Base class for all class definitions.
 */
class Class_Definition
{
public:
  /**
   * Create a class definition type for the given FCO. This factory
   * method will allocate the correct class definition based on the
   * metaname of the FCO.
   */
  static Class_Definition * _create (GAME::Mga::FCO_in fco);

  /// Destructor.
  virtual ~Class_Definition (void);

  /// Build the class definition for the object.
  virtual void build (GAME::Mga::FCO_in fco) = 0;

  /**
   * Generate the class definition.
   */
  virtual void generate (const Generation_Context & ctx) = 0;
};

#endif  // !defined _EXTENSION_CLASSES_CLASS_DEFINITION_H_
