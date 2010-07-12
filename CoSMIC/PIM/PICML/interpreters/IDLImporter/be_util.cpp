
//=============================================================================
/**
 *  @file    be_util.cpp
 *
 *  $Id$
 *
 *  Static helper methods used by multiple visitors.
 *
 *
 *  @author Jeff Parsons
 */
//=============================================================================

#include "be_util.h"
#include "be_extern.h"

#include "ast_generator.h"

#include "ace/Log_Msg.h"

// Prepare an argument for a BE.
void
be_util::prep_be_arg (char *)
{
}

void
be_util::arg_post_proc (void)
{
}

void
be_util::usage (void)
{
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -x <filename>\t\tName of the generated file.")
      ACE_TEXT (" Default is \"PICML_default_xme_file.xme\".\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -r <pathname>\t\tPath of the directory to iterate")
      ACE_TEXT (" over recursively, processing each IDL file found.\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -o <dir>\t\tOutput directory for the generated file.")
      ACE_TEXT (" Default is current directory\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -i <filepath>\t\tPath to XME input file.")
      ACE_TEXT (" Default is no XME input file\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -l <filepath>\t\tAttach specified file as a ")
      ACE_TEXT ("library\n")
    ));
  ACE_DEBUG ((
      LM_DEBUG,
      ACE_TEXT (" -m <filepath>\t\tPath to GME's mga.dtd file.")
      ACE_TEXT (" Default is c:\\Program Files\\GME\n")
    ));

  //ACE_DEBUG ((
  //    LM_DEBUG,
  //    ACE_TEXT (" -Sp \t\t\tSuppress pruning of elements removed")
  //    ACE_TEXT (" in modified IDL.")
  //    ACE_TEXT (" Default is to do pruning\n")
  //  ));
}

AST_Generator *
be_util::generator_init (void)
{
  AST_Generator *gen = 0;
  ACE_NEW_RETURN (gen,
                  AST_Generator,
                  0);
  return gen;
}

