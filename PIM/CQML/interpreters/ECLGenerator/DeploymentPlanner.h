#pragma once

#include "KindAggregator.h"
#include "PlacementMaps.h"

typedef CQML::KindAggregator<CQML::AbstractComponent>::KindMap MGAComponentMap;
typedef CQML::KindAggregator<CQML::AbstractNode>::KindMap MGANodeMap;

class DeploymentPlanner
{
public:
	

	DeploymentPlanner(MGAComponentMap const & comp_map,
		              MGANodeMap const & node_map);
	~DeploymentPlanner(void);
	void get_placement (NodeToCompMapping &, CompToNodeMapping &);

private:
	MGAComponentMap comp_map_;
	MGANodeMap node_map_;
};
