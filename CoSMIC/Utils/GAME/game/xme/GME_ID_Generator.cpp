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

namespace GAME
{
namespace XME
{

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
init (xercesc::DOMDocument * proj, const ::Utils::XStr & name, typeinfo_t & type)
{
  using xercesc::DOMNodeList;

  // Initialize the count based on the number of node found
  // in the model that match the elements tagname.
  DOMNodeList * list = proj->getElementsByTagName (name);
  type.count_ = list->getLength ();
}

//
// generate_id
//
::Utils::XStr & GME_ID_Generator::generate_id (typeinfo_t & type)
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
