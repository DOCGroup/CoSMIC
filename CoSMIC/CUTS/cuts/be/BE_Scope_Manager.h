// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Scope_Manager.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_SCOPE_MANAGER_H_
#define _CUTS_BE_SCOPE_MANAGER_H_

#include "BE_export.h"
#include "PICML/PICML.h"
#include <map>

//=============================================================================
/**
 * @class CUTS_BE_Scope_Manager
 *
 * Object that generates and caches the scopes of PICML elements.
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_Scope_Manager
{
public:
  /// Constructor.
  CUTS_BE_Scope_Manager (void);

  /// Destructor.
  ~CUTS_BE_Scope_Manager (void);

  /**
   * Get the singleton instance.
   *
   * @return      Pointer to a scope manager.
   */
  static CUTS_BE_Scope_Manager * instance (void);

  /// Close the singleton instance.
  static void close_singleton (void);

  /**
   * Generate the scope for the object.
   *
   * @param[in]       type          The target type to generate scope.
   * @param[in]       separator     The separator string
   * @return          The scope for \a type.
   */
  std::string generate_scope (const PICML::NamedType & type,
                              const std::string & separator,
                              bool cache = true);

private:
  /**
   * Determine if the manager has a cache scope for \a using
   * \a seperator.
   *
   * @retval          true          Manager contains a scope for
   *                                \a type using \a separator.
   * @retval          false         Manager does not contain a scope.
   */
  bool find (const PICML::NamedType & type,
             const std::string & separator,
             std::string & scope);

  /// Type definition of scopes by separator.
  typedef std::map <std::string, std::string> Separator_Map;

  /// Type definition for cached scopes.
  typedef std::map <const PICML::NamedType, Separator_Map> Scope_Map;

  /// Collection of cached scopes.
  Scope_Map scopes_;

  /// Singleton instance.
  static CUTS_BE_Scope_Manager * instance_;
};

/// Macro to simplify accessing the CUTS_BE_Scope_Manager singleton.
#define CUTS_BE_SCOPE_MANAGER() \
  CUTS_BE_Scope_Manager::instance ()

#if defined (__CUTS_INLINE__)
#include "BE_Scope_Manager.inl"
#endif

#endif  // !defined _CUTS_BE_SCOPE_MANAGER_H_
