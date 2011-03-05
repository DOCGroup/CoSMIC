// -*- C++ -*-

//=============================================================================
/**
 * @file      Image_Resolver.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_GRAPHICS_IMAGE_RESOLVER_H_
#define _GME_GRAPHICS_IMAGE_RESOLVER_H_

#include <string>
#include <vector>

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include "game/config.h"

#include "game/mga/utils/Registrar.h"
#include "Graphics_export.h"

namespace GAME
{
namespace Mga
{

// Forward decl.
class Project;

namespace graphics
{
/**
 * @class Image_Resolver
 *
 * Utility class that resolves the location of an image. It uses the
 * icon paths defined in the element projects to resolve the correct
 * location. If the icon exists in multiple locations, then the first
 * path where the image is located is used.
 */
class GAME_GRAPHICS_Export Image_Resolver
{
public:
  /// Default constructor.
  Image_Resolver (void);

  /// Destructor.
  ~Image_Resolver (void);

  bool lookup_icon (const std::string & icon_filename,
                    std::string & out_filename);

  bool refresh (const Project & project,
                const Registrar & r,
                Registrar::ACCESS_MODE mode);

  bool init (const Project & project,
             const Registrar & r,
             Registrar::ACCESS_MODE mode);

  /// Test if the resolver is initialized.
  bool is_init (void) const;

private:
  /// Initialization status for the class.
  bool is_init_;

  /// Colleciton of paths.
  std::vector <std::string> paths_;
};

/// Type definition of the global image resolver.
typedef ACE_Singleton <Image_Resolver, ACE_Null_Mutex> GLOBAL_IMAGE_RESOLVER;

GAME_GRAPHICS_SINGLETON_DECLARE (ACE_Singleton, Image_Resolver, ACE_Null_Mutex);

}
}
}

#if defined (__GAME_INLINE__)
#include "Image_Resolver.inl"
#endif

#endif  // !defined _GME_GRAPHICS_IMAGE_RESOLVER_H_
