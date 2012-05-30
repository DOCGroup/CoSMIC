// $Id$

#include "StdAfx.h"
#include "IteratorCall_Expr.h"
#include "boost/bind.hpp"
#include "Object_Value.h"
#include "Collection_Value_T.h"
#include "game/mga/Filter.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/FCO.h"


//
// Constructor
//
IteratorCall_Expr::IteratorCall_Expr (Value_Expr * obj,
                                      Iterator * name,
                                      Boolean_Expr * expr)
:obj_(obj),
 name_(name),
 expr_(expr)
{
}

//
// Destructor
//
IteratorCall_Expr::~IteratorCall_Expr (void)
{
}

//
// evaluate
//
bool IteratorCall_Expr::evaluate (Ocl_Context &res)
{ 
  bool result = false;

  // Collect the value for the invoking collection
  Collection_Value_T<GAME::Mga::FCO> * cv = 
    dynamic_cast <Collection_Value_T<GAME::Mga::FCO> *> (this->obj_->evaluate (res));

  if (cv != 0)
  {
    std::vector<GAME::Mga::FCO> collection = cv->value ();

    if (this->dec_type_.size() > 0)
    {
      // Setting the values of declarators if they are there (max for two)
      // and storing them to the locals map to be used by expressions
      std::vector<GAME::Mga::FCO>::iterator 
        xit = collection.begin (), xit_end = collection.end ();

      switch (this->next_.size ()) {
        case 0:
          {
            result = this->expr_->evaluate (res);
            break;
          }
        case 1:
          {
            // Evaluating the expression against every possible value of the
            // declarator variable
            for (; xit != xit_end; ++xit)
            {
              res.locals[this->next_[0]] = new Object_Value (*(xit));
              result = this->expr_->evaluate (res);
            }
            break;
          }
        case 2:
          {
            // Evaluating the expression against every possible value of the
            // declarators available
            for (size_t i = 0; i < collection.size (); i++)
            {
              for (size_t j = i+1; j < collection.size (); j++)
              {
                // Setting value for first variable
                res.locals[this->next_[0]] = new Object_Value (collection[i]);
                // Setting value for second variable
                res.locals[this->next_[1]] = new Object_Value (collection[j]);
                
                result = this->expr_->evaluate (res);
              }
            }
            break;
          }
        default:
          result = false;
      }
    }
  }
	return result;	
}

//
// filter_evaluate
//
bool IteratorCall_Expr::filter_evaluate (Ocl_Context &res, GAME::Mga::FCO &current)
{ 
  bool result = false;

  std::string name = current->name ();

  switch (this->next_.size ()) {
    case 0:
    {
      result = this->expr_->filter_evaluate (res, current);
      break;
    }
    case 1:
    {
      result = this->expr_->filter_evaluate (res, current);
      break;
    }
    default:
      result = false;
  }
          
  return result;
}

//
// set_declarators
//
void IteratorCall_Expr::set_declarators (std::vector<std::string> & next)
{
  this->next_ = next;
}

//
// set_dec_type
//
void IteratorCall_Expr::set_dec_type (std::string & type)
{
  this->dec_type_ = type;
}