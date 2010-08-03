// $Id: $

#include "Interface.h"
#include "ace/Log_Msg.h"
#include "ace/Auto_Ptr.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{

  ACE_DEBUG ((LM_DEBUG, "*** begin validating interface declarations\n"));

  try
  {
    ACE_Auto_Ptr <MyJustANoun> noun_;
    
    // test JustANoun members
    noun_->person("me");
    noun_->place("IDL");
    noun_->thing(1000);
    noun_->idea(true);
    noun_->my_event(12);
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "MyJustANoun threw an exception\n"));
  }

  try
  {
    ACE_Auto_Ptr <MyNounWithAttributes> noun_;
    
    // test MyNounWithAttributes members
    noun_->person("me");
    noun_->place("IDL");
    noun_->thing(1000);
    noun_->idea(true);
    noun_->my_event(12);
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "MyNounWithAttributes threw an exception\n"));
  }

  try
  {
    ACE_Auto_Ptr <MyNounWithAttributesAndException> noun_;
    
    // test MyNounWithAttributesAndException members
    noun_->person("me");
    noun_->place(1234);
    noun_->thing(false);
    noun_->idea('I');
    noun_->my_event(12.34);
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "MyNounWithAttributesAndException threw an exception\n"));
  }

  try
  {
    ACE_Auto_Ptr <MyPerson> person_;
    // test MyPerson members
    person_->my_person(true);
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "MyPerson threw an exception\n"));
  }

  try
  {
    ACE_Auto_Ptr <MyPlace> place_;
    // test MyPlace members
    place_->my_place(2000);
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "MyPlace threw an exception\n"));
  }

  try
  {
    ACE_Auto_Ptr <MyThing> thing_;
    // test MyPlace members
    thing_->my_thing(false);
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "MyThing threw an exception\n"));
  }

  try
  {
    ACE_Auto_Ptr <MyIdea> idea_;
    // test MyPlace members
    idea_->my_idea('I');
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "MyIdea threw an exception\n"));
  }

  try
  {
    ACE_Auto_Ptr <MyEvent> event_;
    // test MyEvent members
    event_->my_event(12.34);
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "MyEvent threw an exception\n"));
  }

  try
  {
    ACE_Auto_Ptr <MyForwardDeclarationPlace> place_;
    // test MyForwardDeclarationPlace members
    place_->my_place(123);
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "MyForwardDeclarationPlace threw an exception\n"));
  }

  try
  {
    ACE_Auto_Ptr <MyForwardDeclarationPerson> person_;
    // test MyForwardDeclarationPerson members
    person_->my_person(true);
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "MyForwardDeclarationPerson threw an exception\n"));
  }

  try
  {
    ACE_Auto_Ptr <NounWithOneWayOPIdea> idea_;
    // test NounWithOneWayOPIdea members
    idea_->is_great(true);
    idea_->create_idea();
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "NounWithOneWayOPIdea threw an exception\n"));
  }

  try
  {
    ACE_Auto_Ptr <NounWithOneWayOPEvent> event_;
    // test NounWithOneWayOPEvent members
    ::CORBA::Long my_type = 0;
    event_->get_type(my_type);
    event_->set_type(10);
    event_->create_event();
  }
  catch(...)
  {
      ACE_ERROR ((LM_ERROR, "NounWithOneWayOPEvent threw an exception\n"));
  }

  ACE_DEBUG ((LM_DEBUG, "*** end validating interface declarations\n"));

  return 0;
}
