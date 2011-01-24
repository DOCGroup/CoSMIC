// $Id$

#include "StdAfx.h"
#include "IDL_File_Deserializer.h"
#include "Layout_Manager.h"
#include "t3/runtime/Runtime_Engine.h"
#include <iterator>

//
// IDL_File_Deserializer
//
IDL_File_Deserializer::IDL_File_Deserializer (void)
{

}

//
// ~IDL_File_Deserializer
//
IDL_File_Deserializer::~IDL_File_Deserializer (void)
{

}

//
// deserialize
//
int IDL_File_Deserializer::
deserialize (std::istream & stream, ::GAME::Object_in obj)
{
  // Right now, we are going to copy the contents to a string
  // and process it from there. Later version will work directly
  // on the stream once we figure out why things are not working!!
  std::string storage;
  stream.unsetf (std::ios::skipws); // No white space skipping!

  std::copy (std::istream_iterator <char> (stream),
             std::istream_iterator <char> (),
             std::back_inserter (storage));

  stream.setf (std::ios::skipws);

  std::string::const_iterator begin = storage.begin ();
  std::string::const_iterator end = storage.end ();

  // Setup the event listener.
  Layout_Manager layout_manager;
  T3_RUNTIME_ENGINE->event_listener (&layout_manager);
  T3_RUNTIME_ENGINE->symbols ().unbind_all ();

  bool retval = this->parser_.parse (begin, end, obj);

  // Remove the current event listener.
  T3_RUNTIME_ENGINE->event_listener (0);

  return retval ? 0 : -1;
}
