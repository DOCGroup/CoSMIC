//=============================================================================
/**
 *  @file       IDL_Detect_Cycles.h
 *
 *  File contains the class IDL_Cycle_Detector.
 *
 *  $Id:$
 *
 *  @author     Harold Owens II <owensh@cs.iupui.edu>
 */
//=============================================================================

#ifndef IDLDETECTCYCLE_H
#define IDLDETECTCYCLE_H

#include <boost/graph/depth_first_search.hpp>
#include <boost/shared_ptr.hpp>

#include "IDL_File_Ordering_Processor.h"

/**
 * @class IDL_Cycle_Detector
 *
 * @brief Implementation of the IDL_Cycle_Detector that is responsible for 
 * detecting cycles within a Graph G.
 */
struct IDL_Cycle_Detector : public boost::dfs_visitor <>
{
  /// Constructor
  IDL_Cycle_Detector (bool& has_cycle, 
                      IDL_File_Ordering_Processor::VERTEX_GRAPH & container,
                      IDL_File_Ordering_Processor::EDGE_CONTAINER & edge);
  /// Destructor
  ~IDL_Cycle_Detector ();
  /**
  * Event which is generator when a node in the graph has already been visited
  * but there is another path to this node (cycle in the graph).
  *
  * @param[out]      E      Edge that caused the cycle in the graph
  * @param[out]      G      Graph containing the cycle
  */
  template <class Edge, class Graph>
  void back_edge (Edge E, Graph& G);
  /**
  * Sets the current graph that is being visited.
  *
  * @param[in]      g      Current graph being visited by visitor.
  */
  void current_graph (IDL_File_Ordering_Processor::GRAPH_PTR g);

protected:
  bool & has_cycle_;///< are there any cycles in graph?
  IDL_File_Ordering_Processor::VERTEX_GRAPH &     container_;///< holds the forward declarable vertices
  IDL_File_Ordering_Processor::EDGE_CONTAINER &   edge_;///< holds the back edges from the graph
  IDL_File_Ordering_Processor::GRAPH_PTR          current_graph_;///< current graph being visited
};

#include "IDL_Cycle_Detector.inl"

#endif // IDLDETECTCYCLE_H