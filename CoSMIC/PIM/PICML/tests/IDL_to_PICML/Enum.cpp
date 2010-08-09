#include "EnumC.h"
#include "ace/Log_Msg.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  using namespace EnumTypes;
  
  Ecolor ec1 = RED;
  Ecolor ec2 = BLUE;
  Ecolor ec3 = GREEN;

  // verify enum
  ACE_DEBUG ((LM_DEBUG, "*** begin validating enum type\n"));

  // verify enum value
  if (ec1 == 0)
    ACE_ERROR ((LM_ERROR, "Value of Enum set incorrectly\n"));

  // verify enum value
  if (ec2 == 1)
    ACE_ERROR ((LM_ERROR, "Value of Enum set incorrectly\n"));

  // verify enum value
  if (ec3 == 2)
    ACE_ERROR ((LM_ERROR, "Value of Enum set incorrectly\n"));

  ACE_DEBUG ((LM_DEBUG, "*** end validating eum type\n"));
  
  return 0;
}