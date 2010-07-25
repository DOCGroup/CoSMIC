// $Id: $

#include "StringC.h"
#include "ace/Log_Msg.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  ACE_DEBUG ((LM_DEBUG, "*** begin validating constant string values\n"));

  // validate CONST_STRING_PERSON
  if (typeid (const char * const) != typeid (CONST_STRING_PERSON))
    ACE_ERROR ((LM_ERROR, "type of CONST_STRING_PERSON is incorrect\n"));

  if (0 != ACE_OS::strcmp (CONST_STRING_PERSON, "A_PERSON_HAS_A_NAME_HEIGHT_AND_AGE_ATTRIBUTES"))
    ACE_ERROR ((LM_ERROR, "value of CONST_STRING_PERSON is incorrect\n"));

  // validate CONST_STRING_PLACE
  if (typeid (const char * const) != typeid (CONST_STRING_PLACE))
    ACE_ERROR ((LM_ERROR, "type of CONST_STRING_PLACE is incorrect\n"));

  if (0 != ACE_OS::strcmp (CONST_STRING_PLACE, "a place has a name, how many and is real attributes"))
    ACE_ERROR ((LM_ERROR, "value of CONST_STRING_PERSON is incorrect\n"));

  // validate CONST_STRING_THING
  if (typeid (const char * const) != typeid (CONST_STRING_THING))
    ACE_ERROR ((LM_ERROR, "type of CONST_STRING_THING is incorrect\n"));

  if (0 != ACE_OS::strcmp (CONST_STRING_THING, "A ThInG hAs A nAmE aNd NuMbEr Of AtTrIbUtEs"))
    ACE_ERROR ((LM_ERROR, "value of CONST_STRING_THING is incorrect\n"));

  // validate CONST_STRING_EVENT
  if (typeid (const char * const) != typeid (CONST_STRING_EVENT))
    ACE_ERROR ((LM_ERROR, "type of CONST_STRING_EVENT is incorrect\n"));

  if (0 != ACE_OS::strcmp (CONST_STRING_EVENT, "A THING HAS A NAME ID AND TYPE ATTRIBUTES"))
    ACE_ERROR ((LM_ERROR, "value of CONST_STRING_EVENT is incorrect\n"));

  // validate CONST_STRING_IDEA
  if (typeid (const char * const) != typeid (CONST_STRING_IDEA))
    ACE_ERROR ((LM_ERROR, "type of CONST_STRING_IDEA is incorrect\n"));

  if (0 != ACE_OS::strcmp (CONST_STRING_IDEA, "AN_IDEA_HAS_A_NAME_IS_GREAT_ID_AND_BEGIN_LETTER_ATTRIBUTES"))
    ACE_ERROR ((LM_ERROR, "value of CONST_STRING_IDEA is incorrect\n"));

  ACE_DEBUG ((LM_DEBUG, "*** end validating constant string values\n"));

  return 0;
}
