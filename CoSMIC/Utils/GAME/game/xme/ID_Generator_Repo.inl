// -*- C++ -*-
// $Id$


namespace GAME
{
namespace XME
{

//
// ID_Generator_Repo
//
GAME_INLINE
ID_Generator_Repo::ID_Generator_Repo (void)
{

}

//
// ~ID_Generator_Repo
//
GAME_INLINE
ID_Generator_Repo::~ID_Generator_Repo (void)
{

}

//
// get
//
GAME_INLINE
GME_ID_Generator * ID_Generator_Repo::get (xercesc::DOMElement * e)
{
  return this->get (e->getOwnerDocument ());
}

}
}
