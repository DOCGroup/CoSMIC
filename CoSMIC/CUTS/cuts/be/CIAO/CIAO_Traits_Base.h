// -*- C++ -*-

//=============================================================================
/**
 * @file      CIAO_Traits_Base.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_TRAITS_BASE_H_
#define _CUTS_CIAO_TRAITS_BASE_H_

#include "UDM_CIAO_Export.h"
#include "cuts/be/BE_File_Traits.h"

#include <fstream>
#include <memory>
#include <bitset>

namespace Indentation
{
  // Forward decl.
  template <typename T> class Cxx;

  // Forward decl.
  template <template <typename> class BufferType,
            typename C> class Implanter;
}

//=============================================================================
/**
 * @class CIAO_Traits_Base
 */
//=============================================================================

class CUTS_UDM_CIAO_Export CIAO_Traits_Base :
  public CUTS_BE_File_Traits
{
public:
  typedef CUTS_BE_File_Traits _super;

  CIAO_Traits_Base (void);

  virtual ~CIAO_Traits_Base (void);

  void close_file (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_impl_begin (
    const PICML::MonolithicImplementation & monoimpl,
    const PICML::Component & type);

  virtual void write_factory_end (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

  virtual void write_method_begin (
    const PICML::InEventPort & sink);

  virtual void write_method_begin (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_method_begin (
    const PICML::PeriodicEvent & periodic);

  virtual void write_method_begin (
    const PICML::ReadonlyAttribute & ro_attr);

  virtual void write_method_begin (
    const PICML::Attribute & attr);

  virtual void write_environment_begin (
    const PICML::Component & component);

  virtual void write_environment_end (
    const PICML::Component & component);

protected:
  void open_file_i (void);

  virtual void write_method (
    const PICML::OutEventPort & source);

  virtual void write_method (
    const PICML::RequiredRequestPort & source);

  std::string to_upper (const std::string & str);

  std::string include (const std::string & str);

  std::string single_line_comment (const std::string & str);

  std::string scope (const PICML::NamedType & type,
                     const std::string & separator);

  // CIAO-specific environment methods
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

  /// Indentation implanter.
  typedef Indentation::Implanter <Indentation::Cxx, char> Formatter_Type;

  /// Pointer to the formatter.
  std::auto_ptr <Formatter_Type> formatter_;

private:
  enum _env_bit
  {
    /// Flag for set_session_context.
    ENV_SET_SESSION_CONTEXT   = 0,

    /// Flag for ciao_preactivate.
    ENV_PREACTIVATE           = 1,

    /// Flag for ccm_activate.
    ENV_ACTIVATE              = 2,

    /// Flag for ciao_postactivate.
    ENV_POSTACTIVATE          = 3,

    /// Flag for ccm_passivate.
    ENV_PASSIVATE             = 4,

    /// Flag for ccm_remove.
    ENV_REMOVE                = 5
  };

  /// Flags that determine which environment methods have
  /// specified by the user.
  std::bitset <6> env_bits_;
};

#endif  // !defined _CUTS_CIAO_TRAITS_BASE_H_