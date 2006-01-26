// $Id$

#include "cuts/be/CIAO/CIAO_Visitor.h"
#include "cuts/pir/File.h"
#include "cuts/pir/Project.h"
#include "cuts/pir/Component.h"
#include "cuts/pir/ComponentHome.h"
#include "cuts/pir/Event.h"
#include "cuts/pir/EventSink.h"
#include "cuts/utils/String.h"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#include <strstream>
#include <functional>
#include <algorithm>

static const char * PORT_AGENT_SUFFIX = "_port_agent_";

namespace CUTS_CIAO
{
  struct Print_Functor_Base
  {
    Print_Functor_Base (std::ofstream & out)
      : out_ (out)
    {

    }

  protected:
    std::ofstream & out_;
  };

  struct Print_Include :
    public Print_Functor_Base
  {
    Print_Include (std::ofstream &out)
      : Print_Functor_Base (out)
    {

    }

    void operator () (const std::string & include)
    {
      this->out_ << "#include \"" << include << "\"" << std::endl;
    }
  };

  struct Print_Register_Port_Agent :
    public Print_Functor_Base
  {
    Print_Register_Port_Agent (std::ofstream & out)
      : Print_Functor_Base (out)
    {

    }

    void operator () (const CUTS_PIR::Event_Sink * event_sink)
    {
      this->out_
        << "this->benchmark_agent_.register_port_agent (&this->"
        << event_sink->name () << PORT_AGENT_SUFFIX << ");";
    }
  };

  struct Print_Port_Agent_Method :
    public Print_Functor_Base
  {
    Print_Port_Agent_Method (std::ofstream & out, const std::string & method)
      : Print_Functor_Base (out),
        method_ (method)
    {

    }

    void operator () (const CUTS_PIR::Event_Sink * event_sink)
    {
      this->out_
        << "this->" << event_sink->name () << PORT_AGENT_SUFFIX
        << "." << this->method_ << ";";
    }

  private:
    const std::string & method_;
  };

  struct Print_Port_Agent_Declaration :
    public Print_Functor_Base
  {
    Print_Port_Agent_Declaration (std::ofstream & out)
      : Print_Functor_Base (out)
    {

    }

    void operator () (const CUTS_PIR::Event_Sink * event_sink)
    {
      this->out_
        << "CUTS_Port_Agent " << event_sink->name ()
        << PORT_AGENT_SUFFIX << ";";
    }
  };

  //===========================================================================
  /*
   *
   */
  //===========================================================================

  Project_Visitor::Project_Visitor (const char * outdir)
    : outdir_ (outdir)
  {

  }

  Project_Visitor::~Project_Visitor (void)
  {

  }

  void Project_Visitor::visit_project (const CUTS_PIR::Project & project)
  {
    // Instantiate a <File_Visitor> for parsing the files.
    File_Visitor file_visitor (this->outdir_.c_str ());

    std::for_each (
      project.files ().begin (),
      project.files ().end (),
      std::bind2nd (
        std::mem_fun <void, CUTS_PIR::File, CUTS_PIR::Visitor *> (
          &CUTS_PIR::File::accept),
        &file_visitor));
  }

  //===========================================================================
  /*
   *
   */
  //===========================================================================

  File_Visitor::File_Visitor (const char * outdir)
    : outdir_ (outdir)
  {

  }

  File_Visitor::~File_Visitor (void)
  {

  }

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

      // Create the exports macro
      this->export_ = file_uppercase + "_EXEC_Export";

      // Write the conditional macro definition for the header file.
      this->hofs_
        << "// -*- C++ -*-" << std::endl
        << std::endl
        << "#ifndef _CUTS_" << define << std::endl
        << "#define _CUTS_" << define << std::endl
        << std::endl;

      this->sofs_
        << "// $Id$" << std::endl
        << std::endl;

      // Write the include files.
      this->hofs_
        << "#include \"" << file.name () << "_exec.h\"" << std::endl
        << "#include \"cuts/CCM_CoWorkEr_T.h\"" << std::endl
        << "#include \"cuts/PortAgent.h\"" << std::endl
        << std::endl;

      this->sofs_
        << "#include \"" << file.name () << "_CoWorkEr.h\"" << std::endl
        << "#include \"cuts/ActivationRecord.h\"" << std::endl;

      if (file.has_events ())
      {
        this->sofs_ << "#include \"cuts/Events_T.h\"" << std::endl;
      }

      // Generate the remaining includes
      std::for_each (
        file.includes ().begin (),
        file.includes ().end (),
        Print_Include (this->hofs_));

      // Visit the contents of the file.
      visit_module_contents (file);

      // Close the conditional macro definition for the file.
      this->hofs_
        << "#endif  // !defined _CUTS_" << define << std::endl
        << std::endl;
    }

    this->hofs_
      << "// end of code generation\n";
    this->sofs_
      << "// end of code generation\n";

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
    std::string component_exec = component.name ();
    component_exec.append ("_exec_i");

    // Generate the session namespace.
    this->hofs_ << "namespace CIDL_" << component.name () << "_Impl {";
    this->sofs_ << "namespace CIDL_" << component.name () << "_Impl {";

    // Generate the component header information.
    this->hofs_
      // Define the component.
      << "class " << this->export_ << " " << this->component_ << std::endl
      << ": public CUTS_CCM_CoWorkEr_T <" << component_exec
      << ", Benchmark_Agent_exec_i> {"

      // Generate the typedefs for the component.
      << "public:" << std::endl
      << "/// Type defintion for this component." << std::endl
      << "typedef " << this->component_ << " This_Component;" << std::endl
      << "/// Type definition for this CoWorkEr." << std::endl
      << "typedef CUTS_CCM_CoWorkEr_T <" << std::endl
      << "\t" << component_exec << ", Benchmark_Agent_exec_i> CoWorkEr_Type;"
      << std::endl
      << "/// Component executor type wrapped by this CoWorkEr." << std::endl
      << "typedef CoWorkEr_Type::Component_Type Component_Type;" << std::endl;

    // Write the constructor.
    write_constructor (component);

    // Write the destructor.
    write_destructor (component);

    // Write the <set_session_context> method.
    write_set_session_context (component);

    // Write the <ciao_preactivate> method.
    write_ciao_preactivate (component);

    // Write the <ccm_passivate> method.
    write_ccm_passivate (component);

    this->hofs_ << std::endl;

    // Generete all the <event_sinks> methods for the <component>.
    std::for_each (
      component.event_sinks ().begin (),
      component.event_sinks ().end (),
      std::bind2nd (
        std::mem_fun <void, CUTS_PIR::Event_Sink, CUTS_PIR::Visitor *> (
          &CUTS_PIR::Event_Sink::accept),
        this));

    // Enter the <private> section of the component declaration.
    write_member_variables (component);

    // End the class declaration.
    this->hofs_
      << "};";

    // Visit the home for the component.
    if (component.home ())
      component.home ()->accept (this);

    // Close the session declaration for the compenent.
    this->hofs_ << "}";
    this->sofs_ << "}";
  }

  //
  // visit_component_home
  //
  void File_Visitor::visit_component_home (const CUTS_PIR::Component_Home & home)
  {
    std::string scoped_name = home.scoped_name ("_");

    // Create the name of the factory.
    this->factory_ = home.name ();
    this->factory_.append ("_CoWorkEr_Factory");

    this->hofs_
      // Define the component home.
      << "class " << this->export_ << " " << this->factory_ << " :" << std::endl
      << "  virtual public " << home.name () << "_exec_i {"
      << "public:" << std::endl
      // Generate the constructor and destructor.
      << this->factory_ << " (void);"
      << "virtual ~" << this->factory_ << " (void);"
      << std::endl
      // Generate the creation method.
      << "virtual ::Components::EnterpriseComponent_ptr create ("
      << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
      << "ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException));"
      // Finish the class declaration.
      << "};";

    // Print the export function for creating the home.
    this->hofs_
      << "extern \"C\" " << this->export_ << std::endl
      << "::Components::HomeExecutorBase_ptr" << std::endl
      << "create_" << scoped_name << "_Impl (void);";

    this->sofs_
      // Generate the constructor/destructor.
      << this->factory_ << "::" << this->factory_ << " (void) { }"
      << this->factory_ << "::~" << this->factory_ << " (void) { }"

      // Generate the creation method for the component.
      << "::Components::EnterpriseComponent_ptr" << std::endl
      << this->factory_ << "::create (ACE_ENV_SINGLE_ARG_DECL)" << std::endl
      << "ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException)) {"
      << "::Components::EnterpriseComponent_ptr retval =" << std::endl
      << "\t::Components::EnterpriseComponent::_nil ();" << std::endl
      << "ACE_NEW_THROW_EX (retval, " << this->component_ << ", CORBA::NO_MEMORY ());"
      << "ACE_CHECK_RETURN (::Components::EnterpriseComponent::_nil ());"
      << "return retval;"
      << "}";

    this->sofs_
      << "extern \"C\" " << this->export_ << std::endl
      << "::Components::HomeExecutorBase_ptr" << std::endl
      << "create_" << scoped_name << "_Impl (void) {"
      << "::Components::HomeExecutorBase_ptr retval =" << std::endl
      << "\t::Components::HomeExecutorBase::_nil ();" << std::endl
      << "ACE_NEW_RETURN (" << std::endl
      << "\tretval, " << std::endl
      << "\t" << home.name () << "_CoWorkEr_Factory, " << std::endl
      << "\t::Components::HomeExecutorBase::_nil ());"
      << "return retval;"
      << "}";
  }

  //
  // visit_event_sink
  //
  void File_Visitor::visit_event_sink (const CUTS_PIR::Event_Sink & event_sink)
  {
    // Get the scoped name of the event.
    std::string scoped_name = event_sink.event_type ()->scoped_name ("::");

    // Begin the method declaration.
    this->hofs_
      << "void " << event_sink.name ()
      << " (::" << scoped_name << " * ev ACE_ENV_ARG_DECL_WITH_DEFAULTS)"
      << std::endl << "\tACE_THROW_SPEC ((::CORBA::SystemException));";

    // Print the method definition.
    this->sofs_
      << "void " << this->component_ << "::" << event_sink.name ()
      << " (::" << scoped_name << " * ev ACE_ENV_ARG_DECL_WITH_DEFAULTS)"
      << std::endl << "ACE_THROW_SPEC ((::CORBA::SystemException)) {"
      << "// Create a new activation record." << std::endl
      << "CUTS_Activation_Record * record =" << std::endl
      << "\tthis->" << event_sink.name ()
      << PORT_AGENT_SUFFIX << ".create_activation_record ();";

    // Print the operations of the method.
    this->sofs_
      << std::endl
      << "// Insert code here"
      << std::endl;

    // Close the method definition.
    this->sofs_
      << std::endl
      << "// Close the activation record." << std::endl
      << "this->" << event_sink.name ()
      << PORT_AGENT_SUFFIX  << ".close_activation_record (record);"
      << "}";
  }

  //
  // write_set_session_context
  //
  void File_Visitor::write_set_session_context (
    const CUTS_PIR::Component & component)
  {
    static const char * SET_SESSION_CONTEXT =
      "set_session_context (::Components::SessionContext_ptr ctx\n"
      "ACE_ENV_ARG_DECL_WITH_DEFAULTS)\n"
      "\tACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hofs_
      << "/// Set the session context for the component." << std::endl
      << "virtual void " << SET_SESSION_CONTEXT << ";";

    this->sofs_
      << "void " << this->component_ << "::" << SET_SESSION_CONTEXT
      << "{"
      << "CoWorkEr_Type::set_session_context (ctx);";

    CUTS_PIR::Component::Event_Types::const_iterator iter;

    for ( iter = component.in_events_types ().begin ();
          iter != component.in_events_types ().end ();
          iter ++)
    {
      this->sofs_
        << "CUTS_REGISTER_EVENTTYPE (" << (*iter)->scoped_name ("::") << ");";
    }

    this->sofs_
      << "}";
  }

  //
  // write_constructor
  //
  void File_Visitor::write_constructor (const CUTS_PIR::Component & component)
  {
    // Print the constructor declaration.
    this->hofs_
      << this->component_ << " (void);" << std::endl;

    // Print the constructor definition.
    this->sofs_
      << this->component_ << "::" << this->component_ << " (void)";

    // Print the instantiation list.
    CUTS_PIR::Component::Event_Sinks::const_iterator iter =
      component.event_sinks ().begin ();

    if (iter != component.event_sinks ().end ())
    {
      this->sofs_
        << std::endl
        << ": " << (*iter)->name () << PORT_AGENT_SUFFIX
        << " (\"__UUID__\", \"" << (*iter)->name () << "\")";

      for (iter ++; iter != component.event_sinks ().end (); iter ++)
      {
        this->sofs_
          << "," << std::endl
          << "  " << (*iter)->name () << PORT_AGENT_SUFFIX
          << " (\"__UUID__\", \"" << (*iter)->name () << "\")";
      }
    }

    this->sofs_ << "{";
    // Register all the <port_agents> with the <benchmark_agent_>.
    std::for_each ( component.event_sinks ().begin (),
                    component.event_sinks ().end (),
                    Print_Register_Port_Agent (this->sofs_));
    this->sofs_ << "}" << std::endl;
  }

  //
  // write_destructor
  //
  void File_Visitor::write_destructor (const CUTS_PIR::Component & component)
  {
    // Print the constructor declaration.
    this->hofs_
      << "virtual ~" << this->component_ << " (void);" << std::endl;

    // Print the constructor definition.
    this->sofs_
      << this->component_ << "::~" << this->component_ << " (void) {"
      << std::endl
      << "}"
      << std::endl;
  }

  //
  // write_ciao_preactivate
  //
  void File_Visitor::write_ciao_preactivate (const CUTS_PIR::Component & component)
  {
    static const char * CIAO_PREACTIVATE =
      "ciao_preactivate (void\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "\tACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hofs_
      << "/// Enter the preactivate state for the component." << std::endl
      << "virtual void " << CIAO_PREACTIVATE << ";";

    this->sofs_
      << "void " << this->component_ << "::" << CIAO_PREACTIVATE
      << "{"
      << "CoWorkEr_Type::ciao_preactivate ();";

    std::for_each (
      component.event_sinks ().begin (),
      component.event_sinks ().end (),
      Print_Port_Agent_Method (this->sofs_, "activate ()"));

    this->sofs_
      << "}";
}

  //
  // write_ccm_passivate
  //
  void File_Visitor::write_ccm_passivate (const CUTS_PIR::Component & component)
  {
    static const char * CCM_PASSIVATE =
      "ccm_passivate (void\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "\tACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hofs_
      << "/// Enter the preactivate state for the component." << std::endl
      << "virtual void " << CCM_PASSIVATE << ";";

    this->sofs_
      << "void " << this->component_ << "::" << CCM_PASSIVATE
      << "{"
      << "CoWorkEr_Type::ccm_passivate ();";

    std::for_each (
      component.event_sinks ().begin (),
      component.event_sinks ().end (),
      Print_Port_Agent_Method (this->sofs_, "deactivate ()"));

    this->sofs_
      << "}";
  }

  //
  // write_member_variables
  //
  void File_Visitor::write_member_variables (const CUTS_PIR::Component & component)
  {
    this->hofs_
      << std::endl
      << "private:" << std::endl
      << "// The <Benchmark_Agent> for the component." << std::endl
      << "CUTS_CCM_Benchmark_Agent_T <Benchmark_Agent_exec_i> benchmark_agent_;"
      << std::endl;

    // Print the declarations for the <CUTS_Port_Agent> objects.
    std::for_each ( component.event_sinks ().begin (),
                    component.event_sinks ().end (),
                    Print_Port_Agent_Declaration (this->hofs_));

  }
}
