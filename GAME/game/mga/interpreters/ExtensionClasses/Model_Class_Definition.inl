// -*- C++ -*-
// $Id$

//
// Model_Class_Definition
//
GAME_INLINE
Model_Class_Definition::Model_Class_Definition (void)
{

}

//
// ~Model_Class_Definition
//
GAME_INLINE
Model_Class_Definition::~Model_Class_Definition (void)
{

}

//
// insert_single_definition
//
GAME_INLINE
void Model_Class_Definition::
insert_single_definition (Object_Class_Definition * def)
{
  this->single_.insert (def);
  this->source_includes_.insert (def);

  def->insert_parent (this);
}

//
// insert_multiple_definition
//
GAME_INLINE
void Model_Class_Definition::
insert_multiple_definition (Object_Class_Definition * def)
{
  this->multiple_.insert (def);
  this->source_includes_.insert (def);

  def->insert_parent (this);
}

//
// insert_optional_definition
//
GAME_INLINE
void Model_Class_Definition::
insert_optional_definition (Object_Class_Definition * def)
{
  this->optional_.insert (def);
  this->source_includes_.insert (def);

  def->insert_parent (this);
}
