
// -*- C++ -*-

//=============================================================================
/**
 * @file      CUTS_BE_CIAO.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_CIAO_TRAITS_H_
#define _CUTS_BE_CIAO_TRAITS_H_

#include "cuts/be/BE_Generators_T.h"
#include "CIAO_Exec_Header_Traits.h"
#include "CIAO_Exec_Source_Traits.h"
#include "CIAO_Proxy_Header_Traits.h"
#include "CIAO_Proxy_Source_Traits.h"

/// Specialization struct for the CUTS_BE_CIAO backend.
struct CUTS_BE_CIAO;

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_File_Open_T <CUTS_BE_CIAO>
{
  static bool
  generate (const PICML::ComponentImplementationContainer & container,
            const PICML::MonolithicImplementation & impl)
  {
    return CIAO_EXEC_HEADER_GENERATOR ()->open_file (container) |
           CIAO_EXEC_SOURCE_GENERATOR ()->open_file (container) |
           CIAO_PROXY_HEADER_GENERATOR ()->open_file (container) |
           CIAO_PROXY_SOURCE_GENERATOR ()->open_file (container);
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_File_Close_T <CUTS_BE_CIAO>
{
  static bool
  generate (const PICML::ComponentImplementationContainer & container,
            const PICML::MonolithicImplementation & impl)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->close_file (container);
    CIAO_EXEC_SOURCE_GENERATOR ()->close_file (container);

    CIAO_PROXY_HEADER_GENERATOR ()->close_file (container);
    CIAO_PROXY_SOURCE_GENERATOR ()->close_file (container);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Prologue_T <CUTS_BE_CIAO>
{
  static bool
  generate (const PICML::ComponentImplementationContainer & container,
            const PICML::MonolithicImplementation & impl)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_prologue (container);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_prologue (container);

    CIAO_PROXY_HEADER_GENERATOR ()->write_prologue (container);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_prologue (container);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Epilogue_T <CUTS_BE_CIAO>
{
  static bool
  generate (const PICML::ComponentImplementationContainer & container,
            const PICML::MonolithicImplementation & impl)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_epilogue (container);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_epilogue (container);

    CIAO_PROXY_HEADER_GENERATOR ()->write_epilogue (container);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_epilogue (container);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Component_Impl_Begin_T <CUTS_BE_CIAO>
{
  static bool
  generate (const PICML::MonolithicImplementation & monoimpl,
            const PICML::Component & component)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_impl_begin (monoimpl, component);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_impl_begin (monoimpl, component);

    CIAO_PROXY_HEADER_GENERATOR ()->write_impl_begin (monoimpl, component);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_impl_begin (monoimpl, component);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Component_Impl_End_T <CUTS_BE_CIAO>
{
  static bool
  generate (const PICML::MonolithicImplementation & monoimpl,
            const PICML::Component & component)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_impl_end (monoimpl, component);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_impl_end (monoimpl, component);

    CIAO_PROXY_HEADER_GENERATOR ()->write_impl_end (monoimpl, component);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_impl_end (monoimpl, component);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Factory_Impl_Begin_T <CUTS_BE_CIAO>
{
  static bool
  generate (const PICML::ComponentFactory & factory,
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

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Factory_Impl_End_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::ComponentFactory & factory,
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

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Object_Impl_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::Component & component,
                        const PICML::ProvidedRequestPort & facet)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_object_impl_begin (component, facet);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_object_impl_begin (component, facet);

    CIAO_PROXY_HEADER_GENERATOR ()->write_object_impl_begin (component, facet);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_object_impl_begin (component, facet);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Object_Impl_End_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::Component & component,
                        const PICML::ProvidedRequestPort & facet)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_object_impl_end (component, facet);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_object_impl_end (component, facet);

    CIAO_PROXY_HEADER_GENERATOR ()->write_object_impl_end (component, facet);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_object_impl_end (component, facet);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Include_File_T <CUTS_BE_CIAO>
{
  static bool generate (const std::string & include)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_include (include);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_Begin_T <CUTS_BE_CIAO>
{
  static bool
  generate (const PICML::Component & component)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_environment_begin (component);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_environment_begin (component);

    CIAO_PROXY_HEADER_GENERATOR ()->write_environment_begin (component);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_environment_begin (component);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_Method_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::InputAction & action)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_environment_method_begin (action);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_environment_method_begin (action);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_Method_End_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::InputAction & action)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_environment_method_end (action);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_environment_method_end (action);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_End_T <CUTS_BE_CIAO>
{
  static bool
  generate (const PICML::Component & component)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_environment_end (component);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_environment_end (component);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Variables_Begin_T <CUTS_BE_CIAO>
{
  static bool
  generate (const PICML::Component & component)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_variables_begin (component);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_variables_begin (component);

    CIAO_PROXY_HEADER_GENERATOR ()->write_variables_begin (component);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_variables_begin (component);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Worker_Variable_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::WorkerType & type,
                        const PICML::Worker & worker)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_worker_variable (type, worker);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_worker_variable (type, worker);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Variables_End_T <CUTS_BE_CIAO>
{
  static bool
  generate (const PICML::Component & component)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_variables_end ();
    CIAO_EXEC_SOURCE_GENERATOR ()->write_variables_end ();
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_PeriodicEvent_Variable_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::PeriodicEvent & periodic)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_PeriodicEvent_variable (periodic);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_PeriodicEvent_variable (periodic);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Attribute_Variable_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::ReadonlyAttribute & attr)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_ReadonlyAttribute_variable (attr);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_ReadonlyAttribute_variable (attr);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Variable_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::Variable & variable)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_variable  (variable);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_variable  (variable);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_InEventPort_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::InEventPort & sink)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_InEventPort_begin (sink);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_InEventPort_begin (sink);

    CIAO_PROXY_HEADER_GENERATOR ()->write_InEventPort_begin (sink);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_InEventPort_begin (sink);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_InEventPort_End_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::InEventPort & sink)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_InEventPort_end  (sink);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_InEventPort_end  (sink);

    CIAO_PROXY_HEADER_GENERATOR ()->write_InEventPort_end  (sink);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_InEventPort_end  (sink);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_ProvidedRequestPort_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::ProvidedRequestPort & source)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_ProvidedRequestPort_begin (source);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_ProvidedRequestPort_begin (source);

    CIAO_PROXY_HEADER_GENERATOR ()->write_ProvidedRequestPort_begin (source);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_ProvidedRequestPort_begin (source);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_ProvidedRequestPort_End_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::ProvidedRequestPort & source)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_ProvidedRequestPort_end  (source);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_ProvidedRequestPort_end  (source);

    CIAO_PROXY_HEADER_GENERATOR ()->write_ProvidedRequestPort_end  (source);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_ProvidedRequestPort_end  (source);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_PeriodicEvent_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::PeriodicEvent & periodic)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_PeriodicEvent_begin (periodic);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_PeriodicEvent_begin (periodic);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_PeriodicEvent_End_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::PeriodicEvent & periodic)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_PeriodicEvent_end  (periodic);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_PeriodicEvent_end  (periodic);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_ReadonlyAttribute_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::ReadonlyAttribute & attr)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_ReadonlyAttribute_begin (attr);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_ReadonlyAttribute_begin (attr);

    CIAO_PROXY_HEADER_GENERATOR ()->write_ReadonlyAttribute_begin (attr);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_ReadonlyAttribute_begin (attr);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_ReadonlyAttribute_End_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::ReadonlyAttribute & attr)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_ReadonlyAttribute_end  (attr);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_ReadonlyAttribute_end  (attr);

    CIAO_PROXY_HEADER_GENERATOR ()->write_ReadonlyAttribute_end  (attr);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_ReadonlyAttribute_end  (attr);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Attribute_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::Attribute & attr)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_Attribute_begin (attr);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_Attribute_begin (attr);

    CIAO_PROXY_HEADER_GENERATOR ()->write_Attribute_begin (attr);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_Attribute_begin (attr);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Attribute_End_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::Attribute & attr)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_Attribute_end  (attr);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_Attribute_end  (attr);

    CIAO_PROXY_HEADER_GENERATOR ()->write_Attribute_end  (attr);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_Attribute_end  (attr);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_OnewayOperation_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::OnewayOperation & oneway)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_OnewayOperation_begin (oneway);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_OnewayOperation_begin (oneway);

    CIAO_PROXY_HEADER_GENERATOR ()->write_OnewayOperation_begin (oneway);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_OnewayOperation_begin (oneway);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_OnewayOperation_End_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::OnewayOperation & oneway)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_OnewayOperation_end  (oneway);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_OnewayOperation_end  (oneway);

    CIAO_PROXY_HEADER_GENERATOR ()->write_OnewayOperation_end  (oneway);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_OnewayOperation_end  (oneway);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_TwowayOperation_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::TwowayOperation & twoway)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_TwowayOperation_begin (twoway);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_TwowayOperation_begin (twoway);

    CIAO_PROXY_HEADER_GENERATOR ()->write_TwowayOperation_begin (twoway);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_TwowayOperation_begin (twoway);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_TwowayOperation_End_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::TwowayOperation & twoway)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_TwowayOperation_end  (twoway);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_TwowayOperation_end  (twoway);

    CIAO_PROXY_HEADER_GENERATOR ()->write_TwowayOperation_end  (twoway);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_TwowayOperation_end  (twoway);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_FactoryOperation_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::FactoryOperation & fop)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_FactoryOperation_begin (fop);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_FactoryOperation_begin (fop);

    CIAO_PROXY_HEADER_GENERATOR ()->write_FactoryOperation_begin (fop);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_FactoryOperation_begin (fop);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_FactoryOperation_End_T <CUTS_BE_CIAO>
{
  static bool generate (const PICML::FactoryOperation & fop)
  {
    CIAO_EXEC_HEADER_GENERATOR ()->write_FactoryOperation_end (fop);
    CIAO_EXEC_SOURCE_GENERATOR ()->write_FactoryOperation_end (fop);

    CIAO_PROXY_HEADER_GENERATOR ()->write_FactoryOperation_end (fop);
    CIAO_PROXY_SOURCE_GENERATOR ()->write_FactoryOperation_end (fop);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Postcondition_T <CUTS_BE_CIAO>
{
  static bool generate (const std::string & postcondition)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_postcondition (postcondition);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Branches_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (size_t branches)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_branches_begin (branches);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Branch_Condition_Begin_T <CUTS_BE_CIAO>
{
  static bool generate (void)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_branch_condition_begin ();
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Branch_Condition_End_T <CUTS_BE_CIAO>
{
  static bool generate (void)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_branch_condition_end ();
    return true;
  }
};


//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Branch_Begin_T <CUTS_BE_CIAO>
{
  static inline bool generate ()
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_branch_begin ();
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Branch_End_T <CUTS_BE_CIAO>
{
  static inline bool generate ()
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_branch_end ();
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Branches_End_T <CUTS_BE_CIAO>
{
  static inline bool generate (void)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_branches_end ();
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Action_Property_T <CUTS_BE_CIAO>
{
  static inline bool generate (const PICML::Property & property)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_action_property (property);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_WorkerAction_Begin_T <CUTS_BE_CIAO>
{
  static inline bool
    generate (const PICML::Worker & worker, const PICML::Action & action)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->
      write_WorkerAction_begin (worker, action);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_OutputAction_Begin_T <CUTS_BE_CIAO>
{
  static inline bool generate (const PICML::OutputAction & action)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_OutputAction_begin (action);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_OutputAction_Property_T <CUTS_BE_CIAO>
{
  static inline bool generate (const PICML::OutputAction & action,
                               const PICML::Property & property)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->
      write_OuputAction_Property (action, property);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_OutputAction_End_T <CUTS_BE_CIAO>
{
  static inline bool generate (const PICML::OutputAction & action)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_OutputAction_end (action);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Action_End_T <CUTS_BE_CIAO>
{
  static inline bool generate (void)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_action_end ();
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Equal_To_T <CUTS_BE_CIAO>
{
  static bool generate (const char * first, const char * last)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_equal_to ();
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Not_Equal_To_T <CUTS_BE_CIAO>
{
  static bool generate (const char * first, const char * last)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_not_equal_to ();
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Greater_Than_T <CUTS_BE_CIAO>
{
  static bool generate (const char * first, const char * last)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_greater_than ();
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Greater_Than_Equal_To_T <CUTS_BE_CIAO>
{
  static bool generate (const char * first, const char * last)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_greater_than_equal_to ();
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Less_Than_T <CUTS_BE_CIAO>
{
  static bool generate (const char * first, const char * last)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_less_than ();
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Less_Than_Equal_To_T <CUTS_BE_CIAO>
{
  static bool generate (const char * first, const char * last)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_less_than_equal_to ();
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Identifier_T <CUTS_BE_CIAO>
{
  static bool generate (const char * begin, const char * end)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_identifier (std::string (begin, end));
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Transcribe_Text_T <CUTS_BE_CIAO>
{
  static bool generate (const char * begin, const char * end)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_text (std::string (begin, end));
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Transcribe_Char_T <CUTS_BE_CIAO>
{
  static bool generate (char ch)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_char (ch);
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_And_T <CUTS_BE_CIAO>
{
  static bool generate (const char * begin, const char * end)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_and_symbol ();
    return true;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Or_T <CUTS_BE_CIAO>
{
  static bool generate (const char * begin, const char * end)
  {
    CIAO_EXEC_SOURCE_GENERATOR ()->write_or_symbol ();
    return true;
  }
};

#endif  // !defined _CUTS_BE_CIAO_TRAITS_H_
