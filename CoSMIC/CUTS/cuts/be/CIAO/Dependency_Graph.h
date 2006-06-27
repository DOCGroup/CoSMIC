// -*- C++ -*-

//=============================================================================
/**
 * @class     Dependency_Graph.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_DEPENDENCY_GRAPH_H_
#define _CUTS_DEPENDECNY_GRAPH_H_

#include "UDM_CIAO_Export.h"
#include <map>
#include <set>
#include <string>

// Forward decl.
class CUTS_Dependency_Node;

// Type definition
typedef std::set <CUTS_Dependency_Node *> CUTS_Reference_Set;

typedef std::set <std::string> String_Set;

//=============================================================================
/**
 * @struct CUTS_Dependency_Node
 */
//=============================================================================

class CUTS_Dependency_Node
{
public:
  enum Node_Flags
  {
    /// None of the flags are set
    DNF_NONE        = 0x0000,

    /// The node has output events (value 1).
    DNF_OUTEVENTS   = 0x0001,

    /// The node has input events (value 2).
    DNF_INEVENTS    = 0x0002,

    /// The node has periodic actions (value 4).
    DNF_PERIODIC    = 0x0004,

    /// The stub project is necessary (value 8).
    DNF_STUB        = 0x0008,

    /// The svnt project is necessary (value 16).
    DNF_SVNT        = 0x0010,

    /// The exec project is necessary (value 32).
    DNF_EXEC        = 0x0020,

    /// The node is used be a CoWorkEr.
    DNF_COWORKER    = 0x0040
  };

  /// Default constructor.
  CUTS_Dependency_Node (const std::string & name);

  /// Default destructor.
  ~CUTS_Dependency_Node (void);

  /// Library paths containing the libraries.
  String_Set libpaths_;

  /// Include paths containing the include files.
  String_Set includes_;

  /// Header files required for file/project to build.
  String_Set header_files_;

  /// Library files required for file/project to build.
  String_Set libs_;

  /**
   * Get the name of the node.
   *
   * @return      Name of the node.
   */
  const std::string & name (void) const;

  /**
   * Get the basename of the node.
   *
   * @return      Basename of the node.
   */
  const char * basename (void) const;

  /// Node flags.
  long flags_;

  /// Reference set for the node.
  CUTS_Reference_Set references_;

private:
  // Name of the node.
  std::string name_;

  /// Pointer to the basename of the <name_>.
  size_t basename_;
};

//=============================================================================
/**
 * @class CUTS_Dependency_Graph
 */
//=============================================================================

class CUTS_UDM_CIAO_Export CUTS_Dependency_Graph
{
public:
  /// Type definition for the dependency graph.
  typedef std::map <
    std::string,
    CUTS_Dependency_Node *> Dependency_Graph;

  /// Constructor.
  CUTS_Dependency_Graph (void);

  /// Destructor.
  ~CUTS_Dependency_Graph (void);

  /**
   * Create a new node in the dependency graph.
   */
  CUTS_Dependency_Node * create_node (const std::string & name);

  /**
   * Find a node in the graph.
   *
   * @param[in]     name          Name of the node to find.
   * @param[out]    node          Pointer to the node if found.
   * @param[in]     auto_create   Create the node if not found.
   * @retval        true          The node was found/created.
   * @retval        false         The node was not found.
   */
  bool find_node (const std::string & name,
                  CUTS_Dependency_Node * &node,
                  bool auto_create);

  /**
   * Find a node in the graph.
   *
   * @param[in]     name          Name of the node to find.
   * @param[out]    node          Pointer to the node if found.
   * @param[in]     auto_create   Create the node if not found.
   * @retval        true          The node was found/created.
   * @retval        false         The node was not found.
   */
  bool find_node (const std::string & name,
                  const CUTS_Dependency_Node * &node) const;

  /**
   * Remove a node from the graph.
   *
   * @param[in]     name      Name of the node to remove.
   */
  void remove_node (const std::string & name);

  /**
   * Get the contained dependency graph.
   *
   * @return      Read-only reference to internal graph.
   */
  const Dependency_Graph & graph (void) const;

private:
  /// Type definition for the dependency graph.
  typedef std::map <
    std::string,
    CUTS_Dependency_Node *> Dependency_Graph;

  /// The dependency graph.
  Dependency_Graph graph_;
};

#endif  // !defined _CUTS_DEPENDENCY_GRAPH_H_
