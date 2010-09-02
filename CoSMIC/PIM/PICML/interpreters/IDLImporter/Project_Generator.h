// -*- C++ -*-

//=============================================================================
/**
 * @file      Project_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _IDL_TO_PICML_PROJECT_GENERATOR_H_
#define _IDL_TO_PICML_PROJECT_GENERATOR_H_

#include "ast_visitor.h"
#include "ast_expression.h"
#include "ast_component.h"
#include "game/xme/Folder.h"
#include "game/xme/Auto_Model_T.h"
#include "ace/Hash_Map_Manager.h"
#include "ace/SString.h"
#include "ace/Null_Mutex.h"

// Forward decl.
class UTL_ExceptList;

// Forward decl.
class UTL_IdList;

// Forward decl.
class AST_Finder;

namespace GME
{
namespace XME
{
// Forward decl.
class Project;

// Forward decl.
class Reference;
}
}

/**
 * @struct ACE_Hash <AST_PredefinedType::PredefinedType>
 *
 * Specialization of ACE_Hash for AST_PredefinedType::PredefinedType.
 */
template < >
struct ACE_Hash <AST_PredefinedType::PredefinedType>
{
  unsigned long operator () (const AST_PredefinedType::PredefinedType & t) const
  {
    return t;
  }
};

/**
 * @struct ACE_Hash <AST_Decl *>
 *
 * Specialization of ACE_Hash for AST_Decl *.
 */
template < >
struct ACE_Hash <AST_Decl *>
{
  unsigned long operator () (AST_Decl * t) const
  {
    return static_cast <unsigned long> (reinterpret_cast <uintptr_t> (t));
  }
};

/**
 * @struct ACE_Hash <FE_Utils::T_Param_Info  *>
 *
 * Specialization of ACE_Hash for FE_Utils::T_Param_Info  *.
 */
template < >
struct ACE_Hash <const FE_Utils::T_Param_Info  *>
{
  unsigned long operator () (const FE_Utils::T_Param_Info  * t) const
  {
    return static_cast <unsigned long> (reinterpret_cast <uintptr_t> (t));
  }
};


// Forward decl.
class PICML_File_Creator;

// Forward decl.
class PICML_File_Creator_Item;

// Forward decl.
class Implementation_Generator;

/**
 * @class Project_Generator
 *
 * Visitor for converting IDL to a PICML model.
 */
class Project_Generator : public ast_visitor
{

public:
  Project_Generator (const PICML_File_Creator & fc,
                     Implementation_Generator & impl_gen,
                     GAME::XME::Project & proj);

  virtual ~Project_Generator (void);

  void finalize (void);

  virtual int visit_decl (AST_Decl *d);
  virtual int visit_scope (UTL_Scope *node);
  virtual int visit_type (AST_Type *node);
  virtual int visit_predefined_type (AST_PredefinedType *node);
  virtual int visit_module (AST_Module *node);
  virtual int visit_interface (AST_Interface *node);
  virtual int visit_interface_fwd (AST_InterfaceFwd *node);
  virtual int visit_valuetype (AST_ValueType *node);
  virtual int visit_valuetype_fwd (AST_ValueTypeFwd *node);
  virtual int visit_component (AST_Component *node);
  virtual int visit_component_fwd (AST_ComponentFwd *node);
  virtual int visit_template_module (AST_Template_Module *node);
  virtual int visit_template_module_inst (AST_Template_Module_Inst *node);
  virtual int visit_template_module_ref (AST_Template_Module_Ref *node);
  virtual int visit_porttype (AST_PortType *node);
  virtual int visit_provides (AST_Provides *node);
  virtual int visit_uses (AST_Uses *node);
  virtual int visit_publishes (AST_Publishes *node);
  virtual int visit_emits (AST_Emits *node);
  virtual int visit_consumes (AST_Consumes *node);
  virtual int visit_extended_port (AST_Extended_Port *node);
  virtual int visit_mirror_port (AST_Mirror_Port *node);
  virtual int visit_connector (AST_Connector *node);
  virtual int visit_eventtype (AST_EventType *node);
  virtual int visit_eventtype_fwd (AST_EventTypeFwd *node);
  virtual int visit_home (AST_Home *node);
  virtual int visit_factory (AST_Factory *node);
  virtual int visit_finder (AST_Finder *node);
  virtual int visit_structure (AST_Structure *node);
  virtual int visit_structure_fwd (AST_StructureFwd *node);
  virtual int visit_exception (AST_Exception *node);
  virtual int visit_expression (AST_Expression *node);
  virtual int visit_enum (AST_Enum *node);
  virtual int visit_operation (AST_Operation *node);
  virtual int visit_field (AST_Field *node);
  virtual int visit_argument (AST_Argument *node);
  virtual int visit_attribute (AST_Attribute *node);
  virtual int visit_union (AST_Union *node);
  virtual int visit_union_fwd (AST_UnionFwd *node);
  virtual int visit_union_branch (AST_UnionBranch *node);
  virtual int visit_union_label (AST_UnionLabel *node);
  virtual int visit_constant (AST_Constant *node);
  virtual int visit_enum_val (AST_EnumVal *node);
  virtual int visit_array (AST_Array *node);
  virtual int visit_sequence (AST_Sequence *node);
  virtual int visit_string (AST_String *node);
  virtual int visit_typedef (AST_Typedef *node);
  virtual int visit_root (AST_Root *node);
  virtual int visit_native (AST_Native *node);
  virtual int visit_valuebox (AST_ValueBox *node);
  virtual int visit_param_holder (AST_Param_Holder *node);

private:
  /// Initialize the project.
  void initialize (void);

  void handle_symbol_resolution (AST_Decl * type,
                                 GAME::XME::Reference & ref,
                                 bool use_library = false);

  bool lookup_symbol (AST_Decl * type,
                      GAME::XME::FCO & fco,
                      bool use_library = false);

  bool lookup_symbol_in_template_module (AST_Decl * type,
                                         GAME::XME::FCO & fco,
                                         bool use_library = false);

  bool lookup_symbol (AST_Decl * type,
                      std::vector <GAME::XME::Folder> & lib,
                      GAME::XME::FCO & fco);

  bool lookup_symbol (AST_Decl * type,
                      GAME::XME::Folder & folder,
                      GAME::XME::FCO & fco);

  bool lookup_symbol (UTL_ScopedNameActiveIterator & name_iter,
                      GAME::XME::Model & model,
                      GAME::XME::FCO & fco);

  void visit_exception_list (UTL_ExceptList * list,
                             const GAME::Xml::String & meta,
                             GAME::XME::Auto_Model_T <GAME::XME::Model> & model);

  int visit_scope (UTL_Scope *node,
                   GAME::XME::Auto_Model_T <GAME::XME::Model> * auto_model);

  void create_name_parameter (GAME::XME::Auto_Model_T <GAME::XME::Model> * module,
                              FE_Utils::T_Param_Info * info);

  void create_sequence_parameter (GAME::XME::Auto_Model_T <GAME::XME::Model> * module,
                                  FE_Utils::T_Param_Info * info);

  void create_type_parameter (GAME::XME::Auto_Model_T <GAME::XME::Model> * module,
                              FE_Utils::T_Param_Info * info,
                              const GAME::Xml::String & type);

  /// Collection of files captured in this project.
  const PICML_File_Creator & files_;

  Implementation_Generator & impl_gen_;

  /// Reference to the target project.
  GAME::XME::Project & proj_;

  /// Location where all the IDL files are stored
  GAME::XME::Folder idl_folder_;

  bool is_in_enum_;

  /// The active parent for the visitor.
  GAME::XME::Auto_Model_T <GAME::XME::Model> * parent_;

  /// Collection of predefined elements.
  ACE_Hash_Map_Manager <AST_PredefinedType::PredefinedType,
                        GAME::XME::Atom,
                        ACE_Null_Mutex> predefined_;

  /// Handle to the string predefined type.
  GAME::XME::Atom string_type_;
  GAME::XME::Atom wstring_type_;

  /// Collection of symbols that can be referenced.
  ACE_Hash_Map_Manager <AST_Decl *,
                        GAME::XME::FCO,
                        ACE_Null_Mutex> symbols_;

  /// Collection of symbols that can be referenced.
  ACE_Hash_Map_Manager <ACE_CString,
                        AST_Template_Module_Inst *,
                        ACE_Null_Mutex> template_insts_;

  /// Collection of symbols that can be referenced.
  PICML_File_Creator_Item * current_file_;

  /// Collection of unresolved references.
  ACE_Hash_Map_Manager <GAME::XME::Reference,
                        AST_Decl *,
                        ACE_Null_Mutex> unresolved_;

  /// Collection of template parameters.
  ACE_Hash_Map_Manager <const FE_Utils::T_Param_Info  *,
                        GAME::XME::FCO,
                        ACE_Null_Mutex> params_;

  ACE_Hash_Map_Manager <ACE_CString,
                        GAME::XME::FCO,
                        ACE_Null_Mutex> active_params_;

  GAME::XME::Reference temp_ref_;
};

#include "Project_Generator.inl"

#endif  // !defined _IDL_TO_PICML_PROJECT_GENERATOR_H_
