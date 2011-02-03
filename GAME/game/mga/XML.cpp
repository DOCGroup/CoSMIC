// $Id$

#include "stdafx.h"
#include "XML.h"

#if !defined (__GAME_INLINE__)
#include "XML.inl"
#endif

#include "Project.h"

namespace GAME
{
namespace Mga
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
  CComVariant guid;
  CComBSTR paradigm, parversion, basename, version;
  CComBSTR filename (xmlfile.length (), xmlfile.c_str ());

  VERIFY_HRESULT (this->parser_->GetXMLInfo (filename,
                                             &paradigm,
                                             &parversion,
                                             &guid,
                                             &basename,
                                             &version));

  // Save information about the paradigm.
  if (paradigm)
  {
    CW2A tmp_paradigm (paradigm);
    info.paradigm_ = tmp_paradigm.m_psz;
  }
  else if (!info.paradigm_.empty ())
  {
    info.paradigm_.clear ();
  }

  // Save information about the paradigm version.
  if (parversion)
  {
    CW2A tmp_parversion (parversion);
    info.paradigm_version_ = tmp_parversion.m_psz;
  }
  else if (!info.paradigm_version_.empty ())
  {
    info.paradigm_version_.clear ();
  }

  // Save information about the project's basename.
  if (basename)
  {
    CW2A tmp_basename (basename);
    info.basename_ = tmp_basename.m_psz;
  }
  else if (!info.basename_.empty ())
  {
    info.basename_.clear ();
  }

  // Save information about the project version.
  if (version)
  {
    CW2A tmp_version (version);
    info.version_ = tmp_version.m_psz;
  }
  else if (!info.version_.empty ())
  {
    info.version_.clear ();
  }
}

//
// parse
//
void XML_Parser::parse (const std::string & xmlfile, Project & project)
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
write (const std::string & xmlfile, Project & project)
{
  CComBSTR bstr (xmlfile.length (), xmlfile.c_str ());

  VERIFY_HRESULT (
    this->dumper_->DumpProject (project.impl (), bstr));
}

}
}
