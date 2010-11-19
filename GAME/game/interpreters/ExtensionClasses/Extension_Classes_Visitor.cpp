#include "StdAfx.h"
#include "StdAfx.cpp"
#include "Extension_Classes_Visitor.h"

#if !defined (__GAME_INLINE__)
#include "Extension_Classes_Visitor.inl"
#endif

#include "Extension_Classes_Code_Generator.h"

#include "boost/bind.hpp"

#include <direct.h>

#include "MetaAttribute.h"
#include "MetaFCO.h"

//#include "Mga.h"

namespace GAME
{

//
// Extension_Clases_Visitor
//
Extension_Classes_Visitor::Extension_Classes_Visitor (const std::string & outdir,
                                                      const std::string & uc_paradigm_name)
: outdir_ (outdir),
  uc_paradigm_name_ (uc_paradigm_name)
{

}

//
// ~Extension_Classes_Visitor
//
Extension_Classes_Visitor::~Extension_Classes_Visitor ()
{

}

//
// visit_Atom
//
void Extension_Classes_Visitor::visit_Atom (GAME::Atom & atom)
{
  
}

//
// visit_Attribute
//
void Extension_Classes_Visitor::visit_Attribute (GAME::Attribute & attribute)
{

}

//
// visit_FCO
//
void Extension_Classes_Visitor::visit_FCO (const GAME::FCO & fco)
{ 
  CONNECTIONS c;
  std::stringstream temp_params, temp_cons;
  std::string src_name, dst_name, lc_meta_name,
              meta_name, fco_name, cons_name;

  meta_name = lc_meta_name = fco.meta ().name ();
  fco_name = fco.name ();
  Extension_Classes_Code_Generator code_generator (fco_name,
                                                   meta_name,
                                                   this->curr_dir_,
                                                   this->uc_paradigm_name_);

  std::transform (lc_meta_name.begin (), lc_meta_name.end (),
                  lc_meta_name.begin (), ::tolower);

  // it determines the base constructor to be called.
  // by default we assume that it calls the concrete GAME class.
  // but if it derived from another object that is it has a
  // connection whose name is "DerivedInheritance" then call the
  // base constructor of that object.
  cons_name = "GAME::";
  cons_name += meta_name;

  // generate code only for these type of objects
  if (meta_name == "FCO" || meta_name == "Atom" || meta_name == "Model" ||
      meta_name == "Reference" || meta_name == "Set" || meta_name == "Connection")
  {
    code_generator.generate_narrow ();

    // add the object to the set to be used for mpc generation
    this->objects_.insert (fco);

    // if object is abstract then donot generate the _create function
    if (!fco.attribute ("IsAbstract").bool_value ())
      code_generator.generate_create ();

    CONNECTIONS connections;
    FCOS proxies;

    // get all the object proxies and also add the object to that list
    fco.referenced_by (proxies);
    proxies.push_back (fco);

    // get all the connections of the objects in the above list
    std::for_each (proxies.begin (),
                   proxies.end (),
                   boost::bind (&GAME::FCO::in_connections,
                                _1,
                                boost::ref (connections)));

    CONNECTIONS::iterator iter = connections.begin (),
                          iter_end = connections.end ();

    for (; iter != iter_end; ++ iter)
    {
      src_name = this->get_src_name ((*iter));
      dst_name = this->get_dst_name ((*iter));

      if (iter->name () == "HasAttribute")
      {
        // if object hass attributes add the set and get functions
        //if (fco_name == dst_name)
          code_generator.generate_attribute_list ((*iter)["src"].target ());
      }

      else if (iter->name () == "DerivedInheritance")
      {
        // add the parent class in the inherited list
        CONNECTIONS temp_conn;
        this->get_src_connections ((*iter), "BaseInheritance", temp_conn);
        code_generator.add_inherited_class (this->get_src_name (temp_conn.front ()));

        // call the constructor of the derived class
        cons_name = this->get_src_name (temp_conn.front ());

        // if the inherited class and the object are of the same meta
        // type then don't inherit the meta class
        if (this->get_src_meta_name (temp_conn.front ()) == meta_name)
          code_generator.set_inheritance_flag ();
      }

      else if (iter->name () == "SourceToConnector")
      {
        // generate function to get all the connections of this type
        CONNECTIONS temp_conn;
        this->get_dst_connections ((*iter), "AssociationClass", temp_conn);
        code_generator.generate_connector_connections (this->get_dst_name (temp_conn.front ()));
      }

      else if (iter->name () == "ConnectorToDestination")
      {
        // generate function to get all the connections of this type
        CONNECTIONS temp_conn;
        this->get_src_connections ((*iter), "AssociationClass", temp_conn);
        code_generator.generate_connector_connections (this->get_dst_name (temp_conn.front ()));
      }

      else if (iter->name () == "AssociationClass")
      {
        // generate the src () and the dst () functions
        CONNECTIONS src_conn, dst_conn;
        this->get_src_connections ((*iter), "SourceToConnector", src_conn);
        this->get_src_connections ((*iter), "ConnectorToDestination", dst_conn);
        code_generator.generate_connection_end ("src", this->get_src_name (src_conn.front ()));
        code_generator.generate_connection_end ("dst", this->get_dst_name (dst_conn.front ()));
      }
    }

    // generate the constructors and the destructors
    code_generator.generate_default_functions ("", "", "");

    // set parameters and base constructor call for IMga constructor
    temp_params << "IMga" << meta_name << " * " << lc_meta_name;
    temp_cons   << " : " << cons_name << " (" << lc_meta_name << ")";
    code_generator.generate_default_functions ("", temp_params.str (), temp_cons.str ());

    // set parameters and base constructor call for copy constructor
    temp_params.str ("");
    temp_params << "const " << fco_name << " & " << lc_meta_name;
    code_generator.generate_default_functions ("", temp_params.str (), temp_cons.str ());

    // generate the destructor and the _narrow function
    code_generator.generate_default_functions ("~", "", "");

    // generate out the the .h and the .cpp files
    code_generator.generate_h_file ();
    code_generator.generate_cpp_file ();
  }
}

//
// visit_Folder
//
void Extension_Classes_Visitor::visit_Folder (GAME::Folder & folder)
{
  // set the path from the root to this folder
  this->curr_paradigm_sheet_root_dir_  = this->outdir_;
  this->curr_paradigm_sheet_root_dir_ += "/";
  this->curr_paradigm_sheet_root_dir_ += folder.name ();

  mkdir (this->curr_paradigm_sheet_root_dir_.c_str ());

  // collect all the paradigm sheets and traverse them
  MODELS paradigm_sheets;
  folder.children ("ParadigmSheet", paradigm_sheets);

  std::for_each (paradigm_sheets.begin (),
                 paradigm_sheets.end (),
                 boost::bind (&GAME::Model::accept,
                              _1,
                              boost::ref (*this)));
}

//
// visit_Model
//
void Extension_Classes_Visitor::visit_Model (GAME::Model & model)
{
  if (model.meta ().name () == "ParadigmSheet")
  {
    std::string filename;

    // check if the sheet is contained directly in the root folder or not
    if (model.project ().root_folder ().name () == model.parent_folder ().name ())
      filename = this->outdir_;
    else
      filename = this->curr_paradigm_sheet_root_dir_;

    filename.append ("/");
    filename.append (model.name ().c_str ());

    mkdir (filename.c_str ());

    this->curr_dir_ = filename;

    // get all the children of this sheet and cll the visitor
    FCOS fcos;
    model.children (fcos);
    std::for_each (fcos.begin (),
                   fcos.end (),
                   boost::bind (&GAME::FCO::accept,
                                _1,
                                boost::ref (*this)));
  }
}

//
// visit_Object
//
void Extension_Classes_Visitor::visit_Object (GAME::Object & object)
{

}

//
// visit_Project
//
void Extension_Classes_Visitor::visit_Project (GAME::Project & project)
{

}

//
// visit_Reference
//
void Extension_Classes_Visitor::visit_Reference (GAME::Reference & reference)
{
  
}

//
// visit_Set
//
void Extension_Classes_Visitor::visit_Set (GAME::Set & set)
{
  
}

}
