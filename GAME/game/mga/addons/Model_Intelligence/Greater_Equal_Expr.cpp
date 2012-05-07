// $Id$

#include "StdAfx.h"
#include "Greater_Equal_Expr.h"
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
Greater_Equal_Expr::Greater_Equal_Expr (Value_Expr *left, Value_Expr *right)
: lhs_ (left),
  rhs_ (right)
{
}

//
// Destructor
//
Greater_Equal_Expr::~Greater_Equal_Expr (void)
{
}

//
// evaluate (The user selection from dialog is not yet functional)
//
bool Greater_Equal_Expr::evaluate (Ocl_Context & res)
{
  // flag to decide the case
  size_t flag = 0;
  bool ret = false;

	if (res.model_constraint)
	{

		// Checking if the local variables are mutable/non-mutable
		if (this->lhs_->is_mutable () && !this->rhs_->is_mutable ())
			flag = 1;
		else if (!this->lhs_->is_mutable () && this->rhs_->is_mutable ())
			flag = 2;
		else if (this->lhs_->is_mutable () && this->rhs_->is_mutable ())
			flag = 3;

		switch (flag) {

			case 1:
				{
					if (this->lhs_->evaluate (res)->is_lesser (this->rhs_->evaluate (res)))
					 {
						 // Counting the number of objects to be added
						 double count;
						 this->rhs_->evaluate (res)->get_diff (this->lhs_->evaluate (res), count);

						 Expr_Command *cmd = new Add_Command (res.model_object,
																									res.target_metaroles,
																									count);

						 //Pushing adding operation to the action list
						 res.actions.push_back (cmd);
						 ret = true;
					 }
					break;
				}
			case 2:
				{
					if (this->lhs_->evaluate (res)->is_greater (this->rhs_->evaluate (res)))
					{
						// Counting the number of objects to be added
						double count;
						this->lhs_->evaluate (res)->get_diff (this->rhs_->evaluate (res), count);

						Expr_Command *cmd = new Add_Command (res.model_object,
																								 res.target_metaroles,
																								 count);

						//Pushing adding operation to the action list
						res.actions.push_back (cmd);
						ret = true;
					}
					break;
				}
			case 3:
				{
					// user is given a choice in dialog 
				}
			default:
				{
					//throw an exception
				}
		}
	}
	else
		ret = this->lhs_->evaluate (res)->is_greater_equal (this->rhs_->evaluate (res));

  return ret;
}

//
// filter_evaluate
//
bool Greater_Equal_Expr::filter_evaluate (Ocl_Context &res, 
                                          GAME::Mga::FCO &current)
{
  res.cur_fco = current;
  bool ret = false;

  if (this->lhs_->is_filter () || this->rhs_->is_filter ())
  {
    ret = this->lhs_->filter_evaluate (res)->is_greater_equal (this->rhs_->filter_evaluate (res));
  }

  return ret;
}

//
// list_add
//
bool Greater_Equal_Expr::list_add (GAME::Mga::Model &obj, 
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
bool Greater_Equal_Expr::list_delete (GAME::Mga::Model &obj, 
                                      size_t count, 
                                      GAME::Mga::Meta::FCO &metatype, 
                                      GAME::Mga::Meta::Role &metarole)
{
  return true;
}
