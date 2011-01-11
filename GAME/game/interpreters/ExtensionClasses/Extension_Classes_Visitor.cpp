// $Id$

#include "StdAfx.h"
#include "StdAfx.cpp"
#include "Extension_Classes_Visitor.h"

#if !defined (__GAME_INLINE__)
#include "Extension_Classes_Visitor.inl"
#endif

#include "game/Model.h"
#include "game/MetaAttribute.h"
#include "game/MetaFCO.h"
#include "game/Reference.h"

#include "boost/bind.hpp"

namespace GAME
{

//
// Extension_Clases_Visitor
//
Extension_Classes_Visitor::
Extension_Classes_Visitor (const std::string & outdir,
                           const std::string & uc_paradigm_name)
: outdir_ (outdir),
  uc_paradigm_name_ (uc_paradigm_name)
{

}

//
// ~Extension_Classes_Visitor
//
Extension_Classes_Visitor::~Extension_Classes_Visitor (void)
{

}

//
// visit_FCO
//
void Extension_Classes_Visitor::visit_FCO (FCO_in fco)
{
  std::string src_name, dst_name, lc_meta_name,
              meta_name, fco_name, cons_name;

  meta_name = lc_meta_name = fco->meta ()->name ();
  fco_name = fco->name ();

  Extension_Classes_Code_Generator code_generator (this->uc_paradigm_name_,
                                                   fco,
                                                   this->outdir_);

  // transform the metaname to lower case.
  std::transform (lc_meta_name.begin (),
                  lc_meta_name.end (),
                  lc_meta_name.begin (),
                  &::tolower);

  // it determines the base constructor to be called.
  // by default we assume that it calls the concrete GAME class.
  // but if it derived from another object that is it has a
  // connection whose name is "DerivedInheritance" then call the
  // base constructor of that object.
  cons_name = "";
  cons_name += meta_name;

  // generate code only for these type of objects
  if (meta_name == "FCO" ||
      meta_name == "Atom" ||
      meta_name == "Model" ||
      meta_name == "Reference" ||
      meta_name == "Set" ||
      meta_name == "Connection")
  {
    code_generator.generate_narrow ();

    // add the object to the set to be used for mpc generation
    this->objects_.insert (fco);

    CONNECTIONS connections;
    FCOS proxies;

    // get all the object proxies and also add the object to that list
    fco->referenced_by (proxies);
    proxies.push_back (fco);

    // get all the connections of the objects in the above list
    std::for_each (proxies.begin (),
                   proxies.end (),
                   boost::bind (&FCO::impl_type::in_connections,
                                boost::bind (&FCO::get, _1),
                                boost::ref (connections)));

    CONNECTIONS::iterator iter = connections.begin (),
                          iter_end = connections.end ();

    for (; iter != iter_end; ++ iter)
    {
      const std::string name = (*iter)->name ();

      FCO src = (*iter)->src ();
      FCO dst = (*iter)->dst ();

      src_name = src->name ();
      dst_name = dst->name ();

      if (name == "HasAttribute")
      {
        code_generator.generate_attribute_list (src);
      }
      else if (name == "DerivedInheritance")
      {
        // add the parent class in the inherited list
        CONNECTIONS temp_conn;
        this->get_src_connections (iter->get (),
                                   "BaseInheritance",
                                   temp_conn);

        FCO temp_src = temp_conn.front ()->src ();
        const std::string inst_path = this->get_instance_path (temp_src);
        code_generator.add_inherited_class (inst_path);

        // call the constructor of the derived class
        cons_name = temp_src->name ();

        // if the inherited class and the object are of the same meta
        // type then don't inherit the meta class
        if (temp_src->meta ()->name () == meta_name)
          code_generator.set_inheritance_flag ();
      }
      else if (name == "SourceToConnector")
      {
        // generate function to get all the connections of this type
        CONNECTIONS temp_conn;
        this->get_dst_connections (iter->get (), "AssociationClass", temp_conn);

        FCO dst = temp_conn.front ()->dst ();
        const std::string inst_path = this->get_instance_path (dst);
        code_generator.generate_connector_connections (inst_path);
      }
      else if (name == "ConnectorToDestination")
      {
        // generate function to get all the connections of this type
        CONNECTIONS temp_conn;
        this->get_src_connections (iter->get (), "AssociationClass", temp_conn);

        FCO dst = temp_conn.front ()->dst ();
        const std::string inst_path = this->get_instance_path (dst);
        code_generator.generate_connector_connections (inst_path);
      }
      else if (name == "AssociationClass")
      {
        // generate the src () and the dst () functions
        CONNECTIONS src_conn, dst_conn;
        this->get_src_connections (iter->get (), "SourceToConnector", src_conn);
        this->get_src_connections (iter->get (), "ConnectorToDestination", dst_conn);

        FCO src = src_conn.front ()->src ();
        const std::string src_inst_path = this->get_instance_path (src);
        code_generator.generate_connection_end ("src", src_inst_path);

        FCO dst = dst_conn.front ()->dst ();
        const std::string dst_inst_path = this->get_instance_path (dst);
        code_generator.generate_connection_end ("dst", dst_inst_path);
      }
      else if ((*iter)->name () == "Containment")
      {
        if (fco_name == src_name)
        {
          FCO fco = (*iter)->dst ();
          const std::string inst_path = this->get_instance_path (fco);
          code_generator.generate_create (inst_path);
        }
      }
    }

    this->create_default_functions (fco_name,
                                    meta_name,
                                    lc_meta_name,
                                    cons_name,
                                    code_generator);

    // generate out the the .h and the .cpp files
    code_generator.generate_h_file ();
    code_generator.generate_cpp_file ();
  }
}

//
// visit_Folder
//
void Extension_Classes_Visitor::visit_Folder (Folder_in folder)
{
  this->create_directory (folder->path ("\\", true));

  // collect all the paradigm sheets and traverse them.
  MODELS paradigm_sheets;
  folder->children ("ParadigmSheet", paradigm_sheets);

  // visit all the paradigm sheets.
  std::for_each (paradigm_sheets.begin (),
                 paradigm_sheets.end (),
                 boost::bind (&Model::impl_type::accept,
                 boost::bind (&Model::get, _1),
                              this));
}

//
// visit_Model
//
void Extension_Classes_Visitor::visit_Model (Model_in model)
{
  this->create_directory (model->path ("\\", true));

  // get all the children of this sheet and call the visitor.
  FCOS fcos;
  model->children (fcos);

  std::for_each (fcos.begin (),
                 fcos.end (),
                 boost::bind (&FCO::impl_type::accept,
                              boost::bind (&FCO::get, _1),
                              this));
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

//
// create_default_functions
//
void Extension_Classes_Visitor::
create_default_functions (std::string fco_name,
                          std::string meta_name,
                          std::string obj_name,
                          std::string constructor_name,
                          Extension_Classes_Code_Generator & generator)
{
  std::stringstream params, base_constructor;

  // generate the constructors and the destructors
  generator.generate_default_functions ("", "void", "");

  // set parameters and base constructor call for IMga constructor
  params << "IMga" << meta_name << " * " << obj_name;
  base_constructor << std::endl << ": " << constructor_name << " (" << obj_name << ")";
  generator.generate_default_functions ("", params.str (), base_constructor.str ());

  // set parameters and base constructor call for copy constructor
  params.str ("");
  params << "const " << fco_name << " & " << obj_name;
  generator.generate_default_functions ("", params.str (), base_constructor.str ());

  // set parameters and base constructor call for constructor that takes
  // parameter of base type
  params.str ("");
  params << "const " << meta_name << " & " << obj_name;
  generator.generate_default_functions ("", params.str (), base_constructor.str ());

  // generate the destructor and the _narrow function
  generator.generate_default_functions ("~", "void", "");
}

}
