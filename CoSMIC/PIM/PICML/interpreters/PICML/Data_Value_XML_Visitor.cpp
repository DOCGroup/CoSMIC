// $Id: Data_Value_Visitor.cpp 1727 2008-01-25 01:35:07Z hillj $

#include "Data_Value_XML_Visitor.h"

using xercesc::LocalFileFormatTarget;
using xercesc::DOMImplementationRegistry;
using xercesc::DOMImplementationLS;
using xercesc::DOMException;
using xercesc::XMLUni;
using xercesc::XMLException;
using xercesc::DOMText;
using xercesc::DOMElement;

//sing xercesc::DOMDocument;
#include "Utils/Utils.h"
#include "Utils/XercesString.h"	
using Utils::XStr;



void 
PICML_Data_Value_XML_Visitor::push()
{
  this->curr_stack_.push (this->curr_);
}

void 
PICML_Data_Value_XML_Visitor::pop()
{
  if (!this->curr_stack_.empty())
    {
      this->curr_ = this->curr_stack_.top();
      this->curr_stack_.pop();
    }
  else
    {
      throw(std::exception());
    }
}

//
// PICML_Data_Value_XML_Visitor
//
PICML_Data_Value_XML_Visitor::PICML_Data_Value_XML_Visitor (xercesc::DOMElement *root,
						    xercesc::DOMDocument *doc)
  : root_ (root),
    curr_ (root),
    doc_ (doc)
{
}

//
// PICML_Data_Value_XML_Visitor
//
PICML_Data_Value_XML_Visitor::~PICML_Data_Value_XML_Visitor (void)
{
}

DOMElement* 
PICML_Data_Value_XML_Visitor::createSimpleContent (const std::string& name,
					       const std::string& value)
{
  DOMElement* pName = this->doc_->createElement (XStr (name.c_str()));
  DOMText* pValue = this->doc_->createTextNode (XStr (value.c_str()));
  pName->appendChild (pValue);
  return pName;
}

void PICML_Data_Value_XML_Visitor::
visit_PICML_String_Data_Value (const PICML_String_Data_Value &dv)
{
  this->curr_->appendChild (this->createSimpleContent ("string",
						       dv.value ()));
}

void PICML_Data_Value_XML_Visitor::
visit_PICML_Char_Data_Value (const PICML_Char_Data_Value &dv)
{
  this->curr_->appendChild (this->createSimpleContent ("char",
						       dv.value ()));  
}

void PICML_Data_Value_XML_Visitor::
visit_PICML_Short_Data_Value (const PICML_Short_Data_Value &dv)
{
  this->curr_->appendChild (this->createSimpleContent ("short",
						       dv.value ()));  
}

void PICML_Data_Value_XML_Visitor::
visit_PICML_UShort_Data_Value (const PICML_UShort_Data_Value &dv)
{
  this->curr_->appendChild (this->createSimpleContent ("ushort",
						       dv.value ()));  
}

void PICML_Data_Value_XML_Visitor::
visit_PICML_Long_Data_Value (const PICML_Long_Data_Value &dv)
{
  this->curr_->appendChild (this->createSimpleContent ("long",
						       dv.value ()));  
}

void PICML_Data_Value_XML_Visitor::
visit_PICML_ULong_Data_Value (const PICML_ULong_Data_Value &dv)
{
  this->curr_->appendChild (this->createSimpleContent ("ulong",
						       dv.value ()));  
}

void PICML_Data_Value_XML_Visitor::
visit_PICML_Enum_Data_Value (const PICML_Enum_Data_Value &dv)
{
  this->curr_->appendChild (this->createSimpleContent ("enum",
						       dv.value ()));  
}

void PICML_Data_Value_XML_Visitor::
visit_PICML_Boolean_Data_Value (const PICML_Boolean_Data_Value &dv)
{
  this->curr_->appendChild (this->createSimpleContent ("boolean",
						       dv.value ()));  
}

void PICML_Data_Value_XML_Visitor::
visit_PICML_Aggregate_Data_Value (const PICML_Aggregate_Data_Value &dv)
{
  for (PICML_Aggregate_Data_Value::const_iterator i = dv.begin ();
       i != dv.end (); ++i)
    {
      this->push ();
      DOMElement *ele = doc_->createElement (XStr ("member"));
      this->curr_ = ele;
      
      this->curr_->appendChild (this->createSimpleContent ("name",
							   i->first));
      
      ele = doc_->createElement (XStr ("value"));
      this->curr_ = ele;
      
      PICML_Data_Value *mdv = i->second;
      mdv->accept (*this);
      this->pop ();
    }
}

void PICML_Data_Value_XML_Visitor::
visit_PICML_Sequence_Data_Value (const PICML_Sequence_Data_Value &dv)
{
  for (PICML_Sequence_Data_Value::const_iterator i = dv.begin ();
       i != dv.end (); ++i)
    {
      this->push ();
      DOMElement *ele = doc_->createElement (XStr ("element"));
      this->curr_ = ele;

      PICML_Data_Value *mdv = *i;
      mdv->accept (*this);
      this->pop ();
    }
}

