// $Id$

namespace GAME
{
namespace Dialogs
{

//
// Selection_List_Dialog_T
//
template <typename T>
Selection_List_Dialog_T <T>::
Selection_List_Dialog_T (Dialog_Display_Strategy * strategy, CWnd * parent)
: Selection_List_Dialog (strategy, parent)
{
}

//
// Selection_List_Dialog_T
//
template <typename T>
Selection_List_Dialog_T <T>::~Selection_List_Dialog_T (void)
{
}

//
// insert
//
template <typename T>
void Selection_List_Dialog_T <T>::insert (std::vector <T> & items)
{
  std::vector <T>::iterator
    iter = items.begin (), iter_end = items.end ();

  for (; iter != iter_end; ++ iter)
    Selection_List_Dialog::insert (*iter);
}

//
// selection
//
template <typename T>
T Selection_List_Dialog_T <T>::selection (void) const
{
  return T::_narrow (this->selection_);
}

}
}
