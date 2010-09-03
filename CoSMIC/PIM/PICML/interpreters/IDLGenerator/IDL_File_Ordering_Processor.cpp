// $Id$

#include "StdAfx.h"
#include <algorithm>

#include "IDL_File_Ordering_Processor.h"
#include "boost/graph/topological_sort.hpp"

#include "Utils/UDM/visit.h"

//
// IDL_File_Ordering_Processor
//
IDL_File_Ordering_Processor::IDL_File_Ordering_Processor (void) :
  visit_template_module_ (false)
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
visit_file (const Udm::Object & object)
{
  this->visit_file_package (object);
}

//
// Visit_Package
//
void IDL_File_Ordering_Processor::
Visit_Package (const PICML::Package & package)
{
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
  this->add_edge (a);
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
// Visit_SwitchedAggregate
//
void IDL_File_Ordering_Processor::
Visit_SwitchedAggregate (const PICML::SwitchedAggregate & s)
{
  this->add_edge (s);
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
}

//
// Visit_Object
//
void IDL_File_Ordering_Processor::
Visit_Object (const PICML::Object & o)
{
  this->add_node (o);
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
}

//
// Visit_Component
//
void IDL_File_Ordering_Processor::
Visit_Component (const PICML::Component & c)
{
  this->add_edge (c);
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
// add_node
//
void IDL_File_Ordering_Processor::
add_node (const Udm::Object & o)
{
  ACCESSOR information = boost::get (Udm_Object (), this->graph_);
  if (o.GetParent ().type () == PICML::File::meta && this->map_.find (o.uniqueId ()) == this->map_.end ())
  {
    VERTEX vertex = boost::add_vertex (this->graph_);
    
    boost::put (information, vertex, o);
    
    this->map_.insert (std::pair<UDM_NAMESPACE::ObjectImpl::uniqueId_type, bool>(o.uniqueId (), o.isSubtype ()));
  }
  else
  {
    for (Udm::Object parent = o.GetParent (); parent.type () != PICML::File::meta; parent = parent.GetParent ())
    {
      if (parent.GetParent ().type () == PICML::File::meta && this->map_.find (parent.uniqueId ()) == this->map_.end ())
      {
        VERTEX vertex = boost::add_vertex (this->graph_);
        
        boost::put (information, vertex, parent);
        
        this->map_.insert (std::pair<UDM_NAMESPACE::ObjectImpl::uniqueId_type, bool>(parent.uniqueId (), parent.isSubtype ()));
      }
    }
  }
}

//
// add_edge
//
void IDL_File_Ordering_Processor::
add_edge (const Udm::Object & o)
{
  typedef vector <PICML::Member> VECTOR;
  typedef vector <PICML::Member>::const_iterator ITER;
  
  VECTOR children = Udm::ChildrenAttr <PICML::Member> (o.__impl (), Udm::NULLCHILDROLE);
  ACCESSOR information = boost::get(Udm_Object (), this->graph_);
  // Determine child references a another object, if so handle the dependency
  for (ITER it=children.begin (); it!=children.end (); ++it)
  { 
    if ((*it).getReferencedObject () == Udm::null)
      continue;
    
    if (((*it).type () == PICML::Member::meta) && (Udm::IsDerivedFrom ((*it).getReferencedObject ().type (), PICML::PredefinedType::meta) == false))
    {
      for (Udm::Object parent = (*it).getReferencedObject (); parent.type () != PICML::File::meta; parent = parent.GetParent ())
      {
        // determine if parent is not in graph; add parent and parent child with edge
        if (parent.GetParent ().type () == PICML::File::meta && this->map_.find (parent.uniqueId ()) == this->map_.end ())
        {
          VERTEX parent_root = boost::add_vertex (this->graph_);
          VERTEX child_parent = boost::add_vertex (this->graph_);
          
          boost::put (information, parent_root, parent);
          boost::put (information, child_parent, (*it).GetParent ());
          
          boost::add_edge (parent_root, child_parent, this->graph_);
          
          this->map_.insert(MAP::value_type (parent.uniqueId (), parent.isSubtype ()));
          this->map_.insert(MAP::value_type ((*it).GetParent ().uniqueId (), (*it).GetParent ().isSubtype ()));
        } // determine if this parent is in graph but child isn't, add child's parent and an edge between parent (already in graph) and child's parent
        else if (parent.GetParent ().type () == PICML::File::meta && this->map_.find (parent.uniqueId ()) != this->map_.end ())
        {
          ACCESSOR accessor;
          
          VERTEX parent_root = find_vertex (parent);
          VERTEX child_parent = boost::add_vertex (this->graph_);
          
          boost::put (information, child_parent, (*it).GetParent ());
          boost::add_edge (parent_root, child_parent, this->graph_);
          
          this->map_.insert (std::pair<UDM_NAMESPACE::ObjectImpl::uniqueId_type, bool>((*it).GetParent ().uniqueId (), (*it).GetParent ().isSubtype ()));
        }
      }
    }
    else
    {
      this->add_node (o); // add this object to graph directly - no edge
    }
  }
}

//
// topological_sort
//
void IDL_File_Ordering_Processor::
topological_sort_i (void)
{
  if (container_.empty ())
    boost::topological_sort (this->graph_, std::back_inserter (this->container_));
}

//
// topological_sort
//
void IDL_File_Ordering_Processor::
topological_sort (CONTAINER & container)
{
  this->topological_sort_i ();
  container = this->container_;
}

//
// graph
//
const IDL_File_Ordering_Processor::GRAPH & IDL_File_Ordering_Processor::
graph (void) const
{
  return this->graph_; 
}

//
// clear
//
void IDL_File_Ordering_Processor::
clear (void)
{
  this->graph_.clear ();
  this->container_.clear ();
  this->map_.clear ();
}

//
// find_vertex
//
IDL_File_Ordering_Processor::VERTEX IDL_File_Ordering_Processor::
find_vertex (const Udm::Object & o)
{
  boost::graph_traits<IDL_File_Ordering_Processor::GRAPH>::vertex_iterator vi, vi_end;
  
  ACCESSOR accessor;
  Udm::Object v;
  
  for (boost::tie (vi, vi_end) = boost::vertices (this->graph_); vi != vi_end; ++vi)
  {
    v = boost::get(Udm_Object (), this->graph_, (*vi)); 
    
    if (v.uniqueId () == o.uniqueId ())
      break;
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
visit_all (const Udm::Object & o, PICML::Visitor & visitor)
{
  Udm::visit_all <PICML::Constant> (o, visitor);
  Udm::visit_all <PICML::Alias> (o, visitor);
  Udm::visit_all <PICML::Collection> (o, visitor);
  Udm::visit_all <PICML::Exception> (o, visitor);
  Udm::visit_all <PICML::Aggregate> (o, visitor);
  Udm::visit_all <PICML::SwitchedAggregate> (o, visitor);
  Udm::visit_all <PICML::ValueObject> (o, visitor);

  Udm::visit_all <PICML::TemplatePackageInstance> (o, visitor);

  Udm::visit_all <PICML::Event> (o, visitor);
  Udm::visit_all <PICML::Object> (o, visitor);
  Udm::visit_all <PICML::PortType> (o, visitor);
  Udm::visit_all <PICML::Component> (o, visitor);
  Udm::visit_all <PICML::ComponentFactory> (o, visitor);
  Udm::visit_all <PICML::ConnectorObject> (o, visitor);

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