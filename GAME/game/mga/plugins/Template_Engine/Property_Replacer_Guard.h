// -*- C++ -*-

//=============================================================================
/**
 *  @file       Property_Replacer_Guard.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PROPERTY_REPLACER_GUARD_H_
#define _PROPERTY_REPLACER_GUARD_H_

#include "parser/Property_Map.h"
#include <set>
#include <vector>
#include <utility>

#include "game/mga/Project.h"

/**
 * @class Property_Replacer_Guard
 *
 * Guard for replacing properties in a model. When the guard is constructed
 * it will replace the properties with their actual value. When the guard
 * is destroyed, it will restore the model back to its original state.
 */
class Property_Replacer_Guard
{
public:
  /// Initializing constructor.
  Property_Replacer_Guard (GAME::Mga::Project proj,
                           const Property_Map & props,
                           std::set <GAME::Mga::Object> & names,
                           std::vector <GAME::Mga::Attribute> & attrs);

  /// Destructor.
  ~Property_Replacer_Guard (void);

private:
  /// Replace properties in the model.
  void replace_properties (const Property_Map & props,
                           std::set <GAME::Mga::Object> & names,
                           std::vector <GAME::Mga::Attribute> & attrs);

  /// Reset the model back to its original state.
  void reset_model (void);

  /// Target project.
  GAME::Mga::Project proj_;

  /// Reference to the property map.
  const Property_Map & props_;

  typedef std::vector < std::pair <GAME::Mga::Object, std::string> >
    Original_Name_Vector;

  /// Reference to objects that have a property in their name.
  Original_Name_Vector orig_names_;

  /// Reference to attributes that have a property in their value.
  typedef std::vector < std::pair <GAME::Mga::Attribute, std::string> >
    Original_Attribute_Vector;

  Original_Attribute_Vector orig_attrs_;
};

#endif  // !defined _PROPERTY_REPLACER_GUARD_H_
