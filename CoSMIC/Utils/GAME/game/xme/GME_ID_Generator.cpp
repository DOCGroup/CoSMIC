// $Id$

#include "GME_ID_Generator.h"

#if !defined (__GAME_INLINE__)
#include "GME_ID_Generator.inl"
#endif

#include "GME_ID_Generator_T.h"

namespace GAME
{
namespace XME
{
const ::Utils::XStr initial_id <Model>::result_type ("id-0065-00000000");
const ::Utils::XStr initial_id <Atom>::result_type ("id-0066-00000000");
const ::Utils::XStr initial_id <Reference>::result_type ("id-0067-00000000");
const ::Utils::XStr initial_id <Connection>::result_type ("id-0068-00000000");
const ::Utils::XStr initial_id <Folder>::result_type ("id-006a-00000000");

//
// init
//
void GME_ID_Generator::init (xercesc::DOMDocument * proj)
{
  GME_XME_ID_GENERATOR (Folder)->init (proj);
  GME_XME_ID_GENERATOR (Model)->init (proj);
  GME_XME_ID_GENERATOR (Reference)->init (proj);
  GME_XME_ID_GENERATOR (Connection)->init (proj);
  GME_XME_ID_GENERATOR (Atom)->init (proj);

  /// @todo add init () for Set
}

//
// reset
//
void GME_ID_Generator::reset (void)
{
  GME_XME_ID_GENERATOR (Folder)->reset ();
  GME_XME_ID_GENERATOR (Model)->reset ();
  GME_XME_ID_GENERATOR (Reference)->reset ();
  GME_XME_ID_GENERATOR (Connection)->reset ();
  GME_XME_ID_GENERATOR (Atom)->reset ();

  /// @todo add reset () for Set
}

}
}
