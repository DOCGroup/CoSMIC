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

#include "game/mga/be/Decorator_T.h"
#include "game/mga/be/Decorator_Impl.h"

#include "game/mga/MetaAspect.h"
#include "game/mga/Part.h"
#include "game/mga/graphics/Image_Manager_T.h"
#include "game/mga/graphics/Image_Resolver.h"

#include "Package_Decorator_export.h"

namespace Gdiplus
{
class Bitmap;
}

/**
 * @class Package_Decorator_Impl
 */
class Package_Decorator_Impl :
  public GAME::Mga::Decorator_Impl
{
public:
  /// Default constructor
  Package_Decorator_Impl (void);

  /// Destructor.
  ~Package_Decorator_Impl (void);

  int initialize_ex (const GAME::Mga::Project & proj,
                     const GAME::Mga::Meta::Part_in part,
                     const GAME::Mga::FCO_in fco,
                     IMgaCommonDecoratorEvents * eventSink,
                     ULONGLONG parentWnd);

  /// Destory the decorator.
  void destroy (void);

  int get_preferred_size (long & sx, long & sy);

  /// Draw the component. This will draw the component's ports
  /// and the components label.
  int draw (Gdiplus::Graphics * g);

private:
  static const std::string TEMPLATEPACKAGE_BITMAP;
  static const std::string PACKAGE_BITMAP;

  std::auto_ptr <Gdiplus::Bitmap> bitmap_;

  std::string label_;
};

#endif  // !defined _PORT_LAYOUT_DECORATOR_IMPL_H_
