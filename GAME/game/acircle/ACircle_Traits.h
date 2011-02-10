//=============================================================================
/**
 *  @file       ACircle_Traits.h
 *
 *  File contains the class ACircle_Traits.
 *
 *  $Id:$
 *
 *  @author     Harold Owens II <owensh@cs.iupui.edu>
 */
//=============================================================================

#ifndef _ACIRCLE_TRAITS_
#define _ACIRCLE_TRAITS_

#include "ACircle_Tag_Dispatch.h"

/**
 * @class ACircle_Traits
 *
 * Generic A-Circle Trait class that is used to provided information about
 * the domain specific methods (backends)
 */
template <typename T>
struct ACircle_Traits
{ 
  typedef typename T::base_type base_type;
  typedef typename T::base_meta base_meta;
  typedef typename T::root_type root_type;
  typedef typename T::visitor_type visitor_type;
  typedef typename T::model_method model_method;
};

#endif // _ACIRCLE_TRAITS_