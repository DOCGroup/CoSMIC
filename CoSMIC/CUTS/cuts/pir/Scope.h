#ifndef _CUTS_PIR_SCOPE_H_
#define _CUTS_PIR_SCOPE_H_

#include "cuts/config.h"
#include <stack>
#include <string>

namespace CUTS_PIR
{
  class CUTS_Export Scope :
    public std::stack <std::string>
  {
  public:
    Scope (void);

    ~Scope (void);

    const char * c_str (const char * seperator);

  private:
    static std::string str_;
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Scope.inl"
#endif

#endif  // !defined _CUTS_PIR_SCOPE_H_
