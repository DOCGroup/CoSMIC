#ifndef _CUTS_COMPONENT_REGISTRY_NODE_H_
#define _CUTS_COMPONENT_REGISTRY_NODE_H_

#include "cuts/Component_Info.h"

//=============================================================================
/**
 * @class CUTS_Component_Registry_Node
 */
//=============================================================================

class CUTS_Export CUTS_Component_Registry_Node
{
public:
  CUTS_Component_Registry_Node (void);

  virtual ~CUTS_Component_Registry_Node (void);

  CUTS_Component_Info & info (void);

  const CUTS_Component_Info & info (void) const;

private:
  /// Information about the component.
  CUTS_Component_Info info_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Component_Registry_Node.inl"
#endif

#endif  // !defined _CUTS_COMPONENT_REGISTRY_NODE_H_
