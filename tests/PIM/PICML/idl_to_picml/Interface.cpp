// $Id$

#include "InterfaceC.h"
#include "ace/Log_Msg.h"
#include "ace/Get_Opt.h"
#include <typeinfo.h>

const char *noun_ior = "file://noun.ior";

int
parse_args (int argc, char *argv[])
{
  ACE_Get_Opt get_opts (argc, argv, "k:p:");
  int c;
  while ((c = get_opts ()) != -1)
    {
      switch (c)
        {
          case 'k':
            noun_ior = get_opts.opt_arg ();
            break;

          case '?':  // display help for use of the server.
          default:
            ACE_ERROR_RETURN ((LM_ERROR,
                               "usage:  %s\n"
                               "-k <Noun IOR> (default is file://noun.ior)\n"
                               "\n",
                               argv [0]),
                              -1);
        }
    }
  return 0;
}

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  ACE_DEBUG ((LM_DEBUG, "*** begin validating interface declarations\n"));

  try
  {
    // Initialize the ORB.
    CORBA::ORB_var orb = CORBA::ORB_init ( argc, argv );
    
    if (parse_args (argc, argv) != 0)
    {
      return -1;
    }

    CORBA::Object_var obj = orb->string_to_object (noun_ior);
    
    JustANoun_var noun = JustANoun::_narrow (obj.in());
    
    if (CORBA::is_nil (noun.in ()))
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "Unable to acquire JustANoun objref\n"),
                        -1);
    }

    noun->person ("me");
    noun->place ("IDL");
    noun->thing (1000);
    noun->idea (true);
    noun->my_event (12);
  }
  catch(const CORBA::Exception& ex)
  {
      ex._tao_print_exception ("Interface");
      ACE_ERROR_RETURN ((LM_ERROR, "Caught CORBA::Exception\n"), 1);
  }

  ACE_DEBUG ((LM_DEBUG, "*** end validating interface declarations\n"));

  return 0;
}
