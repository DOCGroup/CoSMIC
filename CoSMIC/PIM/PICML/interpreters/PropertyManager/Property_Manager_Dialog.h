// -*- C++ -*-

//=============================================================================
/**
 * @file      PropertyManager_Dialog.h
 *
 * Main dialog for the Property Manager interpreter
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_PROPERTY_MANAGER_DIALOG_H_
#define _PICML_PROPERTY_MANAGER_DIALOG_H_

#include "Property_Manager_Dialog_ListCtrl.h"

/**
 * @class PICML_Property_Manager_Dialog
 *
 * Main dialog for the data value manager addon. The dialog does not
 * contain any control for entering data values. Instead, the client
 * has to bind the dialog to a collection of PICML_DT_Control objects.
 */
class PICML_Property_Manager_Dialog : public CDialog
{
public:
  PICML_Property_Manager_Dialog (const GAME::FCO_in prop, CWnd * parent = 0);

  /// Destructor.
  virtual ~PICML_Property_Manager_Dialog (void);

protected:

  virtual void DoDataExchange (CDataExchange * pDX);

  virtual BOOL OnInitDialog (void);

private:
  DECLARE_MESSAGE_MAP ();

  /// Target property for the dialog.
  GAME::FCO prop_;

  PICML_Property_Manager_ListCtrl listview_;
};

#endif  // !defined _PICML_PROPERTY_MANAGER_DIALOG_H_
