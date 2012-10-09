// -*- C++ -*-
// $Id$

//
// Proxy_Visitor
//
GAME_INLINE
Proxy_Visitor::Proxy_Visitor (void)
{

}

//
// ~Proxy_Visitor
//
GAME_INLINE
Proxy_Visitor::~Proxy_Visitor (void)
{

}

//
// Proxy_Fwd_Visitor
//
GAME_INLINE
Proxy_Fwd_Visitor::Proxy_Fwd_Visitor (GAME::Mga::Visitor * fwd)
: fwd_ (fwd)
{

}

//
// ~Proxy_Fwd_Visitor
//
GAME_INLINE
Proxy_Fwd_Visitor::~Proxy_Fwd_Visitor (void)
{

}
