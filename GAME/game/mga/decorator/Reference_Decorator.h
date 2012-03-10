// -*- C++ -*-

//=============================================================================
/**
 * @file        Reference_Decorator.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_REFERENCE_DECORATOR_H_
#define _GAME_MGA_REFERENCE_DECORATOR_H_

#include "FCO_Decorator.h"

namespace GAME
{
namespace Mga
{
/**
 * @class Reference_Decorator
 *
 * Base class for all reference decorators. This class provides required
 * functionality that allows reference decorators to behave correctly.
 * Clients to can extend this class to add more domain-specific behavior
 * to the decorator.
 */
class GAME_MGA_DECORATOR_Export Reference_Decorator :
  public FCO_Decorator
{
public:
  /// Default constructor.
  Reference_Decorator (void);

  /**
   * Initializing constructor
   *
   * @param[in]       use_default_bitmap        Use default bitmap
   * @param[in]       show_refers_to            Show the reference element
   */
  Reference_Decorator (bool use_defualt_bitmap, bool show_refers_to);

  /// Destructor.
  virtual ~Reference_Decorator (void);

  virtual int initialize (const Project & proj,
                          const Meta::Part_in part,
                          const FCO_in fco,
                          IMgaCommonDecoratorEvents * eventSink,
                          ULONGLONG parentWnd);

  /// Destroy the decorator.
  virtual void destroy (void);

  /// Update the decorator's active state.
  virtual void set_active (bool state);

  /// Update the decorator's selected state.
  virtual void set_selected (bool state);

  /// Set the location of the decorator's element.
  virtual void set_location (const GAME::Mga::Rect & location);

  /// Get the preferred size.
  virtual int get_preferred_size (long & sx, long & sy);

  /// Draw the element.
  virtual int draw (Gdiplus::Graphics * g);

  /// Get the object's ports.
  virtual int get_ports (std::vector <FCO> & v);

  /// Get the location of a port.
  virtual int get_port_location (const FCO_in fco,
                                 long & sx,
                                 long & sy,
                                 long & ex,
                                 long & ey);

protected:
  /// The delegate decorator for this referenced object.
  CComPtr <IMgaElementDecorator> delegate_;

private:
  bool show_refers_to_;
};


}
}

#if defined (__GAME_INLINE__)
#include "Reference_Decorator.inl"
#endif

#endif  // !defined _GAME_MGA_REFERENCE_DECORATOR_H_
