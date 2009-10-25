// -*- C++ -*-

//=============================================================================
/**
 * @file      Dialogs.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_DIALOGS_H_
#define _PICML_MANAGER_DIALOGS_H_

#include "ace/SString.h"

/**
 * @class Component_Name_Dialog
 */
class Component_Name_Dialog : public CDialog
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     parent      Parent window
   */
  Component_Name_Dialog (CWnd * parent = 0);

  /// Destructor.
  virtual ~Component_Name_Dialog (void);

  /**
   * Get the inputed name of the component dialog.
   *
   * @return        The component name.
   */
  const ACE_CString & component_name (void) const;

  /**
   * Set the component name. If this is done before the dialog
   * box is displayed, then the text box will contain this value.
   *
   * @param[in]     name        Name of the component
   */
  void component_name (const ACE_CString & name);

protected:
  /**
   * Data exchange method for tranfering information to and from
   * the dialog box controls.
   *
   * @param[in]     pDX         Pointer to the data exchange.
   */
  virtual void DoDataExchange (CDataExchange * pDX);

private:
  /// The name of the component.
  ACE_CString name_;
};

#include "Dialogs.inl"

#endif  // !defined _PICML_MANAGER_DIALOGS_H_
