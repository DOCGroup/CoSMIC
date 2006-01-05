// $Id$

#include "Cidlc_Visitor.h"
#include <strstream>

namespace PICML
{
  //
  // Cidlc_Visitor
  //
  Cidlc_Visitor::Cidlc_Visitor (const std::string& outputPath)
  : outputPath_ (outputPath),
    cidl_writer_ (cidl_file_),
    last_package_ (false)
  {

  }

  //
  // ~Cidlc_Visitor
  //
  Cidlc_Visitor::~Cidlc_Visitor (void)
  {

  }

  //
  // process_Factory_decl
  //
  void Cidlc_Visitor::process_Factory_decl (ComponentFactory_Set & factory)
  {
    if (factory.size () == 0)
      return;

    // Visit all the <ComponentFactory> objects.
    int remaining = factory.size ();

		for ( ComponentFactory_Set::iterator iter = factory.begin ();
          iter != factory.end (); 
          iter ++)
    {
      (*iter).Accept (*this);

      // We need to print a <newline> if there any more <ComponentFactory>
      // element remaining in the set.
      if (remaining -- > 1)
      {
        this->cidl_writer_.nl ();
        this->cidl_writer_.nl ();
      }
    }
  }

  //
  // Visit_File
  //
  void Cidlc_Visitor::Visit_File (const File &file)
  {
	  // Simple Algorithm to write out the cidl file
	  // Step 1: Read the contents of the interface file.
    // Step 2: When we locate the first factory, create the cidl file
    //         for the idl file.
    // Step 3: As we locate a factory, write its associated entry
    //         to the current file.
	  // Step 4: Close the cidl file if its open.

    std::string filename = file.name ();
    // The target file is : <dir> + "\" + fileName + ".cidl"
    std::ostrstream fullpath;
    fullpath  << this->outputPath_ << "\\" 
              << filename  << ".cidl" << std::ends;

    this->cidl_file_.open (fullpath.str ());
    if (this->cidl_file_.is_open ())
    {
 	    // Write the header information onto this file
	    this->cidl_writer_.gen_ifdef_macro (filename);

	    // Write out the Dependent IDL files
	    this->cidl_writer_.gen_cidlc_include (filename);
      this->cidl_writer_.nl ();

	    // Check if there are any componentFactory definitions present.
	    ComponentFactory_Set factories = file.ComponentFactory_kind_children ();

	    // For each Component Factory Definitions visit the Factory.
	    this->process_Factory_decl (factories);

	    // Visit all the first level <Package> objects in this file.
	    std::set <PICML::Package> packages = file.Package_kind_children ();
      
      int count = packages.size ();
      this->last_package_ = false;

	    for ( std::set <PICML::Package>::iterator iter = packages.begin ();
	          iter != packages.end ();
		        iter ++)
		  {
        if (-- count == 0)
          this->last_package_ = true;

        (*iter).Accept (*this);
		  }

      // If the <cidl_file_> is open then we have written one or more
      // factories to the <cidl_file_>. We have to therefore write the 
      // #endif macro.
      this->cidl_writer_ << "\n\n";
		  this->cidl_writer_.gen_endif (filename);
      this->cidl_file_.close ();
    }
  }

  //
  // Visit_ComponentFactory
  //
  void Cidlc_Visitor::Visit_ComponentFactory (const ComponentFactory &factory)
  {
	  // Get the Corresponding name of the Component associated with the
	  // factory
	  const PICML::ManagesComponent conn = factory.dstManagesComponent();
	  PICML::Manageable managable = conn.dstManagesComponent_end();

    // Visit the managed object.
    std::string type = managable.type ().name ();

    if (type == "Component")
    {
      Component::Cast (managable).Accept (*this);
    }
    else if (type == "ComponentRef")
    {
      ComponentRef::Cast (managable).Accept (*this);
    }
    else
    {
      return;
    }

    // Begin the <composition> declaration.
    this->cidl_writer_ 
      << "composition session " << this->managed_name_ << "_Impl{"
      << "home executor " <<  this->managed_name_ << "Home_Exec{"
      // Write the name of the factory/home being implemented.
      << "implements " << factory.name () << ";\n"
      // Write the name of the component it manages.
      << "manages " <<  this->managed_name_ << "_Exec;"
      << "};};";
  }

  //
  // Visit_ComponentRef
  //
  void Cidlc_Visitor::Visit_ComponentRef (const ComponentRef& reference)
  {
	  reference.GetStrValue ("name", this->managed_name_);
  }

  //
  // Visit_Component
  //
  void Cidlc_Visitor::Visit_Component (const Component& component)
  {
	  component.GetStrValue ("name", this->managed_name_);
  }

  //
  // Visit_Package
  //
  void Cidlc_Visitor::Visit_Package (const Package & package)
  {
    bool last_package = this->last_package_;

    // Locate all the <ComponentFactory> objects.
	  ComponentFactory_Set factories = package.ComponentFactory_kind_children ();

    if (!factories.empty ())
    {
      while (!this->package_names_.empty ())
      {
        this->cidl_writer_ 
          << "module " << this->package_names_.front () 
          << "{";
        this->package_names_.pop ();
      }

      // Write the name of the <package> as a module
      this->cidl_writer_ << "module " << package.name () << "{";

      // Process all the factories.
      process_Factory_decl (factories);
    }
    else
    {
      this->package_names_.push (package.name ());
    }


	  // Get all the <Package> objects defined in this <package>.
    typedef std::set <PICML::Package> Package_Set;
	  Package_Set packages = package.Package_kind_children ();

    int count = packages.size ();
    this->last_package_ = false;

    if (!(factories.empty () || packages.empty ()))
    {
      this->cidl_writer_ << "\n\n";
    }

    // Visit all the <package> objects.
		for ( Package_Set::const_iterator iter = packages.begin ();
		      iter != packages.end ();
			    iter ++)
		{
      if (-- count == 0)
        this->last_package_ = true;

      Visit_Package (*iter);
		}

    if (this->package_names_.empty ())
    {
      this->cidl_writer_ << "};";

      if (!last_package)
        this->cidl_writer_ << "\n\n";
    }
    else
    {
      this->package_names_.pop ();
    }
  }
}
