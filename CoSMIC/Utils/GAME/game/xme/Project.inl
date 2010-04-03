// -*- C++ -*-
// $Id$

#include "XME_Utils.h"

namespace GME
{
namespace XME
{
//
// Project
//
GME_INLINE
Project::Project (void)
: doc_ (0)
{

}

//
// Project
//
GME_INLINE
Project::Project (Project & proj)
: doc_ (proj.release ()),
  xmefile_ (proj.xmefile_)
{

}

//
// Project
//
GME_INLINE
Project::Project (xercesc::DOMDocument * doc)
: doc_ (doc)
{

}

//
// ~Project
//
GME_INLINE
Project::~Project (void)
{
  if (0 != this->doc_)
    this->doc_->release ();
}

//
// operator ==
//
GME_INLINE
bool Project::operator == (const Project & rhs) const
{
  return this->doc_ != 0 && this->doc_->isSameNode (rhs.doc_);
}

//
// operator !=
//
GME_INLINE
bool Project::operator != (const Project & rhs) const
{
  return !(*this == rhs);
}

//
// save
//
GME_INLINE
bool Project::save (void) const
{
  return this->save_i (this->xmefile_);
}

//
// name
//
GME_INLINE
const XMLCh * Project::name (void) const
{
  return Utils::get_element_value (this->doc_->getDocumentElement (),
                                   ELEMENT_NAME);
}

//
// name
//
GME_INLINE
void Project::name (const ::Utils::XStr & value)
{
  Utils::set_element_value (this->doc_->getDocumentElement (),
                            ELEMENT_NAME,
                            value);
}

//
// author
//
GME_INLINE
const XMLCh * Project::author (void) const
{
  return Utils::get_element_value (this->doc_->getDocumentElement (),
                                   ELEMENT_AUTHOR);
}

//
// author
//
GME_INLINE
void Project::author (const ::Utils::XStr & value)
{
  Utils::set_element_value (this->doc_->getDocumentElement (),
                            ELEMENT_AUTHOR,
                            value);
}

//
// comment
//
GME_INLINE
const XMLCh * Project::comment (void) const
{
  return Utils::get_element_value (this->doc_->getDocumentElement (),
                                   ELEMENT_COMMENT);
}

//
// commnet
//
GME_INLINE
void Project::comment (const ::Utils::XStr & value)
{
  Utils::set_element_value (this->doc_->getDocumentElement (),
                            ELEMENT_COMMENT,
                            value);
}

//
// release
//
GME_INLINE
xercesc::DOMDocument * Project::release (void)
{
  xercesc::DOMDocument * temp = this->doc_;
  this->doc_ = 0;

  return temp;
}
}
}
