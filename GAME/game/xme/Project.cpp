// $Id$

#include "Project.h"

#if !defined (__GAME_INLINE__)
#include "Project.inl"
#endif

#include "Folder.h"
#include "Registry.h"
#include "GME_ID_Generator.h"
#include "ID_Generator_Repo.h"
#include "Library_Importer.h"

#include "game/xml/Error_Handler.h"
#include "game/xml/Entity_Resolver.h"

#include "boost/bind.hpp"

#include "ace/OS_Memory.h"
#include "ace/OS_NS_stdio.h"
#include "ace/OS_NS_time.h"
#include "ace/CORBA_macros.h"

#include <sstream>

#include "xercesc/parsers/XercesDOMParser.hpp"
#include "xercesc/framework/Wrapper4InputSource.hpp"
#include "xercesc/framework/LocalFileInputSource.hpp"
#include "xercesc/dom/DOM.hpp"

namespace GAME
{
namespace XME
{
const GAME::Xml::String Project::TAGNAME ("project");
const GAME::Xml::String Project::DTD ("mga.dtd");
const GAME::Xml::String Project::XML_VERSION ("1.0");
const GAME::Xml::String Project::ELEMENT_NAME ("name");
const GAME::Xml::String Project::ELEMENT_AUTHOR ("author") ;
const GAME::Xml::String Project::ELEMENT_COMMENT ("comment");
const GAME::Xml::String Project::ROOT_FOLDER ("RootFolder");
const GAME::Xml::String Project::ATTR_LIBREF ("libref");

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
// Project
//
GAME_INLINE
Project::
Project (xercesc::DOMDocument * doc, const Configuration * config)
: doc_ (doc),
  config_ (config)
{
  GAME_XME_ID_GENERATOR_REPO->open (doc);
}

//
// _create
//
Project Project::
_create (const GAME::Xml::String & xmefile,
         const GAME::Xml::String & paradigm,
         const GAME::Xml::String & guid,
         const Configuration * config)
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

  // Get the root element of the document.
  DOMElement * root = doc->getDocumentElement ();

  // Set the project attributes (i.e, metaguid, paradigm,
  // cdate, and mdate).
  std::ostringstream metaguid;
  metaguid << "{" << guid << "}";

  root->setAttribute (GAME::Xml::String ("metaguid"), GAME::Xml::String (metaguid.str ()));
  root->setAttribute (GAME::Xml::String ("metaname"), paradigm);

#define TIMESTAMP_BUFSIZE 27
  ACE_TCHAR ts[TIMESTAMP_BUFSIZE];
  timestamp (ts, TIMESTAMP_BUFSIZE);

  root->setAttribute (GAME::Xml::String ("cdate"), GAME::Xml::String (ts));

  // Initialize the project attributes.
  Project project (doc, config);
  project.name (GAME::Xml::String::EMPTY_STRING);
  project.comment (GAME::Xml::String::EMPTY_STRING);
  project.author (GAME::Xml::String::EMPTY_STRING);

  // Create the root folder for the project.
  Folder root_folder (root, ROOT_FOLDER, 0);

  // Save the current state of the project.
  project.save (xmefile);

  return project;
}

//
// _open
//
Project Project::
_open (const GAME::Xml::String & location, const Configuration * config)
{
  using namespace xercesc;

  XercesDOMParser parser;
  parser.setValidationScheme(XercesDOMParser::Val_Always);
  parser.setDoNamespaces (true);
  parser.setCreateCommentNodes (false);
  parser.setCreateEntityReferenceNodes (false);
  parser.setIncludeIgnorableWhitespace (false);
  parser.setDoSchema (true);

  // Set the error handler.
  using GAME::Xml::Xml_Error_Handler;
  std::auto_ptr <xercesc::HandlerBase> handler (new Xml_Error_Handler ());
  parser.setErrorHandler (handler.get ());

  // Set the entity resolver.
  using GAME::Xml::Entity_Resolver;
  std::auto_ptr <xercesc::EntityResolver> resolver (new Entity_Resolver (config->schema_path_));
  parser.setEntityResolver (resolver.get ());

  // Parse the specified XML document.
  parser.parse (location);

  // Initialize a project variable.
  Project proj (parser.adoptDocument (), config);
  proj.xmefile_ = location;

  return proj;
}

//
// save
//
bool Project::save (const GAME::Xml::String & xmefile)
{
  if (!this->save_i (xmefile))
    return false;

  this->xmefile_ = xmefile;
  return true;
}

//
// save_i
//
bool Project::save_i (const GAME::Xml::String & xmefile) const
{
  using namespace xercesc;

  // Update the modification time for the project.
#define TIMESTAMP_BUFSIZE 27
  ACE_TCHAR ts[TIMESTAMP_BUFSIZE];
  timestamp (ts, TIMESTAMP_BUFSIZE);

  DOMElement * root = this->doc_->getDocumentElement ();
  root->setAttribute (GAME::Xml::String ("mdate"), GAME::Xml::String (ts));

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
    // Remove the project from the id generator repo.
    GAME_XME_ID_GENERATOR_REPO->close (this->doc_);

    // Release all the resource owned by this document.
    this->doc_->release ();
    this->doc_ = 0;
  }

  // Erase the target filename.
  this->xmefile_.clear ();
  this->config_ = 0;

}

//
// operator =
//
const Project & Project::operator = (const Project & proj)
{
  // Take ownership of the document.
  this->doc_ = proj.doc_;
  this->xmefile_ = proj.xmefile_;
  this->config_ = proj.config_;

  return *this;
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
  GAME::Xml::String tagname;
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

struct find_by_libid_t
{
  find_by_libid_t (const GAME::Xml::String & libid)
    : libid_ (libid)
  {

  }

  template <typename T>
  bool operator () (T t) const
  {
    using GAME::Xml::String;

    static const String LibraryId ("LibraryId");

    try
    {
      Registry registry (t);
      const Registry_Node libid_node = registry.child (LibraryId, false);
      const String libid (libid_node.value (), false);

      return libid == this->libid_;
    }
    catch (const Not_Found &)
    {
      return false;
    }
  }

private:
  const GAME::Xml::String & libid_;
};

//
// attach_library
//
Library Project::attach_library (const GAME::Xml::String & libpath)
{
  GAME::Xml::String xmefile (libpath);
  xmefile.append (GAME::Xml::String (".xme"));

  // Make sure we have the fullpath for the library.
  char abspath[MAXPATHLEN];
  std::string filename =
    ACE_OS::realpath (xmefile.to_string ().c_str (), abspath);

  std::replace (filename.begin (),
                filename.end (),
                '\\',
                '/');

  xmefile = filename.c_str ();

  // Let the project's root folder adopt the library's root
  using namespace xercesc;

  Project lib_project = Project::_open (xmefile, this->config_);
  Folder lib_root_folder = lib_project.root_folder ();

  try
  {
    using GAME::Xml::String;
    static const String LibraryId ("LibraryId");

    // Get the library id for the attaching model.
    Registry registry (lib_root_folder);
    const Registry_Node libid_node = registry.child (LibraryId, false);
    const String libid (libid_node.value (), false);

    // Make sure this library does not already exist. We do not want
    // to attached it more than one to the project since it can cause
    // problems in the long run.
    std::vector <Library> libs;

    if (this->attached_libraries (libs))
    {
      std::vector <Library>::iterator
        result = std::find_if (libs.begin (),
                               libs.end (),
                               find_by_libid_t (libid));

      if (result != libs.end ())
      {
        lib_project.close ();
        return *result;
      }
    }
  }
  catch (const Not_Found &)
  {
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("*** warning: %s does not have a library id; ")
                ACE_TEXT ("automatically attaching...\n"),
                filename.c_str ()));
  }

  // Since we did not find the library, we can begin process. ;-)
  Library_Importer importer (GAME_XME_ID_GENERATOR_REPO->get (this->doc_));
  importer.import (lib_root_folder);

  // Attach this document as a library.
  DOMNode * node = this->doc_->importNode (lib_root_folder.ptr (), true);
  DOMElement * e = dynamic_cast <DOMElement *> (node);

  Folder root_folder = this->root_folder ();
  root_folder.ptr ()->appendChild (e);

  lib_project.close ();
  return Library (e, xmefile, false);
}

//
// attached_libraries
//
size_t Project::attached_libraries (std::vector <Library> & libs)
{
  Folder root = this->root_folder ();
  static const GAME::Xml::String metaname ("RootFolder");

  std::vector <Folder> temp;

  if (root.children (metaname, temp))
  {
    std::vector <Folder>::iterator
      iter = temp.begin (), iter_end = temp.end ();

    for (; iter != iter_end; ++ iter)
      libs.push_back (Library (iter->ptr (), true));
  }

  return libs.size ();
}

}
}
