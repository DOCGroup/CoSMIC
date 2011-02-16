// -*- C++ -*-

//=============================================================================
/**
 * @file    Factory_T.h
 *
 * $Id$
 *
 * @author  James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_FACTORY_T_H_
#define _GAME_MGA_FACTORY_T_H_

namespace GAME
{
namespace Mga
{

template <typename T, typename P>
T create_root_object (P parent, const Meta::FCO_in metafco);

template <typename T, typename P>
T create_root_object (P parent, const std::string & metaname);

template <typename T, typename P>
T create_object (P parent, const Meta::Role_in role);

template <typename T, typename P>
T create_object (P parent, const std::string & metaname);

template <typename T, typename P>
T create_folder (P parent, const std::string & metaname);

template <typename T, typename P>
T create_folder (P parent, const Meta::Folder_in meta);

}
}

#include "Factory_T.cpp"

#endif  // !defined _GAME_MGA_FACTORY_T_H_
