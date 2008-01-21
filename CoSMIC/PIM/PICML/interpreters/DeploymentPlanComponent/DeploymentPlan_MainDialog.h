/* -*- C++ -*- */

//=============================================================================
/**
 * @file          DeploymentPlan_MainDialog.h
 *
 * Main dialog for the deployment plan interpreter.
 *
 * $Id$
 *
 * @author        James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _DEPLOYMENTPLAN_MAINDIALOG_H_
#define _DEPLOYMENTPLAN_MAINDIALOG_H_

//=============================================================================
/**
 * @class DeploymentPlan_MainDialog
 *
 * MFC-based wrapper class for the main dialog.
 */
//=============================================================================

class DeploymentPlan_MainDialog : public CDialog
{
public:
  /// Default constructor.
  DeploymentPlan_MainDialog (CWnd * parent = 0);

  /// Destructor.
  virtual ~DeploymentPlan_MainDialog (void);

  /// Get the disable optimization flag.
  int disable_optimization (void) const;

  const CString & output_directory (void) const;

protected:
  /// Handle the initialize dialog method.
  virtual BOOL OnInitDialog (void);

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

  /// Optimization disable flag.
  int disable_optimize_;

  /// The output directory for the deployment plans.
  CString output_directory_;
};

#endif  /* !defined _DEPLOYMENTPLAN_MAINDIALOG_H_ */
