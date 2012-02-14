// $Id$

namespace GAME
{
namespace Xml
{

//
// Document
//
GAME_INLINE
Document::Document (xercesc::DOMImplementation * impl)
: impl_ (impl),
  doc_ (0)
{

}

//
// ~Document
//
GAME_INLINE
Document::~Document (void)
{
  this->close ();
}

//
// operator ->
//
GAME_INLINE
xercesc::DOMDocument * Document::operator -> (void) const
{
  return this->doc_;
}

//
// impl
//
GAME_INLINE
xercesc::DOMImplementation * Document::impl (void) const
{
  return this->impl_;
}

//
// doc
//
GAME_INLINE
xercesc::DOMDocument * Document::doc (void) const
{
  return this->doc_;
}

//
// root
//
GAME_INLINE
const Fragment & Document::root (void) const
{
  return *this->root_.get ();
}

//
// root
//
GAME_INLINE
Fragment & Document::root (void)
{
  return *this->root_.get ();
}

}
}
