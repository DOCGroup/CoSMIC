// $Id$

#include "Msg_Log.h"
#include <iostream>

//
// CUTS_Msg_Log_Strategy
//
CUTS_Msg_Log_Strategy::~CUTS_Msg_Log_Strategy (void)
{

}

//
// CUTS_Msg_Log
//
CUTS_Msg_Log::CUTS_Msg_Log (void)
: log_ (0)
{

}

//
// ~CUTS_Msg_Log
//
CUTS_Msg_Log::~CUTS_Msg_Log (void)
{
  if (this->log_ != 0)
    delete this->log_;
}

//
// init
//
void CUTS_Msg_Log::init (CUTS_Msg_Log_Strategy * log)
{
  if (this->log_)
    delete this->log_;

  this->log_ = log;
}

//
// open
//
bool CUTS_Msg_Log::open (const ACE_CString & name)
{
  if (this->log_ == 0)
    return false;

  return this->log_->open (name);
}

//
// close
//
void CUTS_Msg_Log::close (size_t passed, size_t failed)
{
  if (this->log_ != 0)
    this->log_->close (passed, failed);
}

//
// info_message
//
void CUTS_Msg_Log::info_message (const ACE_CString & msg)
{
  if (this->log_ != 0)
    this->log_->info_message (msg);
}

//
// error_message
//
void CUTS_Msg_Log::error_message (const ACE_CString & msg)
{
  if (this->log_ != 0)
    this->log_->error_message (msg);
}

//
// warning_message
//
void CUTS_Msg_Log::warning_message (const ACE_CString & msg)
{
  if (this->log_ != 0)
    this->log_->warning_message (msg);
}
