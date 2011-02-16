// $Id$

#include "stdafx.h"
#include "Extension_Classes_Visitor.h"

#if !defined (__GAME_INLINE__)
#include "Extension_Classes_Visitor.inl"
#endif

#include "Attribute_Generator.h"
#include "Base_Class_Locator.h"
#include "Containment_Generator.h"
#include "Factory_Method_Generator.h"
#include "Functors.h"
#include "InConnection_Generator.h"
#include "Parent_Generator.h"

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
      << " ," << std::endl
      << a->name () << "_Impl";
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
    if (c->src ()->is_equal_to (this->self_))
      c->dst ()->accept (this);
    else
      c->src ()->accept (this);
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
    const std::string basename = this->outdir_ + "/" + atom->name ();
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

  // Let's locate the base classes for this element. If we are able to
  // locate any base class, then we can assume that this extension class
  // is derived from a fundamental type.
  std::set <Atom> base_classes;
  Base_Class_Locator bc_locator (base_classes);
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
  std::string define_name = name;
  std::transform (define_name.begin (),
                  define_name.end (),
                  define_name.begin (),
                  &::toupper);

  this->header_
    << "#ifndef _" << this->define_prefix_ << "_" << define_name << "_H_" << std::endl
    << "#define _" << this->define_prefix_ << "_" << define_name << "_H_" << std::endl
    << std::endl;

  // Include the correct header files for the base classes.
  if (base_classes.empty ())
    this->header_ << include_t ("game/mga/" + metaname + ".h");
  else
    std::for_each (base_classes.begin (),
                   base_classes.end (),
                   include_base_classes_t (this->header_));

  this->source_
    << "// $" << "Id" << "$" << std::endl
    << std::endl
    << include_t (this->pch_basename_ + ".h")
    << include_t (name + ".h")
    << std::endl
    << include_t ("game/mga/MetaModel.h")
    << include_t ("game/mga/MetaFolder.h")
    << include_t ("game/mga/Functional_T.h")
    << std::endl;

  // First, we need to gather all connections from this FCO that could
  // lead to another FCO that must be included in the header file.
  std::vector <Connection> src_to_connector;
  fco->in_connections ("SourceToConnector", src_to_connector);

  std::vector <Connection> connector_to_dst;
  fco->in_connections ("ConnectorToDestination", connector_to_dst);

  std::vector <Connection> containment;
  fco->in_connections ("Containment", containment);
  fco->in_connections ("FolderContainment", containment);

  std::set <Connection> unique_containment (containment.begin (),
                                            containment.end ());

  // Generate the include statements for this attached FCOs.
  Include_Generator includes (fco, this->source_);
  std::for_each (src_to_connector.begin (),
                 src_to_connector.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &includes));

  std::for_each (connector_to_dst.begin (),
                 connector_to_dst.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &includes));

  std::for_each (containment.begin (),
                 containment.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &includes));

  if (is_in_root_folder)
    this->header_ << include_t ("game/mga/RootFolder.h");

  // Write the class definition and default methods, such as default
  // constructor, destructor, and _create () method. When writing the
  // create method, we want to make sure that the parents are type-safe.
  this->header_
    << std::endl
    << include_t (project_name + "_fwd.h")
    << include_t (project_name + "_export.h")
    << std::endl
    << "namespace " << project_name
    << "{"
    << "// Forward decl. and type definitions" << std::endl
    << "class " << this->classname_ << ";"
    << "typedef " << this->classname_ << " * " << name << "_in;"
    << "typedef ::GAME::Mga::Smart_Ptr <" << this->classname_ << "> " << name << ";"
    << std::endl
    << "class " << export_name << " " << this->classname_ << " : ";

  // Write the base classes for this derived class.
  if (base_classes.empty ())
  {
    this->header_ << "public " << default_base_classname;
  }
  else
  {
    this->header_ << "public " << (*base_classes.begin ())->name () << "_Impl";

    std::for_each (++ base_classes.begin (),
                   base_classes.end (),
                   generate_base_class_t (this->header_));
  }

  // Determine the tag type for this extension class.
  std::string tag_type = metaname;
  tag_type[0] = ::tolower (tag_type[0]);

  this->header_
    << "{"
    << "public:" << std::endl
    << "/// Tag type of this extension class." << std::endl
    << "typedef ::GAME::Mga::" << tag_type << "_tag_t tag_type;"
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
    << ": ";

  // Write the base member initialiation section. This should include
  // invoking the constructor on each base class for this extension
  // class definition.
  if (base_classes.empty ())
  {
    this->source_ << default_base_classname << " (ptr)";
  }
  else
  {
    this->source_ << (*base_classes.begin ())->name () << "_Impl (ptr)";

    std::for_each (++ base_classes.begin (),
                   base_classes.end (),
                   generate_bmi_t (this->source_));
  }

  this->source_
    << "{"
    << "}"
    << function_header_t ("~" + this->classname_)
    << this->classname_ << "::~"<< this->classname_ << " (void)"
    << "{"
    << "}";

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

    std::for_each (containment.begin (),
                   containment.end (),
                   boost::bind (&Connection::impl_type::accept,
                                boost::bind (&Connection::get, _1),
                                &factory_gen));

    this->header_
      << "///@}"
      << std::endl;
  }

  if (is_connection)
    this->generate_connection_points (fco);

  // Let's write the attributes for this extension class.
  std::vector <Connection> has_attributes;
  fco->in_connections ("HasAttribute", has_attributes);

  if (!has_attributes.empty ())
  {
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
  std::for_each (src_to_connector.begin (),
                 src_to_connector.end (),
                 boost::bind (&Connection::impl_type::accept,
                              boost::bind (&Connection::get, _1),
                              &in_connection_gen));

  std::for_each (connector_to_dst.begin (),
                 connector_to_dst.end (),
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

    std::for_each (containment.begin (),
                   containment.end (),
                   boost::bind (&Connection::impl_type::accept,
                                boost::bind (&Connection::get, _1),
                                &containment_gen));
    this->header_
      << "///@}"
      << std::endl;
  }
  else
  {
    this->header_
      << std::endl
      << "/**" << std::endl
      << " * @name Parent Methods" << std::endl
      << " */" << std::endl
      << "///@{" << std::endl;

    // We are going to generate the parent method for this class.
    Parent_Generator parent_gen (this->classname_,
                                 this->header_,
                                 this->source_);

    std::for_each (containment.begin (),
                   containment.end (),
                   boost::bind (&Connection::impl_type::accept,
                                boost::bind (&Connection::get, _1),
                                &parent_gen));

    this->header_
      << "///@}"
      << std::endl;
  }

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
  this->visit_Folder (folder);
}

//
// visit_Folder
//
void Extension_Classes_Visitor::visit_Folder (Folder_in folder)
{
  // Save the current output directory.
  std::string prev_outdir = this->outdir_;

  // Create the directory for this model, and its elements.
  this->outdir_ += "/" + GAME::Utils::normalize (folder->name ());
  GAME::Utils::create_path (this->outdir_);

  // collect all the paradigm sheets and traverse them.
  std::vector <Model> paradigm_sheets;
  folder->children ("ParadigmSheet", paradigm_sheets);

  // visit all the paradigm sheets.
  std::for_each (paradigm_sheets.begin (),
                 paradigm_sheets.end (),
                 boost::bind (&Model::impl_type::accept,
                              boost::bind (&Model::get, _1),
                              this));

  // Visit all the SheetFolder elements in the model.
  std::vector <GAME::Mga::Folder> folders;
  folder->children ("SheetFolder", folders);

  std::for_each (folders.begin (),
                 folders.end (),
                 boost::bind (&Folder::impl_type::accept,
                              boost::bind (&Folder::get, _1),
                              this));

  this->outdir_ = prev_outdir;
}

//
// visit_Model
//
void Extension_Classes_Visitor::visit_Model (Model_in model)
{
  // Save the current output directory.
  std::string prev_outdir = this->outdir_;

  // Create the directory for this model, and its elements.
  this->outdir_ += "/" + GAME::Utils::normalize (model->name ());
  GAME::Utils::create_path (this->outdir_);

  // get all the children of this sheet and call the visitor.
  std::vector <FCO> fcos;
  model->children (fcos);

  std::for_each (fcos.begin (),
                 fcos.end (),
                 boost::bind (&FCO::impl_type::accept,
                              boost::bind (&FCO::get, _1),
                              this));

  // Restore the previous directory.
  this->outdir_ = prev_outdir;
}

//
// generate_connection_points
//
void Extension_Classes_Visitor::generate_connection_points (FCO_in fco)
{
  std::vector <Connection> association_class;
  fco->in_connections ("AssociationClass", association_class);

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
