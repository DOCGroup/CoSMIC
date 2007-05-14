// -*- C++ -*-

//=============================================================================
/**
 * @file      Default_Msg_Log.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_TESTS_DEFAULT_MSG_LOG_H_
#define _CUTS_TESTS_DEFAULT_MSG_LOG_H_

#include "Msg_Log.h"

//=============================================================================
/**
 * @class CUTS_Default_Msg_Log_Strategy
 */
//=============================================================================

class CUTS_TEST_Export CUTS_Default_Msg_Log_Strategy :
  public CUTS_Msg_Log_Strategy
{
public:
  CUTS_Default_Msg_Log_Strategy (void);
  virtual ~CUTS_Default_Msg_Log_Strategy (void);

  bool open (const ACE_CString & name);
  void close (size_t passed, size_t failed);

  void error_message (const ACE_CString & msg);
  void warning_message (const ACE_CString & msg);
  void info_message (const ACE_CString & msg);
};


#endif  // !defined _CUTS_TESTS_DEFAULT_MSG_LOG_H_
