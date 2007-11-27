// -*- C++ -*-

//=============================================================================
/**
 * @file      CIAO_Proxy_Header_Traits.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_PROXY_HEADER_TRAITS_H_
#define _CUTS_CIAO_PROXY_HEADER_TRAITS_H_

#include "CIAO_Header_Traits.h"
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

//=============================================================================
/**
 * @class CUTS_CIAO_Header_Traits
 *
 * CIAO header file generator for the CUTS-PICML backend.
 */
//=============================================================================

class CUTS_CIAO_Proxy_Header_Traits :
  public CUTS_CIAO_Header_Traits
{
public:
  /// Type definition of the super class.
  typedef CUTS_CIAO_Header_Traits _super;

  CUTS_CIAO_Proxy_Header_Traits (void);

  virtual ~CUTS_CIAO_Proxy_Header_Traits (void);

  virtual bool open_file (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_prologue (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_epilogue (
    const PICML::ComponentImplementationContainer & container);

  // @@ begin component impl.
  void write_impl_begin (
    const PICML::MonolithicImplementation & monoimpl,
    const PICML::Component & type);

  void write_impl_end (
    const PICML::MonolithicImplementation &,
    const PICML::Component & type);

  virtual void write_variables_begin (
    const PICML::Component & component);

  virtual void write_ReadonlyAttribute_begin (
    const PICML::ReadonlyAttribute & attr);

  virtual void write_ReadonlyAttribute_end (
    const PICML::ReadonlyAttribute & attr);

  virtual void write_Attribute_begin (
    const PICML::Attribute & attr);

  virtual void write_Attribute_end (
    const PICML::Attribute & attr);

private:
  bool get_component_factory (
    const PICML::Component & component,
    PICML::ComponentFactory & factory);

  void write_eventsink_variable (
    const PICML::InEventPort & sink);

  virtual void write_id_variable (
    const PICML::OutEventPort & source);

  size_t endpoint_id_;
};

// Singleton definition.
#define CIAO_PROXY_HEADER_GENERATOR() \
  ACE_Singleton <CUTS_CIAO_Proxy_Header_Traits, \
                 ACE_Null_Mutex>::instance ()

#endif  // !defined _CUTS_CIAO_PROXY_HEADER_TRAITS_H_
