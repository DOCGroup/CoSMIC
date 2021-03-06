// -*- C++ -*-

//=============================================================================
/**
 * @file        Validation.h
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_VALIDATION_H_
#define _PICML_MI_VALIDATION_H_

#include "game/mga/GME_fwd.h"

namespace PICML
{
namespace MI
{

/**
 * Test if an element is inside a template module.
 *
 * @param[in]     fco         Element to test.
 * @retval        true        Element is inside a template module
 * @retval        false       Element is not inside a template module
 */
bool is_in_template_module (const GAME::Mga::FCO_in fco);

/**
 * Test if an element is inside a template module instance.
 *
 * @param[in]     fco         Element to test.
 * @retval        true        Element is inside a template module
 * @retval        false       Element is not inside a template module
 */
bool is_in_template_module_instance (const GAME::Mga::FCO_in fco);

}
}

#endif  // !defined _PICML_MI_VALIDATION_H_
