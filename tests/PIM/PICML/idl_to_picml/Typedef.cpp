// $Id$

#include "TypedefC.h"
#include "ace/Log_Msg.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  using namespace Noun;
  
  // verify union
  ACE_DEBUG ((LM_DEBUG, "*** begin validating typedef\n"));
  
  // validate personArray
  if (typeid (Person) != typeid (personArray))
    ACE_ERROR ((LM_ERROR, "type of personArray is incorrect\n"));
    
  // validate placeArray
  if (typeid (Place) != typeid (placeArray))
    ACE_ERROR ((LM_ERROR, "type of placeArray is incorrect\n"));
    
    // validate thingArray
  if (typeid (Thing) != typeid (thingArray))
    ACE_ERROR ((LM_ERROR, "type of thingArray is incorrect\n"));
    
  // validate eventArray
  if (typeid (Event) != typeid (eventArray))
    ACE_ERROR ((LM_ERROR, "type of eventArray is incorrect\n"));
    
  // validate ideaArray
  if (typeid (Idea) != typeid (ideaArray))
    ACE_ERROR ((LM_ERROR, "type of ideaArray is incorrect\n"));
    
  // validate personArray
  if (typeid (emptyNoun) != typeid (emptyNounArray))
    ACE_ERROR ((LM_ERROR, "type of emptyNounArray is incorrect\n"));
    
  // validate longArray
  if (typeid (::CORBA::Long) != typeid (longArray))
    ACE_ERROR ((LM_ERROR, "type of longArray is incorrect\n"));
  
  // validate shortArray
  if (typeid (::CORBA::Short) != typeid (shortArray))
    ACE_ERROR ((LM_ERROR, "type of shortArray is incorrect\n"));
  
  // validate doubleArray
  if (typeid (::CORBA::Double) != typeid (doubleArray))
    ACE_ERROR ((LM_ERROR, "type of doubleArray is incorrect\n"));
    
  // validate floatArray
  if (typeid (::CORBA::Float) != typeid (floatArray))
    ACE_ERROR ((LM_ERROR, "type of floatArray is incorrect\n"));
  
  // validate booleanArray
  if (typeid (::CORBA::Boolean) != typeid (booleanArray))
    ACE_ERROR ((LM_ERROR, "type of booleanArray is incorrect\n"));
    
  // validate charArray
  if (typeid (::CORBA::Char) != typeid (charArray))
    ACE_ERROR ((LM_ERROR, "type of charArray is incorrect\n"));

  ACE_DEBUG ((LM_DEBUG, "*** end validating typedef\n"));

  return 0;
}
