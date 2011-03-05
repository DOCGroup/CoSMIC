// $Id$

#if !defined (__GAME_INLINE__)
#include "Image_Manager_T.inl"
#endif

namespace GAME
{
namespace Mga
{
namespace graphics
{
//
// associate_image
//
template <typename T>
bool Image_Manager_T <T>::
associate_image (const T & key,
                 const std::string & filename,
                 Gdiplus::Image * & image)
{
  if (!this->get_image (filename, image))
  {
    CA2W tempstr (filename.c_str ());
    image = Gdiplus::Image::FromFile (tempstr);
  }

  this->assoc_[key] = image;
  return true;
}

//
// get_image
//
template <typename T>
bool Image_Manager_T <T>::
get_image (const T & key, Gdiplus::Image * & image) const
{
  std::map <T, Gdiplus::Image *>::const_iterator iter = this->assoc_.find (key);

  if (iter != this->assoc_.end ())
  {
    image = iter->second;
    return true;
  }

  return false;
}

//
// get_image
//
template <typename T>
bool Image_Manager_T <T>::
get_image (const std::string & filename, Gdiplus::Image * & image) const
{
  std::map <std::string, Gdiplus::Image *>::
    const_iterator iter = this->images_.find (filename);

  if (iter != this->images_.end ())
  {
    image = iter->second;
    return true;
  }

  return false;
}

//
// clear
//
template <typename T>
void Image_Manager_T <T>::clear (void)
{
  image_map_t::iterator
    iter = this->images_.begin (),
    iter_end = this->images_.end ();

  for (; iter != iter_end; ++ iter)
    delete iter->second;

  this->images_.clear ();
  this->assoc_.clear ();
}

}
}
}
