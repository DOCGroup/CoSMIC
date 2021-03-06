#include "Project_Generator.h"
#include "File_Creator.h"

#include "ast_argument.h"
#include "ast_array.h"
#include "ast_attribute.h"
#include "ast_component_fwd.h"
#include "ast_provides.h"
#include "ast_uses.h"
#include "ast_publishes.h"
#include "ast_emits.h"
#include "ast_consumes.h"
#include "ast_enum.h"
#include "ast_enum_val.h"
#include "ast_eventtype.h"
#include "ast_eventtype_fwd.h"
#include "ast_exception.h"
#include "ast_finder.h"
#include "ast_field.h"
#include "ast_home.h"
#include "ast_native.h"
#include "ast_operation.h"
#include "ast_root.h"
#include "ast_sequence.h"
#include "ast_structure_fwd.h"
#include "ast_typedef.h"
#include "ast_union.h"
#include "ast_union_branch.h"
#include "ast_union_fwd.h"
#include "ast_union_label.h"
#include "ast_valuebox.h"
#include "ast_valuetype_fwd.h"

#include "ast_porttype.h"
#include "ast_connector.h"
#include "ast_mirror_port.h"
#include "ast_extended_port.h"
#include "ast_template_module.h"
#include "ast_template_module_inst.h"
#include "ast_template_module_ref.h"
#include "ast_param_holder.h"

#include "utl_exceptlist.h"
#include "utl_identifier.h"
#include "utl_idlist.h"
#include "utl_string.h"
#include "utl_strlist.h"
#include "utl_labellist.h"

#include "fe_utils.h"

#include "global_extern.h"
#include "nr_extern.h"
#include "fe_extern.h"
#include "be_extern.h"

#include "game/xme/Project.h"
#include "game/xme/Connection.h"
#include "game/xme/functional.h"
#include "game/xme/modelgen.h"

#include "ace/OS_NS_stdio.h"

#include "boost/bind.hpp"
#include <functional>
#include <sstream>
#include <iostream>

namespace constant
{
namespace meta
{
  static const GAME::Xml::String PREDEFINED_TYPES ("PredefinedTypes");
  static const GAME::Xml::String String ("String");
  static const GAME::Xml::String WideString ("WideString");
}

namespace attr
{
  static const GAME::Xml::String abstract ("abstract");
  static const GAME::Xml::String local ("local");
  static const GAME::Xml::String single_destination ("single_destination");
  static const GAME::Xml::String multiple_connections ("multiple_connections");
  static const GAME::Xml::String value ("value");
  static const GAME::Xml::String InterfaceSemantics ("InterfaceSemantics");
}

namespace aspect
{
  static const GAME::Xml::String InterfaceDefinition ("InterfaceDefinition");
  static const GAME::Xml::String TemplateParameters ("TemplateParameters");
}

namespace name
{
  static const GAME::Xml::String PartRegs ("PartRegs");
  static const GAME::Xml::String Position ("Position");
}
}

struct predefined_typeinfo
{
  const char * metaname_;
  AST_PredefinedType::PredefinedType type_id_[4];
};

/**
 * @struct arrange_horizontal
 *
 * Functor that arranges elements horizontally on the screen.
 */
struct arrange_horizontal
{
  arrange_horizontal (const GAME::Xml::String & aspect,
                      int x,
                      int y,
                      int dx)
    : aspect_ (aspect),
      x_ (x),
      y_ (y),
      dx_ (dx)
  {

  }

  void operator () (GAME::XME::FCO fco)
  {
    // Set the position of the element.
    GAME::XME::set_position (fco,
                             this->aspect_,
                             this->x_,
                             this->y_);

    // Advance to the next element.
    this->x_ += this->dx_;
  }

  void operator () (const Template_Parameter_Manager::PARAMETER & param)
  {
    // Set the position of the element.
    GAME::XME::set_position (param.second,
                             this->aspect_,
                             this->x_,
                             this->y_);

    // Advance to the next element.
    this->x_ += this->dx_;
  }

private:
  const GAME::Xml::String & aspect_;

  int x_;

  const int y_;

  /// Amount to shift the point y-units
  const int dx_;
};

/**
 * @struct not_t
 */
template <typename FUNC>
struct not_t
{
  not_t (const FUNC & func)
    : func_ (func)
  {

  }

  template <typename T>
  bool operator () (T t) const
  {
    return !this->func_ (t);
  }

private:
  const FUNC & func_;
};

/**
 * @struct aspect_filter_t
 */
template <typename T>
struct aspect_filter_t
{
  aspect_filter_t (const GAME::Xml::String & aspect)
    : aspect_ (aspect)
  {

  }

  bool operator () (T t) const
  {
    return GAME::XME::is_in_aspect (t, this->aspect_);
  }

private:
  const GAME::Xml::String & aspect_;
};

/**
 * @struct arrange_vertical
  *
 * Functor that arranges elements vertically on the screen.
 */
struct arrange_vertical
{
  arrange_vertical (int x, int y, int dy)
    : x_ (x),
      y_ (y),
      dy_ (dy)
  {

  }

  void operator () (GAME::XME::FCO & fco)
  {
    // Set the position of the element.
    GAME::XME::set_position (fco,
                             constant::aspect::InterfaceDefinition,
                             this->x_,
                             this->y_);

    // Advance to the next element.
    this->y_ += this->dy_;
  }

private:
  /// The current x-position.
  const int x_;

  int y_;

  /// Amount to shift the point y-units
  const int dy_;
};

///////////////////////////////////////////////////////////////////////////////
// stream operators

//
// operator <<
//
GAME::Xml::String & operator << (GAME::Xml::String & str, const AST_Expression::AST_ExprValue & ev)
{
  std::ostringstream buffer;

  switch (ev.et)
  {
  case AST_Expression::EV_short:
    buffer << ev.u.sval;
    break;

  case AST_Expression::EV_ushort:
    buffer << ev.u.usval;
    break;

  case AST_Expression::EV_long:
    buffer << ev.u.lval;
    break;

  case AST_Expression::EV_ulong:
    buffer << ev.u.ulval;
    break;

  case AST_Expression::EV_longlong:
    buffer << ev.u.llval;
    break;

  case AST_Expression::EV_ulonglong:
    buffer << ev.u.ullval;
    break;

  case AST_Expression::EV_bool:
    buffer << (ev.u.bval ? "TRUE" : "FALSE");
    break;

  case AST_Expression::EV_float:
    buffer << ev.u.fval;
    break;

  case AST_Expression::EV_longdouble:
  case AST_Expression::EV_double:
    buffer << ev.u.dval;
    break;

  case AST_Expression::EV_char:
    buffer << ev.u.cval;
    break;

  case AST_Expression::EV_wchar:
    //buffer << ev.u.wcval;
    //ACE_OS::sprintf (buffer, "%lc", ev.u.wcval);
    //str = buffer;
    break;

  case AST_Expression::EV_octet:
    buffer << (int)ev.u.oval;
    break;

  case AST_Expression::EV_wstring:
    str.set (ev.u.wstrval);
    return str;

  case AST_Expression::EV_string:
    str.set (ev.u.strval->get_string ());
    return str;

  default:
    return str;
  }

  // Save the buffer in the string.
  str.set (buffer.str ().c_str ());

  return str;
}

//
// operator <<
//
GAME::Xml::String & operator << (GAME::Xml::String & str, AST_Expression & expr)
{
  const AST_Expression::ExprComb ec = expr.ec ();

  switch (ec)
  {
  case AST_Expression::EC_symbol:
    str.set (expr.param_holder ()->local_name ()->get_string ());
    break;

  default:
    str << *expr.ev ();
  }

  return str;
}


//
// operator <<
//
GAME::Xml::String & operator << (GAME::Xml::String & str, AST_Constant & c)
{
  const AST_Expression::ExprType et = c.et ();

  if (et == AST_Expression::EV_enum)
    str = c.full_name ();
  else
    str << *c.constant_value ();

  return str;
}

//
// operator <<
//
GAME::Xml::String & operator << (GAME::Xml::String & str, AST_UnionLabel & label)
{

  if (label.label_kind () == AST_UnionLabel::UL_default)
  {
    str = "default";
  }
  else
  {
    AST_Expression * e = label.label_val ();

    switch (e->ev ()->et)
    {
    case AST_Expression::EV_enum:
      {
        UTL_ScopedName * sn = e->n ();
        AST_Decl * decl = e->defined_in ()->lookup_by_name (sn, true, false);
        str = decl->local_name ()->get_string ();
      }
      break;

    default:
      str << *label.label_val ()->ev ();
    }
  }

  return str;
}

///////////////////////////////////////////////////////////////////////////////
// Project_Generator class

//
// initialize
//
void Project_Generator::initialize (void)
{
  using GAME::XME::Folder;
  using GAME::XME::Atom;
  using GAME::Xme_t;

  Folder root_folder = this->proj_.root_folder ();

  // Make sure the predefined types folder exists.
  Folder types_folder;

  if (GAME::create_if_not <Xme_t> (root_folder, constant::meta::PREDEFINED_TYPES, types_folder,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              constant::meta::PREDEFINED_TYPES,
                              boost::bind (&GAME::XME::Folder::name, _1)))))
  {
    types_folder.name (constant::meta::PREDEFINED_TYPES);
  }

  // Retrieve all the predefined types in this folder, which will
  // be all the atoms in the folder.
  std::vector <Atom> current_types;
  types_folder.children (current_types);

  static const predefined_typeinfo predefined_types[] =
  {
    {"Boolean", {AST_PredefinedType::PT_boolean, AST_PredefinedType::PT_void}},
    {"Byte", {AST_PredefinedType::PT_octet, AST_PredefinedType::PT_void}},

    {"Char", {AST_PredefinedType::PT_char, AST_PredefinedType::PT_void}},
    {"WideChar", {AST_PredefinedType::PT_wchar, AST_PredefinedType::PT_void}},

    {"ShortInteger", {AST_PredefinedType::PT_short, AST_PredefinedType::PT_void}},
    {"LongInteger", {AST_PredefinedType::PT_long, AST_PredefinedType::PT_void}},
    {"LongLongInteger", {AST_PredefinedType::PT_longlong, AST_PredefinedType::PT_void}},

    {"UnsignedShortInteger", {AST_PredefinedType::PT_ushort, AST_PredefinedType::PT_void}},
    {"UnsignedLongInteger", {AST_PredefinedType::PT_ulong, AST_PredefinedType::PT_void}},
    {"UnsignedLongLongInteger", {AST_PredefinedType::PT_ulonglong, AST_PredefinedType::PT_void}},

    {"FloatNumber", {AST_PredefinedType::PT_float, AST_PredefinedType::PT_void}},
    {"DoubleNumber", {AST_PredefinedType::PT_double, AST_PredefinedType::PT_void}},
    {"LongDoubleNumber", {AST_PredefinedType::PT_longdouble, AST_PredefinedType::PT_void}},

    {"GenericObject", {AST_PredefinedType::PT_object, AST_PredefinedType::PT_void}},
    {"GenericValue", {AST_PredefinedType::PT_any, AST_PredefinedType::PT_void}},
    {"GenericValueObject", {AST_PredefinedType::PT_value, AST_PredefinedType::PT_void}},

    {0, AST_PredefinedType::PT_void}
  };

  Atom predefined_type;
  GAME::Xml::String metaname;

  for (const predefined_typeinfo * iter = predefined_types;
       iter->metaname_ != 0;
       ++ iter)
  {
    // Tranlate the C string to a XMLString.
    metaname.set (iter->metaname_);

    // Either, create a new element or get the existing one.
    if (GAME::create_if_not <Xme_t> (types_folder, metaname, current_types, predefined_type,
        GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                metaname,
                                boost::bind (&GAME::XME::Atom::kind, _1)))))
    {
      predefined_type.name (metaname);
    }

    // Associate the GME type with its IDL predefined types.
    for (const AST_PredefinedType::PredefinedType * type_ptr = iter->type_id_;
         AST_PredefinedType::PT_void != *type_ptr;
         ++ type_ptr)
    {
      this->predefined_.bind (*type_ptr, predefined_type);
    }
  }

  // Create the string predefined type.
  if (GAME::create_if_not <Xme_t> (types_folder, constant::meta::String, current_types, this->string_type_,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              constant::meta::String,
                              boost::bind (&GAME::XME::Atom::kind, _1)))))
  {
    this->string_type_.name (constant::meta::String);
  }

  if (GAME::create_if_not <Xme_t> (types_folder, constant::meta::WideString, current_types, this->wstring_type_,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              constant::meta::String,
                              boost::bind (&GAME::XME::Atom::kind, _1)))))
  {
    this->wstring_type_.name (constant::meta::WideString);
  }
}

//
// finalize
//
void Project_Generator::finalize (void)
{
  typedef
    ACE_Hash_Map_Manager <GAME::XME::Reference,
                          AST_Decl *,
                          ACE_Null_Mutex>
                          unresolved_t;

  for (unresolved_t::ITERATOR iter (this->unresolved_); !iter.done (); ++ iter)
  {
    if (0 != this->handle_symbol_resolution (iter->item (), iter->key (), true))
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%T (%t) - %M - failed to resolve %s referenced by %s; it ")
                  ACE_TEXT ("will remain NIL\n"),
                  iter->item ()->repoID (),
                  iter->key ().path ("/").to_string ().c_str ()));
  }
}

//
// visit_root
//
int Project_Generator::visit_root (AST_Root * node)
{
  using GAME::XME::Folder;
  using GAME::XME::Model;

  char abspath[MAXPATHLEN];
  ACE_CString fullpath;

  for (UTL_ScopeActiveIterator si (node, UTL_Scope::IK_decls);
       !si.is_done (); si.next ())
  {
    AST_Decl * d = si.item ();
    AST_Decl::NodeType nt = d->node_type ();

    if (nt == AST_Decl::NT_pre_defined || (nt == AST_Decl::NT_enum_val && !this->is_in_enum_))
      continue;

    if (node->node_type () == AST_Decl::NT_component)
    {
      // We do not support embedded named types.
      if (nt == AST_Decl::NT_struct ||
          nt == AST_Decl::NT_sequence ||
          nt == AST_Decl::NT_typedef)
      {
        continue;
      }
    }

    // Some of the files will have a full path, and others will not. So,
    // to be save we just need to make sure we have the real path for
    // each element.
    fullpath = ACE_OS::realpath (d->file_name ().c_str (), abspath);
    std::replace (fullpath.begin (),
                  fullpath.end (),
                  '\\',
                  '/');

    if (0 != this->files_.files ().find (fullpath, this->current_file_))
      continue;

    this->parent_ = &this->current_file_->file_;
    int retval = d->ast_accept (this);
    const char * repo_id = d->repoID ();

    if (retval != 0)
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%T (%t) - %M - failed to construct %s in %s\n"),
                         d->repoID (),
                         d->file_name ().c_str ()),
                         -1);
  }

  return 0;
}

//
// visit_decl
//
int Project_Generator::visit_decl (AST_Decl *d)
{
  return 0;
}

//
// visit_scope
//
int Project_Generator::
visit_scope (UTL_Scope * node, GAME::XME::Auto_Model_T <GAME::XME::Model> * auto_model)
{
  // Save the current parent model.
  GAME::XME::Auto_Model_T <GAME::XME::Model> * temp = this->parent_;
  this->parent_ = auto_model;

  // Visit this scope.
  int retval = this->visit_scope (node);

  // Restore the old parent model.
  this->parent_ = temp;
  return retval;
}

//
// visit_scope
//
int Project_Generator::visit_scope (UTL_Scope *node)
{
  AST_Decl * node_decl = ScopeAsDecl (node);
  bool in_root = node_decl->node_type () == AST_Decl::NT_root;

  for (UTL_ScopeActiveIterator si (node, UTL_Scope::IK_decls);
       !si.is_done (); si.next ())
  {
    AST_Decl * d = si.item ();
    AST_Decl::NodeType nt = d->node_type ();

    if (nt == AST_Decl::NT_pre_defined || (nt == AST_Decl::NT_enum_val && !this->is_in_enum_))
      continue;

    // Want to skip the 'uses multiple' related artifacts.
    if (node_decl->node_type () == AST_Decl::NT_component)
    {
      if (nt == AST_Decl::NT_struct ||
          nt == AST_Decl::NT_sequence ||
          nt == AST_Decl::NT_typedef)
      {
        continue;
      }
    }

    int retval = d->ast_accept (this);

    if (retval != 0)
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("adding_visitor::visit_scope - ")
                         ACE_TEXT ("codegen for scope failed\n")),
                         -1);
  }

  return 0;
}

//
// visit_module
//
int Project_Generator::visit_module (AST_Module *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building module %s...\n"),
                node->repoID ()));

  using GAME::XME::Auto_Model_T;
  using GAME::XME::FCO;
  using GAME::XME::Model;
  using GAME::Xme_t;

  // If this template module is the product of a template module
  // reference, then we need to restore the parameter set for that
  // declaration. Otherwise, we run the risk of having incorrect
  // parameters being referenced in this module.
  AST_Template_Module_Ref * module_ref = node->from_ref ();

  if (0 != module_ref)
  {
    if (be_global->is_debugging_enabled ())
      ACE_ERROR ((LM_DEBUG,
                  ACE_TEXT ("%T (%t) - %M - restoring parameter set for %s\n"),
                  module_ref->repoID ()));

    if (0 != this->param_mgr_.begin_parameter_set (module_ref))
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%T (%t) - %M - failed to restore parameter set for %s [file=%s]\n"),
                  module_ref->repoID (),
                  module_ref->file_name ().c_str ()));
  }

  Model package;
  Auto_Model_T <Model> * module = 0;
  const char * repo_id = node->repoID ();

  if (0 != this->current_file_->modules_.find (repo_id, module))
  {
    // Either locate an existing package, or create a new one.
    static const GAME::Xml::String meta_Package ("Package");
    const GAME::Xml::String name (node->local_name ()->get_string ());

    // Do we really need to perform this check since not finding
    // a module for this package means it does not exist?!
    if (be_global->is_debugging_enabled ())
      ACE_ERROR((LM_DEBUG,
                 ACE_TEXT ("%T (%t) - %M - creating %s in %s\n"),
                 node->repoID (),
                 this->parent_->get ().path ("/").to_string ().c_str ()));

    if (this->parent_->create_if_not (meta_Package, package,
        GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                name,
                                boost::bind (&Model::name, _1)))))
    {
      package.name (name);
    }
  }

  // First, let's see if we have already created this element and bound
  // it to the template module hash map.
  this->current_file_->modules_.find (repo_id, module);

  if (0 == module && !package.is_nil ())
  {
    // At this point, we only care about managing the objects that
    // are not in the TemplateParameters aspect.
    std::vector <FCO> non_parameters;
    package.children (non_parameters);

    std::vector <FCO>::iterator end_iter =
      std::remove_if (non_parameters.begin (),
                      non_parameters.end (),
                      aspect_filter_t <FCO> (constant::aspect::TemplateParameters));

    // We need to store this package in the global space since it
    // is reentrant. We don't want elements deleted on accident. ;-)
    ACE_NEW_RETURN (module,
                    Auto_Model_T <Model> (package,
                                          non_parameters.begin (),
                                          end_iter),
                    -1);

    if (0 != this->current_file_->modules_.bind (repo_id, module))
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%T (%t) - %M - failed to bind %s\n"),
                         repo_id),
                         -1);
  }

  int retval = -1;

  if (0 != module)
  {
    // Visit the remaining elements in this scope.
    retval = this->visit_scope (node, module);

    // Make sure we re-cache the parameter set if this module is
    // the product of a template module reference.
    if (0 != module_ref)
      this->param_mgr_.end_parameter_set (module_ref);
  }

  return retval;
}

//
// visit_interface
//
int Project_Generator::visit_interface (AST_Interface *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building interface %s...\n"),
                node->repoID ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Object ("Object");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model object;

  if (this->parent_->create_if_not (meta_Object, object,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    object.name (name);
  }

  if (node->is_abstract ())
    object.attribute (constant::attr::InterfaceSemantics, true).value (constant::attr::abstract);
  else if (node->is_local ())
    object.attribute (constant::attr::InterfaceSemantics, true).value (constant::attr::local);

  // Store the element as a symbol.
  this->store_symbol (node, object);

  Auto_Model_T <Model> auto_model (object);
  int retval = this->visit_scope (node, &auto_model);

  // Arrange all the child elements veritcally in the model.
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (60, 60, 100));

  using GAME::XME::FCO;

  // Check for any interface inheritance.
  static const GAME::Xml::String meta_Inherits ("Inherits");
  long inherits_flat_count = node->n_inherits_flat ();
  AST_Interface ** inherits_flat = node->inherits_flat ();

  //if (0 == inherits_count)
  //  long inherits_flat_count = node->n_inherits ();

  for (long i = 0; i < inherits_flat_count; ++ i)
  {
    FCO referred_interface;

    if (!this->lookup_symbol (inherits_flat[i], referred_interface))
      continue;

    Reference inherits_ref;

    if (auto_model.create_if_not (meta_Inherits, inherits_ref,
        GAME::contains <Xme_t> (boost::bind (std::equal_to <FCO> (),
                                referred_interface,
                                boost::bind (&Reference::refers_to, _1)))))
    {
      if (be_global->is_debugging_enabled ())
        ACE_DEBUG ((LM_DEBUG,
                    ACE_TEXT ("%T (%t) - %M - setting %s to reference %s\n"),
                    inherits_ref.path ("/").to_string ().c_str (),
                    referred_interface.path ("/").to_string ().c_str ()));

      inherits_ref.refers_to (referred_interface);
      inherits_ref.name (meta_Inherits);
    }
  }

  return retval;
}

//
// visit_interface_fwd
//
int Project_Generator::visit_interface_fwd (AST_InterfaceFwd *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building forward decl %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Object ("Object");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model object;

  if (this->parent_->create_if_not (meta_Object, object,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    object.name (name);
  }

  // Set the attributes for the object.
  if (node->is_abstract ())
    object.attribute (constant::attr::InterfaceSemantics, true).value (constant::attr::abstract);
  else if (node->is_local ())
    object.attribute (constant::attr::InterfaceSemantics, true).value (constant::attr::local);

  // Store the element as a symbol.
  this->symbols_.bind (node, object);

  return 0;
}

//
// visit_valuetype
//
int Project_Generator::visit_valuetype (AST_ValueType *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_ValueObject ("ValueObject");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model value_object;

  if (this->parent_->create_if_not (meta_ValueObject, value_object,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    value_object.name (name);
  }

  // Set the attributes for the object.
  if (node->is_abstract ())
    value_object.attribute (constant::attr::abstract, true).value (true);

  // Store the element as a symbol.
  this->symbols_.bind (node, value_object);

  // Visit the elements in the structure.
  Auto_Model_T <Model> auto_model (value_object);
  if (-1 == this->visit_scope (node, &auto_model))
    return -1;

  // Align the elements in the structure.
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (60, 60, 100));

  return 0;
}

//
// visit_valuetype_fwd
//
int Project_Generator::visit_valuetype_fwd (AST_ValueTypeFwd *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building forward decl. %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_ValueObject ("ValueObject");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model value_object;

  if (this->parent_->create_if_not (meta_ValueObject, value_object,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    value_object.name (name);
  }

  // Set the attributes for the object.
  if (node->is_abstract ())
    value_object.attribute (constant::attr::abstract, true).value (true);

  // Store the element as a symbol.
  this->symbols_.bind (node, value_object);
  return 0;
}

//
// visit_component
//
int Project_Generator::visit_component (AST_Component *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::XME::Reference;
  using GAME::XME::FCO;

  using GAME::Xme_t;

  static const GAME::Xml::String meta_Component ("Component");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model component;

  if (this->parent_->create_if_not (meta_Component, component,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    component.name (name);
  }

  // Store the element as a symbol.
  this->symbols_.bind (node, component);

  Auto_Model_T <Model> auto_model (component);
  int retval = this->visit_scope (node, &auto_model);

  // Check for any component inheritence.
  AST_Type ** inherits = node->inherits ();

  if (inherits != 0)
  {
    // There is a bug in TAO_IDL_FE where it returns a supported interface
    // as an inherited interface. So, we need check if this is actually an
    // inherited interface.
    bool is_inherited = true;

    AST_Type ** supports_list = node->supports ();
    long supports_count = node->n_supports ();

    for (long i = 0; i < supports_count; ++ i)
    {
      if (supports_list[i] == *inherits)
      {
        is_inherited = false;
        break;
      }
    }

    if (is_inherited)
    {
      static const GAME::Xml::String meta_CompenentInherits ("ComponentInherits");

      Reference ref_inherits;

      if (auto_model.create_if_not (meta_CompenentInherits, ref_inherits,
          GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                  meta_CompenentInherits,
                                  boost::bind (&Reference::kind, _1)))))
      {
        ;
      }

      ref_inherits.name (meta_CompenentInherits);
      this->handle_symbol_resolution (*inherits, ref_inherits);
    }
  }

  // Check for any component inheritence.
  long supports_count = node->n_supports ();

  if (supports_count > 0)
  {
    static const GAME::Xml::String meta_Supports ("Supports");
    AST_Type ** supports_list = node->supports ();

    for (long i = 0; i < supports_count; ++ i)
    {
      FCO referred_interface;

      if (!this->lookup_symbol (supports_list[i], referred_interface))
        continue;

      Reference supports;

      if (auto_model.create_if_not (meta_Supports, supports,
          GAME::contains <Xme_t> (boost::bind (std::equal_to <FCO> (),
                                  referred_interface,
                                  boost::bind (&Reference::refers_to, _1)))))
      {
        if (be_global->is_debugging_enabled ())
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("%T (%t) - %M - setting %s to reference %s\n"),
                      supports.path ("/").to_string ().c_str (),
                      referred_interface.path ("/").to_string ().c_str ()));

        supports.refers_to (referred_interface);
        supports.name (meta_Supports);
      }
    }
  }

  return retval;
}

//
// visit_component_fwd
//
int Project_Generator::visit_component_fwd (AST_ComponentFwd *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building forward decl. %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Component ("Component");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model component;

  if (this->parent_->create_if_not (meta_Component, component,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    component.name (name);
  }

  // Store the element as a symbol.
  this->symbols_.bind (node, component);

  return 0;
}

//
// visit_provides
//
int Project_Generator::visit_provides (AST_Provides *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_ProvidedRequestPort ("ProvidedRequestPort");

  // Either locate an existing package, or create a new one.
  Reference ref;
  const GAME::Xml::String name (node->local_name ()->get_string ());

  if (this->parent_->create_if_not (meta_ProvidedRequestPort, ref,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Reference::name, _1)))))
  {
    ref.name (name);
  }

  // Resolve the event type for this port.
  this->handle_symbol_resolution (node->provides_type (), ref);

  return 0;
}

//
// visit_uses
//
int Project_Generator::visit_uses (AST_Uses *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_RequiredRequestPort ("RequiredRequestPort");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Reference ref;

  if (this->parent_->create_if_not (meta_RequiredRequestPort, ref,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Reference::name, _1)))))
  {
    ref.name (name);
  }

  ref.attribute (constant::attr::multiple_connections, true).value (node->is_multiple ());

  // Resolve the event type for this port.
  this->handle_symbol_resolution (node->uses_type (), ref);

  return 0;
}

//
// visit_publishes
//
int Project_Generator::visit_publishes (AST_Publishes *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_OutEventPort ("OutEventPort");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Reference ref;

  if (this->parent_->create_if_not (meta_OutEventPort, ref,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Reference::name, _1)))))
  {
    ref.name (name);
  }

  // Set the attributes for the object.
  ref.attribute (constant::attr::single_destination, true).value (false);

  // Resolve the event type for this port.
  this->handle_symbol_resolution (node->publishes_type (), ref);

  return 0;
}

//
// visit_emits
//
int Project_Generator::visit_emits (AST_Emits *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_OutEventPort ("OutEventPort");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Reference ref;

  if (this->parent_->create_if_not (meta_OutEventPort, ref,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Reference::name, _1)))))
  {
    ref.name (name);
  }

  // Set the attributes for the object.
  ref.attribute (constant::attr::single_destination, true).value (true);

  // Resolve the event type for this port.
  this->handle_symbol_resolution (node->emits_type (), ref);

  return 0;
}

//
// visit_consumes
//
int Project_Generator::visit_consumes (AST_Consumes *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_InEventPort ("InEventPort");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Reference ref;

  if (this->parent_->create_if_not (meta_InEventPort, ref,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Reference::name, _1)))))
  {
    ref.name (name);
  }

  // Resolve the event type for this port.
  this->handle_symbol_resolution (node->consumes_type (), ref);

  return 0;
}

//
// visit_eventtype
//
int Project_Generator::visit_eventtype (AST_EventType *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Event ("Event");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model ev;

  if (this->parent_->create_if_not (meta_Event, ev,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    ev.name (name);
  }

  // Store the element as a symbol.
  this->symbols_.bind (node, ev);

  // Visit the elements in the structure.
  Auto_Model_T <Model> auto_model (ev);
  if (-1 == this->visit_scope (node, &auto_model))
    return -1;

  // Align the elements in the structure.
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (60, 60, 100));

  return 0;
}

//
// visit_eventtype_fwd
//
int Project_Generator::visit_eventtype_fwd (AST_EventTypeFwd *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building forward decl. %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Event ("Event");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model ev;

  if (this->parent_->create_if_not (meta_Event, ev,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    ev.name (name);
  }

  // Store the element as a symbol.
  this->symbols_.bind (node, ev);

  return 0;
}

//
// visit_home
//
int Project_Generator::visit_home (AST_Home *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_ComponentFactory ("ComponentFactory");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model component_factory;

  if (this->parent_->create_if_not (meta_ComponentFactory, component_factory,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    component_factory.name (name);
  }

  // Add a LookupKey to the element, if applicable.
  Auto_Model_T <Model> auto_clean (component_factory);
  AST_Type * primary_key = node->primary_key ();

  if (0 != primary_key)
  {
    static const GAME::Xml::String meta_LookupKey ("LookupKey");

    using GAME::XME::Reference;
    Reference lookup_key;

    auto_clean.create_if_not (meta_LookupKey, lookup_key,
                              GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                                      meta_LookupKey,
                                                      boost::bind (&Model::kind, _1))));

    // Set the reference to the valid model element.
    this->handle_symbol_resolution (primary_key, lookup_key);
  }

  // Locate the component that this home manages.
  GAME::XME::FCO component;
  this->lookup_symbol (node->managed_component (), component);

  // TODO need to update with condition to check if a connection already
  // exists between the factory and the component.
  using GAME::XME::Connection;
  Connection manages;

  // Create a connection between this home and the component.
  static const GAME::Xml::String meta_ManagesComponent ("ManagesComponent");

  if (!GAME::find <Xme_t> (this->parent_->get (), meta_ManagesComponent, manages,
        boost::bind (std::logical_and <bool> (),
          boost::bind (std::equal_to <GAME::XME::FCO> (),
                       component_factory,
                       boost::bind (&Connection::src, _1)),
          boost::bind (std::equal_to <GAME::XME::FCO> (),
                       component,
                       boost::bind (&Connection::dst, _1)))))
  {
    GAME::XME::Connection::_create (this->parent_->get (),
                                   meta_ManagesComponent,
                                   component_factory,
                                   component);
  }

  // Store the element as a symbol.
  return this->visit_scope (node, &auto_clean);
}

//
// visit_factory
//
int Project_Generator::visit_factory (AST_Factory *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_FactoryOperation ("FactoryOperation");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model factory_op;

  if (this->parent_->create_if_not (meta_FactoryOperation, factory_op,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    factory_op.name (name);
  }

  Auto_Model_T <Model> auto_model (factory_op);
  if (0 != this->visit_scope (node, &auto_model))
    return -1;

  // Align the elements in the structure.
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_horizontal (constant::aspect::InterfaceDefinition, 60, 60, 100));

  return 0;
}

//
// visit_finder
//
int Project_Generator::visit_finder (AST_Finder *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_LookupOperation ("LookupOperation");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model lookup_op;

  if (this->parent_->create_if_not (meta_LookupOperation, lookup_op,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    lookup_op.name (name);
  }

  Auto_Model_T <Model> auto_model (lookup_op);
  if (0 != this->visit_scope (node, &auto_model))
    return -1;

  // Align the elements in the structure.
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_horizontal (constant::aspect::InterfaceDefinition, 60, 60, 100));

  return 0;
}

//
// visit_structure
//
int Project_Generator::visit_structure (AST_Structure *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Aggregate ("Aggregate");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model aggregate;

  if (this->parent_->create_if_not (meta_Aggregate, aggregate,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    aggregate.name (name);
  }

  this->symbols_.bind (node, aggregate);

  // Visit the elements in the structure.
  Auto_Model_T <Model> auto_model (aggregate);
  if (-1 == this->visit_scope (node, &auto_model))
    return -1;

  // Align the elements in the structure.
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (60, 60, 100));

  return 0;
}

//
// visit_structure_fwd
//
int Project_Generator::visit_structure_fwd (AST_StructureFwd *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building forward decl. %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Aggregate ("Aggregate");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model aggregate;

  if (this->parent_->create_if_not (meta_Aggregate, aggregate,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    aggregate.name (name);
  }

  this->symbols_.bind (node, aggregate);
  return 0;
}

//
// visit_exception
//
int Project_Generator::visit_exception (AST_Exception *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Exception ("Exception");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model exception;

  if (this->parent_->create_if_not (meta_Exception, exception,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    exception.name (name);
  }

  this->symbols_.bind (node, exception);

  Auto_Model_T <Model> auto_model (exception);
  return this->visit_scope (node, &auto_model);
}

int Project_Generator::visit_expression (AST_Expression *node){ return 0; }

//
// visit_enum
//
int Project_Generator::visit_enum (AST_Enum *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Enum ("Enum");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model enumeration;

  if (this->parent_->create_if_not (meta_Enum, enumeration,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    enumeration.name (name);
  }

  // Save the enum value
  this->symbols_.bind (node, enumeration);

  // Visit the contents of the enumeration.
  Auto_Model_T <Model> auto_model (enumeration);
  this->is_in_enum_ = true;

  if (-1 == this->visit_scope (node, &auto_model))
    return -1;

  this->is_in_enum_ = false;
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (60, 60, 100));

  return 0;
}

//
// visit_enum_val
//
int Project_Generator::visit_enum_val (AST_EnumVal *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Atom;
  using GAME::Xme_t;

  // Either locate an existing package, or create a new one.
  Atom value;
  const GAME::Xml::String name (node->local_name ()->get_string ());
  static const GAME::Xml::String meta_EnumValue ("EnumValue");

  if (this->parent_->create_if_not (meta_EnumValue, value,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Atom::name, _1)))))
  {
    value.name (name);
  }

  return 0;
}

//
// visit_operation
//
int Project_Generator::visit_operation (AST_Operation *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  Model operation;
  const GAME::Xml::String name (node->local_name ()->get_string ());

  if (node->flags () == AST_Operation::OP_oneway)
  {
    // Create, or locate, a oneway operation.
    static const GAME::Xml::String meta_OnewayOperation ("OnewayOperation");

    if (this->parent_->create_if_not (meta_OnewayOperation, operation,
        GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                name,
                                boost::bind (&Model::name, _1)))))
    {
      operation.name (name);
    }
  }
  else
  {
    // Create, or locate, a twoway operation.
    static const GAME::Xml::String meta_TwowayOperation ("TwowayOperation");

    if (this->parent_->create_if_not (meta_TwowayOperation, operation,
        GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                name,
                                boost::bind (&Model::name, _1)))))
    {
      operation.name (name);
    }
  }

  Auto_Model_T <Model> auto_model (operation);

  if (!node->void_return_type ())
  {
    using GAME::XME::Reference;
    using GAME::XME::FCO;

    // Create the return type element.
    Reference return_type;
    static const GAME::Xml::String meta_ReturnType ("ReturnType");

    if (auto_model.create_if_not (meta_ReturnType, return_type,
        GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                meta_ReturnType,
                                boost::bind (&Reference::kind, _1)))))
    {
      return_type.name (meta_ReturnType);
    }

    this->handle_symbol_resolution (node->return_type (), return_type);
  }

  // Visit the remaining elements in the model.
  this->visit_scope (node, &auto_model);

  // Add the exception elements to the operation.
  static const GAME::Xml::String meta_Exception ("ExceptionRef");
  this->visit_exception_list (node->exceptions (), meta_Exception, auto_model);

  // Finally, short all the element in <auto_model> horizontally.
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_horizontal (constant::aspect::InterfaceDefinition, 60, 60, 100));
  return 0;
}

//
// visit_field
//
int Project_Generator::visit_field (AST_Field *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  // Locate the concrete type in the symbol table.
  const GAME::Xml::String field_name (node->local_name ()->get_string ());
  AST_Type * type = node->field_type ();
  const GAME::Xml::String metename = type->node_type () == AST_Decl::NT_array ? "ArrayMember" : "Member";

  // Either locate the existing Member element, or create a new
  // one for the field.

  Reference member;
  if (this->parent_->create_if_not (metename, member,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              field_name,
                              boost::bind (&Reference::name, _1)))))
  {
    member.name (field_name);
  }

  // Locate the target FCO that will be referenced.
  this->handle_symbol_resolution (type, member);

  if (type->node_type () == AST_Decl::NT_array)
  {
    AST_Array * arr = dynamic_cast <AST_Array *> (type);
    AST_Expression ** dims = arr->dims ();

    GAME::Xml::String value;
    value << *dims[0]->ev ();

    member.attribute ("Size", true).value (value);
  }

  return 0;
}

//
// visit_array
//
int Project_Generator::visit_array (AST_Array *node)
{
  return 0;
}

//
// visit_attribute
//
int Project_Generator::visit_attribute (AST_Attribute *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  Model attribute;
  const GAME::Xml::String name (node->local_name ()->get_string ());

  if (node->readonly ())
  {
    // We need to create a ReadonlyAttribute for the model.
    static const GAME::Xml::String meta_ReadonlyAttribute ("ReadonlyAttribute");

    if (this->parent_->create_if_not (meta_ReadonlyAttribute, attribute,
        GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                name,
                                boost::bind (&Model::name, _1)))))
    {
      attribute.name (name);
    }
  }
  else
  {
    // We need to create an Attribute for the model.
    static const GAME::Xml::String meta_Attribute ("Attribute");

    if (this->parent_->create_if_not (meta_Attribute, attribute,
        GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                name,
                                boost::bind (&Model::name, _1)))))
    {
      attribute.name (name);
    }
  }

  Auto_Model_T <GAME::XME::Model> auto_model (attribute);

  // Set the reference element for the attribute's type.
  static const GAME::Xml::String meta_AttributeMember ("AttributeMember");

  using GAME::XME::Reference;
  Reference attribute_member;
  std::vector <Reference> attribute_members;

  auto_model.create_if_not (meta_AttributeMember, attribute_member,
                            GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                                    meta_AttributeMember,
                                                    boost::bind (&Reference::kind, _1))));

  this->handle_symbol_resolution (node->field_type (), attribute_member);

  // Handle the *get* exceptions for this element.
  static const GAME::Xml::String meta_GetException ("GetException");
  this->visit_exception_list (node->get_get_exceptions (),
                              meta_GetException,
                              auto_model);

  if (!node->readonly ())
  {
    // Handle the *set* exceptions for this element since it is
    // not a readonly attribute.
    static const GAME::Xml::String meta_SetException ("SetException");
    this->visit_exception_list (node->get_set_exceptions (),
                                meta_SetException,
                                auto_model);
  }


  // Finally, arrange the elements in horizontal order.
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_horizontal (constant::aspect::InterfaceDefinition, 60, 60, 100));

  return 0;
}

//
// visit_argument
//
int Project_Generator::visit_argument (AST_Argument *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building argument %s...\n"),
                node->repoID ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_list[5] =
  {
    GAME::Xml::String::EMPTY_STRING,
    "InParameter",
    "OutParameter",
    GAME::Xml::String::EMPTY_STRING,
    "InoutParameter"
  };

  // Initialize the typename for the argument.
  const GAME::Xml::String * meta = &meta_list[node->direction ()];
  const GAME::Xml::String name (node->local_name ()->get_string ());

  // Create the argument if it does not exist.
  Reference argument;
  if (this->parent_->create_if_not (*meta, argument,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Reference::name, _1)))))
  {
    argument.name (name);
  }

  this->handle_symbol_resolution (node->field_type (), argument);

  return 0;
}

//
// visit_union
//
int Project_Generator::visit_union (AST_Union *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::FCO;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_SwitchedAggregate ("SwitchedAggregate");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model switched_aggregate;

  if (this->parent_->create_if_not (meta_SwitchedAggregate, switched_aggregate,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    switched_aggregate.name (name);
  }

  // Add the element to the symbol table.
  this->symbols_.bind (node, switched_aggregate);
  Auto_Model_T <Model> auto_model (switched_aggregate);

  // Insert the discriminator into the model.
  GAME::XME::FCO fco;
  this->lookup_symbol (node->disc_type (), fco);

  using GAME::XME::Reference;
  Reference discriminator;
  static const GAME::Xml::String meta_Discriminator ("Discriminator");

  if (auto_model.create_if_not (meta_Discriminator, discriminator,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              meta_Discriminator,
                              boost::bind (&Reference::kind, _1)))))
  {
    discriminator.name (meta_Discriminator);
  }

  discriminator.refers_to (fco);

  // Visit the elements in the structure.
  if (-1 == this->visit_scope (node, &auto_model))
    return -1;

  // Align the elements in the structure.
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (60, 60, 100));

  return 0;
}

//
// visit_union_fwd
//
int Project_Generator::visit_union_fwd (AST_UnionFwd *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building forward decl. %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_SwitchedAggregate ("SwitchedAggregate");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model switched_aggregate;

  if (this->parent_->create_if_not (meta_SwitchedAggregate, switched_aggregate,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    switched_aggregate.name (name);
  }

  this->symbols_.bind (node, switched_aggregate);
  return 0;
}

//
// visit_union_branch
//
int Project_Generator::visit_union_branch (AST_UnionBranch *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Member ("Member");
  const GAME::Xml::String name (node->local_name ()->get_string ());

  Reference branch;
  if (this->parent_->create_if_not (meta_Member, branch,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Reference::name, _1)))))
  {
    branch.name (name);
  }

  this->handle_symbol_resolution (node->field_type (), branch);

  // Set all the labels for this member. Remember, there can be
  // more than one label associated with a branch.
  UTL_LabelList * labels = node->labels ();
  const size_t length = node->label_list_length ();

  for (size_t i = 0; i < length; ++ i)
  {
    using GAME::XME::Atom;
    using GAME::XME::Connection;

    // Get the name of the label.
    AST_UnionLabel * l = node->label (i);

    GAME::Xml::String label_name;
    label_name << *l;

    // Create the label for this member.
    Atom label;
    static const GAME::Xml::String meta_Label ("Label");

    if (this->parent_->create_if_not (meta_Label, label,
        GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                label_name,
                                boost::bind (&Atom::name, _1)))))
    {
      label.name (label_name);
    }

    // Create a connection between the current union branch
    // element (i.e., Member) and the newly created label.
    static const GAME::Xml::String meta_LabelConnection ("LabelConnection");
    Connection connection;

    if (!GAME::find <Xme_t> (this->parent_->get (), meta_LabelConnection, connection,
          boost::bind (std::logical_and <bool> (),
            boost::bind (std::equal_to <GAME::XME::FCO> (),
                         branch,
                         boost::bind (&Connection::src, _1)),
            boost::bind (std::equal_to <GAME::XME::FCO> (),
                         label,
                         boost::bind (&Connection::dst, _1)))))
    {
      Connection::_create (this->parent_->get (),
                           meta_LabelConnection,
                           branch,
                           label);
    }
  }

  return 0;
}

//
// visit_union_label
//
int Project_Generator::visit_union_label (AST_UnionLabel *node)
{
  return 0;
}

//
// visit_constant
//
int Project_Generator::visit_constant (AST_Constant *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Constant ("Constant");
  const GAME::Xml::String name (node->local_name ()->get_string ());

  Reference constant;
  if (this->parent_->create_if_not (meta_Constant, constant,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                   name,
                                   boost::bind (&Reference::name, _1)))))
  {
    constant.name (name);
  }

  // We are going to declare a static array for mapping the
  // expression's type to the corresponding predefined type.
#define EXPRTYPE_TO_PREDEFINEDTYPE_MAP_SIZE 20

  static const
    AST_PredefinedType::PredefinedType
    static_map[EXPRTYPE_TO_PREDEFINEDTYPE_MAP_SIZE] =
  {
    AST_PredefinedType::PT_short,
    AST_PredefinedType::PT_ushort,
    AST_PredefinedType::PT_long,
    AST_PredefinedType::PT_ulong,
    AST_PredefinedType::PT_longlong,
    AST_PredefinedType::PT_ulonglong,
    AST_PredefinedType::PT_float,
    AST_PredefinedType::PT_double,
    AST_PredefinedType::PT_longdouble,
    AST_PredefinedType::PT_char,
    AST_PredefinedType::PT_wchar,
    AST_PredefinedType::PT_octet,
    AST_PredefinedType::PT_boolean,
    AST_PredefinedType::PT_void,
    AST_PredefinedType::PT_void,
    AST_PredefinedType::PT_void,
    AST_PredefinedType::PT_any,
    AST_PredefinedType::PT_object,
    AST_PredefinedType::PT_void,
    AST_PredefinedType::PT_void
  };

  GAME::XME::FCO fco;

  switch (node->et ())
  {
  case AST_Expression::EV_enum:
    {
      // Search for the enumeration value.
      UTL_ScopedName * scoped_name = node->enum_full_name ();
      AST_Decl * enum_decl = node->defined_in ()->lookup_by_name (scoped_name, true);
      AST_Enum * enum_type = AST_Enum::narrow_from_decl (enum_decl);

      // Locate the enum's corresponding modeling element.
      this->lookup_symbol (enum_type, fco);
    }
    break;

  case AST_Expression::EV_string:
  case AST_Expression::EV_wstring:
    // Select the string type.
    fco = this->string_type_;
    break;

  default:
    {
      // Let's assume the remaining types are *predefined*.
      GAME::XME::Atom atom;
      if (0 == this->predefined_.find (static_map[node->et ()], atom))
        fco = atom;
    }
  }

  // Set the constant's reference.
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - setting %s to reference %s\n"),
                constant.path ("/").to_string ().c_str (),
                fco.path ("/").to_string ().c_str ()));

  constant.refers_to (fco);

  // Last, we need to set the value of the constant.
  GAME::Xml::String value;
  value << *node;

  constant.attribute (constant::attr::value, true).value (value);

  return 0;
}

//
// visit_typedef
//
int Project_Generator::visit_typedef (AST_Typedef *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building typedef %s...\n"),
                node->repoID ()));

  if (be_global->is_debugging_enabled () && node->field_type ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - field type is %s...\n"),
                node->field_type ()->repoID ()));

  AST_Type * base_type = node->base_type ();
  if (0 == base_type)
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - there is no base type!\n")));

  static const GAME::Xml::String meta_list[2] =
  {
    "Alias",
    "Collection"
  };

  size_t index = 0;

  // Collection types in IDML are generated as IDL typedefs, so we
  // want the reverse of that as the behavior here.
  switch (base_type->node_type ())
  {
  case AST_Decl::NT_array:
    index = 1;
    base_type = AST_Array::narrow_from_decl (base_type)->base_type ();
    break;

  case AST_Decl::NT_sequence:
    index = 1;
    base_type = AST_Sequence::narrow_from_decl (base_type)->base_type ();
    break;
  }

  // Create the alias if it already does not exist in this model.
  using GAME::XME::Reference;
  using GAME::Xme_t;

  Reference alias;
  const GAME::Xml::String name (node->local_name ()->get_string ());

  if (this->parent_->create_if_not (meta_list[index], alias,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                   name,
                                   boost::bind (&Reference::name, _1)))))
  {
    alias.name (name);
  }

  this->handle_symbol_resolution (base_type, alias);
  this->symbols_.bind (node, alias);

  return 0;
}

//
// visit_valuebox
//
int Project_Generator::visit_valuebox (AST_ValueBox *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_Boxed ("Boxed");
  const GAME::Xml::String name (node->local_name ()->get_string ());

  Reference boxed;
  if (this->parent_->create_if_not (meta_Boxed, boxed,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Reference::name, _1)))))
  {
    boxed.name (name);
  }

  this->handle_symbol_resolution (node->boxed_type (), boxed);

  return 0;
}

//
// visit_exception_list
//
void Project_Generator::
visit_exception_list (UTL_ExceptList * list,
                      const GAME::Xml::String & meta,
                      GAME::XME::Auto_Model_T <GAME::XME::Model> & model)
{
  using GAME::XME::Reference;
  using GAME::XME::FCO;
  using GAME::Xme_t;

  FCO fco;
  Reference exception;

  for (UTL_ExceptlistActiveIterator iter (list); !iter.is_done (); iter.next ())
  {
    // Lookup the exception type in the model.
    AST_Type * type = iter.item ();

    if (this->lookup_symbol (type, fco))
    {
      // Create the exception if it does not already exist.
      if (model.create_if_not (meta, exception,
          GAME::contains <Xme_t> (boost::bind (std::equal_to <FCO> (),
                                  fco,
                                  boost::bind (&Reference::refers_to, _1)))))
      {
        if (be_global->is_debugging_enabled ())
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("%T (%t) - %M - setting %s to reference %s\n"),
                      exception.path ("/").to_string ().c_str (),
                      fco.path ("/").to_string ().c_str ()));

        exception.refers_to (fco);
      }
    }
  }
}

//
// store_symbol
//
int Project_Generator::store_symbol (AST_Decl * decl, const GAME::XME::FCO & fco)
{
  int retval = this->symbols_.bind (decl, fco);

  switch (retval)
  {
  case -1:
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - failed to store %s as %s\n"),
                decl->repoID (),
                fco.path ("/").to_string ().c_str ()));
    break;

  case 0:
    if (be_global->is_debugging_enabled ())
      ACE_ERROR ((LM_DEBUG,
                  ACE_TEXT ("%T (%t) - %M - successfully stored %s as %s\n"),
                  decl->repoID (),
                  fco.path ("/").to_string ().c_str ()));
    break;

  case 1:
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - %s already exists in symbol table\n"),
                decl->repoID (),
                fco.path ("/").to_string ().c_str ()));
    break;
  }

  return retval;
}


//
// handle_symbol_resolution
//
int Project_Generator::
handle_symbol_resolution (AST_Decl * type,
                          GAME::XME::Reference & ref,
                          bool use_library)
{
  GAME::XME::FCO fco;
  this->temp_ref_ = ref;
  int retval = 0;

  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - handle_symbol_resolution () locating %s\n"),
                type->repoID ()));

  if (this->lookup_symbol (type, fco, use_library))
  {
    if (be_global->is_debugging_enabled ())
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%T (%t) - %M - handle_symbol_resolution () [%s] = %s\n"),
                  type->repoID (),
                  fco.path ("/").to_string ().c_str ()));

    if (be_global->is_debugging_enabled ())
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%T (%t) - %M - setting %s to reference %s [%s]\n"),
                  ref.path ("/").to_string ().c_str (),
                  fco.path ("/").to_string ().c_str (),
                  type->repoID ()));

    if (ref != fco)
      ref.refers_to (fco);
    else
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%T (%t) - %M - self-reference not allowed [%s | %s]\n"),
                  ref.path ("/").to_string ().c_str (),
                  fco.path ("/").to_string ().c_str ()));

      retval = -1;
    }
  }
  else
  {
    this->unresolved_.bind (ref, type);
    retval = -1;
  }

  return retval;
}

//
// lookup_symbol
//
bool Project_Generator::
lookup_symbol (AST_Decl * type, GAME::XME::FCO & fco, bool use_library)
{
  using GAME::XME::FCO;
  AST_Decl::NodeType node_type = type->node_type ();

  if (node_type == AST_Decl::NT_pre_defined)
  {
    // Since we do not support all the predefined types in PICML, we
    // must map each type to its corresponding PICML type.
    AST_PredefinedType * pt = dynamic_cast <AST_PredefinedType *> (type);

    GAME::XME::Atom predefined;
    if (0 != this->predefined_.find (pt->pt (), predefined))
      return false;

    fco = predefined;
    return true;
  }
  else if (node_type == AST_Decl::NT_array)
  {
    AST_Array * ar = dynamic_cast <AST_Array *> (type);
    return this->lookup_symbol (ar->base_type (), fco, use_library);
  }
  else if (node_type == AST_Decl::NT_string)
  {
    fco = this->string_type_;
    return true;
  }
  else if (node_type == AST_Decl::NT_wstring)
  {
    fco = this->wstring_type_;
    return true;
  }
  else if (node_type == AST_Decl::NT_param_holder)
  {
    AST_Param_Holder * param = dynamic_cast <AST_Param_Holder *> (type);
    const FE_Utils::T_Param_Info * info = param->info ();

    if (be_global->is_debugging_enabled ())
      ACE_ERROR ((LM_DEBUG,
                  ACE_TEXT ("%T (%t) - %M - lookup parameter %s of type %s\n"),
                  param->repoID (),
                  info->name_.c_str ()));

    if (this->param_mgr_.find (info, fco))
      return true;
  }
  else if (0 == this->symbols_.find (type, fco))
  {
    return true;
  }
  else if (use_library)
  {
    std::vector <GAME::XME::Library> libraries;
    this->proj_.attached_libraries (libraries);

    if (this->lookup_symbol (type, libraries, fco))
      return true;
  }

  return false;
}

//
// lookup_symbol
//
bool Project_Generator::
lookup_symbol (AST_Decl * type,
               std::vector <GAME::XME::Library> & libs,
               GAME::XME::FCO & fco)
{
  // Check the provided libraries.
  std::vector <GAME::XME::Library>::iterator
    iter = libs.begin (), iter_end = libs.end ();

  for (; iter != iter_end; ++ iter)
  {
    std::vector <GAME::XME::Folder> idl_files;
    static const GAME::Xml::String meta ("InterfaceDefinitions");

    iter->children (meta, idl_files);

    // We should go through these to find the right file before
    // continuing with our search.
    std::vector <GAME::XME::Folder>::iterator
      idl_files_iter = idl_files.begin (),
      idl_files_end = idl_files.end ();

    for (; idl_files_iter != idl_files_end; ++ idl_files_iter)
    {
      if (this->lookup_symbol (type, *idl_files_iter, fco))
        return true;
    }

    // See if this library has any attached libraries. If so, we should
    // continue searching through them as well.
    std::vector <GAME::XME::Library> libraries;
    iter->attached_libraries (libraries);

    if (this->lookup_symbol (type, libraries, fco))
      return true;
  }

  return false;
}

//
// lookup_symbol
//
bool Project_Generator::
lookup_symbol (AST_Decl * type,
               GAME::XME::Folder & folder,
               GAME::XME::FCO & fco)
{
  // We are in an interface definitions folder.
  std::vector <GAME::XME::Model> files;
  folder.children (files);

  //if (type == AST_Decl::NT_module)
  //  ;

  std::vector <GAME::XME::Model>::iterator
    iter = files.begin (), iter_end = files.end ();

  for (; iter != iter_end; ++ iter)
  {
    // Search the current file for this symbol.
    UTL_ScopedNameActiveIterator name_iter (type->name ());
    name_iter.next ();

    if (this->lookup_symbol (name_iter, *iter, fco))
      return true;
  }

  return false;
}

//
// lookup_symbol
//
bool Project_Generator::
lookup_symbol (UTL_ScopedNameActiveIterator & name_iter,
               GAME::XME::Model & model,
               GAME::XME::FCO & fco)
{
  std::vector <GAME::XME::FCO> children;
  model.children (children);

  std::vector <GAME::XME::FCO>::iterator
    iter = children.begin (), iter_end = children.end ();

  GAME::Xml::String name;
  char * iter_name;

  for ( ; iter != iter_end; ++ iter)
  {
    name.set (iter->name (), false);
    iter_name = name_iter.item ()->get_string ();

    if (0 == ACE_OS::strcmp (iter_name, name.to_string ().c_str ()))
    {
      // We found what we are looking for. Let's advance the
      // name iterator and see if there is anything left.
      name_iter.next ();
      GAME::Xml::String kind (iter->kind (), false);

      if (name_iter.is_done ())
      {
        fco = *iter;
        return true;
      }
      else if (iter->type () == GAME::XME::Object_Type::OT_MODEL)
      {
        GAME::XME::Model model = GAME::XME::Model::_narrow (*iter);
        return this->lookup_symbol (name_iter, model, fco);
      }
      else
      {
        // We got there before of a bad XML document.
        return false;
      }
    }
  }

  return false;
}

//
// visit_native
//
int Project_Generator::visit_native (AST_Native *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Atom;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_NativeValue ("NativeValue");
  const GAME::Xml::String name (node->local_name ()->get_string ());

  Atom native;

  if (this->parent_->create_if_not (meta_NativeValue, native,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Atom::name, _1)))))
  {
    native.name (name);
  }

  return 0;
}

///////////////////////////////////////////////////////////////////////////////
// IDL 3+

//
// visit_porttype
//
int Project_Generator::visit_porttype (AST_PortType *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_PortType ("PortType");

  // Either locate an existing package, or create a new one.
  Model porttype;
  const GAME::Xml::String name (node->local_name ()->get_string ());

  if (this->parent_->create_if_not (meta_PortType, porttype,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    porttype.name (name);
  }

  // Store the element as a symbol.
  this->symbols_.bind (node, porttype);

  Auto_Model_T <Model> auto_model (porttype);
  int retval = this->visit_scope (node, &auto_model);

  // Arrange all the child elements veritcally in the model.
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (60, 60, 100));

  return 0;
}

//
// visit_extended_port
//
int Project_Generator::visit_extended_port (AST_Extended_Port *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_ExtendedPort ("ExtendedPort");

  // Either locate an existing package, or create a new one.
  Reference ref;
  const GAME::Xml::String name (node->local_name ()->get_string ());

  if (this->parent_->create_if_not (meta_ExtendedPort, ref,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Reference::name, _1)))))
  {
    ref.name (name);
  }

  // Resolve the port type for this port.
  this->handle_symbol_resolution (node->field_type (), ref);

  return 0;
}

//
// visit_mirror_port
//
int Project_Generator::visit_mirror_port (AST_Mirror_Port *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_MirrorPort ("MirrorPort");

  // Either locate an existing package, or create a new one.
  Reference ref;
  const GAME::Xml::String name (node->local_name ()->get_string ());

  if (this->parent_->create_if_not (meta_MirrorPort, ref,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Reference::name, _1)))))
  {
    ref.name (name);
  }

  // Resolve the port type for this port.
  this->handle_symbol_resolution (node->field_type (), ref);

  return 0;
}

//
// visit_connector
//
int Project_Generator::visit_connector (AST_Connector *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building %s...\n"),
                node->flat_name ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::XME::Reference;
  using GAME::Xme_t;

  static const GAME::Xml::String meta_ConnectorObject ("ConnectorObject");

  // Either locate an existing package, or create a new one.
  const GAME::Xml::String name (node->local_name ()->get_string ());
  Model connector;

  if (this->parent_->create_if_not (meta_ConnectorObject, connector,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    connector.name (name);
  }

  // Store the element as a symbol.
  this->symbols_.bind (node, connector);

  // Visit the child elements of this model.
  Auto_Model_T <Model> auto_model (connector);
  int retval = this->visit_scope (node, &auto_model);

  // Lastly, check for any component inheritence.
  AST_Connector * base = node->base_connector ();

  if (0 != base)
  {
    static const GAME::Xml::String meta_ConnectorInherits ("ConnectorInherits");

    Reference ref_inherits;

    if (auto_model.create_if_not (meta_ConnectorInherits, ref_inherits,
        GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                meta_ConnectorInherits,
                                boost::bind (&Reference::kind, _1)))))
    {
      ;
    }

    ref_inherits.name (meta_ConnectorInherits);
    this->handle_symbol_resolution (base, ref_inherits);
  }

  return retval;
}

//
// visit_template_module
//
int Project_Generator::visit_template_module (AST_Template_Module *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building template module %s...\n"),
                node->repoID ()));

  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::XME::Atom;
  using GAME::Xme_t;

  // Let's see if we can find the module in the global map.
  const char * repo_id = node->repoID ();
  Auto_Model_T <Model> * module = 0;

  if (0 != this->current_file_->modules_.find (repo_id, module))
  {
    static const GAME::Xml::String meta_Package ("Package");

    // Either locate an existing package, or create a new one.
    const GAME::Xml::String name (node->local_name ()->get_string ());
    Model package;

    if (this->parent_->create_if_not (meta_Package, package,
        GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                name,
                                boost::bind (&Model::name, _1)))))
    {
      package.name (name);
    }

    // We need to store this package in the global space since it
    // is reentrant. We don't want elements deleted on accident. ;-)
    ACE_NEW_RETURN (module,
                    Auto_Model_T <Model> (package),
                    -1);

    // Save this module to the symbol table.
    this->current_file_->modules_.bind (repo_id, module);
    this->symbols_.bind (node, module->get ());
  }

  // Now, let's add the template parameters to this package.
  FE_Utils::T_PARAMLIST_INFO * params = node->template_params ();
  FE_Utils::T_PARAMLIST_INFO::ITERATOR iter (*params);
  FE_Utils::T_Param_Info * info = 0;

  this->param_mgr_.begin_parameter_set ();

  for (; !iter.done (); iter.advance ())
  {
    // Get the next template parameter.
    iter.next (info);

    switch (info->type_)
    {
    case AST_Type::NT_type:
      this->create_name_parameter (module, info);
      break;

    case AST_Type::NT_sequence:
      this->create_sequence_parameter (module, info);
      break;

    case AST_Type::NT_interface:
      {
        static const GAME::Xml::String meta_Type ("Object");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_eventtype:
      {
        static const GAME::Xml::String meta_Type ("Event");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_valuetype:
      {
        static const GAME::Xml::String meta_Type ("ValueObject");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_enum:
      {
        static const GAME::Xml::String meta_Type ("Enum");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_struct:
      {
        static const GAME::Xml::String meta_Type ("Aggregate");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_union:
      {
        static const GAME::Xml::String meta_Type ("SwitchedAggregate");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_except:
      {
        static const GAME::Xml::String meta_Type ("Exception");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    default:
      ;
    };
  }

  // Order the parameters before adding anymore elements to the
  // model. This is done by arranging the parameters horizontally.
  if (this->param_mgr_.has_parameters ())
    std::for_each (this->param_mgr_.active_parameter_set ()->begin (),
                   this->param_mgr_.active_parameter_set ()->end (),
                   arrange_horizontal (constant::aspect::TemplateParameters, 60, 60, 100));

  // Visit the remaining contents in the module.
  int retval = this->visit_scope (node, module);
  this->param_mgr_.end_parameter_set ();

  return retval;
}

//
// create_name_parameter
//
void Project_Generator::
create_name_parameter (GAME::XME::Auto_Model_T <GAME::XME::Model> * module,
                        FE_Utils::T_Param_Info * info)
{
  // We need to create a named parameter.
  using GAME::XME::Atom;
  using GAME::Xme_t;

  Atom named_parameter;
  GAME::Xml::String param_name (info->name_.c_str ());
  static const GAME::Xml::String meta_NamedParameter ("NameParameter");

  if (module->create_if_not (meta_NamedParameter, named_parameter,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              param_name,
                              boost::bind (&Atom::name, _1)))))
  {
    named_parameter.name (param_name);
  }

  // Save the parameter.
  if (0 != this->param_mgr_.push_back (info, named_parameter))
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - failed to store named parameter %s\n"),
                info->name_.c_str ()));
}

//
// create_type_parameter
//
void Project_Generator::
create_type_parameter (GAME::XME::Auto_Model_T <GAME::XME::Model> * module,
                       FE_Utils::T_Param_Info * info,
                       const GAME::Xml::String & type)
{
  // We need to create a named parameter.
  using GAME::XME::Atom;
  using GAME::Xme_t;

  Atom parameter;
  GAME::Xml::String param_name (info->name_.c_str ());
  static const GAME::Xml::String meta_TypeParameter ("TypeParameter");

  if (module->create_if_not (meta_TypeParameter, parameter,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              param_name,
                              boost::bind (&Atom::name, _1)))))
  {
    parameter.name (param_name);
  }

  static const GAME::Xml::String attr_Type ("Type");
  parameter.attribute (attr_Type, true).value (type);

  // Save the parameter.
  if (0 != this->param_mgr_.push_back (info, parameter))
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - failed to store type parameter %s\n"),
                info->name_.c_str ()));
}

//
// create_sequence_parameter
//
void Project_Generator::
create_sequence_parameter (GAME::XME::Auto_Model_T <GAME::XME::Model> * module,
                           FE_Utils::T_Param_Info * info)
{
  using GAME::XME::Reference;
  using GAME::Xme_t;

  Reference parameter;
  GAME::Xml::String param_name (info->name_.c_str ());
  static const GAME::Xml::String meta_CollectionParameter ("CollectionParameter");

  if (module->create_if_not (meta_CollectionParameter, parameter,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              param_name,
                              boost::bind (&Reference::name, _1)))))
  {
    parameter.name (param_name);
  }

  // Save the parameter.
  if (0 != this->param_mgr_.push_back (info, parameter))
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - failed to store collection parameter %s\n"),
                info->name_.c_str ()));

  // Locate the parameter that we are referencing.
  GAME::XME::FCO target;

  if (this->param_mgr_.find (info->seq_param_ref_.c_str (), target))
    parameter.refers_to (target);
}

//
// visit_param_holder
//
int Project_Generator::visit_param_holder (AST_Param_Holder *node)
{
  return 0;
}

//
// visit_template_module_inst
//
int Project_Generator::visit_template_module_inst (AST_Template_Module_Inst *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building template module instance %s...\n"),
                node->repoID ()));

  // Store the element as a symbol.
  using GAME::XME::Auto_Model_T;
  using GAME::XME::Reference;
  using GAME::XME::Model;
  using GAME::XME::FCO;
  using GAME::Xme_t;

  // Create the template package instance element. Make sure
  // we save it to the symbols for later usage.
  Model module_inst;
  const GAME::Xml::String name (node->local_name ()->get_string ());
  static const GAME::Xml::String meta_TemplatePackageAlias ("TemplatePackageInstance");

  if (this->parent_->create_if_not (meta_TemplatePackageAlias, module_inst,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              name,
                              boost::bind (&Model::name, _1)))))
  {
    module_inst.name (name);
  }

  // At this point, we only care about managing the objects that
  // are in the TemplateParameters aspect.
  std::vector <FCO> parameters;
  module_inst.children (parameters);

  aspect_filter_t <FCO> aspect_filter (constant::aspect::TemplateParameters);

  std::vector <FCO>::iterator end_iter =
    std::remove_if (parameters.begin (),
                    parameters.end (),
                    not_t <aspect_filter_t <FCO> > (aspect_filter));

  Auto_Model_T <Model> * auto_model = 0;
  ACE_NEW_RETURN (auto_model,
                  Auto_Model_T <Model> (module_inst, parameters.begin (), end_iter),
                  -1);

  // Store the module in the current file. We need to make sure we
  // keep it alive as long as we are processing this file.
  this->current_file_->modules_.bind (node->repoID (), auto_model);
  this->symbols_.bind (node, module_inst);

  // Make sure there is a package type in this element. We also need
  // to reference the correct package.
  Reference package_type;
  static const GAME::Xml::String meta_PackageType ("PackageType");

  if (auto_model->create_if_not (meta_PackageType, package_type,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              meta_PackageType,
                              boost::bind (&Reference::kind, _1)))))
  {
    package_type.name (meta_PackageType);
  }

  this->handle_symbol_resolution (node->ref (), package_type);

  // Finally, add the parameters to the listing.
  const FE_Utils::T_ARGLIST * arg_list = node->template_args ();
  FE_Utils::T_ARGLIST::CONST_ITERATOR iter (*arg_list);
  AST_Decl ** decl = 0;

  for (; !iter.done (); iter.advance ())
  {
    // Get the next template parameter.
    iter.next (decl);

    FCO value;

    if (!this->lookup_symbol (*decl, value))
      continue;

    // Make sure we have a template value of this element.
    Reference parameter_value;
    static const GAME::Xml::String meta_TemplateParameterValue ("TemplateParameterValue");

    if (auto_model->create_if_not (meta_TemplateParameterValue, parameter_value,
        GAME::contains <Xme_t> (boost::bind (std::equal_to <FCO> (),
                                value,
                                boost::bind (&Reference::refers_to, _1)))))
    {
      parameter_value.name (meta_TemplateParameterValue);
      parameter_value.refers_to (value);
    }
  }

  // Arrange the template parameters.
  std::for_each (auto_model->children ().begin (),
                 auto_model->children ().end (),
                 arrange_horizontal (constant::aspect::TemplateParameters, 60, 60, 100));

  return 0;
}

//
// visit_template_module_ref
//
int Project_Generator::visit_template_module_ref (AST_Template_Module_Ref *node)
{
  if (be_global->is_debugging_enabled ())
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - building template module reference %s...\n"),
                node->repoID ()));

  using GAME::XME::Auto_Model_T;
  using GAME::XME::Atom;
  using GAME::XME::Model;
  using GAME::XME::Reference;
  using GAME::Xme_t;

  // Let's see if we can find the module in the global map.
  const char * repo_id = node->repoID ();
  Auto_Model_T <Model> * module = 0;
  this->param_mgr_.begin_parameter_set ();

  if (0 != this->current_file_->modules_.find (repo_id, module))
  {
    static const GAME::Xml::String meta_TemplatePackageAlias ("TemplatePackageAlias");

    // Either locate an existing package, or create a new one.
    const GAME::Xml::String name (node->local_name ()->get_string ());
    Model package;

    if (this->parent_->create_if_not (meta_TemplatePackageAlias, package,
        GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                name,
                                boost::bind (&Model::name, _1)))))
    {
      package.name (name);
    }

    // We need to store this package in the global space since it
    // is reentrant. We don't want elements deleted on accident. ;-)
    ACE_NEW_RETURN (module,
                    Auto_Model_T <Model> (package),
                    -1);

    // Save this module to the symbol table.
    this->current_file_->modules_.bind (repo_id, module);
    this->symbols_.bind (node, module->get ());
  }

  // Make sure there is a package type in this element. We also need
  // to reference the correct template module/package.
  Reference package_type;
  static const GAME::Xml::String meta_PackageType ("PackageType");

  if (module->create_if_not (meta_PackageType, package_type,
      GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                              meta_PackageType,
                              boost::bind (&Reference::kind, _1)))))
  {
    package_type.name (meta_PackageType);
  }

  this->handle_symbol_resolution (node->ref (), package_type);

  // Now, let's add the template parameters to this package.
  UTL_StrList * params = node->param_refs ();
  UTL_StrlistActiveIterator iter (params);

  for (; !iter.is_done (); iter.next ())
  {
    static const GAME::Xml::String meta_TemplateParameterReference ("TemplateParameterReference");

    // Get the current string item.
    UTL_String * str = iter.item ();
    const FE_Utils::T_Param_Info * info;

    if (this->param_mgr_.find (str->get_string (), info))
    {
      // Locate the FCO associate with this parameter.
      GAME::XME::Reference param;
      this->param_mgr_.find (str->get_string (), param);

      // Create a new parameter element.
      GAME::XME::Reference param_ref;
      const GAME::Xml::String param_name (str->get_string ());

      if (module->create_if_not (meta_TemplateParameterReference, param_ref,
          GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                  param_name,
                                  boost::bind (&Reference::name, _1)))))
      {
        param_ref.name (param_name);
      }

      // Update the parameter, then store it in the parameter manager.
      param_ref.refers_to (param);

      if (0 != this->param_mgr_.push_back (info, param_ref))
        ACE_ERROR ((LM_ERROR,
                    ACE_TEXT ("%T (%t) - %M - failed to store parameter %s\n"),
                    info->name_.c_str ()));
    }
    else
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("%T (%t) - %M - failed to locate parameter info for %s\n"),
                  str->get_string ()));
  }

  // Order the parameters before adding anymore elements to the
  // model. This is done by arranging the parameters horizontally.
  if (this->param_mgr_.has_parameters ())
    std::for_each (this->param_mgr_.active_parameter_set ()->begin (),
                   this->param_mgr_.active_parameter_set ()->end (),
                   arrange_horizontal (constant::aspect::TemplateParameters, 60, 60, 100));

  this->param_mgr_.end_parameter_set (node);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
// unused methods

int Project_Generator::visit_sequence (AST_Sequence *node){ return 0; }
int Project_Generator::visit_string (AST_String *node){ return 0; }
int Project_Generator::visit_type (AST_Type *node) { return 0; }
int Project_Generator::visit_predefined_type (AST_PredefinedType *node) { return 0; }
