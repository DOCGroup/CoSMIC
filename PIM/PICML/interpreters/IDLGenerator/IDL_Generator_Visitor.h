// -*- C++ -*-

//=============================================================================
/**
 * @file      IDL_Generator_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _IDL_GENERATOR_VISITOR_H_
#define _IDL_GENERATOR_VISITOR_H_

#include "PICML/PICML.h"
#include "PICML/Visitor.h"

/**
 * @class IDL_Generator_Visitor
 */
class IDL_Generator_Visitor : public PICML::Visitor
{
public:
  IDL_Generator_Visitor (const std::string & outdir);

  virtual ~IDL_Generator_Visitor (void);

  virtual void visit_RootFolder (PICML::RootFolder_in folder);

  virtual void visit_InterfaceDefinitions (PICML::InterfaceDefinitions_in folder);

  virtual void visit_File (PICML::File_in file);

private:
  const std::string & outdir_;
};

#endif  // !defined _IDL_GENERATOR_VISITOR_H_
