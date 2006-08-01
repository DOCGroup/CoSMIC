// -*- C++ -*-

//=============================================================================
/**
 * @file    UDM_CIAO_Visitor.h
 *
 * @brief   Defines the UDM_CIAO_Visitor object
 *
 * $Id$
 *
 * @author  James H. Hill
 */
//=============================================================================

#ifndef _CUTS_UDM_CIAO_VISITOR_H_
#define _CUTS_UDM_CIAO_VISITOR_H_

#include "PICML/PICML.h"
#include "UDM_CIAO_Export.h"
#include "String_Set.h"
#include <fstream>
#include <list>
#include <map>
#include <stack>

// Forward decl.
class CUTS_Dependency_Graph;

// Forward decl.
class CUTS_Dependency_Node;

//===========================================================================
/**
  * @class UDM_CIAO_Visitor
  *
  * @brief Code generator for the CIAO backend from UDM models.
  */
//===========================================================================

class CUTS_UDM_CIAO_Export CUTS_UDM_CIAO_Visitor : public PICML::Visitor
{
public:
  /**
    * Intializing constructor.
    *
    * @param[in]        outdir      Output directory for the source code.
    * @param[out]       impls       Collection of generated implemenations.
    * @param[inout]     graph       Dependency graph for the model.
    */
  CUTS_UDM_CIAO_Visitor (const std::string & outdir,
                         CUTS_Dependency_Graph & impls,
                         const CUTS_Dependency_Graph & graph);

  /// Destructor.
  virtual ~CUTS_UDM_CIAO_Visitor (void);

protected:
  /// Visit the RootFolder of a PICML model.
  void Visit_RootFolder (const PICML::RootFolder &);

  /// Visit a Component in the PICML model.
  void Visit_Component (const PICML::Component &);

  /// Visit a Component in the PICML model.
  void Visit_ComponentRef (const PICML::ComponentRef &);

  void Visit_WorkerType (const PICML::WorkerType &);

  void Visit_Worker (const PICML::Worker &);

  void Visit_InEventPort (const PICML::InEventPort &);

  void Visit_Event (const PICML::Event &);

  void Visit_Input (const PICML::Input &);

  void Visit_InputAction (const PICML::InputAction &);

  void Visit_State (const PICML::State &);

  void Visit_Effect (const PICML::Effect &);

  void Visit_Transition (const PICML::Transition &);

  void Visit_Action (const PICML::Action &);

  void Visit_Property (const PICML::Property &);

  void Visit_String (const PICML::String &);

  void Visit_LongInteger (const PICML::LongInteger &);

  void Visit_ManagesComponent (const PICML::ManagesComponent &);

  void Visit_ComponentFactory (const PICML::ComponentFactory &);

  void Visit_OutEventPort (const PICML::OutEventPort &);

  void Visit_PeriodicAction (const PICML::PeriodicAction &);

  void Visit_OutputAction (const PICML::OutputAction &);

  void Visit_Environment (const PICML::Environment &);

  void Visit_CompositeAction (const PICML::CompositeAction &);

  void Visit_Variable (const PICML::Variable &);

  void Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort &);

  void Visit_Object (const PICML::Object &);

  void Visit_ComponentImplementations (
    const PICML::ComponentImplementations &);

  void Visit_ComponentImplementationContainer (
    const PICML::ComponentImplementationContainer &);

  void Visit_MonolithicImplementation (
    const PICML::MonolithicImplementation &);

  void Visit_Implements (const PICML::Implements &);

private:
  void generate_constructor (void);

  void generate_destructor (void);

  void generate_member_variables (const PICML::Component &);

  void generate_init (const PICML::Component & component);

  void generate_fini (const PICML::Component & component);

  void generate_set_session_context (const PICML::Component &);

  void generate_ciao_preactivate (const PICML::Component &);

  void generate_ccm_activate (const PICML::Component &);

  void generate_ciao_postactivate (const PICML::Component &);

  void generate_ccm_passivate (const PICML::Component &);

  void generate_ccm_remove (const PICML::Component &);

  void generate_scope (const std::string & seperator);

  void generate_scope (const PICML::MgaObject &);

  void generate_factory (const std::string & factory);

  void reset_component_info (void);

  void reset_file_info (void);

  /// Get the dependency node of a component.
  CUTS_Dependency_Node * get_dependency_node (const PICML::Component &);

  /// Output directory for the source files.
  std::string outdir_;

  /// The constructed implementation graph for the model.
  CUTS_Dependency_Graph & impls_;

  /// The current implementation node.
  CUTS_Dependency_Node * impl_node_;

  /// The constructed dependency graph for the model.
  const CUTS_Dependency_Graph & dependency_graph_;

  /// Output stream for the header file.
  std::ofstream hout_;

  /// Output stream for the source file.
  std::ofstream sout_;

  /// Output stream for the workspace file.
  std::ofstream wout_;

  /// Name of the current component.
  std::string component_;

  std::string container_;

  std::string monolithic_;

  typedef std::set <std::string> CUTS_String_Set;

  CUTS_String_Set event_sinks_;

  CUTS_String_Set event_types_;

  CUTS_String_Set file_depends_;

  bool has_out_events_;

  std::string temp_str_;

  typedef std::list <std::string> Scope_List;

  typedef std::map <std::string, std::string> Event_Map;

  Event_Map event_map_;

  Scope_List scope_;

  bool has_activate_;

  std::stack <PICML::InputActionBase> call_stack_;

  std::stack <PICML::State> holding_state_;

  bool ignore_effects_;

  size_t depth_;

  bool generated_factory_;
};

#endif  // !defined _CUTS_UDM_CIAO_VISITOR_H_
