// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Method_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_METHOD_VISITOR_H_
#define _CUTS_BE_METHOD_VISITOR_H_

#include "BE_File_Generator_Set.h"
#include "PICML/PICML.h"

//=============================================================================
/**
 * @class CUTS_BE_Method_Visitor
 *
 * Visitor responsible for writing methods of PICML elements. This
 * visitor delegates responsibility to the appropriate write method
 * for each element in the target generators.
 */
//=============================================================================

class CUTS_BE_Method_Visitor : public PICML::Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     generators      Set of file generators.
   */
  CUTS_BE_Method_Visitor (const CUTS_BE_File_Generator_Set & generators);

  /// Destructor.
  virtual ~CUTS_BE_Method_Visitor (void);

protected:
  /// Generate all the methods for a component. This should be
  /// treated as the entry point for the visitor.
  void Visit_Component (const PICML::Component &);

  /// Generate the method for a ProvidedRequestPort element.
  void Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort &);

  /// Generate the method for an InEventPort element.
  void Visit_InEventPort (const PICML::InEventPort & );

  /// Generate the method for an PeriodicEvent element.
  void Visit_PeriodicEvent (const PICML::PeriodicEvent &);

  /// Generate the method for a ReadonlyAttribute element.
  void Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute &);

  /// Generate the method for a Attribute element.
  void Visit_Attribute (const PICML::Attribute &);

  /// Generate the method(s) for an Environment element.
  void Visit_Environment (const PICML::Environment &);

private:
  /// Target backend file generators.
  const CUTS_BE_File_Generator_Set & generators_;
};

#endif  // !defined _CUTS_BE_METHOD_VISITOR_H_
