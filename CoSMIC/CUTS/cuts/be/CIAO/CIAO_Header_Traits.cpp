// $Id$

#include "CIAO_Header_Traits.h"

#if !defined (__CUTS_INLINE__)
#include "CIAO_Header_Traits.inl"
#endif

#include "CIAO_Var_Type.h"
#include "CIAO_Retn_Type.h"
#include "CIAO_In_Type.h"
#include "Export_File_Generator.h"
#include "cuts/be/BE_Options.h"

// UDM headers
#include "Uml.h"

// STL headers
#include <algorithm>
#include <fstream>

//
// CUTS_CIAO_Header_Traits
//
CUTS_CIAO_Header_Traits::
CUTS_CIAO_Header_Traits (void)
{

}

//
// ~CUTS_CIAO_Header_Traits
//
CUTS_CIAO_Header_Traits::
~CUTS_CIAO_Header_Traits (void)
{

}

//
// write_environment_begin
//
void CUTS_CIAO_Header_Traits::
write_environment_begin (const PICML::Component & component)
{
  this->outfile ()
    << "protected:" << std::endl;

  this->_super::write_environment_begin (component);
}


//
// write_method_begin
//
void CUTS_CIAO_Header_Traits::
write_method_begin (const PICML::InEventPort & sink)
{
  this->outfile ()
    << single_line_comment ("EventSink: " + (std::string)sink.name ())
    << "virtual void ";

  this->_super::write_method_begin (sink);
}

//
// write_method_end
//
void CUTS_CIAO_Header_Traits::
write_method_end (const PICML::InEventPort & sink)
{
  this->outfile ()
    << ";" << std::endl;
}

//
// write_method_begin
//
void CUTS_CIAO_Header_Traits::
write_method_begin (const PICML::PeriodicEvent & periodic)
{
  this->outfile ()
    << single_line_comment ("PeriodicEvent: " + (std::string)periodic.name ())
    << "void ";

  this->_super::write_method_begin (periodic);
}

//
// write_method_end
//
void CUTS_CIAO_Header_Traits::
write_method_end (const PICML::PeriodicEvent & sink)
{
  this->outfile ()
    << ";" << std::endl;
}

//
// write_method
//
void CUTS_CIAO_Header_Traits::
write_method (const PICML::OutEventPort & source)
{
  this->outfile ()
    << single_line_comment ("EventSource: " + (std::string)source.name ())
    << "virtual void ";

  this->_super::write_method (source);

  this->outfile ()
    << ";"
    << std::endl;
}

//
// write_method
//
void CUTS_CIAO_Header_Traits::
write_method (const PICML::RequiredRequestPort & receptacle)
{
  PICML::Object object = PICML::Object::Cast (receptacle.ref ());

  this->outfile ()
    << single_line_comment ("Receptacle: " + (std::string)receptacle.name ())
    << "virtual " << scope (object, "::") << object.name () << "_ptr "
    << std::endl << "  ";

  this->_super::write_method (receptacle);

  this->outfile ()
    << ";"
    << std::endl;
}

//
// write_method_begin
//
void CUTS_CIAO_Header_Traits::
write_method_begin (const PICML::ProvidedRequestPort & facet)
{
  this->outfile ()
    << single_line_comment ("Facet: " + (std::string)facet.name ())
    << "virtual void ";

  this->_super::write_method_begin (facet);
}

//
// write_method_end
//
void CUTS_CIAO_Header_Traits::
write_method_end (const PICML::ProvidedRequestPort & facet)
{
  this->outfile ()
    << ";" << std::endl;
}

//
// write_set_session_context
//
void CUTS_CIAO_Header_Traits::
write_set_session_context (const PICML::Component & component)
{
  this->outfile ()
    << single_line_comment ("Environment: set_session_context")
    << "virtual void ";

  this->_super::write_set_session_context (component);

  this->outfile ()
    << ";" << std::endl;
}

//
// write_ciao_preactivate
//
void CUTS_CIAO_Header_Traits::
write_ciao_preactivate (const PICML::Component & component)
{
  this->outfile ()
    << single_line_comment ("Environment: preactivate")
    << "virtual void ";

  this->_super::write_ciao_preactivate (component);

  this->outfile ()
    << ";" << std::endl;
}

//
// write_cmm_activate
//
void CUTS_CIAO_Header_Traits::
write_ccm_activate (const PICML::Component & component)
{
  this->outfile ()
    << single_line_comment ("Environment: activate")
    << "virtual void ";

  this->_super::write_ccm_activate (component);

  this->outfile ()
    << ";" << std::endl;
}

//
// write_ciao_postactivate
//
void CUTS_CIAO_Header_Traits::
write_ciao_postactivate (const PICML::Component & component)
{
  this->outfile ()
    << single_line_comment ("Environment: postactivate")
    << "virtual void ";

  this->_super::write_ciao_postactivate (component);

  this->outfile ()
    << ";" << std::endl;
}

//
// write_ccm_passivate
//
void CUTS_CIAO_Header_Traits::
write_ccm_passivate (const PICML::Component & component)
{
  this->outfile ()
    << single_line_comment ("Environment: passivate")
    << "virtual void ";

  this->_super::write_ccm_passivate (component);

  this->outfile ()
    << ";" << std::endl;
}

//
// write_ccm_remove
//
void CUTS_CIAO_Header_Traits::
write_ccm_remove (const PICML::Component & component)
{
  this->outfile ()
    << single_line_comment ("Environment: remove")
    << "virtual void ";

  this->_super::write_ccm_remove (component);

  this->outfile ()
    << ";" << std::endl;
}

//
// write_method_begin
//
void CUTS_CIAO_Header_Traits::
write_method_begin (const PICML::ReadonlyAttribute & attr)
{
  PICML::AttributeMember member = attr.AttributeMember_child ();

  if (member != Udm::null)
  {
    PICML::MemberType mtype = member.ref ();

    if (mtype != Udm::null)
    {
      // Write the getter method for the attribute.
      this->outfile ()
        << single_line_comment ("get " + (std::string)attr.name ())
        << "virtual "
        << CUTS_CIAO_Retn_Type (mtype)
        << " ";

      this->_super::write_method_begin (attr);
    }
  }
}

//
// write_method_end
//
void CUTS_CIAO_Header_Traits::
write_method_end (const PICML::ReadonlyAttribute & attr)
{
  this->outfile ()
    << ";" << std::endl;
}

//
// write_method_begin
//
void CUTS_CIAO_Header_Traits::
write_method_begin (const PICML::Attribute & attr)
{
  // Generate the getter method for the attribute.
  PICML::Attribute temp_attr (attr);
  PICML::ReadonlyAttribute ro = PICML::ReadonlyAttribute::Cast (temp_attr);

  this->write_method_begin (ro);
  this->write_method_end (ro);

  // Close the getter method and generate the setter method
  // for the current attribute.
  this->outfile ()
    << single_line_comment ("set " + (std::string)attr.name ())
    << "virtual void ";

  this->_super::write_method_begin (attr);
}

//
// write_method_end
//
void CUTS_CIAO_Header_Traits::
write_method_end (const PICML::Attribute & attr)
{
  this->outfile ()
    << ";" << std::endl;
}

//
// write_variables_begin
//
void CUTS_CIAO_Header_Traits::
write_variables_begin (const PICML::Component & component)
{
  this->outfile ()
    << "private:" << std::endl;
}
