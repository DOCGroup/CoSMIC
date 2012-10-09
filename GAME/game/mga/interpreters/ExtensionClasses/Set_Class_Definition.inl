// -*- C++ -*-
// $Id$

//
// Set_Class_Definition
//
GAME_INLINE
Set_Class_Definition::Set_Class_Definition (void)
{

}

//
// ~Set_Class_Definition
//
GAME_INLINE
Set_Class_Definition::~Set_Class_Definition (void)
{

}

//
// insert_member
//
GAME_INLINE
void Set_Class_Definition::insert_member (Object_Class_Definition * member)
{
  this->members_.insert (member);
  this->source_includes_.insert (member);
}
