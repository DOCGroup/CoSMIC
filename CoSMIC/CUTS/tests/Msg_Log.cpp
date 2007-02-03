// $Id$

#include "Msg_Log.h"

//
// instance_
//
CUTS_Msg_Log * CUTS_Msg_Log::instance_ = 0;

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
bool CUTS_Msg_Log::open (const std::string & outdir)
{
  return this->log_->open (outdir);
}

//
// close
//
void CUTS_Msg_Log::close (void)
{
  this->log_->close ();
}

//
// info_message
//
void CUTS_Msg_Log::info_message (const std::string & msg)
{
  this->log_->info_message (msg);
}

//
// error_message
//
void CUTS_Msg_Log::error_message (const std::string & msg)
{
  this->log_->error_message (msg);
}

//
// warning_message
//
void CUTS_Msg_Log::warning_message (const std::string & msg)
{
  this->log_->warning_message (msg);
}

//
// instance
//
CUTS_Msg_Log * CUTS_Msg_Log::instance (void)
{
  if (CUTS_Msg_Log::instance_ == 0)
    CUTS_Msg_Log::instance_ = new CUTS_Msg_Log ();
  return CUTS_Msg_Log::instance_;
}

//
// close_singleton
//
void CUTS_Msg_Log::close_singleton (void)
{
  if (CUTS_Msg_Log::instance_ != 0)
  {
    delete CUTS_Msg_Log::instance_;
    CUTS_Msg_Log::instance_ = 0;
  }
}

