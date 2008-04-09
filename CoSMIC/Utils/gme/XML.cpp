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
XML_Parser::XML_Parser (void)
{
  VERIFY_HRESULT (this->parser_.CoCreateInstance (L"Mga.MgaParser"));
}

//
// get_info
//
void XML_Parser::
get_info (const std::string & xmlfile, XML_Info & info)
{
  CComBSTR filename (xmlfile.length (), xmlfile.c_str ());
  CComBSTR paradigm, parversion, basename, version;
  VARIANT guid;

  VERIFY_HRESULT (this->parser_->GetXMLInfo (filename, 
                                             &paradigm, 
                                             &parversion, 
                                             &guid, 
                                             &basename, 
                                             &version));

  info.paradigm_ = CW2A (paradigm).m_psz;
  info.paradigm_version_ = CW2A (parversion).m_psz;
  info.basename_ = CW2A (basename).m_psz;
  info.version_ = CW2A (version).m_psz;
}

//
// parse
//
void XML_Parser::parse (const std::string & xmlfile, GME::Project & project)
{
  CComBSTR bstr (xmlfile.length (), xmlfile.c_str ());

  VERIFY_HRESULT (
    this->parser_->ParseProject (project.impl (), bstr));
}

///////////////////////////////////////////////////////////////////////////////
// XML_Dumper

//
// XML_Dumper
//
XML_Dumper::XML_Dumper (void)
{
  VERIFY_HRESULT (this->dumper_.CoCreateInstance (L"Mga.MgaDumper"));
}

//
// write
//
void XML_Dumper::
write (const std::string & xmlfile, GME::Project & project)
{
  CComBSTR bstr (xmlfile.length (), xmlfile.c_str ());

  VERIFY_HRESULT (
    this->dumper_->DumpProject (project.impl (), bstr));
}

}
