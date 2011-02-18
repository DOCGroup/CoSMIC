// $Id$

#include "StdAfx.h"
#include "Package_Component.h"
#include "Package_Component_Impl.h"

#include "PackageMainDialog.h"

#include "game/mga/be/Interpreter_T.h"
#include "game/mga/Project.h"
#include "game/mga/utils/Project_Settings.h"

#include "Utils/Utils.h"
#include "Utils/xercesc/XercesString.h"

#include "UdmGme.h"
#include "UdmStatic.h"

#include "PICML/PICML.h"
#include "PackageOptions.h"
#include "PackageVisitor.h"
#include "PackagerVisitor.h"
#include "PackageMainDialog.h"

GAME_DECLARE_INTERPRETER (Package_Component, Package_Component_Impl);

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

  void operator () (const GAME::Mga::FCO_in fco) const
  {
    this->coll_.insert (this->network_.Gme2Udm (fco->impl ()));
  }

private:
  UdmGme::GmeDataNetwork & network_;

  std::set <Udm::Object> & coll_;
};

//
// Package_Component_Impl
//
Package_Component_Impl::Package_Component_Impl (void)
: GAME::Mga::Interpreter_Impl_Base ("DAnCE Packaging Generator",
                                    "MGA.Interpreter.PackageComponent",
                                    "PICML")
{

}

//
// ~Package_Component_Impl
//
Package_Component_Impl::~Package_Component_Impl (void)
{

}

//
// invoke_ex
//
int Package_Component_Impl::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in focus,
           std::vector <GAME::Mga::FCO> & selected,
           long flags)
{
  UdmGme::GmeDataNetwork dngBackend (PICML::diagram);

  try
  {
    dngBackend.OpenExisting (project.impl ());

    // Load the last configuration for this project.
    PackageOptions options;
    this->load_configuration (project, options);

    if (this->is_interactive_)
    {
      // Get the options for the interpreter.
      AFX_MANAGE_STATE (::AfxGetStaticModuleState ());
      PackageMainDialog dialog (options, ::AfxGetMainWnd ());

      if (dialog.DoModal () == IDCANCEL)
        return 0;

      // Save the directory back to the model.
      this->save_configuration (project, options);
    }

    PICML::RootFolder root = PICML::RootFolder::Cast (dngBackend.GetRootObject());

    if (options.generate_descriptors_)
    {
      // The user has elected to generate the descriptors.
      PICML::PackageVisitor package_visitor (options.descriptor_directory_);
      root.Accept (package_visitor);

      if (this->is_interactive_)
        ::AfxMessageBox ("Successfully generated descriptor files.", MB_OK | MB_ICONINFORMATION);
    }

    if (options.generate_packages_)
    {
      // The user has elected to generate the packages.
      PICML::PackagerVisitor
        packager_visitor (options.descriptor_directory_,
                          options.implementation_directory_,
                          options.package_directory_);

      root.Accept (packager_visitor);

      if (this->is_interactive_)
        ::AfxMessageBox ("Successfully generated packages.", MB_OK | MB_ICONINFORMATION);
    }

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
// load_configuration
//
void Package_Component_Impl::
load_configuration (GAME::Mga::Project proj, PackageOptions & options)
{
  GAME::Mga::Project_Settings settings (proj, "PICML/Packaging");

  settings.get_string_value ("Descriptor", options.descriptor_directory_);
  settings.get_string_value ("Implementation", options.implementation_directory_);
  settings.get_string_value ("Package", options.package_directory_);
}

//
// save_configuration
//
void Package_Component_Impl::
save_configuration (GAME::Mga::Project proj, const PackageOptions & options)
{
  GAME::Mga::Project_Settings settings (proj, "PICML/Packaging");

  // Only store the options that were used during this execution
  // of the interpreter.
  if (options.generate_descriptors_)
    settings.set_string_value ("Descriptor", options.descriptor_directory_);

  if (options.generate_packages_)
  {
    settings.set_string_value ("Implementation", options.implementation_directory_);
    settings.set_string_value ("Package", options.package_directory_);
  }
}
