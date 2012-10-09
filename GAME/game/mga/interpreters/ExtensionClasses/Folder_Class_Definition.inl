// -*- C++ -*-
// $Id$

//
// Folder_Class_Definition
//
GAME_INLINE
Folder_Class_Definition::Folder_Class_Definition (void)
{

}

//
// ~Folder_Class_Definition
//
GAME_INLINE
Folder_Class_Definition::~Folder_Class_Definition (void)
{

}

//
// insert_child
//
GAME_INLINE
void Folder_Class_Definition::insert_child (Object_Class_Definition * child)
{
  this->children_.insert (child);
  this->source_includes_.insert (child);
}

