// $Id$

#include "stdafx.h"
#include "Port_Decorator.h"

#if !defined (__GAME_INLINE__)
#include "Port_Decorator.inl"
#endif

// We should make a graphics configuration class and place these
// contants there. This way, they can be customized for different
// domains.
#define GME_PORT_WIDTH          11
#define GME_PORT_HEIGHT         11
#define GME_PORT_LABEL_OFFSET   2
#define GME_PORT_LABEL_LENGTH   4

namespace GAME
{
namespace Mga
{

//
// draw
//
bool Port_Decorator::draw (Gdiplus::Graphics * g)
{
  if (0 == this->image_)
    return false;

  // Draw the port's image.
  g->DrawImage (this->image_,
                static_cast <float> (this->location_.x_value ()),
                static_cast <float> (this->location_.y_value ()),
                static_cast <float> (GME_PORT_WIDTH),
                static_cast <float> (GME_PORT_HEIGHT));

  // There is now need to continue if we have no label.
  if (this->label_.empty ())
    return true;

  // Write the name of the port.
  float px = static_cast <float> (this->location_.x_value ());
  float py = static_cast <float> (this->location_.y_value () - 1);

  Gdiplus::StringFormat format;

  if (this->alignment_ == ALIGNMENT_LEFT)
  {
    px += GME_PORT_WIDTH + GME_PORT_LABEL_OFFSET;

    format.SetAlignment (Gdiplus::StringAlignmentNear);
    format.SetLineAlignment (Gdiplus::StringAlignmentNear);
  }
  else
  {
    px -= GME_PORT_LABEL_OFFSET;

    format.SetAlignment (Gdiplus::StringAlignmentFar);
    format.SetLineAlignment (Gdiplus::StringAlignmentNear);
  }

  const Gdiplus::Font font (L"Arial", 8);
  const Gdiplus::SolidBrush brush (Gdiplus::Color (0, 0, 0));

  CComBSTR bstr (this->label_.length (), this->label_.c_str ());

  // Draw the label for the element.
  g->DrawString (bstr,
                 GME_PORT_LABEL_LENGTH,
                 &font,
                 Gdiplus::PointF (px, py),
                 &format,
                 &brush);

  return true;
}

//
// get_location
//
void Port_Decorator::
get_location (long & sx, long & sy, long & ex, long & ey)
{
  sx = this->location_.x_value ();
  sy = this->location_.y_value ();

  ex = sx + GME_PORT_WIDTH;
  ey = sy + GME_PORT_HEIGHT;
}

}
}
