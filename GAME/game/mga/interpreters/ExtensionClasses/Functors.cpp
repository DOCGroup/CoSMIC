// $Id$

#include "StdAfx.h"
#include "Functors.h"

//
// include_t
//
include_t::include_t (const std::string & str, bool sys_header)
: str_ (str),
  sys_header_ (sys_header)
{

}

//
// function_header_t
//
function_header_t::function_header_t (const std::string & str)
: str_ (str)
{

}

//
// operator <<
//
std::ostream & operator << (std::ostream & out, const include_t & i)
{
  char open_tag = i.sys_header_ ? '<' : '"';
  char close_tag = i.sys_header_ ? '>' : '"';

  out << "#include " << open_tag << i.str_ << close_tag << std::endl;
  return out;
}

//
// operator <<
//
std::ostream & operator << (std::ostream & out, const function_header_t & f)
{
  out
    << "//" << std::endl
    << "// " << f.str_ << std::endl
    << "//" << std::endl;

  return out;
}
