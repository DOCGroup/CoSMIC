// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Xml
{

//
// Fragment
//
GAME_INLINE
Fragment::Fragment (xercesc::DOMElement * e)
: fragment_ (e)
{

}

//
// Fragment
//
Fragment::Fragment (const Fragment & f)
: fragment_ (f.fragment_)
{

}

//
// ~Fragment
//
GAME_INLINE
Fragment::~Fragment (void)
{

}

//
// create_element
//
GAME_INLINE
xercesc::DOMElement * Fragment::create_element (const String & name)
{
  return Fragment::create_element (this->fragment_, name);
}

//
// create_element
//
GAME_INLINE
xercesc::DOMElement * Fragment::
create_element (const String & ns, const String & name)
{
  return Fragment::create_element (this->fragment_, ns, name);
}

//
// create_simple_content
//
GAME_INLINE
xercesc::DOMElement * Fragment::
create_simple_content (const String & name, const String & value)
{
  return Fragment::create_simple_content (this->fragment_, name, value);
}

//
// create_simple_content
//
GAME_INLINE
xercesc::DOMElement * Fragment::
create_simple_content (const String & ns, const String & name, const String & value)
{
  return Fragment::create_simple_content (this->fragment_, ns, name, value);
}

//
// operator ->
//
GAME_INLINE
xercesc::DOMElement * Fragment::operator -> (void)
{
  return this->fragment_;
}

//
// ptr
//
GAME_INLINE
xercesc::DOMElement * Fragment::ptr (void)
{
  return this->fragment_;
}

//
// operator ->
//
GAME_INLINE
void Fragment::operator = (xercesc::DOMElement * e)
{
  this->fragment_ = e;
}

//
// operator xercesc::DOMElement *
//
GAME_INLINE
Fragment::operator xercesc::DOMElement * (void)
{
  return this->fragment_;
}

}
}
