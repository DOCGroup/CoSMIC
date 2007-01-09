// -*- C++ -*-

//=============================================================================
/**
 * @file      CUTS_BE_IDL_Graph.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_IDL_GRAPH_H_
#define _CUTS_BE_IDL_GRAPH_H_

#include "BE_Depend_Graph_T.h"
#include "BE_IDL_Node.h"
#include "PICML/PICML.h"

//=============================================================================
/**
 * @class CUTS_BE_IDL_Graph
 */
//=============================================================================

class CUTS_BE_IDL_Graph :
  public CUTS_BE_Depend_Graph_T <CUTS_BE_IDL_Node>,
  public PICML::Visitor
{
public:
  /// Default constructor.
  CUTS_BE_IDL_Graph (void);

  /// Destructor.
  virtual ~CUTS_BE_IDL_Graph (void);

protected:
  /// Visit the RootFolder of a PICML model.
  void Visit_RootFolder (const PICML::RootFolder &);

  /// Visit InterfaceDefinitions folder in a PICML model.
  void Visit_InterfaceDefinitions (const PICML::InterfaceDefinitions &);

  /// Visit a File in a PICML model.
  void Visit_File (const PICML::File &);

  /// Visit a Package in a PICML model.
  void Visit_Package (const PICML::Package &);

  /// Visit a Component in a PICML model.
  void Visit_Component (const PICML::Component &);

  /// Visit an Object in a PICML model.
  void Visit_Object (const PICML::Object &);

  /// Visit an InEventPort of a PICML model.
  void Visit_InEventPort (const PICML::InEventPort &);

  /// Visit an OutEventPort of a PICML model.
  void Visit_OutEventPort (const PICML::OutEventPort &);

  /// Visit an ProvidedRequestPort of a PICML model.
  void Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort &);

  /// Visit an RequiredRequestPort of a PICML model.
  void Visit_RequiredRequestPort (const PICML::RequiredRequestPort &);

  /// Visit an Event in a PICML model.
  void Visit_Event (const PICML::Event &);

  /// Visit a Providable element in a PICML model.
  void Visit_Providable (const PICML::Provideable &);

  /// Visit a Supports element in a PICML model.
  void Visit_Supports (const PICML::Supports &);

  /// Visit a ReadonlyAttribute in a PICML model.
  void Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute &);

  /// Visit a NameType element in a PICML model.
  void Visit_NamedType (const PICML::NamedType & type);

private:
  /**
   * Get the parent file of a named type.
   *
   * @param[in]     type      The source named type.
   * @return        The parent of the named type.
   */
  PICML::File NamedType_parent (const PICML::NamedType & type);

  /**
   * Visit the contents of a File/Package element in a PICML
   * model.
   *
   * @param[in]     object        The source object.
   */
  void visit_file_and_package_contents (const Udm::Object & object);

  /// Singleton instance of the graph.
  static CUTS_BE_IDL_Graph * instance_;

  /// The current node in the graph.
  CUTS_BE_IDL_Node * current_node_;

  /// Type definition for a collection of files.
  typedef std::set <PICML::File> File_Set;

  /// Files that need to be parsed.
  File_Set pending_files_;

  /// The file that's currently being preprocessed.
  PICML::File active_file_;
};

#define CUTS_BE_IDL_GRAPH() \
  CUTS_BE_IDL_Graph::instance ()

#endif  // !defined _CUTS_BE_IDL_GRAPH_H_
