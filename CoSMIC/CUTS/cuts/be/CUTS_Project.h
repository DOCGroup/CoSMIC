// -*- C++ -*-

#ifndef _CUTS_PROJECT_H_
#define _CUTS_PROJECT_H_

#include "BE_export.h"
#include "PICML/PICML.h"
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

class CUTS_BE_Export CUTS_Project :
  public PICML::Visitor
{
public:
  CUTS_Project (void);

  virtual ~CUTS_Project (void);

  const PICML::Object & get_testing_service (void) const;

  const PICML::File & get_cuts_file (void) const;

  const PICML::String & get_string_type (void) const;

  bool is_valid (void) const;

  const std::string & message (void) const;

private:
  void Visit_RootFolder (const PICML::RootFolder &);

  void Visit_PredefinedTypes (const PICML::PredefinedTypes &);

  void Visit_InterfaceDefinitions (const PICML::InterfaceDefinitions &);

  void Visit_Package (const PICML::Package &);

  void Visit_File (const PICML::File &);

  PICML::Object testing_service_;

  PICML::File cuts_file_;

  PICML::String string_;

  bool valid_;

  std::string message_;
};

CUTS_BE_SINGLETON_DECLARE (ACE_Singleton, CUTS_Project, ACE_Null_Mutex);

#define CUTS_BE_PROJECT() \
  ACE_Singleton <CUTS_Project, ACE_Null_Mutex>::instance ()

#endif  /* !defined _CUTS_PROJECT_H_ */
