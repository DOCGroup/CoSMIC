// -*- C++ -*-

//=============================================================================
/**
 * @file      CIAO_Traits.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_CIAO_TRAITS_H_
#define _CUTS_BE_CIAO_TRAITS_H_

#include "CIAO_Exec_Header_Traits.h"
#include "CIAO_Exec_Source_Traits.h"
#include "CIAO_Proxy_Header_Traits.h"
#include "CIAO_Proxy_Source_Traits.h"

namespace CUTS_BE
{
  //=============================================================================
  /**
   * @class CIAO_Traits
   *
   * CIAO specific traits. This trait file is used to parametermize
   * the backend implementation generator of CUTS.
   */
  //=============================================================================

  class CIAO_Traits
  {
  public:
    // POG: Open_File
    struct CUTS_UDM_CIAO_Export Open_File
    {
      static inline bool generate (
        const PICML::ComponentImplementationContainer & container)
      {
        return
          CIAO_EXEC_HEADER_GENERATOR ()->open_file (container) |
          CIAO_EXEC_SOURCE_GENERATOR ()->open_file (container) |
          CIAO_PROXY_HEADER_GENERATOR ()->open_file (container) |
          CIAO_PROXY_SOURCE_GENERATOR ()->open_file (container);
      }
    };

    // POG: Close_File
    struct CUTS_UDM_CIAO_Export Close_File
    {
      static inline bool generate (
        const PICML::ComponentImplementationContainer & container)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->close_file (container);
        CIAO_EXEC_SOURCE_GENERATOR ()->close_file (container);

        CIAO_PROXY_HEADER_GENERATOR ()->close_file (container);
        CIAO_PROXY_SOURCE_GENERATOR ()->close_file (container);
        return true;
      }
    };

    // POG: Prologue
    struct CUTS_UDM_CIAO_Export Prologue
    {
      static inline bool generate (
        const PICML::ComponentImplementationContainer & container)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_prologue (container);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_prologue (container);

        CIAO_PROXY_HEADER_GENERATOR ()->write_prologue (container);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_prologue (container);
        return true;
      }
    };

    // POG: Epilogue
    struct CUTS_UDM_CIAO_Export Epilogue
    {
      static inline bool generate (
        const PICML::ComponentImplementationContainer & container)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_epilogue (container);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_epilogue (container);

        CIAO_PROXY_HEADER_GENERATOR ()->write_epilogue (container);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_epilogue (container);
        return true;
      }
    };

    // POG: Component_Impl_Begin
    struct CUTS_UDM_CIAO_Export Component_Impl_Begin
    {
      static inline bool generate (
        const PICML::MonolithicImplementation & monoimpl,
        const PICML::Component & component)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_impl_begin (monoimpl, component);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_impl_begin (monoimpl, component);

        CIAO_PROXY_HEADER_GENERATOR ()->write_impl_begin (monoimpl, component);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_impl_begin (monoimpl, component);
        return true;
      }
    };

    // POG: Component_Impl_End
    struct CUTS_UDM_CIAO_Export Component_Impl_End
    {
      static inline bool generate (
        const PICML::MonolithicImplementation & monoimpl,
        const PICML::Component & component)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_impl_end (monoimpl, component);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_impl_end (monoimpl, component);

        CIAO_PROXY_HEADER_GENERATOR ()->write_impl_end (monoimpl, component);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_impl_end (monoimpl, component);
        return true;
      }
    };

    // POG: Factory_Impl_Begin
    struct CUTS_UDM_CIAO_Export Factory_Impl_Begin
    {
      static inline bool generate (
        const PICML::ComponentFactory & factory,
        const PICML::MonolithicImplementation & monoimpl,
        const PICML::Component & component)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->
          write_factory_impl_begin (factory, monoimpl, component);
        CIAO_EXEC_SOURCE_GENERATOR ()->
          write_factory_impl_begin (factory, monoimpl, component);

        CIAO_PROXY_HEADER_GENERATOR ()->
          write_factory_impl_begin (factory, monoimpl, component);
        CIAO_PROXY_SOURCE_GENERATOR ()->
          write_factory_impl_begin (factory, monoimpl, component);
        return true;
      }
    };

    // POG: Factory_Impl_End
    struct CUTS_UDM_CIAO_Export Factory_Impl_End
    {
      static inline bool generate (
        const PICML::ComponentFactory & factory,
        const PICML::MonolithicImplementation & monoimpl,
        const PICML::Component & component)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->
          write_factory_impl_end (factory, monoimpl, component);
        CIAO_EXEC_SOURCE_GENERATOR ()->
          write_factory_impl_end (factory, monoimpl, component);

        CIAO_PROXY_HEADER_GENERATOR ()->
          write_factory_impl_end (factory, monoimpl, component);
        CIAO_PROXY_SOURCE_GENERATOR ()->
          write_factory_impl_end (factory, monoimpl, component);
        return true;
      }
    };

    // POG: Environment_Begin
    struct CUTS_UDM_CIAO_Export Environment_Begin
    {
      static inline bool generate (const PICML::Component & component)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_environment_begin (component);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_environment_begin (component);

        CIAO_PROXY_HEADER_GENERATOR ()->write_environment_begin (component);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_environment_begin (component);
        return true;
      }
    };

    // POG: Environment_Method_Begin
    struct CUTS_UDM_CIAO_Export Environment_Method_Begin
    {
      static inline bool generate (const PICML::InputAction & action)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_environment_method_begin (action);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_environment_method_begin (action);
        return true;
      }
    };

    // POG: Environment_Method_End
    struct CUTS_UDM_CIAO_Export Environment_Method_End
    {
      static inline bool generate (const PICML::InputAction & action)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_environment_method_end (action);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_environment_method_end (action);
        return true;
      }
    };

    // POG: Environment_End
    struct CUTS_UDM_CIAO_Export Environment_End
    {
      static inline bool generate (const PICML::Component & component)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_environment_end (component);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_environment_end (component);
        return true;
      }
    };

    // POG: Variables_Begin
    struct CUTS_UDM_CIAO_Export Variables_Begin
    {
      static inline bool generate (const PICML::Component & component)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_variables_begin (component);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_variables_begin (component);

        CIAO_PROXY_HEADER_GENERATOR ()->write_variables_begin (component);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_variables_begin (component);
        return true;
      }
    };

    // POG: Variable
    struct CUTS_UDM_CIAO_Export Variable
    {
      static inline bool generate (
        const PICML::Variable & variable)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_variable  (variable);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_variable  (variable);
        return true;
      }
    };

    // POG: Worker_Variable
    struct CUTS_UDM_CIAO_Export Worker_Variable
    {
      static inline bool generate (
        const PICML::WorkerType & type,
        const PICML::Worker & worker)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_worker_variable (type, worker);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_worker_variable (type, worker);
        return true;
      }
    };

    // POG: PeriodicEvent_Variable
    struct CUTS_UDM_CIAO_Export PeriodicEvent_Variable
    {
      static inline bool generate (
        const PICML::PeriodicEvent & periodic)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_PeriodicEvent_variable (periodic);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_PeriodicEvent_variable (periodic);
        return true;
      }
    };

    // POG: Attribute_Variable
    struct CUTS_UDM_CIAO_Export Attribute_Variable
    {
      static inline bool generate (
        const PICML::ReadonlyAttribute & attr)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_ReadonlyAttribute_variable (attr);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_ReadonlyAttribute_variable (attr);
        return true;
      }
    };

    // POG: Variables_End
    struct CUTS_UDM_CIAO_Export Variables_End
    {
      static inline bool generate (const PICML::Component & component)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_variables_end ();
        CIAO_EXEC_SOURCE_GENERATOR ()->write_variables_end ();
        return true;
      }
    };

    // POG: InEventPort_Begin
    struct CUTS_UDM_CIAO_Export InEventPort_Begin
    {
      static inline bool generate (
        const PICML::InEventPort & port)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_InEventPort_begin (port);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_InEventPort_begin (port);

        CIAO_PROXY_HEADER_GENERATOR ()->write_InEventPort_begin (port);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_InEventPort_begin (port);
        return true;
      }
    };

    // POG: InEventPort_End
    struct CUTS_UDM_CIAO_Export InEventPort_End
    {
      static inline bool generate (
        const PICML::InEventPort & port)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_InEventPort_end  (port);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_InEventPort_end  (port);

        CIAO_PROXY_HEADER_GENERATOR ()->write_InEventPort_end  (port);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_InEventPort_end  (port);
        return true;
      }
    };

    // POG: ProvidedRequestPort_Begin
    struct CUTS_UDM_CIAO_Export ProvidedRequestPort_Begin
    {
      static inline bool generate (
        const PICML::ProvidedRequestPort & port)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_ProvidedRequestPort_begin (port);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_ProvidedRequestPort_begin (port);

        CIAO_PROXY_HEADER_GENERATOR ()->write_ProvidedRequestPort_begin (port);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_ProvidedRequestPort_begin (port);
        return true;
      }
    };

    // POG: ProvidedRequestPort_End
    struct CUTS_UDM_CIAO_Export ProvidedRequestPort_End
    {
      static inline bool generate (
        const PICML::ProvidedRequestPort & port)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_ProvidedRequestPort_end  (port);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_ProvidedRequestPort_end  (port);

        CIAO_PROXY_HEADER_GENERATOR ()->write_ProvidedRequestPort_end  (port);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_ProvidedRequestPort_end  (port);
        return true;
      }
    };

    // POG: PeriodicEvent_Begin
    struct CUTS_UDM_CIAO_Export PeriodicEvent_Begin
    {
      static inline bool generate (
        const PICML::PeriodicEvent & periodic)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_PeriodicEvent_begin (periodic);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_PeriodicEvent_begin (periodic);
        return true;
      }
    };

    // POG: PeriodicEvent_End
    struct CUTS_UDM_CIAO_Export PeriodicEvent_End
    {
      static inline bool generate (
        const PICML::PeriodicEvent & periodic)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_PeriodicEvent_end  (periodic);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_PeriodicEvent_end  (periodic);
        return true;
      }
    };

    // POG: ReadonlyAttribute_Begin
    struct CUTS_UDM_CIAO_Export ReadonlyAttribute_Begin
    {
      static inline bool generate (
        const PICML::ReadonlyAttribute & attr)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_ReadonlyAttribute_begin (attr);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_ReadonlyAttribute_begin (attr);

        CIAO_PROXY_HEADER_GENERATOR ()->write_ReadonlyAttribute_begin (attr);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_ReadonlyAttribute_begin (attr);
        return true;
      }
    };

    // POG: ReadonlyAttribute_End
    struct CUTS_UDM_CIAO_Export ReadonlyAttribute_End
    {
      static inline bool generate (
        const PICML::ReadonlyAttribute & attr)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_ReadonlyAttribute_end  (attr);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_ReadonlyAttribute_end  (attr);

        CIAO_PROXY_HEADER_GENERATOR ()->write_ReadonlyAttribute_end  (attr);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_ReadonlyAttribute_end  (attr);
        return true;
      }
    };

    // POG: Attribute_Begin
    struct CUTS_UDM_CIAO_Export Attribute_Begin
    {
      static inline bool generate (
        const PICML::Attribute & attr)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_Attribute_begin (attr);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_Attribute_begin (attr);

        CIAO_PROXY_HEADER_GENERATOR ()->write_Attribute_begin (attr);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_Attribute_begin (attr);
        return true;
      }
    };

    // POG: Attribute_End
    struct CUTS_UDM_CIAO_Export Attribute_End
    {
      static inline bool generate (
        const PICML::Attribute & attr)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_Attribute_end  (attr);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_Attribute_end  (attr);

        CIAO_PROXY_HEADER_GENERATOR ()->write_Attribute_end  (attr);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_Attribute_end  (attr);
        return true;
      }
    };

    // POG: OnewayOperation_Begin
    struct CUTS_UDM_CIAO_Export OnewayOperation_Begin
    {
      static inline bool generate (
        const PICML::OnewayOperation & oneway)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_OnewayOperation_begin (oneway);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_OnewayOperation_begin (oneway);

        CIAO_PROXY_HEADER_GENERATOR ()->write_OnewayOperation_begin (oneway);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_OnewayOperation_begin (oneway);
        return true;
      }
    };

    // POG: OnewayOperatoin_End
    struct CUTS_UDM_CIAO_Export OnewayOperation_End
    {
      static inline bool generate (
        const PICML::OnewayOperation & oneway)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_OnewayOperation_end  (oneway);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_OnewayOperation_end  (oneway);

        CIAO_PROXY_HEADER_GENERATOR ()->write_OnewayOperation_end  (oneway);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_OnewayOperation_end  (oneway);
        return true;
      }
    };

    // POG: TwowayOperation_Begin
    struct CUTS_UDM_CIAO_Export TwowayOperation_Begin
    {
      static inline bool generate (
        const PICML::TwowayOperation & twoway)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_TwowayOperation_begin (twoway);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_TwowayOperation_begin (twoway);

        CIAO_PROXY_HEADER_GENERATOR ()->write_TwowayOperation_begin (twoway);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_TwowayOperation_begin (twoway);
        return true;
      }
    };

    // POG: TwowayOperatoin_End
    struct CUTS_UDM_CIAO_Export TwowayOperation_End
    {
      static inline bool generate (
        const PICML::TwowayOperation & twoway)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_TwowayOperation_end  (twoway);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_TwowayOperation_end  (twoway);

        CIAO_PROXY_HEADER_GENERATOR ()->write_TwowayOperation_end  (twoway);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_TwowayOperation_end  (twoway);
        return true;
      }
    };

    // POG: FactoryOperation_Begin
    struct CUTS_UDM_CIAO_Export FactoryOperation_Begin
    {
      static inline bool generate (
        const PICML::FactoryOperation & factory_op)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_FactoryOperation_begin (factory_op);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_FactoryOperation_begin (factory_op);

        CIAO_PROXY_HEADER_GENERATOR ()->write_FactoryOperation_begin (factory_op);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_FactoryOperation_begin (factory_op);
        return true;
      }
    };

    // POG: FactoryOperation_End
    struct CUTS_UDM_CIAO_Export FactoryOperation_End
    {
      static inline bool generate (
        const PICML::FactoryOperation & factory_op)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_FactoryOperation_end (factory_op);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_FactoryOperation_end (factory_op);

        CIAO_PROXY_HEADER_GENERATOR ()->write_FactoryOperation_end (factory_op);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_FactoryOperation_end (factory_op);
        return true;
      }
    };

    // POG: FactoryOperation_Begin
    struct CUTS_UDM_CIAO_Export Object_Impl_Begin
    {
      static inline bool generate (
        const PICML::Component & component,
        const PICML::ProvidedRequestPort & facet)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_object_impl_begin (component, facet);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_object_impl_begin (component, facet);

        CIAO_PROXY_HEADER_GENERATOR ()->write_object_impl_begin (component, facet);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_object_impl_begin (component, facet);
        return true;
      }
    };

    // POG: FactoryOperation_End
    struct CUTS_UDM_CIAO_Export Object_Impl_End
    {
      static inline bool generate (
        const PICML::Component & component,
        const PICML::ProvidedRequestPort & facet)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_object_impl_end (component, facet);
        CIAO_EXEC_SOURCE_GENERATOR ()->write_object_impl_end (component, facet);

        CIAO_PROXY_HEADER_GENERATOR ()->write_object_impl_end (component, facet);
        CIAO_PROXY_SOURCE_GENERATOR ()->write_object_impl_end (component, facet);
        return true;
      }
    };

    // POG: FactoryOperation_End
    struct CUTS_UDM_CIAO_Export Include
    {
      static inline bool generate (const std::string & include)
      {
        CIAO_EXEC_HEADER_GENERATOR ()->write_include (include);
        return true;
      }
    };

    // POG: Precondition
    struct CUTS_UDM_CIAO_Export Precondition
    {
      static inline bool generate (const std::string & precondition)
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->write_precondition (precondition);
        return true;
      }
    };

    // POG: Branches_Begin
    struct CUTS_UDM_CIAO_Export Branches_Begin
    {
      static inline bool generate (size_t branches)
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->write_branches_begin (branches);
        return true;
      }
    };

    // POG: Branch_Precondition
    struct CUTS_UDM_CIAO_Export Branch_Begin
    {
      static inline bool generate (const std::string & precondition)
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->write_branch_begin (precondition);
        return true;
      }
    };

    // POG: Branch_Precondition
    struct CUTS_UDM_CIAO_Export Branch_End
    {
      static inline bool generate ()
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->write_branch_end ();
        return true;
      }
    };

    // POG: Branches_Begin
    struct CUTS_UDM_CIAO_Export Branches_End
    {
      static inline bool generate (void)
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->write_branches_end ();
        return true;
      }
    };

    // POG: Postcondition
    struct CUTS_UDM_CIAO_Export Postcondition
    {
      static inline bool generate (const std::string & postcondition)
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->write_postcondition (postcondition);
        return true;
      }
    };

    // POG: Action_Property
    struct CUTS_UDM_CIAO_Export Action_Property
    {
      static inline bool generate (const PICML::Property & property)
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->write_action_property (property);
        return true;
      }
    };

    // POG: WorkerAction_Begin
    struct CUTS_UDM_CIAO_Export WorkerAction_Begin
    {
      static inline bool
        generate (const PICML::Worker & worker, const PICML::Action & action)
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->
          write_WorkerAction_begin (worker, action);
        return true;
      }
    };

    // POG: OutputAction_Begin
    struct CUTS_UDM_CIAO_Export OutputAction_Begin
    {
      static inline bool generate (const PICML::OutputAction & action)
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->write_OutputAction_begin (action);
        return true;
      }
    };

    // POG: OuputAction_Property
    struct CUTS_UDM_CIAO_Export OutputAction_Property
    {
      static inline bool generate (
        const PICML::OutputAction & action,
        const PICML::Property & property)
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->
          write_OuputAction_Property (action, property);
        return true;
      }
    };

    // POG: OuputAction_End
    struct CUTS_UDM_CIAO_Export OutputAction_End
    {
      static inline bool generate (const PICML::OutputAction & action)
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->write_OutputAction_end (action);
        return true;
      }
    };

    // POG: Action_Property
    struct CUTS_UDM_CIAO_Export Action_End
    {
      static inline bool generate (void)
      {
        CIAO_EXEC_SOURCE_GENERATOR ()->write_action_end ();
        return true;
      }
    };
  };
}

#endif  // !defined _CUTS_BE_CIAO_TRAITS_H_
