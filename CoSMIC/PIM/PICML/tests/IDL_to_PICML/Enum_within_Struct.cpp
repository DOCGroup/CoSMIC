#include "Enum_within_StructC.h"
#include "ace/Log_Msg.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  using namespace EnumTypes;

  Person p1, p2, p3;

  p1.m_name = "Tester1";
  p1.e = Person::Ecolor::RED;

  p2.m_name = "Tester2";
  p2.e = Person::Ecolor::BLUE;

  p3.m_name = "Tester3";
  p3.e = Person::Ecolor::GREEN;

  // verify enum_within_struct
  ACE_DEBUG ((LM_DEBUG, "*** begin validating enum type within struct\n"));

  // verify string for struct person
  if (p1.m_name != "Tester1")
    ACE_ERROR ((LM_ERROR, "The string value for struct Person was set incorrectly\n"));

  // verify enum for struct person
  if (p1.e != 0)
    ACE_ERROR ((LM_ERROR, "The enum value for struct Person was set incorrectly\n"));

  // verify string for struct person
  if (p2.m_name != "Tester2")
    ACE_ERROR ((LM_ERROR, "The string value for struct Person was set incorrectly\n"));

  // verify enum for struct person
  if (p2.e != 1)
    ACE_ERROR ((LM_ERROR, "The enum value for struct Person was set incorrectly\n"));

  // verify string for struct person
  if (p3.m_name != "Tester3")
    ACE_ERROR ((LM_ERROR, "The string value for struct Person was set incorrectly\n"));

  // verify enum for struct person
  if (p3.e != 2)
    ACE_ERROR ((LM_ERROR, "The enum value for struct Person was set incorrectly\n"));

  ACE_DEBUG ((LM_DEBUG, "*** end validating enum type within struct\n"));

  return 0;
}