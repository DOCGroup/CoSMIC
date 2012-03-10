// -*- C++ -*-

//=============================================================================
/**
 * @file        FCO_Decorator.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_FCO_DECORATOR_H_
#define _GAME_MGA_FCO_DECORATOR_H_

#include "Decorator_Impl.h"

namespace GAME
{
namespace Mga
{
/**
 * @class FCO_Decorator
 *
 * Base class for all reference decorators. This class provides required
 * functionality that allows reference decorators to behave correctly.
 * Clients to can extend this class to add more domain-specific behavior
 * to the decorator.
 */
class GAME_MGA_DECORATOR_Export FCO_Decorator : public Decorator_Impl
{
public:
  /// Default constructor.
  FCO_Decorator (void);
  FCO_Decorator (bool use_default_bitmap);

  /// Destructor.
  virtual ~FCO_Decorator (void);

  virtual int initialize (const Project & proj,
                          const Meta::Part_in part,
                          IMgaCommonDecoratorEvents * eventSink,
                          ULONGLONG parentWnd);

  virtual int initialize (const Project & proj,
                          const Meta::Part_in part,
                          const FCO_in fco,
                          IMgaCommonDecoratorEvents * eventSink,
                          ULONGLONG parentWnd);

  /**
   * Draw the element.
   *
   * @param[in]         g         Target graphics object
   */
  virtual int draw (Gdiplus::Graphics * g);

  /**
   * Get the element's prefered size. This will be base on the
   * bitmap stored in this decorator.
   *
   * @param[out]        sx        Height of the element
   * @param[out]        sy        Width of the element
   */
  virtual int get_preferred_size (long & sx, long & sy);

protected:
  int init_image_resolver (const Project & proj);
  int init_default_bitmap (const Project & proj, Meta::FCO_in metafco);

  /// Draw the FCO's label
  void draw_label (Gdiplus::Graphics * g) const;

  /// Draw the bitmap's label.
  void draw_bitmap (Gdiplus::Graphics * g) const;

  /// Pointer to the element's bitmap.
  std::auto_ptr <Gdiplus::Image> bitmap_;

  /// The element's label.
  std::string label_;

private:
  /// Load the default bitmap for the decorator.
  bool use_default_bitmap_;
};

}
}

#if defined (__GAME_INLINE__)
#include "FCO_Decorator.inl"
#endif

#endif  // !defined _GAME_MGA_FCO_DECORATOR_H_
