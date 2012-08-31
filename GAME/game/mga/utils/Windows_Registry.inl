// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

///////////////////////////////////////////////////////////////////////////////
// Windows_Registry_Key

//
// Windows_Registry_Key
//
GAME_INLINE
Windows_Registry_Key::Windows_Registry_Key (void)
: key_ (0),
  requires_close_ (false)
{

}

//
// Windows_Registry_Key
//
GAME_INLINE
Windows_Registry_Key::
Windows_Registry_Key (HKEY key, const char * subkey)
: key_ (0),
  requires_close_ (false)
{
  this->open (key, subkey);
}

//
// Windows_Registry_Key
//
GAME_INLINE
int Windows_Registry_Key::
open (const Windows_Registry_Key & key, const char * subkey)
{
  return this->open (key.key_, subkey);
}

//
// ~Windows_Registry_Key
//
GAME_INLINE
Windows_Registry_Key::~Windows_Registry_Key (void)
{
  this->close ();
}

//
// is_valid
//
GAME_INLINE
bool Windows_Registry_Key::is_valid (void) const
{
  return 0 != this->key_;
}

///////////////////////////////////////////////////////////////////////////////
// Windows_Registry_Key_Iterator

//
// ~Windows_Registry_Key_Iterator
//
GAME_INLINE
Windows_Registry_Key_Iterator::~Windows_Registry_Key_Iterator (void)
{

}

//
// ~Windows_Registry_Key_Iterator
//
GAME_INLINE
const char * Windows_Registry_Key_Iterator::name (void) const
{
  return this->buffer_.get ();
}

//
// done
//
GAME_INLINE
bool Windows_Registry_Key_Iterator::done (void) const
{
  return this->index_ >= this->count_;
}

///////////////////////////////////////////////////////////////////////////////
// Windows_Registry_Value_Iterator

//
// Windows_Registry_Value_Iterator
//
GAME_INLINE
Windows_Registry_Value_Iterator::
Windows_Registry_Value_Iterator (const Windows_Registry_Key & key,
                                      u_char * buffer,
                                      u_long bufsize)
: key_ (key),
  is_done_ (false),
  index_ (0),
  buffer_ (buffer),
  bufsize_ (bufsize),
  datasize_ (bufsize_)
{
  this->advance ();
}

//
// ~Windows_Registry_Value_Iterator
//
GAME_INLINE
Windows_Registry_Value_Iterator::
~Windows_Registry_Value_Iterator (void)
{

}

//
// advance
//
GAME_INLINE
int Windows_Registry_Value_Iterator::advance (void)
{
  return this->advance (this->buffer_, this->datasize_);
}

//
// done
//
GAME_INLINE
bool Windows_Registry_Value_Iterator::done (void)
{
  return this->is_done_;
}

}
}
