// -*- C++ -*-

//=============================================================================
/**
 *  @file       Decorator.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_SHOW_REFERENCE_DECORATOR_IMPL_H_
#define _PICML_SHOW_REFERENCE_DECORATOR_IMPL_H_

#include "game/mga/decorator/Reference_Decorator.h"

/**
 * @class Show_Reference_Decorator_Impl
 *
 * Implementation of the ShowReferenceDecorator.
 */
class Show_Reference_Decorator_Impl :
  public GAME::Mga::Reference_Decorator
{
public:
  /// Default constructor.
  Show_Reference_Decorator_Impl (void);

  /// Destructor
  virtual ~Show_Reference_Decorator_Impl (void);
};

#endif  //_PICML_SHOW_REFERENCE_DECORATOR_IMPL_H_
