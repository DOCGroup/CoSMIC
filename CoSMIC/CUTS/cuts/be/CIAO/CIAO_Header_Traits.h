// -*- C++ -*-

//=============================================================================
/**
 * @file      Header_File_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_HEADER_TRAITS_H_
#define _CUTS_CIAO_HEADER_TRAITS_H_

#include "CIAO_Traits_Base.h"

//=============================================================================
/**
 * @class CUTS_CIAO_Header_Traits
 *
 * CIAO header file generator for the CUTS-PICML backend.
 */
//=============================================================================

class CUTS_CIAO_Header_Traits :
  public CIAO_Traits_Base
{
public:
  /// Type definition of the super class.
  typedef CIAO_Traits_Base _super;

  CUTS_CIAO_Header_Traits (void);

  virtual ~CUTS_CIAO_Header_Traits (void);

  virtual bool open_file (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_impl_begin (
    const PICML::MonolithicImplementation & monoimpl,
    const PICML::Component & component);

  virtual void write_InEventPort_begin (
    const PICML::InEventPort & sink);

  virtual void write_InEventPort_end (
    const PICML::InEventPort & sink);

  virtual void write_ProvidedRequestPort_begin (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_ProvidedRequestPort_end (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_PeriodicEvent_begin (
    const PICML::PeriodicEvent & periodic);

  virtual void write_PeriodicEvent_end (
    const PICML::PeriodicEvent & periodic);

  virtual void write_Attribute_begin (
    const PICML::Attribute & attr);

  virtual void write_Attribute_end (
    const PICML::Attribute & attr);

  virtual void write_ReadonlyAttribute_begin (
    const PICML::ReadonlyAttribute & attr);

  virtual void write_ReadonlyAttribute_end (
    const PICML::ReadonlyAttribute & attr);

  virtual void write_variables_begin (
    const PICML::Component & component);

  virtual void write_object_impl_begin (
    const PICML::Component & component,
    const PICML::ProvidedRequestPort & facet);

  virtual void write_object_impl_end (
    const PICML::Component & component,
    const PICML::ProvidedRequestPort & facet);

  virtual void write_TwowayOperation_begin (
    const PICML::TwowayOperation & twoway);

  virtual void write_TwowayOperation_end (
    const PICML::TwowayOperation & twoway);

  virtual void write_OnewayOperation_begin (
    const PICML::OnewayOperation & oneway);

  virtual void write_OnewayOperation_end (
    const PICML::OnewayOperation & oneway);

  virtual void write_factory_impl_begin (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

  virtual void write_FactoryOperation_begin (
    const PICML::FactoryOperation & factory_op);

  virtual void write_FactoryOperation_end (
    const PICML::FactoryOperation & factory_op);

  virtual void write_factory_impl_end (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

protected:
  virtual void write_set_session_context (
    const PICML::Component & component);

  virtual void write_ciao_preactivate (
    const PICML::Component & component);

  virtual void write_ccm_activate (
    const PICML::Component & component);

  virtual void write_ciao_postactivate (
    const PICML::Component & component);

  virtual void write_ccm_passivate (
    const PICML::Component & component);

  virtual void write_ccm_remove (
    const PICML::Component & component);

  virtual void write_method (
    const PICML::OutEventPort & source);

  virtual void write_method (
    const PICML::RequiredRequestPort & source);

  void write_forward_decl (const PICML::ProvidedRequestPort & facet);
};

#if defined (__CUTS_INLINE__)
#include "CIAO_Header_Traits.inl"
#endif

#endif  // !defined _CUTS_CIAO_HEADER_TRAITS_H_
