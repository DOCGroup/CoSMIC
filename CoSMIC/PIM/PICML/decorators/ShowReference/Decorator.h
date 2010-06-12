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

#ifndef __DECORATOR_H_
#define __DECORATOR_H_

#include "DecoratorLib.h"
#include "game/be/Decorator_T.h"
#include "game/be/Decorator_Impl.h"
#include "MaskedBitmap.h"

/**
 * @class Show_Reference_Decorator_Impl
 *
 * Implementation of the ShowReferenceDecorator.
 */
class Show_Reference_Decorator_Impl : public GAME::Decorator_Impl
{
public:
  /// Default constructor.
  Show_Reference_Decorator_Impl (void);

  /// Destructor
  ~Show_Reference_Decorator_Impl (void);

  int initialize (const GAME::Project & proj, 
                  const GAME::Meta::Part & part, 
                  const GAME::FCO & fco);

  int initialize_ex (const GAME::Project & proj, 
                     const GAME::Meta::Part & part, 
                     const GAME::FCO & fco,
                     IMgaCommonDecoratorEvents * eventSink, 
                     ULONGLONG parentWnd);

  int get_preferred_size (long & sx, long & sy);

  int draw (CDC & context);
  int draw (Gdiplus::Graphics & g);

private:
  /// The bitmap image for the element.
  CMaskedBitmap bitmap_;

  /// The label for the element.
  CString label_;
};

DECLARE_DECORATOR (ShowReferenceDecorator, Show_Reference_Decorator_Impl);

#endif //__DECORATOR_H_
