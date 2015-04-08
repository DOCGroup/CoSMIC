#include "StdAfx.h"
#include "IDL_File_Generator.h"
#include "IDLStream.h"
#include "File_Processor.h"
#include "IDL_File_Dependency_Processor.h"

#include "PIM/PICML/utils/game/Utility.h"

#include "game/mga/utils/Position_Sort_T.h"

#include "boost/bind.hpp"
#include "boost/iterator/filter_iterator.hpp"

#include <algorithm>

struct visit_all
{
public:
template <typename T>
void operator () (T & collection, PICML::Visitor * visitor) const
{
  for (auto item : collection)
    item->accept (visitor);
}
};

template <typename T, typename SORTER>
struct collection_sort
{
public:
std::vector <T> operator () (GAME::Mga::Collection_T <T> & collection, const std::string & aspect) const
{
  typedef GAME::Mga::Position_Sort_T <T, SORTER> sorter_t;
  sorter_t sorter (aspect, SORTER ());

  std::vector <T> result;

  for (T item : collection)
    result.push_back (item);

  std::sort (result.begin (), result.end (), sorter);
  return result;
}
};

template <typename BASE>
struct derives_from
{
public:
template <typename T>
bool operator () (const T & derived) const
{
  try
  {
    BASE::_narrow (derived);
    return true;
  }
  catch (GAME::Mga::Exception & e)
  {
    ACE_UNUSED_ARG (e);
    return false;
  }
}
};

//
// IDL_File_Generator
//
IDL_File_Generator::
IDL_File_Generator (IDL_File_Dependency_Processor & depends_graph,
                    IDLStream & idl)
: depends_graph_ (depends_graph),
  idl_ (idl),
  in_event_ (false)
{

}

//
// ~IDL_File_Generator
//
IDL_File_Generator::~IDL_File_Generator (void)
{

}

//
// visit_File
//
void IDL_File_Generator::visit_File (PICML::File_in file)
{
  this->templates_only_ = true;
  for (auto package : file->get_Packages ())
    package->accept (this);

  this->templates_only_ = false;

  this->depends_graph_.visit_file (file, *this);
}

//
// visit_Package
//
void IDL_File_Generator::visit_Package (PICML::Package_in package)
{
  GAME::Mga::Collection_T <PICML::TemplateParameter> params = package->children <PICML::TemplateParameter> ();

  if (this->templates_only_ && params.size ())
    return;
  else if (!this->templates_only_ && !params.size ())
    return;

  // Start the model specification.
  this->idl_ << "module " << package->name ();

  if (params.size ())
  {
    // Write each of the parameters in the module. We must right
    // the first parameter out of the for-loop to ensure we have
    // the correct placement of commas between each parameter.
    this->idl_ << " < ";

    typedef collection_sort <PICML::TemplateParameter, GAME::Mga::PS_Left_To_Right> param_sorter;
    bool first_param = true;
    for (auto parameter : param_sorter () (params, "InterfaceDefinition"))
    {
      if (!first_param)
        this->idl_ << ", ";
      first_param = false;

      parameter->accept (this);
    }

    this->idl_ << " > ";
  }

  // Write the remaining contents of the package.
  this->idl_ << nl
             << "{" << idt << nl;

  this->depends_graph_.visit_all_forward_declaration (package);
  this->depends_graph_.visit_package (package, *this);

  this->idl_ << uidt_nl << "};" << nl;
}

//
// visit_NameParameter
//
void IDL_File_Generator::
visit_NameParameter (PICML::NameParameter_in c)
{
  this->idl_ << "typename " << c->name ();
}

//
// visit_CollectionParameter
//
void IDL_File_Generator::
visit_CollectionParameter (PICML::CollectionParameter_in c)
{
  PICML::NameParameter ref = c->refers_to_NameParameter ();
  this->idl_ << "sequence <" << ref->name () << "> " << c->name ();
}

//
// visit_TypedParameter
//
void IDL_File_Generator::
visit_TypeParameter (PICML::TypeParameter_in c)
{
  std::string type = c->Type ();

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

  this->idl_ << " " << c->name ();
}

//
// visit_TemplatePackageInstance
//
void IDL_File_Generator::
visit_TemplatePackageInstance (PICML::TemplatePackageInstance_in p)
{
  PICML::PackageType t = p->get_PackageType ();

  this->idl_ << nl
    << "module " << PICML::fq_type (t->refers_to_Package (), "::", true) << "< ";

  typedef collection_sort <PICML::TemplateParameterValue, GAME::Mga::PS_Left_To_Right> param_sorter;
  bool first_param = true;
  for (auto parameter : param_sorter () (p->get_TemplateParameterValues (), "InterfaceDefinition"))
  {
    if (!first_param)
      this->idl_ << ", ";
    first_param = false;

    this->visit_TemplateParameterValueType (parameter->refers_to_TemplateParameterValueType ());
  }

  this->idl_ << " > " << p->name () << ";" << nl;
}

//
// visit_Enum
//
void IDL_File_Generator::visit_Enum (PICML::Enum_in e)
{
  this->idl_ << "enum " << e->name () << nl
             << "{" << idt;

  bool first_param = true;

  typedef collection_sort <PICML::EnumValue, GAME::Mga::PS_Top_To_Bottom> sorter;
  for (PICML::EnumValue m : sorter () (e->get_EnumValues (), "InterfaceDefinition"))
  {
    if (!first_param)
      this->idl_ << ", ";

    first_param = false;

    m->accept (this);
  }

  this->idl_ << uidt_nl
             << "};" << nl
             << nl;
}

//
// visit_EnumValue
//
void IDL_File_Generator::visit_EnumValue (PICML::EnumValue_in e)
{
  this->idl_ << nl << e->name ();
}

//
// visit_Constant
//
void IDL_File_Generator::visit_Constant (PICML::Constant_in c)
{
  this->idl_ << "const ";

  // Write the constant's type.
  PICML::ConstantType t = c->refers_to_ConstantType ();
  this->visit_ConstantType (t);

  // Write the name of the constant.
  this->idl_ << " " << c->name () << " = ";

  // Write the value of the constant, if applicable.
  std::string value = c->value ();
  std::string cls = t->metaname;

  if (cls == PICML::String::impl_type::metaname || cls == PICML::WideString::impl_type::metaname)
  {
    // Make sure the wide string has a 'L' prefix.
    if (cls == PICML::WideString::impl_type::metaname)
      this->idl_ << "L";

    // Make sure the string is enclosed in quotations.
    if (value[0] != '"')
      this->idl_ << '"';

    this->idl_ << value;

    if (value[value.length () - 1] != '"')
      this->idl_ << '"';
  }
  else if (cls == PICML::Char::impl_type::metaname)
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
// visit_Aggregate
//
void IDL_File_Generator::visit_Aggregate (PICML::Aggregate_in a)
{
  std::vector <PICML::Member> sorted_members;

  // First, generate the RTI-DDS pragma support.
  if (a->has_Key ())
  {
    PICML::Key key = a->get_Key ();

    // First, gather all the members
    for (auto member : key->src_of_KeyMember ())
      sorted_members.push_back (member->dst_Member ());

    // Now sort the members
    ::GAME::Mga::Position_Sort_T <PICML::Member, GAME::Mga::PS_Top_To_Bottom> sorter_t;
    std::sort (sorted_members.begin (), sorted_members.end (), sorter_t);

    // We can declare this as a DDS type.
    this->idl_ << "#pragma DCPS_DATA_TYPE \"" << a->name () << "\"" << nl;

    // Write all members of the key.
    for (auto member : sorted_members)
      this->idl_ << "#pragma DCPS_DATA_KEY \""
                   << a->name () << " " << member->name () << "\"" << nl;

    this->idl_ << nl;
  }

  this->idl_ << "struct " << a->name () << nl
             << "{" << idt;

  // Sort the elements by the position in the InterfaceDefinition aspect.
  typedef collection_sort <PICML::Member, GAME::Mga::PS_Top_To_Bottom> sorter;
  for (PICML::Member member : sorter () (a->get_Members (), "InterfaceDefinition"))
    member->accept (this);

  this->idl_ << uidt_nl << "};" << nl
             << nl;

  if (a->has_Key ())
  {
    // Since there is a key in this aggregate, we need to write at
    // least an empty key list.
    this->idl_ << "#pragma keylist " << a->name ();

    for (auto member: sorted_members)
      this->idl_ << " " << member->name ();

    this->idl_ << nl << nl;
  }
}

//
// visit_SwitchedAggregate
//
void IDL_File_Generator::
visit_SwitchedAggregate (PICML::SwitchedAggregate_in s)
{
  this->idl_ << "union " << s->name () << " switch (";

  this->visit_ConstantType (s->get_Discriminator ()->refers_to_ConstantType ());

  this->idl_ << ")" << nl
             << "{" << idt;

  typedef collection_sort <PICML::Member, GAME::Mga::PS_Top_To_Bottom> sorter;
  for (PICML::Member member : sorter () (s->get_Members (), "InterfaceDefinition"))
    member->accept (this);

  this->idl_ << uidt_nl << "};" << nl
             << nl;
}

//
// visit_Member
//
void IDL_File_Generator::visit_Member (PICML::Member_in m)
{
  for (auto label : m->src_of_LabelConnection ())
    label->accept (this);
  this->idl_ << nl;

  if (this->in_event_)
    this->idl_ << "public ";

  this->visit_MemberType (m->refers_to_MemberType ());
  this->idl_ << " " << m->name () << ";";

  if (m->has_dst_of_KeyMember ())
    this->idl_ << "  // @key";
}

//
// visit_ArrayMember
//
void IDL_File_Generator::
visit_ArrayMember (PICML::ArrayMember_in m)
{
  this->idl_ << nl;

  this->visit_MemberType (m->refers_to_MemberType ());

  long array_size = static_cast <long> (m->Size ());
  this->idl_ << " " << m->name () << "[" << array_size << "];" << nl;
}

//
// visit_Event
//
void IDL_File_Generator::visit_Event (PICML::Event_in e)
{
  if (e->abstract ())
    this->idl_ << "abstract ";

  this->idl_ << "eventtype " << e->name ();

  GAME::Mga::Collection_T <PICML::Inherits> inherits = e->get_Inheritss ();

  if (inherits.size ())
  {
    this->idl_ << " : " << idt_nl;

    bool first_element = true;
    for (auto inherit : inherits)
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      PICML::fq_type (inherit->refers_to_Inheritable (), "::", true);
    }

    this->idl_ << uidt;
  }

  GAME::Mga::Collection_T <PICML::Supports> supports = e->get_Supportss ();

  if (supports.size ())
  {
    this->idl_ << idt_nl
               << " supports " << idt_nl;

    bool first_element = true;
    for (auto support : supports)
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      PICML::fq_type (support->refers_to_Object (), "::", true);
    }
  }

  this->idl_ << nl
             << "{" << idt;

  this->in_event_ = true;
  this->visit_ObjectByValue (e);
  this->in_event_ = false;

  this->idl_ << uidt_nl
             << "};"
             << nl;
}

//
// visit_Event
//
void IDL_File_Generator::
visit_ValueObject (PICML::ValueObject_in v)
{
  if (v->abstract ())
    this->idl_ << "abstract ";

  this->idl_ << "valuetype " << v->name ();

  GAME::Mga::Collection_T <PICML::Inherits> inherits = v->get_Inheritss ();

  if (inherits.size ())
  {
    this->idl_ << " : " << idt_nl;

    bool first_element = true;
    for (auto inherit : inherits)
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      this->idl_ << PICML::fq_type (inherit->refers_to_Inheritable (), "::", true);
    }

    this->idl_ << uidt;
  }

  GAME::Mga::Collection_T <PICML::Supports> supports = v->get_Supportss ();

  if (supports.size ())
  {
    this->idl_ << idt_nl
               << " supports " << idt_nl;

    bool first_element = true;
    for (auto support : supports)
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      this->idl_ << PICML::fq_type (support->refers_to_Object (), "::", true);
    }
  }

  this->idl_ << nl
             << "{" << idt;

  this->visit_ObjectByValue (v);

  this->idl_ << "};" << uidt_nl;
}

//
// visit_ObjectByValue
//
void IDL_File_Generator::
visit_ObjectByValue (PICML::ObjectByValue_in o)
{
  visit_all () (o->get_Aggregates (), this);
  visit_all () (o->get_SwitchedAggregates (), this);
  visit_all () (o->get_Aliass (), this);
  visit_all () (o->get_Constants (), this);
  visit_all () (o->get_Enums (), this);
  visit_all () (o->get_Collections (), this);
  visit_all () (o->get_Exceptions (), this);
  visit_all () (o->get_PortTypes (), this);
  visit_all () (o->get_FactoryOperations (), this);
  visit_all () (o->get_OnewayOperations (), this);
  visit_all () (o->get_TwowayOperations (), this);
  visit_all () (o->get_ReadonlyAttributes (), this);

  typedef collection_sort <PICML::Member, GAME::Mga::PS_Top_To_Bottom> sorter;
  visit_all () (sorter ()(o->get_Members (), "InterfaceDefinition"), this);
 
}

//
// visit_LabelConnection
//
void IDL_File_Generator::
visit_LabelConnection (PICML::LabelConnection_in c)
{
  PICML::Label label = c->dst_Label ();
  this->idl_ << "case " << label->name () << ":" << nl;
}

//
// visit_Component
//
void IDL_File_Generator::visit_Component (PICML::Component_in c)
{
  this->idl_
    << nl
    << "component " << c->name ();

  // Write the inherits specification for the component.
  if (c->has_ComponentInherits ())
    this->idl_ << " : " << idt_nl
               << PICML::fq_type (c->get_ComponentInherits ()->refers_to_Component (), "::", true) << uidt_nl;

  // Write the interfaces that its supports.
  GAME::Mga::Collection_T <PICML::Supports> supports = c->get_Supportss ();

  if (supports.size ())
  {
    this->idl_ << idt_nl << " supports ";

    typedef collection_sort <PICML::Supports, GAME::Mga::PS_Left_To_Right> sorter;
    bool first_element = true;
    for (PICML::Supports support : sorter () (supports, "InterfaceDefinition"))
    {
      if (!first_element)
        this->idl_ << ", " << nl;
      first_element = false;

      this->idl_ << PICML::fq_type (support->refers_to_Object (), "::", true);
    }

    this->idl_ << uidt;
  }

  this->idl_ << nl
             << "{" << idt_nl;

  // Write each of the ports for the component.
  visit_all () (c->get_ProvidedRequestPorts (), this);
  visit_all () (c->get_RequiredRequestPorts (), this);
  visit_all () (c->get_InEventPorts (), this);
  visit_all () (c->get_OutEventPorts (), this);
  visit_all () (c->get_ExtendedPorts (), this);
  visit_all () (c->get_ReadonlyAttributes (), this);
  visit_all () (c->get_Attributes (), this);

  this->idl_ << uidt_nl
             << "};"
             << nl;
}

//
// visit_ConnectorObject
//
void IDL_File_Generator::
visit_ConnectorObject (PICML::ConnectorObject_in c)
{
  this->idl_ << "connector " << c->name ();

  // Write the inherits specification for the component.
  if (c->has_ConnectorInherits ())
    this->idl_ << " : " << idt_nl
               << PICML::fq_type (c->get_ConnectorInherits ()->refers_to_ConnectorObject (), "::", true) << uidt_nl;

  this->idl_ << nl
             << "{" << idt_nl;

  visit_all () (c->get_ProvidedRequestPorts (), this);
  visit_all () (c->get_RequiredRequestPorts (), this);
  visit_all () (c->get_ExtendedPorts (), this);
  visit_all () (c->get_ReadonlyAttributes (), this);

  this->idl_ << uidt_nl
             << "};" << nl
             << nl;
}

//
// visit_ExtendedPort
//
void IDL_File_Generator::
visit_ExtendedPort (PICML::ExtendedPort_in p)
{
  this->idl_ << "port " << PICML::fq_type (p->refers_to_PortType (), "::", true)
             << " " << p->name () << ";" << nl;
}

//
// visit_MirrorPort
//
void IDL_File_Generator::
visit_MirrorPort (PICML::MirrorPort_in p)
{
  this->idl_ << "mirrorport " << PICML::fq_type (p->refers_to_PortType (), "::", true)
             << " " << p->name () << ";" << nl;
}

//
// visit_PortType
//
void IDL_File_Generator::visit_PortType (PICML::PortType_in p)
{
  this->idl_ << "porttype " << p->name () << nl
             << "{" << idt_nl;

  visit_all () (p->children <PICML::ObjectPort> (), this);

  this->idl_ << uidt_nl
             << "};" << nl
             << nl;
}

//
// visit_ProvidedRequestPort
//
void IDL_File_Generator::
visit_ProvidedRequestPort (PICML::ProvidedRequestPort_in p)
{
  this->idl_ << "provides ";
  this->visit_Provideable (p->refers_to_Provideable ());
  this->idl_ << " " << p->name () << ";" << nl;
}

//
// visit_RequiredRequestPort
//
void IDL_File_Generator::
visit_RequiredRequestPort (PICML::RequiredRequestPort_in p)
{
  if (p->AsyncCommunication ())
  {
    // Generate the pragma statement for the receptacle to enable
    // ami4ccm support.
    this->idl_ << "#pragma ciao ami4ccm receptacle \""
               << PICML::fq_type (p->parent_Component (), "::", true)
               << "::" << p->name () << "\"" << nl;
  }

  this->idl_ << "uses ";

  if (p->multiple_connections ())
    this->idl_ << "multiple ";

    this->visit_Provideable (p->refers_to_Provideable ());
  this->idl_ << " " << p->name () << ";" << nl;
}

//
// visit_InEventPort
//
void IDL_File_Generator::
visit_InEventPort (PICML::InEventPort_in p)
{
  this->idl_ << "consumes ";

  this->visit_EventType (p->refers_to_EventType ());
  this->idl_ << " " << p->name () << ";" << nl;
}

//
// visit_OutEventPort
//
void IDL_File_Generator::visit_OutEventPort (PICML::OutEventPort_in p)
{
  if (p->single_destination ())
    this->idl_ << "emits ";
  else
    this->idl_ << "publishes ";

  this->visit_EventType (p->refers_to_EventType ());
  this->idl_ << " " << p->name () << ";" << nl;
}

/**
 * @struct is_async_receptacle_t
 */
struct is_async_receptacle_t
{
  bool operator () (PICML::RequiredRequestPort_in p) const
  {
    return p->AsyncCommunication ();
  }
};

//
// visit_Object
//
void IDL_File_Generator::visit_Object (PICML::Object_in o)
{
  // Determine if this interface is required by an async receptacle.
  // If this is the case, then we need to generate the pragma statement
  // for it.
  if (o->SupportsAsync ())
    this->idl_ << nl
               << "#pragma ciao ami4ccm interface \""
               << PICML::fq_type (o, "::", true) << "\"" << nl
               << nl;

  // Write the port's semantics. It will either be abstract
  // or a local interface.
  std::string semantics = o->InterfaceSemantics ();

  if (semantics != "standard")
    this->idl_ << semantics << " ";

  this->idl_ << "interface " << o->name ();

  GAME::Mga::Collection_T <PICML::Inherits> inherits = o->get_Inheritss ();

  if (inherits.size ())
  {
    // Generate the interfaces that are inherited by this interface
    // before generating any of its methods.
    this->idl_ << " :" << idt_nl;

    bool first_element = true;
    for (PICML::Inherits inherit : inherits)
    {
      if (first_element)
      {
        this->idl_ << PICML::fq_type (inherit->refers_to_Inheritable (), "::", true);
        first_element = false;
      }
      else
        inherit->accept (this);
     }

    this->idl_ << uidt;
  }

  this->idl_ << nl
             << "{" << idt;
 
  visit_all () (o->get_Aggregates (), this);
  visit_all () (o->get_SwitchedAggregates (), this);
  visit_all () (o->get_Aliass (), this);
  visit_all () (o->get_Constants (), this);
  visit_all () (o->get_Enums (), this);
  visit_all () (o->get_Collections (), this);
  visit_all () (o->get_Exceptions (), this);
  visit_all () (o->get_OnewayOperations (), this);
  visit_all () (o->get_TwowayOperations (), this);
  visit_all () (o->get_ReadonlyAttributes (), this);

  this->idl_ << uidt_nl
             << "};"
             << nl;
}

//
// visit_Inherits
//
void IDL_File_Generator::visit_Inherits (PICML::Inherits_in i)
{
  this->idl_ << ", " << nl
             << PICML::fq_type (i->refers_to_Inheritable (), "::", true);
}

//
// visit_Alias
//
void IDL_File_Generator::visit_Alias (PICML::Alias_in a)
{
  this->idl_ << "typedef ";

  this->visit_MemberType (a->refers_to_MemberType ());
 
  this->idl_ << " " << a->name () << ";" << nl
             << nl;
}

//
// visit_Attribute
//
void IDL_File_Generator::visit_Attribute (PICML::Attribute_in a)
{
  this->idl_ << "attribute ";

  this->visit_MemberType (a->get_AttributeMember ()->refers_to_MemberType ());

  this->idl_ << " " << a->name ();

  // Write the exception list, if any.
  GAME::Mga::Collection_T <PICML::GetException> get_exceptions = a->get_GetExceptions ();
  if (get_exceptions.size ())
  {
    this->idl_ << idt_nl
               << "getraises (";

    typedef collection_sort <PICML::GetException, GAME::Mga::PS_Left_To_Right> sorter;
    bool first_element = true;
    for (auto exception : sorter () (get_exceptions, "InterfaceDefinition"))
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      this->visit_ExceptionType (exception);
    }

    this->idl_ << ")" << uidt_nl;
  }

  GAME::Mga::Collection_T <PICML::SetException> set_exceptions = a->get_SetExceptions ();
  if (set_exceptions.size ())
  {
    this->idl_ << idt_nl
               << "setraises (";

    typedef collection_sort <PICML::SetException, GAME::Mga::PS_Left_To_Right> sorter;
    bool first_element = true;
    for (auto exception : sorter () (set_exceptions, "InterfaceDefinition"))
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      this->visit_ExceptionType (exception);
    }

    this->idl_ << ")" << uidt_nl;
  }

  this->idl_ << ";";
}

//
// visit_ReadonlyAttribute
//
void IDL_File_Generator::
visit_ReadonlyAttribute (PICML::ReadonlyAttribute_in a)
{
  this->idl_ << "readonly attribute ";

  a->get_AttributeMember ()->accept (this);

  this->idl_ << " " << a->name () << ";" << nl;
}

//
// visit_AttributeMember
//
void IDL_File_Generator::visit_AttributeMember (PICML::AttributeMember_in m)
{
  this->visit_MemberType (m->refers_to_MemberType ());
}

//
// visit_OnewayOperation
//
void IDL_File_Generator::
visit_OnewayOperation (PICML::OnewayOperation_in op)
{
  this->idl_ << nl
             << "oneway void " << op->name () << " (";

  GAME::Mga::Collection_T <PICML::ParameterType> params = op->children <PICML::ParameterType> ();
  if (params.size ())
  {
    typedef collection_sort <PICML::ParameterType, GAME::Mga::PS_Left_To_Right> sorter;
    bool first_element = true;
    for (auto parameter : sorter () (params, "InterfaceDefinition"))
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      parameter->accept (this);
    }
  }

  this->idl_ << ");" << nl;
}

//
// visit_TwowayOperation
//
void IDL_File_Generator::
visit_TwowayOperation (PICML::TwowayOperation_in op)
{
  this->idl_ << nl;

  if (!op->has_ReturnType ())
    this->idl_ << "void";
  else
    this->visit_MemberType (op->get_ReturnType ()->refers_to_MemberType ());

  this->idl_ << " " << op->name () << " (";

  GAME::Mga::Collection_T <PICML::ParameterType> params = op->children <PICML::ParameterType> ();
  if (params.size ())
  {
    typedef collection_sort <PICML::ParameterType, GAME::Mga::PS_Left_To_Right> sorter;
    bool first_element = true;
    for (auto parameter : sorter () (params, "InterfaceDefinition"))
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      parameter->accept (this);
    }
  }

  this->idl_ << ")";

  // Now, lets see if we need to generate the raises () statement
  // for this method.

  GAME::Mga::Collection_T <PICML::ExceptionRef> exceptions = op->get_ExceptionRefs ();
  if (exceptions.size ())
  {
    this->idl_ << idt_nl
               << "raises (";

    typedef collection_sort <PICML::ExceptionRef, GAME::Mga::PS_Left_To_Right> sorter;
    bool first_element = true;
    for (auto exception : sorter () (exceptions, "InterfaceDefinition"))
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      this->visit_ExceptionType (exception);
    }

    this->idl_ << ")" << uidt;
  }

  this->idl_ << ";";
}

//
// visit_InParameter
//
void IDL_File_Generator::visit_InParameter (PICML::InParameter_in p)
{
  this->idl_ << "in ";
  this->visit_ParameterType (p);
}

//
// visit_OutParameter
//
void IDL_File_Generator::visit_OutParameter (PICML::OutParameter_in p)
{
  this->idl_ << "out ";
  this->visit_ParameterType (p);
}

//
// visit_InoutParameter
//
void IDL_File_Generator::visit_InoutParameter (PICML::InoutParameter_in p)
{
  this->idl_ << "inout ";
  this->visit_ParameterType (p);
}

//
// visit_ParameterType
//
void IDL_File_Generator::visit_ParameterType (PICML::ParameterType_in pt)
{
  this->visit_MemberType (pt->refers_to_MemberType ());
  this->idl_ << " " << pt->name ();
}

//
// visit_Collection
//
void IDL_File_Generator::visit_Collection (PICML::Collection_in c)
{
  this->idl_ << "typedef sequence < ";

  this->visit_MemberType (c->refers_to_MemberType ());

  std::string bound = c->bound ();
  if (!bound.empty ())
    this->idl_ << ", " << bound;

  this->idl_ << " > " << c->name () << ";" << nl
             << nl;
}

//
// visit_Exception
//
void IDL_File_Generator::visit_Exception (PICML::Exception_in e)
{
  this->idl_ << "exception " << e->name () << nl
             << "{" << idt_nl;

  typedef collection_sort <PICML::Member, GAME::Mga::PS_Top_To_Bottom> sorter;
  for (auto value : sorter () (e->get_Members (), "InterfaceDefinition"))
    value->accept (this);

  this->idl_ << uidt_nl
             << "};" << nl;
}

//
// visit_ComponentFactory
//
void IDL_File_Generator::
visit_ComponentFactory (PICML::ComponentFactory_in f)
{
  this->idl_ << "home " << f->name ();

  // Write the inherits specification for the component.
  if (f->is_subtype ())
    this->idl_ << " : " << idt_nl
               << PICML::fq_type (f->archetype (), "::", true) << uidt_nl;

  // Write the interfaces that its supports.
  GAME::Mga::Collection_T <PICML::Supports> supports = f->get_Supportss ();
  if (supports.size ())
  {
    this->idl_ << idt << "supports " << idt_nl;

    typedef collection_sort <PICML::Supports, GAME::Mga::PS_Left_To_Right> sorter;
    bool first_element = true;
    for (PICML::Supports support : sorter () (supports, "InterfaceDefinition"))
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      this->idl_ << PICML::fq_type (support->refers_to_Object (), "::", true);
    }

    this->idl_ << uidt << uidt;
  }

  // Write the component that this home manages.
  this->idl_ << nl
             << "manages "
             << PICML::fq_type (f->src_of_ManagesComponent ()->dst_Manageable (), "::", true);
              ;

  if (f->has_LookupKey ())
  {
    this->idl_ << nl
               << "primarykey ";

    PICML::LookupKeyType t = f->get_LookupKey ()->refers_to_LookupKeyType ();

    if (t->metaname == PICML::ValueObject::impl_type::metaname)
      this->idl_ << PICML::fq_type (t, "::", true);
    else
      this->idl_ << t->name ();
  }

  this->idl_ << nl
             << "{" << idt_nl;

  visit_all () (f->get_Aggregates (), this);
  visit_all () (f->get_SwitchedAggregates (), this);
  visit_all () (f->get_Aliass (), this);
  visit_all () (f->get_Constants (), this);
  visit_all () (f->get_Enums (), this);
  visit_all () (f->get_Collections (), this);
  visit_all () (f->get_Exceptions (), this);
  visit_all () (f->get_PortTypes (), this);
  visit_all () (f->get_ReadonlyAttributes (), this);
  visit_all () (f->get_FactoryOperations (), this);
  visit_all () (f->get_LookupOperations (), this);
  visit_all () (f->get_OnewayOperations (), this);
  visit_all () (f->get_TwowayOperations (), this);

  this->idl_ << uidt_nl
             << "};" << nl
             << nl;
}

//
// visit_LookupOperation
//
void IDL_File_Generator::
visit_LookupOperation (PICML::LookupOperation_in op)
{
  this->idl_ << nl
             << "finder " << op->name () << " (";

  GAME::Mga::Collection_T <PICML::InParameter> params = op->get_InParameters ();
  if (params.size ())
  {
    bool is_first = true;
    typedef collection_sort <PICML::InParameter, GAME::Mga::PS_Left_To_Right> sorter;
    for (PICML::InParameter param : sorter () (params, "InterfaceDefinition"))
    {
      if (!is_first)
        this->idl_ << ", ";
      is_first = false;

      param->accept (this);
    }
  }

  this->idl_ << ")";

  // Finally, write the exception list to the document.
  GAME::Mga::Collection_T <PICML::ExceptionRef> excepts = op->get_ExceptionRefs ();
  if (excepts.size ())
  {
    this->idl_ << idt_nl << "raises (";

    bool is_first = true;
    for (PICML::ExceptionRef exception : excepts)
    {
      if (!is_first)
        this->idl_ << ", ";
      is_first = false;

      this->visit_ExceptionType (exception->refers_to_ExceptionType ());
    }
    this->idl_ << ")" << uidt;
  }

  this->idl_ << ";" << nl;
}

//
// visit_FactoryOperation
//
void IDL_File_Generator::
visit_FactoryOperation (PICML::FactoryOperation_in op)
{
  this->idl_ << nl
             << "factory " << op->name () << " (";

  GAME::Mga::Collection_T <PICML::InParameter> params = op->get_InParameters ();
  if (params.size ())
  {
    bool is_first = true;
    typedef collection_sort <PICML::InParameter, GAME::Mga::PS_Left_To_Right> sorter;
    for (PICML::InParameter p : sorter () (params, "InterfaceDefinition"))
    {
      if (!is_first)
        this->idl_ << ", ";
      is_first = false;

      p->accept (this);
    }
  }

  this->idl_ << ")";

  // Finally, write the exception list to the document.
  GAME::Mga::Collection_T <PICML::ExceptionRef> excepts = op->get_ExceptionRefs ();
  if (excepts.size ())
  {
    this->idl_ << idt_nl << "raises (";

    bool is_first = true;
    for (PICML::ExceptionRef ex : excepts)
    {
      if (!is_first)
        this->idl_ << ", ";
      is_first = false;

      this->visit_ExceptionType (ex->refers_to_ExceptionType ());
    }

    this->idl_ << ")" << uidt;
  }

  this->idl_ << ";";
}

//
// visit_Byte
//
void IDL_File_Generator::visit_Byte (PICML::Byte_in b)
{
  this->idl_ << "octet";
}

//
// visit_Char
//
void IDL_File_Generator::visit_Char (PICML::Char_in c)
{
  this->idl_ << "char";
}

//
// visit_WideChar
//
void IDL_File_Generator::visit_WideChar (PICML::WideChar_in w)
{
  this->idl_ << "wchar";
}

//
// visit_Boolean
//
void IDL_File_Generator::visit_Boolean (PICML::Boolean_in b)
{
  this->idl_ << "boolean";
}

//
// visit_String
//
void IDL_File_Generator::visit_String (PICML::String_in s)
{
  this->idl_ << "string";
}

//
// visit_WideString
//
void IDL_File_Generator::
visit_WideString (PICML::WideString_in )
{
  this->idl_ << "wstring";
}

//
// visit_UnsignedShortInteger
//
void IDL_File_Generator::
visit_UnsignedShortInteger (PICML::UnsignedShortInteger_in s)
{
  this->idl_ << "unsigned short";
}

//
// visit_UnsignedLongInteger
//
void IDL_File_Generator::
visit_UnsignedLongInteger (PICML::UnsignedLongInteger_in l)
{
  this->idl_ << "unsigned long";
}

//
// visit_UnsignedLongLongInteger
//
void IDL_File_Generator::
visit_UnsignedLongLongInteger (PICML::UnsignedLongLongInteger_in )
{
  this->idl_ << "unsigned long long";
}

//
// visit_ShortInteger
//
void IDL_File_Generator::visit_ShortInteger (PICML::ShortInteger_in s)
{
  this->idl_ << "short";
}

//
// visit_LongInteger
//
void IDL_File_Generator::visit_LongInteger (PICML::LongInteger_in l)
{
  this->idl_ << "long";
}

//
// visit_LongLongInteger
//
void IDL_File_Generator::
visit_LongLongInteger (PICML::LongLongInteger_in )
{
  this->idl_ << "long long";
}

//
// visit_FloatNumber
//
void IDL_File_Generator::visit_FloatNumber (PICML::FloatNumber_in f)
{
  this->idl_ << "float";
}

//
// visit_DoubleNumber
//
void IDL_File_Generator::visit_DoubleNumber (PICML::DoubleNumber_in d)
{
  this->idl_ << "double";
}

//
// visit_LongDoubleNumber
//
void IDL_File_Generator::
visit_LongDoubleNumber (PICML::LongDoubleNumber_in)
{
  this->idl_ << "long double";
}

//
// visit_GenericObject
//
void IDL_File_Generator::visit_GenericObject (PICML::GenericObject_in f)
{
  this->idl_ << "Object";
}

//
// visit_GenericValue
//
void IDL_File_Generator::visit_GenericValue (PICML::GenericValue_in f)
{
  this->idl_ << "any";
}

//
// visit_GenericValueObject
//
void IDL_File_Generator::
visit_GenericValueObject (PICML::GenericValueObject_in )
{
  this->idl_ << "ValueBase";
}

//
// visit_TypeEncoding
//
void IDL_File_Generator::
visit_TypeEncoding (PICML::TypeEncoding_in t)
{
  // This is an "interface"
  this->idl_ << "::CORBA::TypeCode";
}

//
// visit_TypeKind
//
void IDL_File_Generator::visit_TypeKind (PICML::TypeKind_in t)
{
  // This is a "enum"
  this->idl_ << "::CORBA::TCKind";
}

//
// visit_Provideable
//
void IDL_File_Generator::visit_Provideable (PICML::Provideable_in p)
{
  if (p->meta ()->name () == PICML::Object::impl_type::metaname)
    this->idl_ << PICML::fq_type (PICML::Object::_narrow (p), "::", true);
  else if (p->meta ()->name () == PICML::GenericObject::impl_type::metaname)
    this->idl_ << "Object";
  else if (derives_from <PICML::TemplateParameter> () (p))
    this->idl_ << p->name ();
}

//
// visit_TemplateParameterValueType
//
void IDL_File_Generator::
visit_TemplateParameterValueType (PICML::TemplateParameterValueType_in t)
{
  if (t->meta ()->name () == PICML::Exception::impl_type::metaname)
    this->idl_ << PICML::fq_type (t, "::", true);
  else
    this->visit_MemberType (PICML::MemberType::_narrow (t));
}

//
// visit_MemberType
//
void IDL_File_Generator::visit_MemberType (PICML::MemberType_in mt)
{
  if (derives_from <PICML::PredefinedType> () (mt))
    mt->accept (this);
  else if (derives_from <PICML::NamedType> () (mt))
    this->idl_ << PICML::fq_type (mt, "::", true);
  else if (derives_from <PICML::TemplateParameter> () (mt))
    this->idl_ << mt->name ();
  else
    this->idl_ << "/* unknown type (" << mt->meta ()->name () << ") */";
}

//
// visit_ConstantType
//
void IDL_File_Generator::
visit_ConstantType (PICML::ConstantType_in ct)
{
  if (derives_from <PICML::PredefinedType> () (ct))
    ct->accept (this);
  else if (ct->meta ()->name () == PICML::Enum::impl_type::metaname)
    this->idl_ << PICML::fq_type (ct, "::", true);
  else
    this->idl_ << "/* unknown type */";
}

//
// visit_EventType
//
void IDL_File_Generator::visit_EventType (PICML::EventType_in e)
{
  if (e->meta ()->name ()== PICML::Event::impl_type::metaname)
    this->idl_ << PICML::fq_type (e, "::", true);
  else if (derives_from <PICML::TemplateParameter> () (e))
    this->idl_ << e->name ();
}

//
// visit_ExceptionType
//
void IDL_File_Generator::
visit_ExceptionType (const PICML::ExceptionType & e)
{
  if (e->meta ()->name () == PICML::Exception::impl_type::metaname)
    this->idl_ << PICML::fq_type (e, "::", true);
  else
    this->idl_ << e->name ();
}
