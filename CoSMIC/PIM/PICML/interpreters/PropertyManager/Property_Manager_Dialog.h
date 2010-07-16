// -*- C++ -*-

//=============================================================================
/**
 * @file      PropertyManager_Dialog.h
 *
 * Main dialog for the Property Manager interpreter
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_PROPERTY_MANAGER_DIALOG_H_
#define _PICML_PROPERTY_MANAGER_DIALOG_H_

#include "Data_Type_Dispatcher.h"

// Forward decl.
class PICML_Data_Value_Control;
class PICML_Sequence_Data_Value;

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

  void SetProperty (const PICML::Property & prop);

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

  int find_prev_item (int item);

  int find_next_item (int item);

  int find_item_i (int item, int step);

  void swap_item_data (int i, int j);

  DECLARE_MESSAGE_MAP ();

  PICML_Data_Value_Control * edit_control_;

  /// Target value of the operation.
  PICML::DataValue target_value_;

  /// Delete item of the operation.
  int target_item_;

  /// Delete index of the operation.
  int target_index_;

  /// Index of the parent.
  int parent_item_;

  /// Global listview item structure.
  LVITEM lvitem_;
};

/**
 * @class PICML_Property_Manager_Dialog
 *
 * Main dialog for the data value manager addon. The dialog does not
 * contain any control for entering data values. Instead, the client
 * has to bind the dialog to a collection of PICML_DT_Control objects.
 */
class PICML_Property_Manager_Dialog : public CDialog
{
public:
  PICML_Property_Manager_Dialog (const PICML::Property & prop, CWnd * parent = 0);

  /// Destructor.
  virtual ~PICML_Property_Manager_Dialog (void);

protected:

  virtual void DoDataExchange (CDataExchange * pDX);

  virtual BOOL OnInitDialog (void);

private:
  DECLARE_MESSAGE_MAP ();

  /// Target property for the dialog.
  PICML::Property prop_;

  PICML_Property_Manager_ListCtrl listview_;
};

#endif  // !defined _PICML_PROPERTY_MANAGER_DIALOG_H_
