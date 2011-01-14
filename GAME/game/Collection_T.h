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

#ifndef _GME_COLLECTION_T_H_
#define _GME_COLLECTION_T_H_

#if !defined (__ComponentLib_h__) && !defined (__DecoratorLib_h__)
#include "Mga.h"
#endif

#include "GAME_export.h"
#include "GME_fwd.h"
#include "Exception.h"
#include <atlcomcli.h>
#include <vector>

namespace GAME
{

//
// iter_to_collection
//
template <typename ITER, typename T>
size_t iter_to_collection (ITER iter, std::vector <T> & coll);

}

#include "Collection_T.cpp"

#endif  // !defined _GME_COLLECTION_T_H_
