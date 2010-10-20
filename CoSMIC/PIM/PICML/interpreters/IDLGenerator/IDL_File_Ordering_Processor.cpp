// $Id$

#include "StdAfx.h"
#include <algorithm>

#include "IDL_File_Ordering_Processor.h"
#include "boost/graph/topological_sort.hpp"

#include "Utils/UDM/visit.h"
#include "IDL_Cycle_Detector.h"

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
visit_file (const Udm::Object & object, bool forward_declaration)
{
  this->clear (forward_declaration);
  this->forward_declaration_ = forward_declaration;
  this->insert (object);
  this->visit_file_package (object);
}

//
// Visit_Package
//
void IDL_File_Ordering_Processor::
Visit_Package (const PICML::Package & package)
{
  this->insert (package);
  this->add_node (package);
  this->visit_file_package (package);
}

//
// visit_file_package
//
void IDL_File_Ordering_Processor::
visit_file_package (const Udm::Object & object)
{
  this->visit_all (object, *this);
}

//
// Visit_Aggregate
//
void IDL_File_Ordering_Processor::
Visit_Aggregate (const PICML::Aggregate & a)
{
  this->add_node (a);
  this->add_edge<PICML::Member, PICML::Aggregate> (a);
  this->add_edge<PICML::ArrayMember, PICML::Aggregate> (a);
  this->add_edge<PICML::Key, PICML::Aggregate> (a);
}

//
// Visit_ArrayMember
//
void IDL_File_Ordering_Processor::
Visit_ArrayMember (const PICML::ArrayMember & m)
{
  this->add_node (m);
}

//
// Visit_Boxed
//
void IDL_File_Ordering_Processor::
Visit_Boxed (const PICML::Boxed & b)
{
  this->add_node (b);
}

//
// Visit_SwitchedAggregate
//
void IDL_File_Ordering_Processor::
Visit_SwitchedAggregate (const PICML::SwitchedAggregate & s)
{
  this->add_node (s);
  this->add_edge<PICML::Member, PICML::SwitchedAggregate> (s);
  this->add_edge<PICML::ArrayMember, PICML::SwitchedAggregate> (s);
  this->add_edge<PICML::Discriminator, PICML::SwitchedAggregate> (s);
}

//
// Visit_SwitchedAggregate
//
void IDL_File_Ordering_Processor::
Visit_Member (const PICML::Member & a)
{
  this->add_node (a);
}

//
// Visit_Enum
//
void IDL_File_Ordering_Processor::
Visit_Enum (const PICML::Enum & e)
{
  this->add_node (e);
}

//
// Visit_Constant
//
void IDL_File_Ordering_Processor::
Visit_Constant (const PICML::Constant & a)
{
  this->add_node (a);
}

//
// Visit_Alias
//
void IDL_File_Ordering_Processor::
Visit_Alias (const PICML::Alias & a)
{
  this->add_node (a);
}

//
// Visit_Collection
//
void IDL_File_Ordering_Processor::
Visit_Collection (const PICML::Collection & c)
{
  this->add_node (c);
}

//
// Visit_Exception
//
void IDL_File_Ordering_Processor::
Visit_Exception (const PICML::Exception & e)
{
  this->add_node (e);
}

//
// Visit_TemplatePackageInstance
//
void IDL_File_Ordering_Processor::
Visit_TemplatePackageInstance (const PICML::TemplatePackageInstance & t)
{
  this->add_node (t);
  this->add_edge<PICML::PackageType, PICML::TemplatePackageInstance> (t);
  this->add_edge<PICML::TemplateParameterValue, PICML::TemplatePackageInstance> (t);
}

//
// Visit_Object
//
void IDL_File_Ordering_Processor::
Visit_Object (const PICML::Object & o)
{
  this->add_node (o);
  this->visit_all (o, *this);
}

//
// Visit_PortType
//
void IDL_File_Ordering_Processor::
Visit_PortType (const PICML::PortType & p)
{
  this->add_node (p);
}

//
// Visit_ValueObject
//
void IDL_File_Ordering_Processor::
Visit_ValueObject (const PICML::ValueObject & o)
{
  this->add_node (o);
}

//
// Visit_Event
//
void IDL_File_Ordering_Processor::
Visit_Event (const PICML::Event & e)
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
// Visit_Component
//
void IDL_File_Ordering_Processor::
Visit_Component (const PICML::Component & c)
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
  this->visit_all (c, *this);
}

//
// Visit_ReadonlyAttribute
//
void IDL_File_Ordering_Processor::
Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & r)
{
  this->add_edge<PICML::AttributeMember, PICML::ReadonlyAttribute> (r);
  this->add_edge<PICML::GetException, PICML::ReadonlyAttribute> (r);
}

//
// Visit_Attribute
//
void IDL_File_Ordering_Processor::
Visit_Attribute (const PICML::Attribute & a)
{
  this->add_edge<PICML::AttributeMember, PICML::Attribute> (a);
  this->add_edge<PICML::GetException, PICML::Attribute> (a);
  this->add_edge<PICML::SetException, PICML::Attribute> (a);
}

//
// Visit_ConnectorObject
//
void IDL_File_Ordering_Processor::
Visit_ConnectorObject (const PICML::ConnectorObject & c)
{
  this->add_node (c);
}

//
// Visit_ComponentFactory
//
void IDL_File_Ordering_Processor::
Visit_ComponentFactory (const PICML::ComponentFactory & c)
{
  this->add_node (c);
}

//
// Visit_TwowayOperation
//
void IDL_File_Ordering_Processor::
Visit_TwowayOperation (const PICML::TwowayOperation & t)
{
  this->add_edge <PICML::ReturnType, PICML::Object> (t);
  this->add_edge <PICML::InParameter, PICML::Object> (t);
  this->add_edge <PICML::InoutParameter, PICML::Object> (t);
  this->add_edge <PICML::OutParameter, PICML::Object> (t);
  this->add_edge <PICML::ExceptionRef, PICML::Object> (t);
}

//
// Visit_OnewayOperation
//
void IDL_File_Ordering_Processor::
Visit_OnewayOperation (const PICML::OnewayOperation & o)
{
  this->add_edge <PICML::InParameter, PICML::Object> (o);
}

//
// add_node
//
void IDL_File_Ordering_Processor::
add_node (const Udm::Object & o)
{
  OBJECT_ACCESSOR information = boost::get (Udm_Object (), *this->current_graph_);
  
  if (o.GetParent ().type () == PICML::File::meta && this->map_.find (o) == this->map_.end ())
  {
    this->add_vertex (o, this->current_graph_);
  }
  else
  {
    for (Udm::Object parent = o.GetParent (); parent.type () != PICML::File::meta; parent = parent.GetParent ())
    {
      if (parent.GetParent ().type () == PICML::File::meta && this->map_.find (parent) == this->map_.end ())
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
add_vertex (const Udm::Object & o, 
            GRAPH_PTR graph)
{
  OBJECT_ACCESSOR information = boost::get (Udm_Object (), *graph);
  
  VERTEX vertex = boost::add_vertex (*graph);

  boost::put (information, vertex, o);

  this->map_.insert (MAP::value_type(o, o.isSubtype ()));
}

//
// add_vertices
//
void IDL_File_Ordering_Processor::
add_vertices (const Udm::Object & parent_ref1,
              const Udm::Object & parent_ref2, 
              GRAPH_PTR graph)
{
  OBJECT_ACCESSOR information = boost::get (Udm_Object (), *graph);
  
  // add the parents to the forward declaration graph
  VERTEX reference = boost::add_vertex (*graph);
  VERTEX direct = boost::add_vertex (*graph);
  
  boost::put (information, direct, parent_ref2);
  boost::put (information, reference, parent_ref1);
  
  // add the dependency between the parents
  EDGE e; 
  bool added = false; 
  boost::tie(e,added) = boost::add_edge (reference, direct, *graph);
  
  this->map_.insert (MAP::value_type (parent_ref1, parent_ref1.isSubtype ()));
  this->map_.insert (MAP::value_type (parent_ref2, parent_ref2.isSubtype ()));
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
find_vertex (const Udm::Object & o, GRAPH_PTR graph, bool & found)
{
  boost::graph_traits<IDL_File_Ordering_Processor::GRAPH>::vertex_iterator vi, vi_end;
  
  Udm::Object v;
  
  for (boost::tie (vi, vi_end) = boost::vertices (*graph); vi != vi_end; ++vi)
  {
    v = boost::get (Udm_Object (), *graph, (*vi)); 
    
    if (v.uniqueId () == o.uniqueId ())
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
// visit_all
//
void IDL_File_Ordering_Processor::
visit_all (const Udm::Object & o, PICML::Visitor & visitor, bool forward_declaration)
{
  Udm::visit_all <PICML::Constant> (o, visitor);
  Udm::visit_all <PICML::Alias> (o, visitor);
  Udm::visit_all <PICML::Collection> (o, visitor);
  Udm::visit_all <PICML::Exception> (o, visitor);
  Udm::visit_all <PICML::Aggregate> (o, visitor);
  Udm::visit_all <PICML::SwitchedAggregate> (o, visitor);
  Udm::visit_all <PICML::ValueObject> (o, visitor);
  Udm::visit_all <PICML::ReadonlyAttribute> (o, visitor);
  Udm::visit_all <PICML::Attribute> (o, visitor);

  Udm::visit_all <PICML::TemplatePackageInstance> (o, visitor);

  Udm::visit_all <PICML::OnewayOperation> (o, visitor);
  Udm::visit_all <PICML::TwowayOperation> (o, visitor);
  
  Udm::visit_all <PICML::PortType> (o, visitor);
  Udm::visit_all <PICML::Event> (o, visitor);
  Udm::visit_all <PICML::Object> (o, visitor);
  
  Udm::visit_all <PICML::Component> (o, visitor);
  Udm::visit_all <PICML::ComponentFactory> (o, visitor);
  Udm::visit_all <PICML::ConnectorObject> (o, visitor);
  Udm::visit_all <PICML::Boxed> (o, visitor);
  
  Udm::visit_all <PICML::Package> (o, visitor);
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
    do
    {
      has_cycle = false;
      cycle_detector.current_graph ((*it).second);
      
      boost::depth_first_search (*(*it).second, boost::visitor (cycle_detector));
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
  Udm::Object o;
  
  o = boost::get (IDL_File_Ordering_Processor::Udm_Object (), *g, v);
  
  if (o != Udm::null)
    this->forward_.insert (MAP::value_type (o, o.isSubtype ()));
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
insert (const Udm::Object & o)
{
  if (o.type () == PICML::File::meta)
  {
    this->current_graph_ = GRAPH_PTR (new GRAPH);
    this->list_.push_back (LIST::value_type (o, this->current_graph_));
  }
  else if (this->forward_declaration_ && o.GetParent ().type () == PICML::File::meta)
  {
    this->current_graph_ = GRAPH_PTR (new GRAPH);
    this->list_.push_back (LIST::value_type (o, this->current_graph_));
    
    OBJECT_ACCESSOR information = boost::get (Udm_Object (), *this->current_graph_);
    
    VERTEX parent = boost::add_vertex (*this->current_graph_);
    
    boost::put (information, parent, o);
    
  }
}

//
// no_forward_declared
//
bool IDL_File_Ordering_Processor::
no_forward_declaration (const Udm::Object & o)
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
same_parent_before_file (const Udm::Object & o, const Udm::Object & p)
{
  return parent_before_file (o).uniqueId () == parent_before_file (p).uniqueId ();
}

//
// parent_in_same_file
//
bool IDL_File_Ordering_Processor::
parent_in_same_file (const Udm::Object & o, const Udm::Object & p)
{
  return parent_file (o).uniqueId () == parent_file (p).uniqueId ();
}

//
// parent_file
//
Udm::Object IDL_File_Ordering_Processor::
parent_file (const Udm::Object & o)
{
  Udm::Object parent;

  for (parent = o.GetParent (); parent.type () != PICML::File::meta; parent = parent.GetParent ())
  {}
  
  return parent;
}

//
// parent_before_file
//
Udm::Object IDL_File_Ordering_Processor::
parent_before_file (const Udm::Object & o)
{
  Udm::Object parent;

  for (parent = o.GetParent (); parent.type () != PICML::File::meta; parent = parent.GetParent ())
  {
    if (parent.GetParent ().type () == PICML::File::meta)
      break;
  }
    
  return parent;
}
