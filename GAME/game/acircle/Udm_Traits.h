//=============================================================================
/**
 *  @file       Udm_Traits.h
 *
 *  File contains the class ACircle_Traits.
 *
 *  $Id:$
 *
 *  @author     Harold Owens II <owensh@cs.iupui.edu>
 */
//=============================================================================

#ifndef _UDM_TRAITS_
#define _UDM_TRAITS_

#include "PICML/PICML.h"
#include "Utils/UDM/visit.h"

#include "ACircle_Tag_Dispatch.h"

/**
 * @class ACircle_Traits
 *
 * Specific A-Circle Trait class that is used to provided information about
 * the Udm domain specific backend
 *
 * @warning To use A-Circle each typedef within this class must be defined
 *          for the specific backend. The trait below is for Udm backend.
 */
template<> 
struct ACircle_Traits <Udm::Object>
{
  typedef Udm::Object base_type;
  typedef Uml::Class base_meta;
  typedef PICML::File root_type;
  typedef PICML::Visitor visitor_type;
  typedef ACircle_Tag_Dispatch::udm_tag model_method;
};

#endif // _UDM_TRAITS_