// $Id$

namespace GAME
{
//
// Event_Handler
//
GAME_INLINE
Event_Handler::Event_Handler (Event_Handler_Interface * impl)
: impl_ (impl),
  enable_ (true)
{
  if (0 != this->impl_)
    this->impl_->set_event_handler (this);
}

//
// ~Event_Handler
//
GAME_INLINE
Event_Handler::~Event_Handler (void)
{
  this->close ();
}

//
// enable
//
GAME_INLINE
void Event_Handler::enable (bool state)
{
  this->enable_ = state;
}

}
