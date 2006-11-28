// -*- C++ -*-

//=============================================================================
/**
 * @file      Log_Msg.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_LOG_MSG_H_
#define _CUTS_LOG_MSG_H_

#include "ace/Log_Msg.h"

#define CUTS_ERROR(level, message) \
  ACE_ERROR ((level, "[%M] -%T - " message))

#define CUTS_DEBUG(level, message) \
  ACE_DEBUG ((level, "[%M] -%T - " message))

#endif  // !defined _CUTS_LOG_MSG_H_
