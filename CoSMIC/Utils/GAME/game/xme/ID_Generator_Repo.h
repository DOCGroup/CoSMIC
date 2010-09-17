// -*- C++ -*-

//=============================================================================
/**
 * @file        ID_Generator_Repo.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_ID_GENERATOR_REPO_H_
#define _GAME_XME_ID_GENERATOR_REPO_H_

#include "xercesc/dom/DOMDocument.hpp"
#include "xercesc/dom/DOMElement.hpp"

#include "ace/Hash_Map_Manager.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/Singleton.h"
#include "ace/Thread_Mutex.h"
#include "game/config.h"

/**
 * @struct ACE_Hash <xercesc::DOMDocument *>
 *
 * Specialization of the ACE_Hash for xercesc::DOMDocument *.
 */
template < >
struct ACE_Hash <xercesc::DOMDocument *>
{
  unsigned long operator () (xercesc::DOMDocument * ptr) const;
};


namespace GAME
{
namespace XME
{
// Forward decl.
class GME_ID_Generator;

/**
 * @class ID_Generator_Repo
 *
 * Collection of id generators. The id generators are stored
 * by their project.
 */
class ID_Generator_Repo
{
public:
  /// Default constructor.
  ID_Generator_Repo (void);

  /// Destructor.
  ~ID_Generator_Repo (void);

  int open (xercesc::DOMDocument * proj);

  void close (xercesc::DOMDocument * proj);

  GME_ID_Generator * get (xercesc::DOMElement * proj);
  GME_ID_Generator * get (xercesc::DOMDocument * proj);

private:
  /// Collection of id generators.
  ACE_Hash_Map_Manager <xercesc::DOMDocument *,
                        GME_ID_Generator *,
                        ACE_RW_Thread_Mutex> idgens_;
};

typedef ACE_Singleton <ID_Generator_Repo,
                       ACE_Thread_Mutex> ID_Generator_Repo_Singleton;

#define GAME_XME_ID_GENERATOR_REPO \
  ID_Generator_Repo_Singleton::instance ()

}
}

#if defined (__GAME_INLINE__)
#include "ID_Generator_Repo.inl"
#endif

#endif  // !defined _GAME_XME_ID_GENERATOR_REPO_H_
