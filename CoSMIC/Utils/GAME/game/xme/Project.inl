// -*- C++ -*-
// $Id$

#include "XME_Utils.h"

namespace GAME
{
namespace XME
{
//
// Project
//
GAME_INLINE
Project::Project (void)
: doc_ (0)
{

}

//
// Project
//
GAME_INLINE
Project::Project (const Project & proj)
: doc_ (proj.doc_),
  xmefile_ (proj.xmefile_)
{

}

//
// Project
//
GAME_INLINE
Project::Project (xercesc::DOMDocument * doc, bool validate)
: doc_ (0)
{
  this->attach (doc, validate);
}

//
// ~Project
//
GAME_INLINE
Project::~Project (void)
{

}

//
// operator ==
//
GAME_INLINE
bool Project::operator == (const Project & rhs) const
{
  return this->doc_ != 0 && this->doc_->isSameNode (rhs.doc_);
}

//
// operator !=
//
GAME_INLINE
bool Project::operator != (const Project & rhs) const
{
  return !(*this == rhs);
}

//
// save
//
GAME_INLINE
bool Project::save (void) const
{
  return this->save_i (this->xmefile_);
}

//
// name
//
GAME_INLINE
const XMLCh * Project::name (void) const
{
  return Utils::get_element_value (this->doc_->getDocumentElement (),
                                   ELEMENT_NAME);
}

//
// name
//
GAME_INLINE
void Project::name (const ::Utils::XStr & value)
{
  Utils::set_element_value (this->doc_->getDocumentElement (),
                            ELEMENT_NAME,
                            value);
}

//
// author
//
GAME_INLINE
const XMLCh * Project::author (void) const
{
  return Utils::get_element_value (this->doc_->getDocumentElement (),
                                   ELEMENT_AUTHOR);
}

//
// author
//
GAME_INLINE
void Project::author (const ::Utils::XStr & value)
{
  Utils::set_element_value (this->doc_->getDocumentElement (),
                            ELEMENT_AUTHOR,
                            value);
}

//
// comment
//
GAME_INLINE
const XMLCh * Project::comment (void) const
{
  return Utils::get_element_value (this->doc_->getDocumentElement (),
                                   ELEMENT_COMMENT);
}

//
// commnet
//
GAME_INLINE
void Project::comment (const ::Utils::XStr & value)
{
  Utils::set_element_value (this->doc_->getDocumentElement (),
                            ELEMENT_COMMENT,
                            value);
}

//
// release
//
GAME_INLINE
xercesc::DOMDocument * Project::release (void)
{
  xercesc::DOMDocument * temp = this->doc_;
  this->doc_ = 0;

  return temp;
}

//
// release
//
GAME_INLINE
bool Project::is_nil (void) const
{
  return this->doc_ == 0;
}
}
}
