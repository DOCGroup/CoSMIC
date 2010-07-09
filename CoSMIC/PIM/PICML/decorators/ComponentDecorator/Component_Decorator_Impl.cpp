// $Id$

#include "StdAfx.h"
#include "Component_Decorator.h"
#include "Component_Decorator_Impl.h"

#include "game/MetaFCO.h"
#include "game/MetaModel.h"
#include "game/Model.h"
#include "game/Reference.h"
#include "game/graphics/Image_Resolver.h"
#include "game/utils/Registrar.h"

#include "boost/bind.hpp"

#define GME_PORT_HEIGHT         11
#define GME_PORT_WIDTH          11

#define GME_PORT_PADDING_Y      4

#define GME_PORT_MARGIN_X       4
#define GME_PORT_MARGIN_Y       4

#define COMPONENT_DEFUALT_WIDTH     143
#define COMPONENT_DEFAULT_HEIGHT    70
#define COMPONENT_LINE_WIDTH        3

DECLARE_DECORATOR (Component_Decorator, Component_Decorator_Impl);

/**
 * @struct sort_top_to_bottom_t
 */
struct sort_top_to_bottom_t
{
  typedef Component_Decorator_Impl::port_set_t port_set_t;

  bool operator () (const port_set_t::value_type & p1, 
                    const port_set_t::value_type & p2) const
  {
    return p1->location ().y_value () < p2->location ().y_value ();
  }
};

/**
 * @struct set_port_location_t
 *
 * Functor to help set the port location.
 */
struct set_port_location_t
{
  typedef Component_Decorator_Impl::port_set_t::value_type value_type;

  set_port_location_t (GAME::utils::Point & next)
    : next_ (next) { }

  void operator () (value_type & port) 
  {
    port->location (this->next_);
    this->next_.shift (0, GME_PORT_HEIGHT + GME_PORT_PADDING_Y);
  }

private:
  /// The next port location.
  GAME::utils::Point & next_;
};

///////////////////////////////////////////////////////////////////////////////
//

//
// Component_Decorator_Impl
//
Component_Decorator_Impl::Component_Decorator_Impl (void)
{

}

//
// ~Component_Decorator_Impl
//
Component_Decorator_Impl::~Component_Decorator_Impl (void)
{

}

template <typename T>
struct delete_t
{
  void operator () (T * ptr) const
  {
    delete ptr;
  }
};

//
// destroy
//
void Component_Decorator_Impl::destroy (void)
{ 
  this->port_bitmaps_.clear ();

  std::for_each (this->l_ports_.begin (),
                 this->l_ports_.end (),
                 delete_t <GAME::graphics::Port_Decorator> ());

  std::for_each (this->r_ports_.begin (),
                 this->r_ports_.end (),
                 delete_t <GAME::graphics::Port_Decorator> ());
}

//
// initialize
//
int Component_Decorator_Impl::
initialize_ex (const GAME::Project & proj, 
               const GAME::Meta::Part & part, 
               const GAME::FCO & fco,
               IMgaCommonDecoratorEvents * eventSink, 
               ULONGLONG parentWnd)
{
	return this->initialize (proj, part, fco);
}

//
// initialize
//
int Component_Decorator_Impl::
initialize (const GAME::Project & project, 
            const GAME::Meta::Part & part,
            const GAME::FCO & fco)
{
  using GAME::utils::GLOBAL_REGISTRAR;
  using GAME::utils::Registrar;

  using GAME::graphics::GLOBAL_IMAGE_RESOLVER;
  using GAME::graphics::Image_Manager_T;
  using GAME::graphics::Image_Resolver;

  // Initialize the icon manager.
  Image_Resolver * resolver = GLOBAL_IMAGE_RESOLVER::instance ();
  
  if (!resolver->is_init ())
    resolver->init (project, *GLOBAL_REGISTRAR::instance (), Registrar::ACCESS_BOTH);

  if (fco.is_nil ())
  {
    // We are going to show the metaname.
    GAME::Meta::FCO metafco = part.role ().kind ();
    this->label_ = metafco.display_name ().c_str ();
  }
  else
  {
    // Determine if we need to show the label for the element.
    std::string show_name = fco.registry_value ("isNameEnabled");

    if (show_name.empty () || show_name == "true")
      this->label_ = fco.name ();
  }

  if (!fco.is_nil ())
    this->initialize_ports ("InterfaceDefinition", fco, resolver);

  // Finally, sort the ports from top to bottom.
  std::sort (this->l_ports_.begin (),
             this->l_ports_.end (),
             sort_top_to_bottom_t ());

  std::sort (this->r_ports_.begin (),
             this->r_ports_.end (),
             sort_top_to_bottom_t ());

  return S_OK;
}

//
// initialize_ports
//
int Component_Decorator_Impl::
initialize_ports (const std::string & aspect_name, 
                  const GAME::FCO & fco,
                  GAME::graphics::Image_Resolver * resolver)
{
  GAME::Model model = GAME::Model::_narrow (fco);
  GAME::Meta::Model metamodel = model.meta ();

  // Get the target aspect.
  GAME::Meta::Aspect aspect = metamodel.aspect (aspect_name);

  if (aspect.is_nil ())
    return 0;

  // Select all the FCO elements in the specified aspect.
  std::vector <GAME::FCO> ports;
  if (model.children (aspect, ports) == 0)
    return 0;

  std::vector <GAME::FCO>::const_iterator 
    iter = ports.begin (), iter_end = ports.end ();

  GAME::Part part;
  std::string icon_filename, filename;
  Gdiplus::Bitmap * image = 0;

  for (; iter != iter_end; ++ iter)
  {
    // First, let's determine if the element is indeed a port. If
    // it is not a port, let's just continue to the next iteration.
    part = iter->part (aspect);

    if (!part.meta ().is_linked ())
      continue;

    // Load the icon for the specified element.
    icon_filename = iter->meta ().registry_value ("icon");

    if (resolver->lookup_icon (icon_filename, filename))
      this->port_bitmaps_.associate_image (*iter, filename, image);

    // Determine what side of the model this port should
    // be displayed.
    long x, y;
    part.get_location (x, y);

    using GAME::graphics::Port_Decorator;

    GAME::utils::Point location (x, y);
    Port_Decorator * port = new Port_Decorator (*iter, image, iter->name (), location);

    if (x < 200)
    {
      this->l_ports_.push_back (port);
      port->alignment (Port_Decorator::ALIGNMENT_LEFT);
    }
    else
    {
      this->r_ports_.push_back (port);
      port->alignment (Port_Decorator::ALINGMENT_RIGHT);
    }
  }

  // We need to get all the ports that we inherit.
  std::vector <GAME::Reference> inherits;

  if (model.children ("ComponentInherits", inherits))
  {
    GAME::Reference inherit = inherits[0];
    GAME::FCO refers_to = inherit.refers_to ();

    if (!refers_to.is_nil ())
      this->initialize_ports ("InterfaceDefinition", refers_to, resolver);
  }

  return 0;
}

//
// location
//
void Component_Decorator_Impl::
set_location (const GAME::utils::Rect & loc)
{
  // Now that we know our dimensions, let's draw the bitmap
  // for this component to size.
  GAME::utils::Point pt (loc.x_, loc.y_);

  // Set the port locations for the left side of model. 
  pt.shift (GME_PORT_MARGIN_X, GME_PORT_MARGIN_Y);

  std::for_each (this->l_ports_.begin (),
                 this->l_ports_.end (),
                 set_port_location_t (pt));

  // Set the port locations for the right side of model. 
  pt.set (loc.cx_ - (GME_PORT_WIDTH + GME_PORT_MARGIN_X), loc.y_ + GME_PORT_MARGIN_Y);

  std::for_each (this->r_ports_.begin (),
                 this->r_ports_.end (),
                 set_port_location_t (pt));

  // Pass control to the base class and set the graphics path.
  GAME::Decorator_Impl::set_location (loc);

  // Initialize the graphics path for the component.
  this->initialize_graphics_path ();
}

//
// initialize_graphics_path
//
int Component_Decorator_Impl::initialize_graphics_path (void)
{
  static const int cs = 15;
  int xr = this->location_.x_ + (this->location_.width () - cs);
  int yr = this->location_.y_ + (this->location_.height () - cs);

  Gdiplus::Rect tl (this->location_.x_, this->location_.y_, cs, cs);
  Gdiplus::Rect tr (xr, this->location_.y_ , cs, cs);
  Gdiplus::Rect bl (this->location_.x_, yr, cs, cs);
  Gdiplus::Rect br (xr, yr, cs, cs);

  // Reset the graphics path.
  this->graphics_path_.Reset ();

  // Start drawing the component image.
  this->graphics_path_.StartFigure ();
  this->graphics_path_.AddArc (tl, 180.0, 90.0);
  this->graphics_path_.AddArc (tr, 270.0, 90.0);
  this->graphics_path_.AddArc (br, 360.0, 90.0);
  this->graphics_path_.AddArc (bl, 90.0, 90.0);
  this->graphics_path_.CloseFigure ();

  return 0;
}

//
// get_preferred_size
//
int Component_Decorator_Impl::
get_preferred_size (long & sx, long & sy)
{
  // The width of the component is the same.
  sx = COMPONENT_DEFUALT_WIDTH;

  // Determine the height of the component's bitmap.
  long curr_height = COMPONENT_DEFAULT_HEIGHT;
  long l_height = (this->l_ports_.size () * (GME_PORT_HEIGHT + GME_PORT_PADDING_Y)) + (2 * GME_PORT_MARGIN_Y);
  long r_height = (this->r_ports_.size () * (GME_PORT_HEIGHT + GME_PORT_PADDING_Y)) + (2 * GME_PORT_MARGIN_Y);
  long p_height = l_height > r_height ? l_height : r_height;
  sy = p_height > curr_height ? p_height : curr_height;

  return 0;
}

//
// draw
//
int Component_Decorator_Impl::draw (Gdiplus::Graphics & g)
{
  return (this->draw_component (g) |
          this->draw_label (g) |
          this->draw_ports (g));
}

//
// draw_component
//
int Component_Decorator_Impl::draw_component (Gdiplus::Graphics & g)
{
  // Start drawing the component image.
  static const Gdiplus::SolidBrush brush (Gdiplus::Color (210, 210, 210));
  g.FillPath (&brush, &this->graphics_path_);

  static const Gdiplus::Pen pen (Gdiplus::Color (100, 100, 100), COMPONENT_LINE_WIDTH);
  g.DrawPath (&pen, &this->graphics_path_);

  return 0;
}

//
// draw_label
//
int Component_Decorator_Impl::draw_label (Gdiplus::Graphics & g)
{
  float height = (float)this->location_.height ();
  float px = static_cast <float> (this->location_.x_) + (this->location_.width () / 2.0f);
  float py = static_cast <float> (this->location_.y_) + (height + 15.0f);

  static const Gdiplus::Font font (L"Arial", 10);
  static const Gdiplus::SolidBrush brush (Gdiplus::Color (0, 0, 0));

  Gdiplus::StringFormat format;
  format.SetAlignment (Gdiplus::StringAlignmentCenter);
  format.SetLineAlignment (Gdiplus::StringAlignmentCenter);

  CComBSTR bstr (this->label_.length (), this->label_.c_str ());

  // Draw the label for the element.
  g.DrawString (bstr, 
                this->label_.length (),
                &font,
                Gdiplus::PointF (px, py),
                &format,
                &brush);

  return 0;
}

//
// draw
//
int Component_Decorator_Impl::draw_ports (Gdiplus::Graphics & g)
{
  if (this->l_ports_.empty () && this->r_ports_.empty ())
    return 0;

  using GAME::graphics::Port_Decorator;

  // Draw the ports for the model.
  std::for_each (this->l_ports_.begin (),
                 this->l_ports_.end (),
                 boost::bind (&Port_Decorator::draw, 
                              _1,
                              boost::ref (g)));

  std::for_each (this->r_ports_.begin (),
                 this->r_ports_.end (),
                 boost::bind (&Port_Decorator::draw, 
                              _1, 
                              boost::ref (g)));

  return 0;
}
