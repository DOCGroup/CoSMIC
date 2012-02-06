//  -*- C++ -*-

//=============================================================================
/**
 *  @file       $File$
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_NOSHOWREFERSTO_DECORATOR_IMPL_H_
#define _PICML_NOSHOWREFERSTO_DECORATOR_IMPL_H_

#include "game/mga/decorator/Reference_Decorator.h"

/**
 * @class NoShowRefersTo_Decorator_Impl
 */
class NoShowRefersTo_Decorator_Impl :
  public GAME::Mga::Reference_Decorator
{
public:
  /// Default constructor
  NoShowRefersTo_Decorator_Impl (void);

  /// Destructor.
  virtual ~NoShowRefersTo_Decorator_Impl (void);
};

#endif  // !defined _PICML_NOSHOWREFERSTO_DECORATOR_IMPL_H_
