//  -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Variable_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_VARIABLE_VISITOR_H_
#define _CUTS_BE_VARIABLE_VISITOR_H_

#include "PICML/PICML.h"
#include "BE_File_Generator_Set.h"

//=============================================================================
/**
 * @class CUTS_BE_Variable_Visitor
 *
 * Visitor for generating variables for a component.
 */
//=============================================================================

class CUTS_BE_Variable_Visitor : public PICML::Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     generators        Target generators.
   */
  CUTS_BE_Variable_Visitor (const CUTS_BE_File_Generator_Set & generators);

  /// Destructor.
  virtual ~CUTS_BE_Variable_Visitor (void);

protected:
  /// Visit a Component element.
  void Visit_Component (const PICML::Component &);

  /// Visit a Variable element.
  void Visit_Variable (const PICML::Variable &);

  /// Visit a WorkerType element.
  void Visit_WorkerType (const PICML::WorkerType &);

  /// Visit an Attribute element.
  void Visit_Attribute (const PICML::Attribute &);

  /// Visit an Attribute element.
  void Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute &);

private:
  /// Collection of file generators.
  CUTS_BE_File_Generator_Set generators_;

  // prevent the following operations
  CUTS_BE_Variable_Visitor (const CUTS_BE_Variable_Visitor &);
  const CUTS_BE_Variable_Visitor & operator = (const CUTS_BE_Variable_Visitor &);
};

#endif  // !defined _CUTS_BE_VARIABLE_VISITOR_H_
