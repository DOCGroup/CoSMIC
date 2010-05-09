// $Id: XercesString.cpp 571 2005-11-23 18:00:18Z kitty $

#include "XercesString.h"
#include "xercesc/util/XMLUniDefs.hpp"
#include "ace/Auto_Functor.h"
#include <ostream>

namespace Utils
{
using xercesc::XMLString;

//
// EMPTY_STRING
//
const ::Utils::XStr XStr::EMPTY_STRING ("");

//
// append
//
void XStr::append (const XMLCh * tail)
{
  // Calculate all the required string lengths.
  size_t curr_length = this->size ();
  size_t tail_length = XMLString::stringLen (tail);
  size_t length = curr_length + tail_length;
  size_t alloc_size = (length + 1) * sizeof (XMLCh);

  // Allocate space for the new string.
  XStr temp_str (this->allocator_);
  temp_str.wstr_ = (XMLCh *)this->allocator_->allocate (alloc_size);
  temp_str.release_ = true;

  // Simple trick, swap the two string's state. We do not have
  // to swap the allocators since they are one in the same.
  std::swap (temp_str.wstr_, this->wstr_);
  std::swap (temp_str.release_, this->release_);

  // Copy the characters into the new string buffer.
  XMLString::moveChars (this->wstr_, temp_str.wstr_, curr_length);
  XMLString::moveChars (this->wstr_ + curr_length, tail, tail_length);
  this->wstr_[length] = xercesc::chNull;

  // Reset the cstring.
  this->as_string_.reset ();
}

////
//// erase
////
//bool XStr::erase(const XMLCh *head, const XMLCh *tail)
//{
//  bool bOK = head <= tail && head >= begin() && tail <= end();
//  if (bOK)
//    {
//      XMLCh *result = new XMLCh[ size() - (tail - head) + 1 ];
//      XMLCh *target = result;
//      bOK = target != NULL;
//      if (bOK)
//        {
//          const XMLCh *cursor = begin();
//
//          while (cursor != head) *target++ = *cursor++;
//          cursor = tail;
//          while ( cursor != end() ) *target++ = *cursor++;
//          *target ++ = 0;
//          XMLString::release(&wstr_);
//          wstr_ = result;
//        }
//    }
//  return bOK;
//}
//

const std::string & XStr::to_string (void) const
{
  // Take the quick path out if we can.
  if (0 != this->as_string_.get ())
    return *this->as_string_;

  // Allocate a new string and reserve space.
  this->as_string_.reset (new std::string ());
  this->as_string_->reserve (this->size ());

  // Save a copy of the string.
  char * temp_str = XMLString::transcode (this->wstr_);
  this->as_string_->assign (temp_str);
  XMLString::release (&temp_str);

  return *this->as_string_;
}

//
// set
//
void XStr::
set (const XMLCh * wstr, bool release, xercesc::MemoryManager * const allocator)
{
  // Handle the current string.
  if (this->release_ && 0 != this->wstr_)
    XMLString::release (&this->wstr_, this->allocator_);

  // Save the new string, or make a copy of it. This will also
  // determine what we do with the new allocator.
  if (release)
  {
    this->wstr_ = XMLString::replicate (wstr, allocator);
    this->allocator_ = allocator;
  }
  else
    this->wstr_ = const_cast <XMLCh *> (wstr);

  // Save the release state.
  this->release_ = release;

  // Reset the cstring
  this->as_string_.reset ();
}

//
// set
//
void XStr::
set (const char * str, xercesc::MemoryManager * const allocator)
{
  // Handle the current string.
  if (this->release_ && 0 != this->wstr_)
    XMLString::release (&this->wstr_, this->allocator_);

  // Make a copy of the source string.
  this->wstr_ = XMLString::transcode (str, allocator);
  this->allocator_ = allocator;
  this->release_ = true;

  // Reset the cstring.
  this->as_string_.reset ();
}

//
// operator <<
//
std::ostream & operator << (std::ostream & out, const XStr & str)
{
  out << str.to_string ().c_str ();
  return out;
}

//
// ~XStr
//
void XStr::clear (void)
{
  if (this->release_ && 0 != this->wstr_)
    XMLString::release (&this->wstr_, this->allocator_);

  this->wstr_ = 0;
}

}
