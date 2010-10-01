// -*- C++ -*-

//=============================================================================
/**
 * @file      Utility.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_GAME_UTILITY_H_
#define _PICML_GAME_UTILITY_H_

#include "game/Model.h"
#include "PICML_GAME_Utils_export.h"

namespace PICML
{
namespace GAME
{
/**
 * Generate the full scope of a PICML named type.
 *
 * @param[in]     named_type      Named type to generate scope for
 * @param[in]     separator       Separator value of hierarchy
 * @param[in]     leading         Include leading separator value
 */
PICML_GAME_UTILS_Export
std::string scope (const ::GAME::Model & named_type,
                   const std::string & separator,
                   bool leading = false);

/**
 * Generate the fully qualified type name of a PICML named type.
 *
 * @param[in]     named_type      Named type to generate scope for
 * @param[in]     separator       Separator value of hierarchy
 * @param[in]     leading         Include leading separator value
 */
PICML_GAME_UTILS_Export
std::string fq_type (const ::GAME::Model & named_type,
                     const std::string & separator,
                     bool leading = false);

/**
 * Locate the template package instance that contains this element
 * type. It is assumed the type is an type that appears in a File and
 * was the result of instantiating a template package.
 */
PICML_GAME_UTILS_Export
::GAME::Model get_template_package_inst (const ::GAME::FCO & type);

}
}

#endif  // !defined _PICML_GAME_UTILITY_H_
