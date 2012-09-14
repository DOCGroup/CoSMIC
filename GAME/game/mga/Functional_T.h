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

#ifndef _GAME_MGA_FUNCTIONAL_T_H_
#define _GAME_MGA_FUNCTIONAL_T_H_

#include "GME_fwd.h"

namespace GAME
{
namespace Mga
{

template <typename T, typename P>
T create_root_folder (P parent, const Meta::Folder_in meta);

template <typename T, typename P>
T create_root_folder (P parent, const std::string & meta);

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

template <typename T>
T get_parent (IMgaObject * obj);

template <typename T, typename R>
T get_refers_to (R ref);

template <typename T>
Object_Impl * allocate_impl (IMgaObject * ptr);

}
}

#include "Functional_T.cpp"

#endif  // !defined _GAME_MGA_FACTORY_T_H_
