// $Id$

#include "game/mga/plugins/Template_Engine/parser/Property_Expander.hpp"
#include "game/mga/plugins/Template_Engine/parser/Property_Listing.hpp"

//
// test_property_tag_parser
//
void test_property_tag_parser (void)
{
  Property_Tag_Config config;
  config.tags_.first = "<%";
  config.tags_.second = "%>";

  namespace spirit = boost::spirit;
  namespace qi = spirit::qi;

  Property_Tag <std::string::const_iterator,
                spirit::ascii::space_type> grammar (config);

  const std::string encoded_prop ("<%Param1%>");
  std::string prop;


  // Parse the file contents.
  bool retval =
    qi::phrase_parse (encoded_prop.begin (),
                      encoded_prop.end (),
                      grammar,
                      boost::spirit::ascii::space,
                      prop);

  if (!retval)
    std::cerr << "*** error: failed to parse " << encoded_prop << std::endl;

  std::cout << "*** info: read property " << prop << std::endl;

  if (prop != "Param1")
    std::cerr
      << "*** error: incorrect property name; expected Param1, but read"
      << prop << std::endl;
}

//
// test_property_lister
//
void test_property_lister (void)
{
  Property_Tag_Config config;
  config.tags_.first = "<%";
  config.tags_.second = "%>";

  namespace spirit = boost::spirit;
  namespace qi = spirit::qi;

  const std::string propstr ("Who is <%PERSON%>");
  std::set <std::string> result;

  Property_Lister lister;
  if (!lister.evaluate (propstr.begin (), propstr.end (), config, result))
    std::cerr << "*** error: failed to parse \"" << propstr << "\"" << std::endl;

  if (result.size () != 1)
    std::cerr << "*** error: result size of " << result.size ()
              << " is incorrect" << std::endl;

  if (result.find ("PERSON") == result.end ())
    std::cerr << "*** error: failed to locate PERSON in result set" << std::endl;

  std::cout << "*** info: test is complete" << std::endl;
}

//
// test_property_expander
//
void test_property_expander (void)
{
  Property_Tag_Config config;
  config.tags_.first = "<%";
  config.tags_.second = "%>";
  Property_Expander expander (config);

  Property_Map prop_map;
  prop_map.set ("PERSON", "James");

  namespace spirit = boost::spirit;
  namespace qi = spirit::qi;

  std::string result;

  // Test expanding a property at the end of the string.
  const std::string propstr_end ("Who is <%PERSON%>");
  if (!expander.evaluate (propstr_end.begin (),
                          propstr_end.end (),
                          prop_map,
                          result))
  {
    std::cerr
      << "*** error (" << __LINE__ << "): "
      << "failed to expand \"" << propstr_end << "\"" << std::endl;
  }

  if (result != "Who is James")
    std::cerr << "*** error (" << __LINE__ << "): "
              << "string expanded incorrectly; got \"" << result << "\"" << std::endl;

  // Test expanding a property at the beginning of the string.
  const std::string propstr_begin ("<%PERSON%> is my friend");

  if (!expander.evaluate (propstr_begin.begin (),
                          propstr_begin.end (),
                          prop_map,
                          result))
  {
    std::cerr
      << "*** error (" << __LINE__ << "): "
      << "failed to expand \"" << propstr_begin << "\"" << std::endl;
  }

  if (result != "James is my friend")
    std::cerr << "*** error (" << __LINE__ << "): "
              << "string expanded incorrectly; got \"" << result << "\"" << std::endl;

  // Test expanding a property in the middle of the string.
  const std::string propstr_middle ("Get <%PERSON%> today");

  if (!expander.evaluate (propstr_middle.begin (),
                          propstr_middle.end (),
                          prop_map,
                          result))
  {
    std::cerr
      << "*** error (" << __LINE__ << "): "
      << "failed to expand \"" << propstr_middle << "\"" << std::endl;
  }

  if (result != "Get James today")
    std::cerr << "*** error (" << __LINE__ << "): "
              << "string expanded incorrectly; got \"" << result << "\"" << std::endl;

  std::cout << "*** info: test is complete" << std::endl;
}

//
// main
//
int main (int argc, char * argv [])
{
  ::test_property_tag_parser ();
  ::test_property_lister ();
  ::test_property_expander ();

  return 0;
}
