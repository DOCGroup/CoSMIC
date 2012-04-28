// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

///////////////////////////////////////////////////////////////////////////////
// class Event_Handler

//
// Event_Handler
//
GAME_INLINE
Event_Handler::Event_Handler (unsigned long mask, bool destroy_on_close)
: mask_ (mask),
  sink_ (0),
  destroy_on_close_ (destroy_on_close)
{

}

//
// ~Event_Handler
//
GAME_INLINE
Event_Handler::~Event_Handler (void)
{

}

//
// initialize
//
GAME_INLINE
int Event_Handler::initialize (Project project)
{
  this->project_ = project;
  return 0;
}

//
// set_event_sink
//
GAME_INLINE
void Event_Handler::set_event_sink (Event_Sink * sink)
{
  this->sink_ = sink;
}

//
// event_mask
//
GAME_INLINE
long Event_Handler::event_mask (void) const
{
  return this->mask_;
}

//
// handle_close
//
GAME_INLINE
void Event_Handler::handle_close (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// class Top_Level_Event_Handler

//
// Top_Level_Event_Handler
//
GAME_INLINE
Top_Level_Event_Handler::Top_Level_Event_Handler (unsigned long mask)
: Event_Handler (mask, false)
{

}

//
// Top_Level_Event_Handler
//
GAME_INLINE
Top_Level_Event_Handler::~Top_Level_Event_Handler (void)
{

}

}
}
