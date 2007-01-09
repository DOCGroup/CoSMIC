// $Id$

#include "CIAO_Source_Traits.h"

#if !defined (__CUTS_INLINE__)
#include "CIAO_Source_Traits.inl"
#endif

// CUTS headers
#include "CIAO_Retn_Type.h"
#include "CIAO_In_Type.h"
#include "CIAO_Var_Type.h"

// STL headers
#include <sstream>

//
// CUTS_CIAO_Source_Traits
//
CUTS_CIAO_Source_Traits::
CUTS_CIAO_Source_Traits (void)
{

}

//
// ~CUTS_CIAO_Source_Traits
//
CUTS_CIAO_Source_Traits::
~CUTS_CIAO_Source_Traits (void)
{

}

//
// write_method_begin
//
void CUTS_CIAO_Source_Traits::
write_method_begin (const PICML::ProvidedRequestPort & facet)
{
  PICML::Component parent = PICML::Component::Cast (facet.parent ());
  PICML::Object obj = PICML::Object::Cast (facet.ref ());

  if (obj == Udm::null)
    return;

  std::string obj_scope = scope (obj, "::");

  this->outfile ()
    << function_header ("Facet: get_" + (std::string)facet.name ())
    << obj_scope << "CCM_" << obj.name () << "_ptr" << std::endl
    << "  " << parent.name () << "::";

  this->_super::write_method_begin (facet);

  this->outfile ()
    << "{";
}

//
// write_method_end
//
void CUTS_CIAO_Source_Traits::
write_method_end (const PICML::ProvidedRequestPort & facet)
{
  this->outfile ()
    << "}";
}

//
// write_method_begin
//
void CUTS_CIAO_Source_Traits::
write_method_begin (const PICML::InEventPort & sink)
{
  PICML::Component parent = PICML::Component::Cast (sink.parent ());

  this->outfile ()
    << function_header ("EventSink: push_" + (std::string)sink.name ())
    << "void " << parent.name () << "::";

  this->_super::write_method_begin (sink);

  this->outfile ()
    << "{";
}

//
// write_method
//
void CUTS_CIAO_Source_Traits::
write_method (const PICML::OutEventPort & source)
{
  PICML::Component parent =
    PICML::Component::Cast (source.parent ());

  this->outfile ()
    << function_header ("EventSource: " + (std::string)source.name ())
    << "void " << parent.name () << "_Context_Proxy::" << std::endl
    << "  ";

  this->_super::write_method (source);

  this->outfile ()
    << "{";
}

//
// write_method
//
void CUTS_CIAO_Source_Traits::
write_method (const PICML::RequiredRequestPort & receptacle)
{
  PICML::Component parent =
    PICML::Component::Cast (receptacle.parent ());

  PICML::Object object = PICML::Object::Cast (receptacle.ref ());

  this->outfile ()
    << function_header ("Receptacle: " + (std::string)receptacle.name ())
    << scope (object, "::") << object.name () << "_ptr "
    << parent.name () << "_Context_Proxy::" << std::endl
    << "  ";

  this->_super::write_method (receptacle);

  this->outfile ()
    << "{";
}

//
// write_method_end
//
void CUTS_CIAO_Source_Traits::
write_method_end (const PICML::InEventPort & sink)
{
  this->outfile ()
    << "}";
}

//
// write_method_begin [PeriodicEvent]
//
void CUTS_CIAO_Source_Traits::
write_method_begin (const PICML::PeriodicEvent & periodic)
{
  // Write the getter method for the attribute.
  PICML::Component parent = PICML::Component::Cast (periodic.parent ());

  this->outfile ()
    << function_header (periodic.name ())
    << "void " << parent.name () << "::";

  // Write the class scope resolution.
  this->_super::write_method_begin (periodic);

  this->outfile ()
    << "{";
}

//
// write_method_end [PeriodicEvent]
//
void CUTS_CIAO_Source_Traits::
write_method_end (const PICML::PeriodicEvent & periodic)
{
  this->outfile ()
    << "}";
}

//
// write_method_begin [ReadonlyAttribute]
//
void CUTS_CIAO_Source_Traits::
write_method_begin (const PICML::ReadonlyAttribute & ro_attr)
{
  PICML::AttributeMember member = ro_attr.AttributeMember_child ();
  PICML::MemberType mtype = member.ref ();

  // Write the getter method for the attribute.
  this->outfile ()
    << function_header ((std::string)ro_attr.name () + " [getter]")
    << CUTS_CIAO_Retn_Type (mtype);

  PICML::Component parent = ro_attr.Component_parent ();

  this->outfile ()
    << " " << parent.name () << "::";

  // Write the class scope resolution.
  this->_super::write_method_begin (ro_attr);

  this->outfile ()
    << "{";
}

//
// write_method_end [ReadonlyAttribute]
//
void CUTS_CIAO_Source_Traits::
write_method_end (const PICML::ReadonlyAttribute & ro_attr)
{
  this->outfile ()
    << "}";
}

//
// write_method_begin [Attribute]
//
void CUTS_CIAO_Source_Traits::
write_method_begin (const PICML::Attribute & attr)
{
  // Generate the getter method for the attribute.
  PICML::Attribute temp_attr (attr);
  PICML::ReadonlyAttribute ro = PICML::ReadonlyAttribute::Cast (temp_attr);

  this->write_method_begin (ro);
  this->write_method_end (ro);

  PICML::AttributeMember member = attr.AttributeMember_child ();
  PICML::MemberType mtype = member.ref ();
  PICML::Component parent = attr.Component_parent ();

  // Close the getter method and generate the setter method
  // for the current attribute.
  this->outfile ()
    << function_header ((std::string)attr.name () + " [setter]")
    << "void " << parent.name () << "::";

  this->_super::write_method_begin (attr);

  this->outfile ()
    << "{";
}

//
// write_method_end [Attribute]
//
void CUTS_CIAO_Source_Traits::
write_method_end (const PICML::Attribute & attr)
{
  this->outfile ()
    << "}";
}

//
// write_set_session_context
//
void CUTS_CIAO_Source_Traits::
write_set_session_context (const PICML::Component & component)
{
  this->outfile ()
    << function_header ("Environment: session context")
    << "void " << component.name () << "::";

  this->_super::write_set_session_context (component);
}

//
// write_ciao_preactivate
//
void CUTS_CIAO_Source_Traits::
write_ciao_preactivate (const PICML::Component & component)
{
  this->outfile ()
    << function_header ("Environment: preactivate")
    << "void " << component.name () << "::";

  this->_super::write_ciao_preactivate (component);
}

//
// write_ccm_activate
//
void CUTS_CIAO_Source_Traits::
write_ccm_activate (const PICML::Component & component)
{
  // Write the function declartion for the method.
  this->outfile ()
    << function_header ("Environment: activate")
    << "void " << component.name () << "::";

  this->_super::write_ccm_activate (component);
}

//
// write_ciao_postactivate
//
void CUTS_CIAO_Source_Traits::
write_ciao_postactivate (const PICML::Component & component)
{
  this->outfile ()
    <<  function_header ("Environment: postactivate")
    << "void " << component.name () << "::";

  this->_super::write_ciao_postactivate (component);
}

//
// write_ccm_passivate
//
void CUTS_CIAO_Source_Traits::
write_ccm_passivate (const PICML::Component & component)
{
  // Write the function declaration.
  this->outfile ()
    << function_header ("Environment: passivate")
    << "void " << component.name () << "::";

  this->_super::write_ccm_passivate (component);
}

//
// write_ccm_remove
//
void CUTS_CIAO_Source_Traits::
write_ccm_remove (const PICML::Component & component)
{
  // Write the function declartion for the method.
  this->outfile ()
    << function_header ("Environment: remove")
    << "void " << component.name () << "::";

  this->_super::write_ccm_remove (component);
}

//
// function_header
//
std::string CUTS_CIAO_Source_Traits::
function_header (const std::string & func)
{
  std::ostringstream ostr;
  ostr
    << "//" << std::endl
    << "// " << func << std::endl
    << "//" << std::endl;
  return ostr.str ();
}
