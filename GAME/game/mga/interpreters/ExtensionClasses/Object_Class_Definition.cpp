// $Id$

#include "StdAfx.h"
#include "Object_Class_Definition.h"

#if !defined (__GAME_INLINE__)
#include "Object_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#include "Functors.h"
#include "Object_Manager.h"
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
class Base_Class_Locator : public ::GAME::Mga::Visitor
{
public:
  //
  // Base_Class_Locator
  //
  Base_Class_Locator (Object_Class_Definition * self)
    : self_ (self)
  {

  }

  //
  // visit_Atom
  //
  virtual void visit_Atom (GAME::Mga::Atom_in item)
  {
    const std::string metaname = item->name ();
    this->process_FCO (metaname, item);

    // Gather all the Proxy elements that reference this element.
    // We need to visit them as well since they may have other
    // base class definitions.
    using GAME::Mga::Iterator;
    using GAME::Mga::Reference;

    Iterator <Reference> iter = item->referenced_by ();
    std::for_each (GAME::Mga::make_impl_iter (iter),
                   GAME::Mga::make_impl_iter (iter.make_end ()),
                   boost::bind (&Reference::impl_type::accept, _1, this));
  }

  //
  // visit_Reference
  //
  void Base_Class_Locator::visit_Reference (GAME::Mga::Reference_in ref)
  {
    const std::string metaname = ref->refers_to ()->name ();
    this->process_FCO (metaname, ref);
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

    if (metaname == "BaseInheritance")
    {
      // We have found the base type, so let's insert it into ourself object
      // as a base class.
      GAME::Mga::Atom src_atom = GAME::Mga::Atom::_narrow (src);
      Object_Class_Definition * base_class = OBJECT_MANAGER->get (src_atom);
      this->self_->base_classes_.insert (base_class);

      // Also, make sure we state the <self_> object is a derived class
      // of the base class.
      base_class->derived_classes_.insert (this->self_);
    }
    else if (metaname == "DerivedInheritance")
    {
      // Visit the Inheritance model element.
      src->accept (this);
    }
  }

private:
  void process_FCO (const std::string & metaname, GAME::Mga::FCO_in fco)
  {
    if (metaname == "Inheritance")
    {
      // Locate all the DerivedInheritance connections for this element.
      std::vector <GAME::Mga::Connection> base_conns;
      fco->in_connections ("BaseInheritance", base_conns);

      std::for_each (GAME::Mga::make_impl_iter (base_conns.begin ()),
                     GAME::Mga::make_impl_iter (base_conns.end ()),
                     boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, this));
    }
    else
    {
      // Locate all the BaseInheritance connections for this element.
      std::vector <GAME::Mga::Connection> derived_conns;
      fco->in_connections ("DerivedInheritance", derived_conns);

      std::for_each (GAME::Mga::make_impl_iter (derived_conns.begin ()),
                     GAME::Mga::make_impl_iter (derived_conns.end ()),
                     boost::bind (&GAME::Mga::Connection::impl_type::accept, _1, this));
    }
  }

  Object_Class_Definition * self_;
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

  void operator () (Object_Class_Definition * item)
  {
    this->hfile_
      << "," << std::endl
      << "  public virtual " << item->classname ();
  }

private:
  std::ostream & hfile_;
};

///////////////////////////////////////////////////////////////////////////////
// include_gen

/**
 * @struct include_gen
 */
struct include_gen
{
  include_gen (std::ostream & out,
               Unique_Object_Class_Definitions & seen,
               bool include_derived_types = false)
    : out_ (out),
      seen_ (seen),
      include_derived_types_ (include_derived_types)
  {

  }

  void operator () (Object_Class_Definition * item)
  {
    if (this->seen_.find (item) != this->seen_.end ())
      return;

    this->seen_.insert (item);

    const std::string path = item->compute_path ("/", false);
    this->out_ << include_t (path + ".h");

    if (this->include_derived_types_)
      std::for_each (item->derived_classes ().begin (),
                     item->derived_classes ().end (),
                     *this);
  }

private:
  std::ostream & out_;
  bool include_derived_types_;
  Unique_Object_Class_Definitions & seen_;
};

/**
 * @struct include_gen
 */
struct parent_include_gen
{
  parent_include_gen (std::ostream & out, Unique_Object_Class_Definitions & seen)
    : out_ (out),
      seen_ (seen)
  {

  }

  void operator () (Object_Class_Definition * item)
  {
    std::for_each (item->parents ().begin (),
                   item->parents ().end (),
                   boost::bind (&parent_include_gen::generate_include, this, _1));

    std::for_each (item->base_classes ().begin (),
                   item->base_classes ().end (),
                   *this);
  }

private:
  void generate_include (Object_Class_Definition * item)
  {
    // Only generate the include statement for the item once.
    if (this->seen_.find (item) != this->seen_.end ())
      return;

    this->seen_.insert (item);

    // Generate the include statement for the item.
    const std::string path = item->compute_path ("/", false);
    this->out_ << include_t (path + ".h");
  }

  std::ostream & out_;
  Unique_Object_Class_Definitions & seen_;
};

/**
 * @struct Factory_Method_Generator
 */
struct Factory_Method_Generator
{
public:
  Factory_Method_Generator (std::ostream & hfile, std::ostream & sfile)
    : hfile_ (hfile),
      sfile_ (sfile),
      self_ (0)
  {

  }

  void operator () (Object_Class_Definition * item)
  {
    if (this->self_ == 0)
      this->self_ = item;

    // Generate the factory for each one of this object's parents.
    std::for_each (item->parents ().begin (),
                   item->parents ().end (),
                   boost::bind (&Factory_Method_Generator::generate, this, _1));

    // Generate the factory methods for each of the base classes.
    std::for_each (item->base_classes ().begin (),
                   item->base_classes ().end (),
                   Factory_Method_Generator (this->self_, this->hfile_, this->sfile_));
  }

private:
  Factory_Method_Generator (Object_Class_Definition * self, std::ostream & hfile, std::ostream & sfile)
    : hfile_ (hfile),
      sfile_ (sfile),
      self_ (self)
  {

  }

  //
  // generate
  //
  void generate (Object_Class_Definition * item)
  {
    // Make sure we are not generating duplicate factory methods.
    if (this->seen_.find (item) != this->seen_.end ())
      return;

    // Insert the item into the seen list.
    this->seen_.insert (item);

    const std::string parent_type = item->metaname ();
    const std::string parent = item->name ();
    const std::string method = parent_type == "Model" ? "create_object" : "create_root_object";

    this->hfile_
      << "static " << this->self_->name () << " _create (const " << parent << "_in parent);";

    this->sfile_
      << function_header_t ("_create (const " + parent + "_in)")
      << this->self_->name () << " " << this->self_->classname () << "::_create (const " << parent << "_in parent)"
      << "{"
      << "return ::GAME::Mga::" << method
      << " < " << this->self_->name () << " > (parent, " << this->self_->name () << "_Impl::metaname);"
      << "}";
  }

  std::ostream & hfile_;
  std::ostream & sfile_;

  std::set <Object_Class_Definition *> seen_;
  Object_Class_Definition * self_;
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
    this->metaname_ = fco->meta ()->name ();
    this->classname_ = this->name_ + "_Impl";
    this->default_base_classname_ = "::GAME::Mga::" + this->metaname_ + "_Impl";
    this->in_root_folder_ = fco->attribute ("InRootFolder")->bool_value ();

    this->is_abstract_ =
      (this->metaname_ == "FCO" ||
      (this->metaname_ != "Folder" && fco->attribute ("IsAbstract")->bool_value ()));
  }

  // Get the base classes for this object.
  Base_Class_Locator base_class_locator (this);
  fco->accept (&base_class_locator);

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

  // Write the include files for each of the used objects. The header file
  // has the includes of all the base classes. The source file has the
  // includes of all the other files that have been identified.
  Unique_Object_Class_Definitions seen_includes;
  std::for_each (this->base_classes_.begin (),
                 this->base_classes_.end (),
                 include_gen (ctx.hfile_, seen_includes));

  seen_includes.clear ();
  std::for_each (this->source_includes_.begin (),
                 this->source_includes_.end (),
                 include_gen (ctx.sfile_, seen_includes, true));

  // Generate the includes for this object's parents.
  parent_include_gen (ctx.sfile_, seen_includes)(this);

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
  std::for_each (this->base_classes_.begin (),
                 this->base_classes_.end (),
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
        << "{";

      if (this->metaname_ == "Folder")
      {
        ctx.sfile_
          << "return ::GAME::Mga::create_root_folder <"
          << this->name_ << "> (parent, " << this->classname_ << "::metaname);"
          << "}";
      }
      else
      {
        ctx.sfile_
          << "return ::GAME::Mga::create_root_object <"
          << this->name_ << "> (parent, " << this->classname_ << "::metaname);"
          << "}";
      }
    }

    // Write the factory method for each parent element.
    Factory_Method_Generator factory_gen (ctx.hfile_, ctx.sfile_);
    factory_gen (this);

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

  // Write the parent getter method for each parent object type.
  std::for_each (this->parents_.begin (),
                 this->parents_.end (),
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
// generate_parent_method
//
void Object_Class_Definition::
generate_parent_method (const Generation_Context & ctx, Object_Class_Definition * definition)
{
  const std::string parent = definition->name ();
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
