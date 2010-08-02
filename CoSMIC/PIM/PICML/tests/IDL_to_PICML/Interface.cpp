// $Id: $

#include "InterfaceC.h"
#include "ace/Log_Msg.h"
#include "ace/Auto_Ptr.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  class myNoun : public JustANoun
  {
    public:
      virtual void person (const char * name){}
      virtual void place (const char * name){}
      virtual void thing (::CORBA::Long number_of){}
      virtual void idea (::CORBA::Boolean is_great){}
      virtual void my_event (::CORBA::Long type){}
  };

  ACE_Auto_Ptr <myNoun> just_a_noun;
  
  ACE_DEBUG ((LM_DEBUG, "*** begin validating interface declarations\n"));
  
  // test JustANoun members
  just_a_noun->person("me");
  just_a_noun->place("IDL");
  just_a_noun->thing(1000);
  just_a_noun->idea(true);
  just_a_noun->my_event(12);
  
  ACE_DEBUG ((LM_DEBUG, "*** end validating interface declarations\n"));
  
  return 0;
}
