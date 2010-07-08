// $Id$

#include "StdAfx.h"
#include "IDL_Generator_Component.h"
#include "IDL_Generator_Component_Impl.h"
#include "IDL_Generator_Visitor.h"

#include "game/be/Interpreter_T.h"

#include "UdmGme.h"
#include "UdmStatic.h"
#include "UdmConfig.h"

#include "game/utils/Project_Settings.h"
#include "Utils/Utils.h"

// Global config object
_config config;

GAME_DECLARE_INTERPRETER (IDL_Generator_Component, IDL_Generator_Component_Impl);

//
// Quotas_Integrator_Impl
//
IDL_Generator_Component_Impl::IDL_Generator_Component_Impl (void)
: GAME::Interpreter_Impl_Base ("IDL File Generator", "MGA.Interpreter.IDLGenerator", "PICML")
{

}

//
// ~IDL_Generator_Component_Impl
//
IDL_Generator_Component_Impl::~IDL_Generator_Component_Impl (void)
{

}

/**
 * @struct insert_udm_t
 */
struct insert_udm_t
{
  insert_udm_t (UdmGme::GmeDataNetwork & network, std::set <Udm::Object> & coll)
    : network_ (network),
      coll_ (coll)
  {

  }

  void operator () (const GAME::FCO & fco) const
  {
    this->coll_.insert (this->network_.Gme2Udm (fco.impl ()));
  }

private:
  UdmGme::GmeDataNetwork & network_;

  std::set <Udm::Object> & coll_;
};

//
// invoke_ex
//
int IDL_Generator_Component_Impl::
invoke_ex (GAME::Project & project,
           GAME::FCO & focus,
           std::vector <GAME::FCO> & selected,
           long flags)
{
  UdmGme::GmeDataNetwork dngBackend (META_NAMESPACE::diagram);
  using namespace META_NAMESPACE;

  try
  {
    // Opening backend
    dngBackend.OpenExisting (project.impl ());

    Udm::Object currentObject;
    if (!focus.is_nil ())
      currentObject = dngBackend.Gme2Udm (focus.impl ());

    set <Udm::Object> selectedObjects;
    std::for_each (selected.begin (),
                   selected.end (),
                   insert_udm_t (dngBackend, selectedObjects));

    if (this->is_interactive_ || this->output_.empty ())
    {
      // Select the output directory for the files.
      if (!::Utils::getPath ("Select target output directory...", this->output_))
        return 0;
    }

    // Generate all the IDL files.
    PICML::RootFolder folder = PICML::RootFolder::Cast (dngBackend.GetRootObject ());

    IDL_Generator_Visitor visitor (this->output_);
    folder.Accept (visitor);

    if (this->is_interactive_)
      ::AfxMessageBox ("Successfully generated IDL files");

    // Closing backend
    dngBackend.CloseWithUpdate ();
    return 0;
  }
  catch (udm_exception & exc)
  {
    if (this->is_interactive_)
      ::AfxMessageBox (exc.what ());
  }

  dngBackend.CloseNoUpdate ();
  return -1;
}

//
// set_parameter
//
int IDL_Generator_Component_Impl::
set_parameter (const std::string & name, const std::string & value)
{
  if (name == "OutputPath")
    this->output_ = value;

  return 0;
}
