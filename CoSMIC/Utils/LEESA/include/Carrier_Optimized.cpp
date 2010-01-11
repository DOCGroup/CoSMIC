#ifndef __CARRIER_OPTIMIZED_CPP_
#define __CARRIER_OPTIMIZEd_CPP_

#include "Carrier_optimized.h"
#include <stdexcept>

namespace LEESA {

namespace SingleStage {

template <class U>
Carrier<U>::Carrier ()
  : first_(0), last_(0), size_(0)
{}

template <class U>
Carrier<U>::Carrier(const U & u)
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
void Carrier<U>::swap(Carrier<U> &t) throw() // Non-throw swap idiom
{
     std::swap(this->first_, t.first_);
     std::swap(this->last_, t.last_);
     std::swap(this->size_, t.size_);
}

template <class U>
template <class ForwardIterator> // Iterator pair idiom
Carrier<U>::Carrier(ForwardIterator start, ForwardIterator end)
  : first_(0), last_(0), size_(0)
{
  for(;start != end; ++start)
  {
    push_back (&*start);
  }
}

template <class U>
Carrier<U>& Carrier<U>::operator = (const Carrier<U> &t) //copy and swap idiom
{
  Carrier<U>(t).swap(*this);
  return *this;
}

template <class U>
void Carrier<U>::push_back(const U * const u)
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
void Carrier<U>::push_back(const U & u)
{
  push_back(&u);
}

template <class U>
void Carrier<U>::push_back(const Node<U> & n)
{
  if(n.single_)
    push_back(n.single_);
  else if(n.many_)
    push_back(*n.many_);
}

template <class U>
void Carrier<U>::push_back(const Carrier<U> & carrier)
{
  if(carrier.empty())
    return;
  
  for(Node<U> * temp(carrier.first_); temp != 0; temp=temp->next_)
  {
    push_back (*temp);
  }

}
  
template <class U>
void Carrier<U>::push_back(const typename ContainerTraits<U>::Container & container)
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
unsigned int Carrier<U>::size()const 
{
  return size_;
}

template <class U>
Carrier<U>::operator typename ContainerTraits<U>::Container() const
{
  typename ContainerTraits<U>::Container temp;
  temp.reserve(this->size());
  temp.insert(temp.end(), begin(), end());
  return temp;
}

#ifndef LEESA_FOR_UDM

template <class U>
Carrier<U>::Carrier (typename DOMAIN_NAMESPACE::SchemaTraits<U>::Optional const & o)
  : first_(0), last_(0), size_(0)
{
  this->push_back(o);
}

template <class U>
void Carrier<U>::push_back (typename DOMAIN_NAMESPACE::SchemaTraits<U>::Optional const & o)
{
  if(o.present())
    this->push_back(&o.get());
}

#endif // LEESA_FOR_UDM

template <class U>
Conductor<U>::Conductor(Node<U> const * n)
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
const U& Conductor<U>::operator *() const
{
  if(!ptr_)
    throw std::out_of_range("Conductor is NULL");
  if(ptr_->single_)
    return *(ptr_->single_);
  else
    return *iter_;
}

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

template<class U>
void swap(Carrier<U>& t, Carrier<U> &u)
{
  t.swap(u);
}            

} // namespace SingleStage
} // namespace LEESA

namespace std
{
  template<class U>
  void swap(LEESA::SingleStage::Carrier<U>& t, LEESA::SingleStage::Carrier<U> &u)
  {
    t.swap(u);
  }            
}


#endif // __CARRIER_OPTIMIZEd_CPP_

