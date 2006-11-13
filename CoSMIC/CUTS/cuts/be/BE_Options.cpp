// $Id$

#include "BE_Options.h"

//
// instance_
//
CUTS_BE_Options * CUTS_BE_Options::instance_ = 0;

//
// instance
//
CUTS_BE_Options * CUTS_BE_Options::instance (void)
{
  if (CUTS_BE_Options::instance_ == 0)
    CUTS_BE_Options::instance_ = new CUTS_BE_Options ();

  return  CUTS_BE_Options::instance_;
}

//
// close_singleton
//
void CUTS_BE_Options::close_singleton (void)
{
  if (CUTS_BE_Options::instance_ != 0)
  {
    delete CUTS_BE_Options::instance_;
    CUTS_BE_Options::instance_ = 0;
  }
}

