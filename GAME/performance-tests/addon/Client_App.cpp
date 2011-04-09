// $Id$

#include "StdAfx.h"
#include "Client_App.h"

#include "ace/Get_Opt.h"
#include "ace/Time_Value.h"
#include "ace/High_Res_Timer.h"
#include "ace/streams.h"

#include "game/mga/ComponentEx.h"
#include "game/mga/Model.h"
#include "game/mga/Transaction.h"

#include <sstream>

static int
execute_object_create_test (GAME::Mga::Project & proj,
                            size_t iters,
                            ACE_Time_Value & duration)
{
  // Start a new transaction.
  GAME::Mga::Transaction t (proj);
  GAME::Mga::RootFolder root = proj.root_folder ();

  // Start the test's timer.
  ACE_High_Res_Timer timer;
  timer.start ();

  for (size_t i = 0; i < iters; ++ i)
  {
    // Create a new Library element. This element appears in the
    // root folder.
    using GAME::Mga::Model;
    Model lib = Model::impl_type::_create (root, "Library");

    // Force the OBJEVENT_CREATE notification.
    t.flush ();
  }

  // Return the duration of the test.
  timer.stop ();
  timer.elapsed_time (duration);

  return 0;
};

//
// Client_App
//
Client_App::Client_App (void)
: test_ ("OBJEVENT_CREATE"),
  iterations_ (10000)
{

}

//
// ~Client_App
//
Client_App::~Client_App (void)
{

}

//
// run_main
//
int Client_App::run_main (int argc, char * argv [])
{
  if (0 != this->parse_args (argc, argv))
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%T (%t) - %M - failed to parse ")
                       ACE_TEXT ("command-line arguments\n")),
                       -1);

  try
  {
    using GAME::Mga::Project;

    // Create a dummy project for the Library paradigm. Make sure we
    // disable the automatic addons for this project, if there are any.
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - creating benchmarking project\n")));

    Project proj = Project::_create ("MGA=benchmark.mga", "Library");
    proj.enable_auto_addons (false);

    // Load the component into memory.
    using GAME::Mga::ComponentEx;
    ComponentEx addon;

    if (!this->addon_progid_.is_empty ())
    {
      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%T (%t) - %M - loading component %s\n"),
                  this->addon_progid_.c_str ()));

      // Load the specified add-on and initialize it with the
      // created project.
      using GAME::Mga::ComponentEx_Impl;
      addon = ComponentEx::impl_type::_load (this->addon_progid_.c_str ());

      ACE_DEBUG ((LM_DEBUG,
                  ACE_TEXT ("%T (%t) - %M - initializing loaded component\n")));

      addon->initialize (proj);
    }

    // Now, we can run the test.
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("%T (%t) - %M - running the benchmark test\n")));

    if (0 != this->execute_test (proj))
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("%T (%t) - %M - failed to execute test\n")),
                         -1);

    // Gracefully close the project.
    proj.close ();

    return 0;
  }
  catch (const GAME::Mga::Failed_Result & ex)
  {
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - caught GME exception [0x%X]\n"),
                ex.value ()));
  }
  catch (const GAME::Mga::Exception & )
  {
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT ("%T (%t) - %M - caught GAME exception\n")));
  }

  return -1;
}

//
// parse_args
//
int Client_App::parse_args (int argc, char * argv [])
{
  // Initialize the command-line parser.
  const char * optargs = "";
  ACE_Get_Opt get_opt (argc, argv, optargs);

  get_opt.long_option ("progid", 'p', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("test", 't', ACE_Get_Opt::ARG_REQUIRED);
  get_opt.long_option ("iterations", ACE_Get_Opt::ARG_REQUIRED);

  char opt;

  // Parse each of the command-line options.
  while (EOF != (opt = get_opt ()))
  {
    switch (opt)
    {
    case 0:
      // This command-line option was a long option.
      if (0 == ACE_OS::strcmp ("progid", get_opt.long_option ()))
      {
        this->addon_progid_ = get_opt.opt_arg ();
      }
      else if (0 == ACE_OS::strcmp ("test", get_opt.long_option ()))
      {
        this->test_ = get_opt.opt_arg ();
      }
      else if (0 == ACE_OS::strcmp ("iterations", get_opt.long_option ()))
      {
        std::istringstream istr (get_opt.opt_arg ());
        istr >> this->iterations_;
      }
      break;

    case 'p':
      this->addon_progid_ = get_opt.opt_arg ();
      break;

    case 't':
      this->test_ = get_opt.opt_arg ();
      break;
    }
  }

  return 0;
}

//
// execute_test
//
int Client_App::execute_test (GAME::Mga::Project p)
{
  ACE_Time_Value duration;

  if (this->test_ == "OBJEVENT_CREATE")
    ::execute_object_create_test (p, this->iterations_, duration);
  else
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("%T (%t) - %M - %s test no found\n"),
                       this->test_.c_str ()),
                       -1);

  std::cout
    << "# Test              Duration" << std::endl
    << this->test_ << "     " << duration << std::endl;

  return 0;
}
