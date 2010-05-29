// -*- C++ -*-

//=============================================================================
/**
 * @file      GME_ID_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_GME_ID_GENERATOR_H_
#define _GAME_GME_ID_GENERATOR_H_

#include "xercesc/dom/DOM.hpp"
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include "game/config.h"
#include "GME_ID_Generator_T.h"

namespace GAME
{
namespace XME
{
/**
 * @class GME_ID_Generator_T
 *
 * ID generator for different model element types.
 */
class GME_ID_Generator
{
public:
  /// Default constructor.
  GME_ID_Generator (void);

  /// Destructor.
  ~GME_ID_Generator (void);

  /**
   * Initialize the id generator.
   *
   * @param[in]     proj      Project used to initial generator
   */
  void init (xercesc::DOMDocument * proj);

  /// Reset the ID generator.
  void reset (void);
};

/// Global id generator for all the types.
typedef ACE_Singleton <GME_ID_Generator, ACE_Null_Mutex> ID_GENERATOR;

// Forward decl.
class Folder;

// Forward decl.
class Model;

// Forward decl.
class Reference;

// Forward decl.
class Connection;

// Forward decl.
class Atom;

template < >
struct initial_id <Model>
{
  static const ::Utils::XStr result_type;
};

template < >
struct initial_id <Atom>
{
  static const ::Utils::XStr result_type;
};

template < >
struct initial_id <Reference>
{
  static const ::Utils::XStr result_type;
};

template < >
struct initial_id <Connection>
{
  static const ::Utils::XStr result_type;
};

template < >
struct initial_id <Folder>
{
  static const ::Utils::XStr result_type;
};

/// @todo add initial_id for Set

}
}

#if defined (__GAME_INLINE__)
#include "GME_ID_Generator.inl"
#endif

#endif  // !defined _GAME_GME_ID_GENERATOR_H_
