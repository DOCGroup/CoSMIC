#ifndef TREE_PARSER_HPP
#define TREE_PARSER_HPP

#include "Options.hpp"

#include <xercesc/dom/DOM.hpp>

class OptionTreeParser
{
public:
  class UnknownOptionKind: public std::exception {
  public:
    UnknownOptionKind(const std::string& msg)
      : msg_(std::string("TreeParser:UnknownOptionKind ") + msg)
    {
    }

    virtual ~UnknownOptionKind() throw()
    {
    }

    virtual const char* what() const throw()
    {
      return msg_.c_str();
    }

  private:
    std::string msg_;
  };

  static OptionCategory* parse_xml(xercesc::DOMDocument* doc);

private:
  OptionTreeParser();
  OptionCategory* parse_document(xercesc::DOMDocument* doc);

  void parse_attributes(xercesc::DOMNode* node, XMLUnicodeString& name,
                        XMLUnicodeString& description);

  OptionCategory* parse_category(xercesc::DOMNode* node);
  BooleanOption* parse_boolean_option(xercesc::DOMNode* node);
  IntegerOption* parse_integer_option(xercesc::DOMNode* node);
  StringOption* parse_string_option(xercesc::DOMNode* node);
  EnumOption* parse_enum_option(xercesc::DOMNode* node);

  std::string parse_enum_item(xercesc::DOMNode* node);
};

#endif // TREE_PARSER_HPP
