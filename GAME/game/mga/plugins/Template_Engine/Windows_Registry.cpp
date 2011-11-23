// $Id$

#include "stdafx.h"
#include "Windows_Registry.h"

#if !defined (__GAME_INLINE__)
#include "Windows_Registry.inl"
#endif

#include "ace/CORBA_macros.h"
#include "ace/OS_memory.h"

//
// open
//
int Windows_Registry_Key::open (HKEY key, const char * subkey)
{
  // Make sure the current key is closed.
  if (0 != this->key_)
    this->close_i ();

  // Open the registry key.
  long result = ::RegOpenKey (key, subkey, &this->key_);

  // Determine if this is a key that needs to be closed.
  if (result == ERROR_SUCCESS)
  {
    if (HKEY_CLASSES_ROOT == key ||
        HKEY_CURRENT_CONFIG == key ||
        HKEY_CURRENT_USER == key ||
        HKEY_LOCAL_MACHINE == key ||
        HKEY_USERS == key)
    {
      this->requires_close_ = false;
    }
    else
      this->requires_close_ = true;
  }

  return ERROR_SUCCESS == result ? 0 : -1;
}

//
// close
//
void Windows_Registry_Key::close (void)
{
  if (0 != this->key_)
    this->close_i ();
}

//
// close
//
void Windows_Registry_Key::close_i (void)
{
  // Close the key if necessary.
  if (this->requires_close_)
    ::RegCloseKey (this->key_);

  // Reset the value of the key.
  this->key_ = 0;
}

//
// get_value
//
int Windows_Registry_Key::get_value (const char * value,
                                     char * buffer,
                                     unsigned long bufsize)
{
  int retval = ::RegQueryValueEx (this->key_,
                                  value,
                                  0,
                                  0,
                                  (unsigned char *)buffer,
                                  &bufsize);

  return retval == ERROR_SUCCESS ? 0 : -1;
}

///////////////////////////////////////////////////////////////////////////////
// Windows_Registry_Key_Iterator

//
// Windows_Registry_Key_Iterator
//
Windows_Registry_Key_Iterator::
Windows_Registry_Key_Iterator (const Windows_Registry_Key & key)
: key_ (key),
  count_ (0),
  index_ (0)
{
  // Initialize the size of the buffer.
  int retval = ::RegQueryInfoKey (this->key_.key_,
                                  0,
                                  0,
                                  0,
                                  &this->count_,
                                  &this->bufsize_,
                                  0,
                                  0,
                                  0,
                                  0,
                                  0,
                                  0);

  if (this->bufsize_ > 0)
  {
    // Increment the buffer size for the NULL terminator.
    ++ this->bufsize_;

    // Allocate a buffer for the key names.
    char * buffer = 0;

    ACE_NEW_THROW_EX (buffer,
                      char [this->bufsize_],
                      ACE_bad_alloc ());

    this->buffer_.reset (buffer);
  }

  // Move to the first subkey.
  if (this->count_ > 0)
    this->advance ();
}

//
// advance
//
void Windows_Registry_Key_Iterator::advance (void)
{
  int retval = ::RegEnumKey (this->key_.key_,
                             this->index_,
                             this->buffer_.get (),
                             this->bufsize_);

  if (retval == ERROR_SUCCESS)
    ++ this->index_;
}

///////////////////////////////////////////////////////////////////////////////
// CUTS_Windows_Registry_Value_Iterator

//
// advance
//
int CUTS_Windows_Registry_Value_Iterator::
advance (u_char * buffer, u_long & bufsize)
{
  u_long name_size = sizeof (this->data_);

  int retval = ::RegEnumValue (this->key_.key_,
                               this->index_,
                               this->data_,
                               &name_size,
                               0,
                               &this->value_type_,
                               buffer,
                               &bufsize);

  if (ERROR_NO_MORE_ITEMS == retval)
    this->is_done_ = true;
  else
    ++ this->index_;

  return ERROR_SUCCESS == retval ? 0 : -1;
}
