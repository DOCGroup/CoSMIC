#ifndef _CUTS_CCM_COWORKER_H_
#define _CUTS_CCM_COWORKER_H_

#include "cuts/config.h"
#include "cuts/CUTS_exec_export.h"
#include "cuts/CUTSC.h"
#include <string>

class CUTS_EXEC_Export CUTS_CCM_CoWorkEr
{
public:
  /// Constructor.
  CUTS_CCM_CoWorkEr (void);

  /// Destructor.
  virtual ~CUTS_CCM_CoWorkEr (void);

  /// Get the name of the server used by this CoWorkEr component.
  virtual char * server_name (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

  /// Change the name of the server used by this CoWorkEr component.
  virtual void server_name (const char * name ACE_ENV_ARG_DECL_WITH_DEFAULTS)
    ACE_THROW_SPEC ((CORBA::SystemException));

protected:
  /// Generate random data for an event.
  void generate_event_data (
    ::CUTS::Data_Event * event, size_t lower, size_t upper);

private:
  /// Name of the server used by this CoWorkEr's database.
  std::string server_name_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/CCM_CoWorkEr.inl"
#endif

#endif  // !defined _CUTS_CCM_COWORKER_H_
