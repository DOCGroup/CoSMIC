// $Id$

#include "StdAfx.h"
#include "IDL_File_Serializer.h"
#include "IDLEmitVisitor.h"
#include "DependencyVisitor.h"

//
// IDL_File_Serializer
//
IDL_File_Serializer::IDL_File_Serializer (void)
{

}

//
// ~IDL_File_Serializer
//
IDL_File_Serializer::~IDL_File_Serializer (void)
{

}

//
// serialize
//
int IDL_File_Serializer::
serialize (const BON::Object & obj, std::ostream & stream)
{
  // Convert the object to a File object.
  IDML::File file (obj);

  if (!file)
    return -1;

  // Make sure the dependencies exist for the file.
  IDML::DependencyVisitor depend_visitor;
  depend_visitor.visitOrderableImpl (file);

  // Generate the text version of the IDL file.
  IDML::IDLEmitVisitor emit_visitor (stream);
  emit_visitor.visitOrderableImpl (file);

  return 0;
}
