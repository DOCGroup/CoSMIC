#include <iostream>
#include <fstream>

#include "Configurator.hpp"

#include "Options/TreeParser.hpp"
#include "Options/ValueParser.hpp"
#include "Options/Options.hpp"

using namespace xercesc;

Configurator::Configurator(const char* tree_file)
{
  system_.initialize();
  XercesAutoPtr<DOMBuilder> parser = system_.new_parser();
  DOMDocument *tree_doc = 0;
  // TODO
  std::string str_tree_file = std::string("c:\\") + std::string(tree_file);
  
  try {
    // parse the options tree
    tree_doc = parser->parseURI(str_tree_file.c_str());

    // TODO
    if (tree_doc == 0)
      throw "Config file not found.";
  }
  catch (const XMLException& toCatch) {
    throw InitializationError();
  }
  catch (const DOMException& toCatch) {
    throw InitializationError();
  }
  catch (...) {
    throw InitializationError();
  }

  root_.reset(OptionTreeParser::parse_xml(tree_doc));
}

void
Configurator::initialize_options(const char* value_data, size_t size)
{
  XercesAutoPtr<DOMBuilder> parser = system_.new_parser();
  DOMDocument *value_doc = 0;
  value_doc =
    system_.parse_string(parser.get(), "OCMLValues", value_data, size);

  OptionValueParser::parse_xml(root_.get(), value_doc);
}

std::string
Configurator::write()
{
  XercesAutoPtr<DOMDocument> new_doc =
    system_.impl()->createDocument(0, XMLUnicodeString("test"), 0);
  XercesAutoPtr<DOMWriter> writer =
    system_.impl()->createDOMWriter();

  DOMNode* node = root_->write(new_doc.get());
  XMLUnicodeString result;
  if (node)
    result = writer->writeToString(*node);
  return result.str();
}
