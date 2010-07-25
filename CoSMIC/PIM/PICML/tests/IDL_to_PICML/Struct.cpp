// $Id: $

#include "StructC.h"
#include "ace/Log_Msg.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  using namespace StructNoun;

  Person person;
  Place place;
  Thing thing;
  Event my_event;

  ACE_DEBUG ((LM_DEBUG, "*** begin validating struct type\n"));
  // verify address ordering of Person members
  if (static_cast<void*>(&person) != static_cast<void*>(&person.m_name))
    ACE_ERROR ((LM_ERROR, "Order of person m_name member variable mapped incorrectly\n"));
  
  if (static_cast<void*>(&person.m_is_member) < static_cast<void*>(&person.m_name) || static_cast<void*>(&person.m_is_member) > static_cast<void*>(&person.m_age))
    ACE_ERROR ((LM_ERROR, "Order of person m_is_member member variable mapped incorrectly\n"));
 
  if (static_cast<void*>(&person.m_age) < static_cast<void*>(&person.m_name) || static_cast<void*>(&person.m_age) < static_cast<void*>(&person.m_is_member))
    ACE_ERROR ((LM_ERROR, "Order of person m_age member variable mapped incorrectly\n"));
  
  // verify address ordering of Place members
  if (static_cast<void*>(&place) != static_cast<void*>(&place.m_name_of))
    ACE_ERROR ((LM_ERROR, "Order of place m_name_of member variable mapped incorrectly\n"));
    
  if (static_cast<void*>(&place.m_how_many) < static_cast<void*>(&place.m_name_of) || static_cast<void*>(&place.m_how_many) > static_cast<void*>(&place.m_has_more))
    ACE_ERROR ((LM_ERROR, "Order of place m_how_many member variable mapped incorrectly\n"));
    
  if (static_cast<void*>(&place.m_has_more) < static_cast<void*>(&place.m_name_of) || static_cast<void*>(&place.m_has_more) < static_cast<void*>(&place.m_how_many))
    ACE_ERROR ((LM_ERROR, "Order of place m_has_more member variable mapped incorrectly\n"));
  
  // verify address ordering of Thing members
  if (static_cast<void*>(&thing) != static_cast<void*>(&thing.m_name))
    ACE_ERROR ((LM_ERROR, "Order of thing m_name member variable mapped incorrectly\n"));
  
  if (static_cast<void*>(&thing.m_class_of) < static_cast<void*>(&thing.m_name) || static_cast<void*>(&thing.m_class_of) > static_cast<void*>(&thing.m_has_more))
    ACE_ERROR ((LM_ERROR, "Order of thing m_class_of member variable mapped incorrectly\n"));
  
  if (static_cast<void*>(&thing.m_has_more) < static_cast<void*>(&thing.m_name) || static_cast<void*>(&thing.m_has_more) < static_cast<void*>(&thing.m_class_of))
    ACE_ERROR ((LM_ERROR, "Order of thing m_has_more member variable mapped incorrectly\n"));

  // verify address ordering of Event members
  if (static_cast<void*>(&my_event) != static_cast<void*>(&my_event.m_type))
    ACE_ERROR ((LM_ERROR, "Order of my_event m_type member variable mapped incorrectly\n"));
  
  if (static_cast<void*>(&my_event.m_my_double) < static_cast<void*>(&my_event.m_type) || static_cast<void*>(&my_event.m_my_double) > static_cast<void*>(&my_event.m_action))
    ACE_ERROR ((LM_ERROR, "Order of my_event m_my_double member variable mapped incorrectly\n"));
  
  if (static_cast<void*>(&my_event.m_action) < static_cast<void*>(&my_event.m_type) || static_cast<void*>(&my_event.m_action) < static_cast<void*>(&my_event.m_my_double))
    ACE_ERROR ((LM_ERROR, "Order of my_event m_action member variable mapped incorrectly\n"));

  ACE_DEBUG ((LM_DEBUG, "*** end validating struct type\n"));

  return 0;
}
