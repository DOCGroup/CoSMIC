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
  Selection_List_Dialog_T (Dialog_Display_Strategy * strategy = 0,
                           CWnd * parent = 0);

  virtual ~Selection_List_Dialog_T (void);

  void insert (std::vector <T> & items);

  T selection (void) const;
};

}
}

#include "Selection_List_Dialog_T.cpp"

#endif  // !defined _GAME_DIALOGS_SELECTION_LIST_T_H_
