// -*- C++ -*-
// $Id$

namespace Utils
{
using xercesc::XMLString;

//
// XStr
//
inline
XStr::XStr (xercesc::MemoryManager * const allocator)
: wstr_ (0),
  release_ (false),
  allocator_ (allocator)
{

}

//
// XStr
//
inline
XStr::XStr (const char * str, xercesc::MemoryManager * const allocator)
: wstr_ (XMLString::transcode (str, allocator)),
  release_ (true),
  allocator_ (allocator)
{

}

//
// XStr
//
inline
XStr::XStr (const std::string & str, xercesc::MemoryManager * const allocator)
: wstr_ (XMLString::transcode (str.c_str (), allocator)),
  release_ (true),
  allocator_ (allocator)
{

}

//
// XStr
//
inline
XStr::XStr (const XMLCh * wstr, bool release, xercesc::MemoryManager * const allocator)
: wstr_ (0),
  release_ (false),
  allocator_ (0)
{
  this->set (wstr, release, allocator);
}

//,
// XStr
//
inline
XStr::XStr (const XStr & str, xercesc::MemoryManager * const allocator)
: wstr_ (0),
  release_ (false),
  allocator_ (0)
{
  this->set (str.wstr_, true, allocator);
}

//
// ~XStr
//
inline
XStr::~XStr (void)
{
  if (this->release_ && 0 != this->wstr_)
    XMLString::release (&this->wstr_, this->allocator_);
}

//
// size
//
inline
size_t XStr::size (void) const
{
  return XMLString::stringLen (this->wstr_);
}

//
// operator []
//
inline
XMLCh & XStr::operator [] (size_t i)
{
  return this->wstr_[i];
}

//
// operator []
//
inline
const XMLCh & XStr::operator [] (size_t i) const
{
  return this->wstr_[i];
}

//
// operator const XMLCh *
//
inline
XStr::operator const XMLCh * (void) const
{
  return this->wstr_;
}

//
// operator const XMLCh *
//
inline
XStr::operator XMLCh * (void)
{
  return this->wstr_;
}

//
// begin
//
inline
const XMLCh * XStr::begin (void) const
{
  return wstr_;
}

//
// begin
//
inline
XMLCh * XStr::begin (void)
{
  return wstr_;
}

//
// end
//
inline
XMLCh * XStr::end (void)
{
  return this->wstr_ + this->size ();
}

//
// end
//
inline
const XMLCh* XStr::end (void) const
{
  return this->wstr_ + this->size ();
}

//
// operator ==
//
inline
bool XStr::operator == (const XMLCh * wstr) const
{
  return XMLString::compareString (this->wstr_, wstr) == 0;
}

//
// operator !=
//
inline
bool XStr::operator != (const XMLCh * wstr) const
{
  return !(*this == wstr);
}

//
// operator ==
//
inline
bool XStr::operator == (const XStr & rhs) const
{
  return XMLString::compareString (this->wstr_, rhs.wstr_) == 0;
}

//
// operator !=
//
inline
bool XStr::operator != (const XStr & rhs) const
{
  return !(*this == rhs);
}

//
// operator =
//
inline
const XStr & XStr::operator = (const XStr & rhs)
{
  this->set (rhs.wstr_, true, this->allocator_);
  return *this;
}

//
// operator =
//
inline
const XStr & XStr::operator = (const XMLCh * rhs)
{
  this->set (rhs, true, this->allocator_);
  return *this;
}

//
// operator =
//
inline
const XStr & XStr::operator = (const char * rhs)
{
  this->set (rhs, this->allocator_);
  return *this;
}

//
// find
//
inline
int XStr::find (const XMLCh ch, size_t start)
{
  return XMLString::indexOf (this->wstr_, ch, start, this->allocator_);
}


}
