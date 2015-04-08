#include "UnionC.h"
#include "ace/Log_Msg.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  using namespace UnionNoun;

  MixedSelection union_idea;
  MixedSelection union_place;
  MixedSelection union_thing;
  MixedSelection union_person;
  MixedSelection union_event;
 
  Idea idea;
  Place place;
  Thing thing;
  Person person;
  Event my_event;
 
  // set discriminators on my unions
  union_idea.an_idea(idea);
  union_place.a_place(place);
  union_thing.a_thing(thing);
  union_person.a_person(person);
  union_event.an_event(my_event);
 
  // verify union
  ACE_DEBUG ((LM_DEBUG, "*** begin validating union type\n"));
 
  // verify union discriminator for Idea
  if (union_idea._d() != E_IDEA)
    ACE_ERROR ((LM_ERROR, "The discriminator for Idea was set incorrectly\n"));
   
  // verify union discriminator for Place
  if (union_place._d() != E_PLACE)
    ACE_ERROR ((LM_ERROR, "The discriminator for Place was set incorrectly\n"));
   
  // verify union discriminator for Thing
  if (union_thing._d() != E_THING)
    ACE_ERROR ((LM_ERROR, "The discriminator for Thing was set incorrectly\n"));
   
  // verify union discriminator for Person
  if (union_person._d() != E_PERSON)
    ACE_ERROR ((LM_ERROR, "The discriminator for Person was set incorrectly\n"));
   
  // verify union discriminator for Event
  if (union_event._d() != E_EVENT)
    ACE_ERROR ((LM_ERROR, "The discriminator for Event was set incorrectly\n"));
   
  ACE_DEBUG ((LM_DEBUG, "*** end validating union type\n"));

  return 0;
}
