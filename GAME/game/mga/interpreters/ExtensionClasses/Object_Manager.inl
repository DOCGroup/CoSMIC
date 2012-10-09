// -*- C++ -*-
// $Id: generate_cpp_class.py 3679 2012-04-30 02:25:20Z hillj $


//
// Object_Manager
//
GAME_INLINE
Object_Manager::Object_Manager (void)
{

}

//
// ~Object_Manager
//
GAME_INLINE
Object_Manager::~Object_Manager (void)
{

}

//
// objects
//
GAME_INLINE
const Object_Manager::map_type & Object_Manager::objects (void) const
{
  return this->objects_;
}
