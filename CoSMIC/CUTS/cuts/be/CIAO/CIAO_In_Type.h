// -*- C++ -*-

//=============================================================================
/**
 * @file    CIAO_In_Type.h
 *
 * $Id$
 *
 * @author  James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_IN_TYPE_H_
#define _CUTS_CIAO_IN_TYPE_H_

#include "cuts/be/BE_Type_Map.h"

//=============================================================================
/**
 * @class CUTS_CIAO_In_Type
 *
 * CIAO C++ mapping for return types.
 */
//=============================================================================

class CUTS_CIAO_In_Type : public CUTS_BE_Type_Map
{
public:
  static CUTS_CIAO_In_Type * instance (void);

  static void close_singleton (void);

private:
  /// Default constructor.
  CUTS_CIAO_In_Type (void);

  /// Destructor.
  ~CUTS_CIAO_In_Type (void);

  /// Pointer to the singleton instance.
  static CUTS_CIAO_In_Type * instance_;

  // prevent the following operations
  CUTS_CIAO_In_Type (const CUTS_CIAO_In_Type &);
  const CUTS_CIAO_In_Type & operator = (const CUTS_CIAO_In_Type &);
};

/// Macro to simply requesting the return types mapping.
#define CIAO_IN_TYPE(type) \
  CUTS_CIAO_In_Type::instance ()->value (type)

#if defined (__CUTS_INLINE__)
#include "CIAO_In_Type.inl"
#endif

#endif  // !defined _CUTS_CIAO_IN_TYPE_H_
