//$Id$
#include "RTConfiguration/RTInjector.h"

namespace CQML
{

	RTInjector::RTInjector (RTConfigurationVisitor *rt_config)
		: rt_config_visitor_ (rt_config)
	{}

	RTInjector::~RTInjector ()
	{	

	}

	std::string RTInjector::get_deployed_resource (const CQML::Component& comp)
	{
		// return the deployed resource reference.
		return this->rt_config_visitor_->get_deployed_resource (comp);
	}

} // namespace CQML

