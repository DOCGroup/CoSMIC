// $Id$

#include "Registrar.h"

#if !defined (__GAME_INLINE__)
#include "Registrar.inl"
#endif

#include "MgaUtil.h"
#include "Parser.hpp"
#include "game/Exception.h"

namespace GAME
{
namespace utils
{
//
// Registrar
//
Registrar::Registrar (void)
: impl_ (0)
{
  CComPtr <IMgaRegistrar> ptr;
  ptr.CoCreateInstance (L"Mga.MgaRegistrar");
  this->impl_ = ptr.Detach ();
}


//
// Registrar
//
GAME_INLINE
Registrar::Registrar (const Registrar & r)
: impl_ (0)
{
  r.impl_->AddRef ();
  this->impl_ = r.impl_;
}

//
// ~Registrar
//
Registrar::~Registrar (void)
{
  this->impl_->Release ();
}


//
// icon_path
//
std::string Registrar::icon_path (ACCESS_MODE mode) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->impl_->get_IconPath ((regaccessmode_enum)mode, &bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// query_paradigm
//
std::string Registrar::
get_paradigm_connstr (const std::string & name, ACCESS_MODE mode) const
{
  CComBSTR connstr;
  CComVariant guid;
  CComBSTR paradigm (name.length (), name.c_str ());

  VERIFY_HRESULT (this->impl_->QueryParadigm (paradigm,
                                              &connstr,
                                              &guid,
                                              (regaccessmode_enum)mode));

  CW2A tempstr (connstr);
  return tempstr.m_psz;
}

///////////////////////////////////////////////////////////////////////////////
// Icon_Manager

//
// refresh_paths
//
bool Icon_Manager::
refresh (const GAME::Project & project, 
         const Registrar & r, 
         Registrar::ACCESS_MODE mode)
{
  // Extract paths from registrar and tokenize the string.
  std::string path = r.icon_path (mode);
  
  using boost::phoenix::ref;
  namespace qi = boost::spirit::qi;
  namespace ascii = boost::spirit::ascii;

  // Initialize the parser.
  PathParserConfig config (project);
  PathParser <std::string::const_iterator> grammar (config, this->paths_);

  return qi::phrase_parse (path.begin (), 
                           path.end (), 
                           grammar, 
                           ascii::space);
}

//
// lookup_icon
//
bool Icon_Manager::
lookup_icon (const std::string & icon_filename, 
             std::string & out_filename)
{
  bool retval = false;
  std::vector <std::string>::const_iterator 
    iter = this->paths_.begin (), iter_end = this->paths_.end ();

  std::string filename;
  HANDLE handle = INVALID_HANDLE_VALUE;

  for (; iter != iter_end; ++ iter)
  {
    WIN32_FIND_DATA finddata;
    filename = *iter + "\\" + icon_filename;

    handle = ::FindFirstFile (filename.c_str (), &finddata);

    if (handle != INVALID_HANDLE_VALUE)
    {
      retval = true;
      out_filename = filename;
      break;
    }
  }

  ::FindClose (handle);
  return retval;
}

}
}
