// $Id$

#include "stdafx.h"
#include "Visitor_Test_Impl.h"

#include "game/be/Interpreter_T.h"

#include "game/Transaction.h"
#include "game/Atom.h"
#include "game/Model.h"
#include "game/Reference.h"
#include "game/Visitor.h"

#include "boost/bind.hpp"
#include <algorithm>
#include <bitset>

GAME_DECLARE_INTERPRETER (VisitorTest, Visitor_Test_Impl);

/**
 * @class Test_Visitor
 *
 * The object that tests if the GAME visitor operates correctly. Right
 * now we use hard coded numerics, but this class will be updated to use
 * the OBJTYPE_* identifiers.
 */
class Test_Visitor : public GAME::Visitor
{
public:
  /// Default constructor
  Test_Visitor (std::bitset <4> & bits)
    : bits_ (bits)
  {

  }

  /// Visit a folder object.
  virtual void visit_Folder (GAME::Folder_in folder)
  {
    if (folder->name () == "SheetFolder")
      this->bits_.set (0);
  }

  /// Visit a reference object.
  virtual void visit_Reference (GAME::Reference_in ref)
  {
    if (ref->name () == "BookReference")
      this->bits_.set (1);
  }

  /// Visit an atom object.
  virtual void visit_Atom (GAME::Atom_in atom)
  {
    if (atom->name () == "Book")
      this->bits_.set (2);
  }

  /// Visit a model element.
  virtual void visit_Model (GAME::Model_in model)
  {
    if (model->name () == "ParadigmSheet")
      this->bits_.set (3);

    std::vector <GAME::FCO> fcos;
    model->children (fcos);

    Test_Visitor tv (this->bits_);
    std::for_each (fcos.begin (),
                   fcos.end (),
                   boost::bind (&GAME::FCO::impl_type::accept,
                                boost::bind (&GAME::FCO::get, _1),
                                &tv));
  }

private:
  /// Flags for visiting the different elements.
  std::bitset <4> & bits_;
};

//
// Quotas_Integrator_Impl
//
Visitor_Test_Impl::Visitor_Test_Impl (void)
: GAME::Interpreter_Impl_Base ("GAME Extension Class Generator",
                               "MetaGME",
                               "GAME.Interpreter.ExtensionClasses")
{

}

//
// ~Visitor_Test_Impl
//
Visitor_Test_Impl::~Visitor_Test_Impl (void)
{

}

//
// invoke_ex
//
int Visitor_Test_Impl::
invoke_ex (GAME::Project project,
           GAME::FCO_in focus,
           std::vector <GAME::FCO> & selected,
           long flags)
{
  GAME::Transaction t (project, TRANSACTION_READ_ONLY);

  try
  {
    std::bitset <4> bits (0);
    Test_Visitor tv (bits);

    GAME::Folder root = project.root_folder ();

    // Get all the FCOs in this folder.
    std::vector <GAME::FCO> fcos;
    root->children (fcos);

    // Visit each of the FCOs.
    std::for_each (fcos.begin (),
                   fcos.end (),
                   boost::bind (&GAME::FCO::impl_type::accept,
                                boost::bind (&GAME::FCO::get, _1),
                                &tv));

    // Get all the folders in this root folder.
    std::vector <GAME::Folder> folders;
    root->children (folders);

    // Visit all the folders.
    std::for_each (folders.begin (),
                   folders.end (),
                   boost::bind (&GAME::Folder::impl_type::accept,
                                boost::bind (&GAME::Folder::get, _1),
                                &tv));

    if (this->interactive ())
    {
      if (bits.count () == bits.size ())
        ::AfxMessageBox ("Successfully visited all types");
      else
        ::AfxMessageBox ("Failed to visit all the types", MB_ICONERROR);
    }
  }
  catch (const GAME::Exception &)
  {
    if (this->interactive ())
      ::AfxMessageBox ("Caught unknown exception", MB_ICONERROR);
  }

  return 0;
}

//
// set_parameter
//
int Visitor_Test_Impl::
set_parameter (const std::string & name, const std::string & value)
{

  return 0;
}
