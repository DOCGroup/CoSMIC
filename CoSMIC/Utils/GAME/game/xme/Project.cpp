// $Id$

#include "Project.h"

#if !defined (__GME_INLINE__)
#include "Project.inl"
#endif

#include "Folder.h"
#include "GME_ID_Generator.h"
#include "GME_ID_Generator_T.h"

#include "Utils/xercesc/XML_Error_Handler.h"
#include "Utils/xercesc/EntityResolver.h"
#include "xercesc/parsers/XercesDOMParser.hpp"

#include "ace/OS_Memory.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_time.h"
#include <sstream>

namespace GME
{
namespace XME
{
const ::Utils::XStr Project::TAGNAME ("project");
const ::Utils::XStr Project::DTD ("mga.dtd");
const ::Utils::XStr Project::XML_VERSION ("1.0");
const ::Utils::XStr Project::ELEMENT_NAME ("name");
const ::Utils::XStr Project::ELEMENT_AUTHOR ("author") ;
const ::Utils::XStr Project::ELEMENT_COMMENT ("comment");

//
// timestamp
//
static ACE_TCHAR * timestamp (ACE_TCHAR * buffer, int length)
{
  if (length < 27)
  {
    errno = EINVAL;
    return 0;
  }

#if defined (WIN32)
   // Emulate Unix.  Win32 does NOT support all the UNIX versions
   // below, so DO we need this ifdef.
  static const ACE_TCHAR *day_of_week_name[] =
  {
    ACE_TEXT ("Sun"),
    ACE_TEXT ("Mon"),
    ACE_TEXT ("Tue"),
    ACE_TEXT ("Wed"),
    ACE_TEXT ("Thu"),
    ACE_TEXT ("Fri"),
    ACE_TEXT ("Sat")
  };

  static const ACE_TCHAR *month_name[] =
  {
    ACE_TEXT ("Jan"),
    ACE_TEXT ("Feb"),
    ACE_TEXT ("Mar"),
    ACE_TEXT ("Apr"),
    ACE_TEXT ("May"),
    ACE_TEXT ("Jun"),
    ACE_TEXT ("Jul"),
    ACE_TEXT ("Aug"),
    ACE_TEXT ("Sep"),
    ACE_TEXT ("Oct"),
    ACE_TEXT ("Nov"),
    ACE_TEXT ("Dec")
  };

  SYSTEMTIME local;
  ::GetLocalTime (&local);

  ACE_OS::sprintf (buffer,
                   ACE_TEXT ("%3s %3s %02d% 02d:%02d:%02d %04d"),
                   day_of_week_name[local.wDayOfWeek],
                   month_name[local.wMonth - 1],
                   (int) local.wDay,
                   (int) local.wHour,
                   (int) local.wMinute,
                   (int) local.wSecond,
                   (int) local.wYear);
#else  /* UNIX */
  ACE_TCHAR timebuf[26]; // This magic number is based on the ctime(3c) man page.
  ACE_Time_Value cur_time = ACE_OS::gettimeofday ();
  time_t secs = cur_time.sec ();

  ACE_OS::ctime_r (&secs,
                   timebuf,
                   sizeof timebuf);
  // date_and_timelen > sizeof timebuf!
  ACE_OS::strsncpy (buffer,
                    timebuf,
                    length);
  buffer[26] = '\0';
#endif /* WIN32 */

  return &buffer[0];
}

//
// _create
//
Project Project::
_create (const ::Utils::XStr & xmefile,
         const ::Utils::XStr & paradigm,
         const ::Utils::XStr & guid)
{
  using namespace xercesc;

  // Get the LS DOM implementation.
  static const XMLCh LS[3] = {chLatin_L, chLatin_S, chNull};
  DOMImplementation * impl = DOMImplementationRegistry::getDOMImplementation (LS);

  // TODO throw an exception here if the implementation
  // failed to load

  // Create the XML document, which is a <project> document.
  DOMDocumentType * doc_type =
    impl->createDocumentType (Project::TAGNAME, 0, Project::DTD);

  // Create the document and set the XML version.
  DOMDocument * doc = impl->createDocument (0, Project::TAGNAME, doc_type);
  doc->setXmlVersion (Project::XML_VERSION);

  // Initialize the GME id generator.
  ID_GENERATOR::instance ()->init (doc);

  // Get the root element of the document.
  DOMElement * root = doc->getDocumentElement ();

  // Set the project attributes (i.e, metaguid, paradigm,
  // cdate, and mdate).
  std::ostringstream metaguid;
  metaguid << "{" << guid << "}";

  root->setAttribute (::Utils::XStr ("metaguid"), ::Utils::XStr (metaguid.str ()));
  root->setAttribute (::Utils::XStr ("metaname"), paradigm);

#define TIMESTAMP_BUFSIZE 27
  ACE_TCHAR ts[TIMESTAMP_BUFSIZE];
  timestamp (ts, TIMESTAMP_BUFSIZE);

  root->setAttribute (::Utils::XStr ("cdate"), ::Utils::XStr (ts));

  // Initialize the project attributes.
  Project project (doc, false);
  project.name (::Utils::XStr::EMPTY_STRING);
  project.comment (::Utils::XStr::EMPTY_STRING);
  project.author (::Utils::XStr::EMPTY_STRING);

  // Create the root folder for the project.
  Folder root_folder (root, "RootFolder", 0);

  // Save the current state of the project.
  project.save (xmefile);

  return project;
}

//
// _open
//
Project Project::
_open (const ::Utils::XStr & location, const ::Utils::XStr & schema)
{
  using xercesc::XercesDOMParser;

  // Initailize the DOM parser.
  XercesDOMParser parser;
  parser.setValidationScheme(XercesDOMParser::Val_Always);
  parser.setDoNamespaces (true);
  parser.setCreateCommentNodes (false);
  parser.setCreateEntityReferenceNodes (false);
  parser.setIncludeIgnorableWhitespace (false);
  parser.setDoSchema (true);

  // Set the error handler.
  xercesc::HandlerBase * handler = new ::Utils::XML_Error_Handler ();
  parser.setErrorHandler (handler);

  // Set the entity resolver.
  xercesc::EntityResolver * resolver = new ::Utils::EntityResolver (schema);
  parser.setEntityResolver (resolver);

  // Parse the specified XML document.
  parser.parse (location);

  // Initialize a project variable.
  Project proj (parser.adoptDocument (), false);
  proj.xmefile_ = location;

  delete handler;
  delete resolver;

  return proj;
}

//
// save
//
bool Project::save (const ::Utils::XStr & xmefile)
{
  if (!this->save_i (xmefile))
    return false;

  this->xmefile_ = xmefile;
  return true;
}

//
// save_i
//
bool Project::save_i (const ::Utils::XStr & xmefile) const
{
  using namespace xercesc;

  // Update the modification time for the project.
#define TIMESTAMP_BUFSIZE 27
  ACE_TCHAR ts[TIMESTAMP_BUFSIZE];
  timestamp (ts, TIMESTAMP_BUFSIZE);

  DOMElement * root = this->doc_->getDocumentElement ();
  root->setAttribute (::Utils::XStr ("mdate"), ::Utils::XStr (ts));

  // Create the serializer for the document.
  DOMImplementation * impl = this->doc_->getImplementation ();
  DOMLSSerializer * serializer = impl->createLSSerializer ();

  // Initialize the serializer.
  if (serializer->getDomConfig ()->canSetParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true))
    serializer->getDomConfig ()->setParameter (XMLUni::fgDOMWRTFormatPrettyPrint, true);

  // Write the document to the URI.
  bool retval = serializer->writeToURI (this->doc_, xmefile);

  // Release the serializer.
  serializer->release ();

  return retval;
}

//
// close
//
void Project::close (void)
{
  if (0 != this->doc_)
  {
    // Release all the resource owned by this document.
    this->doc_->release ();
    this->doc_ = 0;
  }

  // Erase the target filename.
  this->xmefile_.clear ();
}

//
// operator =
//
const Project & Project::operator = (const Project & proj)
{
  // Take ownership of the document.
  this->doc_ = proj.doc_;
  this->xmefile_ = proj.xmefile_;

  return *this;
}

//
// attach
//
void Project::attach (xercesc::DOMDocument * proj, bool validate)
{
  if (validate)
  {
    using xercesc::DOMElement;

    DOMElement * e = this->doc_->getDocumentElement ();
    ::Utils::XStr tagname (e->getTagName (), false);

    if (tagname != Project::TAGNAME)
      throw Invalid_Cast ();
  }

  // Save the project.
  this->doc_ = proj;
}

//
// root_folder
//
Folder Project::root_folder (void) const
{
  using xercesc::DOMElement;
  using xercesc::DOMNode;
  using xercesc::DOMNodeList;

  // Get the folder element from the document.
  DOMElement * e = this->doc_->getDocumentElement ();
  DOMNodeList * list = e->getChildNodes ();

  // Locate the first RootFolder in the collection. Right now, we
  // are cheating and assuming the first folder is going to be
  // the RootFolder.
  ::Utils::XStr tagname;
  size_t length = list->getLength ();
  DOMNode * node = 0;

  for (size_t i = 0; i < length; ++ i)
  {
    // Get the next node. We are only interested in DOMNode items
    // that are of type DOMElement.
    node = list->item (i);

    if (node->getNodeType () == DOMNode::ELEMENT_NODE)
    {
      // Get the tagname for the next item in the list.
      e = dynamic_cast <DOMElement *> (node);
      tagname.set (e->getTagName (), false);

      // Check the tagname of the current element.
      if (tagname == Folder::TAGNAME)
        return Folder (e, false);
    }
  }

  return Folder ();
}

}

}
