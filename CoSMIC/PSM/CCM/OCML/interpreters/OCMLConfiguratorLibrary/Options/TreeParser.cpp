#include "TreeParser.hpp"
#include "../../Common/StringUtils.hpp"

using namespace xercesc;

/**
 * Static public factory method. Parses an xml option tree and returns the
 * generated root category.
 */
OptionCategory*
OptionTreeParser::parse_xml(DOMDocument* doc)
{
  OptionTreeParser parser;
  if (doc)
    return parser.parse_document(doc);
}

OptionTreeParser::OptionTreeParser()
{
}

OptionCategory*
OptionTreeParser::parse_document(DOMDocument* doc)
{
  return parse_category(doc->getDocumentElement());
}

void
OptionTreeParser::parse_attributes(DOMNode* node,
                                   XMLUnicodeString& name,
                                   XMLUnicodeString& description)
{
  DOMNamedNodeMap* attributes = node->getAttributes();

  name =
    attributes->getNamedItem(XMLUnicodeString("name"))->getNodeValue();
  description =
    attributes->getNamedItem(XMLUnicodeString("description"))->getNodeValue();
}

OptionCategory*
OptionTreeParser::parse_category(DOMNode* node)
{
  XMLUnicodeString name, description;
  parse_attributes(node, name, description);

  OptionCategory* result =
    new OptionCategory(name.str().c_str(), description.str().c_str());

  DOMNodeList* children = node->getChildNodes();

  for (size_t i = 0; i < children->getLength(); ++i)
  {
    DOMNode* child_node = children->item(i);
    XMLUnicodeString child_node_name = child_node->getNodeName();

    if (child_node_name	== "OptionCategory")
      result->add_category(parse_category(child_node));
    else if (child_node_name == "BooleanOption")
      result->add_option(parse_boolean_option(child_node));
    else if (child_node_name == "StringOption")
      result->add_option(parse_string_option(child_node));
    else if (child_node_name == "IntegerOption")
      result->add_option(parse_integer_option(child_node));
    else if (child_node_name == "EnumOption")
      result->add_option(parse_enum_option(child_node));
/*
    else
      throw UnknownOptionKind(child_node_name.str());
*/
  }

  return result;
}

BooleanOption*
OptionTreeParser::parse_boolean_option(DOMNode* node)
{
  XMLUnicodeString name, description;
  parse_attributes(node, name, description);

  return new BooleanOption(name.str().c_str(), description.str().c_str());
}

IntegerOption*
OptionTreeParser::parse_integer_option(DOMNode* node)
{
  XMLUnicodeString name, description;
  parse_attributes(node, name, description);

  return new IntegerOption(name.str().c_str(), description.str().c_str());
}

StringOption*
OptionTreeParser::parse_string_option(DOMNode* node)
{
  XMLUnicodeString name, description;
  parse_attributes(node, name, description);

  return new StringOption(name.str().c_str(), description.str().c_str());
}

EnumOption*
OptionTreeParser::parse_enum_option(DOMNode* node)
{
  XMLUnicodeString name, description;
  parse_attributes(node, name, description);

  EnumOption* result =
    new EnumOption(name.str().c_str(), description.str().c_str());

  DOMNodeList* children = node->getChildNodes();

  for (size_t i = 0; i < children->getLength(); ++i)
    {
      XMLUnicodeString item_node_name = children->item(i)->getNodeName();
      if (item_node_name.str() == std::string("Item"))
        {
          std::string item_name = parse_enum_item(children->item(i));
          result->add_item(item_name.c_str());
        }
    }
  return result;
}

std::string
OptionTreeParser::parse_enum_item(DOMNode* node)
{
  DOMNamedNodeMap* attributes = node->getAttributes();
  XMLUnicodeString name =
    attributes->getNamedItem(XMLUnicodeString("name"))->getNodeValue();

  return name.str();
}
