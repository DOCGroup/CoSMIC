// -*- C++ -*-

//=============================================================================
/**
 * @file      PICMLManager_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_ADDON_H_
#define _PICML_MANAGER_ADDON_H_

#include "PICMLManager.h"
#include "PICMLManager_i.c"

#include "game/be/Addon_Impl_T.h"
#include "game/be/ComponentEx_T.h"

#include "PICMLManager_Impl.h"

GAME_DEFAULT_ADDON_IMPL (PICML_Manager_ComponentEx_Impl,
                         "PICML Model Intelligence", 
                         "PICML", 
                         "MGA.AddOn.PICMLManager");

/**
 * @class PICML_Manager_Impl
 *
 * The factory for the PICML manager add-on. This contains the factory
 * for creating the actual COM object. You will notice that the 
 * CComCoClass < > is parameterized by the actual COM object that 
 * will be created.
 */
class PICML_Manager_Impl :
  public GAME::Addon_Impl_T < PICML_Manager_ComponentEx_Impl, PICMLManager_Impl >,
  public IConfigurator
{
public:
  /// Default constructor.
  PICML_Manager_Impl (void);

  /// Destructor.
  virtual ~PICML_Manager_Impl (void);

  // IConfigurator
  STDMETHOD (setImplementationFolder) (BSTR folder);
  STDMETHOD (setArtifactFolder) (BSTR folder);
  STDMETHOD (resetConfiguration) (void);

private:
  typedef GAME::Addon_Impl_T < PICML_Manager_ComponentEx_Impl, PICMLManager_Impl > base_type;

  BEGIN_COM_MAP (PICML_Manager_Impl)
    COM_INTERFACE_ENTRY (IConfigurator)
    COM_INTERFACE_ENTRY_CHAIN (base_type)
  END_COM_MAP ()
};

#endif  // !defined _PICML_MANAGER_ADDON_H_
