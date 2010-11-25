
namespace GAME
{

//
// get_objects
//
GAME_INLINE
void Extension_Classes_Visitor::get_objects (std::set <GAME::Object> & objects)
{
  objects = this->objects_;
}

//
// get_src_connections
//
GAME_INLINE
void Extension_Classes_Visitor::get_src_connections (GAME::Connection connection,
                                                     std::string name,
                                                     CONNECTIONS & connection_vector)
{
  connection["src"].target ().in_connections (name, connection_vector);
}

//
// get_dst_connections
//
GAME_INLINE
void Extension_Classes_Visitor::
get_dst_connections (GAME::Connection connection,
                           std::string name,
                           CONNECTIONS & connection_vector)
{
  connection["dst"].target ().in_connections (name, connection_vector);
}

//
// create_directory
//
GAME_INLINE
void Extension_Classes_Visitor::create_directory (std::string inner_path)
{
  // insert the full path at the begining and then create the directory
  inner_path.insert (0, this->outdir_);
  mkdir (inner_path.c_str ());
}

}