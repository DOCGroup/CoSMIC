// -*- C++ -*-

//=============================================================================
/**
 * @file      Data_Item.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PROPERTY_MANAGER_DATA_ITEM_H_
#define _PROPERTY_MANAGER_DATA_ITEM_H_

#include <string>

/**
 * @class Data_Item
 *
 * Base class for all items in the list view. Using this base
 * abstraction will make it a LOT easier to manage the different
 * element types.
 */
class Data_Item
{
public:
  /// Destructor.
  virtual ~Data_Item (void);

  virtual void get_display_info (std::string & name, std::string & value) const = 0;

  virtual void value_click_begin (CWnd * parent, int item, const CRect & rect);

  virtual void value_click_end (void);

  virtual int get_context_menu (void) const;

  virtual void init_menu_popup (CMenu * menu) const;

protected:
  /// Initailizing constructor.
  Data_Item (void);
};

#endif  // !defined _PROPERTY_MANAGER_DATA_ITEM_H_
