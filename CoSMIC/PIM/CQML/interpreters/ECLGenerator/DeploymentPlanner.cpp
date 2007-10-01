#include "DeploymentPlanner.h"

DeploymentPlanner::DeploymentPlanner(
	CQML::KindAggregator<CQML::AbstractComponent>::KindMap const & comp_map,
	CQML::KindAggregator<CQML::AbstractNode>::KindMap const & node_map)
: comp_map_ (comp_map),
  node_map_ (node_map)
{
}

DeploymentPlanner::~DeploymentPlanner(void)
{
}
