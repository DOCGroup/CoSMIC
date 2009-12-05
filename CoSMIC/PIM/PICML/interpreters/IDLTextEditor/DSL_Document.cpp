// $Id$

#include "StdAfx.h"
#include "DSL_Document.h"
#include "DSL_Serializer.h"
#include "DSL_Deserializer.h"
#include "BONImpl.h"

IMPLEMENT_DYNCREATE (DSL_Document, CRichEditDoc)

BEGIN_MESSAGE_MAP (DSL_Document, CRichEditDoc)
  ON_COMMAND (ID_FILE_SAVE, OnFileSave)
END_MESSAGE_MAP ()

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
DSL_Document::DSL_Document (const BON::Object & obj)
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

}

//
// CreateClientItem
//
CRichEditCntrItem * DSL_Document::CreateClientItem (REOBJECT * obj) const
{
  return new CRichEditCntrItem (obj, const_cast <DSL_Document *> (this));
}

//
// OnSaveDocument
//
void DSL_Document::OnFileSave (void)
{
  ::AfxMessageBox ("OnFileSave");
}

//
// serialize
//
int DSL_Document::serialize (std::ostream & stream)
{
  if (0 == this->serializer_)
    return -1;

  int retval = 0;

  if (this->obj_)
  {
    // Serialize the object to the stream.
    retval = this->serializer_->serialize (this->obj_, stream);

    // Set the title to the object's name.
    if (0 == retval)
      this->SetTitle (this->obj_->getName ().c_str ());
  }

  return 0;
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
  return this->obj_->isReadOnly () || this->obj_->isInLibrary ();
}
