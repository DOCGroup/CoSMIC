// $Id$

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
vector <T> operator () (const Collection_T <typename T> & collection, const std::string & aspect = "") const
{
  typedef GAME::Mga::Position_Sort_T <T, SORTER> sorter_t;
  sorter_t sorter (aspect, SORTER ());

  std::vector <T> result;

  for (auto item : collection)
    result.push_back (item);

  std::sort (result.begin (), result.end (), sorter_t ());
}
};

template <typename BASE>
struct derives_from
{
public:
template <typename T>
bool operator (const T & derived) const
{
  GAME::Mga::FCO parent = dervied->derived_from ();
  while (parent->meta ()->name () != GAME::Mga::FCO::impl_type::metaname)
  {
    if (parent->meta ()->name () == BASE::impl_type::metaname)
      return true;
    parent = parent->derived_from ();
  }
  return false;
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
// Visit_File
//
void IDL_File_Generator::Visit_File (const PICML::File_in file)
{
  this->templates_only_ = true;
  for (auto package : file->get_Packages ())
    package->accept (this);

  this->templates_only_ = false;

  this->depends_graph_.visit_file (file, *this);
}

//
// Visit_Package
//
void IDL_File_Generator::Visit_Package (const PICML::Package_in package)
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
    for (auto parameter : param_sorter () (params, ""))
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
  this->depends_graph_.visit_all (package, *this);

  this->idl_ << uidt_nl << "};" << nl;
}

//
// Visit_NameParameter
//
void IDL_File_Generator::
Visit_NameParameter (const PICML::NameParameter_in c)
{
  this->idl_ << "typename " << c->name ();
}

//
// Visit_CollectionParameter
//
void IDL_File_Generator::
Visit_CollectionParameter (const PICML::CollectionParameter_in c)
{
  PICML::NameParameter ref = c->refers_to_NameParameter ();
  this->idl_ << "sequence <" << ref->name () << "> " << c->name ();
}

//
// Visit_TypedParameter
//
void IDL_File_Generator::
Visit_TypeParameter (const PICML::TypeParameter_in c)
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
// Visit_TemplatePackageInstance
//
void IDL_File_Generator::
Visit_TemplatePackageInstance (const PICML::TemplatePackageInstance_in p)
{
  PICML::PackageType t = p->get_PackageType ();

  this->idl_ << nl
    << "module " << PICML::fq_type (t->refers_to_Package (), "::", true) << "< ";

  typedef collection_sort <PICML::TemplateParameterValue, GAME::Mga::PS_Left_To_Right> param_sorter;
  bool first_param = true;
  for (auto parameter : param_sorter () (p->get_TemplateParameterValues ()))
  {
    if (!first_param)
      this->idl_ << ", ";
    first_param = false;

    this->Visit_TemplateParameterValueType (parameter->refers_to_TemplateParameterValueType ());
  }

  this->idl_ << " > " << p->name () << ";" << nl;
}

//
// Visit_Enum
//
void IDL_File_Generator::Visit_Enum (const PICML::Enum_in e)
{
  this->idl_ << "enum " << e->name () << nl
             << "{" << idt;

  bool first_param = true;

  typedef collection_sort <PICML::EnumValue, GAME::Mga::PS_Top_To_Bottom> sorter;
  for (PICML::EnumValue m : sorter () (e->get_EnumValues ()))
  {
    if (!first_param)
      this->idl_ << ", ";

    first_param = false;

    m->accept (this);
  }

  this->idl_ << nl << uidt_nl
             << "};" << nl
             << nl;
}

//
// Visit_EnumValue
//
void IDL_File_Generator::Visit_EnumValue (const PICML::EnumValue_in e)
{
  this->idl_ << nl << e->name ();
}

//
// Visit_Constant
//
void IDL_File_Generator::Visit_Constant (const PICML::Constant_in c)
{
  this->idl_ << "const ";

  // Write the constant's type.
  PICML::ConstantType t = c->refers_to_ConstantType ();
  this->Visit_ConstantType (t);

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
// Visit_Aggregate
//
void IDL_File_Generator::Visit_Aggregate (const PICML::Aggregate_in a)
{
  std::vector <PICML::Member> sorted_members;

  // First, generate the RTI-DDS pragma support.
  if (a->has_Key ())
  {
    PICML::Key key = a->get_Key ();

    // First, gather all the members
    for (auto connection : key->src_of_KeyMember ())
      sorted_members.push_back (connection->dst_Member ());

    // Now sort the members
    ::GAME::Mga::Position_Sort_T <PICML::Member, GAME::Mga::PS_Top_To_Bottom> sorter_t;
    std::sort (sorted_members.begin (), sorted_members.end (), sorter_t);

    // We can declare this as a DDS type.
    this->idl_ << "#pragma DCPS_DATA_TYPE \"" << a.name () << "\"" << nl;

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
  for (PICML::Member member : sorter () (a->get_Members ()))
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
// Visit_SwitchedAggregate
//
void IDL_File_Generator::
Visit_SwitchedAggregate (const PICML::SwitchedAggregate_in s)
{
  this->idl_ << "union " << s->name () << " switch (";

  this->Visit_ConstantType (s->get_Discriminator ()->refers_to_ConstantType ());

  this->idl_ << ")" << nl
             << "{" << idt;

  typedef collection_sort <PICML::Member, GAME::Mga::PS_Top_To_Bottom> sorter;
  for (PICML::Member member : sorter () (s->get_Members (), "InterfaceDefinition"))
    member->accept (this);

  this->idl_ << uidt_nl << "};" << nl
             << nl;
}

//
// Visit_Member
//
void IDL_File_Generator::Visit_Member (const PICML::Member_in m)
{
  for (auto label_connection : m->src_of_LabelConnection ())
    label_connection->accept (this);
  this->idl_ << nl;

  if (this->in_event_)
    this->idl_ << "public ";

  this->Visit_MemberType (m->refers_to_MemberType ());
  this->idl_ << " " << m->name () << ";";

  for (auto member_connection : m->dst_of_KeyMember ())
    this->idl_ << "  // @key";

  this->idl_ << nl;
}

//
// Visit_ArrayMember
//
void IDL_File_Generator::
Visit_ArrayMember (const PICML::ArrayMember_in m)
{
  this->idl_ << nl;

  this->Visit_MemberType (m->refers_to_MemberType ());

  long array_size = static_cast <long> (m->Size ());
  this->idl_ << " " << m->name () << "[" << array_size << "];" << nl;
}

//
// Visit_Event
//
void IDL_File_Generator::Visit_Event (const PICML::Event_in e)
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
  this->Visit_ObjectByValue (e);
  this->in_event_ = false;

  this->idl_ << uidt_nl
             << "};" << nl;
}

//
// Visit_Event
//
void IDL_File_Generator::
Visit_ValueObject (const PICML::ValueObject_in v)
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

  this->Visit_ObjectByValue (v);

  this->idl_ << "};" << uidt_nl;
}

//
// Visit_ObjectByValue
//
void IDL_File_Generator::
Visit_ObjectByValue (const PICML::ObjectByValue_in o)
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
  visit_all () (sorter ()(o->get_Members ()));
  
}

//
// Visit_LabelConnection
//
void IDL_File_Generator::
Visit_LabelConnection (const PICML::LabelConnection_in c)
{
  PICML::Label label = c->dst_Label ();
  this->idl_ << "case " << label->name () << ":" << nl;
}

//
// Visit_Component
//
void IDL_File_Generator::Visit_Component (const PICML::Component_in c)
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
    for (PICML::Supports support : sorter () (supports))
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

  this->idl_ << uidt_nl
             << "};"
             << nl;
}

//
// Visit_ConnectorObject
//
void IDL_File_Generator::
Visit_ConnectorObject (const PICML::ConnectorObject_in c)
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
// Visit_ExtendedPort
//
void IDL_File_Generator::
Visit_ExtendedPort (const PICML::ExtendedPort_in p)
{
  this->idl_ << "port " << PICML::fq_type (p->refers_to_PortType (), "::", true)
             << " " << p->name () << ";" << nl;
}

//
// Visit_MirrorPort
//
void IDL_File_Generator::
Visit_MirrorPort (const PICML::MirrorPort_in p)
{
  this->idl_ << "mirrorport " << PICML::fq_type (p->refers_to_PortType (), "::", true)
             << " " << p->name () << ";" << nl;
}

//
// Visit_PortType
//
void IDL_File_Generator::Visit_PortType (const PICML::PortType_in p)
{
  this->idl_ << "porttype " << p->name () << nl
             << "{" << idt_nl;

  visit_all () (p->children <PICML::ObjectPort> (), this);

  this->idl_ << uidt_nl
             << "};" << nl
             << nl;
}

//
// Visit_ProvidedRequestPort
//
void IDL_File_Generator::
Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort_in p)
{
  this->idl_ << "provides ";
  this->Visit_Provideable (p->refers_to_Provideable ());
  this->idl_ << " " << p->name () << ";" << nl;
}

//
// Visit_RequiredRequestPort
//
void IDL_File_Generator::
Visit_RequiredRequestPort (const PICML::RequiredRequestPort_in p)
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

    this->Visit_Provideable (p->refers_to_Provideable ());
  this->idl_ << " " << p->name () << ";" << nl;
}

//
// Visit_InEventPort
//
void IDL_File_Generator::
Visit_InEventPort (const PICML::InEventPort_in p)
{
  this->idl_ << "consumes ";

  this->Visit_EventType (p->refers_to_EventType ());
  this->idl_ << " " << p->name () << ";" << nl;
}

//
// Visit_OutEventPort
//
void IDL_File_Generator::Visit_OutEventPort (const PICML::OutEventPort_in p)
{
  if (p->single_destination ())
    this->idl_ << "emits ";
  else
    this->idl_ << "publishes ";

  this->Visit_EventType (p->refers_to_EventType ());
  this->idl_ << " " << p->name () << ";" << nl;
}

/**
 * @struct is_async_receptacle_t
 */
struct is_async_receptacle_t
{
  bool operator () (const PICML::RequiredRequestPort_in p) const
  {
    return p->AsyncCommunication ();
  }
};

//
// Visit_Object
//
void IDL_File_Generator::Visit_Object (const PICML::Object_in o)
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
             << "};" << nl
             << nl;
}

//
// Visit_Inherits
//
void IDL_File_Generator::Visit_Inherits (const PICML::Inherits_in i)
{
  this->idl_ << ", " << nl
             << PICML::fq_type (i->refers_to_Inheritable (), "::", true);
}

//
// Visit_Alias
//
void IDL_File_Generator::Visit_Alias (const PICML::Alias_in a)
{
  this->idl_ << "typedef ";

  this->Visit_MemberType (a->refers_to_MemberType ());
  
  this->idl_ << " " << a->name () << ";" << nl
             << nl;
}

//
// Visit_Attribute
//
void IDL_File_Generator::Visit_Attribute (const PICML::Attribute_in a)
{
  this->idl_ << "attribute ";

  this->Visit_MemberType (a->get_AttributeMember ()->refers_to_MemberType ());

  this->idl_ << " " << a->name ();

  // Write the exception list, if any.
  GAME::Mga::Collection_T <PICML::GetException> get_exceptions = a->get_GetExceptions ();
  if (get_exceptions.size ())
  {
    this->idl_ << idt_nl
               << "getraises (";

    typedef collection_sort <PICML::GetException, GAME::Mga::PS_Left_To_Right> sorter;
    bool first_element = true;
    for (auto exception : sorter () (get_exceptions))
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      this->Visit_ExceptionType (exception);
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
    for (auto exception : sorter () (set_exceptions))
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      this->Visit_ExceptionType (exception);
    }

    this->idl_ << ")" << uidt_nl;
  }

  this->idl_ << ";" << nl;
}

//
// Visit_ReadonlyAttribute
//
void IDL_File_Generator::
Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute_in a)
{
  this->idl_ << "readonly attribute ";

  a->get_AttributeMember ()->accept (this);

  this->idl_ << " " << a->name () << ";" << nl;
}

//
// Visit_AttributeMember
//
void IDL_File_Generator::Visit_AttributeMember (const PICML::AttributeMember_in m)
{
  this->Visit_MemberType (m->refers_to_MemberType ());
}

//
// Visit_OnewayOperation
//
void IDL_File_Generator::
Visit_OnewayOperation (const PICML::OnewayOperation_in op)
{
  this->idl_ << nl
             << "oneway void " << op->name () << " (";

  GAME::Mga::Collection_T <PICML::ParameterType> params = op->children <PICML::ParameterType> ();
  if (params.size ())
  {
    typedef collection_sort <PICML::ParameterType, GAME::Mga::PS_Left_To_Right> sorter;
    bool first_element = true;
    for (auto parameter : sorter () (params))
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
// Visit_TwowayOperation
//
void IDL_File_Generator::
Visit_TwowayOperation (const PICML::TwowayOperation_in op)
{
  this->idl_ << nl;

  if (!op->has_ReturnType ())
    this->idl_ << "void";
  else
    this->Visit_MemberType (op->get_ReturnType ()->refers_to_MemberType ());

  this->idl_ << " " << op->name () << " (";

  GAME::Mga::Collection_T <PICML::ParameterType> params = op->children <PICML::ParameterType> ();
  if (params.size ())
  {
    typedef collection_sort <PICML::ParameterType, GAME::Mga::PS_Left_To_Right> sorter;
    bool first_element = true;
    for (auto parameter : sorter () (params))
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
    for (auto exception : sorter () (exceptions))
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      this->Visit_ExceptionType (exception);
    }

    this->idl_ << ")" << uidt;
  }

  this->idl_ << ";" << nl;
}

//
// Visit_InParameter
//
void IDL_File_Generator::Visit_InParameter (const PICML::InParameter_in p)
{
  this->idl_ << "in ";
  this->Visit_ParameterType (p);
}

//
// Visit_OutParameter
//
void IDL_File_Generator::Visit_OutParameter (const PICML::OutParameter_in p)
{
  this->idl_ << "out ";
  this->Visit_ParameterType (p);
}

//
// Visit_InoutParameter
//
void IDL_File_Generator::Visit_InoutParameter (const PICML::InoutParameter_in p)
{
  this->idl_ << "inout ";
  this->Visit_ParameterType (p);
}

//
// Visit_ParameterType
//
void IDL_File_Generator::Visit_ParameterType (const PICML::ParameterType_in pt)
{
  this->Visit_MemberType (pt->refers_to_MemberType ());
  this->idl_ << " " << pt->name ();
}

//
// Visit_Collection
//
void IDL_File_Generator::Visit_Collection (const PICML::Collection_in c)
{
  this->idl_ << "typedef sequence < ";

  this->Visit_MemberType (c->refers_to_MemberType ());

  std::string bound = c->bound ();
  if (!bound.empty ())
    this->idl_ << ", " << bound;

  this->idl_ << " > " << c->name () << ";" << nl
             << nl;
}

//
// Visit_Exception
//
void IDL_File_Generator::Visit_Exception (const PICML::Exception_in e)
{
  this->idl_ << "exception " << e->name () << nl
             << "{" << idt_nl;

  typedef collection_sort <PICML::Member, GAME::Mga::PS_Top_To_Bottom> sorter;
  for (auto value : sorter () (e->get_Members ()))
    value->accept (this);

  this->idl_ << uidt_nl
             << "};" << nl;
}

//
// Visit_ComponentFactory
//
void IDL_File_Generator::
Visit_ComponentFactory (const PICML::ComponentFactory_in f)
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
    for (PICML::Supports support : sorter () (supports))
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      this->idl_ << PICML::fq_type (support->refers_to_Object (), "::", true);
    }

    this->idl_ << uidt << uidt;
  }

  // Write the component that this home manages.
  GAME::Mga::Collection_T <PICML::ManagesComponent> manages = f->src_of_ManagesComponent ();
  if (manages.size ())
  {
    this->idl_ << nl
               << "manages ";

    bool first_element = true;
    for (PICML::ManagesComponent connection : manages)
    {
      if (!first_element)
        this->idl_ << ", ";
      first_element = false;

      this->idl_ << PICML::fq_type (connection->dst_Manageable (), "::", true);
    }
  }


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
// Visit_LookupOperation
//
void IDL_File_Generator::
Visit_LookupOperation (const PICML::LookupOperation_in op)
{
  this->idl_ << nl
             << "finder " << op->name () << " (";

  GAME::Mga::Collection_T <PICML::InParameter> params = op->get_InParameters ();
  if (params.size ())
  {
    bool is_first = true;
    typedef collection_sort <PICML::InParameter, GAME::Mga::PS_Left_To_Right> sorter;
    for (PICML::InParameter param : sorter () (params))
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

      this->Visit_ExceptionType (exception->refers_to_ExceptionType ());
    }
    this->idl_ << ")" << uidt;
  }

  this->idl_ << ";" << nl;
}

//
// Visit_FactoryOperation
//
void IDL_File_Generator::
Visit_FactoryOperation (const PICML::FactoryOperation_in op)
{
  this->idl_ << nl
             << "factory " << op->name () << " (";

  GAME::Mga::Collection_T <PICML::InParameter> params = op->get_InParameters ();
  if (params.size ())
  {
    bool is_first = true;
    typedef collection_sort <PICML::InParameter, GAME::Mga::PS_Left_To_Right> sorter;
    for (PICML::InParameter p : params)
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

      this->Visit_ExceptionType (ex->refers_to_ExceptionType ());
    }

    this->idl_ << ")" << uidt;
  }

  this->idl_ << ";";
}

//
// Visit_Byte
//
void IDL_File_Generator::Visit_Byte (const PICML::Byte_in b)
{
  this->idl_ << "octet";
}

//
// Visit_Char
//
void IDL_File_Generator::Visit_Char (const PICML::Char_in c)
{
  this->idl_ << "char";
}

//
// Visit_WideChar
//
void IDL_File_Generator::Visit_WideChar (const PICML::WideChar_in w)
{
  this->idl_ << "wchar";
}

//
// Visit_Boolean
//
void IDL_File_Generator::Visit_Boolean (const PICML::Boolean_in b)
{
  this->idl_ << "boolean";
}

//
// Visit_String
//
void IDL_File_Generator::Visit_String (const PICML::String_in s)
{
  this->idl_ << "string";
}

//
// Visit_WideString
//
void IDL_File_Generator::
Visit_WideString (const PICML::WideString_in )
{
  this->idl_ << "wstring";
}

//
// Visit_UnsignedShortInteger
//
void IDL_File_Generator::
Visit_UnsignedShortInteger (const PICML::UnsignedShortInteger_in s)
{
  this->idl_ << "unsigned short";
}

//
// Visit_UnsignedLongInteger
//
void IDL_File_Generator::
Visit_UnsignedLongInteger (const PICML::UnsignedLongInteger_in l)
{
  this->idl_ << "unsigned long";
}

//
// Visit_UnsignedLongLongInteger
//
void IDL_File_Generator::
Visit_UnsignedLongLongInteger (const PICML::UnsignedLongLongInteger_in )
{
  this->idl_ << "unsigned long long";
}

//
// Visit_ShortInteger
//
void IDL_File_Generator::Visit_ShortInteger (const PICML::ShortInteger_in s)
{
  this->idl_ << "short";
}

//
// Visit_LongInteger
//
void IDL_File_Generator::Visit_LongInteger (const PICML::LongInteger_in l)
{
  this->idl_ << "long";
}

//
// Visit_LongLongInteger
//
void IDL_File_Generator::
Visit_LongLongInteger (const PICML::LongLongInteger_in )
{
  this->idl_ << "long long";
}

//
// Visit_FloatNumber
//
void IDL_File_Generator::Visit_FloatNumber (const PICML::FloatNumber_in f)
{
  this->idl_ << "float";
}

//
// Visit_DoubleNumber
//
void IDL_File_Generator::Visit_DoubleNumber (const PICML::DoubleNumber_in d)
{
  this->idl_ << "double";
}

//
// Visit_LongDoubleNumber
//
void IDL_File_Generator::
Visit_LongDoubleNumber (const PICML::LongDoubleNumber_in)
{
  this->idl_ << "long double";
}

//
// Visit_GenericObject
//
void IDL_File_Generator::Visit_GenericObject (const PICML::GenericObject_in f)
{
  this->idl_ << "Object";
}

//
// Visit_GenericValue
//
void IDL_File_Generator::Visit_GenericValue (const PICML::GenericValue_in f)
{
  this->idl_ << "any";
}

//
// Visit_GenericValueObject
//
void IDL_File_Generator::
Visit_GenericValueObject (const PICML::GenericValueObject_in )
{
  this->idl_ << "ValueBase";
}

//
// Visit_TypeEncoding
//
void IDL_File_Generator::
Visit_TypeEncoding (const PICML::TypeEncoding_in t)
{
  // This is an "interface"
  this->idl_ << "::CORBA::TypeCode";
}

//
// Visit_TypeKind
//
void IDL_File_Generator::Visit_TypeKind (const PICML::TypeKind_in t)
{
  // This is a "enum"
  this->idl_ << "::CORBA::TCKind";
}

//
// Visit_Provideable
//
void IDL_File_Generator::Visit_Provideable (const PICML::Provideable_in p)
{
  if (p->meta ()->name () == PICML::Object::impl_type::metaname)
    this->idl_ << PICML::fq_type (PICML::Object::_narrow (p), "::", true);
  else if (p->meta ()->name () == PICML::GenericObject::impl_type::metaname)
    this->idl_ << "Object";
  else if (derives_from <PICML::TemplateParameter> () (p))
    this->idl_ << p->name ();
}

//
// Visit_TemplateParameterValueType
//
void IDL_File_Generator::
Visit_TemplateParameterValueType (const PICML::TemplateParameterValueType_in t)
{
  if (t->meta ()->name () == PICML::Exception::impl_type::metaname)
    this->idl_ << PICML::fq_type (t, "::", true);
  else
    this->Visit_MemberType (PICML::MemberType::_narrow (t));
}

//
// Visit_MemberType
//
void IDL_File_Generator::Visit_MemberType (const PICML::MemberType_in mt)
{
  if (derives_from <PICML::PredefinedType> () (mt))
    mt->accept (this);
  else if (derives_from <PICML::NamedType> () (mt))
    this->idl_ << PICML::fq_type (mt, "::", true);
  else if (derives_from <PICML::TemplateParameter> () (mt))
    this->idl_ << mt->name ();
  else
    this->idl_ << "/* unknown type (" << mt.type ().name () << ") */";
}

//
// Visit_ConstantType
//
void IDL_File_Generator::
Visit_ConstantType (const PICML::ConstantType_in ct)
{
  if (derives_from <PICML::PredefinedType> () (ct))
    ct->accept (this);
  else if (ct->meta ()->name () == PICML::Enum::impl_type::metaname)
    this->idl_ << PICML::fq_type (ct, "::", true);
  else
    this->idl_ << "/* unknown type */";
}

//
// Visit_EventType
//
void IDL_File_Generator::Visit_EventType (const PICML::EventType_in e)
{
  if (e->meta ()->name ()== PICML::Event::impl_type::metaname)
    this->idl_ << PICML::fq_type (e, "::", true);
  else if (derives_from <PICML::TemplateParameter> () (e))
    this->idl_ << e->name ();
}

//
// Visit_ExceptionType
//
void IDL_File_Generator::
Visit_ExceptionType (const PICML::ExceptionType_in e)
{
  if (e->meta ()->name () == PICML::Exception::impl_type::metaname)
    this->idl_ << PICML::fq_type (e, "::", true);
  else
    this->idl_ << e->name ();
}
