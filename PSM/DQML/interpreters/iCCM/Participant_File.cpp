// $Id$

#include "stdafx.h"
#include "Participant_File.h"
#include "Participant_Visitor.h"

#include "DQML/DQML.h"

#include "game/xml/Document.h"

#include "boost/bind.hpp"
#include <algorithm>

#include "Utils/Utils.h"

namespace DQML_iCCM
{
using GAME::Mga::Iterator;
using GAME::Xml::String;

///////////////////////////////////////////////////////////////////////////////
// Participant_File_Locator

//
// Participant_File_Locator
//
Participant_File_Locator::Participant_File_Locator (const std::string & path)
: path_ (path)
{

}

//
// Participant_File_Locator
//
Participant_File_Locator::~Participant_File_Locator (void)
{

}

//
// visit_RootFolder
//
void Participant_File_Locator::visit_RootFolder (DQML::RootFolder_in item)
{
  for (auto & iccm_folder : item->get_iCCM ())
    iccm_folder->accept (this);
}

//
// visit_iCCM
//
void Participant_File_Locator::visit_iCCM (DQML::iCCM_in item)
{
  for (auto & qos_folder : item->get_DomainQosFolders ())
    qos_folder->accept (this);
}

//
// visit_DomainQosFolder
//
void Participant_File_Locator::
visit_DomainQosFolder (DQML::DomainQosFolder_in item)
{
  for (auto & domain : item->get_Domains ())
    domain->accept (this);
}

//
// visit_Domain
//
void Participant_File_Locator::visit_Domain (DQML::Domain_in item)
{
  this->domain_ = item->name ();

  for (auto & participant : item->get_Participants ())
    participant->accept (this);
}

//
// visit_Domain
//
void Participant_File_Locator::visit_Participant (DQML::Participant_in item)
{
  const std::string pathname = this->path_ + "/" + this->domain_;
  Utils::CreatePath (pathname);

  Participant_File file;
  file.generate (pathname, item);
}

///////////////////////////////////////////////////////////////////////////////
// Participant_File

//
// Participant_File
//
Participant_File::Participant_File (void)
{

}

//
// Participant_File
//
Participant_File::~Participant_File (void)
{

}

//
// generate
//
void Participant_File::
generate (const std::string & path, DQML::Participant_in participant)
{
  const std::string filename = path + "/" + participant->name () + ".dpq";

  // Create a new document and populate its contents.
  GAME::Xml::LS_Document document;
  Participant_Visitor visitor (document);
  participant->accept (&visitor);

  // Serialize the Xml document to a file.
  using namespace xercesc;
  DOMLSSerializer* serializer = ((DOMImplementationLS*)document.impl ())->createLSSerializer ();

  // Initialize the serializer.
  if (serializer->getDomConfig()->canSetParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true))
    serializer->getDomConfig()->setParameter (XMLUni::fgDOMWRTDiscardDefaultContent, true);

  if (serializer->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true))
    serializer->getDomConfig ()->setParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true);

  // Write the document to the URI.
  bool retval = serializer->writeToURI (document.root (), String (filename));
  serializer->release ();
}

}
