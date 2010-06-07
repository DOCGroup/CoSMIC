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
#include "Utils/xercesc/XercesString.h"

/**
 * @class Scope
 */
class Scope
{
public:
  static void scope (const ::GAME::XME::FCO & fco,
                     const ::Utils::XStr & separator,
                     bool leading,
                     ::Utils::XStr & result);

  static void fq_name (const ::GAME::XME::FCO & fco,
                       const ::Utils::XStr & separator,
                       bool leading,
                       ::Utils::XStr & result);
};

#endif  // !defined _IDL_TO_PICML_SCOPE_H_
