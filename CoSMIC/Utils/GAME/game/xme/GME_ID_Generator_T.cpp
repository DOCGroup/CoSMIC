// $Id$

#if !defined (__GME_INLINE__)
#include "GME_ID_Generator_T.inl"
#endif

#include "Model.h"
#include "Folder.h"
#include "Connection.h"
#include "Reference.h"

namespace GME
{
namespace XME
{
//
// GME_ID_Generator_T
//
template <typename T>
GME_ID_Generator_T <T>::GME_ID_Generator_T (void)
: count_ (0),
  id_ (initial_id <T>::result_type)
{

}

//
// init
//
template <typename T>
void GME_ID_Generator_T <T>:: init (xercesc::DOMDocument * proj)
{
  using xercesc::DOMNodeList;

  // Initialize the count based on the number of node found
  // in the model that match the elements tagname.
  DOMNodeList * list = proj->getElementsByTagName (T::TAGNAME);
  this->count_ = list->getLength ();
}

//
// generate_id
//
template <typename T>
const ::Utils::XStr & GME_ID_Generator_T <T>::generate_id  (void)
{
  using xercesc::XMLString;

  // To generate the id, we just need to convert the current
  // count to a hexadecimal text format.
#define COUNT_ENCODE_OFFSET   8
#define COUNT_ENCODE_BUFSIZE  9
#define COUNT_ENCODE_RADIX    16

  static XMLCh buffer[COUNT_ENCODE_BUFSIZE];
  XMLString::sizeToText (this->count_,
                         buffer,
                         COUNT_ENCODE_BUFSIZE,
                         COUNT_ENCODE_RADIX);

  // Pad the id with zeros.
  size_t length = XMLString::stringLen (buffer);
  size_t adjust = 8 - length;

  XMLCh * ptr = this->id_ + COUNT_ENCODE_OFFSET;
  for (; adjust != 0; -- adjust)
    *ptr ++ = xercesc::chDigit_0;

  // Insert the number into the id.
  XMLString::moveChars (ptr, buffer, length + 1);

  // Increment the count for the next id
  ++ this->count_;

  return this->id_;
}

}
}
