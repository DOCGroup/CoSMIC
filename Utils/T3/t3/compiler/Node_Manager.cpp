// $Id$

#include "Node_Manager.h"
#include "Rule_Node.h"

//
// ~T3_Node_Manager
//
T3_Node_Manager::~T3_Node_Manager (void)
{
  for (node_set_type::ITERATOR iter (this->nodes_); !iter.done (); ++ iter)
    delete (*iter);
}

//
// release_node
//
int T3_Node_Manager::release_node (T3_Node * node)
{
  if (0 != this->nodes_.remove (node))
    return -1;

  delete node;
  return 0;
}

//
// find_rule
//
int T3_Node_Manager::
lookup_rule (const ACE_CString & name, T3_Rule_Node * &node)
{
  // Locate the rule in the map.
  if (0 == this->rule_map_.find (name, node))
    return 0;

  // Allocate a new T3_Rule_Node.
  T3_Rule_Node * temp_node = 0;
  ACE_NEW_RETURN (temp_node, T3_Rule_Node (name), -1);
  ACE_Auto_Ptr <T3_Rule_Node> auto_clean (temp_node);

  // Save the node.
  if (0 == this->nodes_.insert (temp_node) &&
      0 == this->rule_map_.bind (name, temp_node))
  {
    node = auto_clean.release ();
    return 0;
  }

  return -1;
}
