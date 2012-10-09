// -*- C++ -*-

//==============================================================================
/**
 *  @file        Object_Manager.h
 *
 *  $Id: generate_cpp_class.py 3679 2012-04-30 02:25:20Z hillj $
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_EXTENSION_CLASSES_OBJECT_MANAGER_H_
#define _GAME_EXTENSION_CLASSES_OBJECT_MANAGER_H_

#include "ace/Singleton.h"
#include "ace/RW_Thread_Mutex.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include "game/mga/Atom.h"

// Forward decl.
class Object_Class_Definition;

/**
 * @class Object_Manager
 *
 * INSERT CLASS DESCRIPTION HERE
 */
class Object_Manager
{
public:
  typedef
    ACE_Hash_Map_Manager <std::string,
                          Object_Class_Definition *,
                          ACE_RW_Thread_Mutex> map_type;

  /// Default constructor.
  Object_Manager (void);

  /// Destructor.
  ~Object_Manager (void);

  /// Get the collection of known objects.
  const map_type & objects (void) const;

  /**
   * Get the object class definition associated with the specified
   * atom element.
   */
  Object_Class_Definition * get (GAME::Mga::Atom_in atom);

  /// Build the specified atom.
  void build (GAME::Mga::Atom_in atom);
  void build (GAME::Mga::Atom_in atom, Object_Class_Definition * & def);

private:
  /// Collection of known objects.
  map_type objects_;
};

#define OBJECT_MANAGER_SINGLETON \
  ACE_Singleton <Object_Manager, ACE_Null_Mutex>

#define OBJECT_MANAGER \
  OBJECT_MANAGER_SINGLETON::instance ()

#if defined (__GAME_INLINE__)
#include "Object_Manager.inl"
#endif

#endif  // _OBJECT_MANAGER_H_
