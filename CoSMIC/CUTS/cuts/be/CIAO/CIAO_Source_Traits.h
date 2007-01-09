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

class CUTS_UDM_CIAO_Export CUTS_CIAO_Source_Traits :
  public CIAO_Traits_Base
{
public:
  typedef CIAO_Traits_Base _super;

  CUTS_CIAO_Source_Traits (void);

  virtual ~CUTS_CIAO_Source_Traits (void);

  virtual void write_method_begin (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_method_end (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_method_begin (
    const PICML::InEventPort & sink);

  virtual void write_method_end (
    const PICML::InEventPort & sink);

  virtual void write_method_begin (
    const PICML::PeriodicEvent & periodic);

  virtual void write_method_end (
    const PICML::PeriodicEvent & periodic);

  virtual void write_method_begin (
    const PICML::Attribute & attr);

  virtual void write_method_end (
    const PICML::Attribute & attr);

  virtual void write_method_begin (
    const PICML::ReadonlyAttribute & readonly);

  virtual void write_method_end (
    const PICML::ReadonlyAttribute & readonly);

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
};

#endif  // !defined _CUTS_CIAO_SOURCE_TRAITS_H_
