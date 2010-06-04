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
/**
 * @struct collection_traits
 *
 * Trait class that determines the GME item type of a collection.
 */
template <typename T>
struct collection_traits
{

};

template < >
struct collection_traits <IMgaObjects>
{
  typedef IMgaObject interface_type;
};

template < >
struct collection_traits <IMgaFCOs>
{
  typedef IMgaFCO interface_type;
};

template < >
struct collection_traits <IMgaFolders>
{
  typedef IMgaFolder interface_type;
};

template < >
struct collection_traits <IMgaAttributes>
{
  typedef IMgaAttribute interface_type;
};

template < >
struct collection_traits <IMgaConnPoints>
{
  typedef IMgaConnPoint interface_type;
};

template < >
struct collection_traits <IMgaRegNodes>
{
  typedef IMgaRegNode interface_type;
};

template < >
struct collection_traits <IMgaMetaFolders>
{
  typedef IMgaMetaFolder interface_type;
};

template < >
struct collection_traits <IMgaMetaFCOs>
{
  typedef IMgaMetaFCO interface_type;
};

template < >
struct collection_traits <IMgaMetaAspects>
{
  typedef IMgaMetaAspect interface_type;
};

/**
 * @struct item_traits
 *
 * Trait class that determines the GME collection type of an object.
 */
template <typename T>
struct item_traits
{

};

template < >
struct item_traits <Object>
{
  typedef IMgaObjects collection_type;
};

template < >
struct item_traits <FCO>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Atom>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Model>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Set>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Reference>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Connection>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Folder>
{
  typedef IMgaFolders collection_type;
};

template < >
struct item_traits <Attribute>
{
  typedef IMgaAttributes collection_type;
};

template < >
struct item_traits <ConnectionPoint>
{
  typedef IMgaConnPoints collection_type;
};

template < >
struct item_traits <RegistryNode>
{
  typedef IMgaRegNodes collection_type;
};

template < >
struct item_traits <Meta::Folder>
{
  typedef IMgaMetaFolders collection_type;
};

template < >
struct item_traits <Meta::FCO>
{
  typedef IMgaMetaFCOs collection_type;
};

template < >
struct item_traits <Meta::Aspect>
{
  typedef IMgaMetaAspects collection_type;
};

template <typename ITER, typename T>
size_t get_children (ITER iter, std::vector <T> & coll);

}

#include "Collection_T.cpp"

#endif  // !defined _GME_COLLECTION_T_H_
