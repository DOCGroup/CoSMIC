// $Id4

#include "stdafx.h"
#include "Runtime_Engine.h"

#include "game/mga/Atom.h"
#include "game/mga/Connection.h"
#include "game/mga/Filter.h"
#include "game/mga/Folder.h"
#include "game/mga/Model.h"
#include "game/mga/Reference.h"
#include "game/mga/Set.h"

#include "game/mga/MetaModel.h"
#include "game/mga/modelgen.h"

#include "boost/bind.hpp"

#include <algorithm>
#include <functional>
#include <stack>

//
// create_element
//
GAME::Mga::Object T3_Runtime_Engine::
create_element (GAME::Mga::Object_in parent, const std::string & type)
{
  switch (parent->type ())
  {
  case OBJTYPE_FOLDER:
    return this->create_element (GAME::Mga::Folder::_narrow (parent), type);

  case OBJTYPE_MODEL:
    return this->create_element (GAME::Mga::Model::_narrow (parent), type);

  default:
    throw T3::bad_parent (parent);
  }
}

//
// create_element
//
GAME::Mga::Object T3_Runtime_Engine::
create_element (GAME::Mga::Folder_in parent, const std::string & type)
{
  GAME::Mga::Object object;

  try
  {
    // Attempt to the get the FCO meta information.
    GAME::Mga::Meta::FCO meta_fco = parent->meta ()->child (type);

    switch (meta_fco->type ())
    {
    case OBJTYPE_ATOM:
      object = GAME::Mga::Atom_Impl::_create (parent, meta_fco);
      break;

    case OBJTYPE_MODEL:
      object = GAME::Mga::Model_Impl::_create (parent, meta_fco);
      break;

    default:
      // Bad choice.
      throw T3::bad_parent (parent);
    }

  }
  catch (const GAME::Mga::Exception &)
  {
    // Since we failed to locate the FCO meta information,
    // this must be a folder type.
    GAME::Mga::Meta::Folder meta_folder = parent->meta ()->folder (type);
    object = GAME::Mga::Folder_Impl::_create (parent, meta_folder);
  }

  if (this->listener_ != 0)
    this->listener_->handle_new_object (object);

  return object;
}

//
// create_element
//
GAME::Mga::Object T3_Runtime_Engine::
create_element (GAME::Mga::Model_in parent, const std::string & type)
{
  GAME::Mga::Object object;
  GAME::Mga::Meta::Role role = parent->meta ()->role (type);
  int obj_type = role->kind ()->type ();

  switch (obj_type)
  {
  case OBJTYPE_ATOM:
    object = GAME::Mga::Atom_Impl::_create (parent, role);
    break;

  case OBJTYPE_MODEL:
    object = GAME::Mga::Model_Impl::_create (parent, role);
    break;

  case OBJTYPE_REFERENCE:
    object = GAME::Mga::Reference_Impl::_create (parent, role);
    break;

  case OBJTYPE_SET:
    object = GAME::Mga::Set_Impl::_create (parent, role);
    break;

  default:
    throw T3::bad_parent (parent);
  }

  if (this->listener_ != 0)
    this->listener_->handle_new_object (object);

  return object;
}

//
// set_attribute
//
void T3_Runtime_Engine::
set_attribute (GAME::Mga::FCO_in fco, const std::string & name, const std::string & value)
{
  if (name == "name")
    fco->name (value);
  else
    fco->attribute (name)->string_value (value);
}

/**
 * @struct set_attr_boolean
 *
 * Functor for setting a boolean attribute.
 */
struct set_attr_boolean
{
  typedef T3_Runtime_Engine::FLAG_TABLE::CONST_ITERATOR const_iterator;

  set_attr_boolean (GAME::Mga::FCO_in fco)
    : fco_ (fco)
  {

  }

  void operator () (const_iterator::value_type & value) const
  {
    // Locate the attribute and set its boolean value.
    GAME::Mga::Attribute attr = this->fco_->attribute (value.key ().c_str ());
    attr->bool_value (value.item ());
  }

private:
  GAME::Mga::FCO fco_;
};

//
// init_fco
//
void T3_Runtime_Engine::init_fco (GAME::Mga::FCO_in fco)
{
  // Set any outstanding attributes
  std::for_each (this->stored_flags_.begin (),
                 this->stored_flags_.end (),
                 set_attr_boolean (fco));

  // If applicable, set the reference for the object.
  if (!this->stored_ref_.is_nil () && fco->type () == OBJTYPE_REFERENCE)
  {
    // Set the reference for the object.
    GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (fco);
    ref->refers_to (this->stored_ref_);
  }
}

//
// store_predefined_reference
//
bool T3_Runtime_Engine::
store_predefined_reference (const GAME::Mga::Object_in obj, const char * pt)
{
  using GAME::Mga_t;

  // Check our symbol table first.
  if (0 == this->sym_table_.find (pt, this->stored_ref_))
    return true;

  // Create a filter for the project.
  GAME::Mga::Project project = obj->project ();
  GAME::Mga::Filter filter (project);

  // Set its properties.
  filter.kind (pt);

  // Apply the filter to the project.
  std::vector <GAME::Mga::FCO> result;
  GAME::Mga::FCO fco;

  if (0 != filter.apply (result))
  {
    // We are going to just take the first one.
    fco = *result.begin ();
  }
  else
  {
    // We need to create the predefined type.
    GAME::Mga::Folder root_folder = project.root_folder ();
    GAME::Mga::Folder predefined_types;

    const char * name = "PredefinedTypes";
    if (GAME::create_if_not <Mga_t> (root_folder, name, predefined_types,
        GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                name,
                                boost::bind (&GAME::Mga::Folder_Impl::name,
                                             boost::bind (&GAME::Mga::Folder::get, _1))))))
    {
      predefined_types->name (name);
    }

    // Create the new predefined type.
    fco = GAME::Mga::Atom_Impl::_create (predefined_types, pt);
    fco->name (pt);
  }

  // Store the type for later usage.
  this->sym_table_.bind (pt, fco);
  this->stored_ref_ = fco;
  return true;
}

//
// store_reference
//
bool T3_Runtime_Engine::
store_reference (const GAME::Mga::Object_in parent, const std::string & symbol)
{
  return this->resolve (parent, symbol, this->stored_ref_);
}

//
// get_scope
//
void T3_Runtime_Engine::
get_scope (const GAME::Mga::Object_in obj, std::string & scope)
{
  std::stack <GAME::Mga::Object> scope_stack;
  GAME::Mga::Object parent (obj);

  while (parent->meta ()->name () != "File")
  {
    scope_stack.push (parent);
    parent = parent->parent ();
  }

  // Use the stack to generate the fully qualified name of the
  // symbol for this object.
  scope = "::";

  while (!scope_stack.empty ())
  {
    // Write the name of the current level.
    scope += scope_stack.top ()->name ();
    scope += "::";

    // Remove the level of the scope.
    scope_stack.pop ();
  }
}

//
// preprocess
//
void T3_Runtime_Engine::
preprocess (GAME::Mga::Object_in parent, const std::string & include_file)
{
  // Remove the extension from the filename.
  size_t npos = include_file.find_last_of ('.');
  std::string basename = include_file.substr (0, npos);

  // Create a filter for the project.
  GAME::Mga::Filter filter (parent->project ());

  // Locate the File with this name.
  filter.kind ("File");
  filter.name (basename);


  std::vector <GAME::Mga::FCO> files;

  if (filter.apply (files))
    this->preprocess_impl (GAME::Mga::Model::_narrow (*files.begin ()));
}

//
// preprocess_impl
//
void T3_Runtime_Engine::preprocess_impl (GAME::Mga::Model_in model)
{
  // Go through all the packages in the file.
  std::vector <GAME::Mga::Model> packages;
  model->children ("Package", packages);

  std::for_each (packages.begin (),
                 packages.end (),
                 boost::bind (&T3_Runtime_Engine::preprocess_impl,
                              this,
                              _1));

  // Get the current scope.
  std::string scope;
  this->get_scope (model, scope);

  static const char * named_types [] =
  {
    "Component",
    "Object",
    "Aggregate",
    "SwitchedAggregate",
    "Enum",
    "Exception",
    "Alias",
    "Collection",
    "ComponentFactory",
    "Event",
    "ValueObject",
    0
  };

  for (const char ** type = named_types; *type != 0; ++ type)
  {
    // Add all named type elements to the symbol table.
    std::vector <GAME::Mga::FCO> children;
    model->children (*type, children);

    std::string fq_name;

    for (std::vector <GAME::Mga::FCO>::iterator iter = children.begin (),
         iter_end = children.end (); iter != iter_end; ++ iter)
    {
      // Construct the fully qualified name for this element.
      fq_name = scope + (*iter)->name ();

      // Save the element to the symbol table.
      this->sym_table_.bind (fq_name.c_str (), *iter);
    }
  }
}

//
// resolve
//
bool T3_Runtime_Engine::
resolve (const GAME::Mga::Object_in parent,
         const std::string & symbol,
         GAME::Mga::FCO & fco)
{
  // We are using a fully qualified scope.
  if (symbol[0] == ':' && symbol[1] == ':')
    return this->sym_table_.find (symbol.c_str (), fco) == 0 ? true : false;

  std::string fq_name;

  if (parent->meta ()->name () == "File")
  {
    fq_name = "::" + symbol;
    return this->sym_table_.find (fq_name.c_str (), fco) == 0 ? true : false;
  }

  GAME::Mga::Object current (parent);

  while (current->meta ()->name () != "Package")
    current = current->parent ();

  // We are using a relative scope. We start at the current
  // level and work our way to the root.
  do
  {
    // Get the fully qualified name for the current scope.
    this->get_scope (current, fq_name);
    fq_name += symbol;

    // Search for the symbol.
    if (this->sym_table_.find (fq_name.c_str (), fco) == 0)
      return true;

    // Move up one level.
    current = current->parent ();
  } while (current->meta ()->name () != "File");

  // We are at the root. Let's give it one last try.
  fq_name = "::" + symbol;
  return this->sym_table_.find (fq_name.c_str (), fco) == 0 ? true : false;
}

/**
 * @struct refers_to
 */
struct refers_to
{
  refers_to (GAME::Mga::FCO & ref_element)
    : ref_element_ (ref_element)
  {

  }

  bool operator () (const GAME::Mga::Object_in obj) const
  {
    GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (obj);
    return ref->refers_to () == this->ref_element_;
  }

private:
  GAME::Mga::FCO & ref_element_;
};

//
// create_unique_reference
//
bool T3_Runtime_Engine::
create_unique_reference (GAME::Mga::Object_in parent,
                         const std::string & symbol,
                         const std::string & type)
{
  GAME::Mga::FCO ref_element;
  return this->create_unique_reference (parent, symbol, type, ref_element);
}

//
// create_unique_reference
//
bool T3_Runtime_Engine::
create_unique_reference (GAME::Mga::Object_in parent,
                         const std::string & symbol,
                         const std::string & type,
                         GAME::Mga::FCO & ref_element)
{
  if (!T3_RUNTIME_ENGINE->resolve (parent, symbol, ref_element))
    return false;

  // Create the object if the reference does not exist.
  GAME::Mga::Object object =
    this->create_element_if_not (parent,
                                 type,
                                 refers_to (ref_element));

  // Make sure we have the correct reference.
  GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (object);

  if (ref->refers_to () != ref_element)
    ref->refers_to (ref_element);

  return true;
}

//
// create_connection_to
//
bool T3_Runtime_Engine::
create_connection_to (const GAME::Mga::Object_in src,
                      const std::string & dest,
                      const std::string & type)
{
  GAME::Mga::FCO dst_fco;
  GAME::Mga::Model parent = GAME::Mga::Model::_narrow (src->parent ());

  if (!this->resolve (parent, dest, dst_fco))
    return false;

  GAME::Mga::FCO src_fco = GAME::Mga::FCO::_narrow (src);
  GAME::Mga::Connection_Impl::_create (parent, type, src_fco, dst_fco);
  return true;
}
