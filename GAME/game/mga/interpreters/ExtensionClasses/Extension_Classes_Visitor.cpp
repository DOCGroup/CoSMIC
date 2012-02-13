// $Id$

#include "stdafx.h"
#include "Extension_Classes_Visitor.h"

#if !defined (__GAME_INLINE__)
#include "Extension_Classes_Visitor.inl"
#endif

#include "Attribute_Generator.h"
#include "Base_Class_Locator.h"
#include "Class_Definition.h"
#include "Connection_Point_Generator.h"
#include "Containment_Generator.h"
#include "Factory_Method_Generator.h"
#include "Functors.h"
#include "InConnection_Generator.h"
#include "Parent_Generator.h"
#include "RefersTo_Method_Generator.h"

#include "game/mga/Attribute.h"
#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/MetaAttribute.h"
#include "game/mga/MetaAtom.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/Reference.h"
#include "game/mga/RootFolder.h"

#include "boost/bind.hpp"

#include "CCF/CodeGenerationKit/IndentationCxx.hpp"
#include "CCF/CodeGenerationKit/IndentationImplanter.hpp"

#include <iomanip>

namespace GAME
{
namespace Mga
{
/**
 * @struct include_base_classes_t
 *
 * Functor that generates the include statement for a base class. This
 * should only be used to generate include statements in the header file
 * of an extension class.
 */
struct include_base_classes_t
{
  include_base_classes_t (std::ofstream & header)
    : header_ (header)
  {

  }

  void operator () (const Atom & a) const
  {
    this->header_ << include_t (a->path ("/", false) + ".h");
  }

private:
  std::ofstream & header_;
};

/**
 * @struct generate_base_classes_t
 *
 * Functor that generates the include statement for a base class. This
 * should only be used to generate include statements in the header file
 * of an extension class.
 */
struct generate_base_class_t
{
  generate_base_class_t (std::ofstream & header)
    : header_ (header)
  {

  }

  void operator () (const Atom & a) const
  {
    this->header_
      << "," << std::endl
      << "  public virtual " << a->name () << "_Impl";
  }

private:
  std::ofstream & header_;
};

/**
 * @struct generate_bmi_t
 *
 * Functor that generates the include statement for a base class. This
 * should only be used to generate include statements in the header file
 * of an extension class.
 */
struct generate_bmi_t
{
  generate_bmi_t (std::ofstream & header)
    : header_ (header)
  {

  }

  void operator () (const Atom & a) const
  {
    this->header_
      << " ," << std::endl
      << a->name () << "_Impl (ptr)";
  }

private:
  std::ofstream & header_;
};

/**
 * @class Connection_Point_Include_Generator
 *
 * Internal visitor that generates the include statments that appear
 * in the source file. The files that are included are those for object
 * that appear in a different file.
 */
class Connection_Point_Include_Generator : public Visitor
{
public:
  /**
   * Initializing constructor.
   */
  Connection_Point_Include_Generator (FCO_in self,
                                      std::ofstream & source,
                                      std::set <Object> & seen)
    : self_ (self),
      source_ (source),
      seen_ (seen)
  {

  }

  /// Destructor.
  virtual ~Connection_Point_Include_Generator (void)
  {

  }

  /// Visit an Atom element.
  virtual void visit_Atom (Atom_in a)
  {
    if (a->is_equal_to (this->self_))
      return;

    const std::string metaname = a->meta ()->name ();

    if (metaname == "Connector")
    {
      // Get the source connection point.
      std::vector <Connection> src_to_connector;
      a->in_connections ("SourceToConnector", src_to_connector);
      src_to_connector.front ()->src ()->accept (this);

      // Visit the destination connectation point.
      std::vector <Connection> connector_to_dst;
      a->in_connections ("ConnectorToDestination", connector_to_dst);
      connector_to_dst.front ()->dst ()->accept (this);
    }
    else if (this->seen_.find (a) == this->seen_.end ())
    {
      // We can generate an include statement since we have not
      // seen this object before. Make sure we save the object since
      // we don't want to include the same header more than once.
      const std::string path = a->path ("/", false);
      this->source_ << include_t (path + ".h");
      this->seen_.insert (a);
    }
  }

  //
  // visit_Connection
  //
  virtual void visit_Connection (Connection_in c)
  {
    c->dst ()->accept (this);
    c->src ()->accept (this);
  }

  //
  // visit_Reference
  //
  virtual void visit_Reference (Reference_in ref)
  {
    ref->refers_to ()->accept (this);
  }

private:
  /// The current object.
  FCO self_;

  /// The target source file.
  std::ofstream & source_;

  /// Collection of seen objects.
  std::set <Object> & seen_;
};

/**
 * @class Parent_Include_Generator
 */
class Parent_Include_Generator : public Visitor
{
public:
  /**
   * Initializing constructor.
   */
  Parent_Include_Generator (std::ofstream & source, std::set <Object> & seen)
    : source_ (source),
      seen_ (seen)
  {

  }

  /// Destructor.
  virtual ~Parent_Include_Generator (void)
  {

  }

  /// Visit an Atom element.
  virtual void visit_Atom (Atom_in a)
  {
    if (this->seen_.find (a) != this->seen_.end ())
      return;

    // We can generate an include statement since we have not
    // seen this object before. Make sure we save the object since
    // we don't want to include the same header more than once.
    const std::string path = a->path ("/", false);
    this->source_ << include_t (path + ".h");
    this->seen_.insert (a);
  }

  //
  // visit_Connection
  //
  virtual void visit_Connection (Connection_in c)
  {
    c->dst ()->accept (this);
  }

  //
  // visit_Reference
  //
  virtual void visit_Reference (Reference_in ref)
  {
    ref->refers_to ()->accept (this);
  }

private:
  /// The target source file.
  std::ofstream & source_;

  /// Collection of seen objects.
  std::set <Object> & seen_;
};

/**
 * @class Include_Generator
 *
 * Internal visitor that generates the include statments that appear
 * in the source file. The files that are included are those for object
 * that appear in a different file.
 */
class Include_Generator : public Visitor
{
public:
  /**
   * Initializing constructor.
   */
  Include_Generator (FCO_in self, std::ofstream & source)
    : self_ (self),
      source_ (source)
  {

  }

  /// Destructor.
  virtual ~Include_Generator (void)
  {

  }

  /// Visit an Atom element.
  virtual void visit_Atom (Atom_in a)
  {
    // We do not want to process ourself in this case.
    if (this->self_->is_equal_to (a))
      return;

    const std::string metaname = a->meta ()->name ();

    if (metaname == "Connector")
    {
      // The connector is one of the Atom element where we must traverse
      // the AssoicationClass connection to locate the actual FCO that
      // we need to include.
      std::vector <Connection> associations;
      a->in_connections ("AssociationClass", associations);

      Connection association = associations.front ();

      if (association->src ()->is_equal_to (a))
        association->dst ()->accept (this);
      else
        association->src ()->accept (this);
    }
    else if (this->seen_objects_.find (a) == this->seen_objects_.end ())
    {
      // We can generate an include statement since we have not
      // seen this object before. Make sure we save the object since
      // we don't want to include the same header more than once.
      const std::string path = a->path ("/", false);
      this->source_ << include_t (path + ".h");
      this->seen_objects_.insert (a);
    }
  }

  /// Visit a Connection element.
  virtual void visit_Connection (Connection_in c)
  {
    c->dst ()->accept (this);
    c->src ()->accept (this);
  }

  //
  // visit_Reference
  //
  virtual void visit_Reference (Reference_in ref)
  {
    ref->refers_to ()->accept (this);
  }

  //
  // seen_objects
  //
  std::set <Object> & seen_objects (void)
  {
    return this->seen_objects_;
  }

private:
  /// The current object.
  FCO self_;

  /// The target source file.
  std::ofstream & source_;

  /// Collection of seen objects.
  std::set <Object> seen_objects_;
};

//
// Extension_Clases_Visitor
//
Extension_Classes_Visitor::
Extension_Classes_Visitor (const std::string & outdir,
                           const Folder_in root,
                           const std::string & pch_basename,
                           std::set <Object> & generated)
: outdir_ (outdir),
  define_prefix_ (root->name ()),
  pch_basename_ (pch_basename),
  generated_ (generated)
{
  GAME::Utils::normalize (this->define_prefix_);
  std::transform (this->define_prefix_.begin (),
                  this->define_prefix_.end (),
                  this->define_prefix_.begin (),
                  &::toupper);
}

//
// ~Extension_Classes_Visitor
//
Extension_Classes_Visitor::~Extension_Classes_Visitor (void)
{

}

//
// visit_Atom
//
void Extension_Classes_Visitor::visit_Atom (Atom_in atom)
{
  const std::string metaname = atom->meta ()->name ();

  if (metaname == "FCO" ||
      metaname == "Atom" ||
      metaname == "Model" ||
      metaname == "Reference" ||
      metaname == "Set" ||
      metaname == "Connection" ||
      metaname == "Folder")
  {
    // Start a new extension class.
    const std::string basename = this->outdir_ + atom->path ("/");
    const std::string hxx_filename = basename + ".h";
    const std::string cpp_filename = basename + ".cpp";

    this->header_.open (hxx_filename.c_str ());
    this->source_.open (cpp_filename.c_str ());

    if (!this->header_.is_open () || !this->source_.is_open ())
      return;

    this->visit_FCO (atom);
    this->generated_.insert (atom);

    // Close the file handles.
    this->header_.close ();
    this->source_.close ();
  }
}

//
// visit_FCO
//
void Extension_Classes_Visitor::visit_FCO (FCO_in fco)
{
  // Set the indentation implanter for this extension class.
  Indentation::Implanter <Indentation::Cxx, char> header_indent (this->header_);
  Indentation::Implanter <Indentation::Cxx, char> source_indent (this->source_);

  const std::string name = fco->name ();
  const std::string metaname = fco->meta ()->name ();
  const std::string default_base_classname = "::GAME::Mga::" + metaname + "_Impl";
  const std::string project_name = GAME::Utils::normalize (fco->project ().name ());

  bool is_abstract =
    (metaname == "FCO" ||
    (metaname != "Folder" && fco->attribute ("IsAbstract")->bool_value ()));

  bool is_connection = metaname == "Connection";
  bool is_model = metaname == "Model";
  bool is_in_root_folder = fco->attribute ("InRootFolder")->bool_value ();

  this->classname_ = name + "_Impl";

  std::string export_name = project_name;
  std::transform (export_name.begin (),
                  export_name.end (),
                  export_name.begin (),
                  &::toupper);
  export_name += "_Export";

  // Build the class definition.
  Class_Definition clsdef;
  clsdef.build (fco);

  // Let's locate the base classes for this element. If we are able to
  // locate any base class, then we can assume that this extension class
  // is derived from a fundamental type.
  Base_Class_Locator bc_locator (clsdef.base_classes_);
  fco->accept (&bc_locator);

  // Generate the default data members for the type.
  this->header_
    << "// -*- C++ -*-" << std::endl
    << std::endl
    << std::left << std::setw (78) << std::setfill ('=') << "//" << std::endl
    << "/**" << std::endl
    << " * @file    " << name << ".h" << std::endl
    << " *" << std::endl
    << " * $" << "Id" << "$" << std::endl
    << " *" << std::endl
    << " * @author  Alhad Mokashi <amokashi at iupui dot edu>" << std::endl
    << " *          James H. Hill <hillj at cs dot iupui dot edu>" << std::endl
    << " */" << std::endl
    << std::left << std::setw (78) << std::setfill ('=') << "//" << std::endl
    << std::endl;

  // Make sure we construct the correct macro definition name.
  std::string define_name = fco->path ("_");
  std::transform (define_name.begin (),
                  define_name.end (),
                  define_name.begin (),
                  &::toupper);

  this->header_
    << "#ifndef " << define_name << "_H_" << std::endl
    << "#define " << define_name << "_H_" << std::endl
    << std::endl;

  // Include the correct header files for the base classes.
  this->header_ << include_t ("game/mga/" + metaname + ".h");

  std::for_each (clsdef.base_classes_.begin (),
                 clsdef.base_classes_.end (),
                 include_base_classes_t (this->header_));

  this->source_
    << "// $" << "Id" << "$" << std::endl
    << std::endl
    << include_t (this->pch_basename_ + ".h")
    << include_t (name + ".h")
    << std::endl;

  // We need to make sure we include the correct header for accessing
  // the object's attributes.
  std::vector <Connection> has_attributes;
  fco->in_connections ("HasAttribute", has_attributes);

  if (!has_attributes.empty ())
    this->source_ << include_t ("game/mga/Attribute.h");

  this->source_
    << include_t ("game/mga/MetaModel.h")
    << include_t ("game/mga/MetaFolder.h")
    << include_t ("game/mga/Functional_T.h")
    << std::endl;

  if (!is_abstract)
    this->source_ << include_t (project_name + "/Visitor.h");

  // Generate the include statements for this attached FCOs.
  Include_Generator includes (fco, this->source_);
  std::for_each (clsdef.src_to_connector_.begin (),
                 clsdef.src_to_connector_.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &includes));

  std::for_each (clsdef.connector_to_dst_.begin (),
                 clsdef.connector_to_dst_.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &includes));

  std::for_each (clsdef.containment_.begin (),
                 clsdef.containment_.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &includes));

  std::for_each (clsdef.refers_to_.begin (),
                 clsdef.refers_to_.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &includes));

  Connection_Point_Include_Generator cp_includes (fco,
                                                  this->source_,
                                                  includes.seen_objects ());
  std::for_each (clsdef.association_class_.begin (),
                 clsdef.association_class_.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &cp_includes));

  Parent_Include_Generator pig (this->source_, includes.seen_objects ());
  std::for_each (clsdef.containment_.begin (),
                 clsdef.containment_.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &pig));

  if (is_in_root_folder)
    this->header_ << include_t ("game/mga/RootFolder.h");

  // Write the class definition and default methods, such as default
  // constructor, destructor, and _create () method. When writing the
  // create method, we want to make sure that the parents are type-safe.
  const std::string root_name = fco->project ().root_folder ()->name ();
  const std::string base_name = root_name + "/" + project_name;

  this->header_
    << std::endl
    << include_t (base_name + "_fwd.h")
    << include_t (base_name + "_export.h")
    << std::endl
    << "namespace " << project_name
    << "{"
    << "// Forward decl. and type definitions" << std::endl
    << "class " << this->classname_ << ";"
    << "typedef " << this->classname_ << " * " << name << "_in;"
    << "typedef ::GAME::Mga::Smart_Ptr <" << this->classname_ << "> " << name << ";";

  if (!is_abstract)
  {
    this->header_
      << std::endl
      << "// Forward decl." << std::endl
      << "class Visitor;";
  }

  this->header_
    << std::endl
    << "class " << export_name << " " << this->classname_ << " :" << std::endl
    << "  public virtual " << default_base_classname;

  // Write the base classes for this derived class.
  std::for_each (clsdef.base_classes_.begin (),
                 clsdef.base_classes_.end (),
                 generate_base_class_t (this->header_));

  // Determine the tag type for this extension class.
  std::string tag_type = metaname;
  std::transform (tag_type.begin (),
                  tag_type.end (),
                  tag_type.begin (),
                  &::tolower);

  this->header_
    << "{"
    << "public:" << std::endl
    << "/// Tag type of this extension class." << std::endl
    << "typedef ::GAME::Mga::" << tag_type << "_tag_t type_tag;"
    << std::endl
    << "/// Type definition of this class's interface." << std::endl
    << "typedef IMga" << metaname << " interface_type;"
    << std::endl
    << "/// Metaname for this extension class." << std::endl
    << "static const std::string metaname;"
    << std::endl
    << "/// Default constructor" << std::endl
    << this->classname_ << " (void);"
    << std::endl
    << "/// Initializing constructor" << std::endl
    << this->classname_ << " (IMga" << metaname << " * ptr);"
    << std::endl
    << "/// Destructor" << std::endl
    << "virtual ~" << this->classname_ << " (void)"
    << (is_abstract ? " = 0" : "") << ";";

  this->source_
    << std::endl
    << "namespace " << project_name
    << "{"
    << function_header_t ("metaname")
    << "const std::string " << this->classname_ << "::metaname = \"" << name << "\";"
    << std::endl
    << function_header_t (this->classname_)
    << this->classname_ << "::" << this->classname_ << " (void)"
    << "{"
    << "}"
    << function_header_t (this->classname_)
    << this->classname_ << "::"
    << this->classname_ << " (IMga" << metaname << " * ptr)" << std::endl
    << "{"
    << "this->object_ = ptr;"
    << "}"
    << function_header_t ("~" + this->classname_)
    << this->classname_ << "::~"<< this->classname_ << " (void)"
    << "{"
    << "}";

  if (!is_abstract)
  {
    this->header_
      << std::endl
      << "/// Accept a visitor for this project." << std::endl
      << "virtual void accept (::GAME::Mga::Visitor * v);";

    this->source_
      << function_header_t ("accept")
      << "void " << this->classname_ << "::accept (::GAME::Mga::Visitor * v)"
      << "{"
      << "try"
      << "{"
      << "// See if this is a visitor we know." << std::endl
      << "Visitor * this_visitor = dynamic_cast <Visitor *> (v);"
      << "this_visitor->visit_" << name << " (this);"
      << "}"
      << "catch (const std::bad_cast & )"
      << "{"
      << "// Fallback to the standard visit method." << std::endl
      << "v->visit_" << metaname << " (this);"
      << "}"
      << "}";
  }

  if (!is_abstract)
  {
    this->header_
      << std::endl
      << "/**" << std::endl
      << " * @name Factory Methods" << std::endl
      << " */" << std::endl
      << "///@{" << std::endl;

    // Since this is not an abstract class, we can implement the
    // factory methods for it.
    if (is_in_root_folder)
    {
      // This object is contained in the root folder. We need to
      // define and implement the factory method bound to the root
      // folder of the project.
      this->header_
        << "static " << name << " _create (const ::GAME::Mga::RootFolder_in parent);";

      // Implement the root folder creation function.
      this->source_
        << function_header_t ("_create")
        << name << " " << this->classname_
        << "::_create (const ::GAME::Mga::RootFolder_in parent)"
        << "{"
        << "return ::GAME::Mga::create_root_object <"
        << name << "> (parent, " << this->classname_ << "::metaname);"
        << "}";
    }

    // Let's generate the remaining factory methods for this object so
    // we are able to actually create it. ;-)
    Factory_Method_Generator factory_gen (fco,
                                          this->classname_,
                                          this->header_,
                                          this->source_);

    std::for_each (clsdef.containment_.begin (),
                   clsdef.containment_.end (),
                   boost::bind (&Connection::impl_type::accept,
                                boost::bind (&Connection::get, _1),
                                &factory_gen));

    this->header_
      << "///@}"
      << std::endl;
  }

  if (is_connection)
  {
    // Generate the connection points for this class.
    Connection_Point_Generator cp_gen (fco,
                                       this->classname_,
                                       this->header_,
                                       this->source_);

    std::for_each (clsdef.association_class_.begin (),
                   clsdef.association_class_.end (),
                   boost::bind (&Connection::impl_type::accept,
                                boost::bind (&Connection::get, _1),
                                &cp_gen));
  }

  if (!has_attributes.empty ())
  {
    // Let's generate concrete methods for accessing the attributes.
    this->header_
      << std::endl
      << "/**" << std::endl
      << " * @name Attribute Methods" << std::endl
      << " */" << std::endl
      << "///@{" << std::endl;

    Attribute_Generator attr_gen (this->classname_, this->header_, this->source_);
    std::for_each (has_attributes.begin (),
                   has_attributes.end (),
                   boost::bind (&Connection::impl_type::accept,
                                boost::bind (&Connection::get, _1),
                                &attr_gen));

    this->header_
      << "///@}"
      << std::endl;
  }

  // Let's the write in_connection methods for this extension class.
  InConnection_Generator in_connection_gen (this->classname_, this->header_, this->source_);
  std::for_each (clsdef.src_to_connector_.begin (),
                 clsdef.src_to_connector_.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &in_connection_gen));

  std::for_each (clsdef.connector_to_dst_.begin (),
                 clsdef.connector_to_dst_.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &in_connection_gen));

  if (is_model)
  {
    this->header_
      << std::endl
      << "/**" << std::endl
      << " * @name Containment Methods" << std::endl
      << " */" << std::endl
      << "///@{" << std::endl;

    // Let's write the containment methods. This code is only valid
    // when dealing with a Model element.
    Containment_Generator containment_gen (fco,
                                           this->classname_,
                                           this->header_,
                                           this->source_);

    std::for_each (clsdef.containment_.begin (),
                   clsdef.containment_.end (),
                   boost::bind (&Connection::impl_type::accept,
                                boost::bind (&Connection::get, _1),
                                &containment_gen));

    this->header_
      << "///@}"
      << std::endl;
  }

  this->header_
    << std::endl
    << "/**" << std::endl
    << " * @name Parent Methods" << std::endl
    << " */" << std::endl
    << "///@{" << std::endl;

  if (is_in_root_folder)
  {
    // Write the parent method for getting the root folder.
    this->header_
      << "::GAME::Mga::RootFolder parent_RootFolder (void) const;";

    this->source_
      << "::GAME::Mga::RootFolder " << this->classname_ << "::parent_RootFolder (void) const"
      << "{"
      << "return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);"
      << "}";
  }

  // Let's generate the remaining parent methods.
  Parent_Generator parent_gen (fco,
                               this->classname_,
                               this->header_,
                               this->source_);

  std::for_each (clsdef.containment_.begin (),
                 clsdef.containment_.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &parent_gen));

  this->header_
    << "///@}"
    << std::endl;

  // Let's generate the methods for a reference.
  this->header_
    << std::endl
    << "/**" << std::endl
    << " * @name Reference Methods" << std::endl
    << " */" << std::endl
    << "///@{" << std::endl;

  RefersTo_Method_Generator refers_to_gen (fco,
                                           this->classname_,
                                           this->header_,
                                           this->source_);

  std::for_each (clsdef.refers_to_.begin (),
                 clsdef.refers_to_.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &refers_to_gen));

  this->header_
    << "///@}"
    << std::endl;

  // End the class definition for this extension class.
  this->header_
    << "};"
    << "}"
    << "#endif" << std::endl;

  this->source_
    << "}";
}

//
// visit_Folder
//
void Extension_Classes_Visitor::visit_RootFolder (RootFolder_in folder)
{
  const std::string path = this->outdir_ + "/" + folder->name ();
  GAME::Utils::create_path (path);

  this->visit_Folder_i (folder);
}

//
// visit_Folder
//
void Extension_Classes_Visitor::visit_Folder (Folder_in folder)
{
  // Create the directory for this model, and its elements.
  const std::string path = this->outdir_ + folder->path ("/");
  GAME::Utils::create_path (path);

  this->visit_Folder_i (folder);
}

//
// visit_Folder_i
//
void Extension_Classes_Visitor::visit_Folder_i (Folder_in folder)
{
  // collect all the paradigm sheets and traverse them.
  std::vector <FCO> paradigm_sheets;
  folder->children (paradigm_sheets);

  // visit all the paradigm sheets.
  std::for_each (paradigm_sheets.begin (),
                 paradigm_sheets.end (),
                 boost::bind (&FCO::impl_type::accept,
                              boost::bind (&FCO::get, _1),
                              this));

  // Visit all the SheetFolder elements in the model.
  std::vector <Folder> folders;
  folder->children ("SheetFolder", folders);

  std::for_each (folders.begin (),
                 folders.end (),
                 boost::bind (&Folder::impl_type::accept,
                              boost::bind (&Folder::get, _1),
                              this));
}

//
// visit_Model
//
void Extension_Classes_Visitor::visit_Model (Model_in model)
{
  // Create the directory for this model, and its elements.
  const std::string path = this->outdir_ + model->path ("/");
  GAME::Utils::create_path (path);

  // get all the children of this sheet and call the visitor.
  std::vector <FCO> fcos;
  model->children (fcos);

  std::for_each (fcos.begin (),
                 fcos.end (),
                 boost::bind (&FCO::impl_type::accept,
                              boost::bind (&FCO::get, _1),
                              this));
}

//
// generate_connection_points
//
void Extension_Classes_Visitor::generate_connection_points (FCO_in fco)
{
  std::vector <Connection> association_class;
  if (0 == fco->in_connections ("AssociationClass", association_class))
    return;

  // Locate the connector in the connection.
  Connection conn = association_class.front ();
  FCO connector = conn->dst ()->is_equal_to (fco) ? conn->src () : conn->dst ();

  // Locate the source connection point method.
  std::vector <Connection> in_connections;
  connector->in_connections ("SourceToConnector", in_connections);

  conn = in_connections.front ();
  std::string rolename = conn->attribute ("srcRolename")->string_value ();
  std::string connpt_type = conn->src ()->name ();

  // Write the source connection point method.
  this->header_
    << std::endl
    << "/// Get the " << rolename << " connection point." << std::endl
    << connpt_type << " " << rolename << " (void);";

  this->source_
    << function_header_t (rolename)
    << connpt_type << " " << this->classname_ << "::" << rolename << " (void)"
    << "{"
    << "GAME::Mga::FCO target = this->connection_point (\"" << rolename << "\")->target ();"
    << "return " << connpt_type << "::_narrow (target);"
    << "}";

  // Reset the container.
  in_connections.clear ();

  // Locate the destination connection point method.
  connector->in_connections ("ConnectorToDestination", in_connections);

  conn = in_connections.front ();
  rolename = conn->attribute ("dstRolename")->string_value ();
  connpt_type = conn->dst ()->name ();

  // Write the destination connection point method.
  this->header_
    << std::endl
    << "/// Get the " << rolename << " connection point." << std::endl
    << connpt_type << " " << rolename << " (void);";

  this->source_
    << function_header_t (rolename)
    << connpt_type << " " << this->classname_ << "::" << rolename << " (void)"
    << "{"
    << "GAME::Mga::FCO target = this->connection_point (\"" << rolename << "\")->target ();"
    << "return " << connpt_type << "::_narrow (target);"
    << "}";
}

//
// get_instance_path
//
std::string Extension_Classes_Visitor::get_instance_path (FCO_in fco)
{
  // check if the fco is a reference. if not the return the fco's path
  // and if yes the return the path of the referred element.
  std::string path, meta_name = fco->meta ()->name ();

  if ((meta_name.length () > 5) &&
      (meta_name.substr ((meta_name.length () - 5), 5) == "Proxy"))
  {
    Reference ref = Reference::_narrow (fco);
    FCO refers_to = ref->refers_to ();

    path = refers_to->path ("/", false);
  }
  else
  {
    path = fco->path ("/", false);
  }

  return path.erase (0, (path.find_first_of ("/") + 1));
}

}
}
