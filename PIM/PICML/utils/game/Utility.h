// -*- C++ -*-

//=============================================================================
/**
 * @file      Utility.h
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_GAME_UTILITY_H_
#define _PICML_GAME_UTILITY_H_

#include "game/mga/Model.h"
#include "PICML_GAME_Utils_export.h"
#include "PICML/NamedTypes/NamedType.h"

namespace PICML
{
/**
 * Generate the full scope of a PICML named type.
 *
 * @param[in]     named_type      Named type to generate scope for
 * @param[in]     separator       Separator value of hierarchy
 * @param[in]     leading         Include leading separator value
 */
PICML_GAME_UTILS_Export
std::string scope (const GAME::Mga::FCO_in named_type,
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
std::string fq_type (const GAME::Mga::FCO_in named_type,
                     const std::string & separator,
                     bool leading = false);

/**
 * Locate the template package instance that contains this element
 * type. It is assumed the type is an type that appears in a File and
 * was the result of instantiating a template package.
 */
PICML_GAME_UTILS_Export
GAME::Mga::Model get_template_package_inst (const GAME::Mga::FCO_in type);

/**
 * Generate the repository id of a named type.
 */
PICML_GAME_UTILS_Export
std::string repository_id (const PICML::NamedType_in named_type);

}

#endif  // !defined _PICML_GAME_UTILITY_H_