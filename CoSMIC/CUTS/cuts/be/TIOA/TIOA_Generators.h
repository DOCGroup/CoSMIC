// -*- C++ -*-

//=============================================================================
/**
 * @file          TIOA_Generators.h
 *
 * Defines the different generators used by the TIAO backend
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_TIOA_GENERATORS_H_
#define _CUTS_BE_TIOA_GENERATORS_H_

#include "cuts/be/BE_Generators_T.h"
#include "cuts/be/String_Set.h"
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include <fstream>

//=============================================================================
/**
 * @struct CUTS_BE_Tioa
 */
//=============================================================================

class CUTS_BE_Tioa
{
public:
  CUTS_BE_Tioa (void);

  /// Reset the generator's state.
  void reset (void);

  /// Target TIOA output file.
  std::ofstream outfile_;

  /// Listing of inputs.
  CUTS_String_Set input_events_;

  /// The last state visited.
  long last_state_id_;

  /// Done generating the environment section.
  bool env_done_;

  /// Keeps track of how many states written.
  long state_count_;
};

//
// disable the following points of visitation
//
namespace CUTS_BE
{
  CUTS_BE_NOT_VISIT (CUTS_BE_Tioa, PICML::ProvidedRequestPort);
  CUTS_BE_NOT_VISIT (CUTS_BE_Tioa, PICML::Attribute);
  CUTS_BE_NOT_VISIT (CUTS_BE_Tioa, PICML::ReadonlyAttribute);
  CUTS_BE_NOT_VISIT (CUTS_BE_Tioa, PICML::ComponentFactory);
  CUTS_BE_NOT_VISIT (CUTS_BE_Tioa, PICML::Property);
  CUTS_BE_NOT_VISIT (CUTS_BE_Tioa, PICML::Object);
  CUTS_BE_NOT_VISIT (CUTS_BE_Tioa, PICML::OnewayOperation);
  CUTS_BE_NOT_VISIT (CUTS_BE_Tioa, PICML::TwowayOperation);
}

template < >
struct CUTS_BE_Write_Variables_Last_T <CUTS_BE_Tioa>
{
  static const bool result_type = false;
};

//=============================================================================
/**
 *
 */
//=============================================================================

#define CUTS_BE_TIOA() \
  ACE_Singleton <CUTS_BE_Tioa, ACE_Null_Mutex>::instance ()

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_File_Open_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::MonolithicImplementation &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_ComponentAssembly_File_Open_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::ComponentAssembly &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_ComponentAssembly_File_Close_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::ComponentAssembly &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Prologue_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::MonolithicImplementation &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_ComponentAssembly_Prologue_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::ComponentAssembly &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_File_Close_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::ComponentImplementationContainer &,
                        const PICML::MonolithicImplementation & );
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::MonolithicImplementation & mono,
                        const PICML::Component & component);

private:
  static void write_portid_InEventPort (const PICML::InEventPort &);

  static void write_param_InEventPort (const PICML::InEventPort &);
  static void write_param_OutEventPort (const PICML::OutEventPort &);

  static void write_vocabulary_State (const PICML::State &);
  static void write_signature_Action (const PICML::Action &);
  static void write_signature_PeriodicEvent (const PICML::PeriodicEvent &);
  static void write_signature_InEventPort (const PICML::InEventPort &);

  static void visit_Environment (const PICML::Environment &);
  static void visit_MultiInput (const PICML::MultiInput &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Component_Impl_End_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::MonolithicImplementation & mono,
                        const PICML::Component & component);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Variables_Begin_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::Component & component);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Variables_End_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::Component & component);

private:
  static void write_system_calls (const PICML::InEventPort &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_State_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::State & state);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_WorkerAction_Begin_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::Worker & worker,
                        const PICML::Action & action);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Action_End_T <CUTS_BE_Tioa>
{
  static bool generate (void);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_InEventPort_Begin_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::InEventPort & sink);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_InEventPort_End_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::InEventPort & sink);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_OutputAction_Begin_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::OutputAction & action);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_End_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::Component & component);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_Method_Begin_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::InputAction & action);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_Method_End_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::InputAction & action);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_PeriodicEvent_Begin_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::PeriodicEvent & periodic);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_PeriodicEvent_End_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::PeriodicEvent & periodic);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_ComponentAssembly_Begin_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::ComponentAssembly &);

private:
  static void write_host_id (const PICML::Component &);
  static void write_host_id_i (const PICML::Component &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Component_Instance_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::Component & component);

private:
  static void Visit_OutEventPort (const PICML::OutEventPort & oep);
  static void Visit_InEventPort (const PICML::InEventPort & oep);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_ComponentAssembly_Connections_Begin_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::ComponentAssembly & assembly);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_emit_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::emit & e);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_PublishConnector_T <CUTS_BE_Tioa>
{
  static bool generate (const PICML::PublishConnector & connector);
};

#endif  // !defined _CUTS_BE_TIOA_GENERATORS_H_
