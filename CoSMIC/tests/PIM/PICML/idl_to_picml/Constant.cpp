// $Id$

#include "ConstantC.h"
#include "ace/Log_Msg.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  ACE_DEBUG ((LM_DEBUG, "*** begin validating constant values\n"));

  // validate CONST_TRUE
  if (typeid (CORBA::Boolean) != typeid (CONST_TRUE))
    ACE_ERROR ((LM_ERROR, "type of CONST_TRUE is incorrect\n"));

  if (!CONST_TRUE)
    ACE_ERROR ((LM_ERROR, "value of CONST_TRUE is incorrect\n"));

  // validate CONST_FALSE
  if (typeid (CORBA::Boolean) != typeid (CONST_FALSE))
    ACE_ERROR ((LM_ERROR, "type of CONST_FALSE is incorrect\n"));

  if (CONST_FALSE)
    ACE_ERROR ((LM_ERROR, "value of CONST_FALSE is incorrect\n"));

  // validate CONST_SHORT_MIN
  if (typeid (CORBA::Short) != typeid (CONST_SHORT_MIN))
    ACE_ERROR ((LM_ERROR, "type of CONST_SHORT_MIN is incorrect\n"));

  if (CONST_SHORT_MIN != ACE_INT16_MIN)
    ACE_ERROR ((LM_ERROR, "value of CONST_SHORT_MIN is incorrect\n"));

  // validate CONST_SHORT_MAX
  if (typeid (CORBA::Short) != typeid (CONST_SHORT_MAX))
    ACE_ERROR ((LM_ERROR, "type of CONST_SHORT_MAX is incorrect\n"));

  if (CONST_SHORT_MAX != ACE_INT16_MAX)
    ACE_ERROR ((LM_ERROR, "value of CONST_SHORT_MAX is incorrect\n"));

  // validate CONST_UNSIGNED_SHORT_MAX
  if (typeid (CORBA::UShort) != typeid (CONST_UNSIGNED_SHORT_MAX))
    ACE_ERROR ((LM_ERROR, "type of CONST_UNSIGNED_SHORT_MAX is incorrect\n"));

  if (CONST_UNSIGNED_SHORT_MAX != ACE_UINT16_MAX)
    ACE_ERROR ((LM_ERROR, "value of CONST_UNSIGNED_SHORT_MAX is incorrect\n"));

  // validate CONST_LONG_MIN
  if (typeid (CORBA::Long) != typeid (CONST_LONG_MIN))
    ACE_ERROR ((LM_ERROR, "type of CONST_LONG_MIN is incorrect\n"));

  if (CONST_LONG_MIN != ACE_INT32_MIN)
    ACE_ERROR ((LM_ERROR, "value of CONST_LONG_MIN is incorrect\n"));

  // validate CONST_LONG_MAX
  if (typeid (CORBA::Long) != typeid (CONST_LONG_MAX))
    ACE_ERROR ((LM_ERROR, "type of CONST_LONG_MAX is incorrect\n"));

  if (CONST_LONG_MAX != ACE_INT32_MAX)
    ACE_ERROR ((LM_ERROR, "value of CONST_LONG_MAX is incorrect\n"));

  // validate CONST_UNSIGNED_LONG_MAX
  if (typeid (CORBA::ULong) != typeid (CONST_UNSIGNED_LONG_MAX))
    ACE_ERROR ((LM_ERROR, "type of CONST_UNSIGNED_LONG_MAX is incorrect\n"));

  if (CONST_UNSIGNED_LONG_MAX != ACE_UINT32_MAX)
    ACE_ERROR ((LM_ERROR, "value of CONST_UNSIGNED_LONG_MAX is incorrect\n"));

  // validate CONST_LONG_LONG_MIN
  if (typeid (CORBA::LongLong) != typeid (CONST_LONG_LONG_MIN))
    ACE_ERROR ((LM_ERROR, "type of CONST_LONG_LONG_MIN is incorrect\n"));

  if (CONST_LONG_LONG_MIN != ACE_INT64_MIN)
    ACE_ERROR ((LM_ERROR, "value of CONST_LONG_LONG_MIN is incorrect\n"));

  // validate CONST_LONG_LONG_MAX
  if (typeid (CORBA::LongLong) != typeid (CONST_LONG_LONG_MAX))
    ACE_ERROR ((LM_ERROR, "type of CONST_LONG_LONG_MAX is incorrect\n"));

  if (CONST_LONG_LONG_MAX != ACE_INT64_MAX)
    ACE_ERROR ((LM_ERROR, "value of CONST_LONG_LONG_MAX is incorrect\n"));

  // validate CONST_UNSIGNED_LONG_LONG_MAX
  if (typeid (CORBA::ULongLong) != typeid (CONST_UNSIGNED_LONG_LONG_MAX))
    ACE_ERROR ((LM_ERROR, "type of CONST_UNSIGNED_LONG_LONG_MAX is incorrect\n"));

  if (CONST_UNSIGNED_LONG_LONG_MAX != ACE_UINT64_MAX)
    ACE_ERROR ((LM_ERROR, "value of CONST_UNSIGNED_LONG_LONG_MAX is incorrect\n"));

  // validate CONST_FLOAT_MIN
  if (typeid (CORBA::Float) != typeid (CONST_FLOAT_MIN))
    ACE_ERROR ((LM_ERROR, "type of CONST_FLOAT_MIN is incorrect\n"));

  if (CONST_FLOAT_MIN != ACE_FLT_MIN)
    ACE_ERROR ((LM_ERROR, "value of CONST_FLOAT_MIN is incorrect\n"));

  // validate CONST_FLOAT_MAX
  if (typeid (CORBA::Float) != typeid (CONST_FLOAT_MAX))
    ACE_ERROR ((LM_ERROR, "type of CONST_FLOAT_MAX is incorrect\n"));

  if (CONST_FLOAT_MAX != ACE_FLT_MAX)
    ACE_ERROR ((LM_ERROR, "value of CONST_FLOAT_MAX is incorrect\n"));

  // validate CONST_DOUBLE_MIN
  if (typeid (CORBA::Double) != typeid (CONST_DOUBLE_MIN))
    ACE_ERROR ((LM_ERROR, "type of CONST_DOUBLE_MIN is incorrect\n"));

  if (CONST_DOUBLE_MIN != ACE_DBL_MIN)
    ACE_ERROR ((LM_ERROR, "value of CONST_DOUBLE_MIN is incorrect\n"));

  // validate CONST_DOUBLE_MAX
  if (typeid (CORBA::Double) != typeid (ACE_DBL_MAX))
    ACE_ERROR ((LM_ERROR, "type of CONST_DOUBLE_MAX is incorrect\n"));

  if (CONST_DOUBLE_MAX != ACE_DBL_MAX)
    ACE_ERROR ((LM_ERROR, "value of CONST_DOUBLE_MAX is incorrect\n"));

  // validate CONST_CHAR_MIN
  if (typeid (CORBA::Char) != typeid (ACE_CHAR_MIN))
    ACE_ERROR ((LM_ERROR, "type of CONST_CHAR_MIN is incorrect\n"));

  if (CONST_CHAR_MIN != 'a')
    ACE_ERROR ((LM_ERROR, "value of CONST_CHAR_MIN is incorrect\n"));

  // validate CONST_CHAR_MAX
  if (typeid (CORBA::Char) != typeid (ACE_CHAR_MAX))
    ACE_ERROR ((LM_ERROR, "type of CONST_CHAR_MAX is incorrect\n"));

  if (CONST_CHAR_MAX != 'Z')
    ACE_ERROR ((LM_ERROR, "value of CONST_CHAR_MAX is incorrect\n"));

  ACE_DEBUG ((LM_DEBUG, "*** end validating constant values\n"));

  return 0;
}
