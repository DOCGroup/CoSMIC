// $Id$

#include "StdAfx.h"
#include "Property_Manager.h"
#include "Property_Manager_Impl.h"

#include "game/be/Interpreter_T.h"

#include "UdmGme.h"
#include "UdmStatic.h"
#include "UdmConfig.h"

#include "PICML/PICML.h"
#include "Property_Manager_Dialog.h"
#include <algorithm>

GAME_DECLARE_INTERPRETER (Property_Manager_Component, PICML_Property_Mangaer_Impl);

/**
 * @struct handle_item_t
 */
struct handle_item_t
{
  handle_item_t (UdmGme::GmeDataNetwork & network)
    : network_ (network)
  {

  }

  void operator () (const GAME::FCO & fco) const
  {
    if (fco.meta () != "Property")
      return;

    // Show the property manager for this object.
    Udm::Object obj = this->network_.Gme2Udm (fco.impl ());
    PICML::Property prop = PICML::Property::Cast (obj);

    CWnd * mainwnd = ::AfxGetMainWnd ();
    PICML_Property_Manager_Dialog dlg (prop, mainwnd);

    if (dlg.DoModal () == IDOK)
      this->network_.CommitEditSequence ();
    else
      this->network_.AbortEditSequence ();
  }

private:
  UdmGme::GmeDataNetwork & network_;
};


//
// PICML_Property_Mangaer_Impl
//
PICML_Property_Mangaer_Impl::PICML_Property_Mangaer_Impl (void)
: GAME::Interpreter_Impl_Base ("Property Manager", "MGA.Interpreter.PropertyManager", "PICML")
{

}

//
// ~PICML_Property_Mangaer_Impl
//
PICML_Property_Mangaer_Impl::~PICML_Property_Mangaer_Impl (void)
{

}

//
// invoke_ex
//
int PICML_Property_Mangaer_Impl::
invoke_ex (GAME::Project & project,
           GAME::FCO & fco,
           std::vector <GAME::FCO> & selected,
           long flags)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  UdmGme::GmeDataNetwork dngBackend (META_NAMESPACE::diagram);
  using namespace META_NAMESPACE;

  try
  {
    // Opening backend
    dngBackend.OpenExisting (project.impl ());

    std::for_each (selected.begin (),
                   selected.end (),
                   handle_item_t (dngBackend));

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
