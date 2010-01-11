#ifndef __CARRIER_OPTIMIZED_H_
#define __CARRIER_OPTIMIZED_H_

#ifndef DOMAIN_NAMESPACE
#error "Please #define DOMAIN_NAMESPACE"
#endif

namespace LEESA {

namespace SingleStage {

template <class U>
class Carrier;

template <class U>
class Conductor;

template <class U>
class Node
{
  const U * const single_;
  const typename ContainerTraits<U>::Container * const many_;
  Node<U> *next_;
  Node<U> *prev_;

public:
    
  Node(Node const & n)
    : single_(n.single_), 
      many_(n.many_), 
      next_(n.next_), 
      prev_(n.prev_)
  {  }

  Node(const U & u)
    : single_(&u), many_(0), next_(0), prev_(0)
  {  }

  Node(const U * const u)
    : single_(u), many_(0), next_(0), prev_(0)
  {  }

  Node(const typename ContainerTraits<U>::Container & container)
    : single_(0), many_(&container), next_(0), prev_(0)
  {  }

  Node(const typename ContainerTraits<U>::Container * const container)
    : single_(0), many_(container), next_(0), prev_(0)
  {  }

  friend class Carrier<U>;
  friend class Conductor<U>;
};


template <class U>
class Conductor
{
  Node<U> const * ptr_;
  typename ContainerTraits<U>::Container::const_iterator iter_;
  void search_next();

  public:
      
  typedef const U & value_type;
  typedef const U & reference;
  typedef const U * pointer;
  typedef ptrdiff_t difference_type;
  typedef std::forward_iterator_tag iterator_category;

  Conductor(Node<U> const * = 0);
  Conductor(Conductor const &);
  Conductor & operator = (const Conductor &);
  bool operator == (const Conductor &) const;
  bool operator != (const Conductor &) const;
  Conductor& operator ++();
  Conductor operator ++(int);
  const U& operator *() const;
};

template <class U>
class Carrier
{
  Node<U> *first_;
  Node<U> *last_;
  unsigned int size_;
  
  void destroy();
  void push_back(const U * const);

public:

  typedef Conductor<U> iterator;
  typedef Conductor<U> const_iterator;

  Carrier();
  Carrier(const Carrier &);
  Carrier(const U &);

  template <class ForwardIterator> 
  Carrier(ForwardIterator, ForwardIterator); //Iterator pair
  
  Carrier& operator = (const Carrier &); 
  
  void swap (Carrier &) throw(); // Non-throw swap
  void push_back(const U &);
  void push_back(const Node<U> &);
  void push_back(const typename ContainerTraits<U>::Container &);
  void push_back(const Carrier &);
  bool empty();
  unsigned int size()const;
  
  const_iterator begin() const;
  const_iterator end() const;
  operator typename ContainerTraits<U>::Container () const;
  
  ~Carrier() throw(); 

#ifndef LEESA_FOR_UDM 

  Carrier (typename DOMAIN_NAMESPACE::SchemaTraits<U>::Optional const & o);
  void push_back (typename DOMAIN_NAMESPACE::SchemaTraits<U>::Optional const & o);

#endif // LEESA_FOR_UDM
};

template <class U>
void swap(Carrier<U>& t, Carrier<U> &u);

} // namespace SingleStage
} // namespace LEESA

namespace std {
  template <class U>
  void swap(LEESA::SingleStage::Carrier<U>& t, LEESA::SingleStage::Carrier<U> &u);
}


#include "Carrier_optimized.cpp"

#endif //  __CARRIER_OPTIMIZED_H_

