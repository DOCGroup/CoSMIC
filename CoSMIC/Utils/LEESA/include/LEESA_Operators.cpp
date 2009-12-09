#include <boost/regex.hpp>

namespace LEESA {

class OpBase {}; // Base of all the operators

template <class LExpr, class RExpr>
struct DFSChildrenOp : LEESAUnaryFunction <typename ET<LExpr>::result_type, void>, 
                       OpBase
{
  typedef LEESAUnaryFunction <typename ET<LExpr>::result_type, void> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<LExpr, DFSChildrenOp<LExpr, RExpr> > expression_type;

  RExpr expr_;
  
  explicit DFSChildrenOp () {}
  
  explicit DFSChildrenOp (RExpr const & e) : expr_(e) {}

  DFSChildrenOp (DFSChildrenOp const &d) : expr_(d.expr_) {}
  
  result_type operator () (argument_type const & arg)
  {
    typedef typename ET<LExpr>::result_kind parent_kind;
    typedef typename ET<RExpr>::argument_kind child_kind;

    BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<parent_kind, child_kind>));

    typename KindTraits<parent_kind>::Container v = arg;
    BOOST_FOREACH(parent_kind kind, v)
    {
      typename KindTraits<child_kind>::Container children = 
#ifdef LEESA_FOR_UDM
      kind.template children_kind<child_kind>();
#else
      children_kind (kind, child_kind());
#endif // LEESA_FOR_UDM      
      std::for_each(children.begin(), children.end(), expr_);
    }
  }
};

template <class LExpr, class RExpr>
struct DFSOp : LEESAUnaryFunction <typename ET<LExpr>::result_type, void>,
               OpBase
{
  typedef LEESAUnaryFunction <typename ET<LExpr>::result_type, void> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<LExpr, DFSOp<LExpr, RExpr> > expression_type;
  typedef typename ET<LExpr>::result_kind LKind;
  typedef typename ET<RExpr>::argument_kind RKind;

  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<LKind, RKind>));

  RExpr expr_;
  
  explicit DFSOp () {}
  
  explicit DFSOp (RExpr const & e) : expr_(e) {}

  DFSOp (DFSOp const &d) : expr_(d.expr_) {}
  
  result_type operator () (argument_type const & arg)
  {
    typename KindTraits<argument_kind>::Container v = arg;
    std::for_each(v.begin(), v.end(), expr_);
  }
};

template <class E>
struct SelectorOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESA::LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, SelectorOp> expression_type;
  
  typename KindTraits<argument_kind>::Container c_;
  bool logical_not_; 
  
  explicit SelectorOp (argument_type const & kl, bool logical_not = false) 
    : c_(kl), logical_not_(logical_not) {}
  
  SelectorOp (SelectorOp const & sop) 
    : logical_not_(sop.logical_not_), c_(sop.c_) {}
  
  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    typename KindTraits<argument_kind>::Container v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
      typename KindTraits<argument_kind>::Container::iterator i = 
        std::find(c_.begin(), c_.end(), kind);
      if ((i != c_.end()) ^ logical_not_) // Logical not of match, if required
        retval.Union(kind);
    }
    return retval;
  }
  SelectorOp operator ! () const
  {
    SelectorOp selector(*this);
    selector.logical_not_ = !this->logical_not_;
    return selector;
  }
};

template <class L, class H>
struct GetChildrenOp : LEESAUnaryFunction <L,H>, OpBase
{
  typedef LEESA::LEESAUnaryFunction<L, H> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<L, GetChildrenOp<argument_type, result_type> > expression_type;

  explicit GetChildrenOp () {}

  GetChildrenOp (GetChildrenOp const &) {}
  result_type operator () (argument_type const & arg)
  {
    BOOST_CONCEPT_ASSERT((LEESA::ParentChildConcept<argument_kind, result_kind>));

    result_type retval;
    typename KindTraits<argument_kind>::Container v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
#ifdef LEESA_FOR_UDM
      retval.Union(kind.template children_kind<result_kind>());
#else
      retval.Union(children_kind(kind, result_kind()));
#endif // LEESA_FOR_UDM
    }
    return retval;
  }
};

#ifndef LEESA_NO_VISITOR

template <class E>
struct VisitorOp : LEESAUnaryFunction <E>,
                   OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, VisitorOp<argument_type> > expression_type;

  SchemaVisitor & visitor_;

  VisitorOp (SchemaVisitor const &v) 
    : visitor_ (const_cast<SchemaVisitor &> (v)) {}
  
  VisitorOp (const VisitorOp & vop) : visitor_ (vop.visitor_) {}
  
  result_type operator () (argument_type const & arg)
  {
    typename KindTraits<argument_kind>::Container v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
#ifdef LEESA_FOR_UDM
      kind.Accept(visitor_);
#else 
      kind.accept(visitor_);
#endif // LEESA_FOR_UDM
    }
    return arg;
  }
};

#endif // LEESA_NO_VISITOR

template <class E>
struct RegexOp : LEESAUnaryFunction <E>,
                 OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, RegexOp<argument_type> > expression_type;

  boost::regex regex_;
  //std::string regex_;
  bool logical_not_; 
  
  explicit RegexOp (std::string const & str = ".*", bool logical_not = false) 
    : regex_(str), logical_not_ (logical_not) {  }
  
  RegexOp (RegexOp const & reop) 
    : logical_not_ (reop.logical_not_), regex_ (reop.regex_) {}
  
  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    typename KindTraits<argument_kind>::Container v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
      bool match = boost::regex_match(std::string(kind.name()), regex_);
      //bool match = (regex_ == std::string(kind.name()));
      if (match ^ logical_not_) // Logical not of match, if required
        retval.Union(kind);
    }
    return retval;
  }
  RegexOp operator ! () 
  {
    RegexOp r(*this);
    r.logical_not_ = !this->logical_not_;
    return r;
  }
};

template <class L, class H>
struct CastOp : LEESAUnaryFunction <L, H>, OpBase
{
  typedef LEESAUnaryFunction <L, H> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<L, CastOp<argument_type, result_type> > expression_type;

  explicit CastOp () {}

  explicit CastOp (H) {} // dummy

  CastOp (CastOp const &) {}

#ifdef LEESA_FOR_UDM

  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    typename KindTraits<argument_kind>::Container v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
      if (Udm::IsDerivedFrom (kind.type(), result_kind::meta))
      {
        result_kind r = result_kind::Cast(kind);
        retval.Union(r);
      }
    }
    return retval;
  }

#else

  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    for(typename argument_type::const_iterator iter(arg.begin());
        iter != arg.end();
        ++iter)
    {
      if (const result_kind * r = dynamic_cast<const result_kind *> (&*iter))
      {
        retval.Union(*r);
      }
    }
    return retval;
  }
#endif  // LEESA_FOR_UDM
};

#ifdef LEESA_FOR_UDM

template <class E>
struct NonNullOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, NonNullOp<argument_type> > expression_type;

  bool logical_not_; 
  
  explicit NonNullOp (bool logical_not = false) 
    : logical_not_ (logical_not) {  }
  
  NonNullOp (NonNullOp const & nnop) 
    : logical_not_ (nnop.logical_not_) {}
  
  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    typename KindTraits<argument_kind>::Container c = arg;
    BOOST_FOREACH(argument_kind kind, c)
    {
      bool match = (Udm::null != kind);
      if (match ^ logical_not_) // Logical not of match, if required
        retval.Union(kind);
    }
    return retval;
  }
  NonNullOp operator ! () 
  {
    NonNullOp n(*this);
    n.logical_not_ = !this->logical_not_;
    return n;
  }
};

template <class L, class H>
struct GetParentOp : LEESAUnaryFunction <L, H>, OpBase
{
  typedef LEESAUnaryFunction <L, H> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<L, GetParentOp<argument_type, result_type> > expression_type;

  explicit GetParentOp () {}
  
  GetParentOp (GetParentOp const &) {}
  
  result_type operator () (argument_type const & arg)
  {
    BOOST_CONCEPT_ASSERT((LEESA::ChildToParentConcept <argument_kind, result_kind>));

    result_type retval;
    typename KindTraits<argument_kind>::Container v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
      result_kind parent = kind.template parent_kind<result_kind>();
      if (std::count (retval.begin(), retval.end(), parent) == 0)
        retval.Union(parent);
    }
    return retval;
  }
};

template <class LExpr, class RExpr>
struct DFSParentOp : std::unary_function<typename ET<LExpr>::result_type, void>,
                     OpBase
{
  typedef std::unary_function<typename ET<LExpr>::result_type, void> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<LExpr, DFSParentOp<LExpr, RExpr> > expression_type;

  RExpr expr_;
  
  explicit DFSParentOp () {}
  
  explicit DFSParentOp (RExpr const & e) : expr_(e) {}

  DFSParentOp (DFSParentOp const &d) : expr_(d.expr_) {}
  
  result_type operator () (argument_type const & arg)
  {
    typedef typename ET<RExpr>::argument_kind parent_kind;
    typedef typename ET<LExpr>::result_kind child_kind;

    BOOST_CONCEPT_ASSERT((LEESA::ChildToParentConcept<child_kind, parent_kind>));

    typename KindTraits<child_kind>::Container v = arg;
    BOOST_FOREACH(child_kind kind, v)
    {
      parent_kind parent = kind.template parent_kind<parent_kind>();
      expr_(parent);
    }
  }
};

template <class RESULT, class TARGETCLASS>
struct AssociationOp : LEESAUnaryFunction <TARGETCLASS, RESULT>,
                       OpBase
{
  typedef LEESAUnaryFunction <TARGETCLASS, RESULT> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<RESULT, AssociationOp<RESULT, TARGETCLASS> > 
      expression_type;

  typedef Udm::AClassPointerAttr<RESULT, TARGETCLASS> (TARGETCLASS::*FUNC)() const;
  FUNC func_;

  explicit AssociationOp (FUNC f) : func_(f) {}
  
  result_type operator () (argument_type const & arg)
  {
    typename KindTraits<argument_kind>::Container v = arg;
    result_type retval;
    BOOST_FOREACH(argument_kind kind, v)
    {
      result_kind r = (kind.*func_)();
      if (r != Udm::null) // This check is important. Don't remove.
        retval.Union(r);
    }
    return retval;
  }
};

template <class ASSOC, class SOURCECLASS, class TARGETCLASS>
struct AssociationManyOp : LEESAUnaryFunction <SOURCECLASS,ASSOC>, OpBase
{
  typedef LEESAUnaryFunction <SOURCECLASS, ASSOC> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<ASSOC, AssociationManyOp> expression_type;

  typedef Udm::AClassAssocAttr<ASSOC, TARGETCLASS> (SOURCECLASS::*FUNC)() const;
  FUNC func_;

  explicit AssociationManyOp (FUNC f) : func_(f) {}
  
  result_type operator () (argument_type const & arg)
  {
    typename KindTraits<argument_kind>::Container v = arg;
    result_type retval;
    BOOST_FOREACH(argument_kind kind, v)
    {
      retval.Union((kind.*func_)());
    }
    return retval;
  }
};

template <class RESULT, class TARGETCLASS>
struct AssociationEndOp : LEESAUnaryFunction <TARGETCLASS,RESULT>,
                          OpBase
{
  typedef LEESAUnaryFunction <TARGETCLASS, RESULT> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<RESULT, AssociationEndOp<RESULT, TARGETCLASS> >
      expression_type;

  typedef Udm::AssocEndAttr<RESULT> (TARGETCLASS::*FUNC)() const;
  FUNC func_;

  explicit AssociationEndOp (FUNC f) : func_(f) {}
  
  result_type operator () (argument_type const & arg)
  {
    typename KindTraits<argument_kind>::Container v = arg;
    result_type retval;
    BOOST_FOREACH(argument_kind kind, v)
    {
      result_kind r = (kind.*func_)();
      if (r != Udm::null) // This check is important. Don't remove.
        retval.Union(r);
    }
    return retval;
  }
};

#endif // LEESA_FOR_UDM

template <class E, class Func>
struct FilterOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESA::LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, FilterOp> expression_type;

  Func func_;
  bool logical_not_; 
  
  explicit FilterOp (Func f, bool logical_not = false) 
    : func_(f), logical_not_ (logical_not) { }

  FilterOp (FilterOp const & fop) 
    : func_(fop.func_), logical_not_ (fop.logical_not_) {}

  result_type operator () (argument_type const & arg)
  {
    result_type retval;
    typename KindTraits<argument_kind>::Container v = arg;
    BOOST_FOREACH(argument_kind kind, v)
    {
      if (func_(kind) ^ logical_not_) // Logical not of match, if required
        retval.Union(kind);
    }
    return retval;
  }
  FilterOp operator ! () 
  {
    FilterOp f(*this);
    f.logical_not_ = !this->logical_not_;
    return f;
  }
};

template <class E, class Func>
struct ForEachOp : LEESAUnaryFunction <E>, OpBase
{
  typedef LEESA::LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, ForEachOp> expression_type;

  Func func_;
  
  explicit ForEachOp (Func f) 
    : func_(f) { }
  
  ForEachOp (ForEachOp const & fop) 
    : func_(fop.func_) {}
  
  result_type operator () (argument_type const & arg)
  {
    typename KindTraits<argument_kind>::Container v = arg;
    std::for_each (v.begin(), v.end(), func_);
    return arg;
  }
};


template <class E, class Comp>
struct SortOp : LEESAUnaryFunction <E>,
                OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E, SortOp<E, Comp> > expression_type;

  Comp comp_;
  
  explicit SortOp (Comp c) : comp_(c) {}
  
  SortOp (SortOp const & sop) : comp_(sop.comp_) {}
  
  result_type operator () (argument_type const & k)
  {
    typename KindTraits<argument_kind>::Container s = k;
    std::sort(s.begin(), s.end(), comp_);
    return s;
  }
};

template <class E, class BinPred>
struct UniqueOp : LEESAUnaryFunction <E>,
                  OpBase
{
  typedef LEESAUnaryFunction <E> Super;
  SUPER_TYPEDEFS(Super);
  typedef ChainExpr<E ,UniqueOp<E, BinPred> > expression_type;

  BinPred pred_;
  
  explicit UniqueOp (BinPred p) : pred_(p) {}
  
  UniqueOp (UniqueOp const & uop) : pred_(uop.pred_) {}
  
  result_type operator () (argument_type const & k)
  {
    typename KindTraits<argument_kind>::Container s = k;
    typename KindTraits<result_kind>::Container retval;
    BOOST_FOREACH(argument_kind kind, s)
    {  
      if (std::count (retval.begin(), retval.end(), kind) == 0)
        retval.push_back(kind);
    }
    return retval;
  }
};

template <class T>
RegexOp<typename ET<T>::result_type> 
SelectByName (T, const char * str)
{
  typedef typename ET<T>::result_type result_type;
  typedef typename ET<T>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  RegexOp<result_type> regex(str);
  return regex;
}

template <class T>
SelectorOp<typename ET<T>::result_type> 
SelectSubSet (T const &t)
{
  typedef typename ET<T>::result_type result_type;
  typedef typename ET<T>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  return SelectorOp<result_type> (t);
}

template <class E, class Func>
FilterOp<E, Func> 
Select (E, Func f)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Func::argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Func::result_type, bool>));
  
  return FilterOp<E, Func> (f);
}

template <class E, class Arg, class Result>
FilterOp<E, std::pointer_to_unary_function<Arg, Result> > 
Select (E, Result (*f) (Arg))
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Arg, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Result, bool>));
  
  FilterOp<E, std::pointer_to_unary_function<Arg, Result> > 
    filter(std::ptr_fun(f));
  return filter;
}

template <class E, class Func>
ForEachOp<typename ET<E>::result_type, Func> 
ForEach (E, Func f)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<result_kind, typename Func::argument_type>));
  
  return ForEachOp<typename ET<E>::result_type, Func> (f);
}

template <class E, class Arg, class Result>
ForEachOp<typename ET<E>::result_type, 
          std::pointer_to_unary_function<Arg, Result> > 
ForEach (E, Result (*f) (Arg))
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Arg, result_kind>));
  
  ForEachOp<typename ET<E>::result_type, 
            std::pointer_to_unary_function<Arg, Result> > 
    foreach(std::ptr_fun(f));
  return foreach;
}

template <class L, class H>
CastOp<typename ET<L>::result_type, 
       typename ET<H>::result_type> 
CastFromTo (L, H)
{
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<L>));
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<H>));

  typedef typename ET<L>::argument_type argument_type;
  typedef typename ET<H>::result_type result_type;

  return CastOp<argument_type, result_type>();
}

#ifdef LEESA_FOR_UDM

template <class T>
NonNullOp<typename ET<T>::result_type> 
SelectNonNull (T)
{
  typedef typename ET<T>::result_type result_type;
  typedef typename ET<T>::result_kind result_kind;
  
  BOOST_MPL_ASSERT((LEESA::DomainKindConcept<result_kind>));
  NonNullOp<result_type> n;
  return n;
}

#endif // LEESA_FOR_UDM

template <class E, class Comp>
SortOp<E, Comp> 
Sort (E, Comp c)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Comp::first_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Comp::second_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename Comp::result_type, bool>));
  
  return SortOp<E, Comp> (c);
}

template <class E, class Arg1, class Arg2, class Result>
SortOp<E, std::pointer_to_binary_function<Arg1, Arg2, Result> > 
Sort (E, Result (*f) (Arg1, Arg2))
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Arg1, result_kind>));  
  BOOST_MPL_ASSERT((boost::is_convertible<Arg2, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<Result, bool>));
  
  SortOp<E, std::pointer_to_binary_function<Arg1, Arg2, Result> > 
    sorter(std::ptr_fun(f));
  return sorter;
}

template <class E, class BinPred>
UniqueOp<E, BinPred> 
Unique (E, BinPred c)
{
  typedef typename ET<E>::result_kind result_kind;
  
  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename BinPred::first_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename BinPred::second_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename BinPred::result_type, bool>));
  
  return UniqueOp<E, BinPred> (c);
}

template <class E>
UniqueOp<E, std::equal_to<typename ET<E>::result_kind> > 
Unique (E)
{
  typedef typename ET<E>::result_kind result_kind;
  typedef std::equal_to<result_kind> EQ;  

  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename EQ::first_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename EQ::second_argument_type, result_kind>));
  BOOST_MPL_ASSERT((boost::is_convertible<typename EQ::result_type, bool>));
  
  return UniqueOp<E, EQ>(EQ());
}
/*
template <class K, class C1, class C2>
ChoiceOp<typename ET<K>::result_type, C1, C2> 
Choice (K, C1 c1, C2 c2)
{
  typedef typename ET<K>::result_kind result_kind;
  typedef typename ET<C1>::argument_kind arg1_kind;
  typedef typename ET<C2>::argument_kind arg2_kind;

  BOOST_CONCEPT_ASSERT((LEESA::DomainKindConcept<result_kind>));
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<result_kind, arg1_kind>));
  BOOST_CONCEPT_ASSERT((LEESA::SameKindsConcept<result_kind, arg2_kind>));
  
  return ChoiceOp<typename ET<K>::result_type, C1, C2>(c1, c2);
}
*/

} // namespace LEESA 
