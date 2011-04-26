// $Id$

#include "StdAfx.h"
#include "Client_App.h"

#include "ace/Get_Opt.h"
#include "ace/Time_Value.h"
#include "ace/High_Res_Timer.h"
#include "ace/streams.h"

#include "game/mga/ComponentEx.h"
#include "game/mga/Model.h"
#include "game/mga/Atom.h"
#include "game/mga/Attribute.h"
#include "game/mga/FCO.h"
#include "game/mga/Reference.h"
#include "game/mga/Transaction.h"

#include <sstream>
#include <set>
//
//execute_object_create_test
//
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
//execute_object_destroyed_test
//
static int
execute_object_destroyed_test (GAME::Mga::Project & proj,
                               size_t iters,
                               ACE_Time_Value & duration)
{
  // Start a new transaction.
  GAME::Mga::Transaction t (proj);
  GAME::Mga::RootFolder root = proj.root_folder ();

  std::vector <GAME::Mga::Model> input;
 
  for (size_t i = 0; i < iters; ++ i)
  {
    // Create a new Library element. This element appears in the
    // root folder.
    using GAME::Mga::Model;
	Model lib = Model::impl_type::_create (root, "Library");

	input.push_back(lib);

	t.flush ();
  }

  t.commit ();

  //Start another transaction
  GAME::Mga::Transaction t1 (proj);
 
  std::vector <GAME::Mga::Model>::iterator 
	  iter = input.begin (), iter_end = input.end ();

   // Start the test's timer.
  ACE_High_Res_Timer timer;
  timer.start ();
  

  for ( ; iter != iter_end; ++ iter)
  {
	  (*iter)->destroy ();
       t1.flush ();	 
  }
 
  // Return the duration of the test.
  timer.stop ();
  timer.elapsed_time (duration);

  return 0;
};

//
//execute_object_newchild_test
//
static int
execute_object_newchild_test (GAME::Mga::Project & proj,
                            size_t iters,
                            ACE_Time_Value & duration)
{
  // Start a new transaction.
  GAME::Mga::Transaction t (proj);
  GAME::Mga::RootFolder root = proj.root_folder ();

  // Create a new Library element. This element appears in the
  // root folder.
  using GAME::Mga::Model;
  Model lib = Model::impl_type::_create (root, "Library");
  
	// Start the test's timer.
  ACE_High_Res_Timer timer;
  timer.start ();
  
  for (size_t i = 0; i < iters; ++ i)
  {
	  
	  using GAME::Mga::Atom;
	  Atom boo = Atom::impl_type::_create (lib, "Book");

    // Force the OBJEVENT_NEWCHILD notification.
    t.flush ();
  }

  // Return the duration of the test.
  timer.stop ();
  timer.elapsed_time (duration);
  
  return 0;
};

//
//execute_object_parent_test
//
static int
execute_object_parent_test (GAME::Mga::Project & proj,
                            size_t iters,
                            ACE_Time_Value & duration)
{
  // Start a new transaction.
  GAME::Mga::Transaction t (proj);
  GAME::Mga::RootFolder root = proj.root_folder ();

  std::vector <GAME::Mga::Atom> input;
  
  // Create a new Library element. This element appears in the
  // root folder.
  using GAME::Mga::Model;
	Model lib = Model::impl_type::_create (root, "Library");

  
  for (size_t i = 0; i < iters; ++ i)
  {
	using GAME::Mga::Atom;
	  Atom boo = Atom::impl_type::_create (lib, "Book");
    
	input.push_back(boo);

	t.flush ();
  }

  t.commit ();

  //Start another transaction
  GAME::Mga::Transaction t1 (proj);

  std::vector <GAME::Mga::Atom>::iterator
	  iter = input.begin (), iter_end = input.end ();

  // Start the test's timer.
  ACE_High_Res_Timer timer;
  timer.start ();
  
 for ( ; iter != iter_end; ++ iter)
	 {
		 (*iter)->parent();

		 // Force the OBJEVENT_PARENT notification.
		 t1.flush ();
	 }


  // Return the duration of the test.
  timer.stop ();
  timer.elapsed_time (duration);

  return 0;
};

//
//execute_object_attribute_test
//
static int
execute_object_attribute_test (GAME::Mga::Project & proj,
                               size_t iters,
                               ACE_Time_Value & duration)
{
  // Start a new transaction.
  GAME::Mga::Transaction t (proj);
  GAME::Mga::RootFolder root = proj.root_folder ();

  std::vector <GAME::Mga::Atom> input;
  std::vector<GAME::Mga::Atom>::iterator traverse;

  // Create a new Library element. This element appears in the
  // root folder.
  using GAME::Mga::Model;
	Model lib = Model::impl_type::_create (root, "Library");

  
  for (size_t i = 0; i < iters; ++ i)
  {
	using GAME::Mga::Atom;
	  Atom boo = Atom::impl_type::_create (lib, "Book");
    
	input.push_back(boo);

	t.flush ();
  }

  t.commit ();

  //Start another transaction
  GAME::Mga::Transaction t1 (proj);
  GAME::Mga::Attribute atr ;

  // Start the test's timer.
  ACE_High_Res_Timer timer;
  timer.start ();
  
 for (traverse = input.begin(); traverse != input.end() ; ++traverse)
	 {
		 atr = (*traverse)->attribute("Quantity");
		 atr->int_value (20);

		 // Force the OBJEVENT_ATTRIBUTE notification.
		 t1.flush ();
	 }


  // Return the duration of the test.
  timer.stop ();
  timer.elapsed_time (duration);

  return 0;
};

//
//execute_object_subt_inst_test
//
static int
execute_object_subt_inst_test (GAME::Mga::Project & proj,
                            size_t iters,
                            ACE_Time_Value & duration)
{
  // Start a new transaction.
  GAME::Mga::Transaction t (proj);
  GAME::Mga::RootFolder root = proj.root_folder ();

  std::vector <GAME::Mga::Atom> input;
  std::vector<GAME::Mga::Atom>::iterator traverse;

  // Create a new Library element. This element appears in the
  // root folder.
  using GAME::Mga::Model;
	Model lib = Model::impl_type::_create (root, "Library");

  
  for (size_t i = 0; i < iters; ++ i)
  {
	using GAME::Mga::Atom;
	  Atom boo = Atom::impl_type::_create (lib, "Book");
    
	input.push_back(boo);

	t.flush ();
  }

  t.commit ();

  //Start another transaction
  GAME::Mga::Transaction t1 (proj);

  // Start the test's timer.
  ACE_High_Res_Timer timer;
  timer.start ();
  
 for (traverse = input.begin(); traverse != input.end() ; ++traverse)
	 {
		 (*traverse)->create_subtype (lib); 

		 // Force the OBJEVENT_SUBT_INST notification.
		 t1.flush ();
	 }


  // Return the duration of the test.
  timer.stop ();
  timer.elapsed_time (duration);

  return 0;
};

//
//execute_object_markedro_test
//
static int
execute_object_markedro_test (GAME::Mga::Project & proj,
                                 size_t iters,
                                 ACE_Time_Value & duration)
{
  // Start a new transaction.
  GAME::Mga::Transaction t (proj);
  GAME::Mga::RootFolder root = proj.root_folder ();

  std::vector <GAME::Mga::Model> input;
  std::vector<GAME::Mga::Model>::iterator traverse;
  
  for (size_t i = 0; i < iters; ++ i)
  {
	// Create a new Library element. This element appears in the
    // root folder.
    using GAME::Mga::Model;
	  Model lib = Model::impl_type::_create (root, "Library");
    
	input.push_back(lib);

	t.flush ();
  }

  t.commit ();

  //Start another transaction
  GAME::Mga::Transaction t1 (proj);

  // Start the test's timer.
  ACE_High_Res_Timer timer;
  timer.start ();
  
 for (traverse = input.begin(); traverse != input.end() ; ++traverse)
	 {
		 (*traverse)->readonly_access(true, true); 

		 // Force the OBJEVENT_MARKEDRO notification.
		 t1.flush ();
	 }


  // Return the duration of the test.
  timer.stop ();
  timer.elapsed_time (duration);

  return 0;
};

//
//execute_object_markedrw_test
//
static int
execute_object_markedrw_test (GAME::Mga::Project & proj,
                              size_t iters,
                              ACE_Time_Value & duration)
{
  // Start a new transaction.
  GAME::Mga::Transaction t (proj);
  GAME::Mga::RootFolder root = proj.root_folder ();

  std::vector <GAME::Mga::Model> input;
  std::vector<GAME::Mga::Model>::iterator traverse;
  
  for (size_t i = 0; i < iters; ++ i)
  {
	// Create a new Library element. This element appears in the
    // root folder.
    using GAME::Mga::Model;
	  Model lib = Model::impl_type::_create (root, "Library");
    
	input.push_back(lib);

	t.flush ();
  }

  t.commit ();

  //Start another transaction
  GAME::Mga::Transaction t1 (proj);

  // Start the test's timer.
  ACE_High_Res_Timer timer;
  timer.start ();
  
 for (traverse = input.begin(); traverse != input.end() ; ++traverse)
	 {
		 (*traverse)->readonly_access(false, true);  

		 // Force the OBJEVENT_MARKEDRW notification.
		 t1.flush ();
	 }


  // Return the duration of the test.
  timer.stop ();
  timer.elapsed_time (duration);

  return 0;
};

//
//execute_object_referenced_test
//
static int
execute_object_referenced_test (GAME::Mga::Project & proj,
                              size_t iters,
                              ACE_Time_Value & duration)
{
  // Start a new transaction.
  GAME::Mga::Transaction t (proj);
  GAME::Mga::RootFolder root = proj.root_folder ();

  std::vector <GAME::Mga::Atom> input;
  std::vector<GAME::Mga::Atom>::iterator traverse;

  // Create a new Library element. This element appears in the
  // root folder.
    using GAME::Mga::Model;
	  Model lib = Model::impl_type::_create (root, "Library");
  
  //Creating a reference to which the objects will refer.
  using GAME::Mga::Reference;
	Reference ref = Reference::impl_type::_create (lib, "Shelf");


  for (size_t i = 0; i < iters; ++ i)
  {
	  using GAME::Mga::Atom;
	    Atom boo = Atom::impl_type::_create (lib, "Book");

	  input.push_back(boo);

	  t.flush ();
  }

  t.commit ();

  //Start another transaction
  GAME::Mga::Transaction t1 (proj);

  // Start the test's timer.
  ACE_High_Res_Timer timer;
  timer.start ();
  
 for (traverse = input.begin(); traverse != input.end() ; ++traverse)
	 {
		 ref->refers_to (*traverse); 

		 // Force the OBJEVENT_REFERENCED notification.
		 t1.flush ();
	 }


  // Return the duration of the test.
  timer.stop ();
  timer.elapsed_time (duration);

  return 0;
};

//
//execute_object_properties_test
//
static int
execute_object_properties_test (GAME::Mga::Project & proj,
                                 size_t iters,
                                 ACE_Time_Value & duration)
{
  // Start a new transaction.
  GAME::Mga::Transaction t (proj);
  GAME::Mga::RootFolder root = proj.root_folder ();

  std::vector <GAME::Mga::Model> input;
  std::vector<GAME::Mga::Model>::iterator traverse;
  
  for (size_t i = 0; i < iters; ++ i)
  {
	// Create a new Library element. This element appears in the
    // root folder.
    using GAME::Mga::Model;
	  Model lib = Model::impl_type::_create (root, "Library");
    
	input.push_back(lib);

	t.flush ();
  }

  t.commit ();

  //Start another transaction
  GAME::Mga::Transaction t1 (proj);

  // Start the test's timer.
  ACE_High_Res_Timer timer;
  timer.start ();
  
 for (traverse = input.begin(); traverse != input.end() ; ++traverse)
	 {
		 (*traverse)->name ("University Library");

		 // Force the OBJEVENT_PROPERTIES notification.
		 t1.flush ();
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
: test_ ("OBJEVENT_CREATED"),
  iterations_ (10000),
  block_size_ (10)
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
  get_opt.long_option ("block", ACE_Get_Opt::ARG_REQUIRED);

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
	   else if (0 == ACE_OS::strcmp ("block", get_opt.long_option ()))
      {
        std::istringstream pstr (get_opt.opt_arg ());
		pstr >> this->block_size_;
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

  ACE_Time_Value temp [50];

  for (int i = 0; i < this->block_size_; i++)
  {
	  // Execute the correct test.
	  if (this->test_ == "OBJEVENT_CREATED")
		  ::execute_object_create_test (p, this->iterations_, duration);
	  else if (this->test_ == "OBJEVENT_DESTROYED")
		  ::execute_object_destroyed_test (p, this->iterations_, duration);
	  else if (this->test_ == "OBJEVENT_NEWCHILD")
		  ::execute_object_newchild_test (p, this->iterations_, duration);
	  else if (this->test_ == "OBJEVENT_PARENT")
		  ::execute_object_parent_test (p, this->iterations_, duration);
	  else if (this->test_ == "OBJEVENT_ATTR")
		  ::execute_object_attribute_test (p, this->iterations_, duration);
	  else if (this->test_ == "OBJEVENT_SUBT_INST")
		  ::execute_object_subt_inst_test (p, this->iterations_, duration);
	  else if (this->test_ == "OBJEVENT_MARKEDRO")
		  ::execute_object_markedro_test (p, this->iterations_, duration);
	  else if (this->test_ == "OBJEVENT_MARKEDRW")
		  ::execute_object_markedrw_test (p, this->iterations_, duration);
	  else if (this->test_ == "OBJEVENT_REFERENCED")
		  ::execute_object_referenced_test (p, this->iterations_, duration);
	  else if (this->test_ == "OBJEVENT_PROPERTIES")
		  ::execute_object_properties_test (p, this->iterations_, duration);
	  else
		  ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%T (%t) - %M - %s test no found\n"),
                             this->test_.c_str ()),
                             -1);

	  //Store data in a temporary array
	  temp [i] = duration;

      // Print the test results.
      std::cout
		  << "\n" << "# Test [ "<< i+1 <<" ]              Duration" << std::endl
		  << this->test_ << "     " << duration << std::endl;
  }

  ACE_Time_Value sum;
  for ( int j = 0; j < this->block_size_; j++)
	  sum = sum + temp [j];

  std::cout<<"\n\n"<<"Total sum     "<<sum;
  
  return 0;
}
