// $Id$

#include "StdAfx.h"
#include "BON2Component.h"
#include "DSL_DocTemplate.h"
#include "DSL_Document.h"
#include "DSL_TextEditor.h"
#include "IDL_File_Serializer.h"
#include "IDL_File_Deserializer.h"

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
  if (!this->m_project)
    return;

  this->m_project->finalizeObjects ();
  this->finalize (m_project);
  this->m_project = NULL;
}

//
// initialize
//
void Component::initialize (Project & project)
{
  // Load the RichEdit2 library.
  if (!::AfxInitRichEdit2 ())
    ::AfxMessageBox ("Failed to load RichEdit library");

  // Document template for the component/intepreter.
  this->template_.reset (new DSL_DocTemplate ());
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
  if (setSelectedFCOs.empty ())
  {
    long flags = MB_OK | MB_ICONWARNING;
    ::AfxMessageBox ("You must select a File element first.", flags);
  }
  else if (setSelectedFCOs.size () > 1)
  {
    long flags = MB_OK | MB_ICONWARNING;
    ::AfxMessageBox ("You may select only one File element.", flags);
  }
  else
  {
    // Set the namespace for the project.
    project->setNmsp ("PICML");

    IDML::File file (*setSelectedFCOs.begin ());
    this->processFile (file);
  }
}

//
// processFile
//
void Component::processFile (const IDML::File & file)
{
  // Create a new document for the model element.
  GAME::Mga::Object obj (file->getObjectI ());
  DSL_Document * dsl_doc = new DSL_Document (obj);


  // Configure the document serializer and deserializer.
  IDL_File_Serializer idl_file_serializer;
  IDL_File_Deserializer idl_file_deserializer;
  dsl_doc->configure (&idl_file_serializer, &idl_file_deserializer);

  // Create a new frame for the document. We are going to use
  // the new document for the initial view.
  CWnd * mainwnd = ::AfxGetMainWnd ();
  CFrameWnd * frame = this->template_->CreateNewFrame (mainwnd, dsl_doc, 0);

  if (0 != frame)
  {
    // Perform the initial update to the frame.
    frame->InitialUpdateFrame (dsl_doc, true);

    // Extract the editor and run the modal loop.
    DSL_TextEditor * editor = dynamic_cast <DSL_TextEditor *> (frame);

    if (0 != editor->DoModal ())
      ::AfxMessageBox ("Failed to create TextEditor", MB_OK | MB_ICONERROR);

    // Destroy the frame before continuing.
    frame->DestroyWindow ();
  }
  else
    ::AfxMessageBox ("Failed to create window", MB_OK | MB_ICONERROR);
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
