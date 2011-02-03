// -*- C++ -*-

//=============================================================================
/**
 *  @file       Selection_List_Dialog.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _GAME_NAME_DIALOG_H_
#define _GAME_NAME_DIALOG_H_

#include "game/mga/Object.h"

namespace GAME
{
namespace Dialogs
{
/**
 * @class Name_Dialog
 *
 * Simple dialog for setting the name of an element.
 */
class AFX_EXT_CLASS Name_Dialog : public CDialog
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     obj         The target object.
   * @param[in]     parent      Parent of the dialog
   */
  Name_Dialog (Mga::Object_in obj, CWnd * parent = 0);

  /// Destructor.
  virtual ~Name_Dialog (void);

protected:
  /**
   * Data exchange method for tranfering information to and from
   * the dialog box controls.
   *
   * @param[in]     pDX         Pointer to the data exchange.
   */
  virtual void DoDataExchange (CDataExchange * pDX);

  /// Initialize the dialog.
  virtual BOOL OnInitDialog (void);

private:
  /// Destination object for the name.
  Mga::Object obj_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Name_Dialog.inl"
#endif

#endif  // !defined _GAME_SELECTION_LIST_DIALOG_H_
