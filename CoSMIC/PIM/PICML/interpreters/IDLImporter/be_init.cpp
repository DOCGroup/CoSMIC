// $Id$

#include "global_extern.h"
#include "be_extern.h"
#include "../../tao/Version.h"

IDL_TO_PICML_BE_Export void
BE_version (void)
{
  ACE_DEBUG ((LM_DEBUG,
              "%s %s\n",
              ACE_TEXT ("TAO_IDML_BE, version"),
              ACE_TEXT (TAO_VERSION)));
}

IDL_TO_PICML_BE_Export int
BE_init (int &, char *[])
{
  return 0;
}

IDL_TO_PICML_BE_Export void
BE_post_init (const char *files[], long nfiles)
{
  be_global->xerces_init ();
  be_global->cache_files (files, nfiles);
  be_global->init_ids (be_global->root_folder ());
}

