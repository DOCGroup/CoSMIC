// -*- C++ -*-

//=============================================================================
/**
 * @file        Collection_T.h
 *
 * Defines the collection container
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_COLLECTION_T_H_
#define _GAME_MGA_COLLECTION_T_H_

#include <vector>

namespace GAME
{
namespace Mga
{

//
// iter_to_collection
//
template <typename ITER, typename T>
size_t iter_to_collection (ITER iter, std::vector <T> & coll);

}
}

#include "Collection_T.cpp"

#endif  // !defined _GME_COLLECTION_T_H_
