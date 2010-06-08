// $Id$

#include "Project_Generator.h"
#include "File_Creator.h"
#include "Implementation_Generator.h"

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

#include "global_extern.h"
#include "nr_extern.h"
#include "fe_extern.h"
#include "be_extern.h"

#include "Utils/Point.h"
#include "Utils/xercesc/XercesString.h"

#include "game/xme/Project.h"
#include "game/xme/Connection.h"
#include "game/xme/functional.h"
#include "game/utils/modelgen.h"

#include "ace/OS_NS_stdio.h"

#include "boost/bind.hpp"
#include <functional>

namespace constant
{
namespace meta
{
  static const ::Utils::XStr PREDEFINED_TYPES ("PredefinedTypes");
  static const ::Utils::XStr String ("String");
}

namespace attr
{
  static const ::Utils::XStr abstract ("abstract");
  static const ::Utils::XStr local ("local");
  static const ::Utils::XStr single_destination ("single_destination");
  static const ::Utils::XStr multiple_connections ("multiple_connections");
  static const ::Utils::XStr value ("value");
  static const ::Utils::XStr InterfaceSemantics ("InterfaceSemantics");
}

namespace aspect
{
  static const ::Utils::XStr InterfaceDefinition ("InterfaceDefinition");
  static const ::Utils::XStr TemplateParameters ("TemplateParameters");
}

namespace name
{
  static const ::Utils::XStr PartRegs ("PartRegs");
  static const ::Utils::XStr Position ("Position");
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
  arrange_horizontal (const ::Utils::XStr & aspect,
                      ::Utils::Point & start, 
                      int dx)
    : aspect_ (aspect),
      pt_ (start),
      dx_ (dx)
  {

  }

  void operator () (GAME::XME::FCO & fco)
  {
    // Set the position of the element.
    GAME::XME::set_position (fco,
                             this->aspect_,
                             this->pt_);

    // Advance to the next element.
    this->pt_.shift (this->dx_, 0);
  }

  void operator () (ACE_Hash_Map_Manager <ACE_CString, GAME::XME::FCO, ACE_Null_Mutex>::ENTRY & e)
  {
    // Set the position of the element.
    GAME::XME::set_position (e.item (),
                             this->aspect_,
                             this->pt_);

    // Advance to the next element.
    this->pt_.shift (this->dx_, 0);
  }

private:
  const ::Utils::XStr & aspect_;

  /// The current position
  ::Utils::Point & pt_;

  /// Amount to shift the point y-units
  int dx_;
};

/**
 * @struct arrange_vertical
  *
 * Functor that arranges elements vertically on the screen.
 */
struct arrange_vertical
{
  arrange_vertical (::Utils::Point & start, int dy)
    : pt_ (start),
      dy_ (dy)
  {

  }

  void operator () (GAME::XME::FCO & fco)
  {
    // Set the position of the element.
    GAME::XME::set_position (fco,
                            constant::aspect::InterfaceDefinition,
                            this->pt_);

    // Advance to the next element.
    this->pt_.shift (0, this->dy_);
  }

private:
  /// The current position
  ::Utils::Point & pt_;

  /// Amount to shift the point y-units
  int dy_;
};

///////////////////////////////////////////////////////////////////////////////
// stream operators

//
// operator <<
//
::Utils::XStr &
operator << (::Utils::XStr & str, const AST_Expression::AST_ExprValue & ev)
{
  char buffer[33] = {'\0'};

  switch (ev.et)
  {
  case AST_Expression::EV_short:
    ACE_OS::sprintf (buffer, "%hd", ev.u.sval);
    str = buffer;
    break;

  case AST_Expression::EV_ushort:
    ACE_OS::sprintf (buffer, "%hu", ev.u.usval);
    str = buffer;
    break;

  case AST_Expression::EV_long:
    ACE_OS::sprintf (buffer, "%ld", ev.u.lval);
    str = buffer;
    break;

  case AST_Expression::EV_ulong:
    ACE_OS::sprintf (buffer, "%u", ev.u.ulval);
    str = buffer;
    break;

  case AST_Expression::EV_longlong:
#if ! defined (ACE_LACKS_LONGLONG_T)
    ACE_OS::sprintf (buffer, "%ld", ev.u.llval);
    str = buffer;
#endif /* ! defined (ACE_LACKS_LONGLONG_T) */
    break;

  case AST_Expression::EV_ulonglong:
#if ! defined (ACE_LACKS_LONGLONG_T)
    ACE_OS::sprintf (buffer,
                     ACE_UINT64_FORMAT_SPECIFIER,
                     ev.u.ullval);
    str = buffer;
#endif /* ! defined (ACE_LACKS_LONGLONG_T) */
    break;

  case AST_Expression::EV_bool:
    str = (ev.u.bval ? "TRUE" : "FALSE");
    break;

  case AST_Expression::EV_float:
    ACE_OS::sprintf (buffer, "%f", ev.u.fval);
    str = buffer;
    break;

  case AST_Expression::EV_longdouble:
  case AST_Expression::EV_double:
    ACE_OS::sprintf (buffer, "%0.16G", ev.u.dval);
    str = buffer;
    break;

  case AST_Expression::EV_char:
    ACE_OS::sprintf (buffer, "%c", ev.u.cval);
    str = buffer;
    break;

  case AST_Expression::EV_wchar:
    ACE_OS::sprintf (buffer, "%lc", ev.u.wcval);
    str = buffer;
    break;

  case AST_Expression::EV_octet:
    ACE_OS::sprintf (buffer, "%d", ev.u.oval);
    str = buffer;
    break;

  case AST_Expression::EV_wstring:
    str = ev.u.wstrval;
    break;

  case AST_Expression::EV_string:
    str = ev.u.strval->get_string ();
    break;

  default:
    break;
  }

  return str;
}

//
// operator <<
//
::Utils::XStr & operator << (::Utils::XStr & str, AST_Constant & c)
{
  if (c.et () == AST_Expression::EV_enum)
    // print scoped name
    ;
  else
    str << *c.constant_value ()->ev ();

  return str;
}

//
// operator <<
//
//::Utils::XStr &
//operator << (::Utils::XStr & str, const AST_UnionLabel & label)
//{
//  ACE_CString name;
//
//  AST_Expression *e = label.label_val ();
//  AST_Union *u = AST_Union::narrow_from_scope (s);
//
//  if (ul->label_kind () == AST_UnionLabel::UL_default)
//    {
//      name = "default";
//    }
//  else
//    {
//      if (u->disc_type ()->node_type () == AST_Decl::NT_enum)
//        {
//          UTL_Scope *parent = u->disc_type ()->defined_in ();
//
//          if (0 == parent)
//            {
//              name = this->print_scoped_name (e->n ());
//            }
//          else
//            {
//              if (ScopeAsDecl (parent)->node_type () != AST_Decl::NT_root)
//                {
//                  name =
//                    this->print_scoped_name (
//                      ScopeAsDecl (parent)->name ());
//
//                  name += "::";
//                }
//
//              name += e->n ()->last_component ()->get_string ();
//            }
//        }
//      else
//        {
//          name =
//            this->expr_val_to_string (ul->label_val ()->ev ());
//        }
//    }
//
//  return name;
//}

///////////////////////////////////////////////////////////////////////////////
// Project_Generator class

//
// initialize
//
void Project_Generator::initialize (void)
{
  using GAME::XME::Folder;
  using GAME::XME::Atom;

  Folder root_folder = this->proj_.root_folder ();

  // Make sure the predefined types folder exists.
  Folder types_folder;

  if (GAME::create_if_not (root_folder, constant::meta::PREDEFINED_TYPES, types_folder,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
    {"Byte", {AST_PredefinedType::PT_char, AST_PredefinedType::PT_octet, AST_PredefinedType::PT_wchar, AST_PredefinedType::PT_void}},
    {"LongInteger", {AST_PredefinedType::PT_long, AST_PredefinedType::PT_ulong, AST_PredefinedType::PT_void}},
    {"ShortInteger", {AST_PredefinedType::PT_short, AST_PredefinedType::PT_ushort, AST_PredefinedType::PT_void}},
    {"DoubleNumber", {AST_PredefinedType::PT_double, AST_PredefinedType::PT_longdouble, AST_PredefinedType::PT_void}},
    {"FloatNumber", {AST_PredefinedType::PT_float, AST_PredefinedType::PT_void}},
    {"GenericObject", {AST_PredefinedType::PT_object, AST_PredefinedType::PT_void}},
    {"GenericValue", {AST_PredefinedType::PT_any, AST_PredefinedType::PT_void}},
    {"GenericValueObject", {AST_PredefinedType::PT_value, AST_PredefinedType::PT_void}},
    {0, AST_PredefinedType::PT_void}
  };

  Atom predefined_type;
  ::Utils::XStr metaname;

  for (const predefined_typeinfo * iter = predefined_types;
       iter->metaname_ != 0;
       ++ iter)
  {
    // Tranlate the C string to a XMLString.
    metaname.set (iter->metaname_);

    // Either, create a new element or get the existing one.
    if (GAME::create_if_not (types_folder, metaname, current_types, predefined_type,
        GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  if (GAME::create_if_not (types_folder, constant::meta::String, current_types, this->string_type_,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   constant::meta::String,
                                   boost::bind (&GAME::XME::Atom::name, _1)))))
  {
    this->string_type_.name (constant::meta::String);
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

  std::for_each (this->unresolved_.begin (),
                 this->unresolved_.end (),
                 boost::bind (&Project_Generator::handle_symbol_resolution,
                              this,
                              boost::bind (&unresolved_t::ENTRY::item, _1),
                              boost::bind (&unresolved_t::ENTRY::key, _1)));
}

//
// visit_root
//
int Project_Generator::visit_root (AST_Root * node)
{
  using GAME::XME::Folder;
  using GAME::XME::Model;

#if !defined USE_MCPP_BUFFER_LEXING
  char abspath[MAXPATHLEN];
  ACE_CString fullpath;
#endif

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
    

#if defined USE_MCPP_BUFFER_LEXING
    if (0 != this->files_.files ().find (d->file_name (), this->current_file_))
      continue;
#else
    fullpath = ACE_OS::realpath (d->file_name ().c_str (), abspath);

    if (0 != this->files_.files ().find (fullpath, this->current_file_))
      continue;
#endif

    this->parent_ = &this->current_file_->file_;
    int retval = d->ast_accept (this);

    if (retval != 0)
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%T (%t) - %M - failed to construct %s in %s\n"),
                         d->local_name ()->get_string (),
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
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  if (node->from_inst ())
    return 0;

  // Let's see if we can find the module in the global map.
  const char * repo_id = node->repoID ();
  Auto_Model_T <Model> * module = 0;

  if (0 != this->current_file_->modules_.find (repo_id, module))
  {
    static const ::Utils::XStr meta_Package ("Package");

    // Either locate an existing package, or create a new one.
    const ::Utils::XStr name (node->local_name ()->get_string ());
    Model package;

    if (this->parent_->create_if_not (meta_Package, package,
        GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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

    this->current_file_->modules_.bind (repo_id, module);
  }

  return this->visit_scope (node, module);
}

//
// visit_interface
//
int Project_Generator::visit_interface (AST_Interface *node)
{
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_Object ("Object");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model object;

  if (this->parent_->create_if_not (meta_Object, object,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  this->symbols_.bind (node, object);

  Auto_Model_T <Model> auto_model (object);
  int retval = this->visit_scope (node, &auto_model);

  // Arrange all the child elements veritcally in the model.
  ::Utils::Point start (60, 60);
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (start, 100));

  using GAME::XME::FCO;

  // Check for any interface inheritance.
  static const ::Utils::XStr meta_Inherits ("Inherits");
  long inherits_count = node->n_inherits ();
  AST_Interface ** inherits = node->inherits_flat ();

  for (long i = 0; i < inherits_count; ++ i)
  {
    FCO referred_interface;
   
    if (!this->lookup_symbol (inherits[i], referred_interface))
      continue;

    Reference inherits_ref;

    if (auto_model.create_if_not (meta_Inherits, inherits_ref,
        GAME::contains (boost::bind (std::equal_to <FCO> (),
                                     referred_interface,
                                     boost::bind (&Reference::refers_to, _1)))))
    {
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
  using GAME::XME::Model;

  static const ::Utils::XStr meta_Object ("Object");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model object;

  if (this->parent_->create_if_not (meta_Object, object,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  static const ::Utils::XStr meta_ValueObject ("ValueObject");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model value_object;

  if (this->parent_->create_if_not (meta_ValueObject, value_object,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   name,
                                   boost::bind (&Model::name, _1)))))
  {
    value_object.name (name);
  }

  // Set the attributes for the object.
  value_object.attribute (constant::attr::abstract, true).value (node->is_abstract ());
  value_object.attribute (constant::attr::local, true).value (node->is_local ());

  // Store the element as a symbol.
  this->symbols_.bind (node, value_object);

  // Visit the elements in the structure.
  Auto_Model_T <Model> auto_model (value_object);
  if (-1 == this->visit_scope (node, &auto_model))
    return -1;

  // Align the elements in the structure.
  ::Utils::Point start (60, 60);

  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (start, 100));

  return 0;
}

//
// visit_valuetype_fwd
//
int Project_Generator::visit_valuetype_fwd (AST_ValueTypeFwd *node)
{
  using GAME::XME::Model;

  static const ::Utils::XStr meta_ValueObject ("ValueObject");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model value_object;

  if (this->parent_->create_if_not (meta_ValueObject, value_object,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   name,
                                   boost::bind (&Model::name, _1)))))
  {
    value_object.name (name);
  }

  // Set the attributes for the object.
  value_object.attribute (constant::attr::abstract, true).value (node->is_abstract ());
  value_object.attribute (constant::attr::local, true).value (node->is_local ());

  // Store the element as a symbol.
  this->symbols_.bind (node, value_object);
  return 0;
}

//
// visit_component
//
int Project_Generator::visit_component (AST_Component *node)
{
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_Component ("Component");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model component;

  if (this->parent_->create_if_not (meta_Component, component,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   name,
                                   boost::bind (&Model::name, _1)))))
  {
    component.name (name);
  }

  // Set the attributes for the object.
  //this->parent_.attribute (constant::attr::abstract, true).value (node->is_abstract ());
  //this->parent_.attribute (constant::attr::local, true).value (node->is_local ());

  // Store the element as a symbol.
  this->symbols_.bind (node, component);

  Auto_Model_T <Model> auto_model (component);
  int retval = this->visit_scope (node, &auto_model);

  // Check for any component inheritence.
  AST_Type ** inherits = node->inherits ();

  if (0 != inherits)
  {
    static const ::Utils::XStr meta_CompenentInherits ("ComponentInherits");

    Reference ref_inherits;

    if (auto_model.create_if_not (meta_CompenentInherits, ref_inherits,
        GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                     meta_CompenentInherits,
                                     boost::bind (&Reference::kind, _1)))))
    {
      ;
    }

    ref_inherits.name (meta_CompenentInherits);
    this->handle_symbol_resolution (*inherits, ref_inherits);
  }

  if (0 == retval)
    this->impl_gen_.generate (component);

  return retval;
}

//
// visit_component_fwd
//
int Project_Generator::visit_component_fwd (AST_ComponentFwd *node)
{
  using GAME::XME::Model;

  static const ::Utils::XStr meta_Component ("Component");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model component;

  if (this->parent_->create_if_not (meta_Component, component,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   name,
                                   boost::bind (&Model::name, _1)))))
  {
    component.name (name);
  }

  // Set the attributes for the object.
  //this->parent_.attribute (constant::attr::abstract, true).value (node->is_abstract ());
  //this->parent_.attribute (constant::attr::local, true).value (node->is_local ());

  // Store the element as a symbol.
  this->symbols_.bind (node, component);

  return 0;
}

//
// visit_provides
//
int Project_Generator::visit_provides (AST_Provides *node)
{
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_ProvidedRequestPort ("ProvidedRequestPort");


  // Either locate an existing package, or create a new one.
  Reference ref;
  const ::Utils::XStr name (node->local_name ()->get_string ());

  if (this->parent_->create_if_not (meta_ProvidedRequestPort, ref,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_RequiredRequestPort ("RequiredRequestPort");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Reference ref;

  if (this->parent_->create_if_not (meta_RequiredRequestPort, ref,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   name,
                                   boost::bind (&Reference::name, _1)))))
  {
    ref.name (name);
  }

  ref.attribute (constant::attr::multiple_connections, true).value (!node->is_multiple ());

  // Resolve the event type for this port.
  this->handle_symbol_resolution (node->uses_type (), ref);

  return 0;
}

//
// visit_publishes
//
int Project_Generator::visit_publishes (AST_Publishes *node)
{
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_OutEventPort ("OutEventPort");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Reference ref;

  if (this->parent_->create_if_not (meta_OutEventPort, ref,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_OutEventPort ("OutEventPort");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Reference ref;

  if (this->parent_->create_if_not (meta_OutEventPort, ref,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_InEventPort ("InEventPort");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Reference ref;

  if (this->parent_->create_if_not (meta_InEventPort, ref,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  static const ::Utils::XStr meta_Event ("Event");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model ev;

  if (this->parent_->create_if_not (meta_Event, ev,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  ::Utils::Point start (60, 60);

  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (start, 100));

  return 0;
}

//
// visit_eventtype_fwd
//
int Project_Generator::visit_eventtype_fwd (AST_EventTypeFwd *node)
{
  using GAME::XME::Model;

  static const ::Utils::XStr meta_Event ("Event");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model ev;

  if (this->parent_->create_if_not (meta_Event, ev,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  static const ::Utils::XStr meta_ComponentFactory ("ComponentFactory");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model component_factory;

  if (this->parent_->create_if_not (meta_ComponentFactory, component_factory,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   name,
                                   boost::bind (&Model::name, _1)))))
  {
    component_factory.name (name);
  }

  // Add a LookupKey to the element, if applicable.
  AST_Type * primary_key = node->primary_key ();

  if (0 != primary_key)
  {
    static const ::Utils::XStr meta_LookupKey ("LookupKey");

    using GAME::XME::Reference;
    Reference lookup_key;

    this->parent_->create_if_not (meta_LookupKey, lookup_key,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  static const ::Utils::XStr meta_ManagesComponent ("ManagesComponent");

  if (!GAME::find (this->parent_->get (), meta_ManagesComponent, manages,
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
  Auto_Model_T <Model> auto_clean (component_factory);
  return this->visit_scope (node, &auto_clean);
}

//
// visit_factory
//
int Project_Generator::visit_factory (AST_Factory *node)
{
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  static const ::Utils::XStr meta_FactoryOperation ("FactoryOperation");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model factory_op;

  if (this->parent_->create_if_not (meta_FactoryOperation, factory_op,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   name,
                                   boost::bind (&Model::name, _1)))))
  {
    factory_op.name (name);
  }

  Auto_Model_T <Model> auto_model (factory_op);
  if (0 != this->visit_scope (node, &auto_model))
    return -1;

  // Align the elements in the structure.
  ::Utils::Point start (60, 60);

  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_horizontal (constant::aspect::InterfaceDefinition, start, 100));

  return 0;
}

//
// visit_finder
//
int Project_Generator::visit_finder (AST_Finder *node)
{
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  static const ::Utils::XStr meta_LookupOperation ("LookupOperation");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model lookup_op;

  if (this->parent_->create_if_not (meta_LookupOperation, lookup_op,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   name,
                                   boost::bind (&Model::name, _1)))))
  {
    lookup_op.name (name);
  }

  Auto_Model_T <Model> auto_model (lookup_op);
  if (0 != this->visit_scope (node, &auto_model))
    return -1;

  // Align the elements in the structure.
  ::Utils::Point start (60, 60);

  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_horizontal (constant::aspect::InterfaceDefinition, start, 100));

  return 0;
}

//
// visit_structure
//
int Project_Generator::visit_structure (AST_Structure *node)
{
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  static const ::Utils::XStr meta_Aggregate ("Aggregate");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model aggregate;

  if (this->parent_->create_if_not (meta_Aggregate, aggregate,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  ::Utils::Point start (60, 60);

  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (start, 100));

  return 0;
}

//
// visit_structure_fwd
//
int Project_Generator::visit_structure_fwd (AST_StructureFwd *node)
{
  using GAME::XME::Model;

  static const ::Utils::XStr meta_Aggregate ("Aggregate");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model aggregate;

  if (this->parent_->create_if_not (meta_Aggregate, aggregate,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  static const ::Utils::XStr meta_Exception ("Exception");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model exception;

  if (this->parent_->create_if_not (meta_Exception, exception,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  static const ::Utils::XStr meta_Enum ("Enum");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model enumeration;

  if (this->parent_->create_if_not (meta_Enum, enumeration,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  ::Utils::Point start (60, 60);

  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (start, 100));

  return 0;
}

//
// visit_enum_val
//
int Project_Generator::visit_enum_val (AST_EnumVal *node)
{
  using GAME::XME::Atom;

  // Either locate an existing package, or create a new one.
  Atom value;
  const ::Utils::XStr name (node->local_name ()->get_string ());
  static const ::Utils::XStr meta_EnumValue ("EnumValue");

  if (this->parent_->create_if_not (meta_EnumValue, value,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  Model operation;
  const ::Utils::XStr name (node->local_name ()->get_string ());

  if (node->flags () == AST_Operation::OP_oneway)
  {
    // Create, or locate, a oneway operation.
    static const ::Utils::XStr meta_OnewayOperation ("OnewayOperation");

    if (this->parent_->create_if_not (meta_OnewayOperation, operation,
        GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                     name,
                                     boost::bind (&Model::name, _1)))))
    {
      operation.name (name);
    }
  }
  else
  {
    // Create, or locate, a twoway operation.
    static const ::Utils::XStr meta_TwowayOperation ("TwowayOperation");

    if (this->parent_->create_if_not (meta_TwowayOperation, operation,
        GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
    static const ::Utils::XStr meta_ReturnType ("ReturnType");

    if (auto_model.create_if_not (meta_ReturnType, return_type,
        GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  static const ::Utils::XStr meta_Exception ("ExceptionRef");
  this->visit_exception_list (node->exceptions (), meta_Exception, auto_model);

  // Finally, short all the element in <auto_model> horizontally.
  ::Utils::Point start (60, 60);
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_horizontal (constant::aspect::InterfaceDefinition, start, 100));
  return 0;
}

//
// visit_field
//
int Project_Generator::visit_field (AST_Field *node)
{
  using GAME::XME::Reference;

  // Locate the concrete type in the symbol table.
  const ::Utils::XStr field_name (node->local_name ()->get_string ());
  AST_Type * type = node->field_type ();

  // Get the current packages in this model.
  static const ::Utils::XStr meta_Member ("Member");

  // Either locate the existing Member element, or create a new
  // one for the field.

  Reference member;
  if (this->parent_->create_if_not (meta_Member, member,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   field_name,
                                   boost::bind (&Reference::name, _1)))))
  {
    member.name (field_name);
  }

  // Locate the target FCO that will be referenced.
  this->handle_symbol_resolution (type, member);

  return 0;
}

//
// visit_attribute
//
int Project_Generator::visit_attribute (AST_Attribute *node)
{
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  Model attribute;
  const ::Utils::XStr name (node->local_name ()->get_string ());

  if (node->readonly ())
  {
    // We need to create a ReadonlyAttribute for the model.
    static const ::Utils::XStr meta_ReadonlyAttribute ("ReadonlyAttribute");

    if (this->parent_->create_if_not (meta_ReadonlyAttribute, attribute,
        GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                     name,
                                     boost::bind (&Model::name, _1)))))
    {
      attribute.name (name);
    }
  }
  else
  {
    // We need to create an Attribute for the model.
    static const ::Utils::XStr meta_Attribute ("Attribute");

    if (this->parent_->create_if_not (meta_Attribute, attribute,
        GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                     name,
                                     boost::bind (&Model::name, _1)))))
    {
      attribute.name (name);
    }
  }

  Auto_Model_T <GAME::XME::Model> auto_model (attribute);

  // Set the reference element for the attribute's type.
  static const ::Utils::XStr meta_AttributeMember ("AttributeMember");

  using GAME::XME::Reference;
  Reference attribute_member;
  std::vector <Reference> attribute_members;

  auto_model.create_if_not (meta_AttributeMember, attribute_member,
                            GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                            meta_AttributeMember,
                                            boost::bind (&Reference::kind, _1))));

  this->handle_symbol_resolution (node->field_type (), attribute_member);

  // Handle the *get* exceptions for this element.
  static const ::Utils::XStr meta_GetException ("GetException");
  this->visit_exception_list (node->get_get_exceptions (),
                              meta_GetException,
                              auto_model);

  if (!node->readonly ())
  {
    // Handle the *set* exceptions for this element since it is
    // not a readonly attribute.
    static const ::Utils::XStr meta_SetException ("SetException");
    this->visit_exception_list (node->get_set_exceptions (),
                                meta_SetException,
                                auto_model);
  }


  // Finally, arrange the elements in horizontal order.
  ::Utils::Point start (60, 60);
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_horizontal (constant::aspect::InterfaceDefinition, start, 100));

  return 0;
}

//
// visit_argument
//
int Project_Generator::visit_argument (AST_Argument *node)
{
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_list[5] =
  {
    ::Utils::XStr::EMPTY_STRING,
    "InParameter",
    "OutParameter",
    ::Utils::XStr::EMPTY_STRING,
    "InoutParameter"
  };

  // Initialize the typename for the argument.
  const ::Utils::XStr * meta = &meta_list[node->direction ()];
  const ::Utils::XStr name (node->local_name ()->get_string ());

  // Create the argument if it does not exist.
  Reference argument;
  if (this->parent_->create_if_not (*meta, argument,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Model;
  using GAME::XME::FCO;
  using GAME::XME::Auto_Model_T;

  static const ::Utils::XStr meta_SwitchedAggregate ("SwitchedAggregate");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model switched_aggregate;

  if (this->parent_->create_if_not (meta_SwitchedAggregate, switched_aggregate,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  static const ::Utils::XStr meta_Discriminator ("Discriminator");

  if (auto_model.create_if_not (meta_Discriminator, discriminator,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  ::Utils::Point start (60, 60);

  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (start, 100));

  return 0;
}

//
// visit_union_fwd
//
int Project_Generator::visit_union_fwd (AST_UnionFwd *node)
{
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  static const ::Utils::XStr meta_SwitchedAggregate ("SwitchedAggregate");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model switched_aggregate;

  if (this->parent_->create_if_not (meta_SwitchedAggregate, switched_aggregate,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_Member ("Member");
  const ::Utils::XStr name (node->local_name ()->get_string ());

  Reference branch;
  if (this->parent_->create_if_not (meta_Member, branch,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   name,
                                   boost::bind (&Reference::name, _1)))))
  {
    branch.name (name);
  }

  this->handle_symbol_resolution (node->field_type (), branch);

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
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_Constant ("Constant");
  const ::Utils::XStr name (node->local_name ()->get_string ());

  Reference constant;
  if (this->parent_->create_if_not (meta_Constant, constant,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
    AST_PredefinedType::PT_short,
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
  constant.refers_to (fco);

  // Last, we need to set the value of the constant.
  ::Utils::XStr value;
  value << *node;

  constant.attribute (constant::attr::value, true).value (value);

  return 0;
}

//
// visit_typedef
//
int Project_Generator::visit_typedef (AST_Typedef *node)
{
  AST_Type * base_type = node->base_type ();

  static const ::Utils::XStr meta_list[2] =
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

  Reference alias;
  const ::Utils::XStr name (node->local_name ()->get_string ());

  if (this->parent_->create_if_not (meta_list[index], alias,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_Boxed ("Boxed");
  const ::Utils::XStr name (node->local_name ()->get_string ());

  Reference boxed;
  if (this->parent_->create_if_not (meta_Boxed, boxed,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
                      const ::Utils::XStr & meta,
                      GAME::XME::Auto_Model_T <GAME::XME::Model> & model)
{
  using GAME::XME::Reference;
  using GAME::XME::FCO;

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
          GAME::contains (boost::bind (std::equal_to <FCO> (),
                                       fco,
                                       boost::bind (&Reference::refers_to, _1)))))
      {
        exception.refers_to (fco);
      }
    }
  }
}

//
// lookup_symbol
//
bool Project_Generator::lookup_symbol (AST_Decl * type, GAME::XME::FCO & fco)
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
  }
  else if (node_type == AST_Decl::NT_string || node_type == AST_Decl::NT_wstring)
  {
    fco = this->string_type_;
  }
  else if (node_type == AST_Decl::NT_param_holder)
  {
    AST_Param_Holder * param = dynamic_cast <AST_Param_Holder *> (type);
    const FE_Utils::T_Param_Info * info = param->info ();

    if (0 != this->params_.find (param->info (), fco))
      return false;
  }
  else
  {
    // Locate the type in the symbol table.
    if (0 != this->symbols_.find (type, fco))
      return false;
  }

  return true;
}

//
// handle_symbol_resolution
//
void Project_Generator::
handle_symbol_resolution (AST_Decl * type, GAME::XME::Reference & ref)
{
  GAME::XME::FCO fco;

  if (this->lookup_symbol (type, fco))
    ref.refers_to (fco);
  else
    this->unresolved_.bind (ref, type);
}

///////////////////////////////////////////////////////////////////////////////
// IDL 3+

//
// visit_porttype
//
int Project_Generator::visit_porttype (AST_PortType *node)
{
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;

  static const ::Utils::XStr meta_PortType ("PortType");

  // Either locate an existing package, or create a new one.
  Model porttype;
  const ::Utils::XStr name (node->local_name ()->get_string ());

  if (this->parent_->create_if_not (meta_PortType, porttype,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  ::Utils::Point start (60, 60);
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_vertical (start, 100));

  return 0;
}

//
// visit_extended_port
//
int Project_Generator::visit_extended_port (AST_Extended_Port *node)
{ 
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_ExtendedPort ("ExtendedPort");

  // Either locate an existing package, or create a new one.
  Reference ref;
  const ::Utils::XStr name (node->local_name ()->get_string ());

  if (this->parent_->create_if_not (meta_ExtendedPort, ref,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_MirrorPort ("MirrorPort");

  // Either locate an existing package, or create a new one.
  Reference ref;
  const ::Utils::XStr name (node->local_name ()->get_string ());

  if (this->parent_->create_if_not (meta_MirrorPort, ref,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::XME::Reference;

  static const ::Utils::XStr meta_ConnectorObject ("ConnectorObject");

  // Either locate an existing package, or create a new one.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  Model connector;

  if (this->parent_->create_if_not (meta_ConnectorObject, connector,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  AST_Type ** inherits = node->inherits ();

  if (0 != inherits)
  {
    static const ::Utils::XStr meta_ConnectorInherits ("ConnectorInherits");

    Reference ref_inherits;

    if (auto_model.create_if_not (meta_ConnectorInherits, ref_inherits,
        GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                     meta_ConnectorInherits,
                                     boost::bind (&Reference::kind, _1)))))
    {
      ;
    }

    ref_inherits.name (meta_ConnectorInherits);
    this->handle_symbol_resolution (*inherits, ref_inherits);
  }

  //if (0 == retval)
  //  this->impl_gen_.generate (component);

  return retval;  
}

//
// visit_template_module
//
int Project_Generator::visit_template_module (AST_Template_Module *node)
{ 
  using GAME::XME::Model;
  using GAME::XME::Auto_Model_T;
  using GAME::XME::Atom;

  // Let's see if we can find the module in the global map.
  const char * repo_id = node->repoID ();
  Auto_Model_T <Model> * module = 0;

  if (0 != this->current_file_->modules_.find (repo_id, module))
  {
    static const ::Utils::XStr meta_Package ("Package");

    // Either locate an existing package, or create a new one.
    const ::Utils::XStr name (node->local_name ()->get_string ());
    Model package;

    if (this->parent_->create_if_not (meta_Package, package,
        GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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

    this->current_file_->modules_.bind (repo_id, module);

    // Save this module to the symbol table.
    this->symbols_.bind (node, module->get ());
  }

  // Now, let's add the template parameters to this package.
  FE_Utils::T_PARAMLIST_INFO * params = node->template_params ();
  FE_Utils::T_PARAMLIST_INFO::ITERATOR iter (*params);
  FE_Utils::T_Param_Info * info = 0;

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
        static const ::Utils::XStr meta_Type ("Object");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_eventtype:
      {
        static const ::Utils::XStr meta_Type ("Event");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_valuetype:
      {
        static const ::Utils::XStr meta_Type ("ValueObject");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_enum:
      {
        static const ::Utils::XStr meta_Type ("Enum");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_struct: 
      {
        static const ::Utils::XStr meta_Type ("Aggregate");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_union: 
      {
        static const ::Utils::XStr meta_Type ("SwitchedAggregate");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;

    case AST_Type::NT_except: 
      {
        static const ::Utils::XStr meta_Type ("Exception");
        this->create_type_parameter (module, info, meta_Type);
      }
      break;
    };
  }

  // Order the parameters before adding anymore elements to the 
  // model. This is done by arranging the parameters horizontally.
  ::Utils::Point start (60, 60);
  std::for_each (this->active_params_.begin (),
                 this->active_params_.end (),
                 arrange_horizontal (constant::aspect::TemplateParameters, start, 100));

  // We are finish with there parameters.
  this->active_params_.unbind_all ();

  // Visit the remaining contents in the module.
  return this->visit_scope (node, module);
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
  
  Atom named_parameter;
  ::Utils::XStr param_name (info->name_.c_str ());
  static const ::Utils::XStr meta_NamedParameter ("NameParameter");

  if (module->create_if_not (meta_NamedParameter, named_parameter,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   param_name,
                                   boost::bind (&Atom::name, _1)))))
  {
    named_parameter.name (param_name);
  }

  // Save the parameter.
  this->params_.bind (info, named_parameter);
  this->active_params_.bind (info->name_, named_parameter);
}

//
// create_type_parameter
//
void Project_Generator::
create_type_parameter (GAME::XME::Auto_Model_T <GAME::XME::Model> * module,
                       FE_Utils::T_Param_Info * info,
                       const ::Utils::XStr & type)
{
  // We need to create a named parameter.
  using GAME::XME::Atom;
  
  Atom parameter;
  ::Utils::XStr param_name (info->name_.c_str ());
  static const ::Utils::XStr meta_TypeParameter ("TypeParameter");

  if (module->create_if_not (meta_TypeParameter, parameter,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   param_name,
                                   boost::bind (&Atom::name, _1)))))
  {
    parameter.name (param_name);
  }

  static const ::Utils::XStr attr_Type ("Type");
  parameter.attribute (attr_Type, true).value (type);

  // Save the parameter.
  this->params_.bind (info, parameter);
  this->active_params_.bind (info->name_, parameter);
}

//
// create_sequence_parameter
//
void Project_Generator::
create_sequence_parameter (GAME::XME::Auto_Model_T <GAME::XME::Model> * module,
                           FE_Utils::T_Param_Info * info)
{
  using GAME::XME::Reference;
  
  Reference parameter;
  ::Utils::XStr param_name (info->name_.c_str ());
  static const ::Utils::XStr meta_CollectionParameter ("CollectionParameter");

  if (module->create_if_not (meta_CollectionParameter, parameter,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   param_name,
                                   boost::bind (&Reference::name, _1)))))
  {
    parameter.name (param_name);
  }

  // Save the parameter.
  this->params_.bind (info, parameter);
  this->active_params_.bind (info->name_, parameter);

  // Locate the parameter that we are referencing.
  GAME::XME::FCO target;

  if (0 == this->active_params_.find (info->seq_param_ref_, target))
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
  // Store the element as a symbol.
  using GAME::XME::Auto_Model_T;
  using GAME::XME::Reference;
  using GAME::XME::Model;
  using GAME::XME::FCO;

  Model module_inst;

  // Create the template package alias.
  const ::Utils::XStr name (node->local_name ()->get_string ());
  static const ::Utils::XStr meta_TemplatePackageAlias ("TemplatePackageInstance");

  if (this->parent_->create_if_not (meta_TemplatePackageAlias, module_inst,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   name,
                                   boost::bind (&Model::name, _1)))))
  {
    module_inst.name (name);
  }

  Auto_Model_T <Model> auto_model (module_inst);

  // Make sure there is a package type in this element. We also need
  // to reference the correct package.
  Reference package_type;
  static const ::Utils::XStr meta_PackageType ("PackageType");

  if (auto_model.create_if_not (meta_PackageType, package_type,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   meta_PackageType,
                                   boost::bind (&Reference::kind, _1)))))
  {
    package_type.name (meta_PackageType);
  }

  this->handle_symbol_resolution (node->ref (), package_type);

  // Finally, add the parameters to the listing.
  FE_Utils::T_ARGLIST * arg_list = node->template_args ();
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
    static const ::Utils::XStr meta_TemplateParameterValue ("TemplateParameterValue");

    if (auto_model.create_if_not (meta_TemplateParameterValue, parameter_value,
        GAME::contains (boost::bind (std::equal_to <FCO> (),
                                     value,
                                     boost::bind (&Reference::refers_to, _1)))))
    {
      parameter_value.name (meta_TemplateParameterValue);
      parameter_value.refers_to (value);
    }
  }

  // Arrange the template parameters.
  ::Utils::Point start (60, 60);
  std::for_each (auto_model.children ().begin (),
                 auto_model.children ().end (),
                 arrange_horizontal (constant::aspect::TemplateParameters, start, 100));

  return 0; 
}

//
// visit_template_module_ref
//
int Project_Generator::visit_template_module_ref (AST_Template_Module_Ref *node)
{ 
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
// unused methods

int Project_Generator::visit_native (AST_Native *node){ return 0; }
int Project_Generator::visit_array (AST_Array *node){ return 0; }
int Project_Generator::visit_sequence (AST_Sequence *node){ return 0; }
int Project_Generator::visit_string (AST_String *node){ return 0; }
int Project_Generator::visit_type (AST_Type *node) { return 0; }
int Project_Generator::visit_predefined_type (AST_PredefinedType *node) { return 0; }
