// $Id: $

#include "MultipleInterfacesC.h"
#include "ace/Log_Msg.h"
#include "ace/Get_Opt.h"
#include <typeinfo.h>

const char *multipleinterfaces_ior = "file://multipleinterfaces.ior";

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
            multipleinterfaces_ior = get_opts.opt_arg ();
            break;

          case '?':  // display help for use of the server.
          default:
            ACE_ERROR_RETURN ((LM_ERROR,
                               "usage:  %s\n"
                               "-k <Noun IOR> (default is file://multipleinterfaces.ior)\n"
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
  using namespace MultipleInterfaces;

  ACE_DEBUG ((LM_DEBUG, "*** begin validating IDL with multiple interfaces\n"));
  
  try
  {
    // Initialize the ORB.
    CORBA::ORB_var orb = CORBA::ORB_init ( argc, argv );
    
    if (parse_args (argc, argv) != 0)
    {
      return -1;
    }

    CORBA::Object_var obj = orb->string_to_object (multipleinterfaces_ior);
    
    Noun_var noun = Noun::_narrow (obj.in());
    
    if (CORBA::is_nil (noun.in ()))
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "Unable to acquire Noun objref\n"),
                        -1);
    }

    noun->my_person ("me");
    noun->my_place ("IDL");
    noun->my_thing (true);
    noun->my_idea (123);
    noun->my_event (1234);
  }
  catch(const CORBA::Exception& ex)
  {
      ex._tao_print_exception ("MultipleInterfaces");
      ACE_ERROR_RETURN ((LM_ERROR, "Caught CORBA::Exception\n"), 1);
  }

  ACE_DEBUG ((LM_DEBUG, "*** end validating IDL with multiple interfaces\n"));

  return 0;
}
