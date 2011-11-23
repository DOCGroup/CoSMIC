// -*- C++ -*-

//=============================================================================
/**
 * @file        Property_Locator.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CUTE_PROPERTY_LOCATOR_H_
#define _CUTS_CUTE_PROPERTY_LOCATOR_H_

#include "game/mga/FCO.h"
#include "game/mga/Visitor.h"
#include "parser/Property_Listing.hpp"

/**
 * @class Property_Locator
 *
 * Visitor that locates properties in a model. This visitor will traverse
 * the entire model from where it is started. All elements that contain
 * a property are stored internally, and can be retrieved later.
 */
class Property_Locator : public GAME::Mga::Visitor
{
public:
  /**
   * Initializing constructor.
   */
  Property_Locator (const Property_Tag_Config & config);

  /// Destructor.
  virtual ~Property_Locator (void);

  /// Visit a RootFolder object.
  virtual void visit_RootFolder (GAME::Mga::RootFolder_in);

  /// Visit a Folder object.
  virtual void visit_Folder (GAME::Mga::Folder_in folder);

  /// Visit a Model object.
  virtual void visit_Model (GAME::Mga::Model_in model);

  /// Reset the locator.
  void reset (void);

  /// Get the objects that have properties as names.
  std::set <GAME::Mga::Object> & names (void);

  /// Get the attributes have have embedded properties.
  std::vector <GAME::Mga::Attribute> & attributes (void);

private:
  /// Configuration for the locator.
  const Property_Tag_Config & config_;

  /// Visit an FCO object.
  void visit_FCO (GAME::Mga::FCO_in fco);

  /// Visit an attribute.
  void visit_Attribute (GAME::Mga::Attribute_in attr);

  /// Check if the name has an attribute.
  void check_name (GAME::Mga::Object_in obj);

  /// Collection of FCO objects that have names as properties.
  std::set <GAME::Mga::Object> names_;

  /// Collection of attributes with properties.
  std::vector <GAME::Mga::Attribute> attrs_;
};

#if defined (__GAME_INLINE__)
#include "Property_Locator.inl"
#endif

#endif  // !defined _CUTS_CUTE_PROPERTY_LOCATOR_H_
