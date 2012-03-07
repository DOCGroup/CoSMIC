// $Id$

#include "Collection_T.h"
#include "game/mga/MetaFCO.h"

namespace GAME
{
namespace Mga
{

namespace assert
{
/**
 * @struct element_not_containable_in_model
 *
 * Assertion that determines if an implementation is containable in
 * a model. This will prevent clients from requesting children of type
 * Folder from a model.
 */
template <typename T>
struct element_not_in_connection;

template < >
struct element_not_in_connection <connection_tag_t>
{
  static const bool result_type = true;
};

}

//
// children
//
template <typename T>
size_t FCO_Impl::in_connections (std::vector <T> & conns) const
{
  typedef typename T::impl_type impl_type;
  assert::element_not_in_connection <impl_type::type_tag>::result_type;

  CComPtr <IMgaConnPoints> temp;
  VERIFY_HRESULT (this->impl ()->get_PartOfConns (&temp));

  std::vector <ConnectionPoint> points;

  if (0 == iter_to_collection (temp.p, points))
    return 0;

  Connection conn;
  std::vector <ConnectionPoint>::const_iterator
    iter = points.begin (), iter_end = points.end ();

  for (; iter != iter_end; ++ iter)
  {
    // Get the connection that own this point.
    conn = (*iter)->owner ();

    if (conn->meta ()->name () == impl_type::metaname)
      conns.push_back (T::_narrow (conn));
  }

  return conns.size ();
}

}
}
