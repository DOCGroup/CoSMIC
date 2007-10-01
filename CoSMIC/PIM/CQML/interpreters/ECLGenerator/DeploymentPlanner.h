#pragma once

#include "KindAggregator.h"

class DeploymentPlanner
{
public:
	DeploymentPlanner(CQML::KindAggregator<CQML::AbstractComponent>::KindMap const & comp_map,
		              CQML::KindAggregator<CQML::AbstractNode>::KindMap const & node_map);
	~DeploymentPlanner(void);

private:
	CQML::KindAggregator<CQML::AbstractComponent>::KindMap comp_map_;
	CQML::KindAggregator<CQML::AbstractNode>::KindMap node_map_;
};
