// $Id$

#include "stdafx.h"
#include "IDL_Cycle_Detector.h"

//
// IDL_Cycle_Detector
//
IDL_Cycle_Detector::IDL_Cycle_Detector (bool& has_cycle, 
                                        IDL_File_Ordering_Processor::VERTEX_GRAPH & container,
                                        IDL_File_Ordering_Processor::EDGE_CONTAINER & edge) 
: has_cycle_ (has_cycle),
  container_ (container),
  edge_ (edge)
{
}

//
// ~IDL_Cycle_Detector
//
IDL_Cycle_Detector::~IDL_Cycle_Detector () 
{
}

//
// current_graph
//
void IDL_Cycle_Detector::
current_graph (IDL_File_Ordering_Processor::GRAPH_PTR graph)
{
  this->current_graph_ = graph;
}
