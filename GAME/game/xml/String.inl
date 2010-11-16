// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Xml
{

using xercesc::XMLString;

//
// String
//
GAME_INLINE
String::String (xercesc::MemoryManager * const allocator)
: wstr_ (0),
  release_ (false),
  allocator_ (allocator)
{

}

//
// String
//
GAME_INLINE
String::String (const char * str, xercesc::MemoryManager * const allocator)
: wstr_ (XMLString::transcode (str, allocator)),
  release_ (true),
  allocator_ (allocator)
{

}

//
// String
//
GAME_INLINE
String::String (const std::string & str, xercesc::MemoryManager * const allocator)
: wstr_ (XMLString::transcode (str.c_str (), allocator)),
  release_ (true),
  allocator_ (allocator)
{

}

//
// String
//
GAME_INLINE
String::String (const XMLCh * wstr, bool release, xercesc::MemoryManager * const allocator)
: wstr_ (0),
  release_ (false),
  allocator_ (0)
{
  this->set (wstr, release, allocator);
}

//,
// String
//
GAME_INLINE
String::String (const String & str, xercesc::MemoryManager * const allocator)
: wstr_ (0),
  release_ (false),
  allocator_ (0)
{
  this->set (str.wstr_, true, allocator);
}

//
// ~String
//
GAME_INLINE
String::~String (void)
{
  if (this->release_ && 0 != this->wstr_)
    XMLString::release (&this->wstr_, this->allocator_);
}

//
// length
//
GAME_INLINE
size_t String::length (void) const
{
  return XMLString::stringLen (this->wstr_);
}

//
// operator []
//
GAME_INLINE
XMLCh & String::operator [] (size_t i)
{
  return this->wstr_[i];
}

//
// operator []
//
GAME_INLINE
const XMLCh & String::operator [] (size_t i) const
{
  return this->wstr_[i];
}

//
// operator const XMLCh *
//
GAME_INLINE
String::operator const XMLCh * (void) const
{
  return this->wstr_;
}

//
// operator const XMLCh *
//
GAME_INLINE
String::operator XMLCh * (void)
{
  return this->wstr_;
}

//
// begin
//
GAME_INLINE
const XMLCh * String::begin (void) const
{
  return wstr_;
}

//
// begin
//
GAME_INLINE
XMLCh * String::begin (void)
{
  return wstr_;
}

//
// end
//
GAME_INLINE
XMLCh * String::end (void)
{
  return this->wstr_ + this->length ();
}

//
// end
//
GAME_INLINE
const XMLCh* String::end (void) const
{
  return this->wstr_ + this->length ();
}

//
// operator ==
//
GAME_INLINE
bool String::operator == (const XMLCh * wstr) const
{
  return XMLString::compareString (this->wstr_, wstr) == 0;
}

//
// operator !=
//
GAME_INLINE
bool String::operator != (const XMLCh * wstr) const
{
  return !(*this == wstr);
}

//
// operator ==
//
GAME_INLINE
bool String::operator == (const String & rhs) const
{
  return XMLString::compareString (this->wstr_, rhs.wstr_) == 0;
}

//
// operator !=
//
GAME_INLINE
bool String::operator != (const String & rhs) const
{
  return !(*this == rhs);
}

//
// operator =
//
GAME_INLINE
const String & String::operator = (const String & rhs)
{
  this->set (rhs.wstr_, true, this->allocator_);
  return *this;
}

//
// operator =
//
GAME_INLINE
const String & String::operator = (const XMLCh * rhs)
{
  this->set (rhs, true, this->allocator_);
  return *this;
}

//
// operator =
//
GAME_INLINE
const String & String::operator = (const char * rhs)
{
  this->set (rhs, this->allocator_);
  return *this;
}

//
// find
//
GAME_INLINE
int String::find (const XMLCh ch, size_t start)
{
  return XMLString::indexOf (this->wstr_, ch, start, this->allocator_);
}

//
// empty
//
GAME_INLINE
bool String::empty (void) const
{
  return this->wstr_ == 0 || this->length () == 0;
}

}
}


//
// operator ==
//
GAME_INLINE
bool operator == (const XMLCh * lhs, const GAME::Xml::String & rhs)
{
  return GAME::Xml::String (lhs, false) == rhs;
}

//
// operator !=
//
GAME_INLINE
bool operator != (const XMLCh * lhs, const GAME::Xml::String & rhs)
{
  return GAME::Xml::String (lhs, false) != rhs;
}
