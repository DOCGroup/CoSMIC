//=============================================================================
/**
 * @file      Data_Type_Visitor.h
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_DATA_TYPE_DISPATCHER_H_
#define _PICML_DATA_TYPE_DISPATCHER_H_

#include "Utils/UDM/Abstract_Type_Dispatcher_T.h"
#include "PICML/PICML.h"

/**
 * @class DataType_Dispatcher
 */
class PICML_Data_Type_Dispatcher :
  public UDM_Abstract_Type_Dispatcher_T <PICML::Visitor>
{
public:
  /// Default constructor.
  PICML_Data_Type_Dispatcher (void);
};

#endif
