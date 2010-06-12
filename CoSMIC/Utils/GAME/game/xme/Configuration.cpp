// $Id$

#include "Configuration.h"
#include "ace/Env_Value_T.h"

namespace GAME
{
namespace XME
{
//
// Configuration
//
Configuration::Configuration (void)
{
  ACE_Env_Value <const char *> path ("COSMIC_ROOT", 0);

  // Need an extra step here because some C++ compilers can't
  // match ACE_CString's assignment from char* operator with
  // ACE_Env_Value's cast operator.
  const char * path_str = path;

  if (path_str != 0)
  {
    static const ::Utils::XStr includes_GME (L"/includes/GME/", false);

    this->schema_path_ = path_str;
    this->schema_path_.append (includes_GME);
  }
}

}
}