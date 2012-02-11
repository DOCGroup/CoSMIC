// $Id$

#include "StdAfx.h"

#include "Equal_Expr.h"
#include "game/mga/Atom.h"
#include "MetaAtom.h"
#include "game/mga/Model.h"
#include "MetaModel.h"
#include "MetaFCO.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"
#include <string>

#include "Add_Command.h"
#include "Expr_Command.h"

//
// Constructor
//
Equal_Expr::Equal_Expr (Value_Expr *left, Value_Expr *right)
: lhs_ (left),
  rhs_ (right)
{
}

//
// Destructor
//
Equal_Expr::~Equal_Expr (void)
{
}

//
// evaluate (The user selection from dialog is not yet functional)
//
bool Equal_Expr::evaluate (Ocl_Context & res)
{

  // flag to decide the case
  size_t flag = 0;
  bool ret = false;

  // Checking if the local variables are mutable/non-mutable
  if ((this->lhs_->ismutable () == true) && (this->rhs_->ismutable () == false))
    flag = 1;
  else if ((this->lhs_->ismutable () == false) && (this->rhs_->ismutable () == true))
    flag = 2;
  else if ((this->lhs_->ismutable () == true) && (this->rhs_->ismutable () == true))
    flag = 3;
 
  switch (flag) {

    case 1:
      {
        if (this->lhs_->evaluate (res) < this->rhs_->evaluate (res))
         {
           // Counting the number of objects to be added
           size_t count = this->rhs_->evaluate (res) - this->lhs_->evaluate (res);

           Expr_Command *cmd = new Add_Command (res.model_object,
                                                res.target_metarole,
                                                res.target_metarole->kind (),
                                                count);

           //Pushing adding operation to the action list
           res.actions.push_back (cmd);
         }
         else
         {
           size_t count = this->lhs_->evaluate (res) - this->rhs_->evaluate (res);
           // Delete objects operation to be called
           
         }    
         break;
      }
    case 2:
      {
        if (this->lhs_->evaluate (res) > this->rhs_->evaluate (res))
        {
          // Counting the number of objects to be added
          size_t count = this->lhs_->evaluate (res) - this->rhs_->evaluate (res);

          Expr_Command *cmd = new Add_Command (res.model_object,
                                               res.target_metarole,
                                               res.target_metarole->kind (),
                                               count);

          //Pushing adding operation to the action list
          res.actions.push_back (cmd);
          ret = true;
        }
        else
        {
          size_t count = this->rhs_->evaluate (res) - this->lhs_->evaluate (res);
          // Delete objects operation to be called
          ret = true;
          
        }
        break;
      }
    case 3:
      { /*
        //Evaluating left hand side
        size_t left_count = this->lhs_->evaluate (obj, res);
        GAME::Mga::Meta::FCO left_metatype = res.target_metarole->kind ();
        GAME::Mga::Meta::Role left_metarole = res.target_metarole;

        //Evaluating right hand side
        size_t right_count = this->rhs_->evaluate (obj, res);
        GAME::Mga::Meta::FCO right_metatype = res.target_metarole->kind ();
        GAME::Mga::Meta::Role right_metarole = res.target_metarole;

        if (left_count == right_count)
          ret = true;
        else if (left_count < right_count)
        {
          size_t count = right_count - left_count;
          std::vector <std::string> options;
          options.push_back ("Add " + left_metatype->name ());
          options.push_back ("Delete" + right_metatype->name ());
          std::string select;

          if (1 == options.size ())
            select = options.front ();
          else
          {
            AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

            // Create the dialog and pass in the data
            using GAME::Dialogs::Selection_List_Dialog_T;
            Selection_List_Dialog_T <std::string> dlg (0, ::AfxGetMainWnd ());
            dlg.title ("Object Addition/Deletion Resolver");
            dlg.directions ("Select the desired action");
            dlg.insert (options);

            if (IDOK != dlg.DoModal ())
              return false;

            select = dlg.selection ();
          }

          if (!select.empty ())
          {
            if (select == ("Add " + left_metatype->name ()))
              ret = list_add (obj, left_count, left_metatype, left_metarole);
            else
              ret = list_delete (obj, right_count, right_metatype, right_metarole);
          }
        }
        else
        {
          size_t count = left_count - right_count;
          std::vector <std::string> options;
          options.push_back ("Add " + left_metatype->name ());
          options.push_back ("Delete" + right_metatype->name ());
          std::string select;

          if (1 == options.size ())
            select = options.front ();
          else
          {
            AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

            // Create the dialog and pass in the data
            using GAME::Dialogs::Selection_List_Dialog_T;
            Selection_List_Dialog_T <std::string> dlg (0, ::AfxGetMainWnd ());
            dlg.title ("Object Addition/Deletion Resolver");
            dlg.directions ("Select the desired action");
            dlg.insert (options);

            if (IDOK != dlg.DoModal ())
              return false;

            select = dlg.selection ();
          }

          if (!select.empty ())
          {
            if (select == ("Add " + left_metatype->name ()))
              ret = list_add (obj, right_count, right_metatype, right_metarole);
            else
              ret = list_delete (obj, left_count, left_metatype, left_metarole);
          }
        }*/
        break;
      }
    default:
      {
        // throw an exception & return false
      }
  }

  return ret;
}


//
// list_add
//
bool Equal_Expr::list_add (GAME::Mga::Model &obj, 
                           size_t count, 
                           GAME::Mga::Meta::FCO &metatype, 
                           GAME::Mga::Meta::Role &metarole)
{
  if (metatype->type () == OBJTYPE_MODEL)
    {
      for (; count != 0; -- count)
        {
          GAME::Mga::Model new_model = GAME::Mga::Model_Impl::_create (obj, metarole);
          char c = '0' + count;
          new_model->name (metarole->name () + c);
        }
    }
  else if (metatype->type () == OBJTYPE_ATOM)
    {
      for (; count != 0; -- count)
        {
          GAME::Mga::Atom new_atom = GAME::Mga::Atom_Impl::_create (obj, metarole);
          char c = '0' + count;
          new_atom->name (metarole->name () + c);
        }
    }

  return true;
}

//
// list delete
//
bool Equal_Expr::list_delete (GAME::Mga::Model &obj, 
                              size_t count, 
                              GAME::Mga::Meta::FCO &metatype, 
                              GAME::Mga::Meta::Role &metarole)
{
  return true;
}