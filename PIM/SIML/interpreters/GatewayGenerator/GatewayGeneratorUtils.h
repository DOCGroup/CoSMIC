#ifndef GATEWAYGENERATOR_UTILS_H
#define GATEWAYGENERATOR_UTILS_H

#include <GatewayGenerator/SIMLBonX.h>

namespace SIML
{

PortProxyImpl* get_pointer (const PortProxy& proxy);

}

namespace WSML
{

PortImpl* get_pointer (const Port& port);
ServiceRefImpl* get_pointer (const ServiceRef& serviceRef);
ServiceImpl* get_pointer (const Service& service);

}

#endif /* GATEWAYGENERATOR_UTILS_H */
