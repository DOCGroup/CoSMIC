// $Id$

#include "StdAfx.h"
#include "IDL_File_Serializer.h"
#include "IDLEmitVisitor.h"
#include "DependencyVisitor.h"
#include "game/Object.h"

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
serialize (const ::GAME::Object & obj, std::ostream & stream)
{
  // Make this an BON object type.
  BON::Object bon_obj (::BON::Object::attach (obj.impl ()));

  // Now, we can use IDML::File BON extension object.
  IDML::File file (bon_obj);

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
