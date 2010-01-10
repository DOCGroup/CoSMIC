#ifndef __LEESA_SINGLE_STAGE_H_
#define __LEESA_SINGLE_STAGE_H_

#ifndef DOMAIN_NAMESPACE
#error "Please #define DOMAIN_NAMESPACE"
#endif

#include "Kind_Traits.h"
#include "LEESA_Concepts.h"

#include <boost/foreach.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits.hpp>
#include <vector>

namespace LEESA {

namespace SingleStage {

template <class Kind>
struct Carrier : public ContainerTraits<Kind>::Container
{
  typedef typename ContainerTraits<Kind>::Container super;

  Carrier () {}

  Carrier (const Kind & k) 
  {
    this->push_back(k);
  }

  Carrier (const Carrier & k) : super(k) {}

  Carrier & operator = (const Carrier & c)
  {
    Carrier<Kind>(c).swap(*this);
    return *this;
  }

  void swap (Carrier & c1, Carrier & c2)
  {
    using namespace std;
    // This swap could be from super's namespace.
    // If such a swap function is not there, std:swap will be used.
    swap(super(c1), super(c2));
  }

  using super::push_back;
  void push_back(Carrier const & c)
  {
    if(this->empty())
      super::operator = (c);
    else
      this->insert(this->end(), c.begin(), c.end());
  }

  void push_back(super const & in)
  {
    std::cout << "push_back (super const &)\n";
    if(this->empty())
      super::operator = (in);
    else
      this->insert(this->end(), in.begin(), in.end());
  }

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
    this->push_back(ca);
  }

  void push_back(Udm::ChildrenAttr<Kind> const & ca) 
  {
    this->push_back(ca);
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

  Carrier (Carrier && c) : super(std::move(c)) {}
  
  Carrier & operator = (Carrier && c)
  {
    super::operator = (std::move(c));
    return *this;
  }
 
  void push_back(Carrier && c)
  {
    if(this->empty())
      *this = std::move(c);
    else
      this->insert(this->end(), c.begin(), c.end());
  }

  void push_back(super && in)
  {
    std::cout << "push_back (super &&)\n";
    if(this->empty())
      super::operator = (std::move(in));
    else
      this->insert(this->end(), in.begin(), in.end());
  }
/*
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
*/  
#endif // __GXX_EXPERIMENTAL_CXX0X__

};

template <class T>
struct IsDomainVisitorBaseOf
{
  typedef IsDomainVisitorBaseOf type;
#ifndef LEESA_NO_VISITOR
  enum { value = boost::is_base_of<SchemaVisitor, T>::value };
#else
  enum { value = 0 };
#endif // LEESA_NO_VISITOR
};

template <class ParentKind, class ChildKind>
typename 
  boost::disable_if <IsDomainVisitorBaseOf<ChildKind>,
                     Carrier<ChildKind> >::type

operator >> (Carrier<ParentKind> const & cpk, ChildKind const & ck)
{
  BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<ParentKind, ChildKind>));
  Carrier<ChildKind> retval;
  BOOST_FOREACH(ParentKind const & parent, cpk)
  {
#ifdef LEESA_FOR_UDM
    retval.push_back(parent.template children_kind<ChildKind>());
#else
    retval.push_back(children_kind(parent, ck));
#endif // LEESA_FOR_UDM
  }
  return retval;
}

template <class Kind>
Carrier<Kind>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
operator >> (Carrier<Kind> && ck, SchemaVisitor & v)
#else
operator >> (Carrier<Kind> const & ck, SchemaVisitor & v)
#endif // __GXX_EXPERIMENTAL_CXX0X__
{
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<Kind>));
  BOOST_FOREACH(Kind const & kind, ck)
  {
#ifdef LEESA_FOR_UDM
    kind.Accept(v);
#else
    kind.accept(v);
#endif // LEESA_FOR_UDM
  }
#ifdef __GXX_EXPERIMENTAL_CXX0X__
  return std::move(ck);
#else
  return ck;
#endif // __GXX_EXPERIMENTAL_CXX0X__
}

} // namespace SingleStage
} // namespace LEESA



#endif // __LEESA_SINGLE_STAGE_H_

