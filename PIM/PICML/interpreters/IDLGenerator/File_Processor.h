// -*- C++ -*-

//=============================================================================
/**
 * @file      File_Processor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _IDL_FILE_PROCESSOR_H_
#define _IDL_FILE_PROCESSOR_H_

#include "PICML/PICML.h"
#include "PICML/Visitor.h"

// Forward decl.
class IDLStream;

// Forward decl.
class IDL_File_Dependency_Processor;

/**
 * @class IDL_File_Processor
 *
 * Implementation of the PICML::Visitor that is responsible for
 * preprocessing File elements before generating an IDL file.
 */
class IDL_File_Processor : public PICML::Visitor
{
public:
  /// Default constructor.
  IDL_File_Processor (IDL_File_Dependency_Processor & depends_graph,
                      IDLStream & idl_stream);

  /// Destructor.
  ~IDL_File_Processor (void);

  virtual void Visit_File (const PICML::File_in file);
  virtual void Visit_Package (const PICML::Package_in p);

  virtual void Visit_Aggregate (const PICML::Aggregate_in a);
  virtual void Visit_SwitchedAggregate (const PICML::SwitchedAggregate_in s);

  virtual void Visit_PortType (const PICML::PortType_in p);
  virtual void Visit_Object (const PICML::Object_in o);
  virtual void Visit_Component (const PICML::Component_in c);

  virtual void Visit_Event (const PICML::Event_in e);
  virtual void Visit_ValueObject (const PICML::ValueObject_in v);

private:
  void generate_include_file (const PICML::File_in file);
  bool file_has_object_with_reference (const PICML::File_in file);

  IDL_File_Dependency_Processor & depends_graph_;

  IDLStream & idl_;
};

#endif  // !defined _IDL_FILE_PROCESSOR_H_
