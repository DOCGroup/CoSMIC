// $Id$

#include "stdafx.h"
#include "Project.h"

#include "Component.h"
#include "ComponentEx.h"

namespace GAME
{
//
// Project
//
Project::Project (void)
{
  VERIFY_HRESULT (this->project_.CoCreateInstance(L"Mga.MgaProject"));
}

//
// Project
//
Project::Project (const Project & project)
  : project_ (project.project_)
{

}

//
// Project
//
Project::Project (IMgaProject * project)
: project_ (project)
{
  CComPtr <IMgaTerritory> terr;

  if (this->project_.p)
  {
    this->project_->get_ActiveTerritory (&terr);
    this->terr_.attach (terr.Detach ());
  }
}

//
// ~Project
//
Project::~Project (void)
{
  this->terr_.close ();
}

//
// _create
//
Project Project::_create (const std::string & name, const std::string & paradigm)
{
  // Convert the string to wide-char format.
  CComBSTR wName (name.length (), name.c_str ());
  CComBSTR wParadigm (paradigm.length (), paradigm.c_str ());

  // Create the project and the initial territory.
  CComPtr <IMgaProject> project;
  VERIFY_HRESULT (project->Create (wName, wParadigm));
  
  CComPtr <IMgaTerritory> terr;
  VERIFY_HRESULT (project->CreateTerritory (0, &terr, 0));

  return project.p;
}

//
// _open
//
Project Project::_open (const std::string & name)
{
  bool ro_mode;
  return Project::_open (name, ro_mode);
}

//
// _open
//
Project Project::_open (const std::string & name, bool & ro_mode)
{
  VARIANT_BOOL temp;
  CComBSTR tempstr (name.length (), name.c_str ());

  CComPtr <IMgaProject> project;
  VERIFY_HRESULT (project->Open (tempstr, &temp));
  ro_mode = (temp == VARIANT_TRUE) ? true : false;

  // Create the default territory for the project.
  CComPtr <IMgaTerritory> terr;
  VERIFY_HRESULT (project->CreateTerritory (0, &terr, 0));

  return project.p;
}

//
// save
//
void Project::save (const std::string & saveas,
                    bool keep_old_name)
{
  CComBSTR tempstr (saveas.length (), saveas.c_str ());

  VERIFY_HRESULT (this->project_->Save (
                  tempstr, keep_old_name ? VARIANT_TRUE : VARIANT_FALSE));
}

//
// close
//
void Project::close (bool abort)
{
  // Release the default territory.
  this->terr_.close ();

  // Close the project.
  VERIFY_HRESULT (this->project_->Close (
                  abort ? VARIANT_TRUE : VARIANT_FALSE));
}

//
// [get_]name
//
std::string Project::name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->project_->get_Name (&bstr));

  CW2CT tempstr (bstr);
  return tempstr.m_psz;
}

//
// [set_]name
//
void Project::name (const std::string & name)
{
  CComBSTR tempstr (name.length (), name.c_str ());
  VERIFY_HRESULT (this->project_->put_Name (tempstr));
}

//
// [get_]version
//
std::string Project::version (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->project_->get_Version (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// [set_]version
//
void Project::version (const std::string & version)
{
  CComBSTR tempstr (version.length (), version.c_str ());
  VERIFY_HRESULT (this->project_->put_Version (tempstr));
}

//
// [get_]author
//
std::string Project::author (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->project_->get_Author (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// [set_]author
//
void Project::author (const std::string & author)
{
  CComBSTR tempstr (author.length (), author.c_str ());
  VERIFY_HRESULT (this->project_->put_Author (tempstr));
}

//
// [get_]comment
//
std::string Project::comment (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->project_->get_Comment (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// [set_]comment
//
void Project::comment (const std::string & comment)
{
  CComBSTR tempstr (comment.length (), comment.c_str ());
  VERIFY_HRESULT (this->project_->put_Comment (tempstr));
}

//
// create_time
//
std::string Project::create_time (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->project_->get_CreateTime (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// change_time
//
std::string Project::change_time (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->project_->get_ChangeTime (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// create_territory
//
Territory Project::create_territory (void)
{
  IMgaTerritory * terr = 0;
  VERIFY_HRESULT (this->project_->CreateTerritory (0, &terr));

  return terr;
}

  //
// create_territory
//
Territory Project::active_territory (void)
{
  IMgaTerritory * terr = 0;
  VERIFY_HRESULT (this->project_->get_ActiveTerritory (&terr));

  return terr;
}

//
// begin_transaction
//
void Project::begin_transaction (transactiontype_enum type)
{
  if (this->terr_ == 0)
    this->terr_ = this->create_territory ();

  // Begin the default transition.
  this->begin_transaction (this->terr_, type);
}

//
// begin_transaction
//
void Project::
begin_transaction (bool commit_existing, transactiontype_enum type)
{
  if (commit_existing)
    this->commit_transaction ();
  else
    this->abort_transaction ();

  // Begin the default transition.
  this->begin_transaction (type);
}

//
// begin_transaction
//
void Project::
begin_transaction (const Territory & terr, transactiontype_enum mode)
{
  VERIFY_HRESULT (this->project_->BeginTransaction (terr, mode));
}

//
// begin_transaction
//
void Project::commit_transaction (void)
{
  VERIFY_HRESULT (this->project_->CommitTransaction ());
}

//
// begin_transaction
//
void Project::abort_transaction (void)
{
  VERIFY_HRESULT (this->project_->AbortTransaction ());
}

//
// root_folder
//
Folder Project::root_folder (void) const
{
  CComPtr <IMgaFolder> folder;
  VERIFY_HRESULT (this->project_->get_RootFolder (&folder));

  return Folder (folder);
}

//
// folder_by_path
//
Folder Project::folder_by_path (const std::string & path) const
{
  CComBSTR bstr (path.length (), path.c_str ());

  CComPtr <IMgaFolder> folder;
  VERIFY_HRESULT (this->project_->GetFolderByPath (bstr, &folder));

  return Folder (folder);
}

//
// object_by_path
//
Object Project::object_by_path (const std::string & path) const
{
  CComBSTR bstr (path.length (), path.c_str ());

  CComPtr <IMgaObject> object;
  VERIFY_HRESULT (this->project_->get_ObjectByPath (bstr, &object));

  return Object (object);
}

//
// impl
//
IMgaProject * Project::impl (void)
{
  return this->project_.p;
}

//
// operator =
//
const Project & Project::operator = (IMgaProject * project)
{
  this->project_ = project;
  return *this;
}

//
// connstr
//
std::string Project::connstr (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->project_->get_ProjectConnStr (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// paradigm_name
//
std::string Project::paradigm_name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->project_->get_MetaName (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// paradigm_version
//
std::string Project::paradigm_version (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->project_->get_MetaVersion (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// paradigm_connstr
//
std::string Project::paradigm_connstr (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->project_->get_ParadigmConnStr (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// enable_auto_addons
//
void Project::enable_auto_addons (bool flag)
{
  VERIFY_HRESULT (this->project_->EnableAutoAddOns (flag ? VARIANT_TRUE : VARIANT_FALSE));
}

//
// create_addon
//
IMgaAddOn * Project::create_addon (IMgaEventSink * sink)
{
  IMgaAddOn * addon = 0;
  VERIFY_HRESULT (this->project_->CreateAddOn (sink, &addon));

  return addon;
}

//
// create_addon
//
size_t Project::addon_components (std::vector <Component> & v) const
{
  CComPtr <IMgaComponents> temp;
  VERIFY_HRESULT (this->project_->get_AddOnComponents (&temp));

  return get_children (temp, v);
}

//
// create_addon
//
size_t Project::addon_components (std::vector <ComponentEx> & v) const
{
  CComPtr <IMgaComponents> temp;
  VERIFY_HRESULT (this->project_->get_AddOnComponents (&temp));

  return get_children (temp, v);
}
}
