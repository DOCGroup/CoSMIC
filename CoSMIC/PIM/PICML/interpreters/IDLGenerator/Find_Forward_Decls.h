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
  typedef std::set <Udm::Object> fwd_decls_t;

  /// Type definition for the set of include files.
  typedef std::set <PICML::File> includes_t;

  /// Default constructor.
  Find_Forward_Decls (bool visit_template_module = false);

  /// Destructor.
  virtual ~Find_Forward_Decls (void);

  /// Get the collection of foward declared objects.
  const fwd_decls_t & fwd_decls (void) const;

  /// Get the collection of files to include.
  const includes_t & includes (void) const;

  /// Clear the set of objects.
  void clear (void);

  // visitor method(s)
  virtual void Visit_File (const PICML::File &);
  virtual void Visit_Package (const PICML::Package & );
  virtual void Visit_TemplatePackageInstance (const PICML::TemplatePackageInstance & a);
  virtual void Visit_Alias (const PICML::Alias & a);
  virtual void Visit_Constant (const PICML::Constant & c);
  virtual void Visit_Collection (const PICML::Collection & c);
  virtual void Visit_Exception (const PICML::Exception & e);
  virtual void Visit_Member (const PICML::Member & m);
  virtual void Visit_Aggregate (const PICML::Aggregate & a);
  virtual void Visit_Component (const PICML::Component & c);
  virtual void Visit_ConnectorObject (const PICML::ConnectorObject & c);
  virtual void Visit_ComponentFactory (const PICML::ComponentFactory & f);
  virtual void Visit_SwitchedAggregate (const PICML::SwitchedAggregate & s);
  virtual void Visit_Object (const PICML::Object & o);
  virtual void Visit_Event (const PICML::Event & e);
  virtual void Visit_ValueObject (const PICML::ValueObject & v);
  virtual void Visit_FactoryOperation (const PICML::FactoryOperation & op);
  virtual void Visit_ExtendedPort (const PICML::ExtendedPort & p);
  virtual void Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & r);
  virtual void Visit_OnewayOperation (const PICML::OnewayOperation & op);
  virtual void Visit_TwowayOperation (const PICML::TwowayOperation & op);
  virtual void Visit_RequiredRequestPort (const PICML::RequiredRequestPort & op);
  virtual void Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & op);
  virtual void Visit_InEventPort (const PICML::InEventPort & in);
  virtual void Visit_OutEventPort (const PICML::OutEventPort & out);
  virtual void Visit_TemplateParameterValue (const PICML::TemplateParameterValue &);
  virtual void Visit_TemplatePackageInstanceDecl (const PICML::TemplatePackageInstanceDecl &);

  bool has_component (void) const;

  bool has_typesupport (void) const;

private:
  void Visit_FilePackage (const Udm::Object & p);
  void Visit_ObjectByValue (const PICML::ObjectByValue & obv);
  void Visit_MemberType (const PICML::MemberType & m);
  void Visit_NamedType (const PICML::NamedType & n);

  PICML::File get_file (const Udm::Object & obj);
  bool is_visible (const Udm::Object & ref);

  bool has_component_;

  bool has_typesupport_;

  /// Set of forward declard objects.
  fwd_decls_t fwd_decls_;

  /// Set of include files (i.e., objects in other files).
  includes_t includes_;

  /// The current file being processed.
  PICML::File current_file_;

  bool visit_template_module_;
};

#endif  // !defined _IDL_FIND_FORWARD_DECLS_H_
