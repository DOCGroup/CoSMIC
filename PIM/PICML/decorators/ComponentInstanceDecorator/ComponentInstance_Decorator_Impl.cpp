#include "StdAfx.h"
#include "ComponentInstance_Decorator.h"
#include "ComponentInstance_Decorator_Impl.h"
#include "game/mga/decorator/Decorator_T.h"

#include "game/mga/MetaFCO.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Model.h"
#include "game/mga/Reference.h"
#include "game/mga/Iterator_T.h"

#include "game/mga/graphics/Image_Resolver.h"
#include "game/mga/graphics/Stock_Objects.h"

#include "boost/bind.hpp"

#define GME_PORT_HEIGHT         11
#define GME_PORT_WIDTH          11

#define GME_PORT_PADDING_Y      4

#define GME_PORT_MARGIN_X       4
#define GME_PORT_MARGIN_Y       4

#define COMPONENT_DEFUALT_WIDTH     143
#define COMPONENT_DEFAULT_HEIGHT    70
#define COMPONENT_LINE_WIDTH        3

DECLARE_DECORATOR (ComponentInstance_Decorator, ComponentInstance_Decorator_Impl);

/**
 * @struct sort_top_to_bottom_t
 */
struct sort_top_to_bottom_t
{
  typedef ComponentInstance_Decorator_Impl::port_set_t port_set_t;

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
  typedef ComponentInstance_Decorator_Impl::port_set_t::value_type value_type;

  set_port_location_t (GAME::Mga::Point & next)
    : next_ (next) { }

  void operator () (value_type & port)
  {
    port->location (this->next_);
    this->next_.shift (0, GME_PORT_HEIGHT + GME_PORT_PADDING_Y);
  }

private:
  /// The next port location.
  GAME::Mga::Point & next_;
};

///////////////////////////////////////////////////////////////////////////////

//
// ComponentInstance_Decorator_Impl
//
ComponentInstance_Decorator_Impl::ComponentInstance_Decorator_Impl (void)
{

}

//
// ~ComponentInstance_Decorator_Impl
//
ComponentInstance_Decorator_Impl::~ComponentInstance_Decorator_Impl (void)
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
void ComponentInstance_Decorator_Impl::destroy (void)
{
  this->port_bitmaps_.clear ();

  std::for_each (this->l_ports_.begin (),
                 this->l_ports_.end (),
                 delete_t <GAME::Mga::Port_Decorator> ());

  std::for_each (this->r_ports_.begin (),
                 this->r_ports_.end (),
                 delete_t <GAME::Mga::Port_Decorator> ());
}

//
// initialize
//
int ComponentInstance_Decorator_Impl::
initialize (const GAME::Mga::Project & proj,
            const GAME::Mga::Meta::Part_in part,
            const GAME::Mga::FCO_in fco,
            IMgaCommonDecoratorEvents * sink,
            ULONGLONG window)
{
  if (0 != GAME::Mga::FCO_Decorator::initialize (proj, part, fco, sink, window))
    return -1;

  // We also need to determine the implementation to show. This is
  // done by getting the name of the implementation.
  using GAME::Mga::Model;
  using GAME::Mga::FCO;
  using GAME::Mga::Iterator;
  using GAME::Mga::Reference;

  Model model = Model::_narrow (fco);
  GAME::Mga::Collection_T <Reference> iter = model->children <Reference> ("ComponentInstanceType");

  if (iter.count() > 0)
  {
    FCO refers_to = iter.first();

    if (!refers_to.is_nil ())
      this->impl_label_ = refers_to->name ();
  }

  if (this->impl_label_.empty ())
    this->impl_label_ = "<undefined>";

  using GAME::Mga::graphics::GLOBAL_IMAGE_RESOLVER;
  this->initialize_ports ("ComponentInterface",
                          fco,
                          GLOBAL_IMAGE_RESOLVER::instance ());

  // Finally, sort the ports from top to bottom.
  std::sort (this->l_ports_.begin (),
             this->l_ports_.end (),
             sort_top_to_bottom_t ());

  std::sort (this->r_ports_.begin (),
             this->r_ports_.end (),
             sort_top_to_bottom_t ());

  return 0;
}

//
// initialize_ports
//
int ComponentInstance_Decorator_Impl::
initialize_ports (const std::string & aspect_name,
                  const GAME::Mga::FCO_in fco,
                  GAME::Mga::graphics::Image_Resolver * resolver)
{
  // Get the target aspect.
  GAME::Mga::Model model = GAME::Mga::Model::_narrow (fco);
  GAME::Mga::Meta::Aspect aspect = model->meta ()->aspect (aspect_name);

  if (aspect.is_nil ())
    return 0;

  // Select all the FCO elements in the specified aspect.
  std::vector <GAME::Mga::FCO> ports;
  if (model->children (aspect, ports) == 0)
    return 0;

  std::vector <GAME::Mga::FCO>::iterator
    iter = ports.begin (), iter_end = ports.end ();

  GAME::Mga::Part part;
  std::string icon_filename, filename;
  Gdiplus::Image * image = 0;

  for (; iter != iter_end; ++ iter)
  {
    // First, let's determine if the element is indeed a port. If
    // it is not a port, let's just continue to the next iteration.
    part = (*iter)->part (aspect);

    if (!part.meta ()->is_linked ())
      continue;

    // Load the icon for the specified element.
    icon_filename = (*iter)->meta ()->registry_value ("icon");

    if (resolver->lookup_icon (icon_filename, filename))
      this->port_bitmaps_.associate_image (*iter, filename, image);

    // Determine what side of the model this port should
    // be displayed.
    long x, y;
    part.get_location (x, y);

    using GAME::Mga::Port_Decorator;

    GAME::Mga::Point location (x, y);
    Port_Decorator * port = new Port_Decorator (*iter,
                                                image,
                                                (*iter)->name (),
                                                location);

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
  std::vector <GAME::Mga::Reference> inherits;

  if (model->children ("ComponentInherits", inherits))
  {
    GAME::Mga::FCO refers_to = inherits.front ()->refers_to ();

    if (!refers_to.is_nil ())
      this->initialize_ports ("InterfaceDefinition", refers_to, resolver);
  }

  return 0;
}

//
// location
//
void ComponentInstance_Decorator_Impl::
set_location (const GAME::Mga::Rect & loc)
{
  // Now that we know our dimensions, let's draw the bitmap
  // for this component to size.
  GAME::Mga::Point pt (loc.x_, loc.y_);

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
  GAME::Mga::Decorator_Impl::set_location (loc);

  // Initialize the graphics path for the component.
  this->initialize_graphics_path ();
}

//
// initialize_graphics_path
//
int ComponentInstance_Decorator_Impl::initialize_graphics_path (void)
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
int ComponentInstance_Decorator_Impl::
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
int ComponentInstance_Decorator_Impl::draw (Gdiplus::Graphics * g)
{
  return ((this->draw_component (g) == 0) &&
          (this->draw_label (g) == 0) &&
          (this->draw_ports (g) == 0)) ? 0 : -1;
}

//
// draw_component
//
int ComponentInstance_Decorator_Impl::draw_component (Gdiplus::Graphics * g)
{
  // Start drawing the component image.
  static const Gdiplus::SolidBrush brush (Gdiplus::Color (210, 210, 210));
  g->FillPath (&brush, &this->graphics_path_);

  static const Gdiplus::Pen pen (Gdiplus::Color (100, 100, 100), COMPONENT_LINE_WIDTH);
  g->DrawPath (&pen, &this->graphics_path_);

  return 0;
}

//
// draw_label
//
int ComponentInstance_Decorator_Impl::draw_label (Gdiplus::Graphics * g)
{
  float height = (float)this->location_.height ();
  float px = static_cast <float> (this->location_.x_) + (this->location_.width () / 2.0f);
  float py = static_cast <float> (this->location_.y_) + (height + 15.0f);
  const CComBSTR bstr (this->label_.length (), this->label_.c_str ());

  using GAME::Mga::graphics::Stock_Objects;
  using GAME::Mga::graphics::GLOBAL_STOCK_OBJECTS;
  Stock_Objects * stock = GAME::Mga::graphics::GLOBAL_STOCK_OBJECTS::instance ();

  // Draw the label for the element.
  g->DrawString (bstr,
                 this->label_.length (),
                 stock->label_font (),
                 Gdiplus::PointF (px, py),
                 stock->label_string_format (),
                 stock->label_brush ());

  if (this->impl_label_.empty ())
    return 0;

  std::string inst_label ("[");
  inst_label += this->impl_label_ + "]";

  const CComBSTR inst_bstr (inst_label.length (), inst_label.c_str ());
  g->DrawString (inst_bstr,
                 inst_label.length (),
                 stock->label_font (),
                 Gdiplus::PointF (px, py + 15),
                 stock->label_string_format (),
                 stock->label_brush ());

  return 0;
}

//
// draw
//
int ComponentInstance_Decorator_Impl::draw_ports (Gdiplus::Graphics * g)
{
  using GAME::Mga::Port_Decorator;

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

//
// get_ports
//
int ComponentInstance_Decorator_Impl::
get_ports (std::vector < ::GAME::Mga::FCO> & v)
{
  for (auto & l_port : l_ports_)
    v.push_back (l_port->fco ());

  for (auto & r_port : r_ports_)
    v.push_back (r_port->fco ());

  return 0;
}

/**
 * @struct is_matching_port
 *
 * Functor for testing if a port decorator matches a given
 * FCO element.
 */
struct is_matching_port
{
  is_matching_port (const GAME::Mga::FCO_in fco)
    : fco_ (fco)
  {

  }

  bool operator () (GAME::Mga::Port_Decorator * d) const
  {
    return this->fco_->is_equal_to (d->fco ());
  }

private:
  const GAME::Mga::FCO_in fco_;
};

//
// get_port_location
//
int ComponentInstance_Decorator_Impl::
get_port_location (const GAME::Mga::FCO_in fco,
                   long & sx,
                   long & sy,
                   long & ex,
                   long & ey)
{
  // Search the left ports for the FCO.
  std::vector <GAME::Mga::Port_Decorator *>::const_iterator result;

  result = std::find_if (this->l_ports_.begin (),
                         this->l_ports_.end (),
                         is_matching_port (fco));

  if (result == this->l_ports_.end ())
  {
    // Search the right ports for the FCO.
    result = std::find_if (this->r_ports_.begin (),
                           this->r_ports_.end (),
                           is_matching_port (fco));

    if (result == this->r_ports_.end ())
      return -1;
  }

  (*result)->get_location (sx, sy, ex, ey);
  return 0;
}
