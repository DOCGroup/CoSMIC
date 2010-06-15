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

#include "game/be/Decorator_T.h"
#include "game/be/Decorator_Impl.h"

#include "game/MetaAspect.h"
#include "game/Part.h"
#include "game/graphics/Image_Manager_T.h"
#include "game/graphics/Image_Resolver.h"
#include "game/graphics/Port_Decorator.h"

#include "Component_Decorator_export.h"

/**
 * @class Component_Decorator_Impl
 */
class COMPONENT_DECORATOR_Export Component_Decorator_Impl :
  public GAME::Decorator_Impl
{
public:
  /// Default constructor
  Component_Decorator_Impl (void);

  /// Destructor.
  ~Component_Decorator_Impl (void);

  int initialize (const GAME::Project & proj, 
                  const GAME::Meta::Part & part, 
                  const GAME::FCO & fco);

  int initialize_ex (const GAME::Project & proj, 
                     const GAME::Meta::Part & part, 
                     const GAME::FCO & fco,
                     IMgaCommonDecoratorEvents * eventSink, 
                     ULONGLONG parentWnd);

  /// Destory the decorator.
  void destroy (void);

  void set_location (const GAME::utils::Rect & location);    

  int get_preferred_size (long & sx, long & sy);

  /// Draw the component. This will draw the component's ports
  /// and the components label.
  int draw (Gdiplus::Graphics & g);

  /// Draw the actual component.
  int draw_component (Gdiplus::Graphics & g);

  /// Draw the component's ports.
  int draw_ports (Gdiplus::Graphics & g);

  /// Draw the label for the component.
  int draw_label (Gdiplus::Graphics & g);

  /// Type definition of the port type.
  typedef std::vector <GAME::graphics::Port_Decorator *> port_set_t;

protected:
  int initialize_ports (const std::string & aspect,
                        const GAME::FCO &, 
                        GAME::graphics::Image_Resolver *);

  int initialize_graphics_path (void);

  /// The label for the element.
  std::string label_;

  /// Pointer to the loaded bitmap.
  Gdiplus::GraphicsPath graphics_path_;

  /// Collection of ports on the left side.
  port_set_t l_ports_;

  /// Collection of ports on the right side.
  port_set_t r_ports_;

  GAME::graphics::Image_Manager_T <GAME::FCO> port_bitmaps_;
};

#endif  // !defined _PORT_LAYOUT_DECORATOR_IMPL_H_
