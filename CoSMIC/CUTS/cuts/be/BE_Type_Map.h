// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Type_Map.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_TYPE_MAP_H_
#define _CUTS_BE_TYPE_MAP_H_

#include "BE_export.h"
#include "PICML/PICML.h"
#include "Uml.h"
#include <string>
#include <map>

//=============================================================================
/**
 * @class CUTS_BE_Type_Map
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_Type_Map
{
public:
  /// Destructor.
  virtual ~CUTS_BE_Type_Map (void);

  virtual std::string value (const PICML::MemberType & type);

  virtual std::string value (const PICML::PredefinedType & type);

  virtual std::string value (const PICML::NamedType & type);

protected:
  /// Type definition for mapping predefined types.
  typedef std::map <Uml::Class, std::string> PredefinedType_Map;

  /// Mapping of predefined types to concrete syntax.
  PredefinedType_Map predefined_type_map_;

  /// Default constructor.
  CUTS_BE_Type_Map (void);
};

#if defined (__CUTS_INLINE__)
#include "BE_Type_Map.inl"
#endif

#endif  // !defined _CUTS_BE_TYPE_MAP_H_
