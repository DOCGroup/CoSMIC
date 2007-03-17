// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Depend_Graph_T
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_DEPEND_GRAPH_T_H_
#define _CUTS_BE_DEPEND_GRAPH_T_H_

#include "cuts/config.h"
#include <map>

//=============================================================================
/**
 * @class CUTS_BE_Depend_T
 *
 * Helper class for managing dependency nodes. This is really used
 * to hold CUTS_BE_IDL_Node and CUTS_Impl_Node objects.
 */
//=============================================================================

template <typename T>
class CUTS_BE_Depend_Graph_T
{
public:
  /// Type definition of the node map.
  typedef std::map <std::string, T *> Node_Map;

  /// Default constructor.
  CUTS_BE_Depend_Graph_T (void);

  /// Destructor.
  ~CUTS_BE_Depend_Graph_T (void);

  /**
   * Locate the node with the specified name in the graph. If the
   * node is not in the path, one is created.
   *
   * @param[in]       name        Name of the node.
   * @param[out]      node        Pointer to the node.
   * @retval          1           The node already existed.
   * @retval          0           The node was newly created.
   * @retval          -1          Error.
   */
  int find (const std::string & name, T * &node);

  /**
   * Locate the node with the specified name in the graph. If the
   * node is not in the path, one is created.
   *
   * @param[in]       name        Name of the node.
   * @param[out]      node        Pointer to the node.
   * @retval          true        The node was found.
   * @retval          false       the node was not found
   */
  bool find (const std::string & name, const T * &node) const;

  /**
   * Remove a node from the graph.
   *
   * @param[in]       name        Name of the node.
   */
  void remove (const std::string & name);

  /**
   * Get a reference to the underlying graph.
   *
   * @return      Reference to the underlying graph.
   */
  Node_Map & graph (void);

  /**
   * Get a read-only reference to the underlying graph.
   *
   * @return      Reference to the underlying graph.
   */
  const Node_Map & graph (void) const;

private:
  /// Underlying graph that really is a map.
  Node_Map graph_;
};

#if defined (__CUTS_INLINE__)
#include "BE_Depend_Graph_T.inl"
#endif

#include "BE_Depend_Graph_T.cpp"

#endif  // !defined _CUTS_BE_DEPEND_GRAPH_T_H_
