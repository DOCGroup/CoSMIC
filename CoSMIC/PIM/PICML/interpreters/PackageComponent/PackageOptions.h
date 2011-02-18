// -*- C++ -*-

//=============================================================================
/**
 * @file      PackageOptions.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//==============================================================================

#ifndef _PACKAGE_OPTIONS_H_
#define _PACKAGE_OPTIONS_H_

#include <string>

/**
 * @class PackageOptions
 *
 * Contains options that clients can modify to affect how the
 * package component executes.
 */
class PackageOptions
{
public:
  /// Default constructor.
  PackageOptions (void);

  /// Flag that determines if package descriptors should be generated.
  /// If this flag is \a true, then descriptor_directory_ will contain
  /// a valid directory location.
  bool generate_descriptors_;

  /// Selected location of the descriptor directory.
  std::string descriptor_directory_;

  /// Flag that determines if packages should be generated. If this
  /// value is \a true, then implementation_directory_ and
  /// package_directory_ will contain valid directory locations.
  bool generate_packages_;

  /// Selected location of the implementation directory.
  std::string implementation_directory_;

  /// Selected location of the package directory.
  std::string package_directory_;
};

#endif  // !defined _PACKAGE_OPTIONS_H_
