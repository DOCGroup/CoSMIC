// $Id$

#include "stdafx.h"
#include "Template_Engine_Impl.h"

#include "Template_Engine.h"
#include "Template_Engine_i.c"

#include "Configuration_File.h"
#include "Property_Locator.h"
#include "Property_Replacer_Guard.h"
#include "Model_Interpreter.h"
#include "Template_Engine_Dialog.h"

#include "game/mga/component/Plugin_T.h"
#include "game/mga/Project.h"
#include "game/mga/Transaction.h"
#include "game/mga/utils/Windows_Registry.h"

#include <sstream>
#include <fstream>

#include "parser/Property_Configuration.hpp"

GAME_DECLARE_PLUGIN (TemplateEngine, GAME_Template_Engine);

//
// GAME_Template_Engine
//
GAME_Template_Engine::GAME_Template_Engine (void)
: GAME::Mga::Plugin_Impl ("GAME Template Engine", "GAME.Plugin.TemplateEngine")
{

}

//
// ~GAME_Template_Engine
//
GAME_Template_Engine::~GAME_Template_Engine (void)
{

}

//
// invoke_ex
//
int GAME_Template_Engine::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in focus,
           std::vector <GAME::Mga::FCO> & selected,
           long flags)
{
  try
  {
    // Get a list of the interpreters for this project.
    Interpreter_List interpreters;
    GAME::Mga::Windows_Registry::get_registered_interpreters (project, interpreters);

    // Let the user select the configuration and interpreter.
    Template_Engine_Dialog dialog (::AfxGetMainWnd ());
    dialog.interpreter_list (&interpreters);

    if (IDCANCEL == dialog.DoModal ())
      return 0;

    switch (dialog.option ())
    {
    case 0:
      // Handle generation of the configuration file.
      this->handle_generate (project,
                             focus,
                             selected,
                             flags,
                             dialog.configuration_filename ().GetString ());
      break;

    case 1:
      {
        // Locate the selected interpreter.
        std::string prog_id;
        Interpreter_List::const_iterator iter =
          interpreters.find (dialog.selected_interpreter ().GetString ());

        if (iter == interpreters.end ())
          break;

        // Handle the intepretation of the model.
        this->handle_interpret (project,
                                focus,
                                selected,
                                flags,
                                dialog.configuration_filename ().GetString (),
                                iter->second.c_str (),
                                dialog.parameters ().GetString ());
        break;
      }
    }

    return 0;
  }
  catch (const GAME::Mga::Failed_Result & ex)
  {
    std::ostringstream ostr;
    ostr << "failed result: [0x" << std::hex
         << ex.value () << "]" << std::endl;

    ::AfxMessageBox (ostr.str ().c_str ());
  }
  catch (const GAME::Mga::Exception & )
  {
  }

  return -1;
}

//
// handle_interpret
//
int GAME_Template_Engine::
handle_interpret (GAME::Mga::Project project,
                  GAME::Mga::FCO_in focus,
                  std::vector <GAME::Mga::FCO> & selected,
                  long flags,
                  const char * config_file,
                  const char * prog_id,
                  const char * parameters)
{
  // Load the property configutions from the specified file.
  Property_Configuration_Map configs;

  if (!Configuration_File::read (config_file, configs))
  {
    ::AfxMessageBox ("Failed to read configuration file");
    return -1;
  }

  // Locate all the properties in the model. We will do this by
  // parsing the entire model from the root folder looking for
  // strings with the tags <% %>.
  Property_Tag_Config config;
  config.tags_.first  = "<%";
  config.tags_.second = "%>";

  Property_Locator locator (config);

  do
  {
    // Next, locate all attributes with a template parameter. We are
    // going to cache the elements for later.
    GAME::Mga::Transaction t (project, TRANSACTION_READ_ONLY);
    project.root_folder ()->accept (&locator);
  } while (0);

  // For each configuration, we need to interpret the model. This
  // should be done by first replacing each property with its
  // concrete value, then running the interpreter on the model.
  Property_Configuration_Map::iterator
    iter = configs.begin (), iter_end = configs.end ();

  // First, let's convert the parameters into a property map. This
  // way it will be a LOT easier to pass the configuration to the
  // selected model interpreter.

  Gme_Model_Interpreter interpreter (prog_id);
  interpreter.set_parameters (parameters);

  for (; iter != iter_end; ++ iter)
  {
    // Replace the properties with the real values.
    Property_Replacer_Guard guard (project,
                                   *iter->second,
                                   locator.names (),
                                   locator.attributes ());

    // Execute the model interpreter.
    interpreter.interpret (project,
                           focus,
                           selected,
                           flags);
  }

  ::AfxMessageBox ("Successfully applied template configurations");
  return 0;
}

//
// handle_generate
//
int GAME_Template_Engine::
handle_generate (GAME::Mga::Project project,
                 GAME::Mga::FCO_in fco,
                 std::vector <GAME::Mga::FCO> & selected,
                 long flags,
                 const char * config_file)
{
  //CUTS_CUTE_Unique_Property_Bag bag;

  //do
  //{
  //  GAME::Mga::Transaction t (project, TRANSACTION_READ_ONLY);

  //  // Locate all unique parameters in the model.
  //  Property_Locator locator (bag);
  //  project.root_folder ()->accept (&locator);
  //} while (0);

  //// Open the configuration for writing. Right now, let's just overwrite
  //// the file's contents.
  //std::ofstream outfile;
  //outfile.open (config_file);

  //if (!outfile.is_open ())
  //  return -1;

  //outfile << "config ([INSERT NAME]) {" << std::endl;

  //CUTS_CUTE_Unique_Property_Bag::CONST_ITERATOR iter (bag.items ());

  //for ( ; !iter.done (); ++ iter)
  //  outfile << "  " << *iter << "=" << std::endl;

  //outfile << "}" << std::endl;

  //outfile.close ();
  return 0;
}
