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

#include "PICML/PICML.h"
#include "PICML_GAME_Utils_export.h"

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
std::string scope (NamedType_in named_type,
                   const std::string & separator,
                   bool leading = false);

PICML_GAME_UTILS_Export
std::string scope (Exception_in ex,
                   const std::string & separator,
                   bool leading = false);

PICML_GAME_UTILS_Export
std::string scope (Package_in package,
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
std::string fq_type (NamedType_in named_type,
                     const std::string & separator,
                     bool leading = false);

PICML_GAME_UTILS_Export
std::string fq_type (Exception_in ex,
                     const std::string & separator,
                     bool leading = false);

PICML_GAME_UTILS_Export
std::string fq_type (Package_in ex,
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
std::string repository_id (NamedType_in named_type);

/**
 * Locate the template package instance that contains this element
 * type. It is assumed the type is an type that appears in a File and
 * was the result of instantiating a template package.
 */
PICML_GAME_UTILS_Export
TemplatePackageInstance get_template_package_inst (const GAME::Mga::FCO_in type);

}

#endif  // !defined _PICML_GAME_UTILITY_H_
