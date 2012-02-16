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

#ifndef _EXTENSION_CLASS_CLASS_DEFINITION_H_
#define _EXTENSION_CLASS_CLASS_DEFINITION_H_

#include "game/mga/Atom.h"
#include "game/mga/Reference.h"
#include "game/mga/Connection.h"
#include "game/mga/Visitor.h"

#include <set>

/**
 * @class Class_Definition
 *
 * Base class for all class definitions.
 */
class Class_Definition : public GAME::Mga::Visitor
{
public:
  void build (GAME::Mga::FCO_in fco);

  /// Base class for the definition.
  std::set <GAME::Mga::Atom> base_classes_;

  std::vector <GAME::Mga::Connection> src_to_connector_;

  std::vector <GAME::Mga::Connection> connector_to_dst_;

  std::vector <GAME::Mga::Connection> containment_;
  std::vector <GAME::Mga::Connection> folder_containment_;

  std::vector <GAME::Mga::Connection> refers_to_;

  // This should be in the Connection class definition.
  std::vector <GAME::Mga::Connection> association_class_;

  std::vector <GAME::Mga::Connection> has_attributes_;

private:
  /// The FCO class definition.
  GAME::Mga::FCO this_;
};

#endif  // !defined _EXTENSION_CLASS_CLASS_DEFINITION_H_
