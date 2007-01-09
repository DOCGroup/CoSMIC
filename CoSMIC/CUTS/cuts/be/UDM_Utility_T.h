// -*- C++ -*-

//=============================================================================
/**
 * @file      UDM_Utility_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_UDM_UTILITY_T_H_
#define _CUTS_UDM_UTILITY_T_H_

#include "cuts/config.h"
#include <string>

//=============================================================================
/**
 * @struct Find_Element_By_Name
 *
 * Functor that compares the name of a UDM element against a
 * predetermined name.
 */
//=============================================================================

template <typename T>
struct Find_Element_By_Name
{
  inline
  Find_Element_By_Name (const std::string & name)
    : name_ (name) { }

  inline
  bool operator () (const T & element)
  {
    return (std::string)element.name () == this->name_;
  }

private:
  std::string name_;
};

//=============================================================================
/**
 * @struct create_element_if_not_exist
 *
 * Functor for creating an element if it does not exist. This
 * is useful when used with the std::find_if method.
 */
//=============================================================================

template <typename COLLECTION, typename COMPARE, typename PARENT>
bool create_element_if_not_exist (const COLLECTION & coll,
                                  COMPARE & comp,
                                  const PARENT & parent,
                                  const Uml::CompositionChildRole & role,
                                  typename COLLECTION::value_type & element);

//=============================================================================
/**
 * @struct is_type
 *
 * Functor for checking the type of a UDM object. This is very
 * useful with boost and their template methods.
 */
//=============================================================================

template <typename T>
struct is_type
{
public:
  bool operator () (const T & element);
};

template <typename T>
struct not_is_type
{
  inline
  not_is_type (const std::string & type)
  : type_ (type) { }

  inline
  bool operator () (const T & element)
  {
    return this->type_ != element.type ().name ();
  }

private:
  /// Name of the type.
  const std::string & type_;
};

#if defined (__CUTS_INLINE__)
#include "UDM_Utility_T.inl"
#endif

#include "UDM_Utility_T.cpp"

#endif  /* !defined _CUTS_UDM_UTILITY_H_ */
