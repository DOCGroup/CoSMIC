// -*- C++ -*-

//=============================================================================
/**
 *  @file       Selection_List_Dialog_T.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _GAME_DIALOGS_SELECTION_LIST_T_H_
#define _GAME_DIALOGS_SELECTION_LIST_T_H_

#include "Selection_List_Dialog.h"

namespace GAME
{
namespace Dialogs
{
/**
 * @class Selection_List_Dialog_T
 *
 * Template version of the selection list dialog. This version
 * allows you to use concrete types, as long as all the items
 * are of the same type.
 */
template <typename T>
class Selection_List_Dialog_T : public Selection_List_Dialog
{
public:
  /**
   * Initializing constructor
   *
   * @param[in]         strategy          Display strategy for dialog
   * @param[in]         parent            The parent window.
   */
  Selection_List_Dialog_T (Dialog_Display_Strategy * strategy = 0,
                           CWnd * parent = 0,
                           int type = 0);

  /// Destructor.
  virtual ~Selection_List_Dialog_T (void);

  void insert (const std::vector <T> & items);

  void meta_insert (const std::vector <T> & metaitems);

  void string_insert (const std::vector <T> & strs);

  template <typename ITER>
  void insert (ITER begin, ITER end);

  template <typename ITER>
  void meta_insert (ITER begin, ITER end);

  template <typename ITER>
  void string_insert (ITER begin, ITER end);

  /// Get the current selection.
  T selection (void);

  /// Get the current meta selection.
  T meta_selection (void);
};

}
}

#include "Selection_List_Dialog_T.cpp"

#endif  // !defined _GAME_DIALOGS_SELECTION_LIST_T_H_
