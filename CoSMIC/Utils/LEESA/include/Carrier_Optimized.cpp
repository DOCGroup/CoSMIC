#ifndef __CARRIER_OPTIMIZED_CPP_
#define __CARRIER_OPTIMIZED_CPP_

#include "Carrier_Optimized.h"
#include <stdexcept>

namespace LEESA {

template <class U>
Carrier<U>::Carrier ()
  : first_(0), last_(0), size_(0)
{}

template <class U>
Carrier<U>::Carrier(U & u)
  : first_(0), last_(0), size_(0)
{
  push_back(u);
}

template <class U>
Carrier<U>::Carrier(const Carrier<U> & c)
  : first_(0), last_(0), size_(0)
{
  for(Node<U> * iter = c.first_; iter != 0; iter=iter->next_)
    push_back (*iter);
}

template <class U>
void Carrier<U>::swap(Carrier<U> & c) throw() // Non-throw swap idiom
{
  std::swap(this->first_, c.first_);
  std::swap(this->last_, c.last_);
  std::swap(this->size_, c.size_);
}

template <class U>
template <class ForwardIterator> // Iterator pair idiom
Carrier<U>::Carrier(ForwardIterator start, ForwardIterator end)
  : first_(0), last_(0), size_(0)
{
  for(;start != end; ++start)
    push_back (&*start);
}

template <class U>
Carrier<U>& Carrier<U>::operator = (const Carrier<U> & c) //copy and swap idiom
{
  Carrier<U>(c).swap(*this);
  return *this;
}

template <class U>
void Carrier<U>::push_back(U * const u)
{
  if (empty())
  {
     last_ = static_cast<Node<U> *>(operator new (sizeof(Node<U>)));
     new (last_) Node<U>(u);
     first_ = last_;
  }
  else 
  {
     last_->next_ = static_cast<Node<U> *>(operator new (sizeof(Node<U>)));
     new (last_->next_) Node<U>(u);
     last_->next_->prev_ = last_;
     last_ = last_->next_;
  }
  ++size_;
}

template <class U>
void Carrier<U>::push_back(U & u)
{
  push_back(&u);
}

template <class U>
void Carrier<U>::push_back(const U & u)
{
  push_back(const_cast<U &> (u));
}

template <class U>
void Carrier<U>::push_back(Node<U> & n)
{
  if(n.single_)
    push_back(n.single_);
  else if(n.many_)
    push_back(*n.many_);
}

template <class U>
void Carrier<U>::push_back(Carrier<U> & carrier)
{
  if(carrier.empty())
    return;
  
  for(Node<U> * temp(carrier.first_); temp != 0; temp=temp->next_)
    push_back (*temp);

}
  
template <class U>
void Carrier<U>::push_back(typename ContainerTraits<U>::Container & container)
{
  if(container.empty())
    return;

  if (empty())
  {
     last_ = static_cast<Node<U> *>(operator new (sizeof(Node<U>)));
     new (last_) Node<U>(container);
     first_ = last_;
  }
  else 
  {
     last_->next_ = static_cast<Node<U> *>(operator new (sizeof(Node<U>)));
     new (last_->next_) Node<U>(container);
     last_->next_->prev_ = last_;
     last_ = last_->next_;
  }
  size_+=container.size();
}

template <class U>
void Carrier<U>::push_back(const typename ContainerTraits<U>::Container & container)
{
  push_back(const_cast<typename ContainerTraits<U>::Container &>(container));
}

template <class U>
void Carrier<U>::destroy()
{
  for(Node<U> * iter = first_; iter != 0; iter=iter->next_)
  {
    iter->~Node<U>();
    operator delete(iter);
  }
  first_ = 0;
  last_ = 0;
  size_ = 0;
}

template<class U>
Carrier<U>::~Carrier() throw()
{
  destroy();
}

template <class U>
bool Carrier<U>::empty()
{
  return (size_ == 0);
}

template <class U>
unsigned int Carrier<U>::size() const 
{
  return size_;
}

template <class U>
Carrier<U>::operator typename ContainerTraits<U>::Container() const
{
  typename ContainerTraits<U>::Container temp;
  temp.reserve(this->size());
  std::copy(this->begin(), this->end(), std::back_inserter(temp));
  return temp;
}

#ifndef LEESA_FOR_UDM

template <class U>
Carrier<U>::Carrier (typename DOMAIN_NAMESPACE::SchemaTraits<U>::Optional & o)
  : first_(0), last_(0), size_(0)
{
  this->push_back(o);
}

template <class U>
void Carrier<U>::push_back (typename DOMAIN_NAMESPACE::SchemaTraits<U>::Optional & o)
{
  if(o.present())
    this->push_back(&o.get());
}

#endif // LEESA_FOR_UDM

template <class U>
typename Carrier<U>::const_iterator Carrier<U>::begin() const
{
  return Carrier<U>::const_iterator(first_);
}

template <class U>
typename Carrier<U>::const_iterator Carrier<U>::end() const
{
  return Carrier<U>::const_iterator(0);
}

template <class U>
typename Carrier<U>::iterator Carrier<U>::begin() 
{
  return Carrier<U>::iterator(first_);
}

template <class U>
typename Carrier<U>::iterator Carrier<U>::end() 
{
  return Carrier<U>::iterator(0);
}

template<class U>
void swap(Carrier<U> & c1, Carrier<U> & c2)
{
  c1.swap(c2);
}            

/************************ Conductor *************************/
  
template <class U>
Conductor<U>::Conductor(Node<U> * n)
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

template <class U>
Conductor<U>::Conductor(Conductor const & c)
  : ptr_(c.ptr_), iter_(c.iter_)
{ }

template <class U>
Conductor<U> & Conductor<U>::operator = (const Conductor<U> &c)
{
  ptr_ = c.ptr_;
  iter_ = c.iter_;
  return *this;
}

template <class U>
bool Conductor<U>::operator == (const Conductor & c) const
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

template <class U>
bool Conductor<U>::operator != (const Conductor & c) const
{
  return !(*this == c);
}

template <class U>
void Conductor<U>::search_next()
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

template <class U>
Conductor<U> & Conductor<U>::operator ++()
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

template <class U>
Conductor<U> Conductor<U>::operator ++(int)
{
  Conductor<U> temp(*this);
  ++*this;
  return temp;
}

template <class U>
U & Conductor<U>::operator *() const
{
  if(!ptr_)
    throw std::out_of_range("Conductor is NULL");
  if(ptr_->single_)
    return *(ptr_->single_);
  else
    return *iter_;
}


/************************ ConstConductor *************************/
  
template <class U>
ConstConductor<U>::ConstConductor(Node<U> const * n)
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

template <class U>
ConstConductor<U>::ConstConductor(ConstConductor const & c)
  : ptr_(c.ptr_), iter_(c.iter_)
{ }

template <class U>
ConstConductor<U>::ConstConductor(Conductor<U> const & c)
  : ptr_(c.ptr_), iter_(c.iter_)
{ }

template <class U>
ConstConductor<U> & ConstConductor<U>::operator = (const ConstConductor<U> &c)
{
  ptr_ = c.ptr_;
  iter_ = c.iter_;
  return *this;
}

template <class U>
bool ConstConductor<U>::operator == (const ConstConductor & c) const
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

template <class U>
bool ConstConductor<U>::operator != (const ConstConductor & c) const
{
  return !(*this == c);
}

template <class U>
void ConstConductor<U>::search_next()
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

template <class U>
ConstConductor<U> & ConstConductor<U>::operator ++()
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

template <class U>
ConstConductor<U> ConstConductor<U>::operator ++(int)
{
  ConstConductor<U> temp(*this);
  ++*this;
  return temp;
}

template <class U>
const U & ConstConductor<U>::operator *() const
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
  template<class U>
  void swap(LEESA::Carrier<U> & c1, LEESA::Carrier<U> & c2)
  {
    c1.swap(c2);
  }            
}


#endif // __CARRIER_OPTIMIZED_CPP_

