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

  XMLString::sizeToText (this->count_,
                         this->id_ + COUNT_ENCODE_OFFSET,
                         COUNT_ENCODE_BUFSIZE,
                         COUNT_ENCODE_RADIX);

  // Increment the count for the next id
  ++ this->count_;

  return this->id_;
}

}
}
