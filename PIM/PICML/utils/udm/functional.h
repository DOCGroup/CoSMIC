// -*- C++ -*-

//=============================================================================
/**
 * @file      functional.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_UDM_UTILITY_H_
#define _PICML_UDM_UTILITY_H_

#include "PICML/PICML.h"
#include "PICML_UDM_Utils_export.h"

namespace PICML
{
namespace utils
{
/**
 * Generate the full scope of a PICML named type.
 *
 * @param[in]     named_type      Named type to generate scope for
 * @param[in]     separator       Separator value of hierarchy
 * @param[in]     leading         Include leading separator value
 */
PICML_UDM_UTILS_Export
std::string scope (const PICML::NamedType & named_type,
                   const std::string & separator,
                   bool leading = false);

PICML_UDM_UTILS_Export
std::string scope (const PICML::Exception & ex,
                   const std::string & separator,
                   bool leading = false);

PICML_UDM_UTILS_Export
std::string scope (const PICML::Package & ex,
                   const std::string & separator,
                   bool leading = false);

/**
 * Generate the fully qualified type name of a PICML named type.
 *
 * @param[in]     named_type      Named type to generate scope for
 * @param[in]     separator       Separator value of hierarchy
 * @param[in]     leading         Include leading separator value
 */
PICML_UDM_UTILS_Export
std::string fq_type (const PICML::NamedType & named_type,
                     const std::string & separator,
                     bool leading = false);

PICML_UDM_UTILS_Export
std::string fq_type (const PICML::Exception & ex,
                     const std::string & separator,
                     bool leading = false);

PICML_UDM_UTILS_Export
std::string fq_type (const PICML::Package & ex,
                     const std::string & separator,
                     bool leading = false);

/**
 * Generate the fully qualified type name of a PICML named type.
 *
 * @param[in]     named_type      Named type to generate scope for
 * @param[in]     separator       Separator value of hierarchy
 * @param[in]     leading         Include leading separator value
 */
PICML_UDM_UTILS_Export
std::string repository_id (const PICML::NamedType & named_type);
}
}

#endif  // !defined _PICML_UDM_UTILITY_H_
