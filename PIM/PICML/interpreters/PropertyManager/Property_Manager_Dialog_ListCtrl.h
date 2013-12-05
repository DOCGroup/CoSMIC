// -*- C++ -*-

//=============================================================================
/**
 * @file      Property_Manager_Dialog_ListCtrl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_PROPERTY_MANAGER_LISTCTRL_DIALOG_H_
#define _PICML_PROPERTY_MANAGER_LISTCTRL_DIALOG_H_

#include "game/mga/Model.h"

// Forward decl.
class Data_Item;

/**
 * @class PICML_Property_Manager_ListCtrl
 */
class PICML_Property_Manager_ListCtrl : public CListCtrl
{
public:
  PICML_Property_Manager_ListCtrl (void);

  virtual ~PICML_Property_Manager_ListCtrl (void);

  /// Initialize the columns for the control.
  BOOL InitControl (void);

  void SetProperty (const GAME::Mga::FCO_in prop);

protected:
  void handle_name_click (const LVHITTESTINFO & testinfo);

  void handle_value_click (const LVHITTESTINFO & testinfo);

  virtual void DrawItem (LPDRAWITEMSTRUCT item);

  afx_msg void OnLButtonDown (UINT flags, CPoint point);

  afx_msg void OnContextMenu (CWnd * parent, CPoint point);

  afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

  afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

  afx_msg void OnInitMenuPopup (CMenu * popup, UINT index, BOOL sysmenu);

  afx_msg void OnCommand_DeleteItem (void);

  afx_msg void OnCommand_MoveUp (void);

  afx_msg void OnCommand_MoveDown (void);

private:
  void end_label_edit (void);

  void collapse_item (int item);

  void swap_item_data (int i, int j);

  DECLARE_MESSAGE_MAP ();

  /// Target value of the operation.
  GAME::Mga::FCO prop_;

  /// Delete item of the operation.
  int target_item_;

  /// Delete index of the operation.
  int target_index_;

  /// Index of the parent.
  int parent_item_;

  /// Global listview item structure.
  LVITEM lvitem_;

  Data_Item * active_item_;
};

#endif  // !defined _PICML_PROPERTY_MANAGER_DIALOG_H_
