// $Id: $

#include "ArrayC.h"
#include "ace/Log_Msg.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  using namespace ArrayBasicTypes;

  BooleanArray    boolean_array = {FALSE, TRUE, TRUE, FALSE};
  ShortArray      short_array = {10, 9, 4, 7};
  LongArray       long_array = {1000, 2000, 3000, 4000};
  CharArray       char_array = {-127, 0, 127, -1};
  FloatArray      float_array = {2.0, 5.0, 4.0, 7.0};
  DoubleArray     double_array = {5.555, 1.111, 4.444, 7.777};

  ACE_DEBUG ((LM_DEBUG, "*** begin validating array type\n"));
  
  // validate boolean_array
  if (typeid (CORBA::Boolean) != typeid (boolean_array))
    ACE_ERROR ((LM_ERROR, "type of boolean_array is incorrect\n"));
    
  if (boolean_array[0]!= FALSE || boolean_array[1] != TRUE || boolean_array[2] != TRUE || boolean_array[3] != FALSE)
    ACE_ERROR ((LM_ERROR, "value of boolean_array is incorrect\n"));
    
  // validate short_array
  if (typeid (CORBA::Short) != typeid (short_array))
    ACE_ERROR ((LM_ERROR, "type of short_array is incorrect\n"));
    
  if (short_array[0]!= 10 || short_array[1] != 9 || short_array[2] != 4 || short_array[3] != 7)
    ACE_ERROR ((LM_ERROR, "value of short_array is incorrect\n"));
    
  // validate long_array
  if (typeid (CORBA::Long) != typeid (long_array))
    ACE_ERROR ((LM_ERROR, "type of long_array is incorrect\n"));
    
  if (long_array[0]!= 1000 || long_array[1] != 2000 || long_array[2] != 3000 || long_array[3] != 4000)
    ACE_ERROR ((LM_ERROR, "value of long_array is incorrect\n"));
    
  // validate char_array
  if (typeid (CORBA::Char) != typeid (char_array))
    ACE_ERROR ((LM_ERROR, "type of char_array is incorrect\n"));
    
  if (char_array[0]!= -127 || char_array[1] != 0 || char_array[2] != 127 || char_array[3] != -1)
    ACE_ERROR ((LM_ERROR, "value of char_array is incorrect\n"));
  
  // validate float_array
  if (typeid (CORBA::Float) != typeid (float_array))
    ACE_ERROR ((LM_ERROR, "type of float_array is incorrect\n"));
    
  if (float_array[0]!= 2.0 || float_array[1] != 5.0 || float_array[2] != 4.0 || float_array[3] != 7.0)
    ACE_ERROR ((LM_ERROR, "value of float_array is incorrect\n"));
    
  // validate double_array
  if (typeid (CORBA::Double) != typeid (double_array))
    ACE_ERROR ((LM_ERROR, "type of float_array is incorrect\n"));
    
  if (double_array[0]!= 5.555 || double_array[1] != 1.111 || double_array[2] != 4.444 || double_array[3] != 7.777)
    ACE_ERROR ((LM_ERROR, "value of double_array is incorrect\n"));
  
  ACE_DEBUG ((LM_DEBUG, "*** end validating array type\n"));
  
  return 0;
}
