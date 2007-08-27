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

#ifndef _CUTS_CIAO_SOURCE_TRAITS_H_
#define _CUTS_CIAO_SOURCE_TRAITS_H_

#include "CIAO_Traits_Base.h"
#include "Port_Manager_T.h"

//=============================================================================
/**
 * @class CUTS_CIAO_Source_Traits
 */
//=============================================================================

class CUTS_CIAO_Source_Traits :
  public CIAO_Traits_Base
{
public:
  typedef CIAO_Traits_Base _super;

  CUTS_CIAO_Source_Traits (void);

  virtual ~CUTS_CIAO_Source_Traits (void);

  virtual bool open_file (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_ProvidedRequestPort_begin (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_ProvidedRequestPort_end (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_InEventPort_begin (
    const PICML::InEventPort & sink);

  virtual void write_InEventPort_end (
    const PICML::InEventPort & sink);

  virtual void write_PeriodicEvent_begin (
    const PICML::PeriodicEvent & periodic);

  virtual void write_Attribute_begin (
    const PICML::Attribute & attr);

  virtual void write_Attribute_end (
    const PICML::Attribute & attr);

  virtual void write_ReadonlyAttribute_begin (
    const PICML::ReadonlyAttribute & readonly);

  virtual void write_ReadonlyAttribute_end (
    const PICML::ReadonlyAttribute & readonly);

  virtual void write_TwowayOperation_begin (
    const PICML::TwowayOperation & twoway);

  virtual void write_TwowayOperation_end (
    const PICML::TwowayOperation & twoway);

  virtual void write_OnewayOperation_begin (
    const PICML::OnewayOperation & oneway);

  virtual void write_OnewayOperation_end (
    const PICML::OnewayOperation & oneway);

  virtual void write_FactoryOperation_begin (
    const PICML::FactoryOperation & factory_op);

  virtual void write_FactoryOperation_end (
    const PICML::FactoryOperation & factory_op);

  virtual void write_object_impl_begin (
    const PICML::Component & component,
    const PICML::ProvidedRequestPort & facet);

  virtual void write_object_impl_end (
    const PICML::Component & component,
    const PICML::ProvidedRequestPort & facet);

  virtual void write_factory_impl_begin (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

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

  /**
   * Helper method that transforms a string into a function header,
   * i.e., decorates it accordingly. The behavior of this method
   * allows it to be used with stream insertion operations.
   *
   * @param[in]     func        Name of the function.
   * @return        The function header for \func.
   */
  std::string function_header (const std::string & func);

  /// The name of the current object's implementation.
  std::string object_impl_;
};

#endif  // !defined _CUTS_CIAO_SOURCE_TRAITS_H_
