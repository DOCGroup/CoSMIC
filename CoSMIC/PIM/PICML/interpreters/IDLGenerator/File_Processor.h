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

// Forward decl.
class IDLStream;

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
  IDL_File_Processor (IDLStream & idl_stream);

  /// Destructor.
  ~IDL_File_Processor (void);

  virtual void Visit_File (const PICML::File & file);
  virtual void Visit_Package (const PICML::Package & p);

  virtual void Visit_Aggregate (const PICML::Aggregate & a);
  virtual void Visit_SwitchedAggregate (const PICML::SwitchedAggregate & s);

  virtual void Visit_PortType (const PICML::PortType & p);
  virtual void Visit_Object (const PICML::Object & o);
  virtual void Visit_Component (const PICML::Component & c);

  virtual void Visit_Event (const PICML::Event & e);
  virtual void Visit_ValueObject (const PICML::ValueObject & v);

private:
  void generate_include_file (const PICML::File & file);

  void Visit_FilePackage (const Udm::Object & object);

  IDLStream & idl_;
};

#endif  // !defined _IDL_FILE_PROCESSOR_H_
