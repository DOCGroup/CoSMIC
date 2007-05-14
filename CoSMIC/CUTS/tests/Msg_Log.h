// -*- C++ -*-

//=============================================================================
/**
 * @file      Msg_Log.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_TEST_MSG_LOG_H_
#define _CUTS_TEST_MSG_LOG_H_

#include "CUTS_Test_export.h"
#include "ace/Singleton.h"
#include "ace/streams.h"
#include "ace/Thread_Mutex.h"
#include "ace/SString.h"
#include <sstream>

//=============================================================================
/**
 * @class CUTS_Msg_Log
 *
 * Message log for the unit test. This object is a singleton that
 * is initialized by the client.
 */
//=============================================================================

class CUTS_TEST_Export CUTS_Msg_Log_Strategy
{
public:
  virtual bool open (const ACE_CString & name) = 0;
  virtual void close (size_t passed, size_t failed) = 0;

  virtual void error_message (const ACE_CString & msg) = 0;
  virtual void warning_message (const ACE_CString & msg) = 0;
  virtual void info_message (const ACE_CString & msg) = 0;

  virtual ~CUTS_Msg_Log_Strategy (void);
};

//=============================================================================
/**
 * @class CUTS_Msg_Log
 *
 * Message log for the unit test. This object is a singleton that
 * is initialized by the client.
 */
//=============================================================================

class CUTS_TEST_Export CUTS_Msg_Log
{
public:
  CUTS_Msg_Log (void);
  virtual ~CUTS_Msg_Log (void);

  void init (CUTS_Msg_Log_Strategy * log);

  bool open (const ACE_CString & name);
  void close (size_t passed, size_t failed);

  void error_message (const ACE_CString & msg);
  void warning_message (const ACE_CString & msg);
  void info_message (const ACE_CString & msg);

private:
  /// Pointer to the actual log.
  CUTS_Msg_Log_Strategy * log_;
};

CUTS_TEST_SINGLETON_DECLARE (ACE_Singleton,
                             CUTS_Msg_Log,
                             ACE_Thread_Mutex);

#define CUTS_MSG_LOG() \
  ACE_Singleton <CUTS_Msg_Log, ACE_Thread_Mutex>::instance ()

#endif  // !defined _CUTS_TEST_MSG_LOG_H_
