
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
void Extension_Classes_Visitor::get_dst_connections (GAME::Connection connection,
                                                     std::string name,
                                                     CONNECTIONS & connection_vector)
{
  connection["dst"].target ().in_connections (name, connection_vector);
}

//
// get_src_name
//
GAME_INLINE
std::string Extension_Classes_Visitor::get_src_name (GAME::Connection connection)
{
  return connection["src"].target ().name ();
}

//
// get_dst_name
//
GAME_INLINE
std::string Extension_Classes_Visitor::get_dst_name (GAME::Connection connection)
{
  return connection["dst"].target ().name ();
}

//
// get_src_meta_name
//
GAME_INLINE
std::string Extension_Classes_Visitor::get_src_meta_name (GAME::Connection connection)
{
  return connection["src"].target ().meta ().name ();
}

//
// get_dst_meta_name
//
GAME_INLINE
std::string Extension_Classes_Visitor::get_dst_meta_name (GAME::Connection connection)
{
  return connection["dst"].target ().meta ().name ();
}

}