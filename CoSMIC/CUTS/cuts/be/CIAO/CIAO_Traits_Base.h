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

// Forward decl.
struct CUTS_BE_Impl_Node;

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

class CIAO_Traits_Base : public CUTS_BE_File_Traits
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

  virtual void write_factory_impl_end (
    const PICML::ComponentFactory & factory,
    const PICML::MonolithicImplementation & impl,
    const PICML::Component & type);

  virtual void write_InEventPort_begin (
    const PICML::InEventPort & sink);

  virtual void write_ProvidedRequestPort_begin (
    const PICML::ProvidedRequestPort & facet);

  virtual void write_PeriodicEvent_begin (
    const PICML::PeriodicEvent & periodic);

  virtual void write_ReadonlyAttribute_begin (
    const PICML::ReadonlyAttribute & ro_attr);

  virtual void write_Attribute_begin (
    const PICML::Attribute & attr);

  virtual void write_environment_begin (
    const PICML::Component & component);

  virtual void write_environment_end (
    const PICML::Component & component);

  virtual void write_TwowayOperation_begin (
    const PICML::TwowayOperation & twoway);

  virtual void write_OnewayOperation_begin (
    const PICML::OnewayOperation & oneway);

  virtual void write_FactoryOperation_begin (
    const PICML::FactoryOperation & factory_op);

  virtual void write_FactoryOperation_end (
    const PICML::FactoryOperation & factory_op);

  void write_include (const std::string & include);

protected:
  void write_OperationBase_begin (
    const PICML::OperationBase & operation_base);

  void open_file_i (void);

  void get_impl_entry_point (
    const PICML::ComponentImplementationContainer & container);

  virtual void write_method (
    const PICML::OutEventPort & source);

  virtual void write_method (
    const PICML::RequiredRequestPort & source);

  void write_exception_spec (const PICML::ExceptionRef & ref);

  void write_parameter (const PICML::ParameterType & param);
  void write_parameter_first (const PICML::ParameterType & param);

  void write_in_parameter (const PICML::InParameter & in);
  void write_in_parameter_first (const PICML::InParameter & in);

  void write_out_parameter (const PICML::OutParameter & out);
  void write_out_parameter_first (const PICML::OutParameter & out);

  void write_inout_parameter (const PICML::InoutParameter & inout);
  void write_inout_parameter_first (const PICML::InoutParameter & inout);

  std::string to_upper (const std::string & str);

  std::string include (const std::string & str);

  std::string single_line_comment (const std::string & str);

  std::string scope (const PICML::MgaObject & type,
                     const std::string & separator,
                     bool leading = false);

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

  /// Entry point for the implementation.
  std::string entry_point_;

  /// The current implementation node.
  const CUTS_BE_Impl_Node * node_;

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
