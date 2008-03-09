// $Id$

#include "stdafx.h"
#include "XML.h"

#if !defined (__GME_INLINE__)
#include "XML.inl"
#endif

#include "Project.h"

namespace GME
{
///////////////////////////////////////////////////////////////////////////////
// XML_Parser

//
// XML_Parser
//
XML_Parser::XML_Parser (GME::Project & project)
: project_ (project)
{
  VERIFY_HRESULT (this->parser_.CoCreateInstance (L"Mga.MgaParser"));
}

//
// parse
//
void XML_Parser::parse (const std::string & xmlfile)
{
  CComBSTR bstr (xmlfile.length (), xmlfile.c_str ());

  VERIFY_HRESULT (
    this->parser_->ParseProject (this->project_.impl (), bstr));
}

///////////////////////////////////////////////////////////////////////////////
// XML_Dumper

//
// XML_Dumper
//
XML_Dumper::XML_Dumper (GME::Project & project)
: project_ (project)
{
  VERIFY_HRESULT (this->dumper_.CoCreateInstance (L"Mga.MgaDumper"));
}

//
// write
//
void XML_Dumper::write (const std::string & xmlfile)
{
  CComBSTR bstr (xmlfile.length (), xmlfile.c_str ());

  VERIFY_HRESULT (
    this->dumper_->DumpProject (this->project_.impl (), bstr));
}

}
