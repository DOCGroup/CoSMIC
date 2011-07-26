// -*- C++ -*-

#ifndef _TEMPLATE_PARAMETER_MANAGER_H_
#define _TEMPLATE_PARAMETER_MANAGER_H_

#include "fe_utils.h"
#include "game/xme/FCO.h"
#include "ace/Containers_T.h"

#include <vector>
#include <utility>
#include <map>

/**
 * @class Template_Parameter_Manager
 */
class Template_Parameter_Manager
{
public:
  /// Type definition of a parameter.
  typedef
    std::pair < const FE_Utils::T_Param_Info *,
                GAME::XME::FCO > PARAMETER;

  /// Type definition of set of parameters.
  typedef std::vector < PARAMETER > PARAMETER_SET;

  /// Default constructor.
  Template_Parameter_Manager (void);

  /// Destructor.
  ~Template_Parameter_Manager (void);

  /// Start a new set of parameters. This will cache the current set
  /// of parameters, if applicable.
  int begin_parameter_set (void);

  /// Restore a parameter set associated with declaration.
  int begin_parameter_set (AST_Decl * decl);

  /// End the current set of parameters. This will restore any previous
  /// parameter set.
  int end_parameter_set (void);

  /// End the parameter set, but cache it for later usage.
  int end_parameter_set (AST_Decl * cache);

  /// Test if there is an active parameter set.
  bool has_parameters (void) const;

  /// Get the active parameter set.
  const PARAMETER_SET * active_parameter_set (void) const;

  /**
   * Insert a new parameter in the active listing. This will add the
   * parameter to the end of the current parameter list.
   */
  int push_back (const FE_Utils::T_Param_Info * info, GAME::XME::FCO fco);

  /**
   * Locate a parameter by its name.
   *
   * @param[in]       name          The parameter name
   * @param[out]      fco           The parameter object
   */
  bool find (const char * name, GAME::XME::FCO & fco) const;

  /**
   * Locate a parameter by its info.
   *
   * @param[in]       info          The parameter information
   * @param[out]      fco           The parameter object
   */
  bool find (const FE_Utils::T_Param_Info * info, GAME::XME::FCO & fco) const;

  bool find (const char * name, const FE_Utils::T_Param_Info * & info) const;

private:
  bool find_i (PARAMETER_SET *,
               const char * name,
               const FE_Utils::T_Param_Info * & info) const;

  bool find_i (PARAMETER_SET *,
               const char * name,
               GAME::XME::FCO & fco) const;

  int begin_parameter_set_i (void);

  /// The active parameter set.
  std::auto_ptr <PARAMETER_SET> active_;

  /// Collection of parameters.
  ACE_Unbounded_Stack < PARAMETER_SET * > entries_;

  /// Set of cached parameter sets.
  std::map <AST_Decl *, PARAMETER_SET * > cached_;
};

#endif  // !defined _TEMPLATE_PARAMETER_MANAGER_H_