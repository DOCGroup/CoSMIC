// $Id$

#include "StdAfx.h"
#include <algorithm>

#include "boost/graph/topological_sort.hpp"
#include "ACircle.h"
#include "ACircle_Tag_Dispatch.h"

//
// ACircle
//
template <typename T>
ACircle <T>::ACircle (void)
{
}

//
// ~ACircle
//
template <typename T>
ACircle <T>::~ACircle (void)
{
}

//
// build_graph
//
template <typename T>
void ACircle <T>::
build_graph (const T & root, VISITOR_TYPE & visitor)
{
  this->visit_all (root, visitor);
}

//
// visit_all
//
template <typename T>
void ACircle <T>::
visit_all (const T & o, VISITOR_TYPE & visitor)
{
  ACircle_Tag_Dispatch::visit_all <TRAIT> (o, visitor);
}

//
// add_edge_mng
//
template <typename T>
template <typename CF, typename M, typename MC>
void ACircle <T>::
add_edge_mng (const T & o)
{
  if (ACircle_Tag_Dispatch::type <TRAIT, BASE_META> (o) == ACircle_Tag_Dispatch::meta <TRAIT, T, MC, BASE_META> ())
  {
    CF c = ACircle_Tag_Dispatch::srcManagesComponent_end <TRAIT, T, MC, CF> (o);
    M m = ACircle_Tag_Dispatch::dstManagesComponent_end <TRAIT, T, MC, M> (o);
    
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

//
// add_node
//
template <typename T>
void ACircle <T>::
add_node (const T & o)
{
  OBJECT_ACCESSOR information = boost::get (Base_Object (), *this->current_graph_);
  
  if (ACircle_Tag_Dispatch::type <TRAIT, BASE_META> (ACircle_Tag_Dispatch::get_parent <TRAIT> (o)) ==
      ACircle_Tag_Dispatch::meta <TRAIT, T, ROOT_TYPE, BASE_META> () 
      && this->map_.find (o) == this->map_.end ())
  {
    this->add_vertex (o, this->current_graph_);
  }
  else
  {
    for (T parent = ACircle_Tag_Dispatch::get_parent <TRAIT> (o); 
         ACircle_Tag_Dispatch::type <TRAIT, BASE_META> (parent) !=  ACircle_Tag_Dispatch::meta <TRAIT, T, ROOT_TYPE, BASE_META> ();
         parent = ACircle_Tag_Dispatch::get_parent <TRAIT> (parent))
    {
      if (ACircle_Tag_Dispatch::type <TRAIT, BASE_META> (ACircle_Tag_Dispatch::get_parent <TRAIT> (parent)) 
          ==  ACircle_Tag_Dispatch::meta <TRAIT, T, ROOT_TYPE, BASE_META> () 
          && this->map_.find (parent) == this->map_.end ())
      {
        this->add_vertex (parent, this->current_graph_);
      }
    }
  }
}

//
// add_edge
//
template <typename T>
template <typename S, typename P>
void ACircle <T>::
add_edge (const T & o)
{
  typedef vector <S> VECTOR;
  typedef vector <S>::const_iterator ITER;
  
  VECTOR children = ACircle_Tag_Dispatch::get_children <TRAIT, T, S> (o);
  
  for (ITER it=children.begin (); it!=children.end (); ++it)
  { 
    if (ACircle_Tag_Dispatch::is_null <TRAIT> (ACircle_Tag_Dispatch::get_referenced_object <TRAIT, BASE_TYPE> (*it)))
      continue;
    
    if ((ACircle_Tag_Dispatch::type <TRAIT, BASE_META> (*it) == ACircle_Tag_Dispatch::meta <TRAIT, T, P, BASE_META> ()) 
        && ACircle_Tag_Dispatch::is_not_prefined_type <TRAIT> (*it))
    {
      BASE_TYPE reference_parent = ACircle_Tag_Dispatch::get_referenced_object <TRAIT, BASE_TYPE> (*it);
      BASE_TYPE parent = this->find_parent<P> ((*it));
      
      if (this->same_parent_before_file <ROOT_TYPE> (parent, reference_parent) == false)
      {
        reference_parent = this->parent_before_file <ROOT_TYPE> (ACircle_Tag_Dispatch::get_referenced_object <TRAIT, BASE_TYPE> (*it));
      }
      
      if (this->parent_in_same_file <ROOT_TYPE> (parent, reference_parent) == false)
      {
        if (this->map_.find (parent) == this->map_.end ())
          this->add_vertex (parent, this->current_graph_);
        continue;
      }
      
      if (this->map_.find (reference_parent) == this->map_.end () && this->map_.find (parent) == this->map_.end ())
      {
        this->add_vertices (reference_parent, parent, this->current_graph_);
      }
      else
      {
        bool found_parent = false;
        bool found_ref_parent = false;
        
        VERTEX reference = this->find_vertex (reference_parent, this->current_graph_, found_ref_parent);
        VERTEX direct = this->find_vertex (parent, this->current_graph_, found_parent);
        
        if (found_parent == true && found_ref_parent == true)
        {
          EDGE e; 
          bool added = false;
          
          boost::tie(e,added) = boost::add_edge (reference, direct, *this->current_graph_);
        }
        else if (found_parent == false && found_ref_parent == false)
        {
          this->add_vertices (reference_parent, parent, this->current_graph_);
        }
        else if (found_parent == false && found_ref_parent == true)
        {
          this->add_vertex (parent, this->current_graph_);
          
          VERTEX direct = this->find_vertex (parent, this->current_graph_, found_parent);
          
          EDGE e; 
          bool added = false; 
          
          boost::tie(e,added) = boost::add_edge (reference, direct, *this->current_graph_);
        }
        else
        {
          this->add_vertex (reference_parent, this->current_graph_);
          
          VERTEX reference = this->find_vertex (reference_parent, this->current_graph_, found_ref_parent);
          
          EDGE e; 
          bool added = false; 
          
          boost::tie(e,added) = boost::add_edge (reference, direct, *this->current_graph_);
        }
      }
    }
  }
}

//
// add_vertex
//
template <typename T>
void ACircle <T>::
add_vertex (const T & o, 
            GRAPH_PTR graph)
{
  OBJECT_ACCESSOR information = boost::get (Base_Object (), *graph);
  
  VERTEX vertex = boost::add_vertex (*graph);

  boost::put (information, vertex, o);

  this->map_.insert (MAP::value_type(o, o.isSubtype ()));
}

//
// add_vertices
//
template <typename T>
void ACircle <T>::
add_vertices (const T & parent_ref1,
              const T & parent_ref2, 
              GRAPH_PTR graph)
{
  OBJECT_ACCESSOR information = boost::get (Base_Object (), *graph);
  
  // add the parents to the graph
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
template <typename T>
void ACircle <T>::
topological_sort (CONTAINER & container)
{
  this->topological_sort_i (container);
}

//
// topological_sort_i
//
template <typename T>
void ACircle <T>::
topological_sort_i (CONTAINER & container)
{
  this->find_cycles (); // remove any cycles from the graph
  this->insert (container);
}

//
// graph
//
template <typename T>
const typename ACircle<T>::GRAPH & ACircle <T>::
graph (void)
{
  return *this->current_graph_; 
}

//
// clear
//
template <typename T>
void ACircle <T>::
clear (bool clear_target_circle)
{
  if (clear_target_circle)
  {
    this->target_.clear ();
    this->cycle_.clear ();
  }
  
  this->edge_.clear ();
  this->map_.clear ();
  this->list_.clear (); 
}

//
// find_vertex
//
template <typename T>
typename ACircle<T>::VERTEX ACircle <T>::
find_vertex (const T & o, GRAPH_PTR graph, bool & found)
{
  boost::graph_traits<GRAPH>::vertex_iterator vi, vi_end;
  
  BASE_TYPE v;
  
  for (boost::tie (vi, vi_end) = boost::vertices (*graph); vi != vi_end; ++vi)
  {
    v = boost::get (Base_Object (), *graph, (*vi)); 
    
    if (ACircle_Tag_Dispatch::uniqueId <TRAIT> (v) == ACircle_Tag_Dispatch::uniqueId <TRAIT> (o))
    {
      found = true;
      break;
    }
  }
  
  return *vi;
}

//
// find_cycles
//
template <typename T>
bool ACircle <T>::
find_cycles (void)
{
  bool has_cycle = false;

  for (ACircle <T>::LIST::iterator it = this->list_.begin (); it != this->list_.end (); ++it)
  {
    std::pair<ACircle <T>::EDGE_ITER, ACircle <T>::EDGE_ITER> e = boost::edges (*(*it).second);

    for (; e.first != e.second; e.first++)
    {
      ACircle <T>::VERTEX source = boost::source (*(e.first), *(*it).second);
      ACircle <T>::VERTEX target = boost::target (*(e.first), *(*it).second);

      std::pair<ACircle <T>::EDGE, bool> edge_d = boost::add_edge (target, source, *(*it).second);

      if (edge_d.second == false)
      {
        // already in graph there is a cycle
        boost::remove_edge (target, source, *(*it).second);
        this->cycle_.push_back (ACircle <T>::VERTEX_GRAPH::value_type (source, (*it).second));
        has_cycle = true;
      }
      else
      {
        boost::remove_edge (edge_d.first,*(*it).second);
      }
    }
  } 
  
  this->cycle_i ();

  return has_cycle;
}

//
// cycle_i
//
template <typename T>
void ACircle <T>::
cycle_i (void)
{
  for (ACircle <T>::VERTEX_GRAPH_IT it = this->cycle_.begin (); it != this->cycle_.end (); ++it)
  {
    this->insert_target ((*it).first, (*it).second);
  }
}

//
// insert_target
//
template <typename T>
void ACircle <T>::
insert_target (VERTEX & v, GRAPH_PTR g)
{
  BASE_TYPE o;

  o = boost::get (Base_Object (), *g, v);
  
  if (ACircle_Tag_Dispatch::is_null <TRAIT> (o))
    this->target_.insert (MAP::value_type (o, ACircle_Tag_Dispatch::is_subtype <TRAIT> (o) ));
}

//
// remove_edge
//
template <typename T>
void ACircle <T>::
remove_edge (GRAPH_PTR graph)
{
  for (ACircle <T>::EDGE_IT it = this->edge_.begin (); it != this->edge_.end (); ++it)
  {
    boost::remove_edge ((*it), *graph);
  }
}

//
// insert
//
template <typename T>
void ACircle <T>::
insert (const T & o, bool find_circle)
{
  if (ACircle_Tag_Dispatch::type <TRAIT, BASE_META> (o) == 
      ACircle_Tag_Dispatch::meta <TRAIT, T, ROOT_TYPE, BASE_META> ())
  {
    this->current_graph_ = GRAPH_PTR (new GRAPH);
    this->list_.push_back (LIST::value_type (o, this->current_graph_));
  }
  else if (find_circle && ACircle_Tag_Dispatch::get_parent <TRAIT>(o) == 
           ACircle_Tag_Dispatch::meta <TRAIT, T, ROOT_TYPE, BASE_META> ())
  {
    this->current_graph_ = GRAPH_PTR (new GRAPH);
    this->list_.push_back (LIST::value_type (o, this->current_graph_));
    
    OBJECT_ACCESSOR information = boost::get (Base_Object (), *this->current_graph_);
    
    VERTEX parent = boost::add_vertex (*this->current_graph_);
    
    boost::put (information, parent, o);
  }
}

//
// no_cycle_detected
//
template <typename T>
bool ACircle <T>::
no_cycle_detected (const T & o)
{
  MAP::iterator it = this->target_.find (o);
  
  return (it == this->target_.end ());
}

//
// insert
//
template <typename T>
void ACircle <T>::
insert (CONTAINER & c)
{
  for (ACircle <T>::LIST::iterator it = this->list_.begin (); it != this->list_.end (); ++it)
  {
    boost::topological_sort (*(*it).second, std::back_inserter (c));
  }
}

//
// find_parent
//
template <typename T>
template <typename U>
T ACircle <T>::
find_parent (const T & o)
{
  BASE_TYPE parent;

  parent =  ACircle_Tag_Dispatch::get_parent <TRAIT> (o);
  
  while (ACircle_Tag_Dispatch::type <TRAIT, BASE_META> (parent) != ACircle_Tag_Dispatch::meta <TRAIT, T, U, BASE_TYPE> ())
  {
    parent = ACircle_Tag_Dispatch::get_parent <TRAIT> (parent);
  }
  
  return parent;
}

//
// same_parent_before_file
//
template <typename T>
template <typename U>
bool ACircle <T>::
same_parent_before_file (const T & o, const T & p)
{
  return ACircle_Tag_Dispatch::uniqueId <TRAIT> (this->parent_before_file <U> (o)) == 
         ACircle_Tag_Dispatch::uniqueId <TRAIT> (this->parent_before_file <U> (p));
}

//
// parent_in_same_file
//
template <typename T>
template <typename U>
bool ACircle <T>::
parent_in_same_file (const T & o, const T & p)
{
  return ACircle_Tag_Dispatch::uniqueId <TRAIT> (this->find_parent <U> (o)) == 
         ACircle_Tag_Dispatch::uniqueId <TRAIT> (this->find_parent <U> (p));
}

//
// parent_before_file
//
template <typename T>
template <typename U>
T ACircle <T>::
parent_before_file (const T & o)
{
  BASE_TYPE parent;

  parent =  ACircle_Tag_Dispatch::get_parent <TRAIT> (o);
  
  while (ACircle_Tag_Dispatch::type <TRAIT, BASE_META> (parent) != 
         ACircle_Tag_Dispatch::meta <TRAIT, T, U, BASE_META> ())
  {
    if (ACircle_Tag_Dispatch::type <TRAIT, BASE_META> (ACircle_Tag_Dispatch::get_parent <TRAIT> (parent)) == 
        ACircle_Tag_Dispatch::meta <TRAIT, T, U, BASE_META> ())
      break;

    parent = ACircle_Tag_Dispatch::get_parent <TRAIT> (parent);
  }
  
  return parent;
}