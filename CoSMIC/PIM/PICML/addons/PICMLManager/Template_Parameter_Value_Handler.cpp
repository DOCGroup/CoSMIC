// $Id$

#include "StdAfx.h"
#include "Template_Parameter_Value_Handler.h"

namespace PICML
{
namespace MI
{

//
// NodeReference_Event_Handler
//
Template_Parameter_Value_Handler::Template_Parameter_Value_Handler (void)
: GAME::Readonly_Event_Handler (OBJEVENT_RELATION | OBJEVENT_DESTROYED, true)
{

}

//
// ~NodeReference_Event_Handler
//
Template_Parameter_Value_Handler::~Template_Parameter_Value_Handler (void)
{

}

}
}