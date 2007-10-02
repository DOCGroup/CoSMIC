#include "DeploymentPlanner.h"
#include "NodeAssigner.h"

DeploymentPlanner::DeploymentPlanner(
	MGAComponentMap const & comp_map,
	MGANodeMap const & node_map)
: comp_map_ (comp_map),
  node_map_ (node_map)
{
}

DeploymentPlanner::~DeploymentPlanner(void)
{
}

void DeploymentPlanner::
get_placement (NodeToCompMapping & node2comp, CompToNodeMapping & comp2node)
{
	std::set <std::string> comp_set;
	for (MGAComponentMap::const_iterator i (comp_map_.begin());
		 i != comp_map_.end();
		 ++i)
	{
		comp_set.insert(i->first);
	}

	std::vector <std::string> node_vec;
	for (MGANodeMap::const_iterator i (node_map_.begin());
		 i != node_map_.end();
		 ++i)
	{
		node_vec.push_back(i->first);
	}

	NodeAssigner & na =  RandomNodeAssigner (node_vec, comp_set);
	CompToNodeMapping empty_mapping;
	na.compute_assignment (empty_mapping);
	node2comp = na.get_node2comp();
	comp2node = na.get_comp2node();
}