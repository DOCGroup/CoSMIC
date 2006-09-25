// -*- C++ -*-

//=============================================================================
/**
 * @file    CIAO_Var_Type.h
 *
 * $Id$
 *
 * @author  James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_VAR_TYPE_H_
#define _CUTS_CIAO_VAR_TYPE_H_

#include "CIAO_Var_Type_T.h"

//=============================================================================
/**
 * @class CUTS_CIAO_In_Type_T <PICML::MemberType>
 *
 * Template specialization for MemberType elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::MemberType>
{
public:
  /**
   * Write the type identifier for a predefined type.
   *
   * @param[in]       out         Target stream
   * @param[in]       type        Source type.
   */
  static void write (std::ostream & out,
                     const PICML::MemberType & type);
};

//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T <PICML::PredefinedType>
 *
 * Template specialization for PredefinedType elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::PredefinedType>
{
public:
  /**
   * Write the type identifier for a predefined type.
   *
   * @param[in]       out         Target stream
   * @param[in]       type        Source type.
   */
  static void write (std::ostream & out,
                     const PICML::PredefinedType & type);
};

//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T <PICML::Byte>
 *
 * Template specialization for Byte elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::Byte>
{
public:
  static void write (std::ostream & out);
};

//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T <PICML::String>
 *
 * Template specialization for String elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::String>
{
public:
  static void write (std::ostream & out);
};

//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T <PICML::ShortInteger>
 *
 * Template specialization for ShortInteger elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::ShortInteger>
{
public:
  static void write (std::ostream & out);
};

//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T <PICML::LongInteger>
 *
 * Template specialization for LongInteger elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::LongInteger>
{
public:
  static void write (std::ostream & out);
};

//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T <PICML::Boolean>
 *
 * Template specialization for Boolean elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::Boolean>
{
public:
  static void write (std::ostream & out);
};

//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T <PICML::RealNumber>
 *
 * Template specialization for RealNumber elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::RealNumber>
{
public:
  static void write (std::ostream & out);
};

//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T <PICML::GenericObject>
 *
 * Template specialization for GenericObject elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::GenericObject>
{
public:
  static void write (std::ostream & out);
};

//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T <PICML::GenericValue>
 *
 * Template specialization for GenericValue elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::GenericValue>
{
public:
  static void write (std::ostream & out);
};


//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T <PICML::GenericValue>
 *
 * Template specialization for GenericValue elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::TypeKind>
{
public:
  static void write (std::ostream & out);
};

//=============================================================================
/**
 * @class CUTS_CIAO_Var_Type_T <PICML::TypeEncoding>
 *
 * Template specialization for TypeEncoding elements.
 */
//=============================================================================

template <>
class CUTS_CIAO_Var_Type_T <PICML::TypeEncoding>
{
public:
  static void write (std::ostream & out);
};

#if defined (__CUTS_INLINE__)
#include "CIAO_Var_Type.inl"
#endif

#endif  // !defined _CUTS_CIAO_VAR_TYPE_H_
