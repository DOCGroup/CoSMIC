#ifndef _PICML_DEPLOYMENT_HANDLER_H_
#define _PICML_DEPLOYMENT_HANDLER_H_

#include "PICML/PICML.h"

namespace PICML
{
/**
 * @class Deployment_Handler
 *
 * Interface for deploying different instances.
 */
class Deployment_Handler
{
public:
  /**
   * Add a connector fragment to the deployment.
   */
  virtual void deploy_connector_fragment (ConnectorInstance_in connector, 
                                          ComponentInstance_in component) = 0;
};

}

#endif  // !defined _PICML_DEPLOYMENT_HANDLER_H_
