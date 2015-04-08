//  -*- C++ -*-

//=============================================================================
/**
 *  @file       ComponentRef_Decorator_Impl.h
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_COMPONENTREF_DECORATOR_IMPL_H_
#define _PICML_COMPONENTREF_DECORATOR_IMPL_H_

#include "game/mga/decorator/Reference_Decorator.h"
#include "ComponentRef_Decorator_export.h"

class Component_Decorator_Impl;

/**
 * @class ComponentRef_Decorator_Impl
 */
class COMPONENTREF_DECORATOR_Export ComponentRef_Decorator_Impl :
  public GAME::Mga::Reference_Decorator
{
public:
  /// Default constructor
  ComponentRef_Decorator_Impl (void);

  /// Destructor.
  virtual ~ComponentRef_Decorator_Impl (void);

  //int initialize (const GAME::Mga::Project & proj,
  //                const GAME::Mga::Meta::Part_in part,
  //                const GAME::Mga::FCO_in fco,
  //                IMgaCommonDecoratorEvents * eventSink,
  //                ULONGLONG parentWnd);

  ///// Draw the component reference.
  //int draw (Gdiplus::Graphics * g);

//private:
//  /// The overlay image for the reference.
//  std::auto_ptr <Gdiplus::Image> refarrow_;
//
//  std::auto_ptr <Gdiplus::Image> component_;
//
//  /// Pointer to the component decorator.
//  std::auto_ptr <Component_Decorator_Impl> delegate_;
};

#endif  // !defined _PICML_COMPONENTREF_DECORATOR_IMPL_H_
