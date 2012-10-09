// -*- C++ -*-
// $Id$

//
// Reference_Class_Definition
//
GAME_INLINE
Reference_Class_Definition::Reference_Class_Definition (void)
{

}

//
// ~Reference_Class_Definition
//
GAME_INLINE
Reference_Class_Definition::~Reference_Class_Definition (void)
{

}

//
// insert_refers_to
//
GAME_INLINE
void Reference_Class_Definition::insert_refers_to (Object_Class_Definition * def)
{
  this->refers_to_.insert (def);
  this->source_includes_.insert (def);
}

