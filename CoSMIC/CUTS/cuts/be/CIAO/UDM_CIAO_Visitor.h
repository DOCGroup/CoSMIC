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

#include <fstream>
#include <list>
#include <map>
#include <stack>

// Forward decl.
class CUTS_Dependency_Graph;
class CUTS_Dependency_Node;

namespace CUTS
{
  //===========================================================================
  /**
   * @class UDM_CIAO_Visitor
   *
   * @brief Code generator for the CIAO backend from UDM models.
   */
  //===========================================================================

  class CUTS_UDM_CIAO_Export UDM_CIAO_Visitor : public PICML::Visitor
  {
  public:
    /**
     * Intializing constructor.
     *
     * @param[in]     outdir      Output directory for the source code.
     * @param[in]     graph       Dependency graph for the model.
     */
    UDM_CIAO_Visitor (const std::string & outdir,
                      const CUTS_Dependency_Graph & graph);

    /// Destructor.
    virtual ~UDM_CIAO_Visitor (void);

  protected:
    /// Visit the RootFolder of a PICML model.
    void Visit_RootFolder (const PICML::RootFolder &);

    /// Visit the InterfaceDefinitions folder in a PICML model.
    void Visit_InterfaceDefinitions (const PICML::InterfaceDefinitions & );

    /// Visit a File in a PICML model.
    void Visit_File (const PICML::File &);

    /// Visit a Package in the PICML model.
    void Visit_Package (const PICML::Package &);

    /// Visit a Component in the PICML model.
    void Visit_Component (const PICML::Component &);

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

  private:
    void visit_file_package_contents (const Udm::Object &);

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

    void reset_component_info (void);

    void reset_file_info (void);

    /// Output directory for the source files.
    std::string outdir_;

    /// The constructed dependency graph for the model.
    const CUTS_Dependency_Graph & dependency_graph_;

    /// The current node in the graph.
    const CUTS_Dependency_Node * node_;

    /// Output stream for the header file.
    std::ofstream hout_;

    /// Output stream for the source file.
    std::ofstream sout_;

    /// Output stream for the workspace file.
    std::ofstream wout_;

    /// Name of the current component.
    std::string component_;


    typedef std::set <std::string> String_Set;

    String_Set event_sinks_;

    String_Set event_types_;

    String_Set file_depends_;

    bool has_out_events_;

    std::string temp_str_;

    std::string function_;

    std::string current_file_;

    typedef std::list <std::string> Scope_List;

    typedef std::map <std::string, std::string> Event_Map;

    //const File_Configuration_Map::const_iterator file_config_;

    Event_Map event_map_;

    Scope_List scope_;

    bool has_activate_;

    bool exclude_executor_;

    std::stack <PICML::InputActionBase> call_stack_;

    std::stack <PICML::State> holding_state_;

    bool ignore_effects_;

    size_t depth_;
  };
}

#endif  // !defined _CUTS_UDM_CIAO_VISITOR_H_
