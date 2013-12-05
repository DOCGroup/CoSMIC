// $Id$

#include "StdAfx.h"
#include "GatewayGenerator/GatewayGeneratorUtils.h"

namespace SIML
{

PortProxyImpl*
get_pointer (const PortProxy& proxy)
{
  return proxy.operator->();
}

}

namespace WSML
{

ServiceRefImpl*
get_pointer (const ServiceRef& serviceRef)
{
  return serviceRef.operator->();
}

ServiceImpl*
get_pointer (const Service& service)
{
  return service.operator->();
}

PortImpl*
get_pointer (const Port& port)
{
  return port.operator->();
}

}
