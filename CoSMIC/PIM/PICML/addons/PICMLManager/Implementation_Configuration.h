// -*- C++ -*-

//=============================================================================
/**
 * @file      Implementation_Configuration.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MI_IMPLEMENTATION_CONFIGURATION_H_
#define _PICML_MI_IMPLEMENTATION_CONFIGURATION_H_

#include <string>

namespace PICML
{
namespace MI
{

/**
 * @class Implementation_Configuration
 *
 * Configuration values of a new component.
 */
class Implementation_Configuration
{
public:
  /// Default constructor.
  Implementation_Configuration (void);

  /// Name of the component.
  std::string type_name_;

  /// Suffix for the servant artifact.
  std::string svnt_artifact_suffix_;

  /// Suffix for the executor artifact.
  std::string exec_artifact_suffix_;

  /// Generate the servant location based on the component's filename.
  bool svnt_artifact_location_based_on_filename_;
};

}
}

#endif  // !defined _PICML_MI_IMPLEMENTATION_CONFIGURATION_H_
