// -*- C++ -*-

//=============================================================================
/**
 * @file      Predefined_Type_Map.h
 *
 * $Id: Predefined_Type_Map.h,v 1.1.2.1 2006/05/05 06:45:25 hillj Exp $
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_CIAO_PREDEFINED_TYPE_MAP_H_
#define _CUTS_CIAO_PREDEFINED_TYPE_MAP_H_

#include "UDM_CIAO_Export.h"

#include <string>
#include <map>

class CUTS_UDM_CIAO_Export CUTS_Predefined_Type_Map
{
public:
  static CUTS_Predefined_Type_Map * instance (void);

  const char * c_str (const char * element);

private:
  CUTS_Predefined_Type_Map (void);

  ~CUTS_Predefined_Type_Map (void);

  void init (void);

  static CUTS_Predefined_Type_Map * instance_;

  typedef std::map <std::string, std::string> Predefined_Type_Map;

  Predefined_Type_Map type_map_;
};

#endif  // !defined _CUTS_CIAO_PREDEFINED_TYPE_MAP_H_
