// -*- C++ -*-

//=============================================================================
/**
 * @file          Natural_Lang_Generators.h
 *
 * Defines generators for the natural language backend
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_NATURAL_LANG_GENERATORS_H_
#define _CUTS_BE_NATURAL_LANG_GENERATORS_H_

#include "cuts/be/BE_Generators_T.h"
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include <fstream>

//=============================================================================
/**
 * @struct CUTS_BE_Natural_Lang
 */
//=============================================================================

struct CUTS_BE_Natural_Lang
{
  /// The output file stream for the generator.
  std::ofstream outfile_;

  /// The indentation count.
  size_t indent_;
};

namespace CUTS_BE
{
  CUTS_BE_NOT_VISIT (CUTS_BE_Natural_Lang, PICML::ProvidedRequestPort);
  CUTS_BE_NOT_VISIT (CUTS_BE_Natural_Lang, PICML::Attribute);
  CUTS_BE_NOT_VISIT (CUTS_BE_Natural_Lang, PICML::ReadonlyAttribute);
  CUTS_BE_NOT_VISIT (CUTS_BE_Natural_Lang, PICML::ComponentFactory);
  CUTS_BE_NOT_VISIT (CUTS_BE_Natural_Lang, PICML::Object);
  CUTS_BE_NOT_VISIT (CUTS_BE_Natural_Lang, PICML::OnewayOperation);
  CUTS_BE_NOT_VISIT (CUTS_BE_Natural_Lang, PICML::TwowayOperation);
}

//=============================================================================
/**
 *
 */
//=============================================================================

#define CUTS_BE_NATURAL_LANG() \
  ACE_Singleton <CUTS_BE_Natural_Lang, ACE_Null_Mutex>::instance ()

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_File_Open_T <CUTS_BE_Natural_Lang>
{
  static bool
  generate (const PICML::ComponentImplementationContainer & container,
            const PICML::MonolithicImplementation & impl);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_File_Close_T <CUTS_BE_Natural_Lang>
{
  static bool
  generate (const PICML::ComponentImplementationContainer & container,
            const PICML::MonolithicImplementation & impl);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Natural_Lang>
{
  static bool
  generate (const PICML::MonolithicImplementation & monoimpl,
            const PICML::Component & type);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_InEventPort_Begin_T <CUTS_BE_Natural_Lang>
{
  static bool generate (const PICML::InEventPort & sink);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_PeriodicEvent_Begin_T <CUTS_BE_Natural_Lang>
{
  static bool generate (const PICML::PeriodicEvent & periodic);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_WorkerAction_Begin_T <CUTS_BE_Natural_Lang>
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
struct CUTS_BE_OutputAction_Begin_T <CUTS_BE_Natural_Lang>
{
  static bool generate (const PICML::OutputAction & action);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Action_Properties_Begin_T <CUTS_BE_Natural_Lang>
{
  static bool generate (size_t count);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Action_Property_T <CUTS_BE_Natural_Lang>
{
  static bool generate (const PICML::Property & property);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Action_Properties_End_T <CUTS_BE_Natural_Lang>
{
  static bool generate (void);
};


//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_Method_Begin_T <CUTS_BE_Natural_Lang>
{
  static bool generate (const PICML::InputAction & action);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Variables_Begin_T <CUTS_BE_Natural_Lang>
{
  static bool generate (const PICML::Component & component);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Variable_T <CUTS_BE_Natural_Lang>
{
  static bool generate (const PICML::Variable & variable);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Worker_Variable_T <CUTS_BE_Natural_Lang>
{
  static bool generate (const PICML::WorkerType & type,
                        const PICML::Worker & worker);
};

#endif  // !defined _CUTS_BE_NATURAL_LANG_GENERATORS_H_
