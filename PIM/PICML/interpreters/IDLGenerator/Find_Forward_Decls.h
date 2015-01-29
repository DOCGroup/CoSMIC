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

#include "PICML/Visitor.h"

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
  virtual void Visit_File (const PICML::File_in);
  virtual void Visit_Package (const PICML::Package_in );
  virtual void Visit_TemplatePackageInstance (const PICML::TemplatePackageInstance_in a);
  virtual void Visit_Alias (const PICML::Alias_in a);
  virtual void Visit_Constant (const PICML::Constant_in c);
  virtual void Visit_Collection (const PICML::Collection_in c);
  virtual void Visit_Exception (const PICML::Exception_in e);
  virtual void Visit_Member (const PICML::Member_in m);
  virtual void Visit_Aggregate (const PICML::Aggregate_in a);
  virtual void Visit_Component (const PICML::Component_in c);
  virtual void Visit_ConnectorObject (const PICML::ConnectorObject_in c);
  virtual void Visit_ComponentFactory (const PICML::ComponentFactory_in f);
  virtual void Visit_SwitchedAggregate (const PICML::SwitchedAggregate_in s);
  virtual void Visit_Object (const PICML::Object_in o);
  virtual void Visit_Event (const PICML::Event_in e);
  virtual void Visit_ValueObject (const PICML::ValueObject_in v);
  virtual void Visit_FactoryOperation (const PICML::FactoryOperation_in op);
  virtual void Visit_ExtendedPort (const PICML::ExtendedPort_in p);
  virtual void Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute_in r);
  virtual void Visit_OnewayOperation (const PICML::OnewayOperation_in op);
  virtual void Visit_TwowayOperation (const PICML::TwowayOperation_in op);
  virtual void Visit_RequiredRequestPort (const PICML::RequiredRequestPort_in op);
  virtual void Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort_in op);
  virtual void Visit_InEventPort (const PICML::InEventPort_in in);
  virtual void Visit_OutEventPort (const PICML::OutEventPort_in out);
  virtual void Visit_TemplateParameterValue (const PICML::TemplateParameterValue_in t);
  virtual void Visit_Boxed (const PICML::Boxed_in b);

  bool has_component (void) const;
  bool has_typesupport (void) const;
  bool has_ami4ccm (void) const;

private:
  void Visit_ObjectByValue (const PICML::ObjectByValue_in obv);
  void Visit_MemberType (const PICML::MemberType_in m);
  void Visit_NamedType (const PICML::NamedType_in n);

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
