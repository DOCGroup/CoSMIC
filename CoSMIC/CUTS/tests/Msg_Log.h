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
#include <string>

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
  virtual bool open (const std::string & outdir) = 0;
  virtual void close (void) = 0;

  virtual void error_message (const std::string & msg) = 0;
  virtual void warning_message (const std::string & msg) = 0;
  virtual void info_message (const std::string & msg) = 0;

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

class CUTS_TEST_Export CUTS_Msg_Log : public CUTS_Msg_Log_Strategy
{
public:
  void init (CUTS_Msg_Log_Strategy * log);

  bool open (const std::string & outdir);
  void close (void);

  void error_message (const std::string & msg);
  void warning_message (const std::string & msg);
  void info_message (const std::string & msg);

  static CUTS_Msg_Log * instance (void);
  static void close_singleton (void);

private:
  CUTS_Msg_Log (void);
  virtual ~CUTS_Msg_Log (void);

  /// The singleton instance.
  static CUTS_Msg_Log * instance_;

  /// Pointer to the actual log.
  CUTS_Msg_Log_Strategy * log_;
};

#endif  // !defined _CUTS_TEST_MSG_LOG_H_
