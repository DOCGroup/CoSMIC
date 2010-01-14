#ifndef __CARRIER_OPTIMIZED_H_
#define __CARRIER_OPTIMIZED_H_

#ifndef DOMAIN_NAMESPACE
#error "Please #define DOMAIN_NAMESPACE"
#endif

#include <boost/type_traits.hpp>

namespace LEESA {

namespace SingleStage {
  template <class Kind> struct ConstCast;
}

template <class U> class Carrier;
template <class U> class Conductor;
template <class U> class ConstConductor;

template <class U>
class Node
{
  U * const single_;
  typename ContainerTraits<U>::Container * const many_;
  Node<U> *next_;
  Node<U> *prev_;

public:
    
  Node(Node const & n)
    : single_(n.single_), 
      many_(n.many_), 
      next_(n.next_), 
      prev_(n.prev_)
  {  }

  Node(U & u)
    : single_(&u), many_(0), next_(0), prev_(0)
  {  }

  Node(U * const u)
    : single_(u), many_(0), next_(0), prev_(0)
  {  }

  Node(typename ContainerTraits<U>::Container & container)
    : single_(0), many_(&container), next_(0), prev_(0)
  {  }

  Node(typename ContainerTraits<U>::Container * const container)
    : single_(0), many_(container), next_(0), prev_(0)
  {  }

  friend class Carrier<U>;
  friend class ConstConductor<U>;
  friend class Conductor<U>;
  friend class LEESA::SingleStage::ConstCast<U>;
};

template <class U>
class Conductor
{
  Node<U> * ptr_;
  typename ContainerTraits<U>::Container::iterator iter_;
  void search_next();

  public:
      
  typedef U & value_type;
  typedef U & reference;
  typedef U * pointer;
  typedef ptrdiff_t difference_type;
  typedef std::forward_iterator_tag iterator_category;

  Conductor(Node<U>  * = 0);
  Conductor(Conductor const &);
  Conductor & operator = (const Conductor &);
  bool operator == (const Conductor &) const;
  bool operator != (const Conductor &) const;
  Conductor& operator ++();
  Conductor operator ++(int);
  U & operator *() const;
};

template <class U>
class ConstConductor
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

  ConstConductor(Node<U> const  * = 0);
  ConstConductor(ConstConductor const &);
  ConstConductor(Conductor<U> const &);
  ConstConductor & operator = (const ConstConductor &);
  bool operator == (const ConstConductor &) const;
  bool operator != (const ConstConductor &) const;
  ConstConductor& operator ++();
  ConstConductor operator ++(int);
  const U & operator *() const;
};

template <class U>
class Carrier : public std::unary_function<Carrier<U>, Carrier<U> >
{
  Node<U> *first_;
  Node<U> *last_;
  unsigned int size_;
  
  void destroy();
  void push_back(U * const);
  void push_back(Node<U> &);

public:
  
  BOOST_CLASS_REQUIRE(U, LEESA, DomainKindConcept);
  BOOST_MPL_ASSERT((LEESA::DomainKindConcept<U>));
  // This is an important concept. Don't remove.

  typedef Carrier<U> expression_type;
  typedef U result_kind;
  typedef U argument_kind;
  typedef Carrier<U> result_type;
  typedef Carrier<U> argument_type;
  
  typedef Conductor<U> iterator;
  typedef Conductor<U> const_iterator;
  //typedef ConstConductor<U> const_iterator;
  typedef U & reference;
  //typedef const U & const_reference;
  
  friend class ::LEESA::SingleStage::ConstCast<U>;
  
  template <class Z>
  struct rebind
  {
    typedef Carrier<Z> type;
  };

  explicit Carrier();
  
  Carrier(const Carrier &); 

  Carrier(const U &);       // Neglects data
  Carrier(U &);             // Maintains data
  Carrier(typename ContainerTraits<U>::Container &); // Maintains data
  
  template <class Z>
  Carrier (Carrier<Z> const &);

  template <class ForwardIterator> 
  Carrier(ForwardIterator, ForwardIterator); //Iterator pair
  
  Carrier& operator = (const Carrier &); 
  
  void swap (Carrier &) throw(); // Non-throw swap
  void push_back(U &);
  void push_back(typename ContainerTraits<U>::Container &);
  void push_back(Carrier &);
 
  Carrier const & operator ()(Carrier const &) const;

  //void push_back(const U &);
  //void push_back(const typename ContainerTraits<U>::Container &);
  //Carrier(typename ContainerTraits<U>::Container &);

  
  bool empty();
  unsigned int size() const;
  
  iterator begin() const;
  iterator end() const;

  iterator begin();
  iterator end();
  
  operator typename ContainerTraits<U>::Container () const;
  
  ~Carrier() throw(); 

#ifndef LEESA_FOR_UDM 

  //Carrier (typename DOMAIN_NAMESPACE::SchemaTraits<U>::Optional &);
  //void push_back (typename DOMAIN_NAMESPACE::SchemaTraits<U>::Optional &);

#endif // LEESA_FOR_UDM

#ifdef __GXX_EXPERIMENTAL_CXX0X__   
  Carrier (Carrier && c);
  Carrier & operator = (Carrier && c);
#endif // __GXX_EXPERIMENTAL_CXX0X__

};

template <class U>
void swap(Carrier<U>& t, Carrier<U> &u);

} // namespace LEESA

namespace std {
  template <class U>
  void swap(LEESA::Carrier<U>& t, LEESA::Carrier<U> &u);
}


#include "Carrier_Optimized.cpp"

#endif //  __CARRIER_OPTIMIZED_H_

