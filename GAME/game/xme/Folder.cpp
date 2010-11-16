// $Id$

#include "Folder.h"

#if !defined (__GAME_INLINE__)
#include "Folder.inl"
#endif

#include "GME_ID_Generator.h"
#include "ID_Generator_Repo.h"
#include <sstream>

namespace GAME
{
namespace XME
{
const GAME::Xml::String Folder::TAGNAME ("folder");
const GAME::Xml::String Folder::ATTR_CHILDRELIDCNTR ("childrelidcntr");
const GAME::Xml::String Folder::NO_CHILDREN ("0x0");

//
// _create
//
Folder Folder::_create (Folder parent, const GAME::Xml::String & kind)
{
  // Generate the relative id for the new folder.
  size_t counter = parent.relid_counter ();
  parent.relid_counter (counter + 1);

  // Generate a unique id for the new folder.
  return Folder (parent.ptr (), kind, counter);
}

//
// Folder
//
Folder::Folder (xercesc::DOMElement * folder, bool validate)
: Object (folder, false),
  counter_ (0)
{
  if (validate && !((this->type_ & Object_Type::OT_FOLDER) == Object_Type::OT_FOLDER))
    throw Invalid_Cast ();

  this->initialize_counter ();
}

//
// Folder
//
Folder::
Folder (xercesc::DOMElement * parent,
        const GAME::Xml::String & kind,
        size_t relid)
: Object (parent,
          TAGNAME,
          GAME_XME_ID_GENERATOR_REPO->get (parent)->generate_folder_id (),
          kind,
          relid),
  counter_ (0)
{
  this->obj_->setAttribute (ATTR_CHILDRELIDCNTR, NO_CHILDREN);
}

//
// attach
//
void Folder::attach (xercesc::DOMElement * obj, bool validate)
{
  // Pass control to the base class.
  Object::attach (obj);

  if (validate && !((this->type_ & Object_Type::OT_FOLDER) == Object_Type::OT_FOLDER))
    throw Invalid_Cast ();

  // Initialize the counter variable.
  this->initialize_counter ();
}

//
// relid_counter
//
void Folder::relid_counter (size_t value)
{
  if (value <= this->counter_)
    return;

  // Write the counter to hexadecimal format.
  std::ostringstream xstr;
  xstr << "0x" << std::hex << value;
  this->obj_->setAttribute (ATTR_CHILDRELIDCNTR, GAME::Xml::String (xstr.str ()));

  // Save the counter's value.
  this->counter_ = value;
}

//
// initialize_counter
//
void Folder::initialize_counter (void)
{
  // Get the child relative id counter value.
  const XMLCh * ch = this->obj_->getAttribute (ATTR_CHILDRELIDCNTR);
  const GAME::Xml::String value (ch, false);

  std::istringstream istr (value.to_string ());
  istr >> std::hex >> this->counter_;
}

}
}
