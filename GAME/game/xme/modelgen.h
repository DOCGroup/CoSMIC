// -*- C++ -*-

//=============================================================================
/**
 *  @file           modelgen.h
 *
 *  $Id$
 *
 *  @author         James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_MODELGEN_H_
#define _GAME_XME_MODELGEN_H_

#include "game/mga/utils/modelgen.h"

namespace GAME
{
/// Tag definition for the MGA architecture.
struct Xme_t;

/**
 * Specialization of the get_chilren () method for the modelgen
 * framework.
 */
template < >
struct get_children <Xme_t>
{
public:
  template <typename P, typename T, typename META>
  size_t operator () (P parent, const META & metaname, T & element);
};

template <typename T>
struct create_element <Xme_t, T>
{
  template <typename P, typename META>
  T operator () (P parent, const META & metaname);
};

}

#include "modelgen.cpp"

#endif  // !defined _GAME_MODELGEN_H_
