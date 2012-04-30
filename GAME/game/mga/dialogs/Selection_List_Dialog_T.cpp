// $Id$

namespace GAME
{
namespace Dialogs
{

//
// Selection_List_Dialog_T
//
template <typename T>
GAME_INLINE
Selection_List_Dialog_T <T>::
Selection_List_Dialog_T (Dialog_Display_Strategy * strategy, CWnd * parent)
: Selection_List_Dialog (strategy, parent)
{
}

//
// Selection_List_Dialog_T
//
template <typename T>
GAME_INLINE
Selection_List_Dialog_T <T>::~Selection_List_Dialog_T (void)
{
}

//
// insert
//
template <typename T>
GAME_INLINE
void Selection_List_Dialog_T <T>::insert (const std::vector <T> & items)
{
  using GAME::Mga::make_impl_iter;
  this->insert (make_impl_iter (items.begin ()), make_impl_iter (items.end ()));
}

//
// insert
//
template <typename T>
template <typename ITER>
GAME_INLINE
void Selection_List_Dialog_T <T>::insert (ITER begin, ITER end)
{
  for (; begin != end; ++ begin)
    Selection_List_Dialog::insert (*begin);
}

//
// selection
//
template <typename T>
GAME_INLINE
T Selection_List_Dialog_T <T>::selection (void)
{
  return T::_narrow (this->selection_);
}

}
}
