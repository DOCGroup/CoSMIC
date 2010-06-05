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

protected:
  int initialize_ports (const GAME::FCO &,  GAME::graphics::Image_Resolver *);

  /// Inline struction for sorting the ports.
  struct sort_t
  {
    sort_t (const GAME::Meta::Aspect & aspect)
      : aspect_ (aspect)
    {

    }

    bool operator () (const GAME::FCO & p1, const GAME::FCO & p2) const
    {
      long x1, y1, x2, y2;

      p1.part (this->aspect_).get_location (x1, y1);
      p2.part (this->aspect_).get_location (x2, y2);

      return y1 < y2;
    }

  private:
    const GAME::Meta::Aspect & aspect_;
  };

  /// Type definition of the port type.
  typedef std::map <GAME::FCO, 
                    GAME::utils::Point,
                    sort_t> 
                    port_map;

  /// The label for the element.
  std::string label_;

  /// Pointer to the loaded bitmap.
  std::auto_ptr <Gdiplus::Bitmap> bitmap_;

  GAME::Meta::Aspect aspect_;

  sort_t sorter_;

  port_map l_ports_;

  port_map r_ports_;

  GAME::graphics::Image_Manager_T <GAME::FCO> port_bitmaps_;
};

#endif  // !defined _PORT_LAYOUT_DECORATOR_IMPL_H_
