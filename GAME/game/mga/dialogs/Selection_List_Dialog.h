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
#include "game/mga/Object.h"
#include "game/mga/MetaBase.h"

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
  Mga::Object selection (void);

  /**
   * Set the dialog's title.
   *
   * @param[in]     str         The dialog's title.
   */
  void title (const char * str);

  /**
   * Set the dialog's directions that are displayed to the user.
   *
   * @param[in]     str         The dialog's directions.
   */
  void directions (const char * str);

  /**
   * Insert a new object into the dialog.
   *
   * @param[in]     object        The new object.
   */
  void insert (const Mga::Object_in object);

  /**
   * Insert a new meta object into the dialog.
   *
   * @param[in]     metabase        The new object.
   */
  void meta_insert (const GAME::Mga::Meta::Base_in metabase);

  /**
   * Insert a collection of objects into the dialog listing.
   *
   * @param[in]     items         Collection of objects
   */
  void insert (const std::vector <Mga::Object> & items);

  /**
   * Insert a collection of metaobjects into the dialog listing.
   *
   * @param[in]     metaitems         Collection of objects
   */
  void meta_insert (const std::vector <GAME::Mga::Meta::Base> & metaitems);

  /**
   * @overloaded
   *
   * @param[in]     begin         Start of collection
   * @param[in]     end           End of collection
   */
  void insert (std::vector <Mga::Object>::const_iterator begin,
               std::vector <Mga::Object>::const_iterator end);

  /**
   * @overloaded
   *
   * @param[in]     begin         Start of collection
   * @param[in]     end           End of collection
   */
  void meta_insert (std::vector <GAME::Mga::Meta::Base>::const_iterator begin,
                    std::vector <GAME::Mga::Meta::Base>::const_iterator end);

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
  Mga::Object selection_;

private:
  void insert_item (const Mga::Object_in &, const std::string &);

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
  std::vector <Mga::Object> items_;

  /// Set of metaitems for this dialog.
  std::vector <GAME::Mga::Meta::Base> metaitems_;
};

}
}

#endif  // !defined _GAME_SELECTION_LIST_DIALOG_H_
