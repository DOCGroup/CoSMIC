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

  bool is_init (void) const;

private:
  /// Initialization status for the class.
  bool is_init_;

  /// Colleciton of paths.
  std::vector <std::string> paths_;
};

typedef ACE_Singleton <Image_Resolver, ACE_RW_Thread_Mutex> GLOBAL_IMAGE_RESOLVER;

GAME_GRAPHICS_SINGLETON_DECLARE (ACE_Singleton, Image_Resolver, ACE_RW_Thread_Mutex);

}
}
}

#if defined (__GAME_INLINE__)
#include "Image_Resolver.inl"
#endif

#endif  // !defined _GME_GRAPHICS_IMAGE_RESOLVER_H_
