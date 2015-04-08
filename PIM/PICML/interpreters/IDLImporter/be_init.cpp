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

//
// BE_init
//
IDL_TO_PICML_BE_Export
int BE_init (int &, char *[])
{
  u_long default_mask =
    LM_EMERGENCY | LM_ALERT | LM_CRITICAL | LM_ERROR |
    LM_WARNING | LM_NOTICE | LM_DEBUG;

  ACE_Log_Msg::instance ()->priority_mask (default_mask, ACE_Log_Msg::PROCESS);

  // Initialize BE global data object.
  ACE_NEW_RETURN (be_global,
                  BE_GlobalData,
                  -1);

  return 0;
}

//
// BE_post_init
//
IDL_TO_PICML_BE_Export
void BE_post_init (char *files[], long nfiles)
{
  idl_global->multi_file_input (true);

  // We should enable you to customize the location (i.e., target
  // folder name) via a command-line argument.
  be_global->initialize ();
  be_global->files ().create_files (files, nfiles, "InterfaceDefinitions");
}

