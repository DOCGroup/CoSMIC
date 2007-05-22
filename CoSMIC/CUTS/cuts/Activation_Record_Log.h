// -*- C++ -*-

//=============================================================================
/**
 * @file      Activation_Record_Log.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_ACTIVATION_RECORD_LOG_H_
#define _CUTS_ACTIVATION_RECORD_LOG_H_

#include "cuts/Log_T.h"
#include "cuts/Activation_Record.h"
#include "ace/RW_Thread_Mutex.h"

typedef CUTS_Log_T <CUTS_Activation_Record,
                    ACE_RW_Thread_Mutex> CUTS_Activation_Record_Log;

#endif  // !defined _CUTS_ACTIVATION_RECORD_LOG_H_
