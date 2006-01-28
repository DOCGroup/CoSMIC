#ifndef _CUTS_CCM_COWORKER_H_
#define _CUTS_CCM_COWORKER_H_

#include "cuts/config.h"
#include "cuts/CUTS_exec_export.h"
#include "cuts/CUTSC.h"
#include "cuts/CCM_BenchmarkAgent.h"
#include "ComponentsC.h"
#include <string>

class CUTS_EXEC_Export CUTS_CCM_CoWorkEr
{
public:
  /// Constructor.
  CUTS_CCM_CoWorkEr (void);

  /// Destructor.
  virtual ~CUTS_CCM_CoWorkEr (void);

  ::CUTS::CCM_Benchmark_Agent_ptr get_cuts_benchmark_agent (
    ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Get the unique ID of the CoWorkEr.
  ::CORBA::Long cuts_coworker_id (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Set the unique ID of the CoWorkEr.
  void cuts_coworker_id (::CORBA::Long unique_id ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Get the name of the server used by this CoWorkEr component.
  char * cuts_coworker_database (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Change the name of the server used by this CoWorkEr component.
  void cuts_coworker_database (const char * name ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

protected:
  /// Generate random data for an event.
  void generate_event_data (
    ::CUTS::Data_Event * event, size_t lower, size_t upper);

  /// The benchmark agent for the CoWorkEr.
  ACE_Auto_Ptr <CUTS_CCM_Benchmark_Agent> benchmark_agent_;

private:
  /// Name of the server used by this CoWorkEr's database.
  std::string server_name_;

};

#if defined (__CUTS_INLINE__)
#include "cuts/CCM_CoWorkEr.inl"
#endif

#endif  // !defined _CUTS_CCM_COWORKER_H_
