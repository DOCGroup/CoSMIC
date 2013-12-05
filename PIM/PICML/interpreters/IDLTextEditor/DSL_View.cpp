// $Id$

#include "StdAfx.h"
#include "DSL_View.h"
#include "DSL_Document.h"

IMPLEMENT_DYNCREATE (DSL_View, CRichEditView)

BEGIN_MESSAGE_MAP (DSL_View, CRichEditView)
  ON_WM_CREATE ()
END_MESSAGE_MAP ()

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
  CDocument * document = this->GetDocument ();
  DSL_Document * dsl_document = dynamic_cast <DSL_Document *> (document);
  CRichEditCtrl & richedit = this->GetRichEditCtrl ();

  // Disable word wrapping for the document.
  this->m_nWordWrap = CRichEditView::WrapNone;
  this->WrapChanged ();

  // Set readonly flag for richedit control, if necessary.
  if (dsl_document->is_readonly ())
    richedit.SetReadOnly ();

  // Set the default font to Courier New.
  CHARFORMAT2 char_format;
  char_format.cbSize = sizeof (CHARFORMAT2);

  // Get the default char format for the control.
  richedit.GetDefaultCharFormat (char_format);

  char_format.dwMask = CFM_FACE | CFM_EFFECTS2;
  char_format.dwEffects ^= CFE_BOLD;
  std::strcpy (char_format.szFaceName, "Courier New");

  richedit.SetDefaultCharFormat (char_format);

  // Stream the document into the view.
  //
  // @note There has to be a way to stream the document into
  // the view without manaully doing it this way. The framework
  // has to support this functionality some kind of way!!
  dsl_document->OnInitialUpdate ();
}
