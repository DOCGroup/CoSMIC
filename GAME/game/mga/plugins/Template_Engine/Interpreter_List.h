// -*- C++ -*-

//=============================================================================
/**
 * @file        Model_Interpreter.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CUTE_INTERPRETER_LIST_H_
#define _CUTS_CUTE_INTERPRETER_LIST_H_

#include "ace/Hash_Map_Manager.h"
#include "ace/Null_Mutex.h"
#include "ace/SString.h"

typedef ACE_Hash_Map_Manager <std::string,
                              std::string,
                              ACE_Null_Mutex>
                              Interpreter_List;

#endif  // !defined _CUTS_CUTE_INTERPRETER_LIST_H_
