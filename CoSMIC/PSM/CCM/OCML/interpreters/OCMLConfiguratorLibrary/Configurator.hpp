#ifndef CONFIGURATOR_HPP
#define CONFIGURATOR_HPP

#include "Options/OptionCategory.hpp"

#include <string>
#include <memory>

#include "../Common/StringUtils.hpp"
#include "../Common/XercesHelpers.hpp"

#include <xercesc/dom/DOM.hpp>
#include <xercesc/util/XMLString.hpp>

class Configurator {
public:
  class InitializationError { };

  Configurator(const char* tree_file);

  void initialize_options(const char* value_data, size_t size);
  std::string write();

  OptionCategory* root_category()
  {
    return root_.get();
  }

private:
  XercesSystem system_;
  std::auto_ptr<OptionCategory> root_;
};

#endif // CONFIGURATOR_HPP
