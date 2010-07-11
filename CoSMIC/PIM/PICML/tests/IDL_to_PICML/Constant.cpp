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

  // validate CONST_STRING
  if (typeid (const char * const) != typeid (CONST_STRING))
    ACE_ERROR ((LM_ERROR, "type of CONST_STRING is incorrect\n"));

  if (0 != ACE_OS::strcmp (CONST_STRING, "IDL_TO_PICML"))
    ACE_ERROR ((LM_ERROR, "value of CONST_STRING is incorrect\n"));

  ACE_DEBUG ((LM_DEBUG, "*** end validating constant values\n"));

  return 0;
}
