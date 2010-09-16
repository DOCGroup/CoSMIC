// $Id$

#include "StdAfx.h"
#include "Package_Type_Handler.h"

#if !defined (__GAME_INLINE__)
#include "Package_Type_Handler.inl"
#endif

#include "Scope_Display_Strategy.h"
#include "Validation.h"

#include "game/Attribute.h"
#include "game/Filter.h"
#include "game/Model.h"
#include "game/Project.h"
#include "game/Reference.h"
#include "game/MetaAspect.h"
#include "game/MetaModel.h"
#include "game/utils/Point.h"
#include "game/manip/copy.h"
#include "game/dialogs/Selection_List_Dialog_T.h"
#include "boost/bind.hpp"
#include <algorithm>

namespace PICML
{
namespace MI
{
//
// left_to_right
//
struct left_to_right_t
{
  left_to_right_t (const std::string & aspect)
    : aspect_ (aspect)
  {

  }

  bool operator () (const GAME::FCO & lhs, const GAME::FCO & rhs)
  {
    GAME::utils::Point pt_lhs, pt_rhs;

    GAME::utils::position (this->aspect_, lhs, pt_lhs);
    GAME::utils::position (this->aspect_, rhs, pt_rhs);

    return pt_lhs.x_value () < pt_rhs.x_value ();
  }

private:
  const std::string & aspect_;
};

///////////////////////////////////////////////////////////////////////////////
// validation functors

/**
 * @struct is_invalid_type
 *
 * Functor for determining if an Alias is of a certain type. This
 * should only be used on Alias elements. It does not check if the
 * element is of the specified type if the element is not an Alias.
 */
struct is_invalid_type
{
  is_invalid_type (const std::string & type)
    : type_ (type)
  {

  }

  bool operator () (const GAME::FCO & fco) const
  {
    const std::string metaname (fco.meta ().name ());

    if (metaname == "Alias")
      return this->check_alias (GAME::Reference::_narrow (fco));

    return is_in_template_module (fco) || metaname != this->type_;
  }

private:
  inline bool check_alias (const GAME::Reference & ref) const
  {
    return (*this) (ref.refers_to ());
  }

  /// The type to validate against.
  const std::string & type_;
};

/**
 * @struct is_invalid_collection_type
 */
struct is_invalid_collection_type
{
  is_invalid_collection_type (const GAME::FCO & type)
    : type_ (type)
  {

  }

  bool operator () (const GAME::FCO & fco) const
  {
    const std::string metaname (fco.meta ().name ());

    if (metaname == "Alias")
      return this->check_collection_alias (fco);

    // Make sure this is a collection element. Otherwise, there
    // is not need to continue.
    if (metaname != "Collection")
      return true;

    GAME::Reference collection = GAME::Reference::_narrow (fco);
    GAME::FCO type = collection.refers_to ();

    while (type.meta ().name () == "Alias")
      type = GAME::Reference::_narrow (type).refers_to ();

    return is_in_template_module (type) || this->type_ != type;
  }

private:
  inline bool check_collection_alias (const GAME::FCO & fco) const
  {
    GAME::Reference alias = GAME::Reference::_narrow (fco);
    return (*this) (alias.refers_to ());
  }

  const GAME::FCO & type_;
};

///////////////////////////////////////////////////////////////////////////////
// class methods

//
// handle_object_relation
//
int Package_Type_Handler::handle_object_relation (GAME::Object obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Reference package_type = GAME::Reference::_narrow (obj);
  GAME::FCO fco = package_type.refers_to ();
  GAME::Model tpi = GAME::Model::_narrow (obj.parent ());

  if (fco.is_nil ())
  {
    // We need to delete the instantiate template package.
  }
  else
  {
    // Get the template parameters for the template package.
    GAME::Model template_package = GAME::Model::_narrow (fco);
    static const std::string aspect_TemplateParameters ("TemplateParameters");
    GAME::Meta::Aspect aspect = template_package.meta ().aspect (aspect_TemplateParameters);

    std::vector <GAME::FCO> parameters;
    template_package.children (aspect, parameters);

    // Sort the children from left to right.
    std::sort (parameters.begin (),
               parameters.end (),
               left_to_right_t (aspect_TemplateParameters));

    // Select a concrete type for each template parameter.
    template_map_t mapping;

    std::for_each (parameters.begin (),
                   parameters.end (),
                   boost::bind (&Package_Type_Handler::select_template_parameter,
                                this,
                                tpi,
                                _1,
                                boost::ref (mapping)));

    // Instantiate the template package if we have gathered all the
    // required template parameters.
    if (parameters.size () == mapping.size ())
      this->instantiate_template_package (template_package,
                                          tpi,
                                          mapping);
  }

  return 0;
}

//
// select_template_parameter
//
bool Package_Type_Handler::
select_template_parameter (GAME::Model parent,
                           GAME::FCO fco,
                           template_map_t & mapping)
{
  const std::string metaname = fco.meta ().name ();

  if (metaname == "TypeParameter")
    return this->select_type_parameter (parent, fco, mapping);
  else if (metaname == "NameParameter")
    return this->select_name_parameter (parent, fco, mapping);
  else if (metaname == "CollectionParameter")
    return this->select_collection_parameter (parent, fco, mapping);
  else
    return false;
}

//
// select_type_parameter
//
bool Package_Type_Handler::
select_type_parameter (GAME::Model parent,
                       GAME::FCO fco,
                       template_map_t & mapping)
{
  // This is a restricted parameter type. The value of the Type
  // attribute will determine what elements are valid for this
  // template parameter. We also need to check all the Alias
  // elements since they may reference a valid choice.
  const std::string type = fco.attribute ("Type").string_value ();
  const std::string kind = type + " Alias";

  GAME::Filter filter (fco.project ());
  filter.kind (kind);

  std::vector <GAME::FCO> elements;
  filter.apply (elements);

  // Remove all alias elements that are not the correct type.
  std::vector <GAME::FCO>::const_iterator iter = elements.begin ();
  std::vector <GAME::FCO>::const_iterator iter_end =
    std::remove_if (elements.begin (),
                    elements.end (),
                    is_invalid_type (type));

  // Determine how many items are in the final collection.
  size_t count = std::distance (iter, iter_end);

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
  GAME::FCO selection;

  switch (count)
  {
  case 0:
    {
      std::string msg = "Project does not contain any " + type + " model elements.";
      ::AfxMessageBox (msg.c_str (), MB_ICONERROR);
    }
    return false;

  case 1:
    selection = elements.front ();
    break;

  default:
    {
      using GAME::Dialogs::Selection_List_Dialog_T;

      // Display a dialog to user to select desired element.
      Scope_Display_Strategy display;
      Selection_List_Dialog_T <GAME::FCO> dialog (&display, ::AfxGetMainWnd ());

      dialog.insert (iter, iter_end);
      dialog.title ("Template Parameter Selector");

      const std::string directions =
        "Select model element for typed template parameter\r\n" +
        fco.name () + ":";

      dialog.directions (directions.c_str ());

      if (dialog.DoModal () == IDCANCEL)
        return false;

      selection = dialog.selection ();
    }
  }

  // Create a template parameter value for this element.
  this->create_template_value_parameter (parent,
                                         fco,
                                         selection,
                                         mapping);
  return true;
}

//
// select_name_parameter
//
bool Package_Type_Handler::
select_name_parameter (GAME::Model parent,
                       GAME::FCO fco,
                       template_map_t & mapping)
{
  // The value of this parameter can be anything! So, we just need to
  // select all the elements in each file and display them.
  static const std::string kind =
    "Aggregate Alias Collection Component ComponentFactory Connector "
    "Constant Enum Event Exception NativeValue Object PortType "
    "SwitchedAggregate ValueObject";

  GAME::Filter filter (fco.project ());
  filter.kind (kind);

  std::vector <GAME::FCO> elements;
  size_t count = filter.apply (elements);

  // Remove all alias elements that are not the correct type.
  std::vector <GAME::FCO>::const_iterator iter = elements.begin ();
  std::vector <GAME::FCO>::const_iterator iter_end;
    std::remove_if (elements.begin (),
                    elements.end (),
                    &is_in_template_module);

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
  GAME::FCO selection;

  switch (count)
  {
  case 0:
    {
      std::string msg = "Project does not contain any valid parameter value types.";
      ::AfxMessageBox (msg.c_str (), MB_ICONERROR);
    }
    return false;

  case 1:
    selection = elements.front ();
    break;

  default:
    {
      using GAME::Dialogs::Selection_List_Dialog_T;

      // Display a dialog to user to select desired element.
      Scope_Display_Strategy display;
      Selection_List_Dialog_T <GAME::FCO> dialog (&display, ::AfxGetMainWnd ());

      dialog.insert (elements);
      dialog.title ("Template Parameter Selector");

      const std::string directions =
        "Select model element for named template parameter\r\n" +
        fco.name () + ":";

      dialog.directions (directions.c_str ());

      if (dialog.DoModal () == IDCANCEL)
        return false;

      selection = dialog.selection ();
    }
  }

  // Create a template parameter value for this element.
  this->create_template_value_parameter (parent,
                                         fco,
                                         selection,
                                         mapping);

  return true;
}

//
// select_collection_parameter
//
bool Package_Type_Handler::
select_collection_parameter (GAME::Model parent,
                             GAME::FCO fco,
                             template_map_t & mapping)
{
  // This parameter is a reference to a previous template
  // parameter. This means, we need to find all the elements
  // that are collections of the referenced type.
  GAME::Reference ref = GAME::Reference::_narrow (fco);
  GAME::FCO param = ref.refers_to ();

  // Now, locate this parameter in the mapping. It will let
  // us know what concrete element we need to search for.
  template_map_t::const_iterator result = mapping.find (param);
  if (result == mapping.end ())
    return false;

  // Get the type that the mapped template parameter value is
  // referencing in the model.
  GAME::Reference tpv = GAME::Reference::_narrow (result->second);
  GAME::FCO type = tpv.refers_to ();

  // Now, locate all collection (or sequence) element in model.
  GAME::Filter filter (fco.project ());
  filter.kind ("Collection Alias");

  std::vector <GAME::FCO> elements;
  filter.apply (elements);

  // Remove all sequences that are not of the identified type.
  std::vector <GAME::FCO>::const_iterator iter = elements.begin ();
  std::vector <GAME::FCO>::const_iterator iter_end =
    std::remove_if (elements.begin (),
                    elements.end (),
                    is_invalid_collection_type (type));

  size_t count = std::distance (iter, iter_end);

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
  GAME::FCO selection;

  switch (count)
  {
  case 0:
    {
      const std::string msg =
        "Project does not contain any sequence <" +
        type.name () + "> model elements.";

      ::AfxMessageBox (msg.c_str (), MB_ICONERROR);
    }
    return false;

  case 1:
    selection = elements.front ();
    break;

  default:
    {
      using GAME::Dialogs::Selection_List_Dialog_T;

      // Display a dialog to user to select desired element.
      Scope_Display_Strategy display;
      Selection_List_Dialog_T <GAME::FCO> dialog (&display, ::AfxGetMainWnd ());

      dialog.insert (iter, iter_end);
      dialog.title ("Template Parameter Selector");

      std::string directions =
        "Select model element for template parameter\r\nsequence <" +
        fco.name () + ">:";

      dialog.directions (directions.c_str ());

      if (dialog.DoModal () == IDCANCEL)
        return false;

      selection = dialog.selection ();
    }
  }

  // Create a template parameter value for this element.
  this->create_template_value_parameter (parent,
                                         fco,
                                         selection,
                                         mapping);
  return true;
}

//
// create_template_value_parameter
//
void Package_Type_Handler::
create_template_value_parameter (GAME::Model parent,
                                 GAME::FCO param,
                                 GAME::FCO value,
                                 template_map_t & mapping)
{
  // Create a template parameter value for this element.
  GAME::Reference tpv = GAME::Reference::_create (parent, "TemplateParameterValue");
  tpv.refers_to (value);

  // Set the position of the template parameter.
  GAME::utils::Point pt (100, 100);
  pt.shift (100 + (100 * mapping.size ()), 0);
  GAME::utils::position ("TemplateParameters", pt, tpv);

  // Save the template parameter mapping.
  mapping[param] = tpv;
}

//
// instantiate_template_package
//
void Package_Type_Handler::
instantiate_template_package (const GAME::Model & template_package,
                              GAME::Model tpi,
                              const template_map_t & mapping)
{
  // Copy all the elements to the template package instance.
  GAME::copy (template_package, tpi, "InterfaceDefinition");

  // Replace the template parameters with the concrete types.
  this->substitute_template_parameters (tpi, mapping);
}

//
// substitute_template_parameters
//
void Package_Type_Handler::
substitute_template_parameters (GAME::Model tpi,
                                const template_map_t & mapping)
{
  GAME::Meta::Aspect idl_aspect = tpi.meta ().aspect ("InterfaceDefinition");

  // Locate all the references at this level.
  std::vector <GAME::Reference> refs;

  if (0 != tpi.children (idl_aspect, refs))
    std::for_each (refs.begin (),
                   refs.end (),
                   boost::bind (&Package_Type_Handler::substitute_template_parameter_reference,
                                this,
                                _1,
                                boost::cref (mapping)));

  // Perform the same operation on all the model elements.
  std::vector <GAME::Model> models;

  if (0 != tpi.children (idl_aspect, models))
    std::for_each (models.begin (),
                   models.end (),
                   boost::bind (&Package_Type_Handler::substitute_template_parameters,
                                this,
                                _1,
                                boost::cref (mapping)));
}

//
// substitute_template_parameter
//
void Package_Type_Handler::
substitute_template_parameter_reference (GAME::Reference ref,
                                         const template_map_t & mapping)
{
  // Locate the refered type in the mapping.
  template_map_t::const_iterator result = mapping.find (ref.refers_to ());

  // Set the reference to the concrete type.
  if (result != mapping.end ())
    ref.refers_to (result->second.refers_to ());
}

}

}
