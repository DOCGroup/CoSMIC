// $Id: Add_Command.cpp 2907 2012-06-07 21:35:18Z tpati $

#include "StdAfx.h"
#include "Add_Command.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"
#include <sstream>

//
// Constructor
//
Add_Command::Add_Command (GAME::Mga::Model parent_model,
                          std::vector <GAME::Mga::Meta::Role> target_metaroles,
                          double count)
: parent_model_ (parent_model),
  target_metaroles_ (target_metaroles),
  count_ (count)
{
}

//
// Destructor
//
Add_Command::~Add_Command (void)
{
}

//
// execute
//
bool Add_Command::execute (void)
{
  std::vector <GAME::Mga::Meta::Role>::iterator
    roleit = target_metaroles_.begin (), roleit_end = target_metaroles_.end ();

  // Adding elements according to their roles
  if (target_metaroles_.size () == 1)
  {
    for (;roleit != roleit_end; roleit++)
    {
      if ((*roleit)->kind ()->type () == OBJTYPE_MODEL)
      {
        for (; this->count_ != 0; -- this->count_)
        {
          GAME::Mga::Model new_model =
            GAME::Mga::Model_Impl::_create (this->parent_model_, (*roleit));

          std::ostringstream ostr;
          ostr << (*roleit)->name () << this->count_;
          new_model->name (ostr.str ());
        }
      }
      else if ((*roleit)->kind ()->type () == OBJTYPE_ATOM)
      {
        for (; this->count_ != 0; -- this->count_)
        {
          GAME::Mga::Atom new_atom =
            GAME::Mga::Atom_Impl::_create (this->parent_model_, (*roleit));

          std::ostringstream ostr;
          ostr << (*roleit)->name () << this->count_;
          new_atom->name (ostr.str ());
        }
      }
      else if ((*roleit)->kind ()->type () == OBJTYPE_REFERENCE)
      {
        for (; this->count_ != 0; -- this->count_)
        {
          GAME::Mga::Reference new_reference =
            GAME::Mga::Reference_Impl::_create (this->parent_model_, (*roleit));

          std::ostringstream ostr;
          ostr << (*roleit)->name () << this->count_;
          new_reference->name (ostr.str ());
        }
      }
      else if ((*roleit)->kind ()->type () == OBJTYPE_SET)
      {
        for (; this->count_ != 0; -- this->count_)
        {
          GAME::Mga::Set new_set =
            GAME::Mga::Set_Impl::_create (this->parent_model_, (*roleit));

          std::ostringstream ostr;
          ostr << (*roleit)->name () << this->count_;
          new_set->name (ostr.str ());
        }
      }
    }
  }
  else
  {
    std::vector <GAME::Mga::Meta::FCO> metafcos;
    GAME::Mga::Meta::FCO select;
    for (;roleit != roleit_end; roleit++)
      metafcos.push_back ((*roleit)->kind ());

    for (; this->count_ != 0; -- this->count_)
    {
      AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

      // Create the dialog and pass in the data
      using GAME::Dialogs::Selection_List_Dialog_T;
      Selection_List_Dialog_T <GAME::Mga::Meta::FCO> dlg (0, ::AfxGetMainWnd (), 1);
      dlg.title ("Inherited MetaFCO type object you want to add to the model");
      dlg.directions ("Select the desired MetaFCO object");
      dlg.meta_insert (metafcos);

      if (IDOK != dlg.DoModal ())
        return false;

      select = dlg.meta_selection ();

      if (select.is_nil ())
        continue;

      GAME::Mga::FCO fco;

      switch (select->type ())
      {
      case OBJTYPE_MODEL:
        fco = GAME::Mga::Model_Impl::_create (this->parent_model_, select->name ());
        break;

      case OBJTYPE_ATOM:
        fco = GAME::Mga::Atom_Impl::_create (this->parent_model_, select->name ());
        break;

      case OBJTYPE_REFERENCE:
        fco = GAME::Mga::Reference_Impl::_create (this->parent_model_, select->name ());
        break;

      case OBJTYPE_SET:
        fco = GAME::Mga::Set_Impl::_create (this->parent_model_, select->name ());
        break;

      default:
        throw GAME::Mga::Exception ("selected type is not supported");
      }

      // Set the name of the new FCO.
      std::ostringstream ostr;
      ostr << (*roleit)->name () << this->count_;
      fco->name (ostr.str ());
    }
  }

  return true;
}