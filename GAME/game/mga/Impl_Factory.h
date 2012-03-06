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
#include "Mga_export.h"

namespace GAME
{
namespace Mga
{
// Forward decl.
class Object_Impl;

// Forward decl.
class Attribute_Impl;

// Forward decl.
class Component_Impl;

// Forward decl.
class ComponentEx_Impl;

// Forward decl.
class ConnectionPoint_Impl;

// Forward decl.
class RegistryNode_Impl;

namespace Meta
{
// Forward decl.
class Base_Impl;

// Forward decl.
class Constraint_Impl;

// Forward decl.
class ConnectionPoint_Impl;
}

/**
 * @class Impl_Factory
 *
 * The interface for all implementation factory objects. The implementation
 * factory is responsible for converting an raw COM pointer to its correct
 * implementation type.
 */
class GAME_MGA_Export Impl_Factory
{
public:
  /// Type definition of a factory method.
  typedef Object_Impl * (*FACTORY_METHOD) (IMgaObject *);

  /// Default constructor.
  Impl_Factory (void);

  /// Destructor.
  virtual ~Impl_Factory (void);

  /**
   * Allocate the implementation pointer for an object.
   *
   * @param[in]           ptr           Pointer to the object
   * @return              Pointer to the implementation.
   */
  virtual Object_Impl * allocate (IMgaObject * ptr) = 0;

  /**
   * Allocate the implementation pointer for an object.
   *
   * @param[in]           ptr           Pointer to the object
   * @return              Pointer to the implementation.
   */
  virtual RegistryNode_Impl * allocate (IMgaRegNode * ptr) = 0;

  /// Allocate an component implementation.
  virtual Component_Impl * allocate (IMgaComponent * ptr) = 0;

  /// Allocate an extended component implementation.
  virtual ComponentEx_Impl * allocate (IMgaComponentEx * ptr) = 0;

  /// Allocate an attribute implementation.
  virtual Attribute_Impl * allocate (IMgaAttribute * ptr) = 0;

  /// Allocate a connection point implementation.
  virtual ConnectionPoint_Impl * allocate (IMgaConnPoint * ptr) = 0;

  /**
   * Allocate the meta implementation pointer for a meta object.
   *
   * @param[in]           ptr           Pointer to the meta object
   * @return              Pointer to the meta implementation.
   */
  virtual Meta::Base_Impl * allocate (IMgaMetaBase * ptr) = 0;

  /// Allocate a constraint implementation.
  virtual Meta::Constraint_Impl * allocate (IMgaConstraint * ptr) = 0;

  /// Allocate a meta connection point implementation.
  virtual Meta::ConnectionPoint_Impl * allocate (IMgaMetaConnJoint * ptr) = 0;

  /**
   * Add a new implementation factory to the chain of commnd. The
   * method updates the next pointer for this object as well as the
   * factory being inserted into the chain.
   *
   * @param[in]         n         Pointer to next factory
   */
  void set_next (Impl_Factory * n);

  /// Remove an implementation factory from the chain.
  void remove (Impl_Factory * n);

protected:
  /// Pointer to the factory implementation.
  Impl_Factory * next_;

private:
  // Prevent the following operations.
  Impl_Factory (const Impl_Factory &);
  const Impl_Factory & operator = (const Impl_Factory &);
};

/**
 * @class Impl_Factory_Base
 *
 * Base class for all implementation factories. This class provides
 * default behaivor for each required method (i.e., a no-op) that is
 * forward to the next factory in the chain of command.
 */
class GAME_MGA_Export Impl_Factory_Base : public Impl_Factory
{
public:
  /// Default constructor.
  Impl_Factory_Base (void);

  /// Destructor.
  virtual ~Impl_Factory_Base (void);

  /**
   * Allocate the implementation pointer for an object.
   *
   * @param[in]           ptr           Pointer to the object
   * @return              Pointer to the implementation.
   */
  virtual Object_Impl * allocate (IMgaObject * ptr);

  /**
   * Allocate the implementation pointer for an object.
   *
   * @param[in]           ptr           Pointer to the object
   * @return              Pointer to the implementation.
   */
  virtual RegistryNode_Impl * allocate (IMgaRegNode * ptr);

  /// Allocate an component implementation.
  virtual Component_Impl * allocate (IMgaComponent * ptr);

  /// Allocate an extended component implementation.
  virtual ComponentEx_Impl * allocate (IMgaComponentEx * ptr);

  /// Allocate an attribute implementation.
  virtual Attribute_Impl * allocate (IMgaAttribute * ptr);

  /// Allocate a connection point implementation.
  virtual ConnectionPoint_Impl * allocate (IMgaConnPoint * ptr);

  /**
   * Allocate the meta implementation pointer for a meta object.
   *
   * @param[in]           ptr           Pointer to the meta object
   * @return              Pointer to the meta implementation.
   */
  virtual Meta::Base_Impl * allocate (IMgaMetaBase * ptr);

  /// Allocate a constraint implementation.
  virtual Meta::Constraint_Impl * allocate (IMgaConstraint * ptr);

  /// Allocate a meta connection point implementation.
  virtual Meta::ConnectionPoint_Impl * allocate (IMgaMetaConnJoint * ptr);
};

/**
 * @class Default_Impl_Factory
 *
 * The default version of the implementation factory. This version
 * ensure that non-standard implementation objects are created correctly.
 * This object also allows clients to install domain-specific implementation
 * factories, which can override the behavior of this implementation
 * factory.
 */
class GAME_MGA_Export Default_Impl_Factory : public Impl_Factory_Base
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

  /// Allocate an registry node implementation.
  RegistryNode_Impl * allocate (IMgaRegNode * ptr);

  /// Allocate an component implementation.
  Component_Impl * allocate (IMgaComponent * ptr);

  /// Allocate an extended component implementation.
  ComponentEx_Impl * allocate (IMgaComponentEx * ptr);

  /// Allocate an attribute implementation.
  Attribute_Impl * allocate (IMgaAttribute * ptr);

  /// Allocate a connection point implementation.
  ConnectionPoint_Impl * allocate (IMgaConnPoint * ptr);

  /**
   * Allocate the meta implementation pointer for a meta object.
   *
   * @param[in]           ptr           Pointer to the meta object
   * @return              Pointer to the meta implementation.
   */
  virtual Meta::Base_Impl * allocate (IMgaMetaBase * ptr);

  /// Allocate a constraint implementation.
  Meta::Constraint_Impl * allocate (IMgaConstraint * ptr);

  /// Allocate a meta connection point implementation.
  Meta::ConnectionPoint_Impl * allocate (IMgaMetaConnJoint * ptr);

private:
  /// Type definition of a meta factory method.
  typedef Meta::Base_Impl * (*META_FACTORY_METHOD) (IMgaMetaBase *);

  /// Collection of factory methods.
  std::vector <FACTORY_METHOD> factory_methods_;

  /// Collection of factory methods for meta objects.
  std::vector <META_FACTORY_METHOD> meta_factory_methods_;
};

/**
 * @class Impl_Factory_Manager
 *
 * Manages the different implementation factories. It also initializes
 * the manager with the default implementation factory.
 */
class GAME_MGA_Export Impl_Factory_Manager : public Impl_Factory_Base
{
public:
  /// Default constructor.
  Impl_Factory_Manager (void);

  /// Destructor.
  virtual ~Impl_Factory_Manager (void);

private:
  /// Default implementation factory for the manager.
  Default_Impl_Factory default_impl_;
};

/// Type definition of the global implementation factory. This version
/// of the global implementation factory is not thread safe.
typedef ACE_Singleton <Impl_Factory_Manager, ACE_Null_Mutex> GLOBAL_IMPL_FACTORY;

GAME_MGA_SINGLETON_DECLARE (ACE_Singleton, Impl_Factory_Manager, ACE_Null_Mutex);

}
}

#if defined (__GAME_INLINE__)
#include "Impl_Factory.inl"
#endif

#endif  // !defined _GAME_IMPL_FACTORY_H_
