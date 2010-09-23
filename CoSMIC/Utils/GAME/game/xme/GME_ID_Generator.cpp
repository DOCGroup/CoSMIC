// $Id$

#include "GME_ID_Generator.h"

#if !defined (__GAME_INLINE__)
#include "GME_ID_Generator.inl"
#endif

#include "Atom.h"
#include "Folder.h"
#include "Model.h"
#include "Connection.h"
#include "Reference.h"

#include "boost/spirit/include/qi_uint.hpp"
#include "boost/spirit/include/qi.hpp"

namespace GAME
{
namespace XME
{
namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

/**
 * @struct PathParser
 *
 * Boost grammar for parsing identifiers.
 */
template <typename IteratorT>
struct Id_Grammar : qi::grammar <IteratorT, size_t (), ascii::space_type>
{
public:
  /// Type definition of the iterator type.
  typedef IteratorT iterator_type;

  Id_Grammar (void)
    : Id_Grammar::base_type (this->parser_)
  {
    this->parser_ =
      qi::lit ("id-") > this->typeid_ > qi::lit ("-") > qi::hex;

    this->typeid_ =
      qi::lit ("0065") |
      qi::lit ("0066") |
      qi::lit ("0067") |
      qi::lit ("0068") |
      qi::lit ("0069") |
      qi::lit ("006a");
  }

private:
  qi::rule <IteratorT, size_t (), ascii::space_type> parser_;

  qi::rule <IteratorT, void (), ascii::space_type> typeid_;
};


//
// init
//
void GME_ID_Generator::init (xercesc::DOMDocument * proj)
{
  GME_ID_Generator::init (proj, Atom::TAGNAME, this->atom_);
  GME_ID_Generator::init (proj, Model::TAGNAME, this->model_);
  GME_ID_Generator::init (proj, Reference::TAGNAME, this->ref_);
  GME_ID_Generator::init (proj, Connection::TAGNAME, this->conn_);
  GME_ID_Generator::init (proj, Folder::TAGNAME, this->folder_);
}

//
// init
//
void GME_ID_Generator::
init (xercesc::DOMDocument * proj, const GAME::Xml::String & name, typeinfo_t & type)
{
  using xercesc::DOMNodeList;

  // Initialize the count based on the number of node found
  // in the model that match the elements tagname.
  DOMNodeList * list = proj->getElementsByTagName (name);
  size_t count = list->getLength ();

  Id_Grammar <std::string::const_iterator> grammar;

  for (size_t i = 0; i < count; ++ i)
  {
    using xercesc::DOMNode;
    using xercesc::DOMElement;

    // Get the next element.
    DOMNode * node = list->item (i);
    DOMElement * e = dynamic_cast <DOMElement *> (node);

    // Get the id string of the element.
    GAME::Xml::String idstr (e->getAttribute (GAME::Xml::String ("id")));
    const std::string & cstr = idstr.to_string ();

    // Parse the string to get the count portion.
    std::string::const_iterator 
      iter = cstr.begin (), iter_end = cstr.end ();

    size_t count = 0;
    
    if (qi::phrase_parse (iter, iter_end, grammar, ascii::space, count))
    {
      // Determine if this value is larget than the current. We
      // need to make sure we do not overwrite the exist ids
      if (count > type.count_)
        type.count_ = count;
    }
  }

  // If there is at least one element in the model, then we need
  // to increment our count to account for largest count number. ;-)
  if (count > 0)
    ++ type.count_;
}

//
// generate_id
//
GAME::Xml::String & GME_ID_Generator::generate_id (typeinfo_t & type)
{
  // Only one thread is allowed access to this method for each
  // type. Otherwise, we could have invalid id generation.
  ACE_GUARD_RETURN (ACE_Thread_Mutex, guard, type.lock_, type.idstr_);

  using xercesc::XMLString;

  // To generate the id, we just need to convert the current
  // count to a hexadecimal text format.
#define COUNT_ENCODE_OFFSET   8
#define COUNT_ENCODE_BUFSIZE  9
#define COUNT_ENCODE_RADIX    16

  static XMLCh buffer[COUNT_ENCODE_BUFSIZE];
  XMLString::sizeToText (type.count_,
                         buffer,
                         COUNT_ENCODE_BUFSIZE,
                         COUNT_ENCODE_RADIX);

  // Pad the id with zeros.
  size_t length = XMLString::stringLen (buffer);
  size_t adjust = 8 - length;

  XMLCh * ptr = type.idstr_ + COUNT_ENCODE_OFFSET;
  for (; adjust != 0; -- adjust)
    *ptr ++ = xercesc::chDigit_0;

  // Insert the number into the id.
  XMLString::lowerCase (buffer);
  XMLString::moveChars (ptr, buffer, length + 1);

  // Increment the count for the next id
  ++ type.count_;

  return type.idstr_;
}

}
}
