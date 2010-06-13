//  -*- C++ -*-

//=============================================================================
/**
 *  @file       Component_Decorator_Impl.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _COMPONENT_DECORATOR_IMPL_H_
#define _COMPONENT_DECORATOR_IMPL_H_

#include "game/be/Decorator_Impl.h"
#include "game/MetaAspect.h"
#include "game/Part.h"
#include "game/graphics/Image_Manager_T.h"
#include "game/graphics/Image_Resolver.h"

#include "NoShowRefersTo_Decorator_export.h"

namespace Gdiplus
{
class Bitmap;
}

/**
 * @class NoShowRefersTo_Decorator_Impl
 */
class NoShowRefersTo_Decorator_Impl :
  public GAME::Decorator_Impl
{
public:
  /// Default constructor
  NoShowRefersTo_Decorator_Impl (void);

  /// Destructor.
  ~NoShowRefersTo_Decorator_Impl (void);

  int initialize_ex (const GAME::Project & proj, 
                     const GAME::Meta::Part & part, 
                     const GAME::FCO & fco,
                     IMgaCommonDecoratorEvents * eventSink, 
                     ULONGLONG parentWnd);

  /// Destory the decorator.
  void destroy (void);

  int get_preferred_size (long & sx, long & sy);

  /// Draw the component. This will draw the component's ports
  /// and the components label.
  int draw (Gdiplus::Graphics & g);

private:
  std::auto_ptr <Gdiplus::Bitmap> bitmap_;

  std::string label_;
};

#endif  // !defined _PORT_LAYOUT_DECORATOR_IMPL_H_
