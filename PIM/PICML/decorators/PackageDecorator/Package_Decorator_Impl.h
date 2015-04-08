//  -*- C++ -*-

//=============================================================================
/**
 *  @file       Component_Decorator_Impl.h
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _COMPONENT_DECORATOR_IMPL_H_
#define _COMPONENT_DECORATOR_IMPL_H_

#include "game/mga/decorator/FCO_Decorator.h"

/**
 * @class Package_Decorator_Impl
 */
class Package_Decorator_Impl : public GAME::Mga::FCO_Decorator
{
public:
  /// Default constructor
  Package_Decorator_Impl (void);

  /// Destructor.
  virtual ~Package_Decorator_Impl (void);

  int initialize (const GAME::Mga::Project & proj,
                  const GAME::Mga::Meta::Part_in part,
                  const GAME::Mga::FCO_in fco,
                  IMgaCommonDecoratorEvents * eventSink,
                  ULONGLONG parentWnd);

private:
  static const std::string TEMPLATEPACKAGE_BITMAP;
};

#endif  // !defined _PORT_LAYOUT_DECORATOR_IMPL_H_
