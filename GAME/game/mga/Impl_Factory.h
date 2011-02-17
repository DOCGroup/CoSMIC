// -*- C++ -*-

//=============================================================================
/**
 * @file          Impl_Factory.h
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_IMPL_FACTORY_H_
#define _GAME_MGA_IMPL_FACTORY_H_

#include <vector>
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

#include "game/config.h"
#include "Mga_export.h"

namespace GAME
{
namespace Mga
{
// Forward decl.
class Object_Impl;

namespace Meta
{
class Base_Impl;
}

/**
 * @class Impl_Factory
 *
 * The interface for all implementation factory objects. The implementation
 * factory is responsible for converting an raw COM pointer to its correct
 * implementation type.
 */
class Impl_Factory
{
public:
  /**
   * Allocate the implementation pointer for an object.
   *
   * @param[in]           ptr           Pointer to the object
   * @return              Pointer to the implementation.
   */
  virtual Object_Impl * allocate (IMgaObject * ptr) = 0;

  /// Type definition of a factory method.
  typedef Object_Impl * (*FACTORY_METHOD) (IMgaObject *);
};

// Forward decl.
class Attribute_Impl;
class Component_Impl;
class ConnectionPoint_Impl;
class RegistryNode_Impl;

/**
 * @class Default_Impl_Factory
 *
 * The default version of the implementation factory. This version
 * ensure that non-standard implementation objects are created correctly.
 * This object also allows clients to install domain-specific implementation
 * factories, which can override the behavior of this implementation
 * factory.
 */
class GAME_MGA_Export Default_Impl_Factory : public Impl_Factory
{
public:
  /// Default constructor.
  Default_Impl_Factory (void);

  /// Destructor.
  virtual ~Default_Impl_Factory (void);

  /**
   * Allocate the implementation pointer for an object.
   *
   * @param[in]           ptr           Pointer to the object
   * @return              Pointer to the implementation.
   */
  virtual Object_Impl * allocate (IMgaObject * ptr);

  RegistryNode_Impl * allocate (IMgaRegNode * ptr);

  Component_Impl * allocate (IMgaComponent * ptr);

  Attribute_Impl * allocate (IMgaAttribute * ptr);

  ConnectionPoint_Impl * allocate (IMgaConnPoint * ptr);

  /**
   * Allocate the meta implementation pointer for a meta object.
   *
   * @param[in]           ptr           Pointer to the meta object
   * @return              Pointer to the meta implementation.
   */
  virtual Meta::Base_Impl * allocate (IMgaMetaBase * ptr);

  /// Set the implementation factory.
  void impl_factory (Impl_Factory * impl);

private:
  /// Type definition of a meta factory method.
  typedef Meta::Base_Impl * (*META_FACTORY_METHOD) (IMgaMetaBase *);

  /// Collection of factory methods.
  std::vector <FACTORY_METHOD> factory_methods_;

  /// Collection of factory methods for meta objects.
  std::vector <META_FACTORY_METHOD> meta_factory_methods_;

  /// Pointer to the factory implementation.
  Impl_Factory * impl_;
};

/// Type definition of the global implementation factory. This version
/// of the global implementation factory is not thread safe.
typedef ACE_Singleton <Default_Impl_Factory,
                       ACE_Null_Mutex>
                       GLOBAL_IMPL_FACTORY;

}
}

#if defined (__GAME_INLINE__)
#include "Impl_Factory.inl"
#endif

#endif  // !defined _GAME_IMPL_FACTORY_H_
