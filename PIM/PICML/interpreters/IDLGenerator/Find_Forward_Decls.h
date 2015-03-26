// -*- C++ -*-

//=============================================================================
/**
 *  @file       Find_Forward_Decls.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _IDL_FIND_FORWARD_DECLS_H_
#define _IDL_FIND_FORWARD_DECLS_H_

#include "PICML/PICML.h"
#include "PICML/Visitor.h"
#include <set>

// Forward decl.
class IDL_File_Dependency_Processor;

/**
 * @class Find_Forward_Decls
 *
 * Visitor class that will locate all the objects that need to be
 * forward declared within a given scope.
 */
class Find_Forward_Decls : public PICML::Visitor
{
public:
  /// Type definition for the set of forward declared objects.
  typedef std::set <GAME::Mga::Object> fwd_decls_t;

  /// Type definition for the set of include files.
  typedef std::set <PICML::File> includes_t;

  /// Default constructor.
  Find_Forward_Decls (IDL_File_Dependency_Processor & depends_graph,
                      bool visit_template_module = false);

  /// Destructor.
  virtual ~Find_Forward_Decls (void);

  /// Get the collection of foward declared objects.
  const fwd_decls_t & fwd_decls (void) const;

  /// Get the collection of files to include.
  const includes_t & includes (void) const;

  /// Clear the set of objects.
  void clear (void);

  // visitor method(s)
  virtual void visit_File (PICML::File_in);
  virtual void visit_Package (PICML::Package_in );
  virtual void visit_TemplatePackageInstance (PICML::TemplatePackageInstance_in a);
  virtual void visit_Alias (PICML::Alias_in a);
  virtual void visit_Constant (PICML::Constant_in c);
  virtual void visit_Collection (PICML::Collection_in c);
  virtual void visit_Exception (PICML::Exception_in e);
  virtual void visit_Member (PICML::Member_in m);
  virtual void visit_Aggregate (PICML::Aggregate_in a);
  virtual void visit_Component (PICML::Component_in c);
  virtual void visit_ConnectorObject (PICML::ConnectorObject_in c);
  virtual void visit_ComponentFactory (PICML::ComponentFactory_in f);
  virtual void visit_SwitchedAggregate (PICML::SwitchedAggregate_in s);
  virtual void visit_Object (PICML::Object_in o);
  virtual void visit_Event (PICML::Event_in e);
  virtual void visit_ValueObject (PICML::ValueObject_in v);
  virtual void visit_FactoryOperation (PICML::FactoryOperation_in op);
  virtual void visit_ExtendedPort (PICML::ExtendedPort_in p);
  virtual void visit_ReadonlyAttribute (PICML::ReadonlyAttribute_in r);
  virtual void visit_OnewayOperation (PICML::OnewayOperation_in op);
  virtual void visit_TwowayOperation (PICML::TwowayOperation_in op);
  virtual void visit_RequiredRequestPort (PICML::RequiredRequestPort_in op);
  virtual void visit_ProvidedRequestPort (PICML::ProvidedRequestPort_in op);
  virtual void visit_InEventPort (PICML::InEventPort_in in);
  virtual void visit_OutEventPort (PICML::OutEventPort_in out);
  virtual void visit_TemplateParameterValue (PICML::TemplateParameterValue_in t);
  virtual void visit_Boxed (PICML::Boxed_in b);

  bool has_component (void) const;
  bool has_typesupport (void) const;
  bool has_ami4ccm (void) const;

private:
  void visit_ObjectByValue (PICML::ObjectByValue_in obv);
  void visit_MemberType (PICML::MemberType_in m);
  void visit_NamedType (PICML::NamedType_in n);

  PICML::File get_file (const GAME::Mga::Object_in obj);

  IDL_File_Dependency_Processor & depends_graph_;

  bool has_component_;

  bool has_typesupport_;

  bool has_ami4ccm_;

  /// Set of forward declard objects.
  fwd_decls_t fwd_decls_;

  /// Set of include files (i.e., objects in other files).
  includes_t includes_;

  /// The current file being processed.
  PICML::File current_file_;

  bool visit_template_module_;
};

#endif  // !defined _IDL_FIND_FORWARD_DECLS_H_
