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

#ifndef _GAME_SELECTION_LIST_DIALOG_H_
#define _GAME_SELECTION_LIST_DIALOG_H_

#include <vector>
#include "game/Object.h"


namespace GAME
{
namespace Dialogs
{
// Forward decl.
class Dialog_Display_Strategy;

/**
 * @class Selection_List_Dialog
 *
 * Simple dialog that shows a list of elements.
 */
class AFX_EXT_CLASS Selection_List_Dialog : public CDialog
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     items       Initial items for the dialog
   * @param[in]     parent      Parent of the dialog
   */
  Selection_List_Dialog (Dialog_Display_Strategy * strategy = 0,
                         CWnd * parent = 0);

  /// Destructor.
  virtual ~Selection_List_Dialog (void);

  /**
   * Get the selected string from the dialog.
   *
   * @return        The selected string value.
   */
  GAME::Object selection (void) const;

  void title (const char * str);
  void directions (const char * str);

  /**
   * Insert a new object into the dialog.
   *
   * @param[in]     object        The new object.
   */
  void insert (const GAME::Object & object);

  /**
   * Insert a collection of objects into the dialog listing.
   *
   * @param[in]     items         Collection of objects
   */
  void insert (const std::vector <GAME::Object> & items);

  /**
   * @overloaded
   *
   * @param[in]     begin         Start of collection
   * @param[in]     end           End of collection
   */
  void insert (std::vector <GAME::Object>::const_iterator begin,
               std::vector <GAME::Object>::const_iterator end);

protected:
  /**
   * Data exchange method for tranfering information to and from
   * the dialog box controls.
   *
   * @param[in]     pDX         Pointer to the data exchange.
   */
  virtual void DoDataExchange (CDataExchange * pDX);

  virtual BOOL OnInitDialog (void);

  /// The selected item from the listbox.
  GAME::Object selection_;

private:
  void insert_item (const GAME::Object &, const std::string &);

  /// Display strategy for the dialog.
  Dialog_Display_Strategy * strategy_;

  /// The list control for the dialog.
  CListBox list_;

  /// The static control with the directions.
  CStatic directions_ctrl_;

  /// Title of the dialog box.
  std::string title_;

  /// Directions to display in dialog box.
  std::string directions_;

  /// Set of items for this dialog.
  std::vector <Object> items_;
};

}
}

#endif  // !defined _GAME_SELECTION_LIST_DIALOG_H_
