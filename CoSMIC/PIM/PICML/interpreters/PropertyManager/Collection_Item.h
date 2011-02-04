// -*- C++ -*-

//=============================================================================
/**
 * @file      Container_Data_Item.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PROPERTY_MANAGER_COLLECTION_ITEM_H_
#define _PROPERTY_MANAGER_COLLECTION_ITEM_H_

#include "Data_Value_Item_Base.h"

// Forward decl.
class Collection_Container_Data_Item;

/**
 * @class Collection_Item
 *
 * Wrapper class for the item in the collection. It also contains
 * a pointer to the real item that should be displayed.
 */
class Collection_Item : public Data_Value_Item_Base
{
  // Friend decl.
  friend class Collection_Container_Data_Item;

public:
  Collection_Item (Collection_Container_Data_Item * parent,
                   Data_Value_Item_Base * item,
                   size_t index);

  virtual ~Collection_Item (void);

  virtual GAME::Mga::FCO get_item (void);

  virtual void get_display_info (std::string & name, std::string & value) const;

  virtual void value_click_begin (CWnd * parent, int item, const CRect & rect);
  virtual void value_click_end (void);

  virtual int get_context_menu (void) const;

  virtual void init_menu_popup (CMenu * popup) const;

  static void swap (Collection_Item * lhs, Collection_Item * rhs);

  size_t get_index (void) const;
  void set_index (size_t i);

  virtual bool is_complex (void) const;

  Collection_Container_Data_Item * parent (void);

private:
  /// Parent container of the collection item.
  Collection_Container_Data_Item * parent_;

  /// Pointer to the real item.
  Data_Value_Item_Base * real_item_;

  /// The current index of the item.
  size_t index_;
};

#endif
