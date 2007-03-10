#ifndef _CUTS_BE_NATURAL_LANG_EXPORT_H_
#define _CUTS_BE_NATURAL_LANG_EXPORT_H_

#include "cuts/config.h"

#if defined (PICML_HAS_DLL) && (PICML_HAS_DLL == 1)
#  if defined (CUTS_BE_NATURAL_LANG_BUILD_DLL)
#    define CUTS_BE_NATURAL_LANG_Export __declspec (dllexport)
#  else /* CUTS_BE_NATURAL_LANG_BUILD_DLL */
#    define CUTS_BE_NATURAL_LANG_Export __declspec (dllimport)
#  endif /* CUTS_BE_NATURAL_LANG_BUILD_DLL */
#else /* PICML_HAS_DLL == 1 */
#  define CUTS_BE_NATURAL_LANG_Export
#endif /* PICML_HAS_DLL == 1 */

#endif // !defined _CUTS_BE_NATURAL_LANG_EXPORT_H_
