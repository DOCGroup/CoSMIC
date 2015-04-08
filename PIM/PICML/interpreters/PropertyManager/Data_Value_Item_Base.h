// -*- C++ -*-

//=============================================================================
/**
 * @file      Data_Value_Item_Base.h
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PROPERTY_MANAGER_DATA_VALUE_BASE_H_
#define _PROPERTY_MANAGER_DATA_VALUE_BASE_H_

#include "Data_Item.h"
#include "game/mga/FCO.h"

/**
 * @class Data_Value_Item
 *
 * Wrapper class for the DataValue element.
 */
class Data_Value_Item_Base : public Data_Item
{
public:
  virtual GAME::Mga::FCO get_item (void) = 0;

  virtual bool is_complex (void) const = 0;

};

#endif  // !defined _PROPERTY_MANAGER_DATA_VALUE_BASE_H_
