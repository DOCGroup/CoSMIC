// $Id$

#include "StdAfx.h"
#include "Lesser_Equal_Expr.h"
#include "game/mga/Atom.h"
#include "MetaAtom.h"
#include "game/mga/Model.h"
#include "MetaModel.h"
#include "MetaFCO.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"
#include <string>

#include "Attribute_Expr.h"
#include "Attribute_Add_Command.h"
#include "Object_Value.h"
#include "Int_Value.h"

//
// Constructor
//
Lesser_Equal_Expr::Lesser_Equal_Expr (Value_Expr *left, Value_Expr *right)
: lhs_ (left),
  rhs_ (right)
{
}

//
// Destructor
//
Lesser_Equal_Expr::~Lesser_Equal_Expr (void)
{
}

//
// evaluate
//
bool Lesser_Equal_Expr::evaluate (Ocl_Context & res)
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
					if (this->lhs_->evaluate (res)->is_greater (this->rhs_->evaluate (res)))
					 {
						 // Counting the number of objects to be deleted
						 double count;
						 this->rhs_->evaluate (res)->get_diff (this->lhs_->evaluate (res), count);

						 // Calling the delete command
						 ret = true;
					 }
					break;
				}
			case 2:
				{
					if (this->lhs_->evaluate (res)->is_lesser (this->rhs_->evaluate (res)))
					{
						// Counting the number of objects to be deleted
						double count;
						this->lhs_->evaluate (res)->get_diff (this->rhs_->evaluate (res), count);

						// Calling the delete command
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
					ret = true;
				}
		}
	}
  else if (res.model_attributes)
  {
    // Assumption for now is that the attribute_expression is lhs and constant_value_expr
    // is rhs

    // Caller
    std::string obj = "";
    // Attribute name
    std::string name = "";


    // Performing the automated attribute value setting only if
    // the constraint contains attribute i.e. either lhs or rhs has attribute
    Attribute_Expr * left = dynamic_cast <Attribute_Expr *> (this->lhs_);
    Attribute_Expr * right = dynamic_cast <Attribute_Expr *> (this->rhs_);

    if (left != 0 || right != 0 )
    {
      if (left != 0)
      {
        name = left->attribute_name ();
        obj = left->caller ();
      }
      else
      {
        name = right->attribute_name ();
        obj = right->caller ();
      }

      GAME::Mga::FCO fco;

      // Checking the invoking object for the attribute
      if (obj == "self")
        fco = GAME::Mga::FCO::_narrow (res.self);
      else
      {
        // The object value associated with the local variable is taken from map
        // and is used for attribute value calculation
        Object_Value * iv = dynamic_cast <Object_Value *> (res.locals [obj]);
        fco = GAME::Mga::FCO::_narrow (iv->value ());
      }

      if (!this->lhs_->evaluate (res)->is_lesser_equal (this->rhs_->evaluate (res)))
      {
        Expr_Command *cmd = new Attribute_Add_Command (fco, name, new Int_Value (0));

        //Pushing adding operation to the action list
        res.actions.push_back (cmd);
      }
      ret = true;
    }
    else
      ret = this->lhs_->evaluate (res)->is_lesser_equal (this->rhs_->evaluate (res));
    
  }
	else
		ret = this->lhs_->evaluate (res)->is_greater_equal (this->rhs_->evaluate (res));

	return ret;
}

//
// filter_evaluate
//
bool Lesser_Equal_Expr::filter_evaluate (Ocl_Context &res, 
                                         GAME::Mga::FCO &current)
{
  res.cur_fco = current;
  bool ret = false;

  if (this->lhs_->is_filter () || this->rhs_->is_filter ())
  {
    ret = this->lhs_->filter_evaluate (res)->is_lesser_equal (this->rhs_->filter_evaluate (res));
  }

  return ret;
}

//
// list_add
//
bool Lesser_Equal_Expr::list_add (GAME::Mga::Model &obj, 
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
bool Lesser_Equal_Expr::list_delete (GAME::Mga::Model &obj, 
                                     size_t count, 
                                     GAME::Mga::Meta::FCO &metatype, 
                                     GAME::Mga::Meta::Role &metarole)
{
  return true;
}
