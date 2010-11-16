// -*- C++ -*-

//=============================================================================
/**
 * @file      int.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_OBJECT_TYPE_H_
#define _GAME_XME_OBJECT_TYPE_H_

#include "XME_export.h"

namespace GAME
{
namespace XME
{
/**
 * @class int
 *
 * Wrapper class for the different object types supported in
 * GME.
 */
class GAME_XME_Export Object_Type
{
public:
  static const int OT_UNKNOWN     = 0x00;   /* 00000000 */
  static const int OT_OBJECT      = 0x01;   /* 00000001 */
  static const int OT_FOLDER      = 0x03;   /* 00000011 */
  static const int OT_FCO         = 0x04;   /* 00000101 */
  static const int OT_ATOM        = 0x0D;   /* 00001101 */
  static const int OT_MODEL       = 0x15;   /* 00010101 */
  static const int OT_REFERENCE   = 0x25;   /* 00100101 */
  static const int OT_CONNECTION  = 0x45;   /* 01000101 */
  static const int OT_SET         = 0x85;   /* 10000101 */
};

}
}


#endif  // !defined _GAME_XME_OBJECT_TYPE_H_
