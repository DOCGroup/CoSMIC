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

#ifdef OPTIMIZED_CARRIER
#include "Carrier_optimized.h"
#else
#include "Carrier_simple.h"
#endif // OPTIMIZED_CARRIER

namespace LEESA {
namespace SingleStage {

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

