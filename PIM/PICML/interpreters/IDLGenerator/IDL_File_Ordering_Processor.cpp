// $Id$

#include "StdAfx.h"
#include <algorithm>

#include "IDL_File_Ordering_Processor.h"
#include "boost/graph/topological_sort.hpp"

#include "IDL_Cycle_Detector.h"

#include "game/mga/component/Console_Service.h"
#include <sstream>

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

//
// IDL_File_Ordering_Processor
//
IDL_File_Ordering_Processor::IDL_File_Ordering_Processor (void) :
  visit_template_module_ (false),
  forward_declaration_ (false)
{
}

//
// ~IDL_File_Ordering_Processor
//
IDL_File_Ordering_Processor::~IDL_File_Ordering_Processor (void)
{
}

//
// visit_file
//
void IDL_File_Ordering_Processor::
visit_file (const PICML::File & file, bool forward_declaration)
{
  this->clear (forward_declaration);
  this->forward_declaration_ = forward_declaration;
  this->insert (file);
  visit_all () (file->get_Constants (), this);
  visit_all () (file->get_Aliass (), this);
  visit_all () (file->get_Collections (), this);
  visit_all () (file->get_Exceptions (), this);
  visit_all () (file->get_Enums (), this);
  visit_all () (file->get_Aggregates (), this);
  visit_all () (file->get_SwitchedAggregates (), this);
  visit_all () (file->get_ValueObjects (), this);
  visit_all () (file->get_TemplatePackageInstances (), this);
  visit_all () (file->get_PortTypes (), this);
  visit_all () (file->get_Events (), this);
  visit_all () (file->get_Objects (), this);
  visit_all () (file->get_ManagesComponents (), this);
  visit_all () (file->get_Components (), this);
  visit_all () (file->get_ComponentFactorys (), this);
  visit_all () (file->get_ConnectorObjects (), this);
  visit_all () (file->get_Boxeds (), this);
  visit_all () (file->get_Packages (), this);
}

//
// visit_Package
//
void IDL_File_Ordering_Processor::
visit_Package (PICML::Package_in p)
{
  this->insert (p);
  this->add_node (p);
  visit_all () (p->get_Constants (), this);
  visit_all () (p->get_Aliass (), this);
  visit_all () (p->get_Collections (), this);
  visit_all () (p->get_Exceptions (), this);
  visit_all () (p->get_Enums (), this);
  visit_all () (p->get_Aggregates (), this);
  visit_all () (p->get_SwitchedAggregates (), this);
  visit_all () (p->get_ValueObjects (), this);
  visit_all () (p->get_TemplatePackageInstances (), this);
  visit_all () (p->get_PortTypes (), this);
  visit_all () (p->get_Events (), this);
  visit_all () (p->get_Objects (), this);
  visit_all () (p->get_ManagesComponents (), this);
  visit_all () (p->get_Components (), this);
  visit_all () (p->get_ComponentFactorys (), this);
  visit_all () (p->get_ConnectorObjects (), this);
  visit_all () (p->get_Boxeds (), this);
  visit_all () (p->get_Packages (), this);
}

//
// visit_Package
//
void IDL_File_Ordering_Processor::
visit_package (PICML::Package_in p, PICML::Visitor * v)
{
  visit_all () (p->get_Constants (), v);
  visit_all () (p->get_Aliass (), v);
  visit_all () (p->get_Collections (), v);
  visit_all () (p->get_Exceptions (), v);
  visit_all () (p->get_Enums (), v);
  visit_all () (p->get_Aggregates (), v);
  visit_all () (p->get_SwitchedAggregates (), v);
  visit_all () (p->get_ValueObjects (), v);
  visit_all () (p->get_TemplatePackageInstances (), v);
  visit_all () (p->get_PortTypes (), v);
  visit_all () (p->get_Events (), v);
  visit_all () (p->get_Objects (), v);
  visit_all () (p->get_ManagesComponents (), v);
  visit_all () (p->get_Components (), v);
  visit_all () (p->get_ComponentFactorys (), v);
  visit_all () (p->get_ConnectorObjects (), v);
  visit_all () (p->get_Boxeds (), v);
  visit_all () (p->get_Packages (), v);
}

//
// visit_Aggregate
//
void IDL_File_Ordering_Processor::
visit_Aggregate (const PICML::Aggregate & a)
{
  std::ostringstream ostr;
  ostr << "Visiting aggregate in file ordering processor";
  GME_CONSOLE_SERVICE->info (ostr.str ().c_str ());

  this->add_node (a);
  this->add_edge<PICML::Member, PICML::Aggregate> (a);
  this->add_edge<PICML::ArrayMember, PICML::Aggregate> (a);
  // From what I could tell, we only add edges for references, so commenting this out
  //this->add_edge<PICML::Key, PICML::Aggregate> (a);
}

//
// visit_ArrayMember
//
void IDL_File_Ordering_Processor::
visit_ArrayMember (PICML::ArrayMember_in m)
{
  this->add_node (m);
}

//
// visit_Boxed
//
void IDL_File_Ordering_Processor::
visit_Boxed (PICML::Boxed_in b)
{
  this->add_node (b);
}

//
// visit_SwitchedAggregate
//
void IDL_File_Ordering_Processor::
visit_SwitchedAggregate (const PICML::SwitchedAggregate & s)
{
  this->add_node (s);
  this->add_edge<PICML::Member, PICML::SwitchedAggregate> (s);
  this->add_edge<PICML::ArrayMember, PICML::SwitchedAggregate> (s);
  this->add_edge<PICML::Discriminator, PICML::SwitchedAggregate> (s);
}

//
// visit_Member
//
void IDL_File_Ordering_Processor::
visit_Member (PICML::Member_in a)
{
  this->add_node (a);
}

//
// visit_Enum
//
void IDL_File_Ordering_Processor::
visit_Enum (PICML::Enum_in e)
{
  this->add_node (e);
}

//
// visit_Constant
//
void IDL_File_Ordering_Processor::
visit_Constant (PICML::Constant_in a)
{
  this->add_node (a);
}

//
// visit_Alias
//
void IDL_File_Ordering_Processor::
visit_Alias (PICML::Alias_in a)
{
  this->add_node (a);
}

//
// visit_Collection
//
void IDL_File_Ordering_Processor::
visit_Collection (PICML::Collection_in c)
{
  this->add_node (c);
}

//
// visit_Exception
//
void IDL_File_Ordering_Processor::
visit_Exception (PICML::Exception_in e)
{
  this->add_node (e);
}

//
// visit_TemplatePackageInstance
//
void IDL_File_Ordering_Processor::
visit_TemplatePackageInstance (const PICML::TemplatePackageInstance & t)
{
  this->add_node (t);
  this->add_edge<PICML::PackageType, PICML::TemplatePackageInstance> (t);
  this->add_edge<PICML::TemplateParameterValue, PICML::TemplatePackageInstance> (t);
}

//
// visit_Object
//
void IDL_File_Ordering_Processor::
visit_Object (PICML::Object_in o)
{
  this->add_node (o);
  visit_all () (o->get_Constants (), this);
  visit_all () (o->get_Aliass (), this);
  visit_all () (o->get_Collections (), this);
  visit_all () (o->get_Exceptions (), this);
  visit_all () (o->get_Enums (), this);
  visit_all () (o->get_Aggregates (), this);
  visit_all () (o->get_SwitchedAggregates (), this);
  visit_all () (o->get_Attributes (), this);
  visit_all () (o->get_OnewayOperations (), this);
  visit_all () (o->get_TwowayOperations (), this);
  visit_all () (o->get_PortTypes (), this);
}

//
// visit_PortType
//
void IDL_File_Ordering_Processor::
visit_PortType (PICML::PortType_in p)
{
  this->add_node (p);
}

//
// visit_ValueObject
//
void IDL_File_Ordering_Processor::
visit_ValueObject (PICML::ValueObject_in o)
{
  this->add_node (o);
}

//
// visit_Event
//
void IDL_File_Ordering_Processor::
visit_Event (const PICML::Event & e)
{
  this->add_node (e);
  this->add_edge<PICML::ArrayMember, PICML::Event> (e);
  this->add_edge<PICML::Member, PICML::Event> (e);
  this->add_edge<PICML::Alias, PICML::Event> (e);
  this->add_edge<PICML::Collection, PICML::Event> (e);
  this->add_edge<PICML::Supports, PICML::Event> (e);
  this->add_edge<PICML::Inherits, PICML::Event> (e);
}

//
// visit_Component
//
void IDL_File_Ordering_Processor::
visit_Component (const PICML::Component & c)
{
  this->add_node (c);
  this->add_edge<PICML::ComponentInherits, PICML::Component> (c);
  this->add_edge<PICML::Supports, PICML::Component> (c);
  this->add_edge<PICML::RequiredRequestPort, PICML::Component> (c);
  this->add_edge<PICML::ProvidedRequestPort, PICML::Component> (c);
  this->add_edge<PICML::OutEventPort, PICML::Component> (c);
  this->add_edge<PICML::InEventPort, PICML::Component> (c);
  this->add_edge<PICML::MirrorPort, PICML::Component> (c);
  this->add_edge<PICML::ExtendedPort, PICML::Component> (c);
  visit_all () (c->get_Attributes (), this);
}

//
// visit_ReadonlyAttribute
//
void IDL_File_Ordering_Processor::
visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & r)
{
  this->add_edge<PICML::AttributeMember, PICML::ReadonlyAttribute> (r);
  this->add_edge<PICML::GetException, PICML::ReadonlyAttribute> (r);
}

//
// visit_Attribute
//
void IDL_File_Ordering_Processor::
visit_Attribute (const PICML::Attribute & a)
{
  this->add_edge<PICML::AttributeMember, PICML::Attribute> (a);
  this->add_edge<PICML::GetException, PICML::Attribute> (a);
  this->add_edge<PICML::SetException, PICML::Attribute> (a);
}

//
// visit_ConnectorObject
//
void IDL_File_Ordering_Processor::
visit_ConnectorObject (PICML::ConnectorObject_in c)
{
  this->add_node (c);
}

//
// visit_ManagesComponent
//
void IDL_File_Ordering_Processor::
visit_ManagesComponent (const PICML::ManagesComponent & m)
{
  this->add_edge (m);
}

//
// visit_ComponentFactory
//
void IDL_File_Ordering_Processor::
visit_ComponentFactory (PICML::ComponentFactory_in c)
{
  this->add_node (c);
}

//
// visit_TwowayOperation
//
void IDL_File_Ordering_Processor::
visit_TwowayOperation (const PICML::TwowayOperation & t)
{
  this->add_edge <PICML::ReturnType, PICML::Object> (t);
  this->add_edge <PICML::InParameter, PICML::Object> (t);
  this->add_edge <PICML::InoutParameter, PICML::Object> (t);
  this->add_edge <PICML::OutParameter, PICML::Object> (t);
  this->add_edge <PICML::ExceptionRef, PICML::Object> (t);
}

//
// visit_OnewayOperation
//
void IDL_File_Ordering_Processor::
visit_OnewayOperation (const PICML::OnewayOperation & o)
{
  this->add_edge <PICML::InParameter, PICML::Object> (o);
}

//
// add_node
//
void IDL_File_Ordering_Processor::
add_node (const GAME::Mga::Object & o)
{
  std::ostringstream ostr;
  ostr << "add_node called on: " << o->name ();
  GME_CONSOLE_SERVICE->info (ostr.str ().c_str ());
  OBJECT_ACCESSOR information = boost::get (Object (), *this->current_graph_);

  if (o->parent ()->meta ()->name () == PICML::File::impl_type::metaname && this->map_.find (o) == this->map_.end ())
  {
    this->add_vertex (o, this->current_graph_);
  }
  else
  {
    for (GAME::Mga::Object parent = o->parent ();
         parent->meta ()->name () != PICML::File::impl_type::metaname;
         parent = parent->parent ())
    {
      if (parent->parent ()->meta ()->name () == PICML::File::impl_type::metaname && this->map_.find (parent) == this->map_.end ())
      {
        this->add_vertex (parent, this->current_graph_);
      }
    }
  }
}

//
// add_vertex
//
void IDL_File_Ordering_Processor::
add_vertex (const GAME::Mga::FCO & o,
            GRAPH_PTR graph)
{
  OBJECT_ACCESSOR information = boost::get (Object (), *graph);

  VERTEX vertex = boost::add_vertex (*graph);

  boost::put (information, vertex, o);

  this->map_.insert (MAP::value_type(o, o->is_subtype ()));
}

//
// add_vertices
//
void IDL_File_Ordering_Processor::
add_vertices (const GAME::Mga::FCO & parent_ref1,
              const GAME::Mga::FCO & parent_ref2,
              GRAPH_PTR graph)
{
  OBJECT_ACCESSOR information = boost::get (Object (), *graph);

  // add the parents to the forward declaration graph
  VERTEX reference = boost::add_vertex (*graph);
  VERTEX direct = boost::add_vertex (*graph);

  boost::put (information, direct, parent_ref2);
  boost::put (information, reference, parent_ref1);

  // add the dependency between the parents
  EDGE e;
  bool added = false;
  boost::tie(e,added) = boost::add_edge (reference, direct, *graph);

  this->map_.insert (MAP::value_type (parent_ref1, parent_ref1->is_subtype ()));
  this->map_.insert (MAP::value_type (parent_ref2, parent_ref2->is_subtype ()));
}

//
// topological_sort
//
void IDL_File_Ordering_Processor::
topological_sort_i (CONTAINER & container)
{
  this->process_forward_declaration (); // remove any cycles from the graph
  this->insert (container);
}

//
// topological_sort
//
void IDL_File_Ordering_Processor::
topological_sort (CONTAINER & container)
{
  this->topological_sort_i (container);
}

//
// graph
//
const IDL_File_Ordering_Processor::GRAPH & IDL_File_Ordering_Processor::
graph (void)
{
  return *this->current_graph_;
}

//
// clear
//
void IDL_File_Ordering_Processor::
clear (bool clear_forward_declaration)
{
  if (clear_forward_declaration)
  {
    this->forward_.clear ();
    this->forward_decl_.clear ();
  }

  this->edge_.clear ();
  this->map_.clear ();
  this->list_.clear ();
}

//
// find_vertex
//
IDL_File_Ordering_Processor::VERTEX IDL_File_Ordering_Processor::
find_vertex (const GAME::Mga::Object_in o, GRAPH_PTR graph, bool & found)
{
  boost::graph_traits<IDL_File_Ordering_Processor::GRAPH>::vertex_iterator vi, vi_end;

  GAME::Mga::Object v;

  for (boost::tie (vi, vi_end) = boost::vertices (*graph); vi != vi_end; ++vi)
  {
    v = boost::get (Object (), *graph, (*vi));

    if (v->id () == o->id ())
    {
      found = true;
      break;
    }
  }

  return *vi;
}

//
// visit_template_module
//
bool IDL_File_Ordering_Processor::
visit_template_module (void)
{
  return this->visit_template_module_;
}

//
// visit_template_module
//
void IDL_File_Ordering_Processor::
visit_template_module (bool visit_template_module)
{
  this->visit_template_module_ = visit_template_module;
}

//
// visit_template_module
//
void IDL_File_Ordering_Processor::
process_forward_declaration (void)
{
  bool has_cycle = false;
  IDL_Cycle_Detector cycle_detector (has_cycle,
                                     this->forward_decl_,
                                     this->edge_);

  for (LIST::iterator it = this->list_.begin (); it != this->list_.end (); ++it)
  {
    this->edge_.clear ();

    do
    {
      has_cycle = false;
      cycle_detector.current_graph ((*it).second);

      boost::depth_first_search (*(*it).second, boost::visitor (cycle_detector));

      if (has_cycle)
        this->remove_back_edges ((*it).second);

    } while (has_cycle);
  }

  this->forward_declaration_i ();
}

//
// forward_declaration
//
bool IDL_File_Ordering_Processor::
forward_declaration (void)
{
  return (this->forward_decl_.size () > 0);
}

//
// forward_declaration_i
//
void IDL_File_Ordering_Processor::
forward_declaration_i (void)
{
  for (FORWARD_IT it = this->forward_decl_.begin (); it != this->forward_decl_.end (); ++it)
  {
    this->set_forward_declaration ((*it).first, (*it).second);
  }
}

//
// set_forward_declaration
//
void IDL_File_Ordering_Processor::
set_forward_declaration (VERTEX & v, GRAPH_PTR g)
{
  GAME::Mga::Object o;

  o = boost::get (IDL_File_Ordering_Processor::Object (), *g, v);
  this->forward_.insert (MAP::value_type (o, GAME::Mga::FCO::_narrow (o)->is_subtype ()));
}

//
// remove_back_edges
//
void IDL_File_Ordering_Processor::
remove_back_edges (GRAPH_PTR graph)
{
  for (IDL_File_Ordering_Processor::EDGE_IT it = this->edge_.begin (); it != this->edge_.end (); ++it)
  {
    boost::remove_edge ((*it), *graph);
  }
}

//
// insert
//
void IDL_File_Ordering_Processor::
insert (const GAME::Mga::Object_in o)
{
  std::ostringstream ostr;
  ostr << "Insert called on: " << o->name ();
  GME_CONSOLE_SERVICE->info (ostr.str ().c_str ());

  if (o->meta ()->name () == PICML::File::impl_type::metaname)
  {
    this->current_graph_ = GRAPH_PTR (new GRAPH);
    this->list_.push_back (LIST::value_type (o, this->current_graph_));
  }
  else if (this->forward_declaration_ && o->parent ()->meta ()->name () == PICML::File::impl_type::metaname)
  {
    this->current_graph_ = GRAPH_PTR (new GRAPH);
    this->list_.push_back (LIST::value_type (o, this->current_graph_));

    OBJECT_ACCESSOR information = boost::get (Object (), *this->current_graph_);

    VERTEX parent = boost::add_vertex (*this->current_graph_);

    boost::put (information, parent, o);
  }
}

//
// no_forward_declared
//
bool IDL_File_Ordering_Processor::
no_forward_declaration (const GAME::Mga::Object_in o)
{
  MAP::iterator it = this->forward_.find (o);

  return (it == this->forward_.end ());
}

//
// insert
//
void IDL_File_Ordering_Processor::
insert (CONTAINER & c)
{
  for (LIST::iterator it = this->list_.begin (); it != this->list_.end (); ++it)
  {
    boost::topological_sort (*(*it).second, std::back_inserter (c));
  }
}

//
// same_parent
//
bool IDL_File_Ordering_Processor::
same_parent_before_file (const GAME::Mga::Object_in o, const GAME::Mga::Object_in p)
{
  return parent_before_file (o)->id () == parent_before_file (p)->id ();
}

//
// parent_in_same_file
//
bool IDL_File_Ordering_Processor::
parent_in_same_file (const GAME::Mga::Object_in o, const GAME::Mga::Object_in p)
{
  return parent_file (o)->id () == parent_file (p)->id ();
}

//
// parent_file
//
GAME::Mga::Object IDL_File_Ordering_Processor::
parent_file (const GAME::Mga::Object_in o)
{
  if (o->meta ()->name () == PICML::File::impl_type::metaname)
    return 0;

  GAME::Mga::Object parent;

  for (parent = o->parent (); parent->meta ()->name () != PICML::File::impl_type::metaname; parent = parent->parent ());

  return parent;
}

//
// parent_before_file
//
GAME::Mga::FCO IDL_File_Ordering_Processor::parent_before_file (const GAME::Mga::Object_in o)
{
  GAME::Mga::Object parent;

  for (parent = o->parent (); parent->meta ()->name () != PICML::File::impl_type::metaname; parent = parent->parent ())
  {
    if (parent->parent ()->meta ()->name () == PICML::File::impl_type::metaname)
      break;
  }

  return parent;
}

//
// add_edge
//
void IDL_File_Ordering_Processor::
add_edge (const GAME::Mga::Object_in o)
{
  if (o->meta ()->name () == PICML::ManagesComponent::impl_type::metaname)
  {
    PICML::ManagesComponent mc = PICML::ManagesComponent::_narrow (o);
    ::PICML::ComponentFactory c = mc->src_ComponentFactory ();
    ::PICML::Manageable m = mc->dst_Manageable ();

    this->add_node (c);
    this->add_node (m);

    bool found_component = false;
    bool found_manageable = false;

    VERTEX manageable = this->find_vertex (c, this->current_graph_, found_manageable);
    VERTEX component = this->find_vertex (m, this->current_graph_, found_component);

    EDGE e;
    bool added = false;

    boost::tie(e,added) = boost::add_edge (component, manageable, *this->current_graph_);
  }
}
