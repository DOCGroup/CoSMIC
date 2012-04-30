// $Id$

#include "StdAfx.h"
#include "Object_Class_Definition.h"

#if !defined (__GAME_INLINE__)
#include "Object_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#include "Functors.h"
#include "Proxy_Visitor.h"

#include "game/mga/Atom.h"
#include "game/mga/Attribute.h"
#include "game/mga/Connection.h"
#include "game/mga/MetaAtom.h"
#include "game/mga/Reference.h"
#include "game/mga/Project.h"

#include "boost/bind.hpp"
#include "boost/lambda/lambda.hpp"
#include "boost/lambda/bind.hpp"

#include <algorithm>
#include <iomanip>

///////////////////////////////////////////////////////////////////////////////
// Base_Class_Locator

/**
 * @class Base_Class_Locator
 */
class Base_Class_Locator : public Proxy_Visitor
{
public:
  Base_Class_Locator (std::set <GAME::Mga::Atom> & base)
    : base_ (base)
  {

  }

  virtual void visit_Atom (GAME::Mga::Atom_in a)
  {
    const std::string metaname = a->meta ()->name ();

    if (metaname == "Inheritance")
    {
      // Locate all the DerivedInheritance connections for this element.
      std::vector <GAME::Mga::Connection> derived_conns;
      a->in_connections ("BaseInheritance", derived_conns);

      std::for_each (GAME::Mga::make_impl_iter (derived_conns.begin ()),
                     GAME::Mga::make_impl_iter (derived_conns.end ()),
                     boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, this));
    }
    else
    {
      // Locate all the BaseInheritance connections for this element.
      std::vector <GAME::Mga::Connection> base_conns;
      a->in_connections ("DerivedInheritance", base_conns);

      std::for_each (GAME::Mga::make_impl_iter (base_conns.begin ()),
                     GAME::Mga::make_impl_iter (base_conns.end ()),
                     boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, this));
    }
  }

  //
  // visit_Connection
  //
  void Base_Class_Locator::visit_Connection (GAME::Mga::Connection_in c)
  {
    const std::string metaname = c->meta ()->name ();
    GAME::Mga::FCO src = c->src ();

    // Make sure we have located the atom, and walked through
    // all the proxy elements.
    while (src->type () == OBJTYPE_REFERENCE)
      src = GAME::Mga::Reference::_narrow (src)->refers_to ();

    // We need to save the destination point if it is the actual
    // derived class.
    if (metaname == "BaseInheritance")
    {
      this->base_.insert (GAME::Mga::Atom::_narrow (src));
    }
    else if (metaname == "DerivedInheritance")
    {
      // Visit the Inheritance model element.
      src->accept (this);
    }
  }

private:
  std::set <GAME::Mga::Atom> & base_;
};

///////////////////////////////////////////////////////////////////////////////
// Parent_Visitor

/**
 * @class Parent_Visitor
 */
class Parent_Visitor : public Proxy_Visitor
{
public:
  //
  // Parent_Visitor
  //
  Parent_Visitor (GAME::Mga::FCO_in child, std::set <GAME::Mga::Atom> & parents)
    : child_ (child),
      parents_ (parents)
  {

  }

  //
  // visit_Atom
  //
  void visit_Atom (GAME::Mga::Atom_in item)
  {
    if (!this->child_->is_equal_to (item))
      this->parents_.insert (item);
  }

  //
  // visit_Connection
  //
  void visit_Connection (GAME::Mga::Connection_in item)
  {
    item->dst ()->accept (this);
  }

private:
  GAME::Mga::FCO_in child_;
  std::set <GAME::Mga::Atom> & parents_;
};

///////////////////////////////////////////////////////////////////////////////
// gen_base_class

/**
 * @struct gen_base_class
 */
struct gen_base_class
{
  gen_base_class (std::ostream & hfile)
    : hfile_ (hfile)
  {

  }

  void operator () (GAME::Mga::Atom_in item)
  {
    this->hfile_
      << "," << std::endl
      << "  public virtual " << item->name () << "_Impl";
  }

private:
  std::ostream & hfile_;
};

///////////////////////////////////////////////////////////////////////////////
// gen_include

/**
 * @struct gen_base_class
 */
struct gen_include
{
  gen_include (std::ostream & hfile)
    : hfile_ (hfile)
  {

  }

  void operator () (GAME::Mga::Atom_in item)
  {
    this->hfile_ << include_t (item->path ("/", false) + ".h");
  }

private:
  std::ostream & hfile_;
};

///////////////////////////////////////////////////////////////////////////////
// Object_Class_Definition

//
// build
//
void Object_Class_Definition::build (GAME::Mga::FCO_in fco)
{
  if (this->obj_.is_nil ())
  {
    // Store the class definition's object.
    this->obj_ = fco;

    // Store information about the model element.
    this->name_ = fco->name ();
    bool stop = this->name_ == "dw_writerdatalifecycle_Connection";

    this->metaname_ = fco->meta ()->name ();
    this->classname_ = this->name_ + "_Impl";
    this->default_base_classname_ = "::GAME::Mga::" + this->metaname_ + "_Impl";
    this->in_root_folder_ = fco->attribute ("InRootFolder")->bool_value ();

    this->is_abstract_ =
      (this->metaname_ == "FCO" ||
      (this->metaname_ != "Folder" && fco->attribute ("IsAbstract")->bool_value ()));
  }

  // Locate all the base classes for this FCO.
  Base_Class_Locator base_class_locator (this->base_classes_);
  fco->accept (&base_class_locator);

  // Gather all this model elements parents.
  this->get_parents (fco, this->parents_);

  // Get the parents of the base classes.
  std::for_each (GAME::Mga::make_impl_iter (this->base_classes_.begin ()),
                 GAME::Mga::make_impl_iter (this->base_classes_.end ()),
                 boost::bind (&Object_Class_Definition::get_parents,
                              this,
                              _1,
                              boost::ref (this->base_parents_)));

  if (fco->type () != OBJTYPE_REFERENCE)
  {
    // There could be proxy elements in the metamodel. We therefore
    // need to gather all of them and continue building the class
    // definition as if they are this FCO object.
    using GAME::Mga::Iterator;
    using GAME::Mga::Reference;

    Iterator <Reference> iter = fco->referenced_by ();
    std::for_each (GAME::Mga::make_impl_iter (iter),
                   GAME::Mga::make_impl_iter (iter.make_end ()),
                   boost::bind (&Class_Definition::build, this, _1));
  }
}

//
// get_parents
//
void Object_Class_Definition::
get_parents (GAME::Mga::FCO_in item, std::set <GAME::Mga::Atom> & parents)
{
  Parent_Visitor parent_visitor (this->obj_, parents);

  // Gather all this model elements parents.
  std::vector <GAME::Mga::Connection> containment;
  item->in_connections ("Containment", containment);

  std::for_each (GAME::Mga::make_impl_iter (containment.begin ()),
                 GAME::Mga::make_impl_iter (containment.end ()),
                 boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, &parent_visitor));

  // Gather all this model elements folder parents.
  std::vector <GAME::Mga::Connection> folder_containment;
  item->in_connections ("FolderContainment", folder_containment);

  std::for_each (GAME::Mga::make_impl_iter (folder_containment.begin ()),
                 GAME::Mga::make_impl_iter (folder_containment.end ()),
                 boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, &parent_visitor));

  if (item->type () != OBJTYPE_REFERENCE)
  {
    // There could be proxy elements in the metamodel. We therefore
    // need to gather all of them and continue building the class
    // definition as if they are this FCO object.
    using GAME::Mga::Iterator;
    using GAME::Mga::Reference;

    Iterator <Reference> iter = item->referenced_by ();
    std::for_each (GAME::Mga::make_impl_iter (iter),
                   GAME::Mga::make_impl_iter (iter.make_end ()),
                   boost::bind (&Object_Class_Definition::get_parents,
                                this,
                                _1,
                                boost::ref (parents)));
  }
}

//
// generate
//
void Object_Class_Definition::generate (const Generation_Context & ctx)
{
  using GAME::Mga::Atom;
  using GAME::Mga::Atom_Impl;

  // Write the class definition.
  namespace lambda = boost::lambda;

  // Make sure we construct the correct macro definition name.
  std::string define_name = this->obj_->path ("_");
  std::transform (define_name.begin (),
                  define_name.end (),
                  define_name.begin (),
                  &::toupper);

  GAME::Mga::Project project = this->obj_->project ();
  const std::string project_name = project.name ();
  const std::string root_name = project.root_folder ()->name ();
  const std::string base_name = root_name + "/" + project_name;

  // Write the start content of each file.
  ctx.hfile_
    << "// -*- C++ -*-" << std::endl
    << std::endl
    << std::left << std::setw (78) << std::setfill ('=') << "//" << std::endl
    << "/**" << std::endl
    << " * @file    " << this->name_ << ".h" << std::endl
    << " *" << std::endl
    << " * $" << "Id" << "$" << std::endl
    << " *" << std::endl
    << " * @author  Alhad Mokashi <amokashi at iupui dot edu>" << std::endl
    << " *          James H. Hill <hillj at cs dot iupui dot edu>" << std::endl
    << " */" << std::endl
    << std::left << std::setw (78) << std::setfill ('=') << "//" << std::endl
    << std::endl
    << "#ifndef " << define_name << "_H_" << std::endl
    << "#define " << define_name << "_H_" << std::endl
    << std::endl
    << include_t (base_name + "_fwd.h")
    << include_t (root_name + "/" + ctx.export_filename_)
    << std::endl;

  ctx.sfile_
    << "// $" << "Id" << "$" << std::endl
    << std::endl
    << include_t (ctx.pch_basename_ + ".h")
    << include_t (this->name_ + ".h")
    << std::endl
    << "#if !defined (__GAME_INLINE__)" << std::endl
    << include_t (this->name_ + ".inl")
    << "#endif" << std::endl
    << std::endl
    << include_t (root_name + "/Visitor.h");

  // Write the include files for each of the used objects.
  std::set <Atom> include_files;
  this->get_includes (include_files);

  std::for_each (GAME::Mga::make_impl_iter (include_files.begin ()),
                 GAME::Mga::make_impl_iter (include_files.end ()),
                 gen_include (ctx.sfile_));

  std::for_each (GAME::Mga::make_impl_iter (this->base_classes_.begin ()),
                 GAME::Mga::make_impl_iter (this->base_classes_.end ()),
                 gen_include (ctx.hfile_));

  if (this->in_root_folder_)
    ctx.hfile_ << include_t ("game/mga/RootFolder.h");

  ctx.hfile_
    << include_t ("game/mga/" + this->metaname_ + ".h");

  ctx.ifile_
    << "// -*- C++ -*-" << std::endl
    << "// $" << "Id" << "$" << std::endl
    << std::endl;

  if (!this->is_abstract_)
  {
    ctx.sfile_
      << include_t ("game/mga/Functional_T.h")
      << include_t ("game/mga/MetaModel.h")
      << include_t ("game/mga/MetaFolder.h")
      << std::endl;
  }

  // Begin the namespace for the object type.

  ctx.hfile_
    << std::endl
    << "namespace " << project_name
    << "{"
    << "// Forward decl. and type definitions" << std::endl
    << "class " << this->classname_ << ";"
    << "typedef " << this->classname_ << " * " << this->name_ << "_in;"
    << "typedef ::GAME::Mga::Smart_Ptr < " << this->classname_ << " > " << this->name_ << ";";

  if (!this->is_abstract_)
  {
    ctx.hfile_
      << std::endl
      << "// Forward decl." << std::endl
      << "class Visitor;";
  }

  ctx.sfile_
    << std::endl
    << "namespace " << project_name
    << "{";

  ctx.ifile_
    << "namespace " << project_name
    << "{";

  ctx.hfile_
    << std::endl
    << "/**" << std::endl
    << " * @class " << this->classname_ << std::endl
    << " *" << std::endl
    << " * Implementation for the " << this->name_ << " model element." << std::endl
    << " */" << std::endl
    << "class " << ctx.export_macro_ << " " << this->classname_ << " :" << std::endl
    << "  public virtual " << this->default_base_classname_;

  // Write the base classes for this derived class.
  typedef std::string (Atom_Impl::*GET_NAME_METHOD) (void) const;
  std::for_each (GAME::Mga::make_impl_iter (this->base_classes_.begin ()),
                 GAME::Mga::make_impl_iter (this->base_classes_.end ()),
                 gen_base_class (ctx.hfile_));

  // Determine the tag type for this extension class.
  std::string tag_type = this->metaname_;
  std::transform (tag_type.begin (),
                  tag_type.end (),
                  tag_type.begin (),
                  &::tolower);

  ctx.hfile_
    << "{"
    << "public:" << std::endl
    << "/// Tag type of this extension class." << std::endl
    << "typedef ::GAME::Mga::" << tag_type << "_tag_t type_tag;"
    << std::endl
    << "/// Type definition of this class's interface." << std::endl
    << "typedef IMga" << this->metaname_ << " interface_type;"
    << std::endl
    << "/// Metaname for this extension class." << std::endl
    << "static const std::string metaname;";

  ctx.sfile_
    << function_header_t ("metaname")
    << "const std::string " << this->classname_ << "::metaname (\"" << this->name_ << "\");"
    << std::endl;

  if (!this->is_abstract_)
  {
    // Since this is not an abstract class, we can implement the
    // factory methods for it.
    ctx.hfile_
      << std::endl
      << "/**" << std::endl
      << " * @name Factory Methods" << std::endl
      << " */" << std::endl
      << "///@{" << std::endl;

    if (this->in_root_folder_)
    {
      // This object is contained in the root folder. We need to
      // define and implement the factory method bound to the root
      // folder of the project.
      ctx.hfile_
        << "static " << this->name_ << " _create (const ::GAME::Mga::RootFolder_in parent);";

      // Implement the root folder factory method.
      ctx.sfile_
        << function_header_t ("_create (const ::GAME::Mga::RootFolder_in)")
        << this->name_ << " " << this->classname_
        << "::_create (const ::GAME::Mga::RootFolder_in parent)"
        << "{"
        << "return ::GAME::Mga::create_root_object <"
        << this->name_ << "> (parent, " << this->classname_ << "::metaname);"
        << "}";
    }

    // Write the factory method for each parent element.
    std::for_each (GAME::Mga::make_impl_iter (this->parents_.begin ()),
                   GAME::Mga::make_impl_iter (this->parents_.end ()),
                   boost::bind (&Object_Class_Definition::generate_factory_method,
                                this,
                                boost::ref (ctx),
                                _1));

    // Write the factory method for each base class's parent element.
    std::for_each (GAME::Mga::make_impl_iter (this->base_parents_.begin ()),
                   GAME::Mga::make_impl_iter (this->base_parents_.end ()),
                   boost::bind (&Object_Class_Definition::generate_factory_method,
                                this,
                                boost::ref (ctx),
                                _1));

    ctx.hfile_
      << "///@}"
      << std::endl;
  }

  // Write the default constructor/destructor for the object.
  ctx.hfile_
    << std::endl
    << "// Default constructor." << std::endl
    << this->classname_ << " (void);"
    << std::endl
    << "// Initializing constructor." << std::endl
    << this->classname_ << " (IMga" << this->metaname_ << " * ptr);"
    << std::endl
    << "// Destructor." << std::endl
    << "virtual ~" << this->classname_ << " (void)"
    << (this->is_abstract_ ? " = 0" : "") << ";";

  ctx.ifile_
    << function_header_t (this->classname_)
    << ctx.inline_ << " "
    << this->classname_ << "::" << this->classname_ << " (void)"
    << "{"
    << "}"
    << function_header_t (this->classname_)
    << ctx.inline_ << " "
    << this->classname_ << "::"
    << this->classname_ << " (IMga" << this->metaname_ << " * ptr)" << std::endl
    << "{"
    << "this->object_ = ptr;"
    << "}"
    << function_header_t ("~" + this->classname_)
    << ctx.inline_ << " "
    << this->classname_ << "::~"<< this->classname_ << " (void)"
    << "{"
    << "}";

  if (!this->is_abstract_)
  {
    // Since we can allocate the implementation for this model element,
    // we can also visit it. This means that we need to add a visit
    // method to the implementation.
    ctx.hfile_
      << std::endl
      << "/// Accept a visitor for this model element." << std::endl
      << "virtual void accept (::GAME::Mga::Visitor * v);";

    ctx.sfile_
      << function_header_t ("accept")
      << "void " << this->classname_ << "::accept (::GAME::Mga::Visitor * v)"
      << "{"
      << "// See if this is a visitor we know." << std::endl
      << "Visitor * this_visitor = dynamic_cast <Visitor *> (v);"
      << std::endl
      << "if (0 != this_visitor)" << std::endl
      << "  this_visitor->visit_" << this->name_ << " (this);"
      << "else" << std::endl
      << "  v->visit_" << this->metaname_ << " (this);"
      << "}";
  }

  // Write the parent accessor methods.
  ctx.hfile_
    << std::endl
    << "/**" << std::endl
    << " * @name Parent Methods" << std::endl
    << " */" << std::endl
    << "///@{" << std::endl;

  if (this->in_root_folder_)
  {
    // This object is contained in the root folder. We need to
    // define and implement the factory method bound to the root
    // folder of the project.
    ctx.hfile_
      << "::GAME::Mga::RootFolder parent_RootFolder (void);";

    // Implement the root folder factory method.
    ctx.sfile_
      << function_header_t ("parent_RootFolder (void)")
      << "::GAME::Mga::RootFolder " << this->classname_ << "::parent_RootFolder (void)"
      << "{"
      << "return ::GAME::Mga::RootFolder::_narrow (this->parent ());"
      << "}";
  }

  // Write the factory method for each parent element.
  std::for_each (GAME::Mga::make_impl_iter (this->parents_.begin ()),
                 GAME::Mga::make_impl_iter (this->parents_.end ()),
                 boost::bind (&Object_Class_Definition::generate_parent_method,
                              this,
                              boost::ref (ctx),
                              _1));

  ctx.hfile_
    << "///@}"
    << std::endl;

  // We have reached the point where we need to let all the other
  // classes definitions generate their required methods. So, let's
  // pass control to them.
  this->generate_definition (ctx);

  // End the class definition.
  ctx.hfile_
    << "};";

  // Write the end content of each file.

  ctx.hfile_
    << "}"
    << "#if defined (__GAME_INLINE__)" << std::endl
    << include_t (this->name_ + ".inl")
    << "#endif" << std::endl
    << std::endl
    << "#endif  // !defined " << define_name << std::endl;

  ctx.sfile_
    << "}";

  ctx.ifile_
    << "}";
}

//
// generate_factory_method
//
void Object_Class_Definition::
generate_factory_method (const Generation_Context & ctx, GAME::Mga::Atom_in item)
{
  const std::string parent_type = item->meta ()->name ();
  const std::string parent = item->name ();
  const std::string method = parent_type == "Model" ? "create_object" : "create_root_object";

  ctx.hfile_
    << "static " << this->name_ << " _create (const " << parent << "_in parent);";

  ctx.sfile_
    << function_header_t ("_create (const " + parent + "_in)")
    << this->name_ << " " << this->classname_ << "::_create (const " << parent << "_in parent)"
    << "{"
    << "return ::GAME::Mga::" << method
    << " < " << this->name_ << " > (parent, " << this->name_ << "_Impl::metaname);"
    << "}";
}

//
// generate_parent_method
//
void Object_Class_Definition::
generate_parent_method (const Generation_Context & ctx, GAME::Mga::Atom_in item)
{
  const std::string parent = item->name ();
  const std::string parent_method = "parent_" + parent;

  ctx.hfile_
    << parent << " " << parent_method << " (void);";

  ctx.sfile_
    << function_header_t (parent_method)
    << parent << " " << this->classname_ << "::" << parent_method << " (void)"
    << "{"
    << "return " << parent << "::_narrow (this->parent ());"
    << "}";
}

//
// get_includes
//
void Object_Class_Definition::
get_includes (std::set <GAME::Mga::Atom> & includes)
{
  typedef std::set <GAME::Mga::Atom> atom_set;

  std::for_each (this->parents_.begin (),
                 this->parents_.end (),
                 boost::bind (&atom_set::insert, boost::ref (includes), _1));

  std::for_each (this->base_parents_.begin (),
                 this->base_parents_.end (),
                 boost::bind (&atom_set::insert, boost::ref (includes), _1));
}
