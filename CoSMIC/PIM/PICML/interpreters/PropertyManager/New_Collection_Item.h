// -*- C++ -*-

//=============================================================================
/**
 * @file      New_Collection_Item.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PROPERTY_MANAGER_NEW_COLLECTION_ITEM_H_
#define _PROPERTY_MANAGER_NEW_COLLECTION_ITEM_H_

#include <memory>
#include "game/mga/utils/Point.h"
#include "game/mga/FCO.h"
#include "Data_Item.h"

// Forward decl.
class Collection_Container_Data_Item;

/**
 * @class New_Collection_Item
 *
 * Item responsible for adding a new element to a collection.
 */
class New_Collection_Item : public Data_Item
{
public:
  New_Collection_Item (Collection_Container_Data_Item * parent,
                       GAME::Mga::FCO_in type,
                       int indent);

  virtual void get_display_info (std::string & name, std::string & value) const;

  virtual void value_click_begin (CWnd * parent, int item, const CRect & rect);

private:
  /// Pointer the parent container.
  std::auto_ptr <Collection_Container_Data_Item> parent_;

  /// The type for the collection.
  GAME::Mga::FCO type_;

  /// The current indentation.
  int indent_;

  /// The nex index value.
  size_t next_index_;

  /// The last location for the element.
  GAME::Mga::Point last_location_;
};


#endif  // !defined _PROPERTY_MANAGER_NEW_COLLECTION_ITEM_H_
