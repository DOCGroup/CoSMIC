// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{
namespace graphics
{
//
// Image_Manager
//
template <typename T>
GAME_INLINE
Image_Manager_T <T>::Image_Manager_T (void)
{

}

//
// ~Image_Manager
//
template <typename T>
GAME_INLINE
Image_Manager_T <T>::~Image_Manager_T (void)
{
  this->clear ();
}

//
// associate_image
//
template <typename T>
GAME_INLINE
bool Image_Manager_T <T>::
associate_image (const T & key, const std::string & filename)
{
  Gdiplus::Image * image = 0;
  return this->associate_image (key, filename, image);
}

}
}
}
