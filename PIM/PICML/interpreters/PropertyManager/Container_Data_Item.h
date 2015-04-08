// -*- C++ -*-

//=============================================================================
/**
 * @file      Container_Data_Item.h
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_CONTAINER_DATA_ITEM_H_
#define _PICML_MANAGER_CONTAINER_DATA_ITEM_H_

#include "Data_Value_Item_Base.h"
#include "game/mga/Model.h"

/**
 * @class Container_Data_Item
 *
 * Wrapper class for the DataValue element.
 */
class Container_Data_Item : public Data_Value_Item_Base
{
public:
  Container_Data_Item (const GAME::Mga::Model_in item);

  virtual GAME::Mga::FCO get_item (void);
  virtual void get_display_info (std::string & name, std::string & value) const;

  virtual bool is_complex (void) const;

protected:
  GAME::Mga::Model item_;
};

#endif
