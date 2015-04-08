#include "StdAfx.h"
#include "DSL_DocTemplate.h"
#include "DSL_Document.h"
#include "DSL_TextEditor.h"
#include "DSL_View.h"
#include "Resource.h"

//
// DSL_DocTemplate
//
DSL_DocTemplate::DSL_DocTemplate (void)
: CSingleDocTemplate (IDR_MAINFRAME,
                      RUNTIME_CLASS (DSL_Document),
                      RUNTIME_CLASS (DSL_TextEditor),
                      RUNTIME_CLASS (DSL_View))
{

}

//
// ~DSL_DocTemplate
//
DSL_DocTemplate::~DSL_DocTemplate (void)
{

}

//
// CreateNewFrame
//
CFrameWnd * DSL_DocTemplate::
CreateNewFrame (CWnd * parent, CDocument* document, CFrameWnd* other)
{
  if (0 != document)
    ASSERT_VALID (document);

  // must have a resource ID to load from
  ASSERT(m_nIDResource != 0);

  CCreateContext context;
  context.m_pCurrentFrame = other;
  context.m_pCurrentDoc = document;
  context.m_pNewViewClass = m_pViewClass;
  context.m_pNewDocTemplate = this;

  if (0 == m_pFrameClass)
  {
    TRACE (traceAppMsg,
           0,
           "Error: you must override CDocTemplate::CreateNewFrame.\n");

    ASSERT (FALSE);
    return NULL;
  }

  // User the frame class to create a new object.
  DSL_TextEditor * frame = new DSL_TextEditor (parent);

  if (0 == context.m_pNewViewClass)
    TRACE (traceAppMsg,
           0,
           "Warning: creating frame with no default view.\n");

  // create new from resource
  if (!frame->LoadFrame (m_nIDResource,
                         WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,
                         parent,
                         &context))
  {
    TRACE (traceAppMsg,
           0,
           "Warning: CDocTemplate couldn't create a frame.\n");

    // frame will be deleted in PostNcDestroy cleanup
    return 0;
  }

  return frame;
}
