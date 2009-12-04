// $Id$

#include "StdAfx.h"
#include "DSL_View.h"
#include "DSL_Document.h"
#include <sstream>

IMPLEMENT_DYNCREATE (DSL_View, CRichEditView)

BEGIN_MESSAGE_MAP (DSL_View, CRichEditView)
  ON_WM_CREATE ()
END_MESSAGE_MAP ()

namespace DSL
{
//
// streamin_callback
//
static DWORD CALLBACK
streamin_callback (DWORD_PTR cookie, LPBYTE buffer, LONG size, LONG * bytes_xfered)
{
  // Extract the stream from the cookie.
  std::istream * stream = reinterpret_cast <std::istream *> (cookie);

  if (0 == stream)
    return -1;

  // Read the next chunk of data into the buffer.
  stream->read ((char *)buffer, size);

  // Get the number of bytes transfered.
  *bytes_xfered = stream->gcount ();
  return 0;
}

}

//
// DSL_View
//
DSL_View::DSL_View (void)
{

}

//
// ~DSL_View
//
DSL_View::~DSL_View (void)
{

}

//
// OnCreate
//
int DSL_View::OnCreate (LPCREATESTRUCT create)
{
  // Update the style of the view.
  create->style |= ES_AUTOHSCROLL |
                   ES_AUTOVSCROLL |
                   ES_MULTILINE |
                   ES_CONTINUOUS;

  // Pass control to the base class to finish creation.
  return CRichEditView::OnCreate (create);
}

//
// OnInitialUpdate
//
void DSL_View::OnInitialUpdate (void)
{
  // Disable word wrapping for the document.
  this->m_nWordWrap = CRichEditView::WrapNone;
  this->WrapChanged ();

  // Update the view with the contents of the document.
  CDocument * document = this->GetDocument ();
  DSL_Document * dsl_document = dynamic_cast <DSL_Document *> (document);

  // Get the richedit control from the view.
  CRichEditCtrl & richedit = this->GetRichEditCtrl ();

  // Set the default font to Courier New.
  CHARFORMAT2 char_format;
  char_format.cbSize = sizeof (CHARFORMAT2);

  // Get the default char format for the control.
  richedit.GetDefaultCharFormat (char_format);

  char_format.dwMask = CFM_FACE | CFM_EFFECTS2;
  char_format.dwEffects ^= CFE_BOLD;
  std::strcpy (char_format.szFaceName, "Courier New");

  richedit.SetDefaultCharFormat (char_format);

  // Stream the document to a temporary stream.
  std::stringstream stream;

  if (0 == dsl_document->serialize (stream))
  {
    // Update the control with the stream's contents.
    EDITSTREAM editstream;
    editstream.dwCookie = reinterpret_cast <DWORD_PTR> (&stream);
    editstream.pfnCallback = DSL::streamin_callback;

    richedit.StreamIn (SF_TEXT, editstream);
  }
}
