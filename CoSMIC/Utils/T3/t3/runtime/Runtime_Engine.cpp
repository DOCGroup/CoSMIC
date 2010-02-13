// $Id4

#include "Runtime_Engine.h"
#include "boost/bind.hpp"
#include "game/Filter.h"
#include "game/utils/modelgen.h"
#include <algorithm>
#include <functional>
#include <stack>

//
// create_element
//
GME::Object T3_Runtime_Engine::
create_element (GME::Object & parent, const std::string & type)
{
  switch (parent.type ())
  {
  case OBJTYPE_FOLDER:
    return this->create_element (GME::Folder::_narrow (parent), type);

  case OBJTYPE_MODEL:
    return this->create_element (GME::Model::_narrow (parent), type);

  default:
    throw T3::bad_parent (parent);
  }
}

//
// create_element
//
GME::Object T3_Runtime_Engine::
create_element (GME::Folder & parent, const std::string & type)
{
  try
  {
    // Attempt to the get the FCO meta information.
    GME::Meta::FCO meta_fco = parent.meta ().child (type);
    GME::Object object;

    switch (meta_fco.type ())
    {
    case OBJTYPE_ATOM:
      object = GME::Atom::_create (meta_fco, parent);
      break;

    case OBJTYPE_MODEL:
      object = GME::Model::_create (meta_fco, parent);
      break;

    default:
      // Bad choice.
      throw T3::bad_parent (parent);
    }

    if (this->listener_ != 0)
      this->listener_->handle_new_object (object);

    return object;
  }
  catch (const GME::Exception &)
  {
    // Since we failed to locate the FCO meta information,
    // this must be a folder type.
    GME::Meta::Folder meta_folder = parent.meta ().folder (type);
    return GME::Folder::_create (meta_folder, parent);
  }
}

//
// create_element
//
GME::Object T3_Runtime_Engine::
create_element (GME::Model & parent, const std::string & type)
{
  GME::Object object;

  GME::Meta::Role role = parent.meta ().role (type);
  int obj_type = role.kind ().type ();

  switch (obj_type)
  {
  case OBJTYPE_ATOM:
    object = GME::Atom::_create (role, parent);
    break;

  case OBJTYPE_MODEL:
    object = GME::Model::_create (role, parent);
    break;

  case OBJTYPE_REFERENCE:
    object = GME::Reference::_create (role, parent);
    break;

  case OBJTYPE_SET:
    object = GME::Set::_create (role, parent);
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
set_attribute (GME::FCO & fco, const std::string & name, const std::string & value)
{
  if (name == "name")
    fco.name (value);
  else
    fco.attribute (name).string_value (value);
}

/**
 * @struct set_attr_boolean
 *
 * Functor for setting a boolean attribute.
 */
struct set_attr_boolean
{
  typedef T3_Runtime_Engine::FLAG_TABLE::CONST_ITERATOR const_iterator;

  set_attr_boolean (GME::FCO & fco)
    : fco_ (fco)
  {

  }

  void operator () (const_iterator::value_type & value) const
  {
    // Locate the attribute and set its boolean value.
    GME::Attribute attr = this->fco_.attribute (value.key ().c_str ());
    attr.bool_value (value.item ());
  }

private:
  GME::FCO & fco_;
};

//
// init_fco
//
void T3_Runtime_Engine::init_fco (GME::FCO & fco)
{
  // Set any outstanding attributes
  std::for_each (this->stored_flags_.begin (),
                 this->stored_flags_.end (),
                 set_attr_boolean (fco));

  // If applicable, set the reference for the object.
  if (this->stored_ref_ && fco.type () == OBJTYPE_REFERENCE)
  {
    // Set the reference for the object.
    GME::Reference ref = GME::Reference::_narrow (fco);
    ref.refers_to (this->stored_ref_);

    // Release the stored reference.
    this->stored_ref_.release ();
  }
}

//
// store_predefined_reference
//
bool T3_Runtime_Engine::
store_predefined_reference (const GME::Object & obj, const char * pt)
{
  // Check our symbol table first.
  if (0 == this->sym_table_.find (pt, this->stored_ref_))
    return true;

  // Create a filter for the project.
  GME::Project project = obj.project ();
  GME::Filter filter (project);

  // Set its properties.
  filter.kind (pt);

  // Apply the filter to the project.
  GME::Collection_T <GME::FCO> result;
  GME::FCO fco;

  if (0 != filter.apply (result))
  {
    // We are going to just take the first one.
    fco = *result.begin ();
  }
  else
  {
    // We need to create the predefined type.
    GME::Folder root_folder = project.root_folder ();
    GME::Folder predefined_types;

    const char * name = "PredefinedTypes";
    if (GAME::create_if_not (root_folder,
                             name,
                             predefined_types,
                             GAME::contains (boost::bind (std::equal_to <std::string> (),
                                             name,
                                             boost::bind (&GME::Folder::name, _1)))))
    {
      predefined_types.name (name);
    }

    // Create the new predefined type.
    fco = GME::Atom::_create (pt, predefined_types);
    fco.name (pt);
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
store_reference (const GME::Object & parent, const std::string & symbol)
{
  return this->resolve (parent, symbol, this->stored_ref_);
}

//
// get_scope
//
void T3_Runtime_Engine::
get_scope (const GME::Object & obj, std::string & scope)
{
  std::stack <GME::Object> scope_stack;
  ::GME::Object parent (obj);

  while (parent.meta ().name () != "File")
  {
    scope_stack.push (parent);
    parent = parent.parent ();
  }

  // Use the stack to generate the fully qualified name of the
  // symbol for this object.
  scope = "::";

  while (!scope_stack.empty ())
  {
    // Write the name of the current level.
    scope += scope_stack.top ().name ();
    scope += "::";

    // Remove the level of the scope.
    scope_stack.pop ();
  }
}

//
// preprocess
//
void T3_Runtime_Engine::
preprocess (GME::Object & parent, const std::string & include_file)
{
  // Remove the extension from the filename.
  size_t npos = include_file.find_last_of ('.');
  std::string basename = include_file.substr (0, npos);

  // Create a filter for the project.
  GME::Filter filter (parent.project ());

  // Locate the File with this name.
  filter.kind ("File");
  filter.name (basename);


  GME::Collection_T <GME::FCO> files;

  if (filter.apply (files))
    this->preprocess_impl (GME::Model::_narrow (*files.begin ()));
}

//
// preprocess_impl
//
void T3_Runtime_Engine::preprocess_impl (GME::Model & model)
{
  // Go through all the packages in the file.
  GME::Collection_T <GME::Model> packages;
  model.children ("Package", packages);

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
    GME::Collection_T <GME::FCO> children;
    model.children (*type, children);

    std::string fq_name;

    for (GME::Collection_T <GME::FCO>::iterator iter = children.begin (),
         iter_end = children.end (); iter != iter_end; ++ iter)
    {
      // Construct the fully qualified name for this element.
      fq_name = scope + iter->name ();

      // Save the element to the symbol table.
      this->sym_table_.bind (fq_name.c_str (), *iter);
    }
  }
}

//
// resolve
//
bool T3_Runtime_Engine::
resolve (const GME::Object & parent, const std::string & symbol, GME::FCO & fco)
{
  // We are using a fully qualified scope.
  if (symbol[0] == ':' && symbol[1] == ':')
    return this->sym_table_.find (symbol.c_str (), fco) == 0 ? true : false;

  std::string fq_name;

  if (parent.meta () == "File")
  {
    fq_name = "::" + symbol;
    return this->sym_table_.find (fq_name.c_str (), fco) == 0 ? true : false;
  }

  GME::Object current (parent);

  while (current.meta ().name () != "Package")
    current = current.parent ();

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
    current = current.parent ();
  } while (current.meta ().name () != "File");

  // We are at the root. Let's give it one last try.
  fq_name = "::" + symbol;
  return this->sym_table_.find (fq_name.c_str (), fco) == 0 ? true : false;
}

/**
 * @struct refers_to
 */
struct refers_to
{
  refers_to (GME::FCO & ref_element)
    : ref_element_ (ref_element)
  {

  }

  bool operator () (const GME::Object & obj) const
  {
    GME::Reference ref = GME::Reference::_narrow (obj);
    return ref.refers_to () == this->ref_element_;
  }

private:
  GME::FCO & ref_element_;
};

//
// create_unique_reference
//
bool T3_Runtime_Engine::
create_unique_reference (GME::Object & parent,
                         const std::string & symbol,
                         const std::string & type)
{
  GME::FCO ref_element;
  return this->create_unique_reference (parent, symbol, type, ref_element);
}

//
// create_unique_reference
//
bool T3_Runtime_Engine::
create_unique_reference (GME::Object & parent,
                         const std::string & symbol,
                         const std::string & type,
                         GME::FCO & ref_element)
{
  if (!T3_RUNTIME_ENGINE->resolve (parent, symbol, ref_element))
    return false;

  // Create the object if the reference does not exist.
  GME::Object object =
    this->create_element_if_not (parent,
                                 type,
                                 refers_to (ref_element));

  // Make sure we have the correct reference.
  GME::Reference ref = GME::Reference::_narrow (object);

  if (ref.refers_to () != ref_element)
    ref.refers_to (ref_element);

  return true;
}

//
// create_connection_to
//
bool T3_Runtime_Engine::
create_connection_to (const GME::Object & src,
                      const std::string & dest,
                      const std::string & type)
{
  GME::FCO dst_fco;

  GME::Model parent = GME::Model::_narrow (src.parent ());

  if (!this->resolve (parent, dest, dst_fco))
    return false;

  GME::FCO src_fco = GME::FCO::_narrow (src);
  GME::Connection::_create (type, parent, src_fco, dst_fco);
  return true;
}
