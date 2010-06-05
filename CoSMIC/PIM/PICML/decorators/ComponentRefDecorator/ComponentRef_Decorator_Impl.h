//  -*- C++ -*-

//=============================================================================
/**
 *  @file       ComponentRef_Decorator_Impl.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _COMPONENTREF_DECORATOR_IMPL_H_
#define _COMPONENTREF_DECORATOR_IMPL_H_

#include "game/be/Decorator_T.h"
#include "game/be/Decorator_Impl.h"
#include "ComponentRef_Decorator_export.h"

class Component_Decorator_Impl;

/**
 * @class ComponentRef_Decorator_Impl
 */
class COMPONENTREF_DECORATOR_Export ComponentRef_Decorator_Impl :
  public GAME::Decorator_Impl
{
public:
  /// Default constructor
  ComponentRef_Decorator_Impl (void);

  /// Destructor.
  ~ComponentRef_Decorator_Impl (void);

  int initialize_ex (const GAME::Project & proj, 
                     const GAME::Meta::Part & part, 
                     const GAME::FCO & fco,
                     IMgaCommonDecoratorEvents * eventSink, 
                     ULONGLONG parentWnd);

  /// Destory the decorator.
  void destroy (void);

  void set_location (const GAME::utils::Rect & location);    

  int get_preferred_size (long & sx, long & sy);

  /// Draw the component reference.
  int draw (Gdiplus::Graphics & g);

private:
  /// The overlay image for the reference.
  std::auto_ptr <Gdiplus::Image> refarrow_;

  std::auto_ptr <Gdiplus::Image> component_;

  /// Pointer to the component decorator.
  std::auto_ptr <Component_Decorator_Impl> delegate_;
};

#endif  // !defined _PORT_LAYOUT_DECORATOR_IMPL_H_
