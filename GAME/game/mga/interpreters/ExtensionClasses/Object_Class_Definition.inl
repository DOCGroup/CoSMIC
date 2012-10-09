// -*- C++ -*-
// $Id$

//
// Object_Class_Definition
//
GAME_INLINE
Object_Class_Definition::Object_Class_Definition (void)
: in_root_folder_ (false),
  is_abstract_ (false)
{

}

//
// ~Object_Class_Definition
//
GAME_INLINE
Object_Class_Definition::~Object_Class_Definition (void)
{

}

//
// is_abstract
//
GAME_INLINE
bool Object_Class_Definition::is_abstract (void) const
{
  return this->is_abstract_;
}

//
// name
//
GAME_INLINE
const std::string & Object_Class_Definition::name (void) const
{
  return this->name_;
}

//
// classname
//
GAME_INLINE
const std::string & Object_Class_Definition::classname (void) const
{
  return this->classname_;
}

//
// metaname
//
GAME_INLINE
const std::string & Object_Class_Definition::metaname (void) const
{
  return this->metaname_;
}

//
// compute_path
//
GAME_INLINE
std::string Object_Class_Definition::
compute_path (std::string separator, bool trailing) const
{
  return this->obj_->path (separator, trailing);
}

//
// in_root_folder
//
GAME_INLINE
bool Object_Class_Definition::in_root_folder (void) const
{
  return this->in_root_folder_;
}

//
// get_object
//
GAME_INLINE
GAME::Mga::FCO_in Object_Class_Definition::get_object (void) const
{
  return this->obj_;
}

//
// base_classes
//
GAME_INLINE
const std::set <Object_Class_Definition *> & Object_Class_Definition::base_classes (void) const
{
  return this->base_classes_;
}

//
// derived_classes
//
GAME_INLINE
const std::set <Object_Class_Definition *> & Object_Class_Definition::derived_classes (void) const
{
  return this->derived_classes_;
}

//
// parents
//
GAME_INLINE
const std::set <Object_Class_Definition *> & Object_Class_Definition::parents (void) const
{
  return this->parents_;
}

//
// insert_parent
//
void Object_Class_Definition::insert_parent (Object_Class_Definition * parent)
{
  this->parents_.insert (parent);
  this->source_includes_.insert (parent);
}

//
// insert_dependency
//
GAME_INLINE
void Object_Class_Definition::insert_dependency (Object_Class_Definition * object)
{
  this->source_includes_.insert (object);
}
