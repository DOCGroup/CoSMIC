// -*- C++ -*-
// $Id$

namespace CUTS_BE
{

//
// Natural_Lang_Generator
//
CUTS_INLINE
Natural_Lang_Generator::Natural_Lang_Generator (void)
{

}

//
// ~Natural_Lang_Generator
//
CUTS_INLINE
Natural_Lang_Generator::~Natural_Lang_Generator (void)
{

}

//
// write_InEventPort_end
//
CUTS_INLINE
void Natural_Lang_Generator::
write_InEventPort_end (const PICML::InEventPort & sink)
{
  this->outfile_ << std::endl;
}

//
// write_PeriodicEvent_end
//
CUTS_INLINE
void Natural_Lang_Generator::
write_PeriodicEvent_end (const PICML::PeriodicEvent & event)
{
  this->outfile_ << std::endl;
}

//
// write_PeriodicEvent_end
//
CUTS_INLINE
void Natural_Lang_Generator::
write_environment_method_end (const PICML::InputAction & action)
{
  this->outfile_ << std::endl;
}

//
// write_WorkerAction_begin
//
CUTS_INLINE
void Natural_Lang_Generator::write_action_end (void)
{
  this->outfile_ << std::endl;
}

}
