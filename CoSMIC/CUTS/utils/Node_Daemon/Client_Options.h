// -*- C++ -*-

//=============================================================================
/**
 * @file      Client_Options.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CLIENT_OPTIONS_H_
#define _CLIENT_OPTIONS_H_

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

//=============================================================================
/**
 * @class Client_Options
 *
 * Collection of configurable client options.
 */
//=============================================================================

class Client_Options
{
public:
  /// Default constructor.
  Client_Options (void);

  /// Verbose setting for the client.
  bool verbose_;
};

/// Singleton for the client options.
#define CLIENT_OPTIONS() \
  ACE_Singleton <Client_Options, ACE_Null_Mutex>::instance ()

/// Wrapper for writing a ACE_ERROR based on the verbose flag
/// in Client_Options.
#define VERBOSE_MESSAGE(msg) \
  if (CLIENT_OPTIONS()->verbose_) \
  { \
    ACE_ERROR (msg); \
  }

/// Wrapper for writing a ACE_ERROR_RETURN based on the verbose
/// flag in Client_Options.
#define VERBOSE_MESSAGE_RETURN(msg, retval) \
  if (CLIENT_OPTIONS()->verbose_) \
  { \
    ACE_ERROR_RETURN (msg, retval); \
  }


#endif  // !defined _CLIENT_OPTIONS_H_
