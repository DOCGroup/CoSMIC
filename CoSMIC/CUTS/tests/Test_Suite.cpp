// $Id$

#include "Test_Suite.h"

//
// CUTS_Test_Suite
//
CUTS_Test_Suite::CUTS_Test_Suite (const char * name)
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
// run
//
void CUTS_Test_Suite::run (int argc, char * argv [])
{
  for (Unit_Test_List::iterator iter = this->unit_test_.begin ();
       iter != this->unit_test_.end ();
       iter ++)
  {
    if ((*iter->second) () == 0)
      ++ this->passed_;
    else
      ++ this->failed_;
  }
}

//
// add_unit_test
//
void CUTS_Test_Suite::add_unit_test (const std::string & name,
                                     unit_test_ptr unit_test)
{
  this->unit_test_.push_back (std::make_pair (name, unit_test));
}

//
// close
//
void CUTS_Test_Suite::close (void)
{
  delete this;
}

//
// name
//
const char * CUTS_Test_Suite::name (void) const
{
  return this->name_.c_str ();
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
