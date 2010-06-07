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

/**
 * @class IDL_Generator_Visitor
 */
class IDL_Generator_Visitor : public PICML::Visitor
{
public:
  IDL_Generator_Visitor (const std::string & outdir);

  virtual ~IDL_Generator_Visitor (void);

  virtual void Visit_RootFolder (const PICML::RootFolder & folder);

  virtual void Visit_InterfaceDefinitions (const PICML::InterfaceDefinitions & folder);

  virtual void Visit_File (const PICML::File & file);

private:
  const std::string & outdir_;
};

#endif  // !defined _IDL_GENERATOR_VISITOR_H_
