// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Factory.h
 *
 * Defines factory object required by all backends
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_FACTORY_H_
#define _CUTS_BE_FACTORY_H_

#include "BE_export.h"
#include "BE.h"

// Forward decl.
class CUTS_BE_Manager;

//=============================================================================
/**
 * @class CUTS_BE_Manager_Factory
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_Manager_Factory
{
public:
  /**
   * Factory method that creates a backend manager.
   *
   * @return      Pointer to a backend manager.
   */
  virtual CUTS_BE_Manager * create_manager (void) = 0;

  /// Close the factory.
  virtual void close (void);

  virtual const char * name (void) const;
  virtual const char * description (void) const;

protected:
  /// Default constructor.
  CUTS_BE_Manager_Factory (void);

  /// Destructor.
  virtual ~CUTS_BE_Manager_Factory (void);

private:
  CUTS_BE_Manager_Factory (const CUTS_BE_Manager_Factory &);
  const CUTS_BE_Manager_Factory & operator = (const CUTS_BE_Manager_Factory &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

#define CUTS_BE_MANAGER_FACTORY_DECLARE(export_macro, factory_type) \
  class factory_type : public CUTS_BE_Manager_Factory \
  { \
  public: \
    factory_type (void); \
    ~factory_type (void); \
    CUTS_BE_Manager * create_manager (void); \
  }; \
  CUTS_BE_CREATE_MANAGER_FACTORY_DECLARE (export_macro)

//=============================================================================
/**
 *
 */
//=============================================================================

#define CUTS_BE_MANAGER_FACTORY_IMPLEMENT(factory_type, manager_type) \
  factory_type::factory_type (void) { } \
  factory_type::~factory_type (void) { } \
  CUTS_BE_Manager * factory_type::create_manager (void) \
  { \
    return new manager_type (); \
  } \
  CUTS_BE_CREATE_MANAGER_FACTORY_IMPLEMENT (CUTS_BE_CIAO_Manager_Factory)

#if defined (__CUTS_INLINE__)
#include "BE_Manager_Factory.inl"
#endif

#endif  // !defined _CUTS_BE_FACTORY_H_
