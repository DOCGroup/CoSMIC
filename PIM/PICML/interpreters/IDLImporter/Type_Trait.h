// -*- C++ -*-

//=============================================================================
/**
 * @file      Type_Trait.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _IDL_TO_PICML_TYPE_TRAIT_H_
#define _IDL_TO_PICML_TYPE_TRAIT_H_

#include "Predefined_Types.h"

namespace IDML
{
/**
 * @struct Type_Trait
 *
 * Trait class that contains project information about a type.
 */
template <typename T>
struct Type_Trait
{
  /// The index value of the type.
  static const int tk_index = -1;

  /// The metaname for the type.
  static const char * metaname;
};

template  <typename T>
const char * Type_Trait <T>::metaname = "";

/// Specialization for TypeKind
template < >
struct Type_Trait <TypeKind>
{
  static const int tk_index = 0;

  static const char * metaname;
};

/// Specialization for TypeEncoding
template < >
struct Type_Trait <TypeEncoding>
{
  static const int tk_index = 1;

  static const char * metaname;
};

/// Specialization for String
template < >
struct Type_Trait <String>
{
  static const int tk_index = 2;

  static const char * metaname;
};

/// Specialization for Boolean
template < >
struct Type_Trait <Boolean>
{
  static const int tk_index = 3;

  static const char * metaname;
};

/// Specialization for ShortInteger
template < >
struct Type_Trait <ShortInteger>
{
  static const int tk_index = 4;

  static const char * metaname;
};

/// Specialization for FloatNumber
template < >
struct Type_Trait <FloatNumber>
{
  static const int tk_index = 5;

  static const char * metaname;
};

/// Specialization for DoubleNumber
template < >
struct Type_Trait <DoubleNumber>
{
  static const int tk_index = 6;

  static const char * metaname;
};

/// Specialization for LongInteger
template < >
struct Type_Trait <LongInteger>
{
  static const int tk_index = 7;

  static const char * metaname;
};

/// Specialization for GenericValueObject
template < >
struct Type_Trait <GenericValueObject>
{
  static const int tk_index = 8;

  static const char * metaname;
};

/// Specialization for GenericValue
template < >
struct Type_Trait <GenericValue>
{
  static const int tk_index = 9;

  static const char * metaname;
};

/// Specialization for GenericObject
template < >
struct Type_Trait <GenericObject>
{
  static const int tk_index = 10;

  static const char * metaname;
};

/// Specialization for Byte
template < >
struct Type_Trait <Byte>
{
  static const int tk_index = 11;

  static const char * metaname;
};

}

#endif  // !defined _IDL_TO_PICML_TYPE_TRAIT_H_
