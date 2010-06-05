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

#define GME_PORT_MARGIN_X       8
#define GME_PORT_MARGIN_Y       8

DECLARE_DECORATOR (Component_Decorator, Component_Decorator_Impl);

/**
 * @struct draw_port_t
 *
 * Functor to help with drawing a port.
 */
struct draw_port_t
{
public:
  typedef GAME::graphics::Image_Manager_T <GAME::FCO> bitmap_map_t;

  draw_port_t (Gdiplus::Graphics & g, const bitmap_map_t & bitmaps)
    : g_ (g),
      bitmaps_ (bitmaps)
  {

  }

  void operator () (const std::pair <GAME::FCO, GAME::utils::Point> & e)
  {
    Gdiplus::Image * image = 0;

    if (this->bitmaps_.get_image (e.first, image))
    {
      this->g_.DrawImage (image,
                          static_cast <float> (e.second.x_value ()),
                          static_cast <float> (e.second.y_value ()),
                          static_cast <float> (GME_PORT_WIDTH),
                          static_cast <float> (GME_PORT_HEIGHT));
    }
  }

private:
  /// Target graphics object.
  Gdiplus::Graphics & g_;

  /// Collection of bitmaps for the ports.
  const bitmap_map_t & bitmaps_;
};

//
// Component_Decorator_Impl
//
Component_Decorator_Impl::Component_Decorator_Impl (void)
: sorter_ (aspect_),
  l_ports_ (sorter_),
  r_ports_ (sorter_)
{

}

//
// ~Component_Decorator_Impl
//
Component_Decorator_Impl::~Component_Decorator_Impl (void)
{

}

//
// destroy
//
void Component_Decorator_Impl::destroy (void)
{ 

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

  std::string icon_filename;

  if (fco.is_nil ())
  {
    // Get the icon for the element in the parts browser.
    GAME::Meta::FCO metafco = part.role ().kind ();

    icon_filename = metafco.registry_value ("icon");
    this->label_ = metafco.display_name ().c_str ();
  }
  else
  {
    // Get the icon filename.
    icon_filename = fco.registry_value ("icon");

    // Determine if we need to show the label for the element.
    std::string show_name = fco.registry_value ("isNameEnabled");

    if (show_name.empty () || show_name == "true")
      this->label_ = fco.name ();
  }

  // Determine the exact location of the filename based on the
  // paths retrieved from the registrar.
  std::string filename;

  if (!resolver->lookup_icon (icon_filename, filename))
    return E_DECORATOR_INIT_WITH_NULL;

  CA2W tempstr (filename.c_str ());
  this->bitmap_.reset (Gdiplus::Bitmap::FromFile (tempstr));

  if (!fco.is_nil ())
    this->initialize_ports (fco, resolver);

  return S_OK;
}

//
// initialize_ports
//
int Component_Decorator_Impl::
initialize_ports (const GAME::FCO & fco, GAME::graphics::Image_Resolver * resolver)
{
  GAME::Model model = GAME::Model::_narrow (fco);
  GAME::Meta::Model metamodel = model.meta ();
  this->aspect_ = metamodel.aspect ("InterfaceDefinition");

  std::vector <GAME::FCO> ports;
  if (model.children (this->aspect_, ports) == 0)
    return 0;

  std::vector <GAME::FCO>::const_iterator 
    iter = ports.begin (), iter_end = ports.end ();

  GAME::Part part;
  std::string icon_filename, filename;

  for (; iter != iter_end; ++ iter)
  {
    // Get information about this part.
    part = iter->part (this->aspect_);
    icon_filename = iter->meta ().registry_value ("icon");

    if (resolver->lookup_icon (icon_filename, filename))
      this->port_bitmaps_.associate_image (*iter, filename);

    // We need to save this element it is part of this aspect 
    // and it is a port. 
    long x, y;

    if (part.meta ().is_linked ())
    {
      part.get_location (x, y);

      if (x < 200)
        this->l_ports_[*iter] = GAME::utils::Point (x, y);
      else
        this->r_ports_[*iter] = GAME::utils::Point (x, y);
    }
  }

  // We need to get all the ports that we inherit.
  std::vector <GAME::Reference> inherits;

  if (model.children ("ComponentInherits", inherits))
  {
    GAME::Reference inherit = inherits[0];
    GAME::FCO refers_to = inherit.refers_to ();

    if (!refers_to.is_nil ())
      this->initialize_ports (refers_to, resolver);
  }

  return 0;
}

struct set_port_location_t
{
  set_port_location_t (GAME::utils::Point & next)
    : next_ (next)
  {

  }

  void operator () (std::pair <const GAME::FCO, GAME::utils::Point> & e) 
  {
    std::string name = e.first.name ();

    e.second = this->next_;
    this->next_.shift (0, GME_PORT_HEIGHT + GME_PORT_PADDING_Y);
  }

private:
  /// The next port location.
  GAME::utils::Point & next_;
};

//
// location
//
void Component_Decorator_Impl::
set_location (const GAME::utils::Rect & loc)
{
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

  // Pass control to the base class.
  GAME::Decorator_Impl::set_location (loc);
}

//
// get_preferred_size
//
int Component_Decorator_Impl::
get_preferred_size (long & sx, long & sy)
{
  // The width of the component is the same.
  sx = this->bitmap_->GetWidth ();

  // Determine the height of the component's bitmap.
  long curr_height = this->bitmap_->GetHeight ();
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
  // Draw the main bitmap for this element.
  g.DrawImage (this->bitmap_.get (),
               this->location_.x_,
               this->location_.y_,
               this->location_.cx_ - this->location_.x_,
               this->location_.cy_ - this->location_.y_);

  return 0;
}

//
// draw_label
//
int Component_Decorator_Impl::draw_label (Gdiplus::Graphics & g)
{
  float height = this->location_.cy_ - this->location_.y_;
  float px = static_cast <float> (this->location_.x_) + (this->bitmap_->GetWidth () / 2.0);
  float py = static_cast <float> (this->location_.y_) + (height + 15.0);

  Gdiplus::Font font (L"Arial", 12);
  Gdiplus::SolidBrush brush (Gdiplus::Color (0, 0, 0));

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

  // Draw the ports for the model.
  std::for_each (this->l_ports_.begin (),
                 this->l_ports_.end (),
                 draw_port_t (g, this->port_bitmaps_));

  std::for_each (this->r_ports_.begin (),
                 this->r_ports_.end (),
                 draw_port_t (g, this->port_bitmaps_));

  return 0;
}
