// -*- C++ -*-
// $Id$

namespace GME
{
namespace XME
{
//
// Collection
//
template <typename T>
GME_INLINE
Collection <T>::Collection (void)
: list_ (0)
{

}

//
// Collection
//
template <typename T>
GME_INLINE
Collection <T>::Collection (xercesc::DOMNodeList * list)
: list_ (list)
{

}

//
// Collection
//
template <typename T>
GME_INLINE
Collection <T>::Collection (const Collection & coll)
: list_ (coll.list_)
{

}

//
// Collection
//
template <typename T>
GME_INLINE
Collection <T>::~Collection (void)
{

}

//
// attach
//
template <typename T>
GME_INLINE
void Collection <T>::attach (xercesc::DOMNodeList * list)
{
  this->list_ = list;
}

//
// release
//
template <typename T>
GME_INLINE
xercesc::DOMNodeList * Collection <T>::release (void)
{
  xercesc::DOMNodeList * temp = this->list_;
  this->list_ = 0;
  return temp;
}

//
// operator =
//
template <typename T>
GME_INLINE
const Collection <T> & Collection <T>::operator = (const Collection & coll)
{
  this->list_ = coll.list_;
  return *this;
}

//
// size
//
template <typename T>
GME_INLINE
size_t Collection <T>::size (void) const
{
  return this->list_ != 0 ? this->list_->getLength () : 0;
}

//
// size
//
template <typename T>
GME_INLINE
T Collection <T>::operator [] (size_t index) const
{
  // TODO change to an exception
  assert (this->list_ != 0);

  // Get the item from the list, and convert it to an element.
  xercesc::DOMNode * node = this->list_->item (index);
  xercesc::DOMElement * e = dynamic_cast <xercesc::DOMElement *> (node);
  return e;
}

}
}
