// $Id$

#include "XML_Generators.h"
#include "cuts/be/BE_Options.h"
#include "cuts/be/BE_Scope_Manager.h"
#include "cuts/be/BE_Preprocessor.h"
#include "boost/bind.hpp"
#include "Uml.h"

// ACE headers
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

// code generation headers
#include "CCF/CodeGenerationKit/IndentationXML.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#define CUTS_BE_XML() \
  ACE_Singleton <CUTS_BE_Xml, ACE_Null_Mutex>::instance ()

//
// CUTS_BE_Xml
//
CUTS_BE_Xml::CUTS_BE_Xml (void)
{

}

//
// CUTS_BE_File_Open_T
//
bool CUTS_BE_File_Open_T <CUTS_BE_Xml>::
generate (const PICML::ComponentImplementationContainer & container,
          const PICML::MonolithicImplementation & impl)
{
  // Locate the preprocessing of the implementation. If this is a
  // proxy implementation, then we ignore it. It's going to cause
  // more problems than we would like.
  const CUTS_BE_Impl_Node * node = 0;
  CUTS_BE_PREPROCESSOR ()->impls ().find (container.name (), node);

  if (node != 0 && node->is_proxy_)
    return false;

  std::string filename =
    CUTS_BE_OPTIONS ()->output_directory_ + "/"
    + (std::string) container.name () + ".xml";

  if (!CUTS_BE_XML ()->outfile_.good ())
    CUTS_BE_XML ()->outfile_.clear ();

  // Open the XML file for writing.
  CUTS_BE_XML ()->outfile_.open (filename.c_str ());

  if (CUTS_BE_XML ()->outfile_.is_open ())
  {
    // Create a formatter for the XML file.
    CUTS_BE_XML ()->formatter_.reset (
      new CUTS_BE_Xml::_formatter_type (CUTS_BE_XML ()->outfile_));

    return true;
  }
  else
  {
    return false;
  }
}

//
// CUTS_BE_File_Close_T
//
bool CUTS_BE_File_Close_T <CUTS_BE_Xml>::
generate (const PICML::ComponentImplementationContainer & container,
          const PICML::MonolithicImplementation & impl)
{
  if (CUTS_BE_XML ()->outfile_.is_open ())
  {
    CUTS_BE_XML ()->formatter_.reset ();
    CUTS_BE_XML ()->outfile_.close ();
  }

  return true;
}

//
// CUTS_BE_Prologue_T
//
bool CUTS_BE_Prologue_T <CUTS_BE_Xml>::
generate (const PICML::ComponentImplementationContainer & container,
          const PICML::MonolithicImplementation & impl)
{
  CUTS_BE_XML ()->outfile_
    << "<?xml version=\"1.0\" encoding=\"UTF-8\" standalone=\"yes\"?>"
    << std::endl;

  return true;
}

//
// CUTS_BE_Component_Impl_Begin_T
//
bool CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Xml>::
generate (const PICML::MonolithicImplementation & mono,
          const PICML::Component & component)
{
  CUTS_BE_XML ()->outfile_
    << "<cuts:behavior type=\"" << component.name () << "\">" << std::endl;

  return true;
}

//
// CUTS_BE_Component_Impl_End_T
//
bool CUTS_BE_Component_Impl_End_T <CUTS_BE_Xml>::
generate (const PICML::MonolithicImplementation & mono,
          const PICML::Component & component)
{
  CUTS_BE_XML ()->outfile_
    << "</cuts:behavior>" << std::endl;
  return true;
}

//
// CUTS_BE_Variables_Begin_T
//
bool CUTS_BE_Variables_Begin_T <CUTS_BE_Xml>::
generate (const PICML::Component & component)
{
  CUTS_BE_XML ()->outfile_ << "<variables>" << std::endl;
  return true;
}

//
// CUTS_BE_Variable_T
//
bool CUTS_BE_Variable_T <CUTS_BE_Xml>::
generate (const PICML::Variable & variable)
{
  PICML::PredefinedType type = variable.ref ();

  if (type != Udm::null)
  {
    CUTS_BE_XML ()->outfile_
      << "<variable name=\"" << variable.name () << "\" "
      << "type=\"" << type.name () << "\" />" << std::endl;
  }

  return true;
}

//
// CUTS_BE_Worker_Variable_T
//
bool CUTS_BE_Worker_Variable_T <CUTS_BE_Xml>::
generate (const PICML::WorkerType & type, const PICML::Worker & worker)
{
  CUTS_BE_XML ()->outfile_
    << "<worker name=\"" << type.name () << "\" type=\""
    << worker.name () << "\" />" << std::endl;

  return true;
}

//
// CUTS_BE_Variables_Begin_T
//
bool CUTS_BE_Variables_End_T <CUTS_BE_Xml>::
generate (const PICML::Component & component)
{
  CUTS_BE_XML ()->outfile_ << "</variables>" << std::endl;
  return true;
}

//
// CUTS_BE_WorkerAction_Begin_T
//
bool CUTS_BE_WorkerAction_Begin_T <CUTS_BE_Xml>::
generate (const PICML::Worker & worker, const PICML::Action & action)
{
  PICML::Action action_type =
    const_cast <PICML::Action &> (action).Archetype ();

  CUTS_BE_XML ()->outfile_
    << "<action parent=\"" << action.name () << "\" name=\""
    << action_type.name () << "\">" << std::endl;

  return true;
}

//
// CUTS_BE_Action_Property_T
//
bool CUTS_BE_Action_Property_T <CUTS_BE_Xml>::
generate (const PICML::Property & property)
{
  // Get the datatype for the property.
  PICML::DataType datatype = property.DataType_child ();

  if (datatype != Udm::null)
  {
    try
    {
      PICML::PredefinedType type =
        PICML::PredefinedType::Cast (datatype.ref ());

      CUTS_BE_XML ()->outfile_
        << "<property name=\"" << property.name () << "\" "
        << "type=\"" << type.name () << "\" value=\""
        << property.DataValue () << "\" />" << std::endl;
    }
    catch (...)
    {

    }
  }

  return true;
}

//
// CUTS_BE_Action_End_T
//
bool CUTS_BE_Action_End_T <CUTS_BE_Xml>::generate (void)
{
  CUTS_BE_XML ()->outfile_ << "</action>" << std::endl;
  return true;
}

//
// CUTS_BE_InEventPort_Begin_T
//
bool CUTS_BE_InEventPort_Begin_T <CUTS_BE_Xml>::
generate (const PICML::InEventPort & sink)
{
  CUTS_BE_XML ()->outfile_
    << "<inevent name=\"" << sink.name () << "\" >" << std::endl;

  return true;
};

//
// CUTS_BE_InEventPort_End_T
//
bool CUTS_BE_InEventPort_End_T <CUTS_BE_Xml>::
generate (const PICML::InEventPort & sink)
{
  CUTS_BE_XML ()->outfile_ << "</inevent>" << std::endl;
  return true;
}

//
// CUTS_BE_Environment_Begin_T
//
bool CUTS_BE_Environment_Begin_T <CUTS_BE_Xml>::
generate (const PICML::Component & component)
{
  CUTS_BE_XML ()->outfile_ << "<environments>" << std::endl;
  return true;
}

//
// CUTS_BE_Environment_Method_Begin_T
//
bool CUTS_BE_Environment_Method_Begin_T <CUTS_BE_Xml>::
generate (const PICML::InputAction & action)
{
  CUTS_BE_XML ()->outfile_
    << "<environment name=\"" << action.name () << "\">" << std::endl;

  return true;
}

//
// CUTS_BE_Environment_Method_Begin_T
//
bool CUTS_BE_Environment_Method_End_T <CUTS_BE_Xml>::
generate (const PICML::InputAction & action)
{
  CUTS_BE_XML ()->outfile_ << "</environment>" << std::endl;
  return true;
}

//
// CUTS_BE_Environment_End_T
//
bool CUTS_BE_Environment_End_T <CUTS_BE_Xml>::
generate (const PICML::Component & component)
{
  CUTS_BE_XML ()->outfile_ << "</environments>" << std::endl;
  return true;
}

//
// CUTS_BE_PeriodicEvent_Begin_T
//
bool CUTS_BE_PeriodicEvent_Begin_T <CUTS_BE_Xml>::
generate (const PICML::PeriodicEvent & periodic)
{
  CUTS_BE_XML ()->outfile_
    << "<periodic period=\"" << periodic.Period ()
    << "\" probability=\"" << periodic.Probability () << "\">" << std::endl;

  return true;
}

//
// CUTS_BE_PeriodicEvent_End_T
//
bool CUTS_BE_PeriodicEvent_End_T <CUTS_BE_Xml>::
generate (const PICML::PeriodicEvent & periodic)
{
  CUTS_BE_XML ()->outfile_ << "</periodic>" << std::endl;
  return true;
}

//
// CUTS_BE_OutputAction_Begin_T
//
bool CUTS_BE_OutputAction_Begin_T <CUTS_BE_Xml>::
generate (const PICML::OutputAction & action)
{
  CUTS_BE_XML ()->outfile_
    << "<output name=\"" << action.name () << "\">" << std::endl;

  return true;
}

//
// CUTS_BE_OutputAction_End_T
//
bool CUTS_BE_OutputAction_End_T <CUTS_BE_Xml>::
generate (const PICML::OutputAction & action)
{
  CUTS_BE_XML ()->outfile_ << "</output>" << std::endl;
  return true;
}

//
// CUTS_BE_Action_Property_T
//
bool CUTS_BE_OutputAction_Property_T <CUTS_BE_Xml>::
generate (const PICML::OutputAction & action,
          const PICML::Property & property)
{
  return CUTS_BE_Action_Property_T <CUTS_BE_Xml>::generate (property);
}

//
// CUTS_BE_Branches_Begin_T
//
bool CUTS_BE_Branches_Begin_T <CUTS_BE_Xml>::generate (size_t branches)
{
  CUTS_BE_XML ()->outfile_ << "<branches>" << std::endl;
  return true;
}

//
// CUTS_BE_Branch_Condition_Begin_T
//
bool CUTS_BE_Branch_Condition_Begin_T <CUTS_BE_Xml>::generate (void)
{
  CUTS_BE_XML ()->outfile_ << "<branch>" << std::endl;
  return true;
}

//
// CUTS_BE_Branch_End_T
//
bool CUTS_BE_Branch_End_T <CUTS_BE_Xml>::generate (void)
{
  CUTS_BE_XML ()->outfile_ << "</branch>" << std::endl;
  return true;
}

//
// CUTS_BE_Branches_End_T
//
bool CUTS_BE_Branches_End_T <CUTS_BE_Xml>::generate (void)
{
  CUTS_BE_XML ()->outfile_ << "</branches>" << std::endl;
  return true;
};

//
// CUTS_BE_Precondition_T
//
bool CUTS_BE_Precondition_T <CUTS_BE_Xml>::
generate (const std::string & precondition)
{

  CUTS_BE_XML ()->outfile_
    << "<condition>" << precondition << "</condition>" << std::endl;

  return true;
}
