#ifndef _CONFIGURATOR_UI_HPP_
#define _CONFIGURATOR_UI_HPP_

#include "CONFIGURATOR_UI_Export.h"
#include <string>

class CONFIGURATOR_UI_Export Configurator_Dialog
{
public:
  std::string show(const std::string& tree_file,
                   const std::string& value_file,
                   const std::string& rule_file);
};

#endif // _CONFIGURATOR_UI_HPP_
