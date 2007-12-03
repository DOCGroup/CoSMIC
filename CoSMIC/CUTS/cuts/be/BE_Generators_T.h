// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Generators_T.h
 *
 * Defines generator objects for the CUTS backend
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_GENERATORS_T_H_
#define _CUTS_BE_GENERATORS_T_H_

#include "PICML/PICML.h"

template <typename IMPL_STRATEGY>
struct CUTS_BE_Write_Variables_Last_T
{
  static const bool result_type = true;
};

template <typename IMPL_STRATEGY>
struct CUTS_BE_Parse_Precondition_T
{
  static const bool result_type = true;
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_File_Open_T
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::MonolithicImplementation &)
  {
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ComponentAssembly_File_Open_T
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::ComponentAssembly &)
  {
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_File_Close_T
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::MonolithicImplementation &)
  {
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ComponentAssembly_File_Close_T
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::ComponentAssembly &)
  {
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Include_File_T
{
  static bool generate (const std::string & include)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Prologue_T
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::MonolithicImplementation &)
  {
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ComponentAssembly_Prologue_T
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::ComponentAssembly &)
  {
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Epilogue_T
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::MonolithicImplementation &)
  {
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ComponentAssembly_Epilogue_T
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::ComponentAssembly &)
  {
    return false;
  }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Component_Impl_Begin_T
{
  static bool generate (const PICML::MonolithicImplementation & monoimpl,
                        const PICML::Component & component)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Component_Impl_End_T
{
  static bool generate (const PICML::MonolithicImplementation & monoimpl,
                        const PICML::Component & component)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Factory_Impl_Begin_T
{
  static bool generate (const PICML::ComponentFactory & factory,
                        const PICML::MonolithicImplementation & monoimpl,
                        const PICML::Component & component)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Factory_Impl_End_T
{
  static bool generate (const PICML::ComponentFactory & factory,
                        const PICML::MonolithicImplementation & monoimpl,
                        const PICML::Component & component)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Object_Impl_Begin_T
{
  static bool generate (const PICML::Component & component,
                        const PICML::ProvidedRequestPort & facet)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Object_Impl_End_T
{
  static bool generate (const PICML::Component & component,
                        const PICML::ProvidedRequestPort & facet)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Environment_Begin_T
{
  static bool generate (const PICML::Component & component)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Environment_Method_Begin_T
{
  static bool generate (const PICML::InputAction & action)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Environment_Method_End_T
{
  static bool generate (const PICML::InputAction & action)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Environment_End_T
{
  static bool generate (const PICML::Component & component)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Variables_Begin_T
{
  static bool generate (const PICML::Component & component)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Attribute_Variable_T
{
  static bool generate (const PICML::ReadonlyAttribute & attr)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Variable_T
{
  static bool generate (const PICML::Variable & variable)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Worker_Variable_T
{
  static bool generate (const PICML::WorkerType & type,
                        const PICML::Worker & worker)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_PeriodicEvent_Variable_T
{
  static bool generate (const PICML::PeriodicEvent & periodic)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Variables_End_T
{
  static bool generate (const PICML::Component & component)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_InEventPort_Begin_T
{
  static bool generate (const PICML::InEventPort & sink)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_InEventPort_End_T
{
  static bool generate (const PICML::InEventPort & sink)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ProvidedRequestPort_Begin_T
{
  static bool generate (const PICML::ProvidedRequestPort & source)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ProvidedRequestPort_End_T
{
  static bool generate (const PICML::ProvidedRequestPort & source)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_PeriodicEvent_Begin_T
{
  static bool generate (const PICML::PeriodicEvent & periodic)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_PeriodicEvent_End_T
{
  static bool generate (const PICML::PeriodicEvent & periodic)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ReadonlyAttribute_Begin_T
{
  static bool generate (const PICML::ReadonlyAttribute & readonly)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ReadonlyAttribute_End_T
{
  static bool generate (const PICML::ReadonlyAttribute & readonly)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Attribute_Begin_T
{
  static bool generate (const PICML::Attribute & attr)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Attribute_End_T
{
  static bool generate (const PICML::Attribute & attr)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_OnewayOperation_Begin_T
{
  static bool generate (const PICML::OnewayOperation & oneway)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_OnewayOperation_End_T
{
  static bool generate (const PICML::OnewayOperation & oneway)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_TwowayOperation_Begin_T
{
  static bool generate (const PICML::TwowayOperation & twoway)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_TwowayOperation_End_T
{
  static bool generate (const PICML::TwowayOperation & twoway)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_FactoryOperation_Begin_T
{
  static bool generate (const PICML::FactoryOperation & factory)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_FactoryOperation_End_T
{
  static bool generate (const PICML::FactoryOperation & factory)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Postcondition_T
{
  static bool generate (const std::string & postcondition)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Precondition_T
{
  static bool generate (const std::string & precondition)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Branches_Begin_T
{
  static bool generate (size_t branches) { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Branch_Begin_T
{
  static bool generate (void)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Branch_Condition_Begin_T
{
  static bool generate (void)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Branch_Condition_End_T
{
  static bool generate (void)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Branch_End_T
{
  static bool generate (void)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Branches_End_T
{
  static bool generate (void)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Action_Properties_Begin_T
{
  static bool generate (size_t count)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Action_Property_T
{
  static bool generate (const PICML::Property & property)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Action_Properties_End_T
{
  static bool generate (void)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_WorkerAction_Begin_T
{
  static bool generate (const PICML::Worker & worker,
                        const PICML::Action & action)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_OutputAction_Begin_T
{
  static bool generate (const PICML::OutputAction & action)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_OutputAction_Property_T
{
  static bool generate (const PICML::OutputAction & action,
                        const PICML::Property & property)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_OutputAction_End_T
{
  static bool generate (const PICML::OutputAction & action)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Action_End_T
{
  static bool generate (void)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_State_T
{
  static bool generate (const PICML::State & state)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Equal_To_T
{
  static bool generate (const char * first, const char * last)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Not_Equal_To_T
{
  static bool generate (const char * first, const char * last)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Greater_Than_T
{
  static bool generate (const char * first, const char * last)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Greater_Than_Equal_To_T
{
  static bool generate (const char * first, const char * last)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Less_Than_T
{
  static bool generate (const char * first, const char * last)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Less_Than_Equal_To_T
{
  static bool generate (const char * first, const char * last)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Identifier_T
{
  static bool generate (const char * begin, const char * end)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Transcribe_Text_T
{
  static bool generate (const char * begin, const char * end)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Transcribe_Char_T
{
  static bool generate (char ch)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_And_T
{
  static bool generate (const char * begin, const char * end)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Or_T
{
  static bool generate (const char * begin, const char * end)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ComponentAssembly_Begin_T
{
  static bool generate (const PICML::ComponentAssembly & assembly)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ComponentAssembly_End_T
{
  static bool generate (const PICML::ComponentAssembly & assembly)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_Component_Instance_T
{
  static bool generate (const PICML::Component & component)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ComponentAssembly_Connections_Begin_T
{
  static bool generate (const PICML::ComponentAssembly & assembly)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_emit_T
{
  static bool generate (const PICML::emit & emit)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_PublishConnector_T
{
  static bool generate (const PICML::PublishConnector & connector)
    { return false; }
};

//=============================================================================
/**
 *
 */
//=============================================================================

template <typename IMPL_STRATEGY>
struct CUTS_BE_ComponentAssembly_Connections_End_T
{
  static bool generate (const PICML::ComponentAssembly & assembly)
    { return false; }
};

#endif  // !defined _CUTS_BE_GENERATORS_T_H_
