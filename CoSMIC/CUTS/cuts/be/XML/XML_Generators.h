// -*- C++ -*-

//=============================================================================
/**
 * @file          XML_Generators.h
 *
 * Defines the different generators used by the TIAO backend
 *
 * $Id$
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_XML_GENERATORS_H_
#define _CUTS_BE_XML_GENERATORS_H_

#include "cuts/be/BE_Generators_T.h"
#include "cuts/be/String_Set.h"
#include <fstream>

namespace Indentation
{
  // Forward decl.
  template <typename T> class XML;

  // Forward decl.
  template <template <typename> class BufferType,
            typename C> class Implanter;
}

//=============================================================================
/**
 * @struct CUTS_BE_Xml
 */
//=============================================================================

class CUTS_BE_Xml
{
public:
  CUTS_BE_Xml (void);

  /// Target TIOA output file.
  std::ofstream outfile_;

  /// Number of properties for an action.
  size_t property_count_;

  /// Indentation implanter.
  typedef Indentation::Implanter <
    Indentation::XML, char> _formatter_type;

  /// Pointer to the formatter.
  std::auto_ptr <_formatter_type> formatter_;
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_File_Open_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::ComponentImplementationContainer &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_File_Close_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::ComponentImplementationContainer &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Prologue_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::ComponentImplementationContainer &);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Component_Impl_Begin_T <CUTS_BE_Xml>
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
struct CUTS_BE_Component_Impl_End_T <CUTS_BE_Xml>
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
struct CUTS_BE_Variables_Begin_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::Component & component);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Variable_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::Variable & variable);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Worker_Variable_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::WorkerType & type,
                        const PICML::Worker & worker);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Variables_End_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::Component & component);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_WorkerAction_Begin_T <CUTS_BE_Xml>
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
struct CUTS_BE_Action_Properties_Begin_T <CUTS_BE_Xml>
{
  static bool generate (size_t count);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Action_Property_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::Property & property);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Action_Properties_End_T <CUTS_BE_Xml>
{
  static bool generate (void);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_OutputAction_Begin_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::OutputAction & action);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_OutputAction_Property_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::OutputAction & action,
                        const PICML::Property & property);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_OutputAction_End_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::OutputAction & action);
};


//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Action_End_T <CUTS_BE_Xml>
{
  static bool generate (void);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_InEventPort_Begin_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::InEventPort & sink);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_InEventPort_End_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::InEventPort & sink);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_Begin_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::Component & component);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_Method_Begin_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::InputAction & action);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_Method_End_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::InputAction & action);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_Environment_End_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::Component & component);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_PeriodicEvent_Begin_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::PeriodicEvent & periodic);
};

//=============================================================================
/**
 *
 */
//=============================================================================

template < >
struct CUTS_BE_PeriodicEvent_End_T <CUTS_BE_Xml>
{
  static bool generate (const PICML::PeriodicEvent & periodic);
};

#endif  // !defined _CUTS_BE_XML_GENERATORS_H_
