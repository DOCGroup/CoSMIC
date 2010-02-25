#ifndef __CARRIER_OPTIMIZED_CPP_
#define __CARRIER_OPTIMIZED_CPP_

#include "Carrier_Optimized.h"
#include <stdexcept>

namespace LEESA {

template <class Kind>
Carrier<Kind>::Carrier ()
  : first_(0), last_(0), size_(0)
{}

/* Anything that comes in as const is considered part of
 * the syntactic sugar. For instance return-by-value of
 * operator functions in the query. Therefore, it is
 * neglected altogether. Only non-const references coming 
 * in either via constructor or push_back will be stored.
 * */
template <class Kind>
Carrier<Kind>::Carrier(const Kind & u)
  : first_(0), last_(0), size_(0)
{ }

template <class Kind>
Carrier<Kind>::Carrier(Kind & u)
  : first_(0), last_(0), size_(0)
{ 
  this->push_back(&u);
}

template <class Kind>
Carrier<Kind>::Carrier(typename ContainerTraits<Kind>::Container & c)
  : first_(0), last_(0), size_(0)
{ 
  this->push_back(c);
}

template <class Kind>
Carrier<Kind> const & Carrier<Kind>::operator ()(Carrier<Kind> const & c) const
{
  return c;
}
  
template <class Kind>
Carrier<Kind>::Carrier(const Carrier<Kind> & c)
  : first_(0), last_(0), size_(0)
{
  for(Node<Kind> * iter = c.first_; iter != 0; iter=iter->next_)
    push_back (*iter);
}

template <class Kind>
void Carrier<Kind>::swap(Carrier<Kind> & c) throw() // Non-throw swap idiom
{
  std::swap(this->first_, c.first_);
  std::swap(this->last_, c.last_);
  std::swap(this->size_, c.size_);
}

template <class Kind>
template <class ForwardIterator> // Iterator pair idiom
Carrier<Kind>::Carrier(ForwardIterator start, ForwardIterator end)
  : first_(0), last_(0), size_(0)
{
  for(;start != end; ++start)
    push_back (&*start);
}

template <class Kind>
template <class Z>
Carrier<Kind>::Carrier(Carrier<Z> const & z_carrier)
  : first_(0), last_(0), size_(0)
{
  BOOST_MPL_ASSERT((boost::is_base_of<Kind, Z>));
  Carrier<Kind> temp(z_carrier.begin(), z_carrier.end());
  this->swap(temp);
}

template <class Kind>
Carrier<Kind>& Carrier<Kind>::operator = (const Carrier<Kind> & c) //copy and swap idiom
{
  Carrier<Kind>(c).swap(*this);
  return *this;
}

template <class Kind>
void Carrier<Kind>::push_back(Kind * const u)
{
  if (empty())
  {
     last_ = static_cast<Node<Kind> *>(operator new (sizeof(Node<Kind>)));
     new (last_) Node<Kind>(u);
     first_ = last_;
  }
  else 
  {
     last_->next_ = static_cast<Node<Kind> *>(operator new (sizeof(Node<Kind>)));
     new (last_->next_) Node<Kind>(u);
     last_->next_->prev_ = last_;
     last_ = last_->next_;
  }
  ++size_;
}

template <class Kind>
void Carrier<Kind>::push_back(Kind & u)
{
  push_back(&u);
}

template <class Kind>
void Carrier<Kind>::push_back(const Kind & u)
{
  push_back(const_cast<Kind &> (u));
}

template <class Kind>
void Carrier<Kind>::push_back(Node<Kind> & n)
{
  if(n.single_)
    push_back(n.single_);
  else if(n.many_)
    push_back(*n.many_);
}

template <class Kind>
void Carrier<Kind>::push_back(Carrier<Kind> & carrier)
{
  if(carrier.empty())
    return;
  
  for(Node<Kind> * temp(carrier.first_); temp != 0; temp=temp->next_)
    push_back (*temp);
}

template <class Kind>
void Carrier<Kind>::move_carrier(Carrier & c)
{
  /* This operation is very similar to std::list<T>::splice. */
  if(!c.empty())
  {
    if(this->empty())
      this->swap(c);
    else
    {
      this->last_->next_ = c.first_;
      c.first_->prev_ = this->last_;
      this->last_ = c.last_;
      this->size_ += c.size_;
      c.first_ = 0;
      c.last_ = 0;
      c.size_ = 0;
    }
  }
}

template <class Kind>
void Carrier<Kind>::push_back(typename ContainerTraits<Kind>::Container & container)
{
  if(container.empty())
    return;

  if (empty())
  {
     last_ = static_cast<Node<Kind> *>(operator new (sizeof(Node<Kind>)));
     new (last_) Node<Kind>(container);
     first_ = last_;
  }
  else 
  {
     last_->next_ = static_cast<Node<Kind> *>(operator new (sizeof(Node<Kind>)));
     new (last_->next_) Node<Kind>(container);
     last_->next_->prev_ = last_;
     last_ = last_->next_;
  }
  size_+=container.size();
}

template <class Kind>
void Carrier<Kind>::push_back(const typename ContainerTraits<Kind>::Container & container)
{
  push_back(const_cast<typename ContainerTraits<Kind>::Container &>(container));
}

template <class Kind>
void Carrier<Kind>::push_back(const Carrier<Kind> & carrier)
{
  push_back(const_cast<Carrier<Kind> &>(carrier));
}

template <class Kind>
void Carrier<Kind>::destroy()
{
  for(Node<Kind> * iter = first_; iter != 0; iter=iter->next_)
  {
    iter->~Node<Kind>();
    operator delete(iter);
  }
  first_ = 0;
  last_ = 0;
  size_ = 0;
}

template<class Kind>
Carrier<Kind>::~Carrier() throw()
{
  destroy();
}

template <class Kind>
bool Carrier<Kind>::empty() const
{
  return (size_ == 0);
}

template <class Kind>
unsigned int Carrier<Kind>::size() const 
{
  return size_;
}

template <class Kind>
Carrier<Kind>::operator typename ContainerTraits<Kind>::Container() const
{
  typename ContainerTraits<Kind>::Container temp;
  temp.reserve(this->size());
  std::copy(this->begin(), this->end(), std::back_inserter(temp));
  return temp;
}

#ifndef LEESA_FOR_UDM

template <class Kind>
void Carrier<Kind>::push_back (const typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Optional & o)
{
  if(o.present())
    this->push_back(const_cast<Kind *>(&o.get()));
}

template <class Kind>
void Carrier<Kind>::push_back (typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Optional & o)
{
  if(o.present())
    this->push_back(&o.get());
}

#endif // LEESA_FOR_UDM

template <class Kind>
typename Carrier<Kind>::iterator Carrier<Kind>::begin() const
{
  return Carrier<Kind>::iterator(first_);
}

template <class Kind>
typename Carrier<Kind>::iterator Carrier<Kind>::end() const
{
  return Carrier<Kind>::iterator(0);
}

template <class Kind>
typename Carrier<Kind>::iterator Carrier<Kind>::begin() 
{
  return Carrier<Kind>::iterator(first_);
}

template <class Kind>
typename Carrier<Kind>::iterator Carrier<Kind>::end() 
{
  return Carrier<Kind>::iterator(0);
}

template<class Kind>
void swap(Carrier<Kind> & c1, Carrier<Kind> & c2)
{
  c1.swap(c2);
}            

#ifdef __GXX_EXPERIMENTAL_CXX0X__   
template <class Kind>
Carrier<Kind>::Carrier (Carrier<Kind> && c)
  : first_(0), last_(0), size_(0)
{
  this->swap(c);
}

template <class Kind>
Carrier<Kind> & Carrier<Kind>::operator = (Carrier<Kind> && c)
{
  this->swap(c);
  return *this;
}

#endif // __GXX_EXPERIMENTAL_CXX0X__

/************************ Conductor *************************/
  
template <class Kind>
Conductor<Kind>::Conductor(Node<Kind> * n)
  : ptr_(n)
{ 
  if(!ptr_)
    return;
  if(ptr_->single_)
    return;
  if(ptr_->many_->size() > 0)
    iter_ = ptr_->many_->begin();
  else
    ptr_ = 0; 
}

template <class Kind>
Conductor<Kind>::Conductor(Conductor const & c)
  : ptr_(c.ptr_), iter_(c.iter_)
{ }

template <class Kind>
Conductor<Kind> & Conductor<Kind>::operator = (const Conductor<Kind> &c)
{
  ptr_ = c.ptr_;
  iter_ = c.iter_;
  return *this;
}

template <class Kind>
bool Conductor<Kind>::operator == (const Conductor & c) const
{
  if(ptr_ == c.ptr_)
  {     
    if(!ptr_)
      return true;
    if(ptr_->single_)
      return true;
    if(iter_ == c.iter_)
      return true;
    else
      return false;
  }
  else
    return false;
}

template <class Kind>
bool Conductor<Kind>::operator != (const Conductor & c) const
{
  return !(*this == c);
}

template <class Kind>
void Conductor<Kind>::search_next()
{
  while(ptr_)
  {
    ptr_ = ptr_->next_;
    if(!ptr_)
      break;
    if(ptr_->single_)
      break;
    else 
    {
      if(ptr_->many_->size() > 0)
      {
        iter_ = ptr_->many_->begin();
        break;
      }
    }
  }
}

template <class Kind>
Conductor<Kind> & Conductor<Kind>::operator ++()
{
  if(!ptr_)
    throw std::out_of_range("Conductor is NULL");
  if(ptr_->single_)
  {
    search_next();
  }
  else
  {
    if(++iter_ == ptr_->many_->end())
      search_next();
  }
  
  return *this;
}

template <class Kind>
Conductor<Kind> Conductor<Kind>::operator ++(int)
{
  Conductor<Kind> temp(*this);
  ++*this;
  return temp;
}

template <class Kind>
Kind & Conductor<Kind>::operator *() const
{
  if(!ptr_)
    throw std::out_of_range("Conductor is NULL");
  if(ptr_->single_)
    return *(ptr_->single_);
  else
    return *iter_;
}


/************************ ConstConductor *************************/
  
template <class Kind>
ConstConductor<Kind>::ConstConductor(Node<Kind> const * n)
  : ptr_(n)
{ 
  if(!ptr_)
    return;
  if(ptr_->single_)
    return;
  if(ptr_->many_->size() > 0)
    iter_ = ptr_->many_->begin();
  else
    ptr_ = 0; 
}

template <class Kind>
ConstConductor<Kind>::ConstConductor(ConstConductor const & c)
  : ptr_(c.ptr_), iter_(c.iter_)
{ }

template <class Kind>
ConstConductor<Kind>::ConstConductor(Conductor<Kind> const & c)
  : ptr_(c.ptr_), iter_(c.iter_)
{ }

template <class Kind>
ConstConductor<Kind> & ConstConductor<Kind>::operator = (const ConstConductor<Kind> &c)
{
  ptr_ = c.ptr_;
  iter_ = c.iter_;
  return *this;
}

template <class Kind>
bool ConstConductor<Kind>::operator == (const ConstConductor & c) const
{
  if(ptr_ == c.ptr_)
  {     
    if(!ptr_)
      return true;
    if(ptr_->single_)
      return true;
    if(iter_ == c.iter_)
      return true;
    else
      return false;
  }
  else
    return false;
}

template <class Kind>
bool ConstConductor<Kind>::operator != (const ConstConductor & c) const
{
  return !(*this == c);
}

template <class Kind>
void ConstConductor<Kind>::search_next()
{
  while(ptr_)
  {
    ptr_ = ptr_->next_;
    if(!ptr_)
      break;
    if(ptr_->single_)
      break;
    else 
    {
      if(ptr_->many_->size() > 0)
      {
        iter_ = ptr_->many_->begin();
        break;
      }
    }
  }
}

template <class Kind>
ConstConductor<Kind> & ConstConductor<Kind>::operator ++()
{
  if(!ptr_)
    throw std::out_of_range("ConstConductor is NULL");
  if(ptr_->single_)
  {
    search_next();
  }
  else
  {
    if(++iter_ == ptr_->many_->end())
      search_next();
  }
  
  return *this;
}

template <class Kind>
ConstConductor<Kind> ConstConductor<Kind>::operator ++(int)
{
  ConstConductor<Kind> temp(*this);
  ++*this;
  return temp;
}

template <class Kind>
const Kind & ConstConductor<Kind>::operator *() const
{
  if(!ptr_)
    throw std::out_of_range("ConstConductor is NULL");
  if(ptr_->single_)
    return *(ptr_->single_);
  else
    return *iter_;
}


} // namespace LEESA

namespace std
{
  template<class Kind>
  void swap(LEESA::Carrier<Kind> & c1, LEESA::Carrier<Kind> & c2)
  {
    c1.swap(c2);
  }            
}


#endif // __CARRIER_OPTIMIZED_CPP_

