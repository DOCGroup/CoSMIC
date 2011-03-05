// $Id$

#include "stdafx.h"

#include "Stock_Objects.h"

#if !defined (__GAME_INLINE__)
#include "Stock_Objects.inl"
#endif

namespace GAME
{
namespace Mga
{
namespace graphics
{

//
// init
//
void Stock_Objects::init (void)
{
  // Initialize the stock objects for the label.
  this->label_font_.reset (new Gdiplus::Font (L"Arial", 10));
  this->label_brush_.reset (new Gdiplus::SolidBrush (Gdiplus::Color (0, 0, 0)));

  this->label_str_format_.reset (new Gdiplus::StringFormat ());
  this->label_str_format_->SetAlignment (Gdiplus::StringAlignmentCenter);
  this->label_str_format_->SetLineAlignment (Gdiplus::StringAlignmentCenter);
}

}
}
}
