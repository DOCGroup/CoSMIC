// -*- C++ -*-

//=============================================================================
/**
 * @file      IDL_Generator_File.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_IDL_GENERATOR_FILE_H_
#define _PICML_IDL_GENERATOR_FILE_H_

#include <iosfwd>
#include "PICML/PICML.h"
#include "IDLStream.h"

#include "IDL_Generator_export.h"

/**
 * @class IDL_Generator_File
 *
 * Wrapper class for generating the IDL file. This makes it easy for
 * third-party objects to generate valid IDL files.
 */
class IDL_GENERATOR_Export IDL_Generator_File
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       out         Target output stream.
   */
  IDL_Generator_File (std::ostream & out);

  /// Destructor.
  ~IDL_Generator_File (void);

  /// Generate the specified file to the attached stream.
  bool generate (const PICML::File_in file);

private:
  /// IDL stream for the file.
  IDLStream idl_;
};

#endif  // !defined _PICML_IDL_GENERATOR_FILE_H_
