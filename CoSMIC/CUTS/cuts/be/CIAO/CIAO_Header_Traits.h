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

class CUTS_UDM_CIAO_Export CUTS_CIAO_Header_Traits :
  public CIAO_Traits_Base
{
public:
  /// Type definition of the super class.
  typedef CIAO_Traits_Base _super;

  CUTS_CIAO_Header_Traits (void);

  virtual ~CUTS_CIAO_Header_Traits (void);

  virtual void write_environment_begin (
    const PICML::Component & component);

  virtual void write_method_begin (
    const PICML::InEventPort & sink);

  virtual void write_method_end (
    const PICML::InEventPort & sink);

  virtual void write_method_begin (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_method_end (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_method_begin (
    const PICML::PeriodicEvent & periodic);

  virtual void write_method_end (
    const PICML::PeriodicEvent & periodic);

  virtual void write_method_begin (
    const PICML::Attribute & attr);

  virtual void write_method_end (
    const PICML::Attribute & attr);

  virtual void write_method_begin (
    const PICML::ReadonlyAttribute & attr);

  virtual void write_method_end (
    const PICML::ReadonlyAttribute & attr);

  virtual void write_variables_begin (
    const PICML::Component & component);

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
};

#if defined (__CUTS_INLINE__)
#include "CIAO_Header_Traits.inl"
#endif

#endif  // !defined _CUTS_CIAO_HEADER_TRAITS_H_
