// $Id$

#include "StdAfx.h"
#include "PICMLVisitor_Impl.h"

#if !defined (__CUTS_INLINE__)
# include "PICMLVisitor_Impl.inl"
#endif

#include <CCF/CodeGenerationKit/IndentationCxx.hpp>
#include <CCF/CodeGenerationKit/IndentationImplanter.hpp>

#include <cuts/utils/String.h>
#include <strstream>

typedef std::set <BON::FCO> ChildFCOs;

static const char * PORT_AGENT_SUFFIX = "_port_agent_";

//
// CUTS_PICMLVisitor_Impl
//
CUTS_PICMLVisitor_Impl::CUTS_PICMLVisitor_Impl (const char * outdir)
: output_dir_ (outdir)
{

}

//
// ~CUTS_PICMLVisitor_Impl
//
CUTS_PICMLVisitor_Impl::~CUTS_PICMLVisitor_Impl (void)
{

}

//
// visitInterfaceDefinitions
//
bool CUTS_PICMLVisitor_Impl::visitInterfaceDefinitions (
  const PICML_BON::InterfaceDefinitions &object)
{
  if (!object)
    return false;

  // Get all the <Event> objects in the interface definitions.
  typedef std::set <BON::FCO> File_Set;
  File_Set files = object->getRootFCOs ();

  // Visit all the events.
  for ( File_Set::iterator iter = files.begin ();
        iter != files.end (); 
        iter ++)
  {
    this->visitFile (*iter);
  }

  return true;
}

//
// visitEvent
//
bool CUTS_PICMLVisitor_Impl::visitEvent (const PICML_BON::Event &object)
{
  if (!object)
    return false; 

  std::string scope;
  BON::Model package = object->getParentModel ("Package");

  // Determine the scope of the event.
  while (package)
  {
    // Write this scope.
    scope.insert (0, "::");
    scope.insert (0, package->getName ());

    // Go up to the next level.
    package = package->getParentModel ("Package");
  }

  // Construct the full name of the event.
  this->object_name_ = scope + object->getName ();

  // Write the event to the header and source files.
  this->hofs_ << this->object_name_ << " * ev";
  this->sofs_ << this->object_name_ << " * ev";
  return true;
}

//
// visitFile
//
bool CUTS_PICMLVisitor_Impl::visitFile (const PICML_BON::File &object)
{
  if (!object)
    return false;

  // Create the source and header file names.
  std::string header_file (this->output_dir_);
  header_file += "\\" + object->getName () + "_CoWorkEr.h";

  std::string source_file (this->output_dir_);
  source_file += "\\" + object->getName () + "_CoWorkEr.cpp";

  // Open the source and header for writing.
  this->hofs_.open (header_file.c_str ());
  this->sofs_.open (source_file.c_str ());

  // Do not continue if both aren't open.
  if (!(this->hofs_.is_open () && this->sofs_.is_open ()))
    return true;

  /// Indentation implanter for the source file.
  Indentation::Implanter <Indentation::Cxx> sguard_ (this->sofs_);

  /// Indentation implanter for the header file.
  Indentation::Implanter <Indentation::Cxx> hguard_ (this->hofs_);

  std::string filename_ucase = String::uppercase (object->getName ());

  // Create the define macro for the header file.
  std::string define = filename_ucase + "_COWORKER_H_";

  // Create the exports macro
  this->export_ = filename_ucase + "_EXEC_Export";

  // Write the conditional macro definition for the header file.
  this->hofs_ << "// -*- C++ -*-" << std::endl
              << std::endl
              << "#ifndef _CUTS_" << define << std::endl
              << "#define _CUTS_" << define << std::endl
              << std::endl;

  this->sofs_ << "// $Id$" << std::endl
              << std::endl;

  // Write the include files.
  this->hofs_ 
    << "#include \"" << object->getName () << "_exec.h\"" << std::endl
    << "#include <cuts/CoWorkEr_T.h>" << std::endl
    << std::endl;
  this->sofs_ 
    << "#include \"" << object->getName () << "_CoWorkEr.h\"" << std::endl
    << "#include \"" 
    << object->getProject ()->getName () << "_cuts_config.h\"" << std::endl
    << std::endl;
              
  // Visit all the contents of the file.
  visit_package_contents (object);

  // Close the conditional macro definition for the file.
  this->hofs_ << "#endif  // !defined _CUTS_" << define << std::endl;

  // Close both the files.
  this->hofs_.close ();
  this->sofs_.close ();
  return true;
}

//
// visitPackage
//
bool CUTS_PICMLVisitor_Impl::visitPackage (const PICML_BON::Package &object)
{
  if (!object)
    return false;

  // Start a new namespace.
  this->sofs_ 
    << "namespace " << object->getName () << std::endl 
    << "{";
  this->hofs_ 
    << "namespace " << object->getName () << std::endl 
    << "{";

  visit_package_contents (object);

  // Close the package definition.
  this->sofs_ << "}";
  this->hofs_ << "}";
  return true;
}

//
// visit_package_contents
//
void CUTS_PICMLVisitor_Impl::visit_package_contents (const BON::Model & object)
{
  // Visit all the <Component> models.
  ChildFCOs children = object->getChildFCOs ("Component");

  for ( ChildFCOs::iterator iter = children.begin ();
        iter != children.end ();
        iter ++)
  {
    this->visitComponent (*iter);
  }  

  // Get all the <Package> models.
  children = object->getChildFCOs ("Package");

  // Visit the child FCOs.
  for ( ChildFCOs::iterator iter = children.begin ();
        iter != children.end ();
        iter ++)
  {
    this->visitPackage (*iter);
  }
}

//
// visitComponent
//
bool CUTS_PICMLVisitor_Impl::visitComponent (const PICML_BON::Component & object)
{
  if (!object)
    return false;

  this->component_ = object->getName () + "_CoWorkEr";

  // Construct some predefined strings for the component.
  std::string component_exec = object->getName () + "_exec_i";

  // Generate the session namespace.
  this->hofs_ << "namespace CIDL_" << object->getName () << "_Impl {";
  this->sofs_ << "namespace CIDL_" << object->getName () << "_Impl {";

  // Generate the component header information.
  this->hofs_ 
    // Define the component.
    << "class " << this->export_ << " " << this->component_ << std::endl
    << ": public CUTS_CCM_CoWorkEr_T <" << component_exec << "> {"

    // Generate the typedefs for the component.
    << "public:" << std::endl
    << "/// Type defintion for this component." << std::endl
    << "typedef " << this->component_ << " This_Component;" << std::endl
    << "/// Type definition for this CoWorkEr." << std::endl
    << "typedef CUTS_CCM_CoWorkEr_T <" << component_exec << "> CoWorkEr_Type;" 
    << std::endl
    << "/// Component executor type wrapped by this CoWorkEr." << std::endl
    << "typedef CoWorkEr_Type::Component_Type Component_Type;" << std::endl
    << "/// Event sources for the component." << std::endl;

  // Visit the <InEventPort> objects.
  ChildFCOs in_event_ports = object->getChildFCOs ("InEventPort");
  for ( ChildFCOs::iterator iter = in_event_ports.begin ();
        iter != in_event_ports.end ();
        iter ++)
  {
    visitInEventPort (*iter);
  }

  // Write the ccm_* and ciao_* methods required by all components.
  write_set_session_context ();
  write_ciao_preactivate ();
  write_ccm_activate ();
  write_ciao_postactivate ();
  write_ccm_remove ();

  // Generate the constructor/desructor for the component. We have to
  // this information last because we have fully populated all the
  // required structures.
  write_constructor_and_destructor ();

  // Enter the <private> section of the component declaration.
  this->hofs_ 
    << "private:" << std::endl
    << "// The <Benchmark_Agent> for the component." << std::endl
    << "CUTS_CCM_Benchmark_Agent_T <Benchmark_Agent_exec_i> benchmark_agent_;";

  // Write all the variable declarations to this component.
  for ( Port_Mapping::iterator iter = this->event_sinks_.begin ();
        iter != this->event_sinks_.end ();
        iter ++)
  {
    this->hofs_ << "CUTS_Port_Agent " << iter->second << PORT_AGENT_SUFFIX << ";";
  }

  // Close the class definition.
  this->hofs_ << "};";

  //@@@@
  // Visit the <ComponentFactory> for the component.
  //@@@@

  // Close the session declaration for the compenent.
  this->sofs_ << "}";
  this->hofs_ << "}";

  return true;
}

//
// visitInEventPort
//
bool CUTS_PICMLVisitor_Impl::visitInEventPort (
  const PICML_BON::InEventPort & object)
{
  if (!object)
    return false;

  // Add this port to the set of <event_sinks_>.
  this->event_sinks_.insert (
    Port_Mapping::value_type ("__UUID__", object->getName ()));

  this->hofs_ 
    << "/// " << object->getName () << " event source" << std::endl
    << "virtual void " << object->getName () << " (::";
  this->sofs_ 
    << "void " << this->component_ << "::" << object->getName () << " (::";

  // Visit the event received.
  if (visitEvent (object->getEvent ()))
    this->event_types_.insert (this->object_name_);

  // Write the declaration.
  this->hofs_ 
    << std::endl
    << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "\tACE_THROW_SPEC ((::CORBA::SystemException));" << std::endl;

  // Write the definition.
  this->sofs_
    << std::endl
    << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)" << std::endl
    << "\tACE_THROW_SPEC ((::CORBA::SystemException))" << std::endl
    << "{CUTS_Timer timer;";

  // Visit the implemenation for the in event port.

  this->sofs_ 
    << "// Save the elapsed time for the port operation." << std::endl
    << "this->" << object->getName () << PORT_AGENT_SUFFIX
    << ".update_timing_info (timer.elapsed ());}";

  return true;
}

//
// write_set_session_context
//
void CUTS_PICMLVisitor_Impl::write_set_session_context (void)
{
  this->hofs_ 
    << "/// Set the session context for the component." << std::endl
    << "virtual void set_session_context "
    << "(::Components::SessionContext_ptr ctx "
    << std::endl
    << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)"
    << std::endl
    << "\tACE_THROW_SPEC ((::CORBA::SystemException, " << std::endl
    << "::Components::CCMException));"
    << std::endl;

  this->sofs_ 
    << "void " << this->component_ 
    << "::set_session_context (::Components::SessionContext_ptr ctx "
    << std::endl
    << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)"
    << std::endl
    << "\tACE_THROW_SPEC ((::CORBA::SystemException, " << std::endl
    << "::Components::CCMException)) {"
    << "CoWorkEr_Type::set_session_context (ctx);"
    << std::endl << std::endl;

  if (!this->event_types_.empty ())
  {
    // Register the all the events received by this compenent.
    this->sofs_ 
      << "// Register all events received by this component." << std::endl;
    for ( String_Set::iterator iter = this->event_types_.begin ();
          iter != this->event_types_.end ();
          iter ++)
    {
      this->sofs_ << "CUTS_REGISTER_EVENTTYPE (" << (*iter) << ");";
    }
  }
  this->sofs_ << "}";
}

//
// write_ciao_preactivate
//
void CUTS_PICMLVisitor_Impl::write_ciao_preactivate (void)
{
  static const char * ciao_preactivate = 
    "ciao_preactivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
    "\tACE_THROW_SPEC ((::CORBA::SystemException,\n::Components::CCMException))";

  this->hofs_ 
    << "/// The components has entered the pre-activate state" << std::endl
    << "virtual void " << ciao_preactivate << ";" << std::endl;
  this->sofs_ 
    << "void " << this->component_ << "::" << ciao_preactivate
    << "{" 
    << "CoWorkEr_Type::ciao_preactivate ();"
    << "}";
}

//
// write_ccm_activate
//
void CUTS_PICMLVisitor_Impl::write_ccm_activate (void)
{
  static const char * ccm_activate = 
    "ccm_activate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
    "\tACE_THROW_SPEC ((::CORBA::SystemException,\n::Components::CCMException))";

  this->hofs_ 
    << "/// The component has entered the activate state" << std::endl
    << "virtual void " << ccm_activate << ";" << std::endl;
  this->sofs_ 
    << "void " << this->component_ << "::" << ccm_activate
    << "{"
    << "CoWorkEr_Type::ccm_activate ();"
    << "}";
}

//
// write_ciao_postactivate
//
void CUTS_PICMLVisitor_Impl::write_ciao_postactivate (void)
{
  static const char * ciao_postactivate = 
    "ciao_postactivate (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
    "\tACE_THROW_SPEC ((::CORBA::SystemException,\n::Components::CCMException))";

  this->hofs_ 
    << "/// The component has entered the post-activate state" << std::endl
    << "virtual void " << ciao_postactivate << ";" << std::endl;
  this->sofs_ 
    << "void " << this->component_ << "::" << ciao_postactivate
    << "{"
    << "CoWorkEr_Type::ciao_postactivate ();"
    << "}";
}

//
// write_ccm_remove
//
void CUTS_PICMLVisitor_Impl::write_ccm_remove (void)
{
  static const char * ccm_remove = 
    "ccm_remove (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
    "\tACE_THROW_SPEC ((::CORBA::SystemException,\n::Components::CCMException))";

  this->hofs_ 
    << "/// The component is being removed from the container." << std::endl
    << "virtual void " << ccm_remove << ";" << std::endl;
  this->sofs_ 
    << "void " << this->component_ << "::" << ccm_remove
    << "{"
    << "CoWorkEr_Type::ccm_remove ();"
    << "}";
}

//
// write_constructor_and_destructor
//
void CUTS_PICMLVisitor_Impl::write_constructor_and_destructor (void)
{
  this->hofs_
    << "/// Constructor." << std::endl
    << this->component_ << " (void);" << std::endl
    << "/// Destructor." << std::endl
    << "virtual ~" << this->component_ << " (void);" << std::endl;

  // Generate the component source information.
  this->sofs_
    << this->component_ << "::" << this->component_ << " (void)" << std::endl;

  if (!this->event_sinks_.empty ())
  {
    this->sofs_ << ": ";
  }

  // Generate <event_sink> port agent member variables.
  Port_Mapping::iterator iter = this->event_sinks_.begin ();

  if (iter != this->event_sinks_.end ())
  {
    this->sofs_ 
      << iter->second << PORT_AGENT_SUFFIX
      << " (\"" << iter->first << "\", \"" << iter->second << "\")";

    for ( ++ iter; iter != this->event_sinks_.end ();  iter ++)
    {
      this->sofs_ 
        << "," << std::endl << iter->second << PORT_AGENT_SUFFIX
        << " (\"" << iter->first << "\", \"" << iter->second << "\")";
    }
  }

  this->sofs_
    << "{" 
    << std::endl 
    << "}"

    // Generate the destructor.
    << this->component_ << "::~" << this->component_ << " (void)" << std::endl
    << "{" 
    << std::endl
    << "}";
}
