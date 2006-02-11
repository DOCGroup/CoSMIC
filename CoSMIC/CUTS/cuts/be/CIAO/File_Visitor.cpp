// $Id$

#include "cuts/be/CIAO/File_Visitor.h"
#include "cuts/pir/Action_Property.h"
#include "cuts/pir/File.h"
#include "cuts/pir/Component.h"
#include "cuts/pir/ComponentHome.h"
#include "cuts/pir/Event.h"
#include "cuts/pir/Event_Source.h"
#include "cuts/pir/EventSink.h"
#include "cuts/pir/Facet.h"
#include "cuts/pir/Method.h"
#include "cuts/pir/Object.h"
#include "cuts/pir/Output_Action.h"
#include "cuts/pir/Periodic_Action.h"
#include "cuts/pir/Worker.h"
#include "cuts/pir/Worker_Action.h"
#include "cuts/pir/Worker_Type.h"

#include "cuts/utils/String.h"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#include <strstream>
#include <functional>
#include <algorithm>

// Suffix appended to all port agents.
static const char * PORT_AGENT_SUFFIX = "_port_agent_";

namespace CUTS_CIAO
{
  //===========================================================================
  /**
   * @struct Print_Functor_Base
   *
   * This functor is the base for all functors that print to a
   * output stream.
   */
  //===========================================================================

  struct Print_Functor_Base
  {
    //
    // Print_Functor_Base
    //
    Print_Functor_Base (std::ofstream & out)
      : out_ (out)
    {

    }

  protected:
    /// Output stream for the functor.
    std::ofstream & out_;
  };

  //===========================================================================
  /**
   * @struct Print_Include
   *
   * This functor prints the appropriate include file.
   */
  //===========================================================================

  struct Print_Include :
    public Print_Functor_Base
  {
    //
    // Print_Include
    //
    Print_Include (std::ofstream &out)
      : Print_Functor_Base (out)
    {

    }

    //
    // operator ()
    //
    void operator () (const std::string & include)
    {
      this->out_ << "#include \"" << include << "\"" << std::endl;
    }
  };

  //===========================================================================
  /**
   * @struct Print_Register_Port_Agent
   *
   * This functor prints the method for registering a port agent
   * with the benchmark agent for a CoWorkEr.
   */
  //===========================================================================

  struct Print_Register_Port_Agent :
    public Print_Functor_Base
  {
    //
    // Print_Register_Port_Agent
    //
    Print_Register_Port_Agent (std::ofstream & out)
      : Print_Functor_Base (out)
    {

    }

    //
    // operator ()
    //
    void operator () (const CUTS_PIR::Event_Sink * event_sink)
    {
      this->out_
        << "this->benchmark_agent_->register_port_agent (&this->push_"
        << event_sink->name () << PORT_AGENT_SUFFIX << ");";
    }
  };

  //===========================================================================
  /**
   * @struct Bind_Register_Port_Agent
   */
  //===========================================================================

  struct Register_Bind_Port_Agent :
    public Print_Functor_Base
  {
    //
    // Print_Register_Port_Agent
    //
    Register_Bind_Port_Agent (std::ofstream & out, const std::string & component)
      : Print_Functor_Base (out),
        register_functor_ (out),
        component_ (component)
    {

    }

    //
    // operator ()
    //
    void operator () (const CUTS_PIR::Event_Sink * event_sink)
    {
      // Print the registration method.
      this->register_functor_ (event_sink);

      // Print the binding method.
      this->out_
        << "this->push_" << event_sink->name () << "_event_handler_.bind ("
        << std::endl << "\t&this->push_" << event_sink->name ()
        << PORT_AGENT_SUFFIX << "," << std::endl
        << "\t&" << this->component_ << "::"
        << "push_" << event_sink->name () << "_event_handler);";
    }

  private:
   Print_Register_Port_Agent register_functor_;
   const std::string & component_;
  };

  //===========================================================================
  /**
   * @struct Declare_Periodic_Trigger
   *
   * This functor prints the method for registering a port agent
   * with the benchmark agent for a CoWorkEr.
   */
  //===========================================================================

  struct Declare_Periodic_Trigger :
    public Print_Functor_Base
  {
    //
    // Print_Register_Port_Agent
    //
    Declare_Periodic_Trigger (std::ofstream & out)
      : Print_Functor_Base (out)
    {

    }

    //
    // operator ()
    //
    void operator () (const CUTS_PIR::Periodic_Action * action)
    {
      this->out_
        << "Periodic_Trigger_Type "
        << action->name () << "_periodic_trigger_;";
    }
  };

  //===========================================================================
  /**
   * @struct Declare_Event_Handler
   */
  //===========================================================================

  struct Declare_Event_Handler :
    public Print_Functor_Base
  {
    //
    // Print_Register_Port_Agent
    //
    Declare_Event_Handler (std::ofstream & out)
      : Print_Functor_Base (out)
    {

    }

    //
    // operator ()
    //
    void operator () (const CUTS_PIR::Event_Sink * es)
    {
      this->out_
        << "Event_Handler_Type push_"
        << es->name () << "_event_handler_;";
    }
  };

  //===========================================================================
  /**
   * @struct Print_Register_Exit_Point
   */
  //===========================================================================

  struct Print_Register_Exit_Point :
    public Print_Functor_Base
  {
    //
    // Print_Register_Port_Agent
    //
    Print_Register_Exit_Point (std::ofstream & out)
      : Print_Functor_Base (out)
    {

    }

    //
    // operator ()
    //
    void operator () (const CUTS_PIR::Event_Source * event_source)
    {
      this->out_
        << "this->benchmark_agent_->register_exit_point (\""
        << event_source->uuid ()
        << "\", \""
        << event_source->name ()
        << "\");";
    }
  };

  //===========================================================================
  /**
   * @struct Print_Unregister_Port_Agent
   *
   * This functor prints the method for unregistering a port agent
   * with the benchmark agent for a CoWorkEr.
   */
  //===========================================================================

  struct Print_Unregister_Port_Agent :
    public Print_Functor_Base
  {
    //
    // Print_Unregister_Port_Agent
    //
    Print_Unregister_Port_Agent (std::ofstream & out)
      : Print_Functor_Base (out)
    {

    }

    //
    // operator ()
    //
    void operator () (const CUTS_PIR::Event_Sink * event_sink)
    {
      this->out_
        << "this->benchmark_agent_->unregister_port_agent (&this->push_"
        << event_sink->name () << PORT_AGENT_SUFFIX << ");";
    }
  };

  //===========================================================================
  /**
   * @struct Print_Port_Agent_Method
   *
   * This functor prints the specified method for the port agent.
   */
  //===========================================================================

  struct Print_Port_Agent_Method :
    public Print_Functor_Base
  {
    //
    // Print_Port_Agent_Method
    //
    Print_Port_Agent_Method (std::ofstream & out, const std::string & method)
      : Print_Functor_Base (out),
        method_ (method)
    {

    }

    //
    // operator ()
    //
    void operator () (const CUTS_PIR::Event_Sink * event_sink)
    {
      this->out_
        << "this->push_" << event_sink->name () << PORT_AGENT_SUFFIX
        << "." << this->method_ << ";";
    }

  private:
    /// The name of the port agent method.
    const std::string & method_;
  };

//===========================================================================
/**
 * @struct Print_Trigger_Method
 */
//===========================================================================

  //
  // Print_Trigger_Method
  //
  struct Print_Trigger_Method :
    public Print_Functor_Base
  {
    Print_Trigger_Method (std::ofstream & out,
                          const std::string & method)
      : Print_Functor_Base (out),
        method_ (method)
    {

    }

    //
    // operator ()
    //
    void operator () (const CUTS_PIR::Periodic_Action * action)
    {
      this->out_
        << "this->" << action->name () << "_periodic_trigger_."
        << this->method_ << ";";
    }

  private:
    /// The name of the port agent method.
    const std::string & method_;
  };

//===========================================================================
/**
 * @struct Print_Trigger_Method
 */
//===========================================================================

  //
  // Print_Trigger_Method
  //
  struct Print_Event_Handler_Method :
    public Print_Functor_Base
  {
    Print_Event_Handler_Method (std::ofstream & out,
                                const std::string & method)
      : Print_Functor_Base (out),
        method_ (method)
    {

    }

    //
    // operator ()
    //
    void operator () (const CUTS_PIR::Event_Sink * sink)
    {
      this->out_
        << "this->push_" << sink->name () << "_event_handler_."
        << this->method_ << ";";
    }

  private:
    /// The name of the port agent method.
    const std::string & method_;
  };

//===========================================================================
/**
 * @struct Print_Port_Agent_Declaration
 *
 * This functor prints the declaration for a port agent.
 */
//===========================================================================

  struct Print_Port_Agent_Declaration :
    public Print_Functor_Base
  {
    //
    // Print_Port_Agent_Declaration
    //
    Print_Port_Agent_Declaration (std::ofstream & out)
      : Print_Functor_Base (out)
    {

    }

    //
    // operator ()
    //
    void operator () (const CUTS_PIR::Event_Sink * event_sink)
    {
      this->out_
        << "CUTS_Port_Agent push_" << event_sink->name ()
        << PORT_AGENT_SUFFIX << ";";
    }
  };

  //===========================================================================
  /*
   * class File_Visitor
   */
  //===========================================================================

  //
  // File_Visitor
  //
  File_Visitor::File_Visitor (const char * outdir)
    : outdir_ (outdir)
  {

  }

  //
  // ~File_Visitor
  //
  File_Visitor::~File_Visitor (void)
  {

  }

  //
  // visit_file
  //
  void File_Visitor::visit_file (const CUTS_PIR::File & file)
  {
    // Create the name of the <source_file> and <header_file>
    std::ostrstream header_file;
    header_file
      << this->outdir_ << "\\" << file.name () << "_CoWorkEr.h" << std::ends;

    std::ostrstream source_file;
    source_file
      << this->outdir_ << "\\" << file.name () << "_CoWorkEr.cpp" << std::ends;

    // Attempt to open both files for writing and continue iff both
    // files are open.
    this->hofs_.open (header_file.str ());
    this->sofs_.open (source_file.str ());

    if (!(this->hofs_.is_open () || this->sofs_.is_open ()))
      return;

    // Indentation implanter for the source file.
    {
      Indentation::Implanter <Indentation::Cxx> sguard_ (this->sofs_);

      // Indentation implanter for the header file.
      Indentation::Implanter <Indentation::Cxx> hguard_ (this->hofs_);

      std::string file_uppercase = String::uppercase (file.name ());

      // Create the define macro for the header file.
      std::string define = file_uppercase + "_COWORKER_H_";

      // Write the conditional macro definition for the header file.
      this->hofs_
        << "// -*- C++ -*-" << std::endl
        << std::endl
        << "// This header file was generated by" << std::endl
        << "// $Id$"
        << std::endl << std::endl
        << "#ifndef _CUTS_" << define << std::endl
        << "#define _CUTS_" << define << std::endl
        << std::endl
        << "#include /**/ \"ace/pre.h\"" << std::endl
        << "#include \"" << file.name () << "_svnt.h\"" << std::endl
        << std::endl
        << "#if !defined (ACE_LACKS_PRAGMA_ONCE)" << std::endl
        << "#pragma once" << std::endl
        << "#endif /* ACE_LACKS_PRAGMA_ONCE */" << std::endl
        << std::endl
        << "#include \"tao/LocalObject.h\"" << std::endl
        << "#include \"cuts/config.h\"" << std::endl
        << std::endl
        << "#include \"cuts/CCM_CoWorkEr_T.h\"" << std::endl
        << "#include \"cuts/Trigger_T.h\"" << std::endl
        << "#include \"cuts/CCM_Event_Producer_T.h\"" << std::endl
        << "#include \"cuts/EventHandler_T.h\"" << std::endl
        << "#include \"cuts/PortAgent.h\"" << std::endl
        << std::endl;

      this->sofs_
        << "// This source file was generated by" << std::endl
        << "// $Id$"
        << std::endl
        << std::endl
        << "#include \"" << file.name () << "_CoWorkEr.h\"" << std::endl
        << "#include \"cuts/ActivationRecord.h\"" << std::endl;

      if (file.has_events ())
      {
        this->sofs_
          << "#include \"cuts/CCM_Events_T.h\"" << std::endl
          << std::endl;
      }

      // Generate the remaining includes
      std::for_each (
        file.includes ().begin (),
        file.includes ().end (),
        Print_Include (this->hofs_));

      if (file.includes ().size () > 0)
        this->hofs_ << std::endl;

      // Visit the contents of the file.
      visit_module_contents (file);

      // Close the conditional macro definition for the file.
      this->hofs_
        << "#endif  // !defined _CUTS_" << define << std::endl;
    }

    // Close both the header and source file.
    this->hofs_.close ();
    this->sofs_.close ();
  }

  //
  // visit_module_contents
  //
  void File_Visitor::visit_module_contents (const CUTS_PIR::Module & module)
  {
    // Visit all the component in the module contents.
    std::for_each (
      module.components ().begin (),
      module.components ().end (),
      std::bind2nd (
        std::mem_fun <void, CUTS_PIR::Component, CUTS_PIR::Visitor *> (
          &CUTS_PIR::Component::accept),
        this));

    // Visit all the modules in the module content.
    std::for_each (
      module.modules ().begin (),
      module.modules ().end (),
      std::bind2nd (
        std::mem_fun <void, CUTS_PIR::Module, CUTS_PIR::Visitor *> (
          &CUTS_PIR::Module::accept),
        this));
  }

  //
  // visit_module
  //
  void File_Visitor::visit_module (const CUTS_PIR::Module & module)
  {
    // Begin a new namespace declaration.
    this->hofs_
      << "namespace " << module.name ()
      << "{";
    this->sofs_
      << "namespace " << module.name ()
      << "{";

    // Visit the contents of the module.
    visit_module_contents (module);

    // End the namespace declaration.
    this->hofs_ << "}";
    this->sofs_ << "}";
  }

  //
  // visit_component
  //
  void File_Visitor::visit_component (const CUTS_PIR::Component & component)
  {
    // Create the name of the <component_>.
    this->component_ = component.name ();
    this->component_.append ("_CoWorkEr");

    // Construct some predefined strings for the component.
    std::string ccm_component = component.name () + "_Exec";
    std::string component_context = component.name () + "_Context";

    this->hofs_
      << "namespace CIDL_" << component.name () << "_Impl {";
    this->sofs_
      << "namespace CIDL_" << component.name () << "_Impl {";

    // Generate the component header information.
    this->hofs_
      // Define the component.
      << "class CUTS_Export " << this->component_ << " :"
      << std::endl
      << "\tpublic CUTS_CCM_CoWorkEr_T <" << ccm_component
      << ", " << component_context << ">," << std::endl
      << "\tpublic virtual TAO_Local_RefCounted_Object {"

      // Generate the typedefs for the component.
      << "public:" << std::endl
      << "/// Type definition for this CoWorkEr." << std::endl
      << "typedef CUTS_CCM_CoWorkEr_T <" << std::endl
      << "\t" << ccm_component << ", "
      << component_context << "> CoWorkEr_Type;"
      << std::endl;

    // Write the constructor.
    write_constructor (component);

    // Write the destructor.
    write_destructor (component);

    // Generete all the <event_sinks> methods for the <component>.
    std::for_each (
      component.event_sinks ().begin (),
      component.event_sinks ().end (),
      std::bind2nd (
        std::mem_fun <void, CUTS_PIR::Event_Sink, CUTS_PIR::Visitor *> (
          &CUTS_PIR::Event_Sink::accept),
        this));

    // Generete all the <facets> methods for the <component>.
    std::for_each (
      component.facets ().begin (),
      component.facets ().end (),
      std::bind2nd (
        std::mem_fun <void, CUTS_PIR::Facet, CUTS_PIR::Visitor *> (
          &CUTS_PIR::Facet::accept),
        this));

    // Generete all the <period_action> methods for the <component>.
    std::for_each (
      component.periodic_actions ().begin (),
      component.periodic_actions ().end (),
      std::bind2nd (
        std::mem_fun <void, CUTS_PIR::Periodic_Action, CUTS_PIR::Visitor *> (
          &CUTS_PIR::Periodic_Action::accept),
        this));

    // Write the <set_session_context> method.
    write_set_session_context (component);

    // Write the <ciao_preactivate> method.
    write_ciao_preactivate (component);

    // Write the <ccm_activate> method.
    write_ccm_activate (component);

    // Write the <cioa_postactivate> method.
    write_ciao_postactivate (component);

    // Write the <ccm_passivate> method.
    write_ccm_passivate (component);

    // Write the <ccm_remove> method.
    write_ccm_remove (component);

    // Enter the <private> section of the component declaration.
    write_member_variables (component);

    // End the class declaration.
    this->hofs_
      << "};";

    // Visit the home for this component.
    if (component.home ())
    {
      component.home ()->accept (this);
    }

    // Close the session namespace.
    this->hofs_ << "}";
    this->sofs_ << "}";

    // Reset the <event_types_> for the next <component>.
    if (!this->event_types_.empty ())
    {
      this->event_types_.clear ();
    }
  }

  //
  // visit_component_home
  //
  void File_Visitor::visit_component_home (const CUTS_PIR::Component_Home & home)
  {
    std::string scoped_name = home.scoped_name ("_");

    // Create the name of the factory.
    std::string factory = home.name ();
    factory.append ("_CoWorkEr_Factory");

    this->hofs_
      // Define the component home.
      << "class CUTS_Export " << factory << " :" << std::endl
      << "  virtual public " << home.manages ()->name () << "Home_Exec,"
      << std::endl
      << "\tvirtual public TAO_Local_RefCounted_Object {"
      << "public:" << std::endl
      // Generate the constructor and destructor.
      << factory << " (void);"
      << "virtual ~" << factory << " (void);"
      << std::endl
      // Generate the creation method.
      << "virtual ::Components::EnterpriseComponent_ptr create ("
      << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
      << "ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException));"
      // Finish the class declaration.
      << "};";

    // Print the export function for creating the home.
    std::string factory_method = scoped_name + "_CoWorkEr_Factory_Impl";

    this->hofs_
      << "extern \"C\" CUTS_Export " << std::endl
      << "::Components::HomeExecutorBase_ptr" << std::endl
      << "create_" << factory_method << " (void);";

    this->sofs_
      // Generate the constructor/destructor.
      << factory << "::" << factory << " (void) { }"
      << factory << "::~" << factory << " (void) { }"

      // Generate the creation method for the component.
      << "::Components::EnterpriseComponent_ptr" << std::endl
      << factory << "::create (ACE_ENV_SINGLE_ARG_DECL)" << std::endl
      << "ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException)) {"
      << "::Components::EnterpriseComponent_ptr retval =" << std::endl
      << "\t::Components::EnterpriseComponent::_nil ();" << std::endl
      << "ACE_NEW_THROW_EX (retval, " << this->component_ << ", CORBA::NO_MEMORY ());"
      << "ACE_CHECK_RETURN (::Components::EnterpriseComponent::_nil ());"
      << "return retval;"
      << "}";

    this->sofs_
      << "extern \"C\" CUTS_Export " << std::endl
      << "::Components::HomeExecutorBase_ptr" << std::endl
      << "create_" << factory_method << " (void) {"
      << "::Components::HomeExecutorBase_ptr retval =" << std::endl
      << "\t::Components::HomeExecutorBase::_nil ();" << std::endl
      << "ACE_NEW_RETURN (" << std::endl
      << "retval, " << std::endl
      << factory << "," << std::endl
      << "::Components::HomeExecutorBase::_nil ());"
      << "return retval;"
      << "}";
  }

  //
  // visit_event_sink
  //
  void File_Visitor::visit_event_sink (const CUTS_PIR::Event_Sink & event_sink)
  {
    static const char * PREFIX = "push_";
    static const char * SUFFIX = "_event_handler";

    // Define the name of the event handler.
    std::string event_handler = PREFIX + event_sink.name () + SUFFIX;

    // Get the <event> that is referenced by this <event_sink>.
    CUTS_PIR::Event * event =
      dynamic_cast <CUTS_PIR::Event *> (event_sink.reference ());

    // Insert the event into the <event_types_>. Since we are using a
    // set we do not have to worry about duplicates appearing since
    // keys are mapped to the address of the event.
    this->event_types_.insert (event);

    // Get the scoped name of the event.
    std::string scoped_name = event->scoped_name ("::");

    // Begin the method declaration.
    this->hofs_
      << std::endl
      << "// event sink: " << event_sink.name () << std::endl
      << "virtual void " << PREFIX << event_sink.name () << " (" << std::endl
      << "::" << scoped_name << " * ev" << std::endl
      << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)" << std::endl
      << "\tACE_THROW_SPEC ((::CORBA::SystemException));"
      << std::endl
      // Print the event handler for this event sink.
      << "void " << event_handler << " (CUTS_Activation_Record * record);";

    // Print the method definition for the event sink.
    this->sofs_
      << "void " << this->component_ << "::" << PREFIX << event_sink.name ()
      << " (" << std::endl << "::" << scoped_name << " * ev" << std::endl
      << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)" << std::endl
      << "\tACE_THROW_SPEC ((::CORBA::SystemException)) {"
      << "this->" << event_handler
      << "_.handle_event (ev->dispatch_time ());"
      << "}";

    // Print the method definition for the event handler.
    this->sofs_
      << "void " << this->component_ << "::"
      << event_handler << " (CUTS_Activation_Record * record) {";

    // Print the operations of the method.
    visit_method (event_sink);

    // Close the method definition.
    this->sofs_
      << "}";
  }

  //
  // write_set_session_context
  //
  void File_Visitor::write_set_session_context (
    const CUTS_PIR::Component & component)
  {
    static const char * SET_SESSION_CONTEXT =
      "set_session_context (\n"
      "::Components::SessionContext_ptr ctx\n"
      "ACE_ENV_ARG_DECL_WITH_DEFAULTS)\n"
      "\tACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    // Write the function declaration.
    this->hofs_
      << "// environment: set_session_context" << std::endl
      << "virtual void " << SET_SESSION_CONTEXT << ";";

    // Write the function definition.
    this->sofs_
      << "void " << this->component_ << "::" << SET_SESSION_CONTEXT
      << "{"
      << "CoWorkEr_Type::set_session_context (ctx);";

    std::string scoped_name;

    // Register all the <event_types_> received by this component.
    for ( Event_Types::iterator iter = this->event_types_.begin ();
          iter != this->event_types_.end ();
          iter ++)
    {
      scoped_name = (*iter)->scoped_name ("::");

      this->sofs_
        << "CIAO_REGISTER_OBV_FACTORY ("
        << scoped_name << "_init, " << scoped_name << ");";
    }

    if (!component.event_sources ().empty ())
    {

      this->sofs_
        << std::endl
        << "// Set the context for the <event_producer_>." << std::endl
        << "this->event_producer_.context (this->context_);";
    }
    // End the function definition.
    this->sofs_ << "}";
  }

  //
  // write_constructor
  //
  void File_Visitor::write_constructor (const CUTS_PIR::Component & component)
  {
    // Print the constructor declaration.
    this->hofs_
      << "// constructor" << std::endl
      << this->component_ << " (void);" << std::endl;

    // Print the constructor definition.
    this->sofs_
      << this->component_ << "::" << this->component_ << " (void)";

    bool first = true;

    // Print the instantiation list.
    CUTS_PIR::Component::Event_Sinks::const_iterator event_sink_iter =
      component.event_sinks ().begin ();

    // Instantiate the event sink port agents.
    if (event_sink_iter != component.event_sinks ().end ())
    {
      if (first)
      {
        this->sofs_
          << std::endl
          << ": ";
        first = false;
      }
      else
      {
        this->sofs_
          << "," << std::endl << "\t";
      }

      this->sofs_
        << "push_" << (*event_sink_iter)->name () << PORT_AGENT_SUFFIX
        << " (\"" << (*event_sink_iter)->uuid () << "\", \""
        << (*event_sink_iter)->name () << "\"), " << std::endl
        << "\tpush_" << (*event_sink_iter)->name ()
        << "_event_handler_ (this)";

      for (event_sink_iter ++;
           event_sink_iter != component.event_sinks ().end ();
           event_sink_iter ++)
      {
        this->sofs_
          << "," << std::endl
          << "\tpush_" << (*event_sink_iter)->name () << PORT_AGENT_SUFFIX
          << " (\"" << (*event_sink_iter)->uuid () << "\", \""
          << (*event_sink_iter)->name () << "\")," << std::endl
          << "\tpush_" << (*event_sink_iter)->name ()
          << "_event_handler_ (this)";
      }
    }

    // Instantiate the periodic triggers.
    CUTS_PIR::Component::Periodic_Actions::const_iterator pa_iter =
      component.periodic_actions ().begin ();

    if (pa_iter != component.periodic_actions ().end ())
    {
      if (first)
      {
        this->sofs_
          << std::endl
          << ": ";
        first = false;
      }
      else
      {
        this->sofs_
          << "," << std::endl << "\t";
      }

      this->sofs_
        << (*pa_iter)->name ()
        << "_periodic_trigger_ (this, &"
        << this->component_ << "::periodic_" << (*pa_iter)->name ()
        << ", " <<(*pa_iter)->period () << ", "
        << (*pa_iter)->probability () << ")";

      for (pa_iter ++;
           pa_iter != component.periodic_actions ().end ();
           pa_iter ++)
      {
        this->sofs_
        << "\t" << (*pa_iter)->name ()
        << "_periodic_trigger_ (this, "
        << this->component_ << "::periodic_" << (*pa_iter)->name ()
        << ", " <<(*pa_iter)->period () << ", "
        << (*pa_iter)->probability () << ")";
      }
    }

    // Begin the implementation.
    this->sofs_ << "{";

    // Register all exit points with the <benchmark_agent_>.
    this->sofs_
      << "// Register the exit points w/ the <benchmark_agent_>" << std::endl;
    std::for_each ( component.event_sources ().begin (),
                    component.event_sources ().end (),
                    Print_Register_Exit_Point (this->sofs_));

    // Register and bind the event handlers and port agents.
    this->sofs_
      << std::endl
      << "// Register and bind the event handlers and port agents" << std::endl;
    std::for_each ( component.event_sinks ().begin (),
                    component.event_sinks ().end (),
                    Register_Bind_Port_Agent (this->sofs_, this->component_));

    // End the function implementation.
    this->sofs_ << "}";
  }

  //
  // write_destructor
  //
  void File_Visitor::write_destructor (const CUTS_PIR::Component & component)
  {
    // Print the constructor declaration.
    this->hofs_
      << "// destructor" << std::endl
      << "virtual ~" << this->component_ << " (void);" << std::endl;

    // Print the constructor definition.
    this->sofs_
      << this->component_ << "::~" << this->component_ << " (void) {";

    // Register all the <port_agents> with the <benchmark_agent_>.
    std::for_each ( component.event_sinks ().begin (),
                    component.event_sinks ().end (),
                    Print_Unregister_Port_Agent (this->sofs_));

    this->sofs_ << "}";
  }

  //
  // write_ciao_preactivate
  //
  void File_Visitor::write_ciao_preactivate (const CUTS_PIR::Component & component)
  {
    static const char * CIAO_PREACTIVATE =
      "ciao_preactivate (\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "\tACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hofs_
      << std::endl
      << "// environment: ciao_preactivate" << std::endl
      << "virtual void " << CIAO_PREACTIVATE << ";";

    this->sofs_
      << "void " << this->component_ << "::" << CIAO_PREACTIVATE
      << "{";

    // Print the activation method for the port agents
    this->sofs_
      << "// Activate the port agent(s)." << std::endl;
    std::for_each (
      component.event_sinks ().begin (),
      component.event_sinks ().end (),
      Print_Port_Agent_Method (this->sofs_, "activate ()"));

    // Print the activation method for the event handlers
    this->sofs_
      << std::endl
      << "// Activate the event handler(s)." << std::endl;
    std::for_each (
      component.event_sinks ().begin (),
      component.event_sinks ().end (),
      Print_Event_Handler_Method (this->sofs_, "activate ()"));

    this->sofs_
      << "}";
  }

  //
  // write_ccm_activate
  //
  void File_Visitor::write_ccm_activate (const CUTS_PIR::Component & component)
  {
    static const char * CCM_ACTIVATE =
      "ccm_activate (\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "\tACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hofs_
      << std::endl
      << "// environment: ccm_activate" << std::endl
      << "virtual void " << CCM_ACTIVATE << ";";

    this->sofs_
      << "void " << this->component_ << "::" << CCM_ACTIVATE
      << "{";

    if (component.activate_method ())
    {
      this->sofs_
        << "// Create a new activation record." << std::endl
        << "CUTS_Activation_Record * record = " << std::endl
        << "\tthis->background_workload_.create_activation_record ();"
        << std::endl;

      // Write the actions in the method.
      this->visit_method (*component.activate_method ());

      this->sofs_
        << "// Close the activation record." << std::endl
        << "this->background_workload_.close_activation_record (record);"
        << std::endl;
    }

    this->sofs_
      << "}";
  }

  //
  // write_ciao_postactivate
  //
  void File_Visitor::write_ciao_postactivate (const CUTS_PIR::Component & component)
  {
    static const char * CIAO_POSTACTIVATE =
      "ciao_postactivate (\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "\tACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hofs_
      << std::endl
      << "// environment: ciao_postactivate" << std::endl
      << "virtual void " << CIAO_POSTACTIVATE << ";";

    this->sofs_
      << "void " << this->component_ << "::" << CIAO_POSTACTIVATE
      << "{";

    std::for_each (
      component.periodic_actions ().begin (),
      component.periodic_actions ().end (),
      Print_Trigger_Method (this->sofs_, "activate ()"));

    this->sofs_
      << "}";
  }

  //
  // write_ccm_passivate
  //
  void File_Visitor::write_ccm_passivate (const CUTS_PIR::Component & component)
  {
    static const char * CCM_PASSIVATE =
      "ccm_passivate (\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "\tACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    // Declare the method in the class.
    this->hofs_
      << std::endl
      << "// environment: ccm_passivate" << std::endl
      << "virtual void " << CCM_PASSIVATE << ";";

    // Begin the method definition.
    this->sofs_
      << "void " << this->component_ << "::" << CCM_PASSIVATE
      << "{";

    // Deactivate all event producer.
    //this->sofs_
    //  << "// Deactivate the event producer." << std::endl;
    //if (!component.event_sources ().empty ())
    //{
    //  this->sofs_
    //    << "this->event_producer_.deactivate ();";
    //}

    // Deactivate all the event handlers.
    this->sofs_
      << "// Deactivate the event handler(s)." << std::endl;
    std::for_each (
      component.event_sinks ().begin (),
      component.event_sinks ().end (),
      Print_Event_Handler_Method (this->sofs_, "deactivate ()"));

    this->sofs_
      << std::endl
      << "// Deactivate the port agent(s)." << std::endl;
    std::for_each (
      component.event_sinks ().begin (),
      component.event_sinks ().end (),
      Print_Port_Agent_Method (this->sofs_, "deactivate ()"));

    // Deactivate all the triggers.
    this->sofs_
      << std::endl
      << "// Deactivate the trigger(s)." << std::endl;
    std::for_each (
      component.periodic_actions ().begin (),
      component.periodic_actions ().end (),
      Print_Trigger_Method (this->sofs_, "deactivate ()"));

    // Close the method definition.
    this->sofs_
      << "}";
  }

  //
  // write_ccm_remove
  //
  void File_Visitor::write_ccm_remove (const CUTS_PIR::Component & component)
  {
    static const char * CCM_REMOVE =
      "ccm_remove (\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "\tACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hofs_
      << std::endl
      << "// environment: ccm_remove" << std::endl
      << "virtual void " << CCM_REMOVE << ";";

    this->sofs_
      << "void " << this->component_ << "::" << CCM_REMOVE
      << "{"
      << std::endl
      << "}";
  }

  //
  // write_member_variables
  //
  void File_Visitor::write_member_variables (const CUTS_PIR::Component & component)
  {
    this->hofs_
      << std::endl << "private:" << std::endl;

    // Print the declarations for the <CUTS_Port_Agent> objects.
    std::for_each ( component.event_sinks ().begin (),
                    component.event_sinks ().end (),
                    Print_Port_Agent_Declaration (this->hofs_));

    // Print all the worker types.
    for (
      CUTS_PIR::Component::Worker_Types::const_iterator iter =
        component.worker_types ().begin ();
      iter != component.worker_types ().end ();
      iter ++)
    {
      (*iter)->accept (this);
    }

    // Print the event producer.
    if (!component.event_sources ().empty ())
    {
      this->hofs_
        << std::endl
        << "typedef CUTS_CCM_Event_Producer_T <" << std::endl
        << "\t" << component.name () << "_Context> Event_Producer;"
        << std::endl
        << "Event_Producer event_producer_;";
    }

    // Print all the event handlers.
    if (!component.event_sinks ().empty ())
    {
      // Declare the type definition for the event handlers
      this->hofs_
        << std::endl
        << "// Type definition for event handlers." << std::endl
        << "typedef CUTS_Event_Handler_T <" << std::endl
        << "\t" << this->component_ << "> Event_Handler_Type;"
        << std::endl;

      std::for_each (
        component.event_sinks ().begin (),
        component.event_sinks ().end (),
        Declare_Event_Handler (this->hofs_));
    }

    // Declare the background workload port agent if neccesary.
    if (!component.periodic_actions ().empty () ||
         component.activate_method ())
    {
      this->hofs_
        << std::endl
        << "// Port agent for managing background workloads." << std::endl
        << "CUTS_Port_Agent background_workload_;";
    }

    if (!component.periodic_actions ().empty ())
    {
      this->hofs_
        << std::endl
        << "// Type definition for periodic trigger types." << std::endl
        << "typedef CUTS_Periodic_Trigger_T <" << std::endl
        << "\t" << this->component_ << "> Periodic_Trigger_Type;"
        << std::endl;

      std::for_each (
        component.periodic_actions ().begin (),
        component.periodic_actions ().end (),
        Declare_Periodic_Trigger (this->hofs_));
    }
  }

  //
  // visit_facet
  //
  void File_Visitor::visit_facet (const CUTS_PIR::Facet & facet)
  {
    static const char * SEPERATOR = "::";
    static const char * PREFIX = "get_";

    try
    {
      // Get the scoped name of the facets object.
      const CUTS_PIR::Object * object =
        dynamic_cast <const CUTS_PIR::Object *> (facet.reference ());

      std::string scope = object->scope (SEPERATOR);

      this->hofs_
        << std::endl
        << "// facet: " << facet.name () << std::endl
        << "virtual " << SEPERATOR << scope << "CCM_"
        << object->name () << "_ptr"
        << std::endl
        << "\t" << PREFIX << facet.name ()
        << " (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)"
        << std::endl
        << "\tACE_THROW_SPEC ((CORBA::SystemException));";

      this->sofs_
        << SEPERATOR << scope << "CCM_" << object->name () << "_ptr"
        << std::endl
        << this->component_ << SEPERATOR << PREFIX << facet.name ()
        << " (" << std::endl
        << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
        << "\tACE_THROW_SPEC ((CORBA::SystemException)) {"
        << "return "
        << SEPERATOR << scope << "CCM_" << object->name ()
        << SEPERATOR << "_nil ();"
        << "}";
    }
    catch (std::bad_cast &)
    {

    }
  }

  //
  // visit_worker_type
  //
  void File_Visitor::visit_worker_type (const CUTS_PIR::Worker_Type & decl)
  {
    try
    {
      // Get the reference worker.
      const CUTS_PIR::Worker * worker =
        dynamic_cast <const CUTS_PIR::Worker *> (decl.reference ());

      // Declare the worker for the component.
      this->hofs_
        << worker->name () << " " << decl.name () << "_;";
    }
    catch (std::bad_cast &)
    {

    }
  }

  //
  // visit_method
  //
  void File_Visitor::visit_method (const CUTS_PIR::Method & method)
  {
    // Generete all the <facets> methods for the <component>.
    CUTS_PIR::Method::Worker_Actions::container_type::const_iterator iter;
    for ( iter = method.actions ().c.begin ();
          iter != method.actions ().c.end ();
          iter ++)
    {
      (*iter)->accept (this);
    }
  }

  //
  // viist_worker_action
  //
  void File_Visitor::visit_worker_action (
    const CUTS_PIR::Worker_Action & action)
  {
    if (action.parent () == 0)
    {
      // Maybe this is an output action since an output action
      // does not have a parent.
      if (typeid (action) == typeid (CUTS_PIR::Output_Action))
      {
        const CUTS_PIR::Output_Action * output
          = dynamic_cast <const CUTS_PIR::Output_Action *> (&action);

        visit_output_action (*output);
      }

      // We have to leave this method regardless of what
      // happens.
      return;
    }

    // Determine what if the action should be logged.
    if (!action.log_action ())
    {
      this->sofs_ << "record->perform_action_no_logging (" << std::endl;
    }
    else
    {
      this->sofs_ << "record->perform_action (" << std::endl;
    }

    // Generate the action to perform.
    this->sofs_
      << "\t" << action.repetitions () << ", "
      << action.parent ()->reference ()->name ()
      << "::" << action.name () << " (this->"
      << action.parent ()->name () <<  "_";

    CUTS_PIR::Worker_Action::Properties::container_type::const_iterator iter;
    for (iter = action.properties ().c.begin ();
         iter != action.properties ().c.end ();
         iter ++)
     {
       this->sofs_
         << ", " << (*iter)->value ();
     }

     this->sofs_ << "));" << std::endl;
  }

  //
  // visit_output_action
  //
  void File_Visitor::visit_output_action (
    const CUTS_PIR::Output_Action & action)
  {
    try
    {
      // Get the event type for the port.
      const CUTS_PIR::Event * event =
        dynamic_cast <const CUTS_PIR::Event *> (
        action.event_source ()->reference ());

      std::string scoped_name = event->scoped_name ("::");

      // Begin writing the implementation for the action.
      this->sofs_
        << "record->record_exit_point (" << std::endl
        << "\t\"" << action.event_source ()->uuid ()<< "\","  << std::endl
        << "\tEvent_Producer::";

      // Determine the type of event to push based on the size.
      if (action.size () == 0)
      {
        this->sofs_ << "Push_Event <";
      }
      else
      {
        this->sofs_ << "Push_Data_Event <";
      }

      this->sofs_
        << std::endl
        << "\t\tOBV_" << scoped_name << ", " << scoped_name
        << ">" << std::endl
        << "\t\t(this->event_producer_, ";

      if (action.size () > 0)
      {
        this->sofs_ << action.size () << ",";
      }

      this->sofs_
        << std::endl
        << "\t\t&Event_Producer::Context::push_"
        << action.name () << "));" << std::endl;
    }
    catch (std::bad_cast &)
    {
      this->sofs_
        << "// exception: failed to generate output action ["
        << action.name () << "]" << std::endl << std::endl;
    }
  }

  void File_Visitor::visit_periodic_action (
    const CUTS_PIR::Periodic_Action & action)
  {
    static const char * PREFIX = "periodic_";

    this->hofs_
      << std::endl
      << "// periodic action: " << action.name () << std::endl
      << "void " << PREFIX << action.name () << " (void);" << std::endl;

    // Begin the function definition.
    this->sofs_
      << "void " << this->component_ << "::" << PREFIX << action.name ()
      << " (void) {"
      << "// Create a new activation record." << std::endl
      << "CUTS_Activation_Record * record =" << std::endl
      << "\tthis->background_workload_.create_activation_record ();"
      << std::endl;

    // Print the actions in the method.
    visit_method (action);

    // Close the function definition.
    this->sofs_
      << "this->background_workload_.close_activation_record (record);"
      << "}";
  }
}
