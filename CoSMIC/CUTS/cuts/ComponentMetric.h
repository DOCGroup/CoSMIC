#ifndef _CUTS_COMPONENT_METRIC_H_
#define _CUTS_COMPONENT_MERTIC_H_

#include "cuts/PortMetric.h"
#include <map>

class CUTS_Component_Metric
{
public:
  typedef std::map <std::string, CUTS_Port_Metric> Port_Metric_Map;

  CUTS_Component_Metric (void);

  virtual ~CUTS_Component_Metric (void);

private:
};

#endif  // !defined _CUTS_COMPONENT_MERTIC_H_
