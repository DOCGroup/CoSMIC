// -*- C++ -*-

//=============================================================================
/**
 * @file      NewComponentDialog.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _NEW_COMPONENT_CONFIG_H_
#define _NEW_COMPONENT_CONFIG_H_

#include "ace/SString.h"

/**
 * @class NewComponentConfig
 *
 * Configuration values of a new component.
 */
class NewComponentConfig
{
public:
  /// Default constructor.
  NewComponentConfig (void)
    : svnt_artifact_suffix_ ("_svnt"),
      exec_artifact_suffix_ ("_exec")
  {

  }

  /// Name of the component.
  ACE_CString component_name_;

  /// Suffix for the servant artifact.
  ACE_CString svnt_artifact_suffix_;

  /// Suffix for the executor artifact.
  ACE_CString exec_artifact_suffix_;
};

#endif  // !defined _NEW_COMPONENT_CONFIG_H_
