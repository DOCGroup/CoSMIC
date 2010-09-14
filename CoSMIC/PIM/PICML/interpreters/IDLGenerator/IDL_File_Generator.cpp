// $Id$

#include "StdAfx.h"
#include "IDL_File_Generator.h"
#include "IDLStream.h"
#include "File_Processor.h"
#include "IDL_File_Dependency_Processor.h"

#include "Utils/UDM/Position_Sort_T.h"
#include "Utils/UDM/visit.h"

#include "PIM/PICML/utils/udm/functional.h"

#include "boost/bind.hpp"
#include "boost/iterator/filter_iterator.hpp"

#include <algorithm>

template <typename T>
struct is_type
{
public:
  bool operator () (const T & element) const
  {
    return T::meta == element.type ();
  }
};

//
// IDL_File_Generator
//
IDL_File_Generator::
IDL_File_Generator (IDLStream & idl)
: idl_ (idl)
{

}

//
// ~IDL_File_Generator
//
IDL_File_Generator::~IDL_File_Generator (void)
{

}

//
// Visit_File
//
void IDL_File_Generator::Visit_File (const PICML::File & file)
{
  this->idl_ << nl
             << "// template module(s)" << nl
             << nl;

  this->templates_only_ = true;
  Udm::visit_all <PICML::Package> (file, *this);

  this->idl_ << nl
             << "// declaration(s)" << nl
             << nl;

  this->templates_only_ = false;
  this->Visit_FilePackage (file);
}

//
// Visit_Package
//
void IDL_File_Generator::Visit_Package (const PICML::Package & package)
{
  typedef UDM_Position_Sort_T <PICML::TemplateParameter, PS_Left_To_Right> sorter_t;
  typedef std::set <PICML::TemplateParameter, sorter_t> parameter_t;
  parameter_t parameters = package.TemplateParameter_children_sorted (sorter_t ());

  if (this->templates_only_ && parameters.empty ())
    return;
  else if (!this->templates_only_ && !parameters.empty ())
    return;

  // Start the model specification.
  this->idl_ << "module " << package.name ();

  if (!parameters.empty ())
  {
    // Write each of the parameters in the module. We must right
    // the first parameter out of the for-loop to ensure we have
    // the correct placement of commas between each parameter.
    this->idl_ << " < ";

    parameter_t::iterator
      iter = parameters.begin (),
      iter_end = parameters.end ();

    this->tp_dispatcher_.dispatch (*this, *iter);

    for (++ iter; iter != iter_end; ++ iter)
    {
      this->idl_ << ", ";
      this->tp_dispatcher_.dispatch (*this, *iter);
    }

    this->idl_ << " > ";
  }

  // Write the remaining contents of the package.
  this->idl_ << nl
             << "{" << idt << nl;

  std::string name = package.name ();

  IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->visit_all (package, *this);

  this->idl_ << uidt_nl << "};" << nl;
}

//
// Visit_FilePackage
//
void IDL_File_Generator::Visit_FilePackage (const Udm::Object & object)
{
  IDL_GENERATOR::GLOBAL_IDL_DEPEND_PROCESSOR::instance()->visit_file (object, *this);
}

//
// Visit_NameParameter
//
void IDL_File_Generator::
Visit_NameParameter (const PICML::NameParameter & c)
{
  this->idl_ << "typename " << c.name ();
}

//
// Visit_CollectionParameter
//
void IDL_File_Generator::
Visit_CollectionParameter (const PICML::CollectionParameter & c)
{
  PICML::MgaObject ref = c.ref ();
  this->idl_ << "sequence <" << ref.name () << "> " << c.name ();
}

//
// Visit_TypedParameter
//
void IDL_File_Generator::
Visit_TypeParameter (const PICML::TypeParameter & c)
{
  std::string type = c.Type ();

  if (type == "Aggregate")
    this->idl_ << "struct ";
  else if (type == "Enum")
    this->idl_ << "enum ";
  else if (type == "Event")
    this->idl_ << "eventtype ";
  else if (type == "Exception")
    this->idl_ << "exception ";
  else if (type == "Object")
    this->idl_ << "interface ";
  else if (type == "SwitchedAggregate")
    this->idl_ << "union ";
  else if (type == "ValueObject")
    this->idl_ << "valuetype ";
  else if (type == "Collection")
    this->idl_ << "sequence ";

  this->idl_ << " " << c.name ();
}

//
// Visit_TemplatePackageAlias
//
void IDL_File_Generator::
Visit_TemplatePackageInstance (const PICML::TemplatePackageInstance & p)
{
  PICML::PackageType t = p.PackageType_child ();

  this->idl_ << nl
    << "module " << PICML::utils::fq_type (t.ref (), "::", true) << "< ";

  typedef UDM_Position_Sort_T <PICML::TemplateParameterValue, PS_Left_To_Right> sorter_t;
  typedef std::set <PICML::TemplateParameterValue, sorter_t> parameter_t;
  parameter_t parameters = p.TemplateParameterValue_children_sorted (sorter_t ());

  parameter_t::iterator
    iter = parameters.begin (),
    iter_end = parameters.end ();

  this->Visit_MemberType (iter->ref ());

  for (++ iter; iter != iter_end; ++ iter)
  {
    this->idl_ << ", ";
    this->Visit_MemberType (iter->ref ());
  }

  this->idl_ << " > " << p.name () << ";" << nl;
}

//
// Visit_Enum
//
void IDL_File_Generator::Visit_Enum (const PICML::Enum & e)
{
  this->idl_ << "enum " << e.name () << nl
             << "{" << idt;

  // Visit the enum values from top to bottom.
  typedef UDM_Position_Sort_T <PICML::EnumValue, PS_Top_To_Bottom> sorter_t;
  typedef std::set <PICML::EnumValue, sorter_t> sorted_values_t;
  sorted_values_t values = e.EnumValue_children_sorted (sorter_t ());

  // Create a iterator to visit values
  sorted_values_t::iterator enum_value_iter = values.begin (), enum_value_end = values.end ();

  // Visit the first element separately as we write it
  // to the idl file without a comma at the end.
  enum_value_iter->Accept (*this);

  // From the second element onwards we add a semicolon
  // and then write the element to the next line.
  for (++ enum_value_iter; enum_value_iter != enum_value_end; ++ enum_value_iter)
  {
    this->idl_ << "," << nl;
    enum_value_iter->Accept (*this);
  }

  this->idl_ << nl << uidt_nl
             << "};" << nl
             << nl;
}

//
// Visit_EnumValue
//
void IDL_File_Generator::Visit_EnumValue (const PICML::EnumValue & e)
{
  this->idl_ << nl << e.name ();
}

//
// Visit_Constant
//
void IDL_File_Generator::Visit_Constant (const PICML::Constant & c)
{
  this->idl_ << "const ";

  // Write the constant's type.
  PICML::ConstantType t = c.ref ();
  this->Visit_ConstantType (t);

  // Write the name of the constant.
  this->idl_ << " " << c.name () << " = ";

  // Write the value of the constant, if applicable.
  std::string value = c.value ();
  const Uml::Class & cls = t.type ();

  if (cls == PICML::String::meta || cls == PICML::WideString::meta)
  {
    // Make sure the wide string has a 'L' prefix.
    if (cls == PICML::WideString::meta)
      this->idl_ << "L";

    // Make sure the string is enclosed in quotations.
    if (value[0] != '"')
      this->idl_ << '"';

    this->idl_ << value;

    if (value[value.length () - 1] != '"')
      this->idl_ << '"';
  }
  else if (cls == PICML::Char::meta)
  {
    this->idl_ << "'" << value << "'";
  }
  else
  {
    // We can just write the value.
    this->idl_  << value;
  }

  this->idl_ << ";" << nl;
}

//
// Visit_Aggregate
//
void IDL_File_Generator::Visit_Aggregate (const PICML::Aggregate & a)
{
  // Sort the elements by the position in the InterfaceDefinition aspect.
  typedef UDM_Position_Sort_T <PICML::Member, PS_Top_To_Bottom> sorter_t;
  sorter_t sorter ("InterfaceDefinition", PS_Top_To_Bottom ());
  typedef std::set <PICML::Member, sorter_t> sorted_values_t;

  // First, generate the RTI-DDS pragma support.
  PICML::Key key = a.Key_child ();
  sorted_values_t key_values (sorter);

  if (key != Udm::null)
  {
    // First, gather all the members in sorted order.
    std::set <PICML::KeyMember> key_members = key.dstKeyMember ();
    std::for_each (key_members.begin (),
                   key_members.end (),
                   boost::bind (&sorted_values_t::insert,
                                boost::ref (key_values),
                                boost::bind (&PICML::KeyMember::dstKeyMember_end, _1)));
  }

  if (!key_values.empty ())
  {
    this->idl_ << "#pragma DCPS_DATA_TYPE \"" << a.name () << "\"" << nl;

    sorted_values_t::iterator
      iter = key_values.begin (), iter_end = key_values.end ();

    for (; iter != iter_end; ++ iter)
      this->idl_ << "#pragma DCPS_DATA_KEY \""
                   << a.name () << " " << iter->name () << "\"" << nl;

    this->idl_ << nl;
  }

  this->idl_ << "struct " << a.name () << nl
             << "{" << idt;

  // Sort the elements by the position in the InterfaceDefinition aspect.
  sorted_values_t sorted_values (sorter);
  std::vector <PICML::Member> members = a.Member_kind_children ();
  std::for_each (members.begin (),
                 members.end (),
                 boost::bind (&sorted_values_t::insert,
                              boost::ref (sorted_values),
                              _1));

  std::for_each (sorted_values.begin (),
                 sorted_values.end (),
                 boost::bind (&Member_Dispatcher <IDL_File_Generator>::dispatch,
                              boost::ref (this->member_dispatcher_),
                              boost::ref (*this),
                              _1));

  this->idl_ << uidt_nl << "};" << nl
             << nl;

  // Now, right the key list. Future version of the IDL generator
  // should enable a user to enable/disable such pragma statements.
  if (!key_values.empty ())
  {
    this->idl_ << "#pragma keylist " << a.name ();

    sorted_values_t::iterator
      iter = key_values.begin (), iter_end = key_values.end ();

    for (; iter != iter_end; ++ iter)
      this->idl_ << " " << iter->name ();

    this->idl_ << nl << nl;
  }
}

//
// Visit_SwitchedAggregate
//
void IDL_File_Generator::
Visit_SwitchedAggregate (const PICML::SwitchedAggregate & s)
{
  this->idl_ << "union " << s.name () << " switch (";

  PICML::Discriminator d = s.Discriminator_child ();
  this->Visit_ConstantType (d.ref ());

  this->idl_ << ")" << nl
             << "{" << idt;

  typedef UDM_Position_Sort_T <PICML::Member, PS_Top_To_Bottom> sorter_t;
  sorter_t sorter ("InterfaceDefinition", PS_Top_To_Bottom ());
  typedef std::set <PICML::Member, sorter_t> sorted_values_t;

  sorted_values_t sorted_values (sorter);
  std::vector <PICML::Member> members = s.Member_kind_children ();
  std::for_each (members.begin (),
                 members.end (),
                 boost::bind (&sorted_values_t::insert,
                              boost::ref (sorted_values),
                              _1));

  std::for_each (sorted_values.begin (),
                 sorted_values.end (),
                 boost::bind (&Member_Dispatcher <IDL_File_Generator>::dispatch,
                              boost::ref (this->member_dispatcher_),
                              boost::ref (*this),
                              _1));

  this->idl_ << uidt_nl << "};" << nl
             << nl;
}

//
// Visit_Member
//
void IDL_File_Generator::Visit_Member (const PICML::Member & m)
{
  PICML::MemberType mt = m.ref ();

  std::set <PICML::LabelConnection> labels = m.dstLabelConnection ();
  std::for_each (labels.begin (),
                 labels.end (),
                 boost::bind (&PICML::LabelConnection::Accept,
                              _1,
                              boost::ref (*this)));

  this->idl_ << nl;
  this->Visit_MemberType (mt);
  this->idl_ << " " << m.name () << ";";

  PICML::KeyMember key = m.srcKeyMember ();
  if (key != Udm::null)
    this->idl_ << "  // @key";

  this->idl_ << nl;
}

//
// Visit_ArrayMember
//
void IDL_File_Generator::
Visit_ArrayMember (const PICML::ArrayMember & m)
{
  PICML::MemberType mt = m.ref ();

  this->idl_ << nl;
  this->Visit_MemberType (mt);

  long array_size = static_cast <long> (m.Size ());
  this->idl_ << " " << m.name () << "[" << array_size << "];" << nl;
}

//
// Visit_Event
//
void IDL_File_Generator::Visit_Event (const PICML::Event & e)
{
  if (e.abstract ())
    this->idl_ << "abstract ";

  this->idl_ << "eventtype " << e.name ();

  std::vector <PICML::Inherits> inherits = e.Inherits_children ();

  if (!inherits.empty ())
  {
    this->idl_ << " : " << idt_nl;

    std::vector <PICML::Inherits>::iterator
      iter = inherits.begin (),
      iter_end = inherits.end ();

    this->idl_ << PICML::utils::fq_type (iter->ref (), "::", true);

    for (++ iter; iter != iter_end; ++ iter)
      this->idl_ << ", " << PICML::utils::fq_type (iter->ref (), "::", true);

    this->idl_ << uidt;
  }

  std::vector <PICML::Supports> supports = e.Supports_children ();

  if (!supports.empty ())
  {
    this->idl_ << idt_nl
               << " supports " << idt_nl;

    std::vector <PICML::Supports>::iterator
      iter = supports.begin (),
      iter_end = supports.end ();

    this->idl_ << PICML::utils::fq_type (PICML::Object::Cast (iter->ref ()), "::", true);

    for (++ iter; iter != iter_end; ++ iter)
      this->idl_ << ", " << PICML::utils::fq_type (PICML::Object::Cast (iter->ref ()), "::", true);
  }

  this->idl_ << nl
             << "{" << idt;

  this->Visit_ObjectByValue (e);

  this->idl_ << uidt_nl
             << "};" << nl;
}

//
// Visit_Event
//
void IDL_File_Generator::
Visit_ValueObject (const PICML::ValueObject & v)
{
  if (v.abstract ())
    this->idl_ << "abstract ";

  this->idl_ << "valuetype " << v.name ();

  std::vector <PICML::Inherits> inherits = v.Inherits_children ();

  if (!inherits.empty ())
  {
    this->idl_ << " : " << idt_nl;

    std::vector <PICML::Inherits>::iterator
      iter = inherits.begin (),
      iter_end = inherits.end ();

    this->idl_ << PICML::utils::fq_type (iter->ref (), "::", true);

    for (++ iter; iter != iter_end; ++ iter)
      this->idl_ << ", " << PICML::utils::fq_type (iter->ref (), "::", true);

    this->idl_ << uidt;
  }

  std::vector <PICML::Supports> supports = v.Supports_children ();

  if (!supports.empty ())
  {
    this->idl_ << idt_nl
               << " supports " << idt_nl;

    std::vector <PICML::Supports>::iterator
      iter = supports.begin (),
      iter_end = supports.end ();

    this->idl_ << PICML::utils::fq_type (PICML::Object::Cast (iter->ref ()), "::", true);

    for (++ iter; iter != iter_end; ++ iter)
      this->idl_ << ", " << PICML::utils::fq_type (PICML::Object::Cast (iter->ref ()), "::", true);
  }

  this->idl_ << nl
             << "{" << idt;

  this->Visit_ObjectByValue (v);

  this->idl_ << "};" << uidt_nl;
}

//
// Visit_ObjectByValue
//
void IDL_File_Generator::
Visit_ObjectByValue (const PICML::ObjectByValue & o)
{
  Udm::visit_all <PICML::Aggregate> (o, *this);
  Udm::visit_all <PICML::SwitchedAggregate> (o, *this);
  Udm::visit_all <PICML::Alias> (o, *this);
  Udm::visit_all <PICML::Constant> (o, *this);
  Udm::visit_all <PICML::Enum> (o, *this);
  Udm::visit_all <PICML::Collection> (o, *this);
  Udm::visit_all <PICML::Exception> (o, *this);
  Udm::visit_all <PICML::PortType> (o, *this);
  Udm::visit_all <PICML::FactoryOperation> (o, *this);

  Udm::visit_all <PICML::OnewayOperation> (o, *this);
  Udm::visit_all <PICML::TwowayOperation> (o, *this);

  std::vector <PICML::ReadonlyAttribute> attrs = o.ReadonlyAttribute_kind_children ();
  std::for_each (attrs.begin (),
                 attrs.end (),
                 boost::bind (&ReadonlyAttribute_Dispatcher <IDL_File_Generator>::dispatch,
                              boost::ref (this->ro_dispatcher_),
                              boost::ref (*this),
                              _1));

  typedef UDM_Position_Sort_T <PICML::Member, PS_Top_To_Bottom> sorter_t;
  typedef std::set <PICML::Member, sorter_t> sorted_values_t;
  sorted_values_t values = o.Member_children_sorted (sorter_t ());
  Udm::visit_all (values, *this);
}

//
// Visit_LabelConnection
//
void IDL_File_Generator::
Visit_LabelConnection (const PICML::LabelConnection & c)
{
  PICML::Label label = c.dstLabelConnection_end ();
  this->idl_ << "case " << label.name () << ":" << nl;
}

//
// Visit_Component
//
void IDL_File_Generator::Visit_Component (const PICML::Component & c)
{
  this->idl_ << "component " << c.name ();

  // Write the inherits specification for the component.
  PICML::ComponentInherits inherits = c.ComponentInherits_child ();

  if (inherits != Udm::null)
    this->idl_ << " : " << idt_nl
               << PICML::utils::fq_type (inherits.ref (), "::", true) << uidt_nl;

  // Write the interfaces that its supports.
  typedef UDM_Position_Sort_T <PICML::Supports, PS_Left_To_Right> sorter_t;
  typedef std::set <PICML::Supports, sorter_t> sorted_values_t;
  sorted_values_t values = c.Supports_children_sorted (sorter_t ());

  if (!values.empty ())
  {
    this->idl_ << idt << "supports" << idt_nl;

    sorted_values_t::iterator iter = values.begin (),
                              iter_end = values.end ();

    this->idl_ << ", " << nl
               << PICML::utils::fq_type (PICML::Object::Cast (iter->ref ()), "::", true);

    for (++ iter; iter != iter_end; ++ iter)
      this->idl_ << ", " << nl
                 << PICML::utils::fq_type (PICML::Object::Cast (iter->ref ()), "::", true);

    this->idl_ << uidt << uidt;
  }

  this->idl_ << nl
             << "{" << idt_nl;

  // Write each of the ports for the component.
  Udm::visit_all <PICML::ProvidedRequestPort> (c, *this);
  Udm::visit_all <PICML::RequiredRequestPort> (c, *this);
  Udm::visit_all <PICML::InEventPort> (c, *this);
  Udm::visit_all <PICML::OutEventPort> (c, *this);

  std::vector <PICML::ExtendedPort> extended = c.ExtendedPort_kind_children ();
  std::for_each (extended.begin (),
                 extended.end (),
                 boost::bind (&ExtendedPort_Dispatcher <IDL_File_Generator>::dispatch,
                              boost::ref (this->extended_dispatcher_),
                              boost::ref (*this),
                              _1));

  std::vector <PICML::ReadonlyAttribute> attrs = c.ReadonlyAttribute_kind_children ();
  std::for_each (attrs.begin (),
                 attrs.end (),
                 boost::bind (&ReadonlyAttribute_Dispatcher <IDL_File_Generator>::dispatch,
                              boost::ref (this->ro_dispatcher_),
                              boost::ref (*this),
                              _1));

  this->idl_ << uidt_nl
             << "};" << nl
             << nl;
}

//
// Visit_ConnectorObject
//
void IDL_File_Generator::
Visit_ConnectorObject (const PICML::ConnectorObject & c)
{
  this->idl_ << "connector " << c.name ();

  // Write the inherits specification for the component.
  PICML::ConnectorInherits inherits = c.ConnectorInherits_child  ();

  if (inherits != Udm::null)
    this->idl_ << " : " << idt_nl
               << PICML::utils::fq_type (inherits.ref (), "::", true) << uidt_nl;

  this->idl_ << nl
             << "{" << idt_nl;

  Udm::visit_all <PICML::ProvidedRequestPort> (c, *this);
  Udm::visit_all <PICML::RequiredRequestPort> (c, *this);

  Udm::visit_all <PICML::ExtendedPort> (c, *this);

  std::vector <PICML::ReadonlyAttribute> attrs = c.ReadonlyAttribute_kind_children ();
  std::for_each (attrs.begin (),
                 attrs.end (),
                 boost::bind (&ReadonlyAttribute_Dispatcher <IDL_File_Generator>::dispatch,
                              boost::ref (this->ro_dispatcher_),
                              boost::ref (*this),
                              _1));

  this->idl_ << uidt_nl
             << "};" << nl
             << nl;
}

//
// Visit_ExtendedPort
//
void IDL_File_Generator::
Visit_ExtendedPort (const PICML::ExtendedPort & p)
{
  this->idl_ << "port " << PICML::utils::fq_type (p, p.ref (), "::", true)
             << " " << p.name () << ";" << nl
             << nl;
}

//
// Visit_MirrorPort
//
void IDL_File_Generator::
Visit_MirrorPort (const PICML::MirrorPort & p)
{
  this->idl_ << "mirrorport " << PICML::utils::fq_type (p, p.ref (), "::", true)
             << " " << p.name () << ";" << nl
             << nl;
}

//
// Visit_PortType
//
void IDL_File_Generator::Visit_PortType (const PICML::PortType & p)
{
  this->idl_ << "porttype " << p.name () << nl
             << "{" << idt_nl;

  std::vector <PICML::ObjectPort> ports = p.ObjectPort_children ();
  std::for_each (ports.begin (),
                 ports.end (),
                 boost::bind (&Port_Dispatcher <IDL_File_Generator>::dispatch,
                              boost::ref (this->port_dispatcher_),
                              boost::ref (*this),
                              _1));

  this->idl_ << uidt_nl
             << "};" << nl
             << nl;
}

//
// Visit_ProvidedRequestPort
//
void IDL_File_Generator::
Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & p)
{
  this->idl_ << "provides ";
  this->Visit_Provideable (p.ref ());
  this->idl_ << " " << p.name () << ";" << nl
             << nl;
}

//
// Visit_RequiredRequestPort
//
void IDL_File_Generator::
Visit_RequiredRequestPort (const PICML::RequiredRequestPort & p)
{
  if (p.AsyncCommunication ())
  {
    // Generate the pragma statement for the receptacle to enable
    // ami4ccm support.
    PICML::Component c = p.Component_parent ();

    this->idl_ << "#pragma ciao ami4ccm receptacle \""
               << PICML::utils::fq_type (c, "::", true)
               << "::" << p.name () << "\"" << nl;
  }

  this->idl_ << "uses ";

  if (p.multiple_connections ())
    this->idl_ << "multiple ";

  this->Visit_Provideable (p.ref ());
  this->idl_ << " " << p.name () << ";" << nl
             << nl;
}

//
// Visit_InEventPort
//
void IDL_File_Generator::
Visit_InEventPort (const PICML::InEventPort & p)
{
  this->idl_ << "consumes ";

  this->Visit_EventType (p.ref ());
  this->idl_ << " " << p.name () << ";" << nl
             << nl;
}

//
// Visit_OutEventPort
//
void IDL_File_Generator::Visit_OutEventPort (const PICML::OutEventPort & p)
{
  if (p.single_destination ())
    this->idl_ << "emits ";
  else
    this->idl_ << "publishes ";

  this->Visit_EventType (p.ref ());
  this->idl_ << " " << p.name () << ";" << nl
             << nl;
}

/**
 * @struct is_async_receptacle_t
 */
struct is_async_receptacle_t
{
  bool operator () (const PICML::RequiredRequestPort & p) const
  {
    return p.AsyncCommunication ();
  }
};

//
// Visit_Object
//
void IDL_File_Generator::Visit_Object (const PICML::Object & o)
{
  // Determine if this interface is required by an async receptacle.
  // If this is the case, then we need to generate the pragma statement
  // for it.
  if (o.SupportsAsync ())
    this->idl_ << nl
               << "#pragma ciao ami4ccm interface \""
               << PICML::utils::fq_type (o, "::", true) << "\"" << nl
               << nl;

  // Write the port's semantics. It will either be abstract
  // or a local interface.
  std::string semantics = o.InterfaceSemantics ();

  if (semantics != "standard")
    this->idl_ << semantics << " ";

  this->idl_ << "interface " << o.name ();

  typedef std::vector <PICML::Inherits> inherits_t;
  inherits_t inherits = o.Inherits_children ();

  if (!inherits.empty ())
  {
    // Generate the interfaces that are inherited by this interface
    // before generating any of its methods.
    this->idl_ << " :" << idt_nl;

    inherits_t::iterator iter = inherits.begin (),
                         iter_end = inherits.end ();

    this->idl_ << PICML::utils::fq_type (iter->ref (), "::", true);

    std::for_each (++ iter,
                   iter_end,
                   boost::bind (&PICML::Inherits::Accept, _1, boost::ref (*this)));

    this->idl_ << uidt;
  }

  this->idl_ << nl
             << "{" << idt;

  Udm::visit_all <PICML::Aggregate> (o, *this);
  Udm::visit_all <PICML::SwitchedAggregate> (o, *this);
  Udm::visit_all <PICML::Alias> (o, *this);
  Udm::visit_all <PICML::Constant> (o, *this);
  Udm::visit_all <PICML::Enum> (o, *this);
  Udm::visit_all <PICML::Collection> (o, *this);
  Udm::visit_all <PICML::Exception> (o, *this);

  Udm::visit_all <PICML::OnewayOperation> (o, *this);
  Udm::visit_all <PICML::TwowayOperation> (o, *this);

  std::vector <PICML::ReadonlyAttribute> attrs = o.ReadonlyAttribute_kind_children ();
  std::for_each (attrs.begin (),
                 attrs.end (),
                 boost::bind (&ReadonlyAttribute_Dispatcher <IDL_File_Generator>::dispatch,
                              boost::ref (this->ro_dispatcher_),
                              boost::ref (*this),
                              _1));

  this->idl_ << uidt_nl
             << "};" << nl
             << nl;
}

//
// Visit_Inherits
//
void IDL_File_Generator::Visit_Inherits (const PICML::Inherits & i)
{
  this->idl_ << ", " << nl
             << PICML::utils::fq_type (i.ref (), "::", true);
}

//
// Visit_Alias
//
void IDL_File_Generator::Visit_Alias (const PICML::Alias & a)
{
  this->idl_ << "typedef ";

  this->Visit_MemberType (a.ref ());

  this->idl_ << " " << a.name () << ";" << nl
             << nl;
}

//
// Visit_Attribute
//
void IDL_File_Generator::Visit_Attribute (const PICML::Attribute & a)
{
  this->idl_ << "attribute ";

  PICML::AttributeMember m = a.AttributeMember_child ();
  this->Visit_MemberType (m.ref ());

  this->idl_ << " " << a.name ();

  // Write the exception list, if any.
  typedef UDM_Position_Sort_T <PICML::GetException, PS_Left_To_Right> get_sorter_t;
  typedef std::set <PICML::GetException, get_sorter_t> get_values_t;
  get_values_t get_exs = a.GetException_children_sorted (get_sorter_t ());

  if (!get_exs.empty ())
  {
    this->idl_ << idt_nl
               << "getraises (";

    get_values_t::iterator iter = get_exs.begin (),
                           iter_end = get_exs.end ();

    this->idl_ << PICML::utils::fq_type (iter->ref (), "::", true);

    for (++ iter; iter != iter_end; ++ iter)
      this->idl_ << PICML::utils::fq_type (iter->ref (), "::", true);

    this->idl_ << ")" << uidt_nl;
  }

  typedef UDM_Position_Sort_T <PICML::SetException, PS_Left_To_Right> set_sorter_t;
  typedef std::set <PICML::SetException, set_sorter_t> set_values_t;
  set_values_t set_exs = a.SetException_children_sorted (set_sorter_t ());

  if (!set_exs.empty ())
  {
    this->idl_ << idt_nl
               << "setraises (";

    set_values_t::iterator iter = set_exs.begin (),
                           iter_end = set_exs.end ();

    this->idl_ << PICML::utils::fq_type (iter->ref (), "::", true);

    for (++ iter; iter != iter_end; ++ iter)
      this->idl_ << PICML::utils::fq_type (iter->ref (), "::", true);

    this->idl_ << ")" << uidt_nl;
  }

  this->idl_ << ";" << nl;
}

//
// Visit_ReadonlyAttribute
//
void IDL_File_Generator::
Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & a)
{
  this->idl_ << "readonly attribute ";

  PICML::AttributeMember m = a.AttributeMember_child ();
  m.Accept (*this);

  this->idl_ << " " << a.name () << ";" << nl;
}

//
// Visit_AttributeMember
//
void IDL_File_Generator::Visit_AttributeMember (const PICML::AttributeMember & m)
{
  this->Visit_MemberType (m.ref ());
}

//
// Visit_OnewayOperation
//
void IDL_File_Generator::
Visit_OnewayOperation (const PICML::OnewayOperation & op)
{
  this->idl_ << nl
             << "oneway void " << op.name () << " (";

  typedef UDM_Position_Sort_T <PICML::ParameterType, PS_Left_To_Right> sorter_t;
  typedef std::set <PICML::ParameterType, sorter_t> sorted_values_t;
  sorted_values_t values = op.ParameterType_kind_children_sorted (sorter_t ());

  if (!values.empty ())
  {
    sorted_values_t::iterator iter = values.begin (),
                              iter_end = values.end ();

    this->param_dispatcher_.dispatch (*this, *iter);

    for (++ iter; iter != iter_end; ++ iter)
    {
      this->idl_ << ", ";
      this->param_dispatcher_.dispatch (*this, *iter);
    }
  }

  this->idl_ << ");" << nl;
}

//
// Visit_TwowayOperation
//
void IDL_File_Generator::
Visit_TwowayOperation (const PICML::TwowayOperation & op)
{
  PICML::ReturnType rt = op.ReturnType_child ();
  this->idl_ << nl;

  if (rt == Udm::null)
    this->idl_ << "void";
  else
    this->Visit_MemberType (rt.ref ());

  this->idl_ << " " << op.name () << " (";

  typedef UDM_Position_Sort_T <PICML::ParameterType, PS_Left_To_Right> sorter_t;
  typedef std::set <PICML::ParameterType, sorter_t> sorted_values_t;
  sorted_values_t values = op.ParameterType_kind_children_sorted (sorter_t ());

  if (!values.empty ())
  {
    sorted_values_t::iterator iter = values.begin (),
                              iter_end = values.end ();

    this->param_dispatcher_.dispatch (*this, *iter);

    for (++ iter; iter != iter_end; ++ iter)
    {
      this->idl_ << ", ";
      this->param_dispatcher_.dispatch (*this, *iter);
    }
  }

  this->idl_ << ")";

  // Now, lets see if we need to generate the raises () statement
  // for this method.

  typedef UDM_Position_Sort_T <PICML::ExceptionRef, PS_Left_To_Right> ex_sorter_t;
  typedef std::set <PICML::ExceptionRef, ex_sorter_t> ex_values_t;
  ex_values_t exs = op.ExceptionRef_children_sorted (ex_sorter_t ());

  if (!exs.empty ())
  {
    ex_values_t::iterator iter = exs.begin (),
                          iter_end = exs.end ();

    this->idl_ << idt_nl
               << "raises (";

    this->idl_ << PICML::utils::fq_type (iter->ref (), "::", true);

    for (++ iter; iter != iter_end; ++ iter)
      this->idl_ << ", " << PICML::utils::fq_type (iter->ref (), "::", true);

    this->idl_ << ")" << uidt;
  }

  this->idl_ << ";" << nl;
}

//
// Visit_InParameter
//
void IDL_File_Generator::Visit_InParameter (const PICML::InParameter & p)
{
  this->idl_ << "in ";
  this->Visit_ParameterType (p);
}

//
// Visit_OutParameter
//
void IDL_File_Generator::Visit_OutParameter (const PICML::OutParameter & p)
{
  this->idl_ << "out ";
  this->Visit_ParameterType (p);
}

//
// Visit_InOutParameter
//
void IDL_File_Generator::Visit_InOutParameter (const PICML::InoutParameter & p)
{
  this->idl_ << "inout ";
  this->Visit_ParameterType (p);
}

//
// Visit_ParameterType
//
void IDL_File_Generator::Visit_ParameterType (const PICML::ParameterType & pt)
{
  this->Visit_MemberType (pt.ref ());
  this->idl_ << " " << pt.name ();
}

//
// Visit_Collection
//
void IDL_File_Generator::Visit_Collection (const PICML::Collection & c)
{
  this->idl_ << "typedef sequence < ";

  this->Visit_MemberType (c.ref ());

  std::string bound = c.bound ();
  if (!bound.empty ())
    this->idl_ << ", " << bound;

  this->idl_ << " > " << c.name () << ";" << nl
             << nl;
}

//
// Visit_Exception
//
void IDL_File_Generator::Visit_Exception (const PICML::Exception & e)
{
  this->idl_ << "exception " << e.name () << nl
             << "{" << idt_nl;

  typedef UDM_Position_Sort_T <PICML::Member, PS_Top_To_Bottom> sorter_t;
  typedef std::set <PICML::Member, sorter_t> sorted_values_t;
  sorted_values_t values = e.Member_children_sorted (sorter_t ());

  Udm::visit_all (values, *this);

  this->idl_ << uidt_nl
             << "};" << nl;
}

//
// Visit_ComponentFactory
//
void IDL_File_Generator::
Visit_ComponentFactory (const PICML::ComponentFactory & f)
{
  this->idl_ << "home " << f.name ();

  // Write the inherits specification for the component.
  if (f.isSubtype ())
    this->idl_ << " : " << idt_nl
               << PICML::utils::fq_type (f.Archetype (), "::", true) << uidt_nl;

  // Write the interfaces that its supports.
  typedef UDM_Position_Sort_T <PICML::Supports, PS_Left_To_Right> sorter_t;
  typedef std::set <PICML::Supports, sorter_t> sorted_values_t;
  sorted_values_t values = f.Supports_children_sorted (sorter_t ());

  if (!values.empty ())
  {
    this->idl_ << idt << "supports" << idt_nl;

    sorted_values_t::iterator iter = values.begin (),
                              iter_end = values.end ();

    this->idl_ << ", " << nl
               << PICML::utils::fq_type (PICML::Object::Cast (iter->ref ()), "::", true);

    for (++ iter; iter != iter_end; ++ iter)
      this->idl_ << ", " << nl
                 << PICML::utils::fq_type (PICML::Object::Cast (iter->ref ()), "::", true);

    this->idl_ << uidt << uidt;
  }

  // Write the component that this home manages.
  PICML::ManagesComponent mc = f.dstManagesComponent ();
  PICML::Component c = PICML::Component::Cast (mc.dstManagesComponent_end ());
  this->idl_ << nl
             << "manages " << PICML::utils::fq_type (c, "::", true);

  PICML::LookupKey key = f.LookupKey_child ();

  if (key != Udm::null)
    this->idl_ << nl
               << "primarykey " << PICML::utils::fq_type (key.ref (), "::", true);

  this->idl_ << nl
             << "{" << idt_nl;

  Udm::visit_all <PICML::Aggregate> (f, *this);
  Udm::visit_all <PICML::SwitchedAggregate> (f, *this);
  Udm::visit_all <PICML::Alias> (f, *this);
  Udm::visit_all <PICML::Constant> (f, *this);
  Udm::visit_all <PICML::Enum> (f, *this);
  Udm::visit_all <PICML::Collection> (f, *this);
  Udm::visit_all <PICML::Exception> (f, *this);
  Udm::visit_all <PICML::PortType> (f, *this);

  std::vector <PICML::ReadonlyAttribute> attrs = f.ReadonlyAttribute_kind_children ();
  std::for_each (attrs.begin (),
                 attrs.end (),
                 boost::bind (&ReadonlyAttribute_Dispatcher <IDL_File_Generator>::dispatch,
                              boost::ref (this->ro_dispatcher_),
                              boost::ref (*this),
                              _1));

  Udm::visit_all <PICML::FactoryOperation> (f, *this);
  Udm::visit_all <PICML::LookupOperation> (f, *this);

  Udm::visit_all <PICML::OnewayOperation> (f, *this);
  Udm::visit_all <PICML::TwowayOperation> (f, *this);

  this->idl_ << uidt_nl
             << "};" << nl
             << nl;
}

//
// Visit_LookupOperation
//
void IDL_File_Generator::
Visit_LookupOperation (const PICML::LookupOperation & op)
{
  this->idl_ << nl
             << "finder " << op.name () << " (";

  typedef UDM_Position_Sort_T <PICML::InParameter, PS_Left_To_Right> sorter_t;
  typedef std::set <PICML::InParameter, sorter_t> sorted_values_t;
  sorted_values_t params = op.InParameter_children_sorted (sorter_t ());

  if (!params.empty ())
  {
    sorted_values_t::iterator
      iter = params.begin (), iter_end = params.end ();

    iter->Accept (*this);

    for (++ iter; iter != iter_end; ++ iter)
    {
      this->idl_ << ", ";
      iter->Accept (*this);
    }
  }

  this->idl_ << ")";

  // Finally, write the exception list to the document.
  std::vector <PICML::ExceptionRef> excepts = op.ExceptionRef_children ();

  if (!excepts.empty ())
  {
    this->idl_ << idt_nl << "raises (";

    std::vector <PICML::ExceptionRef>::iterator
      iter = excepts.begin (), iter_end = excepts.end ();

    this->idl_ << PICML::utils::fq_type (iter->ref (), "::", true);
    for (++ iter; iter != iter_end; ++ iter)
      this->idl_ << ", " << PICML::utils::fq_type (iter->ref (), "::", true);

    this->idl_ << ")" << uidt;
  }

  this->idl_ << ";" << nl;
}

//
// Visit_FactoryOperation
//
void IDL_File_Generator::
Visit_FactoryOperation (const PICML::FactoryOperation & op)
{
  this->idl_ << nl
             << "factory " << op.name () << " (";

  typedef UDM_Position_Sort_T <PICML::InParameter, PS_Left_To_Right> sorter_t;
  typedef std::set <PICML::InParameter, sorter_t> sorted_values_t;
  sorted_values_t params = op.InParameter_children_sorted (sorter_t ());

  if (!params.empty ())
  {
    sorted_values_t::iterator
      iter = params.begin (), iter_end = params.end ();

    iter->Accept (*this);

    for (++ iter; iter != iter_end; ++ iter)
    {
      this->idl_ << ", ";
      iter->Accept (*this);
    }
  }

  this->idl_ << ")";

  // Finally, write the exception list to the document.
  std::vector <PICML::ExceptionRef> excepts = op.ExceptionRef_children ();

  if (!excepts.empty ())
  {
    this->idl_ << idt_nl << "raises (";

    std::vector <PICML::ExceptionRef>::iterator
      iter = excepts.begin (), iter_end = excepts.end ();

    this->idl_ << PICML::utils::fq_type (iter->ref (), "::", true);
    for (++ iter; iter != iter_end; ++ iter)
      this->idl_ << ", " << PICML::utils::fq_type (iter->ref (), "::", true);

    this->idl_ << ")" << uidt;
  }

  this->idl_ << ";";
}

//
// Visit_Byte
//
void IDL_File_Generator::Visit_Byte (const PICML::Byte & b)
{
  this->idl_ << "octet";
}

//
// Visit_Char
//
void IDL_File_Generator::Visit_Char (const PICML::Char & c)
{
  this->idl_ << "char";
}

//
// Visit_WideChar
//
void IDL_File_Generator::Visit_WideChar (const PICML::WideChar & w)
{
  this->idl_ << "wchar";
}

//
// Visit_Boolean
//
void IDL_File_Generator::Visit_Boolean (const PICML::Boolean & b)
{
  this->idl_ << "boolean";
}

//
// Visit_String
//
void IDL_File_Generator::Visit_String (const PICML::String & s)
{
  this->idl_ << "string";
}

//
// Visit_WideString
//
void IDL_File_Generator::
Visit_WideString (const PICML::WideString & )
{
  this->idl_ << "wstring";
}

//
// Visit_UnsignedShortInteger
//
void IDL_File_Generator::
Visit_UnsignedShortInteger (const PICML::UnsignedShortInteger & s)
{
  this->idl_ << "unsigned short";
}

//
// Visit_UnsignedLongInteger
//
void IDL_File_Generator::
Visit_UnsignedLongInteger (const PICML::UnsignedLongInteger & l)
{
  this->idl_ << "unsigned long";
}

//
// Visit_UnsignedLongLongInteger
//
void IDL_File_Generator::
Visit_UnsignedLongLongInteger (const PICML::UnsignedLongLongInteger & )
{
  this->idl_ << "unsigned long long";
}

//
// Visit_ShortInteger
//
void IDL_File_Generator::Visit_ShortInteger (const PICML::ShortInteger & s)
{
  this->idl_ << "short";
}

//
// Visit_LongInteger
//
void IDL_File_Generator::Visit_LongInteger (const PICML::LongInteger & l)
{
  this->idl_ << "long";
}

//
// Visit_LongLongInteger
//
void IDL_File_Generator::
Visit_LongLongInteger (const PICML::LongLongInteger & )
{
  this->idl_ << "long long";
}

//
// Visit_FloatNumber
//
void IDL_File_Generator::Visit_FloatNumber (const PICML::FloatNumber & f)
{
  this->idl_ << "float";
}

//
// Visit_DoubleNumber
//
void IDL_File_Generator::Visit_DoubleNumber (const PICML::DoubleNumber & d)
{
  this->idl_ << "double";
}

//
// Visit_LongDoubleNumber
//
void IDL_File_Generator::
Visit_LongDoubleNumber (const PICML::LongDoubleNumber &)
{
  this->idl_ << "long double";
}

//
// Visit_GenericObject
//
void IDL_File_Generator::Visit_GenericObject (const PICML::GenericObject & f)
{
  this->idl_ << "Object";
}

//
// Visit_GenericValue
//
void IDL_File_Generator::Visit_GenericValue (const PICML::GenericValue & f)
{
  this->idl_ << "any";
}

//
// Visit_GenericValueObject
//
void IDL_File_Generator::
Visit_GenericValueObject (const PICML::GenericValueObject & )
{
  this->idl_ << "ValueBase";
}

//
// Visit_TypeEncoding
//
void IDL_File_Generator::
Visit_TypeEncoding (const PICML::TypeEncoding & t)
{
  // This is an "interface"
  this->idl_ << "::CORBA::TypeCode";
}

//
// Visit_TypeKind
//
void IDL_File_Generator::Visit_TypeKind (const PICML::TypeKind & t)
{
  // This is a "enum"
  this->idl_ << "::CORBA::TCKind";
}

//
// Visit_Provideable
//
void IDL_File_Generator::Visit_Provideable (const PICML::Provideable & p)
{
  if (p.type () == PICML::Object::meta)
    this->idl_ << PICML::utils::fq_type (PICML::Object::Cast (p), "::", true);
  else if (p.type () == PICML::GenericObject::meta)
    this->idl_ << "Object";
  else if (Udm::IsDerivedFrom (p.type (), PICML::TemplateParameter::meta))
    this->idl_ << p.name ();
}

//
// Visit_MemberType
//
void IDL_File_Generator::Visit_MemberType (const PICML::MemberType & mt)
{
  if (Udm::IsDerivedFrom (mt.type (), PICML::PredefinedType::meta))
    this->pt_dispatcher_.dispatch (*this, mt);
  else if (Udm::IsDerivedFrom (mt.type (), PICML::NamedType::meta))
    this->idl_ << PICML::utils::fq_type (PICML::NamedType::Cast (mt), "::", true);
  else if (Udm::IsDerivedFrom (mt.type (), PICML::TemplateParameter::meta))
    this->idl_ << mt.name ();
  else
    this->idl_ << "/* unknown type (" << mt.type ().name () << ") */";
}

//
// Visit_ConstantType
//
void IDL_File_Generator::
Visit_ConstantType (const PICML::ConstantType & ct)
{
  if (Udm::IsDerivedFrom (ct.type (), PICML::PredefinedType::meta))
    this->pt_dispatcher_.dispatch (*this, ct);
  else if (ct.type () == PICML::Enum::meta)
    this->idl_ << PICML::utils::fq_type (PICML::Enum::Cast (ct), "::", true);
  else
    this->idl_ << "/* unknown type */";
}

//
// Visit_EventType
//
void IDL_File_Generator::Visit_EventType (const PICML::EventType & e)
{
  if (e.type () == PICML::Event::meta)
    this->idl_ << PICML::utils::fq_type (PICML::Event::Cast (e), "::", true);
  else if (Udm::IsDerivedFrom (e.type (), PICML::TemplateParameter::meta))
    this->idl_ << e.name ();
}
