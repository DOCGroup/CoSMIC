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

#include "cuts/be/BE_Options.h"

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
  Main_Dialog (CUTS_BE_Options * options, CWnd * parent = 0);

  /// Destructor.
  virtual ~Main_Dialog (void);

protected:
  /// Handle the initialize dialog method.
  virtual BOOL OnInitDialog (void);

  /// Handle the data exchange message.
  void DoDataExchange (CDataExchange * pDX);

  /// Handle the WM_COMMAND message.
  afx_msg BOOL OnCommand (WPARAM wParam, LPARAM lParam);

private:
  /// Pointer to the backend options.
  CUTS_BE_Options * options_;
};

#endif  // !defined _CUTS_PICML_MAIN_DIALOG_H_
