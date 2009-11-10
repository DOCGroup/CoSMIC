// $Id$

#include "StdAfx.h"
#include "BON2Component.h"
#include "IDMLBonExtension.h"
#include "DependencyVisitor.h"
#include "IDLEmitVisitor.h"
#include "Utils/Utils.h"
#include "boost/bind.hpp"

#include <fstream>
#include <direct.h>

namespace BON
{

using namespace IDML;

//
// Component
//
Component::Component (void)
: m_bIsInteractive (false)
{
}

//
// Component
//
Component::~Component (void)
{
  if (m_project)
  {
    m_project->finalizeObjects ();
    finalize (m_project);
    m_project = NULL;
  }
}

//
// initialize
//
void Component::initialize (Project & project)
{
}

//
// finalize
//
void Component::finalize (Project & project)
{

}

//
// invoke
//
void Component::invoke (Project& project, const std::set<FCO>& setModels, long lParam)
{
  #ifdef SUPPORT_OLD_INVOKE
    Object focus;
    this->invokeEx (project, focus, setModels, lParam);
  #else
    if (m_bIsInteractive)
      ::AfxMessageBox ("This BON2 Component does not support the obsolete invoke mechanism!");
  #endif
}

//
// invokeEx
//
void Component::invokeEx (Project& project,
                          FCO& currentFCO,
                          const std::set <FCO>& setSelectedFCOs,
                          long lParam)
{
  // Get the output directory for the generated files.
  const std::string message ("Please specify the output directory");

  if (!Utils::getPath (message, this->outputPath_))
    return;

  // Set the namespace for the project.
  project->setNmsp ("PICML");

  if (setSelectedFCOs.empty ())
  {
    // Select all the objects of type IDML::File.
    std::set <Object> selected = project->findByKind ("File");

    // Process each of the object in the group.
    std::for_each (selected.begin (),
                   selected.end (),
                   boost::bind (&Component::processObjectAsFile, this, _1));

  }
  else
  {
    // The user selected a set of objects that would like to generate
    // IDL files for. We should honor that request. Right now, we only
    // support selecting a set of InterfaceDefinitions folders or a
    // set of File elements.
    std::for_each (setSelectedFCOs.begin (),
                   setSelectedFCOs.end (),
                   boost::bind (&Component::processFCOAsFile, this, _1));
  }

  if (this->m_bIsInteractive)
  {
    ::AfxMessageBox ("Successfully generated interface definitions files.",
                     MB_OK | MB_ICONINFORMATION);
  }
}

//
// processObjectAsFile
//
void Component::processObjectAsFile (const BON::Object & obj)
{
  IDML::File file (obj);

  if (file)
    this->processFile (file);
}

//
// processFCOAsFile
//
void Component::processFCOAsFile (const BON::FCO & fco)
{
  IDML::File file (fco);

  if (file)
    this->processFile (file);
}

//
// processFile
//
void Component::processFile (const IDML::File & file)
{
  if (file->isInLibrary ())
    return;

  // Make sure the dependencies exist for the file.
  DependencyVisitor depend_visitor;
  depend_visitor.visitOrderableImpl (file);

  // Preserves any directory structure that may have existed
  // with IDL files imported into the model.
  std::string filepath = file->getpath ();
  std::string dirpath = this->outputPath_ + (filepath == "" ? "" : "/" + filepath);

  // We don't care about the return value. Since we are passing
  // an absolute path, it will always get created unless it
  // already exists. Either way the stream gets a valid file path.
  (void) ::_mkdir (dirpath.c_str ());

  std::string raw_filename = file->getName ();
  std::string fullpath = dirpath
                         + "/"
                         + raw_filename
                         + ".idl";

  std::ofstream strm (fullpath.c_str ());

  if (strm.is_open ())
  {
    // Finally, generate the interface definition file.
    IDLEmitVisitor emit_visitor (strm);
    emit_visitor.visitOrderableImpl (file);

    // Close the file.
    strm.close ();
  }
  else if (this->m_bIsInteractive)
  {
    std::string msg = "Failed to open " + fullpath;
    ::AfxMessageBox (msg.c_str (), MB_OK | MB_ICONERROR);
  }
}

//
// objectInvokeEx
//
void Component::objectInvokeEx (Project& project,
                                Object& currentObject,
                                const std::set <Object>& setSelectedObjects,
                                long lParam)
{
  if (m_bIsInteractive)
    ::AfxMessageBox ("This BON2 Component does not support objectInvokeEx method!");
}

//
// getParameter
//
Util::Variant Component::getParameter (const std::string& strName)
{
  return Util::Variant ();
}

//
// setParameter
//
void Component::setParameter (const std::string& strName, const Util::Variant& varValue)
{

}

}; // namespace BON
