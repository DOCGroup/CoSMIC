// -*- C++ -*-

//=============================================================================
/**
 * @file      Data_Value_Item.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_DATA_VALUE_ITEM_H_
#define _PICML_MANAGER_DATA_VALUE_ITEM_H_

#include "Data_Value_Item_Base.h"

// Forward decl.
class PICML_Data_Value_Control;

/**
 * @class Data_Value_Item
 *
 * Wrapper class for the DataValue element.
 */
class Data_Value_Item : public Data_Value_Item_Base
{
public:
  /// Initalizing constructor.
  Data_Value_Item (const GAME::FCO & item);

  virtual GAME::FCO get_item (void) const;
  virtual void get_display_info (std::string & name, std::string & value) const;

  virtual void value_click_begin (CWnd * parent, int item, const CRect & rect);
  virtual void value_click_end (void);

  virtual bool is_complex (void) const;

private:
  /// The actual item.
  GAME::FCO item_;

  /// The control for editing the value.
  PICML_Data_Value_Control * control_;
};

#endif  // !defined _PICML_MANAGER_DATA_VALUE_ITEM_H_
