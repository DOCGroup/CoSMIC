#include "StdAfx.h"

#include "PICMLManager_i.c"
#include "PICML_Manager_Addon.h"

#include "game/mga/component/ComponentEx_T.h"

DECLARE_GAME_COMPONENT_EX (PICML_Manager_Impl, PICMLManager_Addon);

//
// PICML_Manager_Impl
//
PICML_Manager_Impl::PICML_Manager_Impl (void)
{

}

//
// ~PICML_Manager_Impl
//
PICML_Manager_Impl::~PICML_Manager_Impl (void)
{

}

//
// setImplementationFolder
//
STDMETHODIMP PICML_Manager_Impl::setImplementationFolder (BSTR folder)
{
  CW2A temp (folder);
  PICML::MI::Global_Configuration::instance ()->impl_folder_ = temp.m_psz;

  return S_OK;
}

//
// setArtifactFolder
//
STDMETHODIMP PICML_Manager_Impl::setArtifactFolder (BSTR folder)
{
  CW2A temp (folder);
  PICML::MI::Global_Configuration::instance ()->artifact_folder_ = temp.m_psz;

  return S_OK;
}

STDMETHODIMP PICML_Manager_Impl::resetConfiguration (void)
{
  PICML::MI::Global_Configuration::instance ()->reset ();

  return S_OK;
}
