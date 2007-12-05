// $Id$

#include "stdafx.h"
#include "Project.h"

namespace GME
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

  }

  //
  // ~Project
  //
  Project::~Project (void)
  {
    this->terr_.close ();
  }

  //
  // create
  //
  void Project::create (const std::string & name,
                        const std::string & paradigm)
  {
    // Convert the string to wide-char format.
    CComBSTR wName (name.length (), name.c_str ());
    CComBSTR wParadigm (paradigm.length (), paradigm.c_str ());

    // Invoke the operation.
    VERIFY_HRESULT (this->project_->Create (wName, wParadigm));

    // Create the default territory for the project.
    this->terr_ = this->create_territory ();
  }

  //
  // open
  //
  void Project::open (const std::string & name,
                      bool * ro_mode)
  {
    VARIANT_BOOL temp;
    CComBSTR tempstr (name.length (), name.c_str ());

    VERIFY_HRESULT (this->project_->Open (tempstr, &temp));

    if (ro_mode)
      *ro_mode = temp == VARIANT_TRUE ? true : false;

    // Create the default territory for the project.
    this->terr_ = this->create_territory ();
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
  void Project::begin_transaction (void)
  {
    if (this->terr_ == 0)
      this->terr_ = this->create_territory ();

    VERIFY_HRESULT (this->project_->BeginTransaction (this->terr_));
  }

  //
  // begin_transaction
  //
  void Project::begin_transaction (const Territory & terr)
  {
    VERIFY_HRESULT (this->project_->BeginTransaction (terr));
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
  // operator IMgaProject *
  //
  Project::operator IMgaProject * (void) const
  {
    return this->project_;
  }

  //
  // impl
  //
  IMgaProject * Project::impl (void)
  {
    return this->project_.p;
  }
}
