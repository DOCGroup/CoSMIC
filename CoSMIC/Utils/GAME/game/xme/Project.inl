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
: doc_ (0),
  config_ (0)
{

}

//
// Project
//
GAME_INLINE
Project::Project (const Project & proj)
: doc_ (proj.doc_),
  xmefile_ (proj.xmefile_),
  config_ (proj.config_)
{

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
void Project::name (const GAME::Xml::String & value)
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
void Project::author (const GAME::Xml::String & value)
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
void Project::comment (const GAME::Xml::String & value)
{
  Utils::set_element_value (this->doc_->getDocumentElement (),
                            ELEMENT_COMMENT,
                            value);
}

//
// release
//
GAME_INLINE
bool Project::is_nil (void) const
{
  return this->doc_ == 0;
}

//
// schema
//
GAME_INLINE
const Configuration * Project::configuration (void) const
{
  return this->config_;
}

//
// attach_library
//
GAME_INLINE
Library Project::
attach_library (const GAME::Xml::String & as_name, const GAME::Xml::String & lib)
{
  Library library = this->attach_library (lib);
  library.name (as_name);

  return library;
}

}
}
