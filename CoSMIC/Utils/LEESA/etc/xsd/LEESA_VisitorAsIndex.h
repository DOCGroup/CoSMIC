#ifndef __LEESA_VISITOR_AS_INDEX_H
#define __LEESA_VISITOR_AS_INDEX_H

//#ifndef PARADIGM_NAMESPACE_FOR_LEESA
//#error "Please define PARADIGM_NAMESPACE_FOR_LEESA, which contains the base Visitor class."
//#endif // PARADIGM_NAMESPACE_FOR_LEESA

namespace LEESA {

template <class Kind>
class VisitorAsIndex;

template <class Kind>
struct VisitorAsIndex_CRTP 
{
  LEESA::VisitorAsIndex<Kind> operator [] 
    (PARADIGM_NAMESPACE_FOR_LEESA::Visitor &v) const;
};

}

#endif // __LEESA_VISITOR_AS_INDEX_H
