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
void Selection_List_Dialog_T <T>::insert (const std::vector <T> & items)
{
  this->insert (items.begin (), items.end ());
}

//
// insert
//
template <typename T>
void Selection_List_Dialog_T <T>::
insert (typename std::vector <T>::const_iterator begin,
        typename std::vector <T>::const_iterator end)
{
  for (; begin != end; ++ begin)
    Selection_List_Dialog::insert (Object_in (begin->get ()));
}

//
// selection
//
template <typename T>
T Selection_List_Dialog_T <T>::selection (void)
{
  return T::_narrow (this->selection_);
}

}
}
