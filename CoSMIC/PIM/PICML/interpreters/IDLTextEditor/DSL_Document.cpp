// $Id$

#include "StdAfx.h"
#include "DSL_Document.h"
#include "DSL_Serializer.h"
#include "DSL_Deserializer.h"
#include <sstream>

IMPLEMENT_DYNCREATE (DSL_Document, CRichEditDoc)

BEGIN_MESSAGE_MAP (DSL_Document, CRichEditDoc)
  ON_COMMAND (ID_FILE_SAVE, OnFileSave)
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

//
// streamout_callback
//
static DWORD CALLBACK
streamout_callback (DWORD_PTR cookie, LPBYTE buffer, LONG size, LONG * bytes_xfered)
{
  // Extract the stream from the cookie.
  std::ostream * stream = reinterpret_cast <std::ostream *> (cookie);

  if (0 == stream)
    return -1;

  // Read the next chunk of data into the buffer.
  stream->write ((char *)buffer, size);
  *bytes_xfered = size;

  return 0;
}
}

//
// DSL_Document
//
DSL_Document::DSL_Document (void)
: serializer_ (0),
  deserializer_ (0)
{

}

//
// DSL_Document
//
DSL_Document::DSL_Document (const ::GME::Object & obj)
: obj_ (obj),
  serializer_ (0),
  deserializer_ (0)
{

}

//
// ~DSL_Document
//
DSL_Document::~DSL_Document (void)
{
  this->obj_.release ();
}

//
// CreateClientItem
//
CRichEditCntrItem * DSL_Document::CreateClientItem (REOBJECT * obj) const
{
  return new CRichEditCntrItem (obj, const_cast <DSL_Document *> (this));
}

//
// OnFileSave
//
void DSL_Document::OnFileSave (void)
{
  if (0 == this->deserializer_ || !this->obj_)
    return;

  // Get a reference to the RichEdit control.
  CRichEditCtrl & richedit = this->GetView ()->GetRichEditCtrl ();

  // Stream information out of the control.
  std::stringstream stream;
  EDITSTREAM editstream;
  editstream.dwCookie = reinterpret_cast <DWORD_PTR> (&stream);
  editstream.pfnCallback = DSL::streamout_callback;

  richedit.StreamOut (SF_TEXT, editstream);

  // Now, deserialize the stream to its object format.
  this->deserializer_->deserialize (stream, this->obj_);
}

//
// OnInitialUpdate
//
void DSL_Document::OnInitialUpdate (void)
{
  // We cannot continue if there is no serializer.
  if (0 == this->serializer_ || !this->obj_)
    return;

  // Serialize the object to the stream.
  std::stringstream stream;
  int retval = this->serializer_->serialize (this->obj_, stream);

  if (0 != retval)
    return;

  // Set the title to the object's name.
  this->SetTitle (this->obj_.name ().c_str ());

  // Get a reference to the RichEdit control.
  CRichEditCtrl & richedit = this->GetView ()->GetRichEditCtrl ();

  // Stream information into the control.
  EDITSTREAM editstream;
  editstream.dwCookie = reinterpret_cast <DWORD_PTR> (&stream);
  editstream.pfnCallback = DSL::streamin_callback;

  richedit.StreamIn (SF_TEXT, editstream);
}

//
// configure
//
void DSL_Document::
configure (DSL_Serializer * serializer, DSL_Deserializer * deserializer)
{
  this->serializer_ = serializer;
  this->deserializer_ = deserializer;
}

//
// is_readonly
//
bool DSL_Document::is_readonly (void) const
{
  return this->obj_.is_lib_object () || this->obj_.readonly_access ();
}
