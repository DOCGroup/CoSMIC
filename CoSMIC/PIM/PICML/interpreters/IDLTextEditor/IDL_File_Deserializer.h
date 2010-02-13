// -*- C++ -*-

//=============================================================================
/**
 *  @file         IDL_File_Deserializer.h
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _IDL_FILE_DESERIALIZER_H_
#define _IDL_FILE_DESERIALIZER_H_

#include "DSL_Deserializer.h"
#include "IDL_File_Parser.hpp"

/**
 * @class IDL_File_Deserializer
 */
class IDL_File_Deserializer : public DSL_Deserializer
{
public:
  /// Default constructor.
  IDL_File_Deserializer (void);

  /// Destructor.
  virtual ~IDL_File_Deserializer (void);

  virtual int deserialize (std::istream & stream, ::GME::Object & obj);

private:
  IDL_File_Parser parser_;
};

#endif  // !defined _IDL_FILE_DESERIALIZER_H_
