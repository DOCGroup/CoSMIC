#include "ArrayC.h"
#include "ace/Log_Msg.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  using namespace ArrayBasicTypes;

  BooleanArray    boolean_array;
  ShortArray      short_array;
  LongArray       long_array;
  CharArray       char_array;
  FloatArray      float_array;
  DoubleArray     double_array;

  // suppress compiler unreferenced local variable warning
  static_cast<BooleanArray> (boolean_array);
  static_cast<ShortArray> (short_array);
  static_cast<LongArray> (long_array);
  static_cast<CharArray> (char_array);
  static_cast<FloatArray> (float_array);
  static_cast<DoubleArray> (double_array);

  ACE_DEBUG ((LM_DEBUG, "*** begin validating array type\n"));

  // validate boolean_array
  if (typeid (CORBA::Boolean) != typeid (boolean_array))
    ACE_ERROR ((LM_ERROR, "type of boolean_array is incorrect\n"));

  // validate short_array
  if (typeid (CORBA::Short) != typeid (short_array))
    ACE_ERROR ((LM_ERROR, "type of short_array is incorrect\n"));

  // validate long_array
  if (typeid (CORBA::Long) != typeid (long_array))
    ACE_ERROR ((LM_ERROR, "type of long_array is incorrect\n"));

  // validate char_array
  if (typeid (CORBA::Char) != typeid (char_array))
    ACE_ERROR ((LM_ERROR, "type of char_array is incorrect\n"));

  // validate float_array
  if (typeid (CORBA::Float) != typeid (float_array))
    ACE_ERROR ((LM_ERROR, "type of float_array is incorrect\n"));

  // validate double_array
  if (typeid (CORBA::Double) != typeid (double_array))
    ACE_ERROR ((LM_ERROR, "type of float_array is incorrect\n"));

  ACE_DEBUG ((LM_DEBUG, "*** end validating array type\n"));

  return 0;
}
