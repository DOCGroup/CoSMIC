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

template <class Kind> class Carrier;
template <class Kind> class Conductor;
template <class Kind> class ConstConductor;
template <class Kind> class NodeIterator;

template <class Kind>
class Node
{
  Kind * const single_;
  typename ContainerTraits<Kind>::Container * const many_;
  Node<Kind> *next_;
  Node<Kind> *prev_;

public:
    
  Node(Node const & n)
    : single_(n.single_), 
      many_(n.many_), 
      next_(n.next_), 
      prev_(n.prev_)
  {  }

  Node(Kind & u)
    : single_(&u), many_(0), next_(0), prev_(0)
  {  }

  Node(Kind * const u)
    : single_(u), many_(0), next_(0), prev_(0)
  {  }

  Node(typename ContainerTraits<Kind>::Container & container)
    : single_(0), many_(&container), next_(0), prev_(0)
  {  }

  Node(typename ContainerTraits<Kind>::Container * const container)
    : single_(0), many_(container), next_(0), prev_(0)
  {  }

  friend class Carrier<Kind>;
  friend class ConstConductor<Kind>;
  friend class Conductor<Kind>;
  friend class NodeIterator<Kind>;
  friend class LEESA::SingleStage::ConstCast<Kind>;
};

template <class Kind>
class Conductor
{
  Node<Kind> * ptr_;
  typename ContainerTraits<Kind>::Container::iterator iter_;
  void search_next();

  public:
      
  typedef Kind & value_type;
  typedef Kind & reference;
  typedef Kind * pointer;
  typedef ptrdiff_t difference_type;
  typedef std::forward_iterator_tag iterator_category;

  Conductor(Node<Kind>  * = 0);
  bool operator == (const Conductor &) const;
  bool operator != (const Conductor &) const;
  Conductor& operator ++();
  Conductor operator ++(int);
  Kind & operator *() const;
};

template <class Kind>
class ConstConductor
{
  Node<Kind> const * ptr_;
  typename ContainerTraits<Kind>::Container::const_iterator iter_;
  void search_next();

  public:
      
  typedef const Kind & value_type;
  typedef const Kind & reference;
  typedef const Kind * pointer;
  typedef ptrdiff_t difference_type;
  typedef std::forward_iterator_tag iterator_category;

  ConstConductor(Node<Kind> const  * = 0);
  ConstConductor(Conductor<Kind> const &);
  bool operator == (const ConstConductor &) const;
  bool operator != (const ConstConductor &) const;
  ConstConductor& operator ++();
  ConstConductor operator ++(int);
  const Kind & operator *() const;
};

template <class Kind>
class NodeIterator 
{
  Node<Kind> * ptr_;
  typename ContainerTraits<Kind>::Container::iterator iter_;

  void advance();

  public:
      
  NodeIterator(Node<Kind>  * = 0);
  bool operator == (const NodeIterator &) const;
  bool operator != (const NodeIterator &) const;
  void next();
  Kind * get() const;
};

template <class Kind>
class Carrier : public std::unary_function<Carrier<Kind>, Carrier<Kind> >
{
  Node<Kind> *first_;
  Node<Kind> *last_;
  unsigned int size_;
  
  void destroy();
  void push_back(Kind * const);
  void push_back(Node<Kind> *);

public:
  
  BOOST_CLASS_REQUIRE(Kind, LEESA, DomainKindConcept);
  BOOST_MPL_ASSERT((LEESA::DomainKindConcept<Kind>));
  // This is an important concept. Don't remove.

  typedef Carrier<Kind> expression_type;
  typedef Kind result_kind;
  typedef Kind argument_kind;
  typedef Carrier<Kind> result_type;
  typedef Carrier<Kind> argument_type;
  
  typedef Conductor<Kind> iterator;
  typedef Conductor<Kind> const_iterator;
  typedef Kind & reference;
  //typedef const Kind & const_reference;
  
  friend class ::LEESA::SingleStage::ConstCast<Kind>;
  
  template <class Z>
  struct rebind
  {
    typedef Carrier<Z> type;
  };

  explicit Carrier();
  
  Carrier(const Carrier &); 

  Carrier(const Kind &);       // Neglects data
  Carrier(Kind &);             // Maintains data
  Carrier(typename ContainerTraits<Kind>::Container &); // Maintains data
  
  template <class Z>
  Carrier (Carrier<Z> const &);

  template <class ForwardIterator> 
  Carrier(ForwardIterator, ForwardIterator); //Iterator pair
  
  Carrier& operator = (const Carrier &); 
  
  void swap (Carrier &) throw(); // Non-throw swap

  void push_back(Kind &);
  void push_back(typename ContainerTraits<Kind>::Container &);
  void push_back(Carrier &);
  
  /* This operation is very similar to std::list<T>::splice. */
  void move_carrier(Carrier &);

  /* All the following 3 push_back functions do const_cast. */
  void push_back(const Kind &);
  void push_back(const typename ContainerTraits<Kind>::Container &);
  void push_back(const Carrier &);
 
  Carrier const & operator ()(Carrier const &) const;

  bool empty() const;
  unsigned int size() const;
  
  iterator begin() const;
  iterator end() const;

  iterator begin();
  iterator end();
  
  operator typename ContainerTraits<Kind>::Container () const;
  
  ~Carrier() throw(); 

#ifndef LEESA_FOR_UDM 

  void push_back (typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Optional &);
  void push_back (const typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Optional &);
  NodeIterator<Kind> begin_node_iterator() const;
  NodeIterator<Kind> end_node_iterator() const;

#endif // LEESA_FOR_UDM

#ifdef __GXX_EXPERIMENTAL_CXX0X__   
  Carrier (Carrier && c);
  Carrier & operator = (Carrier && c);
#endif // __GXX_EXPERIMENTAL_CXX0X__

};

template <class Kind>
void swap(Carrier<Kind>& t, Carrier<Kind> &u);

} // namespace LEESA

namespace std {
  template <class Kind>
  void swap(LEESA::Carrier<Kind>& t, LEESA::Carrier<Kind> &u);
}


#include "Carrier_Optimized.cpp"

#endif //  __CARRIER_OPTIMIZED_H_

