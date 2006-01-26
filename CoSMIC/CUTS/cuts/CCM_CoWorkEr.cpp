// $Id$

#include "cuts/CCM_CoWorkEr.h"
#include "cuts/CCM_BenchmarkAgent.h"
#include "ace/OS_NS_stdlib.h"
#include "ace/OS_NS_time.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/CCM_CoWorkEr.inl"
#endif

CUTS_CCM_CoWorkEr::CUTS_CCM_CoWorkEr (void)
{
  ACE_OS::srand (ACE_OS::time (0));
}

CUTS_CCM_CoWorkEr::~CUTS_CCM_CoWorkEr (void)
{

}

//
// server_name
//
char * CUTS_CCM_CoWorkEr::server_name (ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
ACE_THROW_SPEC ((CORBA::SystemException))
{
  // Create a duplicate copy of the string and it to the client.
  ::CORBA::String_var str =
    CORBA::string_dup (this->server_name_.c_str ());

  return str._retn ();
}

//
// generate_event_data
//
void CUTS_CCM_CoWorkEr::generate_event_data (::CUTS::Data_Event * event,
                                             size_t minsize,
                                             size_t maxsize)
{
  // Calculate the size of the data.
  int size = minsize + (ACE_OS::rand () % (maxsize - minsize));

  // Allocate a buffer of that size and fill it with garbage.
  char value = 'A';
  char * buffer = CORBA::string_alloc (size);
  std::fill (buffer, buffer + size - 1, value);
  buffer[size - 1] = '\0';

  // Initialize the buffer with garbage data.
  event->data (buffer);
}
