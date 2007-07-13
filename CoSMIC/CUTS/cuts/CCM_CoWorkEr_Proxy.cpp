// $Id$

#include "cuts/CCM_CoWorkEr_Proxy.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/CCM_CoWorkEr_Proxy.inl"
#endif

//#include "tao/RTCORBA/RT_ORB_Loader.h"
//#include "tao/RTCORBA/Priority_Mapping_Manager.h"
//#include "tao/RTCORBA/Linear_Priority_Mapping.h"
#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_time.h"
#include "ace/OS_NS_unistd.h"
#include "ace/INET_Addr.h"

//
// CUTS_CCM_CoWorkEr_Proxy
//
CUTS_CCM_CoWorkEr_Proxy::CUTS_CCM_CoWorkEr_Proxy (void)
: agent_ (0)
{
  // Create a new <Benchmark_Agent_i> object and activate it.
  ACE_NEW_THROW_EX (this->agent_, Benchmark_Agent_i (), CORBA::NO_MEMORY ());

  // Activate the <agent_> and transfer ownership.
  CUTS::Benchmark_Agent_var agent = this->agent_->_this ();
  this->servant_ = this->agent_;
}

//
// ~CUTS_CCM_CoWorkEr_Proxy
//
CUTS_CCM_CoWorkEr_Proxy::~CUTS_CCM_CoWorkEr_Proxy (void)
{
  //if (!::CORBA::is_nil (this->benchmark_poa_.in ()))
  //  this->benchmark_poa_->destroy (0, 0);
}

//
// init_realtime
//
void CUTS_CCM_CoWorkEr_Proxy::
init_realtime (CORBA::ORB_ptr orb, PortableServer::POA_ptr poa)
{
  //// Get the Real-time ORB.
  //ACE_DEBUG ((LM_DEBUG, "[%M] -%T - resolving RTORB initial reference\n"));
  //CORBA::Object_var obj = orb->resolve_initial_references ("RTORB");

  //ACE_DEBUG ((LM_DEBUG, "[%M] -%T - narrowing RTORB object\n"));
  //this->rt_orb_ = RTCORBA::RTORB::_narrow (obj.in ());

  ///// @note Right now we are using a linear priority mapping for
  ///// the RT ORB. Eventually we will want to convert to a custom
  ///// mapping that allows the BDC to only have the highest priority.
  ///// Also we would want to define a new scheduling policy such that
  ///// anytime that priority is invoked it will always get scheduled
  ///// next.
  //obj = orb->resolve_initial_references ("PriorityMappingManager");
  //RTCORBA::PriorityMappingManager_var mapping_manager =
  //  RTCORBA::PriorityMappingManager::_narrow (obj.in ());

  //RTCORBA::PriorityMapping * lmap = 0;
  //ACE_NEW_THROW_EX (lmap,
  //                  TAO_Linear_Priority_Mapping (ACE_SCHED_RR),
  //                  CORBA::NO_MEMORY ());

  //mapping_manager->mapping (lmap);

  //// Set the policies for the SERVER_DECLARED POA that executes at
  //// the highest priority.
  //CORBA::PolicyList policies (1);
  //policies.length (1);

  //policies[0] =
  //  this->rt_orb_->create_priority_model_policy (RTCORBA::SERVER_DECLARED,
  //                                               RTCORBA::maxPriority);

  //// Get the <RTPortableServer>.
  //PortableServer::POA_var child_poa =
  //  poa->create_POA ("CUTS_Benchmark_POA",
  //                   PortableServer::POAManager::_nil (),
  //                   policies);

  //this->benchmark_poa_ = RTPortableServer::POA::_narrow (child_poa.in ());

  //// Activate the <Benchmark_Agent> under the <Benchmark_POA>.
  //this->benchmark_poa_->activate_object (this->agent_);
}

//
// register_i
//
long CUTS_CCM_CoWorkEr_Proxy::
register_i (CUTS::Testing_Service_ptr ts, CUTS::Component_Registration & reg)
{
  int regid = CUTS_UNKNOWN_IMPL;

  // Get the hostname and ip-address for this component.
  char hostname[1024];
  ACE_OS::hostname (hostname, sizeof (hostname));
  ACE_INET_Addr inet ((u_short)0, hostname, AF_ANY);

  reg.host_info.ipaddr   = ::CORBA::string_dup (inet.get_host_addr ());
  reg.host_info.hostname = ::CORBA::string_dup (inet.get_host_name ());

  try
  {
    ACE_DEBUG ((LM_INFO,
                "*** info (CoWorkEr): registering %s with the BDC\n",
                reg.name.in ()));

    regid = ts->register_component (reg);
  }
  catch (const CUTS::Registration_Failed &)
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - component registration failed for %s\n",
                reg.name.in ()));
  }
  catch (const CUTS::Registration_Limit &)
  {
    ACE_ERROR ((LM_ERROR,
                "[%M] -%T - component registation limit reached; failed to "
                "register %s\n",
                reg.name.in ()));
  }

  return regid;
}
