// -*- C++ -*-

//=============================================================================
/**
 * @file      Main_Dialog.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_PICML_MAIN_DIALOG_H_
#define _CUTS_PICML_MAIN_DIALOG_H_

// Forward decl.
struct CUTS_BE_Options;

// Forward decl.
class CUTS_BE_Manager_Factory_Repo;

// Forward decl.
class CUTS_BE_Manager_Factory;

//=============================================================================
/**
 * @class Main_Dialog
 *
 * Main dialog for the CUTS PICML interpreter.
 */
//=============================================================================

class Main_Dialog : public CDialog
{
public:
  /**
   * Main constructor.
   *
   * @param[in]     options       The backend options.
   * @param[in]     parent        Parent of the dialog.
   */
  Main_Dialog (CUTS_BE_Options * options,
               const CUTS_BE_Manager_Factory_Repo & factory_repo,
               CWnd * parent = 0);

  /// Destructor.
  virtual ~Main_Dialog (void);

  /**
   * Get the selected manager factory for model generation. This
   * factory pointer will be one located in the factory repository
   * used in the constructor.
   *
   * @return        Pointer to the manager factory.
   */
  CUTS_BE_Manager_Factory * manager_factory (void) const;

protected:
  /// Handle the initialize dialog method.
  virtual BOOL OnInitDialog (void);

  /// Handle the data exchange message.
  void DoDataExchange (CDataExchange * pDX);

  /// Handle the WM_COMMAND message.
  afx_msg BOOL OnCommand (WPARAM wParam, LPARAM lParam);

  afx_msg void On_BE_List_SelChange (void);

private:
  DECLARE_MESSAGE_MAP ();

  /// Pointer to the backend options.
  CUTS_BE_Options * options_;

  /// Collection of manager factories available for selection.
  const CUTS_BE_Manager_Factory_Repo & factory_repo_;

  /// The selected manager factory.
  CUTS_BE_Manager_Factory * manager_factory_;

  /// The backend list box control.
  CListBox be_list_;
};

#endif  // !defined _CUTS_PICML_MAIN_DIALOG_H_
