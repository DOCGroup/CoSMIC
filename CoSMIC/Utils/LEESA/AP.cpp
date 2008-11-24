#ifndef __AP_CPP
#define __AP_CPP

namespace LEESA {

template <class L, class H> struct DescendantOp;

template <class L, class H>
struct ET <DescendantOp<L, H> > 
	: public ETBase <DescendantOp<L, H> > {};

template <class L, class H>
struct DescendantOp : LEESAUnaryFunction<L, H>, OpBase
{
  typedef LEESA::LEESAUnaryFunction<L, H> Super;
  SUPER_TYPEDEFS(Super);
	typedef typename ChainExpr<L, DescendantOp> expression_type;

  BOOST_CONCEPT_ASSERT((Udm::DescendantKindConcept<argument_kind, result_kind>));

  result_type retval_;

  struct Accumulate
  {
    template <class K>
    struct rebind 
    {
      typedef Accumulate type;
    };
    
    result_type & retval_;
    Accumulate (result_type & r)
      : retval_(r) {}

    template <class K>
    void operator () (K arg)
    {
      typedef typename ET<K>::argument_kind Kind;
      retval_.Union(evaluate(arg, Kind() >> CastFromTo(Kind(), result_kind())));
    }
    void operator () (result_type k)
    {
		  retval_.Union(k);
    }
  };
  result_type operator () (argument_type const & arg)
  {
    Accumulate acc(retval_);
    evaluate(arg, argument_kind() >> FullTD(argument_kind(), acc));
    return retval_;
  }

};

template <class L, class H>
DescendantOp<typename ET<L>::result_type, 
             typename ET<H>::result_type> 
DescendantFrom (L, H)
{
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<L>));
	BOOST_CONCEPT_ASSERT((Udm::UdmKindConcept<H>));
  BOOST_CONCEPT_ASSERT((Udm::DescendantKindConcept<L,H>));

	typedef typename ET<L>::argument_type argument_type;
	typedef typename ET<H>::result_type result_type;

	return DescendantOp<argument_type, result_type>();
}




} // namespace LEESA

#endif // __AP_CPP 

