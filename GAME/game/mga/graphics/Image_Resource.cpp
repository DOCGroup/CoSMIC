// $Id$

#include "stdafx.h"
#include "Image_Resource.h"
#include "game/mga/Exception.h"
#include <memory>

namespace GAME
{
namespace Mga
{
namespace graphics
{

/**
 * @class HGlobal_Auto_Free
 *
 * Utility class for ensure proper release of global memory.
 */
class HGlobal_Auto_Free
{
public:
  /**
   * Initializing constructor.
   */
  HGlobal_Auto_Free (HGLOBAL global)
    : global_ (global)
  {

  }

  /// Destructor.
  ~HGlobal_Auto_Free (void)
  {
    ::GlobalFree (this->global_);
  }

private:
  /// Pointer to the global memory.
  HGLOBAL global_;
};

/**
 * @class Global_Guard
 *
 * Utility class to ensure proper cleanup of locks.
 */
class Global_Guard
{
public:
  /**
   * Initializing constructor.
   */
  Global_Guard (LPVOID buffer)
    : buffer_ (buffer),
      lock_ (::GlobalLock (buffer_))
  {

  }

  /// Destructor.
  ~Global_Guard (void)
  {
    ::GlobalUnlock (this->buffer_);
  }

  LPVOID buffer (void) const
  {
    return this->buffer_;
  }

  LPVOID ptr (void) const
  {
    return this->lock_;
  }

  bool is_valid (void) const
  {
    return this->lock_ != NULL;
  }

private:
  /// Pointer the buffer.
  LPVOID buffer_;

  /// Pointer to the lock.
  LPVOID lock_;
};

//
// load
//
Gdiplus::Image * Image_Resource::load (UINT id, LPCTSTR type)
{
  HMODULE module = ::AfxGetInstanceHandle ();
  return Image_Resource::load (module, MAKEINTRESOURCE (id), type);
}

//
// load
//
Gdiplus::Image * Image_Resource::
load (LPCTSTR name, LPCTSTR type)
{
  HMODULE module = ::AfxGetInstanceHandle ();
  return Image_Resource::load (module, name, type);
}

//
// load
//
Gdiplus::Image * Image_Resource::
load (HMODULE instance, LPCTSTR name, LPCTSTR type)
{
  // Locate the resource in the module.
  HRSRC rc = ::FindResource (instance, name, type);
  if (rc == NULL)
    return 0;

  // Get the size of the resource.
  DWORD size = ::SizeofResource (instance, rc);
  if (0 == size)
    return 0;

  // Lock the resource.
  LPVOID rcdata = ::LockResource (::LoadResource (instance, rc));
  if (rcdata == NULL)
    return 0;

  // Allocate space to load the resource into memory.
  HGLOBAL buffer = ::GlobalAlloc (GMEM_MOVEABLE, size);
  if (buffer == NULL)
    return 0;

  // Automatically free the memory when control returns from
  // this function.
  HGlobal_Auto_Free auto_free (buffer);
  Global_Guard guard (buffer);

  if (!guard.is_valid ())
    return 0;

  // Copy the memory over into the buffer.
  ::CopyMemory (guard.ptr (), rcdata, size);

  // Create a IStream for reading the resource's data.
  ATL::CComPtr <IStream> stream;
  if (::CreateStreamOnHGlobal (guard.buffer (), FALSE, &stream) != S_OK)
    return 0;

  // Load the bitmap from the stream.
  std::auto_ptr <Gdiplus::Image> bitmap (Gdiplus::Image::FromStream (stream));

  if (0 != bitmap.get () && bitmap->GetLastStatus() == Gdiplus::Ok)
    return bitmap.release ();

  return 0;
}

}
}
}