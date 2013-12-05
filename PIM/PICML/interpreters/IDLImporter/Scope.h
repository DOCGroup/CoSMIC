// -*- C++ -*-

//=============================================================================
/**
 * @file      File_Creator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _IDL_TO_PICML_SCOPE_H_
#define _IDL_TO_PICML_SCOPE_H_

#include "game/xme/FCO.h"

/**
 * @class Scope
 */
class Scope
{
public:
  static void scope (const ::GAME::XME::FCO & fco,
                     const GAME::Xml::String & separator,
                     bool leading,
                     GAME::Xml::String & result);

  static void fq_name (const ::GAME::XME::FCO & fco,
                       const GAME::Xml::String & separator,
                       bool leading,
                       GAME::Xml::String & result);
};

#endif  // !defined _IDL_TO_PICML_SCOPE_H_
