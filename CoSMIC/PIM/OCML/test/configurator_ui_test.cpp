#include <ui/configurator_ui.hpp>
#include <ace/OS.h>
#include <ace/Log_Msg.h>
#include <iostream>
#include <vector>
#include <string>

std::string tree_file = "orb_tree.xml";
std::string value_file;
std::string rule_file;

bool usage(const char* bin_name)
{
  std::cerr << "Usage: " << bin_name
            << " tree_file [-v value_file] [-r rule_file]"
            << std::endl;
  return false;
}

bool parse_params(int argc, ACE_TCHAR** argv)
{
  std::vector<std::string> args(argv+1, argv + argc);
  std::vector<std::string>::iterator iter = args.begin();

  if (iter == args.end())
    return true;

  if ((*iter)[0] != '-')
  {
    tree_file = *iter;
    ++iter;
  }

  if (*iter == "-v")
  {
    ++iter;
    value_file = *iter;
    ++iter;
  }

  if (*iter == "-r")
  {
    ++iter;
    rule_file = *iter;
    ++iter;
  }

  if (iter != args.end())
    return usage(argv[0]);

  return true;
}

int ACE_TMAIN(int argc, ACE_TCHAR** argv)
{
  ACE_LOG_MSG->priority_mask(LM_DEBUG, ACE_Log_Msg::PROCESS);
  if (parse_params(argc, argv) == false)
    return 1;
  Configurator_Dialog dlg;
  std::string new_values = dlg.show(tree_file, value_file, rule_file);
  std::cout << new_values;
  return 0;
}
