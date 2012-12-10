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

#include <string>

namespace PICML
{
namespace MI
{

// Forward decl.
class Implementation_Configuration;

/**
 * @class Default_Implementation_Dialog
 */
class Default_Implementation_Dialog : public CDialog
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     parent      Parent window
   */
  Default_Implementation_Dialog (Implementation_Configuration & config, CWnd * parent = 0);

  /// Destructor.
  virtual ~Default_Implementation_Dialog (void);

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
  Implementation_Configuration & config_;
};

}
}

#include "Dialogs.inl"

#endif  // !defined _PICML_MANAGER_DIALOGS_H_
