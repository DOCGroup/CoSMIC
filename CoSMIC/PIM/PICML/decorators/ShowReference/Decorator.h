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

#include "DecoratorLib.h"
#include "game/mga/be/decorator/Decorator_T.h"
#include "game/mga/be/decorator/Decorator_Impl.h"

/**
 * @class Show_Reference_Decorator_Impl
 *
 * Implementation of the ShowReferenceDecorator.
 */
class Show_Reference_Decorator_Impl : public GAME::Mga::Decorator_Impl
{
public:
  /// Default constructor.
  Show_Reference_Decorator_Impl (void);

  /// Destructor
  ~Show_Reference_Decorator_Impl (void);

  int initialize_ex (const GAME::Mga::Project & proj,
                     const GAME::Mga::Meta::Part_in part,
                     const GAME::Mga::FCO_in fco,
                     IMgaCommonDecoratorEvents * eventSink,
                     ULONGLONG parentWnd);

  int get_preferred_size (long & sx, long & sy);

  int draw (Gdiplus::Graphics * g);

private:
  /// The bitmap image for the element.
  std::auto_ptr <Gdiplus::Bitmap> bitmap_;

  /// The label for the element.
  std::string label_;
};

DECLARE_DECORATOR (ShowReferenceDecorator, Show_Reference_Decorator_Impl);

#endif  //_PICML_SHOW_REFERENCE_DECORATOR_IMPL_H_
