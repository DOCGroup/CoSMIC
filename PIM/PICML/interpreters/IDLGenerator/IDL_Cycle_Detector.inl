// $Id$

#include "IDL_File_Dependency_Processor.h"
#include "IDL_File_Ordering_Processor.h"

//
// back_edge
//
template <class Edge, class Graph>
void IDL_Cycle_Detector::
back_edge (Edge E, Graph& G) 
{
  IDL_File_Ordering_Processor::VERTEX v (boost::target (E, G));
  
  this->container_.push_back (IDL_File_Ordering_Processor::VERTEX_GRAPH::value_type (v, this->current_graph_));
  
  this->edge_.push_back (E);
  this->has_cycle_ = true;
}
