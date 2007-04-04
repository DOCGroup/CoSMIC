// -*- C++ -*-

//=============================================================================
/**
 * @file      PackageMainDialog.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PACKAGE_MAIN_DIALOG_H_
#define _PACKAGE_MAIN_DIALOG_H_

// Forward decl.
class PackageOptions;

//=============================================================================
/**
 * @class PackageMainDialog
 *
 * Main dialog for the PICML package interpreter. This allows the
 * the user to enter "command-line" parameters that determines the
 * side-effects of the interpreter.
 */
//=============================================================================

class PackageMainDialog : public CDialog
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     opts        Options to receive dialog inputs.
   * @param[in]     parent      The parent of the dialog.
   */
  PackageMainDialog (PackageOptions & opts, CWnd * parent = 0);

  /// Destructor.
  virtual ~PackageMainDialog (void);

protected:
  /// Handle the initialize dialog method.
  virtual BOOL OnInitDialog (void);

  /**
   * Data exchange method for tranfering information to and from
   * the dialog box controls.
   *
   * @param[in]     pDX         Pointer to the data exchange.
   */
  void DoDataExchange (CDataExchange * pDX);

  /// Event handler for clicking the generate descriptors checkbox.
  afx_msg void OnClick_GenerateDescriptors (void);

  /// Event handler for clicking the generate packages checkbox.
  afx_msg void OnClick_GeneratePackages (void);

  /// Event handler the for Browse button associated with
  /// descriptor output directory.
  afx_msg void OnClick_BrowseDescriptor (void);

  /// Event handler the for Browse button associated with
  /// implementation input directory.
  afx_msg void OnClick_BrowseImplementation (void);

  /// Event handler the for Browse button associated with
  /// package output directory.
  afx_msg void OnClick_BrowsePackage (void);

  /// Event handler for clicking the Cancel button.
  void OnCancel (void);

private:
  /**
   * Helper method for reusig the browsing code.
   *
   * @param[in]       prompt      Prompt to display to the user.
   * @param[in]       ctrl_id     Id of the edit control
   */
  void BrowseForFolder (const char * prompt, UINT ctrl_id);

  // Declare the message map for the dialog.
  DECLARE_MESSAGE_MAP ();

  /// The options that stores the dialogs input.
  PackageOptions & opts_;

  CButton generate_descriptors_button_;

  CButton generate_packages_button_;
};

#endif  // !defined _PACKAGE_MAIN_DIALOG_H_
