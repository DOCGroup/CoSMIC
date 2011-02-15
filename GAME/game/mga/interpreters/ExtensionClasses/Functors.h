// -*- C++ -*-

#ifndef _GAME_EXTENSION_CLASSES_FUNCTORS_H_
#define _GAME_EXTENSION_CLASSES_FUNCTORS_H_

#include <string>
#include <ostream>

struct include_t
{
  include_t (const std::string & str, bool sys_header = false);

  const std::string & str_;

  const bool sys_header_;
};

struct function_header_t
{
  function_header_t (const std::string & str);

  const std::string & str_;
};

std::ostream & operator << (std::ostream & out, const include_t & i);
std::ostream & operator << (std::ostream & out, const function_header_t & f);

#endif
