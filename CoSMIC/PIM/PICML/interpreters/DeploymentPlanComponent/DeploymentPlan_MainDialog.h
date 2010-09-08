/* -*- C++ -*- */

//=============================================================================
/**
 * @file          Deployment_Plan_Dialog.h
 *
 * Main dialog for the deployment plan interpreter.
 *
 * $Id$
 *
 * @author        James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _DEPLOYMENT_PLAN_DIALOG_H_
#define _DEPLOYMENT_PLAN_DIALOG_H_

#include "Configuration.h"

/**
 * @class Deployment_Plan_Dialog
 *
 * MFC-based wrapper class for the main dialog.
 */
class Deployment_Plan_Dialog : public CDialog
{
public:
  /**
   * Initializing constructor
   *
   * @param[inout]        cfg           Initial configuration
   * @param[in]           parent        The parent window.
   */
  Deployment_Plan_Dialog (Configuration & cfg, CWnd * parent = 0);

  /// Destructor.
  virtual ~Deployment_Plan_Dialog (void);

protected:
  /// Event handler the for Browse button associated with
  /// implementation input directory.
  afx_msg void OnClick_Browse (void);

  /**
   * Data exchange method for tranfering information to and from
   * the dialog box controls.
   *
   * @param[in]     pDX         Pointer to the data exchange.
   */
  void DoDataExchange (CDataExchange * pDX);

private:
  // Declare the message map for the dialog.
  DECLARE_MESSAGE_MAP ();

  /// The target configuration.
  Configuration & config_;
};

#endif  /* !defined _DEPLOYMENTPLAN_MAINDIALOG_H_ */
