#ifndef __CARRIER_SIMPLE_H_
#define __CARRIER_SIMPLE_H_

#ifndef DOMAIN_NAMESPACE
#error "Please #define DOMAIN_NAMESPACE"
#endif

#include <boost/type_traits.hpp>

namespace LEESA {

template <class Kind>
class Carrier : public std::unary_function<Carrier<Kind>, Carrier<Kind> >
{
  public:
  BOOST_CLASS_REQUIRE(Kind, LEESA, DomainKindConcept);
  BOOST_MPL_ASSERT((LEESA::DomainKindConcept<Kind>));
  // This is an important concept. Don't remove.

  typedef typename KindTraits<Kind>::Container Container;
  typedef Carrier<Kind> expression_type;
  typedef Kind result_kind;
  typedef Kind argument_kind;
  typedef Carrier<Kind> result_type;
  typedef Carrier<Kind> argument_type;
  typedef typename Container::iterator iterator;
  typedef typename Container::iterator const_iterator;
  //typedef typename Container::const_iterator const_iterator;

  template <class U>
  struct rebind
  {
    typedef Carrier<U> type;
  };
  
  mutable Container c_;

  explicit Carrier () {}
  
  template <class U>
  Carrier (Carrier<U> const & u_carrier)
  {
    BOOST_MPL_ASSERT((boost::is_base_of<Kind, U>));
    c_.reserve(u_carrier.size());
    c_.insert(c_.end(), u_carrier.begin(), u_carrier.end());
  }

  Carrier (const Carrier & k) : c_(k.c_) { }
  Carrier (const Kind & k) { this->push_back(k); }
  Carrier (const Container & c) : c_(c) { }

  Carrier & operator = (const Carrier & c)
  {
    Carrier<Kind>(c).swap(*this);
    return *this;
  }

  void swap (Carrier & c)
  {
    //using std::swap;
    // I'm hoping that Koenig lookup will pickup the most
    // appropriate swap for whatever Carrier's container is.
    //swap(c1.c_, c2.c_);
    this->c_.swap(c.c_);
  }

  void push_back(Kind const & k)
  {
    c_.push_back(k);
  }

  void push_back(Carrier const & carrier)
  {
    push_back(carrier.c_);
  }

  void move_carrier(Carrier & carrier)
  {
    push_back(carrier.c_);
  }

  void push_back(Container const & in)
  {
    if(c_.empty())
      c_.reserve(in.size());
  
    c_.insert(c_.end(), in.begin(), in.end());
  }

  iterator begin() { return c_.begin(); }
  iterator begin() const { return c_.begin(); }

  iterator end() { return c_.end(); }
  iterator end() const { return c_.end(); }
  
  bool empty() const 
  {
    return c_.empty();
  }
  
  size_t size() const 
  {
    return c_.size();
  }
  
  operator Container () const { return c_; } 
  result_type const & operator () (argument_type const & p) const { return p; }

#ifdef LEESA_FOR_UDM

  Carrier (Udm::ParentAttr<Kind> const & c) 
  {
    this->push_back(c);
  }

  void push_back(Udm::ParentAttr<Kind> const & c) 
  {
    this->push_back(c);
  }

  Carrier(Udm::ChildrenAttr<Kind> const & ca) 
  {
    Kind kind = ca;
    this->push_back(kind);
  }

  void push_back(Udm::ChildrenAttr<Kind> const & ca) 
  {
    Container c = ca;
    this->push_back(c);
  }

#else 

  Carrier (typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Optional const & o)
  {
    this->push_back(o);
  }

  void push_back (typename DOMAIN_NAMESPACE::SchemaTraits<Kind>::Optional const & o)
  {
    if (o.present()) 
    {
      this->push_back(o.get());
    }
  }

#endif // LEESA_FOR_UDM

#ifdef __GXX_EXPERIMENTAL_CXX0X__

  Carrier (Kind && k) 
  {
    this->push_back(std::move(k));
  }

  Carrier (Carrier && c) 
  {
    this->swap(c);
  }
  
  Carrier (Container && c) 
  {
    this->c_.swap(c);
  }
  
  Carrier & operator = (Carrier && c)
  {
    this->swap(c);
    return *this;
  }
 
  Carrier & operator = (Container && c)
  {
    this->c_.swap(c.c_);
    return *this;
  }
 
  void push_back(Kind && k)
  {
    this->push_back(std::move(k));
  }

  void push_back(Carrier && c)
  {
    if(this->empty())
      *this = std::move(c);
    else
      this->insert(this->end(), c.begin(), c.end());
  }

  void push_back(Container && in)
  {
    //std::cout << "push_back (super &&)\n";
    if(this->empty())
      this->c_.swap(in);
    else
      this->insert(this->end(), in.begin(), in.end());
  }

#endif // __GXX_EXPERIMENTAL_CXX0X__

};

template<class U>
void swap(Carrier<U> & c1, Carrier<U> & c2)
{
  c1.swap(c2);
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

#endif // __CARRIER_SIMPLE_H_

