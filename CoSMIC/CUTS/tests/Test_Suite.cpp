// $Id$

#include "Test_Suite.h"
#include "Default_Msg_Log.h"

//
// CUTS_Test_Suite
//
CUTS_Test_Suite::CUTS_Test_Suite (void)
: passed_ (0),
  failed_ (0)
{

}

//
// CUTS_Test_Suite
//
CUTS_Test_Suite::CUTS_Test_Suite (const ACE_CString & name)
: name_ (name),
  passed_ (0),
  failed_ (0)
{

}

//
// CUTS_Test_Suite
//
CUTS_Test_Suite::~CUTS_Test_Suite (void)
{

}

//
// add_unit_test
//
int CUTS_Test_Suite::
add_unit_test (const ACE_CString & name, _unit_test unit_test)
{
  this->unit_test_.push_back (std::make_pair (name, unit_test));
  return 0;
}

//
// name
//
const ACE_CString & CUTS_Test_Suite::name (void) const
{
  return this->name_;
}

//
// name
//
void CUTS_Test_Suite::name (const ACE_CString & name)
{
  this->name_ = name;
}

//
// passed
//
size_t CUTS_Test_Suite::passed (void) const
{
  return this->passed_;
}

//
// failed
//
size_t CUTS_Test_Suite::failed (void) const
{
  return this->failed_;
}

//
// run_all_unit_test
//
int CUTS_Test_Suite::
run_all_unit_test (int argc, char * argv [])
{
  // Create the default logging strategy.
  CUTS_Msg_Log_Strategy * msg_log = 0;
  ACE_NEW_RETURN (msg_log, CUTS_Default_Msg_Log_Strategy, -1);

  // Initalize the logger.
  CUTS_MSG_LOG ()->init (msg_log);
  CUTS_MSG_LOG ()->open (this->name_);

  // Run all the unit tests in the test suite.
  for (Unit_Test_List::iterator iter = this->unit_test_.begin ();
       iter != this->unit_test_.end ();
       iter ++)
  {
    std::ostringstream ostr;
    ostr << "running test '" << iter->first << "'" << std::endl;
    CUTS_MSG_LOG ()->info_message (ostr.str ().c_str ());

    if ((*iter->second) () == 0)
    {
      this->passed_ ++;
    }
    else
    {
      this->failed_ ++;
    }

    ostr.seekp (0);
  }

  CUTS_MSG_LOG ()->close (this->passed_, this->failed_);
  return 0;
}
