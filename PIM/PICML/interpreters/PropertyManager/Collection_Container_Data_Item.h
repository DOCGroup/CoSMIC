// -*- C++ -*-

//=============================================================================
/**
 * @file      Collection_Container_Data_Item.h
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PROPERTY_MANAGER_COLLECTION_CONTAINER_DATA_ITEM_H_
#define _PROPERTY_MANAGER_COLLECTION_CONTAINER_DATA_ITEM_H_

#include "Container_Data_Item.h"
#include <vector>

// Forward decl.
class Collection_Item;

/**
 * @class Data_Value_Item
 *
 * Data item for a collection of elements (i.e., sequence).
 */
class Collection_Container_Data_Item : public Container_Data_Item
{
public:
  Collection_Container_Data_Item (const GAME::Mga::Model_in item);

  Collection_Item * new_item (void);
  Collection_Item * new_item (GAME::Mga::FCO item);

  size_t get_size (void) const;

  bool move_up (Collection_Item * item);
  bool move_down (Collection_Item * item);

  bool delete_item (Collection_Item * item);

private:
  /// The collection of items.
  std::vector <Collection_Item *> items_;

  GAME::Mga::FCO type_;

  bool is_complex_type_;
};

#endif
