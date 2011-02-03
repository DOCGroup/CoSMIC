#include "Utils.h"

namespace GAME
{
namespace Mga
{

//
// get_objects
//
GAME_INLINE
const std::set <Object> & Extension_Classes_Visitor::get_objects (void) const
{
  return this->objects_;
}

//
// get_src_connections
//
GAME_INLINE
void Extension_Classes_Visitor::
get_src_connections (Connection_in conn,
                     std::string name,
                     CONNECTIONS & connection_vector)
{
  conn->src ()->in_connections (name, connection_vector);
}

//
// get_dst_connections
//
GAME_INLINE
void Extension_Classes_Visitor::
get_dst_connections (Connection_in conn,
                     std::string name,
                     CONNECTIONS & connection_vector)
{
  conn->dst ()->in_connections (name, connection_vector);
}

//
// create_directory
//
GAME_INLINE
void Extension_Classes_Visitor::create_directory (std::string inner_path)
{
  // insert the full path at the begining and then create the directory
  inner_path.insert (0, this->outdir_);
  ::GAME::Utils::create_path (inner_path);
}

}
}
