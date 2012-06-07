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
Selection_List_Dialog_T (Dialog_Display_Strategy * strategy, CWnd * parent, int type)
: Selection_List_Dialog (strategy, parent, type)
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
// meta_insert
//
template <typename T>
GAME_INLINE
void Selection_List_Dialog_T <T>::meta_insert (const std::vector<T> & metaitems)
{
  using GAME::Mga::make_impl_iter;
  this->meta_insert (make_impl_iter (metaitems.begin ()), make_impl_iter (metaitems.end ()));
}

//
// string_insert
//
template <typename T>
GAME_INLINE
void Selection_List_Dialog_T <T>::string_insert (const std::vector<T> & strs)
{
  this->string_insert (strs.begin (), strs.end ());
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
// meta_insert
//
template <typename T>
template <typename ITER>
GAME_INLINE
void Selection_List_Dialog_T <T>::meta_insert (ITER begin, ITER end)
{
  for (; begin != end; ++ begin)
    Selection_List_Dialog::meta_insert (*begin);
}

//
// string_insert
//
template <typename T>
template <typename ITER>
GAME_INLINE
void Selection_List_Dialog_T <T>::string_insert (ITER begin, ITER end)
{
  for (; begin != end; ++ begin)
    Selection_List_Dialog::string_insert (*begin);
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

//
// meta_selection
//
template <typename T>
GAME_INLINE
T Selection_List_Dialog_T <T>::meta_selection (void)
{
  return T::_narrow (this->metaselection_);
}

}
}
