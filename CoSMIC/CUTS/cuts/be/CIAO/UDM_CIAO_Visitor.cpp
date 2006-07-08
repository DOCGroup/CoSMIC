// $Id$

#include "UDM_CIAO_Visitor.h"
#include "UmlExt.h"
#include "Predefined_Type_Map.h"
#include "CoWorkEr_Cache.h"
#include "Dependency_Graph.h"
#include "UDM_Utility_T.h"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#include <sstream>
#include <functional>
#include <algorithm>

namespace CUTS
{
  /// The suffix for the header files.
  static const char * HEADER_SUFFIX = ".h";

  /// The suffix for the source files.
  static const char * SOURCE_SUFFIX = ".cpp";

  static const char * EVENT_SINK_PREFIX = "push_";
  static const char * EVENT_SINK_POSTFIX = "_event_handler";
  static const char * PORT_AGENT_POSTFIX = "_port_agent";

  //===========================================================================
  /**
   * @struct Sort_By_Position
   *
   * @brief Help functor to sort objects by their position. The object
   * sorted by this method are in left-to-right ordering. Their y-value
   * is currently ignored when sorting objects.
   */
  //===========================================================================

  template <typename T>
  struct Sort_By_Position
  {
    struct Position
    {
      /// X-value of the position.
      long x;

      /// Y-value of the position
      long y;

      /**
       * Extraction operator. This method takes a string and extracts
       * the coordinates from it. The format of the string should be
       * (x, y). If the source string does not have coordinates stored
       * in this format, it will cause unpredictable behavior.
       *
       * @param[in]     str     Source string with the x-,y-coordinates
       */
      void operator <<= (const std::string & str)
      {
        char tmp;

        std::istringstream istr (str);

        istr >> tmp;
        istr >> this->x;
        istr >> tmp;
        istr >> this->y;
      }
    };

    /**
     * Functor operation. This method will compare the determine
     * which object is the furthest most left object of the two.
     */
    bool operator () (const T & lhs, const T & rhs)
    {
      Position pos_lhs;
      pos_lhs <<= lhs.position ();

      Position pos_rhs;
      pos_rhs <<= rhs.position ();

      return pos_lhs.x < pos_rhs.x;
    }
  };

  //===========================================================================
  /*
   * UDM_CIAO_Visitor
   */
  //===========================================================================

  //
  // UDM_CIAO_Visitor
  //
  UDM_CIAO_Visitor::UDM_CIAO_Visitor (const std::string & outdir,
                                      const CUTS_Dependency_Graph & graph)
  : outdir_ (outdir),
    dependency_graph_ (graph),
    node_ (0),
    has_out_events_ (false),
    has_activate_ (false),
    ignore_effects_ (false),
    depth_ (0)
  {

  }

  //
  // ~UDM_CIAO_Visitor
  //
  UDM_CIAO_Visitor::~UDM_CIAO_Visitor (void)
  {
    CUTS_CoWorkEr_Cache::instance ()->close ();
  }

  //
  // Visit_RootFolder
  //
  void UDM_CIAO_Visitor::Visit_RootFolder (const PICML::RootFolder & root)
  {
    typedef std::set <PICML::InterfaceDefinitions> I_Defs_Sets;
    I_Defs_Sets idefs = root.InterfaceDefinitions_children ();

    std::for_each (idefs.begin (),
                   idefs.end (),
                   UDM_Accept_Functor <UDM_CIAO_Visitor,
                                       I_Defs_Sets::value_type> (*this));
  }

  //
  // Visit_InterfaceDefinitions
  //
  void UDM_CIAO_Visitor::Visit_InterfaceDefinitions (
    const PICML::InterfaceDefinitions & defs)
  {
    // Get all the files in this interface definitions folder.
    typedef std::set <PICML::File> File_Set;
    File_Set files = defs.File_kind_children ();

    for (File_Set::iterator iter = files.begin ();
         iter != files.end ();
         iter ++)
    {
      iter->Accept (*this);
    }
  }

  //
  // Visit_File
  //
  void UDM_CIAO_Visitor::Visit_File (const PICML::File & file)
  {
    // Locate the <CUTS_Dependency_Node> for the <file>.
    if (!this->dependency_graph_.find_node (file.name (),
                                            this->node_))
    {
      return;
    }

    // We only need to continue if we have at least one <CoWorkEr>
    // in the file.
    if ((this->node_->flags_ & CUTS_Dependency_Node::DNF_EXEC) == 0)
    {
      return;
    }

    // Generate the header and source filename(s).
    std::ostringstream hfile;
    hfile << this->outdir_ << "/" << file.name () << ".h" << std::ends;

    std::ostringstream sfile;
    sfile << this->outdir_ << "/" << file.name () << ".cpp" << std::ends;

    // Open the header and source file(s).
    this->hout_.open (hfile.str ().c_str ());
    this->sout_.open (sfile.str ().c_str ());

    if (this->hout_.is_open () && this->sout_.is_open ())
    {
      do
      {
        // Initialize the indentation implanters for the C++
        // specific files
        Indentation::Implanter <Indentation::Cxx> h_guard (this->hout_);
        Indentation::Implanter <Indentation::Cxx> s_guard (this->sout_);

        // Convert the filename to its uppercase equivalent.
        std::string upper_name = file.name ();

        std::transform (upper_name.begin (),
                        upper_name.end (),
                        upper_name.begin (),
                        toupper);

        std::ostringstream hash_def;
        hash_def << "_" << upper_name << std::ends;

        // Generate the header file preamble.
        this->hout_
          << "// -*- C++ -*-" << std::endl
          << std::endl
          << "// This file was generated by" << std::endl
          << "// $Id$"
          << std::endl << std::endl
          << "#ifndef " << hash_def.str () << std::endl
          << "#define " << hash_def.str () << std::endl
          << std::endl
          << "#include /**/ \"ace/pre.h\"" << std::endl
          << std::endl
          << "#include \"cuts/CUTS_exec_export.h\"" << std::endl
          << "#include \"" << file.name () << "_svnt.h\"" << std::endl
          << std::endl
          << "#if !defined (ACE_LACKS_PRAGMA_ONCE)" << std::endl
          << "#pragma once" << std::endl
          << "#endif /* ACE_LACKS_PRAGMA_ONCE */" << std::endl
          << std::endl
          << "#include \"tao/LocalObject.h\"" << std::endl
          << "#include \"cuts/config.h\"" << std::endl
          << "#include \"cuts/CCM_CoWorkEr_T.h\"" << std::endl;

        // Check if the current file contains InEvent and OutEvent ports,
        // and periodic actions.
        if ((this->node_->flags_ & CUTS_Dependency_Node::DNF_INEVENTS))
        {
          this->hout_
            << "#include \"cuts/EventHandler_T.h\"" << std::endl;
        }

        if ((this->node_->flags_ & CUTS_Dependency_Node::DNF_OUTEVENTS))
        {
          this->hout_
            << "#include \"cuts/CCM_Event_Producer_T.h\"" << std::endl;
        }

        if ((this->node_->flags_ & CUTS_Dependency_Node::DNF_PERIODIC))
        {
          this->hout_
            << "#include \"cuts/Trigger_T.h\"" << std::endl;
        }

        // Generate the remaining header files needed for this file to
        // compile successfully.
        if (!this->node_->includes_.empty ())
        {
          String_Set::const_iterator iter;

          for (iter = this->node_->includes_.begin ();
               iter != this->node_->includes_.end ();
               iter ++)
          {
            this->hout_ << "#include \"" << *iter << ".h\"" << std::endl;
          }

          this->hout_ << std::endl;
        }

        // Generate the source file preamble.
        this->sout_
          << "// This file was generated by" << std::endl
          << "// $Id$"
          << std::endl
          << std::endl
          << "#include \"" << file.name () << HEADER_SUFFIX << "\"" << std::endl
          << "#include \"cuts/ActivationRecord.h\"" << std::endl
          << std::endl;

        // Visit the contents of the file.
        this->visit_file_package_contents (file);

        // Generate the header file postamble.
        this->hout_
          << "#include /**/ \"ace/post.h\"" << std::endl
          << std::endl
          << "#endif   /* !defined " << hash_def.str () << "*/";
      } while (0);

      // Insert a extra line at the end of the file.
      this->hout_ << std::endl;
      this->sout_ << std::endl;

      // Close the source and header files.
      this->hout_.close ();
      this->sout_.close ();

      // Generate the project for this file.
      this->reset_file_info ();
    }
  }

  //
  // Visit_Package
  //
  void UDM_CIAO_Visitor::Visit_Package (const PICML::Package & package)
  {
    // Begin a new namespace.
    this->hout_
      << "namespace " << package.name ()
      << "{";
    this->sout_
      << "namespace " << package.name ()
      << "{";

    this->scope_.push_back (package.name ());
    this->visit_file_package_contents (package);
    this->scope_.pop_back ();

    // End the current namespace.
    this->hout_
      << "}";
    this->sout_
      << "}";
  }

  //
  // visit_file_package_contents
  //
  void UDM_CIAO_Visitor::visit_file_package_contents (const Udm::Object & obj)
  {
    // Visit all the components at this level.
    std::set <PICML::Component> components =
      Udm::ChildrenAttr <PICML::Component> (obj.__impl (), Udm::NULLCHILDROLE);

    for (std::set <PICML::Component>::iterator iter = components.begin ();
         iter != components.end ();
         iter ++)
    {
      iter->Accept (*this);
    }

    // Visit all the packages at this level.
    std::set <PICML::Package> packages =
      Udm::ChildrenAttr <PICML::Package> (obj.__impl (), Udm::NULLCHILDROLE);

    for (std::set <PICML::Package>::iterator iter = packages.begin ();
         iter != packages.end ();
         iter ++)
    {
      iter->Accept (*this);
    }
  }

  //
  // Visit_Component
  //
  void UDM_CIAO_Visitor::Visit_Component (const PICML::Component & component)
  {
    // Verify the component is indeed a CoWorkEr. If it is not then
    // there is no need of continuing w/ the code generation. We
    // can just skip to the next component.
    if (!CUTS_CoWorkEr_Cache::instance ()->is_coworker (component))
    {
      return;
    }

    // Create the names of the component.
    this->component_ = component.name ();

    // Construct some predefined strings for the component.
    std::string ccm_component = this->component_ + "_Exec";
    std::string component_context = this->component_ + "_Context";

    this->hout_
      << "namespace CIDL_" << this->component_ << "_Impl {";
    this->sout_
      << "namespace CIDL_" << this->component_ << "_Impl {";

    // Generate the component header information.
    this->hout_
      // Define the component.
      << "class CUTS_EXEC_Export " << this->component_ << " :"
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

    // Generate the constructor and destructor for the component.
    this->generate_constructor ();
    this->generate_destructor ();

    // Visit the event sources for the component.
    typedef std::set <PICML::OutEventPort> OutEventPort_Set;

    OutEventPort_Set event_sources = component.OutEventPort_kind_children ();
    if (!event_sources.empty ())
    {
      this->has_out_events_ = true;

      std::for_each (event_sources.begin (),
                     event_sources.end (),
                     UDM_Accept_Functor <UDM_CIAO_Visitor,
                                         OutEventPort_Set::value_type> (*this));
    }

    // Visit the event sinks for the component.
    typedef std::set <PICML::InEventPort> InEventPort_Set;
    InEventPort_Set event_sinks = component.InEventPort_kind_children ();

    std::for_each (
      event_sinks.begin (),
      event_sinks.end (),
      UDM_Accept_Functor <UDM_CIAO_Visitor,
                          InEventPort_Set::value_type> (*this));

    // Visit the facets for the components.
    typedef std::set <PICML::ProvidedRequestPort> ProvidedRequestPort_Set;
    ProvidedRequestPort_Set facets =
      component.ProvidedRequestPort_kind_children ();

    std::for_each (
      facets.begin (),
      facets.end (),
      UDM_Accept_Functor <UDM_CIAO_Visitor,
                          ProvidedRequestPort_Set::value_type> (*this));

    // Visit the environment for the component.
    PICML::Environment env = component.Environment_child ();

    if (env)
    {
      env.Accept (*this);
    }

    // Generate the SessionComponent methods.
    this->generate_set_session_context (component);
    this->generate_ciao_preactivate (component);
    this->generate_ccm_activate (component);
    this->generate_ciao_postactivate (component);
    this->generate_ccm_passivate (component);
    this->generate_ccm_remove (component);

    // Generate the private section of the class.
    this->hout_ << "private:" << std::endl;

    typedef std::set <PICML::PeriodicAction> Periodic_Set;
    Periodic_Set periodic = component.PeriodicAction_kind_children ();

    std::for_each (periodic.begin (),
                   periodic.end (),
                   UDM_Accept_Functor <UDM_CIAO_Visitor,
                                       Periodic_Set::value_type> (*this));

    this->generate_init (component);
    this->generate_fini (component);
    this->generate_member_variables (component);

    // Close off the class definition.
    this->hout_ << "};";

    // Visit the home for this component.
    typedef std::set <PICML::ManagesComponent> Manages_Set;
    Manages_Set manages = component.srcManagesComponent ();

    std::for_each (manages.begin (),
                   manages.end (),
                   UDM_Accept_Functor <UDM_CIAO_Visitor,
                                       Manages_Set::value_type> (*this));

    // Close off the namespace definition.
    this->hout_ << "}";
    this->sout_ << "}";

    // Reset all the data for this component.
    this->reset_component_info ();
  }

  //
  // Visit_ManagesComponent
  //
  void UDM_CIAO_Visitor::Visit_ManagesComponent (
    const PICML::ManagesComponent & manages)
  {
    PICML::ComponentFactory factory = manages.srcManagesComponent_end ();
    factory.Accept (*this);
  }

  //
  // Visit_ComponentFactory
  //
  void UDM_CIAO_Visitor::Visit_ComponentFactory (
    const PICML::ComponentFactory & factory)
  {
    std::string factory_name = factory.name ();

    this->hout_
      // Define the component home.
      << "class CUTS_EXEC_Export " << factory_name << " :" << std::endl
      << "  virtual public " << this->component_
      << "Home_Exec," << std::endl
      << "\tvirtual public TAO_Local_RefCounted_Object {"
      << "public:" << std::endl
      // Generate the constructor and destructor.
      << factory_name << " (void);"
      << "virtual ~" << factory_name << " (void);"
      << std::endl
      // Generate the creation method.
      << "virtual ::Components::EnterpriseComponent_ptr create ("
      << "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
      << "ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException));"
      // Finish the class declaration.
      << "};";

    // Generate the scope for the component factory.
    this->generate_scope ("_");

    this->hout_
      << "extern \"C\" CUTS_EXEC_Export "
      << "::Components::HomeExecutorBase_ptr" << std::endl
      << "create_" << this->temp_str_ << factory_name << "_Impl (void);";

    this->sout_
      // Generate the constructor/destructor.
      << factory_name << "::" << factory_name << " (void) { }"
      << factory_name << "::~" << factory_name << " (void) { }"

      // Generate the creation method for the component.
      << "::Components::EnterpriseComponent_ptr" << std::endl
      << factory_name << "::create (ACE_ENV_SINGLE_ARG_DECL)" << std::endl
      << "ACE_THROW_SPEC ((::CORBA::SystemException, ::Components::CCMException)) {"
      << "::Components::EnterpriseComponent_ptr retval =" << std::endl
      << "\t::Components::EnterpriseComponent::_nil ();" << std::endl
      << "ACE_NEW_THROW_EX (retval, " << std::endl
      << this->component_ << "," << std::endl << "CORBA::NO_MEMORY ());"
      << std::endl
      << "ACE_CHECK_RETURN (::Components::EnterpriseComponent::_nil ());"
      << std::endl
      << "return retval;"
      << "}";

    this->sout_
      << "extern \"C\" CUTS_EXEC_Export "
      << "::Components::HomeExecutorBase_ptr" << std::endl
      << "create_" << this->temp_str_ << factory_name << "_Impl"
      << " (void) {"
      << "::Components::HomeExecutorBase_ptr retval =" << std::endl
      << "\t::Components::HomeExecutorBase::_nil ();" << std::endl
      << "ACE_NEW_RETURN (" << "retval, " << std::endl
      << factory_name << "," << std::endl
      << "::Components::HomeExecutorBase::_nil ());"
      << std::endl
      << "return retval;"
      << "}";
  }

  //
  // Visit_Worker
  //
  void UDM_CIAO_Visitor::Visit_Worker (const PICML::Worker & worker)
  {
    // Write the worker type as the declaration.
    this->hout_ << worker.name ();
  }

  //
  // Visit_WorkerType
  //
  void UDM_CIAO_Visitor::Visit_WorkerType (const PICML::WorkerType & type)
  {
    // Visit the worker type before we handle the worker.
    PICML::Worker worker = type.ref ();
    worker.Accept (*this);

    // Write the name declaration for the worker.
    this->hout_ << " " << type.name () << "_;";
  }

  //
  // generate_constructor
  //
  void UDM_CIAO_Visitor::generate_constructor (void)
  {
    this->hout_
      << "// Constructor" << std::endl
      << this->component_ << " (void);"
      << std::endl;

    this->sout_
      << this->component_ << "::" << this->component_ << " (void) {"
      << this->component_ << "::init ();"
      << "}";
  }

  //
  // generate_destructor
  //
  void UDM_CIAO_Visitor::generate_destructor (void)
  {
    this->hout_
      << "// Destructor" << std::endl
      << "virtual ~" << this->component_ << " (void);"
      << std::endl;

    this->sout_
      << this->component_ << "::~" << this->component_ << " (void) {"
      << this->component_ << "::fini ();"
      << "}";
  }

  //
  // generate_member_variables
  //
  void UDM_CIAO_Visitor::generate_member_variables (
    const PICML::Component & component)
  {
    // Write all the worker declarations to the header.
    typedef std::set <PICML::WorkerType> WorkerType_Set;
    WorkerType_Set worker_types = component.WorkerType_kind_children ();

    if (!worker_types.empty ())
    {
      std::for_each (worker_types.begin (),
                     worker_types.end (),
                     UDM_Accept_Functor <UDM_CIAO_Visitor,
                                         WorkerType_Set::value_type> (*this));
      this->hout_ << std::endl;
    }

    // Write all the variable declartions to the header.
    typedef std::set <PICML::Variable> Variable_Set;
    Variable_Set variables = component.Variable_children ();

    if (!variables.empty ())
    {
      std::for_each (variables.begin (),
                     variables.end (),
                     UDM_Accept_Functor <UDM_CIAO_Visitor,
                                         Variable_Set::value_type> (*this));
      this->hout_ << std::endl;
    }

    // Write the event handler declarations.
    if (!this->event_sinks_.empty ())
    {
      typedef std::set <PICML::InEventPort> InEventPort_Set;
      InEventPort_Set in_events = component.InEventPort_kind_children ();

      for (InEventPort_Set::iterator iter = in_events.begin ();
           iter != in_events.end ();
           iter ++)
      {
        // Visit the event.
        PICML::Event event = iter->ref ();
        event.Accept (*this);

        this->hout_
          << "// Event Sink: " << iter->name () << std::endl
          << "void " << EVENT_SINK_PREFIX << iter->name () << EVENT_SINK_POSTFIX
          << " (" << std::endl
          << this->temp_str_ << " * ev, CUTS_Activation_Record * record);"
          << std::endl
          << "CUTS_Event_Handler_T <" << std::endl
          << "  " << this->component_ << "," << std::endl
          << "  " << this->temp_str_ << "> "
          << EVENT_SINK_PREFIX << iter->name () << EVENT_SINK_POSTFIX << "_;"
          << std::endl;
      }
    }

    // Write the event producer declaration.
    if (this->has_out_events_)
    {
      this->hout_
        << "// Type definition for the event producer." << std::endl
        << "typedef CUTS_CCM_Event_Producer_T <" << std::endl
        << "  " << component.name () << "_Context> Event_Producer;"
        << std::endl
        << "Event_Producer event_producer_;";
    }

    // Write the periodic event declarations.
    typedef std::set <PICML::PeriodicAction> Periodic_Set;
    Periodic_Set pset = component.PeriodicAction_kind_children ();

    if (!pset.empty ())
    {
      this->hout_
        << std::endl
        << "// Type definition for the periodic event type." << std::endl
        << "typedef CUTS_Periodic_Trigger_T <" << std::endl
        << "  " << this->component_ << "> Periodic_Event;" << std::endl;

      for (Periodic_Set::iterator iter = pset.begin ();
          iter != pset.end ();
          iter ++)
      {
        this->hout_
          << "Periodic_Event periodic_" << iter->name () << "_;";
      }
    }
  }

  //
  // generate_fini
  //
  void UDM_CIAO_Visitor::generate_fini (const PICML::Component & component)
  {
    this->hout_
      << "// Finalizer helper method" << std::endl
      << "void fini (void);" << std::endl;

    this->sout_
      << "//\n// fini\n//" << std::endl
      << "void " << this->component_ << "::fini (void) {";

    for (String_Set::iterator iter = this->event_sinks_.begin ();
         iter != this->event_sinks_.end ();
         iter ++)
    {
      this->sout_
        << "this->benchmark_agent_->unregister_port_agent (&this->"
        << EVENT_SINK_PREFIX << *iter << EVENT_SINK_POSTFIX
        << "_.port_agent ());";
    }

    this->sout_ << "}";
  }

  //
  // Visit_InEventPort
  //
  void UDM_CIAO_Visitor::Visit_InEventPort (const PICML::InEventPort & port)
  {
    // First we have to the get the <PICML::Input> object attached
    // to this <PICML::InEventPort>. If there isn't on connected to
    // it then we know that we do not have to generate any behavior
    // code for this port.
    PICML::Input input = port.dstInput ();

    // We only need to add this port to the event sinks if there is
    // an <PICML::Input> associated with the port.
    if (input)
    {
      this->event_sinks_.insert (port.name ());
    }

    // Generate the function declaration for this event sink. This
    // is the standard CCM method thats exposed to the outside
    // world.
    this->hout_
      << "/// Event Sink: " << port.name () << std::endl
      << "virtual void " << EVENT_SINK_PREFIX << port.name () << " ("
      << std::endl;

    this->sout_
      << "//" << std::endl
      << "// Event Sink: " << port.name () << std::endl
      << "//" << std::endl
      << "void " << this->component_ << "::"
      << EVENT_SINK_PREFIX << port.name () << " (" << std::endl;

    // Visit the event declartion and print its declaration for
    // the function.
    PICML::Event event = port.ref ();

    if (event != Udm::null)
    {
      event.Accept (*this);
    }

    // Insert the event name into the <event_types_> since we will
    // have to register its factory later.
    this->event_types_.insert (this->temp_str_);

    // Write the variable declaration for the event.
    this->hout_ << this->temp_str_ << " * ev" << std::endl;
    this->sout_ << this->temp_str_ << " * ev" << std::endl;

    this->hout_
      << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)" << std::endl
      << "\tACE_THROW_SPEC ((::CORBA::SystemException));"
      << std::endl;

    this->sout_
      << "ACE_ENV_ARG_DECL_WITH_DEFAULTS)" << std::endl
      << "\tACE_THROW_SPEC ((::CORBA::SystemException))"
      << "{";

    // We only need to generate the event handler method if there
    // is behavior defined for this port, e.g., it is connected
    // to a <PICML::Input> oject.
    if (input)
    {
      this->sout_
        << "this->" << EVENT_SINK_PREFIX << port.name ()
        << EVENT_SINK_POSTFIX << "_.handle_event (ev);";
    }

    this->sout_ << "}";

    // We can generate the upcall method for the component if we
    // are attached to a <PICML::Input> object.
    if (input)
    {
      this->sout_
        << "//" << std::endl
        << "// Event Sink [handler]: " << port.name () << std::endl
        << "//" << std::endl
        << "void " << this->component_ << "::" << EVENT_SINK_PREFIX
        << port.name () << EVENT_SINK_POSTFIX
        << " (" << std::endl
        << this->temp_str_ << " * ev," << std::endl
        << "CUTS_Activation_Record * record)"
        << "{";

      input.Accept (*this);

      // Keep the compilers happy in case the event is not used
      // in the source code.
      this->sout_
        << "ACE_UNUSED_ARG (ev);"
        << "}";
    }
  }

  //
  // Visit_Event
  //
  void UDM_CIAO_Visitor::Visit_Event (const PICML::Event & event)
  {
    this->generate_scope (event);
    this->temp_str_.append (event.name ());
  }

  //
  // generate_init
  //
  void UDM_CIAO_Visitor::generate_init (const PICML::Component & component)
  {
    // Generate the header method.
    this->hout_
      << "// Initializer helper method" << std::endl
      << "void init (void);" << std::endl;

    // Generate the source code for this method.
    this->sout_
      << "//\n// init\n//" << std::endl
      << "void " << this->component_ << "::" << "init (void) {";

    for (String_Set::iterator iter = this->event_sinks_.begin ();
         iter != this->event_sinks_.end ();
         iter ++)
    {
      this->sout_
        << "// Configuring <" << *iter << "> event port" << std::endl
        << "this->"
        << EVENT_SINK_PREFIX << *iter << EVENT_SINK_POSTFIX
        << "_.bind (" << std::endl
        << "\"" << *iter << "\", this," << std::endl
        << "&" << this->component_ << "::"
        << EVENT_SINK_PREFIX << *iter << EVENT_SINK_POSTFIX << ");"
        << "this->benchmark_agent_->register_port_agent (" << std::endl
        << "&this->" << EVENT_SINK_PREFIX << *iter << EVENT_SINK_POSTFIX
        << "_.port_agent ());"
        << std::endl;
    }

    // Initialize the periodic events.
    typedef std::set <PICML::PeriodicAction> Periodic_Set;
    Periodic_Set pset = component.PeriodicAction_kind_children ();

    if (!pset.empty ())
    {
      this->sout_
        << "// Initialize all the periodic events." << std::endl;

      for (Periodic_Set::iterator iter = pset.begin ();
          iter != pset.end ();
          iter ++)
      {
        this->sout_
          << "// periodic event: " << iter->name () << std::endl
          << "this->periodic_" << iter->name () << "_.init (" << std::endl
          << "this, &" << this->component_
          << "::periodic_" << iter->name () << ");"
          << "this->periodic_" << iter->name () << "_.probability ("
          << iter->Probability () << ");"
          << std::endl;
      }
    }

    this->sout_ << "}";
  }

  //
  // Visit_Input
  //
  void UDM_CIAO_Visitor::Visit_Input (const PICML::Input & input)
  {
    PICML::InputAction action =
      PICML::InputAction::Cast (input.dstInput_end ());

    action.Accept (*this);
  }

  //
  // Visit_InputActionBase
  //
  void UDM_CIAO_Visitor::Visit_InputAction (
    const PICML::InputAction & action)
  {
    // Push this input action onto the call stack.
    this->call_stack_.push (action);

    PICML::Effect effect = action.dstInputEffect ();
    effect.Accept (*this);
  }

  //
  // Visit_Effect
  //
  void UDM_CIAO_Visitor::Visit_Effect (const PICML::Effect & effect)
  {
    // Generate the postcondition for the effect if there is any.
    std::string post = effect.Postcondition ();

    if (!post.empty ())
    {
      this->sout_ << post << ";" << std::endl;
    }

    // Visit the next state in the chain.
    PICML::State state = effect.dstInputEffect_end ();
    state.Accept (*this);
  }

  //
  // Visit_State
  //
  void UDM_CIAO_Visitor::Visit_State (const PICML::State & state)
  {
    if (!this->ignore_effects_)
    {
      // Determine if this state is a finishing state for conditional
      // flows. If the state has more than one source, then we can
      // conclude that we are ending one or more conditional flows.
      std::set <PICML::Effect> effects = state.srcInputEffect ();

      if (effects.size () > 1)
      {
        if (this->holding_state_.empty ())
        {
          this->holding_state_.push (state);
        }
        else if (this->holding_state_.top () != state)
        {
          this->holding_state_.push (state);
        }
        return;
      }
    }
    else
    {
      this->ignore_effects_ = false;
    }

    // Check for a finishing transition from this state.
    PICML::Finish finish_conn = state.dstFinish ();

    if (finish_conn)
    {
      // Get the name of the input port.
      PICML::InputActionBase finish =
        PICML::InputActionBase::Cast (finish_conn.dstFinish_end ());

      if (finish == this->call_stack_.top ())
      {
        // Remove the action from the top of the call stack.
        this->call_stack_.pop ();
        return;
      }
    }

    // Get all the transitions from this state. If there is more than
    // one transition, then we need to prepare generating flow control
    // in execution path.
    typedef std::set <PICML::Transition> Transition_Set;
    Transition_Set transitions = state.dstInternalPrecondition ();

    if (transitions.size () > 1)
    {
      ++ this->depth_;
    }

    // Get the number of transitions and first transition in
    // the set.
    Transition_Set::iterator iter = transitions.begin ();

    // Handle the first transition as if it was the only
    // transition connected to the state.
    std::string condition = iter->Precondition ();

    if (!condition.empty ())
    {
      this->sout_ << "if (" << condition << "){";
    }

    iter->Accept (*this);

    if (!condition.empty ())
    {
      this->sout_ << "}";
    }

    // Visit the remaining transitions and print them out as
    // conditional 'if else' statements.
    for (iter ++; iter != transitions.end (); iter ++)
    {
      // Generate the conditional statement.
      condition = iter->Precondition ();
      this->sout_ << "else if (" << condition << "){";

      iter->Accept (*this);

      this->sout_ << "}";
    }

    // Now that we have visited all the transitions from the
    // state, we can jump to the state were all the branching
    // transitions from this state merge.
    if (transitions.size () > 1)
    {
      if (this->depth_ -- == this->holding_state_.size ())
      {
        // Get the topmost holding state and jump to it. We need to make
        // sure we tell the holding state to ignore any effect connections
        // since it will cause it to return.
        PICML::State jmp_state = this->holding_state_.top ();
        this->holding_state_.pop ();
        this->ignore_effects_ = true;

        jmp_state.Accept (*this);
      }
    }
  }

  //
  // Visit_Transition
  //
  void UDM_CIAO_Visitor::Visit_Transition (const PICML::Transition & trans)
  {
    // Get the action connected to the end of the transaction.
    PICML::ActionBase action =
      PICML::ActionBase::Cast (trans.dstInternalPrecondition_end ());
    std::string _typename = action.type ().name ();

    // We only continue at this point if the action is an instance
    // of a predefined action, or it has more than 1 repetition
    // specified.
    if (action.isInstance () && action.Repetitions () > 0)
    {
      if (_typename == (std::string)PICML::Action::meta.name ())
      {
        PICML::Action::Cast (action).Accept (*this);
      }
      else if (_typename == (std::string) PICML::CompositeAction::meta.name ())
      {
        PICML::CompositeAction::Cast (action).Accept (*this);
      }
      else if (_typename == (std::string) PICML::OutputAction::meta.name ())
      {
        PICML::OutputAction::Cast (action).Accept (*this);
      }
    }

    // Continue down the chain.
    PICML::Effect effect = action.dstInputEffect ();
    effect.Accept (*this);
  }

  //
  // Visit_WorkerAction
  //
  void UDM_CIAO_Visitor::Visit_Action (const PICML::Action & action)
  {
    // Generate the correct type of logging for the record.
    this->sout_ << "record->";

    if (action.LogAction ())
    {
      this->sout_ << "perform_action (";
    }
    else
    {
      this->sout_ << "perform_action_no_logging (";
    }

    // Get action type and it's worker parent.
    PICML::Action action_type = action;
    while (PICML::Action (action_type.Archetype ()) != Udm::null)
      action_type = action_type.Archetype ();

    PICML::Worker worker = action_type.Worker_parent ();

    // Generate the preamble for the worker action.
    this->sout_
      << std::endl;

    if (action.Repetitions () > 1)
    {
      this->sout_
        << action.Repetitions () << ", ";
    }

    this->sout_
      << worker.name () << "::" << action_type.name () << " (this->"
      << action.name () << "_";

    // Generate the parameters for the action.
    typedef std::set <PICML::Property,
                      Sort_By_Position <PICML::Property> > Property_Set;

    Property_Set properties =
      action.Property_kind_children_sorted (
      Sort_By_Position <PICML::Property> ());

    for (Property_Set::iterator iter = properties.begin ();
         iter != properties.end ();
         iter ++)
    {
      this->sout_ << ", ";
      iter->Accept (*this);
    }

    this->sout_ << "));" << std::endl;
  }

  //
  // Visit_Property
  //
  void UDM_CIAO_Visitor::Visit_Property (const PICML::Property & property)
  {
    // Get the data type for the property and store the value
    // for later use.
    PICML::DataType dt = property.DataType_child ();
    PICML::PredefinedType pre_type = dt.ref ();
    this->temp_str_ = property.DataValue ();

    // Determine with predefined type this object is, if indeed it
    // is a predefined type.

    if ((std::string) pre_type.type ().name () ==
        (std::string) PICML::String::meta.name ())
    {
      PICML::String::Cast (pre_type).Accept (*this);
    }
    else if ((std::string) pre_type.type ().name () ==
              (std::string) PICML::LongInteger::meta.name ())
    {
      PICML::LongInteger::Cast (pre_type).Accept (*this);
    }
  }

  //
  // Visit_String
  //
  void UDM_CIAO_Visitor::Visit_String (const PICML::String & str)
  {
    this->sout_ << "\"" << this->temp_str_ << "\"";
  }

  //
  // Visit_LongInteger
  //
  void UDM_CIAO_Visitor::Visit_LongInteger (const PICML::LongInteger & li)
  {
    this->sout_ << this->temp_str_;
  }

  //
  // Visit_OutEventPort
  //
  void UDM_CIAO_Visitor::Visit_OutEventPort (const PICML::OutEventPort & oep)
  {
    PICML::Event event = oep.ref ();

    if (event != Udm::null)
    {
      event.Accept (*this);
      this->event_map_.insert (Event_Map::value_type (oep.name (),
                                                      this->temp_str_));
    }
  }

  //
  // generate_scope
  //
  void UDM_CIAO_Visitor::generate_scope (const std::string & seperator)
  {
    this->temp_str_.clear ();

    for (Scope_List::iterator iter = this->scope_.begin ();
         iter != this->scope_.end ();
         iter ++)
    {
      this->temp_str_.append (*iter);
      this->temp_str_.append (seperator);
    }
  }

  //
  // generate_set_session_context
  //
  void UDM_CIAO_Visitor::generate_set_session_context (
    const PICML::Component & component)
  {
    const char * SET_SESSION_CONTEXT =
      "set_session_context (\n"
      "::Components::SessionContext_ptr ctx\n"
      "ACE_ENV_ARG_DECL_WITH_DEFAULTS)\n"
      "  ACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hout_
      << "// SessionComponent: set_session_context" << std::endl
      << "void " << SET_SESSION_CONTEXT << ";" << std::endl;

    this->sout_
      << "//" << std::endl
      << "// SessionComponent: set_session_context" << std::endl
      << "//" << std::endl
      << "void " << this->component_ << "::" << SET_SESSION_CONTEXT
      << "{"
      << "CoWorkEr_Type::set_session_context (ctx);";

    // Generate the <CIAO_REGISTER_OBV_FACTORY> methods
    if (!this->event_types_.empty ())
    {
      this->sout_ << std::endl;

      for (String_Set::iterator iter = this->event_types_.begin ();
           iter != this->event_types_.end ();
           iter ++)
      {
        this->sout_
          << "CIAO_REGISTER_OBV_FACTORY (" << *iter << "_init," << std::endl
          << *iter << ");";
      }
    }

    // Set the context for the event producer if there are
    // any output events.
    if (this->has_out_events_)
    {
      this->sout_
        << std::endl
        << "// Set the context for the <event_producer_>." << std::endl
        << "this->event_producer_.context (this->context_);";
    }

    this->sout_
      << "}";
  }

  //
  // reset_file_info
  //
  void UDM_CIAO_Visitor::reset_file_info (void)
  {
    //this->file_depends_.clear ();
    //this->file_config_ = this->config_.end ();
  }

  //
  // reset_component_info
  //
  void UDM_CIAO_Visitor::reset_component_info (void)
  {
    this->event_sinks_.clear ();
    this->event_types_.clear ();
    this->event_map_.clear ();

    this->has_out_events_ = false;
    this->has_activate_ = false;
  }

  //
  // generate_ciao_preactivate
  //
  void UDM_CIAO_Visitor::generate_ciao_preactivate (
    const PICML::Component & component)
  {
    const char * CIAO_PREACTIVATE =
      "ciao_preactivate (\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "  ACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    // Generate the method declaration.
    this->hout_
      << "// SessionComponent: ciao_preactivate" << std::endl
      << "void " << CIAO_PREACTIVATE << ";" << std::endl;

    // Generate the method definition.
    this->sout_
      << "//" << std::endl
      << "// SessionComponent: ciao_preactivate" << std::endl
      << "//" << std::endl
      << "void " << this->component_ << "::" << CIAO_PREACTIVATE
      << "{"
      << "// Pass control to the base class." << std::endl
      << "CoWorkEr_Type::ciao_preactivate ();";

    // Set the parents for all the workers in this component.
    typedef std::set <PICML::WorkerType> WorkerType_Set;
    WorkerType_Set workers = component.WorkerType_kind_children ();

    if (!workers.empty ())
    {
      this->sout_
        << std::endl
        << "// Initialize all the workers for this component." << std::endl;

      for (WorkerType_Set::const_iterator iter = workers.begin ();
          iter != workers.end ();
          iter ++)
      {
        this->sout_
          << "this->" << iter->name () << "_.parent (this->registration_id_);";
      }
    }

    if (this->has_out_events_)
    {
      this->sout_
        << std::endl
        << "// Activate the event producer." << std::endl
        << "this->event_producer_.activate (this->registration_id_);";
    }

    // Activate all the event handlers.
    if (!this->event_sinks_.empty ())
    {
      this->sout_
        << std::endl
        << "// Activate the event handlers." << std::endl;

      for (String_Set::const_iterator iter = this->event_sinks_.begin ();
          iter != this->event_sinks_.end ();
          iter ++)
      {
        this->sout_
          << "this->" << EVENT_SINK_PREFIX << *iter
          << EVENT_SINK_POSTFIX << "_.activate ();";
      }
    }

    this->sout_ << "}";
  }

  //
  // generate_ccm_activate
  //
  void UDM_CIAO_Visitor::generate_ccm_activate (const PICML::Component &)
  {
    const char * CCM_ACTIVATE =
      "ccm_activate (\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "  ACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hout_
      << "// SessionComponent: ccm_activate" << std::endl
      << "void " << CCM_ACTIVATE << ";" << std::endl;

    this->sout_
      << "//" << std::endl
      << "// SessionComponent: ccm_activate" << std::endl
      << "//" << std::endl
      << "void " << this->component_ << "::" << CCM_ACTIVATE
      << "{";

    if (this->has_activate_)
    {
      this->sout_ << "this->cuts_activate ();";
    }

    this->sout_ << "}";
  }

  //
  // generate_ciao_postactivate
  //
  void UDM_CIAO_Visitor::generate_ciao_postactivate (
    const PICML::Component & component)
  {
    const char * CIAO_POSTACTIVATE =
      "ciao_postactivate (\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "  ACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hout_
      << "// SessionComponent: ciao_postactivate" << std::endl
      << "void " << CIAO_POSTACTIVATE << ";" << std::endl;

    this->sout_
      << "//" << std::endl
      << "// SessionComponent: ciao_postactivate" << std::endl
      << "//" << std::endl
      << "void " << this->component_ << "::" << CIAO_POSTACTIVATE
      << "{";

    // Generate the code to activate all of the periodic events
    // if there are any in this component.
    typedef std::set <PICML::PeriodicAction> Periodic_Set;
    Periodic_Set pset = component.PeriodicAction_kind_children ();

    for (Periodic_Set::iterator iter = pset.begin ();
         iter != pset.end ();
         iter ++)
    {
      this->sout_
        << "this->periodic_" << iter->name () << "_.activate ("
        << iter->Period () << ");";
    }

    this->sout_
      << "}";
  }

  //
  // generate_ccm_passivate
  //
  void UDM_CIAO_Visitor::generate_ccm_passivate (
    const PICML::Component & component)
  {
    const char * CCM_PASSIVATE =
      "ccm_passivate (\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "  ACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hout_
      << "// SessionComponent: ccm_passivate" << std::endl
      << "void " << CCM_PASSIVATE << ";" << std::endl;

    this->sout_
      << "//" << std::endl
      << "// SessionComponent: ccm_passivate" << std::endl
      << "//" << std::endl
      << "void " << this->component_ << "::" << CCM_PASSIVATE
      << "{"
      << "// Pass control to the base class." << std::endl
      << "CoWorkEr_Type::ccm_passivate ();";

    // Generate the code to deactivate all of the periodic events
    // if there are any in this component.
    typedef std::set <PICML::PeriodicAction> Periodic_Set;
    Periodic_Set pset = component.PeriodicAction_kind_children ();

    if (!pset.empty ())
    {
      this->sout_
        << std::endl
        << "// Deactivating all the periodic events" << std::endl;

      for (Periodic_Set::iterator iter = pset.begin ();
           iter != pset.end ();
           iter ++)
      {
        this->sout_
          << "this->periodic_" << iter->name () << "_.deactivate ();";
      }
    }

    // Generate the necessary code to deactivate all the event
    // producers if there are any.
    if (this->has_out_events_)
    {
      this->sout_
        << std::endl
        << "// Deactivate the event producer." << std::endl
        << "this->event_producer_.deactivate ();";
    }

    // Activate all the event handlers.
    if (!this->event_sinks_.empty ())
    {
      this->sout_
        << std::endl
        << "// Activate the event handlers." << std::endl;

      for (String_Set::const_iterator iter = this->event_sinks_.begin ();
          iter != this->event_sinks_.end ();
          iter ++)
      {
        this->sout_
          << "this->" << EVENT_SINK_PREFIX << *iter
          << EVENT_SINK_POSTFIX << "_.deactivate ();";
      }
    }

    this->sout_ << "}";
  }

  //
  // generate_ccm_remove
  //
  void UDM_CIAO_Visitor::generate_ccm_remove (
    const PICML::Component & component)
  {
    const char * CCM_REMOVE =
      "ccm_remove (\n"
      "ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)\n"
      "  ACE_THROW_SPEC ((::CORBA::SystemException,\n"
      "::Components::CCMException))";

    this->hout_
      << "// SessionComponent: ccm_remove" << std::endl
      << "void " << CCM_REMOVE << ";" << std::endl;

    this->sout_
      << "//" << std::endl
      << "// SessionComponent: ccm_remove" << std::endl
      << "//" << std::endl
      << "void " << this->component_ << "::" << CCM_REMOVE
      << "{"
      << "CoWorkEr_Type::ccm_remove ();"
      << "}";
  }

  //
  // Visit_PeriodicAction
  //
  void UDM_CIAO_Visitor::Visit_PeriodicAction (
    const PICML::PeriodicAction & action)
  {
    const char * PREFIX = "periodic_";

    this->hout_
      << "// periodic event: " << action.name () << std::endl
      << "void " << PREFIX << action.name () << " (void);";

    this->sout_
      << "//" << std::endl
      << "// periodic event: " << action.name () << std::endl
      << "//" << std::endl
      << "void " << this->component_ << "::"
      << PREFIX << action.name () << " (void){"
      << "CUTS_Activation_Record dummy_record;"
      << "CUTS_Activation_Record * record = &dummy_record;"
      << std::endl;

    // Push this input action onto the call stack.
    this->call_stack_.push (action);

    // Start parsing this action sequence.
    PICML::Effect effect = action.dstInputEffect ();
    effect.Accept (*this);

    this->sout_ << "}";
  }

  //
  // Visit_OutputAction
  //
  void UDM_CIAO_Visitor::Visit_OutputAction (
    const PICML::OutputAction & output)
  {
    size_t size = 0;
    // Generate the parameters for the action.
    typedef std::set <PICML::Property> Property_Set;
    Property_Set properties = output.Property_kind_children ();

    for (Property_Set::iterator iter = properties.begin ();
         iter != properties.end ();
         iter ++)
    {
      if ((std::string) iter->name () == "size")
      {
        // Convert string to an integer.
        std::string value = iter->DataValue ();
        std::istringstream (value) >> size;
        break;
      }
    }

    // Generate the preamble for the worker action.
    this->sout_
      << "record->record_exit_point (" << std::endl
      << "\"" << output.name () << "\"," << std::endl
      << "Event_Producer::";

    // Determine the type of event to push based on the size.
    if (size == 0)
    {
      this->sout_ << "Push_Event <";
    }
    else
    {
      this->sout_ << "Push_Data_Event <";
    }

    this->sout_
      << std::endl << "OBV_";

    Event_Map::iterator result = this->event_map_.find (output.name ());

    if (result != this->event_map_.end ())
    {
      this->sout_ << result->second << ", " << result->second << "> (" << std::endl;
    }

    this->sout_
      << "this->event_producer_, ";

    if (size > 0)
    {
      this->sout_ << size << ", ";
    }

    this->sout_
      << "&Event_Producer::Context::"
      << EVENT_SINK_PREFIX << output.name () << "));"
      << std::endl;
  }

  //
  // Visit_Environment
  //
  void UDM_CIAO_Visitor::Visit_Environment (const PICML::Environment & env)
  {
    // Get all the inputs from the environment.
    typedef std::set <PICML::MultiInput> MultiInput_Set;
    MultiInput_Set inputs = env.dstMultiInput ();

    for (MultiInput_Set::const_iterator iter = inputs.begin ();
         iter != inputs.end ();
         iter ++)
    {
      PICML::InputAction action =
        PICML::InputAction::Cast (iter->dstMultiInput_end ());

      if ((std::string) action.name () == "activate")
      {
        this->has_activate_ = true;

        this->hout_
          << "// Environment: activate" << std::endl
          << "void cuts_activate (void);" << std::endl;

        this->sout_
          << "//" << std::endl
          << "// Environment: activate" << std::endl
          << "//" << std::endl
          << "void " << this->component_ << "::" << "cuts_activate (void){"
          << "CUTS_Activation_Record dummy_record;"
          << "CUTS_Activation_Record * record = &dummy_record;" << std::endl;

        action.Accept (*this);

        this->sout_ << "}";
      }
    }
  }

  //
  // Visit_CompositeAction
  //
  void UDM_CIAO_Visitor::Visit_CompositeAction (const PICML::CompositeAction & ca)
  {
    PICML::InputAction action = ca.InputAction_child ();
    action.Accept (*this);
  }

  //
  // Visit_Variable
  //
  void UDM_CIAO_Visitor::Visit_Variable (const PICML::Variable & variable)
  {
    PICML::PredefinedType ptype = variable.ref ();
    std::string str_type = ptype.type ().name ();

    this->hout_
      << "// Variable: " << variable.name () << std::endl
      << CUTS_Predefined_Type_Map::instance ()->c_str (str_type.c_str ())
      << " "
      << variable.name ()
      << ";";
  }

  //
  // Visit_ProvidedRequestPort
  //
  void UDM_CIAO_Visitor::Visit_ProvidedRequestPort (
    const PICML::ProvidedRequestPort & facet)
  {
    try
    {
      // Get the object that is provided by this facet.
      PICML::Object object = PICML::Object::Cast (facet.ref ());
      object.Accept (*this);

      this->hout_
        << "// facet: " << facet.name () << std::endl
        << "virtual " << this->temp_str_
        << "CCM_" << object.name () << "_ptr" << std::endl
        << "  get_" << facet.name ()
        << " (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
        << "  ACE_THROW_SPEC ((CORBA::SystemException));" << std::endl;

      this->sout_
        << "// facet: " << facet.name () << std::endl
        << this->temp_str_
        << "CCM_" << object.name () << "_ptr" << std::endl
        << "  " << this->component_ << "::get_" << facet.name ()
        << " (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)" << std::endl
        << "  ACE_THROW_SPEC ((CORBA::SystemException)){"
        << "return " << this->temp_str_ << "CCM_" << object.name ()
        << "::_nil ();"
        << "}";
    }
    catch (...)
    {
      // We failed to cast the reference
    }
  }

  //
  // Visit_Object
  //
  void UDM_CIAO_Visitor::Visit_Object (const PICML::Object & object)
  {
    this->generate_scope (object);
  }

  //
  // generate_full_scope
  //
  void UDM_CIAO_Visitor::generate_scope (const PICML::MgaObject & object)
  {
    this->temp_str_.clear ();

    PICML::Package package;

    // Store the name of the event type and get its parent.
    PICML::MgaObject parent = PICML::MgaObject::Cast (object.parent ());

    // Continue building the name of the event type until we have
    // reached the File, or end of the Package tree.
    while ((std::string) parent.type ().name () ==
           (std::string) PICML::Package::meta.name ())
    {
      package = PICML::Package::Cast (parent);

      this->temp_str_.append (package.name ());
      this->temp_str_.append ("::");

      parent = package.parent ();
    }
  }
}
