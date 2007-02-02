// -*- C++ -*-

//=============================================================================
/**
 * @file      CCM_Component_Registry.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CCM_COMPONENT_REGISTRY_H_
#define _CUTS_CCM_COMPONENT_REGISTRY_H_

#include "cuts/CUTSC.h"
#include "cuts/Component_Registry_Node.h"

namespace CUTS
{
  //===========================================================================
  /**
   * @class CCM_Component_Registry_Node
   *
   * CCM implementation of the component registry node. This version
   * allows storage of the Benchmark_Agent object with the registration
   * information of a component.
   */
  //===========================================================================

  class CCM_Component_Registry_Node :
    public CUTS_Component_Registry_Node
  {
  public:
    /**
     * Initializing constructor.
     *
     * @param[in]       agent       The benchmark agent.
     */
    CCM_Component_Registry_Node (::CUTS::Benchmark_Agent_ptr agent);

    /// Destructor.
    virtual ~CCM_Component_Registry_Node (void);

    /**
     * Get the benchmark agent. This return value must be stored
     * in a _var type. This will ensure proper memory management.
     *
     * @return          The registered benchmark agent.
     */
    ::CUTS::Benchmark_Agent_ptr benchmark_agent (void);

  private:
    /// The benchmark agent for the component.
    ::CUTS::Benchmark_Agent_var agent_;
  };
}

#endif  // !defined _CUTS_CCM_COMPONENT_REGISTRY_H_
