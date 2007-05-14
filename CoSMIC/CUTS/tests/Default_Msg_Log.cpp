// $Id$

#include "Default_Msg_Log.h"

//
// CUTS_Default_Msg_Log_Strategy
//
CUTS_Default_Msg_Log_Strategy::
CUTS_Default_Msg_Log_Strategy (void)
{

}

//
// ~CUTS_Default_Msg_Log_Strategy
//
CUTS_Default_Msg_Log_Strategy::
~CUTS_Default_Msg_Log_Strategy (void)
{

}

//
// open
//
bool CUTS_Default_Msg_Log_Strategy::open (const ACE_CString & name)
{
  return true;
}

//
// close
//
void CUTS_Default_Msg_Log_Strategy::close (size_t passed, size_t failed)
{
  std::cout
    << "*** results: "
    << passed << " passed and " << failed << " failed" << std::endl;
}

//
// info_message
//
void CUTS_Default_Msg_Log_Strategy::info_message (const ACE_CString & msg)
{
  std::cout << "*** info: " << msg;
}

//
// error_message
//
void CUTS_Default_Msg_Log_Strategy::error_message (const ACE_CString & msg)
{
  std::cerr << "*** error: " << msg;
}

//
// warning_message
//
void CUTS_Default_Msg_Log_Strategy::warning_message (const ACE_CString & msg)
{
  std::cout << "*** warning: " << msg;
}
