//  -*- C++ -*-

//=============================================================================
/**
 *  @file       ComponentInstance_Decorator_Impl.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _COMPONENT_INSTANCE_DECORATOR_IMPL_H_
#define _COMPONENT_INSTANCE_DECORATOR_IMPL_H_

#include "game/be/Decorator_T.h"
#include "game/be/Decorator_Impl.h"

#include "game/MetaAspect.h"
#include "game/Part.h"
#include "game/graphics/Image_Manager_T.h"
#include "game/graphics/Image_Resolver.h"
#include "game/graphics/Port_Decorator.h"

#include "ComponentInstance_Decorator_export.h"

/**
 * @class ComponentInstance_Decorator_Impl
 */
class COMPONENTINSTANCE_DECORATOR_Export ComponentInstance_Decorator_Impl :
  public GAME::Decorator_Impl
{
public:
  /// Default constructor
  ComponentInstance_Decorator_Impl (void);

  /// Destructor.
  ~ComponentInstance_Decorator_Impl (void);

  int initialize (const GAME::Project & proj,
                  const GAME::Meta::Part_in part,
                  const GAME::FCO_in fco);

  int initialize_ex (const GAME::Project & proj,
                     const GAME::Meta::Part_in part,
                     const GAME::FCO_in fco,
                     IMgaCommonDecoratorEvents * eventSink,
                     ULONGLONG parentWnd);

  /// Destory the decorator.
  void destroy (void);

  void set_location (const GAME::utils::Rect & location);

  int get_preferred_size (long & sx, long & sy);

  /// Draw the component. This will draw the component's ports
  /// and the components label.
  int draw (Gdiplus::Graphics * g);

  int get_ports (std::vector < ::GAME::FCO > & v);

  int get_port_location (const GAME::FCO_in fco,
                         long & sx,
                         long & sy,
                         long & ex,
                         long & ey);

  /// Draw the actual component.
  int draw_component (Gdiplus::Graphics * g);

  /// Draw the component's ports.
  int draw_ports (Gdiplus::Graphics * g);

  /// Draw the label for the component.
  int draw_label (Gdiplus::Graphics * g);

  /// Type definition of the port type.
  typedef std::vector <GAME::graphics::Port_Decorator *> port_set_t;

protected:
  int initialize_ports (const std::string & aspect,
                        const GAME::FCO_in,
                        GAME::graphics::Image_Resolver *);

  int initialize_graphics_path (void);

  /// The label for the element.
  std::string label_;

  /// The implementation label.
  std::string impl_label_;

  /// Pointer to the loaded bitmap.
  Gdiplus::GraphicsPath graphics_path_;

  /// Collection of ports on the left side.
  port_set_t l_ports_;

  /// Collection of ports on the right side.
  port_set_t r_ports_;

  GAME::graphics::Image_Manager_T <GAME::FCO> port_bitmaps_;
};

#endif  // !defined _PORT_LAYOUT_DECORATOR_IMPL_H_
