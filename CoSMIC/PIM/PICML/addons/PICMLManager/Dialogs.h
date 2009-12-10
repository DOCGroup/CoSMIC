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

/// Forward decl.
class NewComponentConfig;

/**
 * @class NewComponentDialog
 */
class NewComponentDialog : public CDialog
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     parent      Parent window
   */
  NewComponentDialog (NewComponentConfig & config, CWnd * parent = 0);

  /// Destructor.
  virtual ~NewComponentDialog (void);

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
  /// Configuration of the new component.
  NewComponentConfig & config_;
};

#include "Dialogs.inl"

#endif  // !defined _PICML_MANAGER_DIALOGS_H_
