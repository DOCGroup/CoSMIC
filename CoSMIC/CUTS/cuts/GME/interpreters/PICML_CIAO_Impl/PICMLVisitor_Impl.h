// -*- C++ -*-

//=============================================================================
/**
 * @file      PICML_Visitor.h
 *
 * $Id$
 *
 * [insert descripter here]
 *
 * @author    James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_PICML_VISITOR_IMPL_H_
#define _CUTS_PICML_VISITOR_IMPL_H_

#include "cuts/fe/PICML/PICMLVisitor.h"

#include <set>
#include <map>
#include <queue>
#include <string>
#include <fstream>
#include <strstream>

//=============================================================================
/**
 * @class CUTS_PICML_Visitor_Impl
 */
//=============================================================================

class CUTS_PICMLVisitor_Impl :
  public PICML_BON::PICMLVisitor
{
public:
  CUTS_PICMLVisitor_Impl (const char * outdir);

  virtual ~CUTS_PICMLVisitor_Impl (void);

protected:
  bool visitInterfaceDefinitions (const PICML_BON::InterfaceDefinitions &object);
  bool visitEvent (const PICML_BON::Event & object);
  bool visitFile (const PICML_BON::File & object);
  bool visitPackage (const PICML_BON::Package & object);
  bool visitComponent (const PICML_BON::Component & object);
  bool visitInEventPort (const PICML_BON::InEventPort & object);

private:
  /// Visit the contents of a package. This is good for files as well.
  void visit_package_contents (const BON::Model & object);

  /// Write the set_session_context method.
  void write_set_session_context (void);
  void write_ciao_preactivate (void);
  void write_ccm_activate (void);
  void write_ciao_postactivate (void);
  void write_ccm_remove (void);
  void write_constructor_and_destructor (void);

  /// Holds the current component.
  std::string component_;

  /// Root directory for the files.
  std::string output_dir_;

  /// Name of the export macro for the file.
  std::string export_;

  /// Source output file.
  std::ofstream sofs_;

  /// Header output file.
  std::ofstream hofs_;

  /// Name of the previous visited object.
  std::string object_name_;

  /// UUID -> name of the port.
  typedef std::map <std::string, std::string> Port_Mapping;

  typedef std::set <std::string> String_Set;

  /// Events receieved by the component.
  String_Set event_types_;

  /// Event sources for the component.
  Port_Mapping event_sinks_;
};

#if defined (__CUTS_INLINE__)
# include "PICMLVisitor_Impl.inl"
#endif

#endif  // !defined _CUTS_PICML_VISITOR_IMPL_H_
