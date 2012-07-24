// $Id$

#include "StdAfx.h"
#include "Exists_Iterator.h"
#include "Boolean_Value.h"
#include "Object_Value.h"

//
// Constructor
//
Exists_Iterator::Exists_Iterator (void)
{
}

//
// Destructor
//
Exists_Iterator::~Exists_Iterator (void)
{
}

//
// evaluate
//
Value * Exists_Iterator::evaluate (Ocl_Context & res,
                                   std::vector <GAME::Mga::FCO> & coll,
                                   std::vector <std::string> & decl,
                                   std::string & decltype,
                                   Boolean_Expr * expr)
{
  int count = 0;
  if (coll.size() == 0)
    return new Boolean_Value (true);
  else
  {
    switch (decl.size ())
    {
    case 0:
      {
        std::vector<GAME::Mga::FCO>::iterator
          xit = coll.begin (), xit_end = coll.end ();

        for (;xit != xit_end; ++xit)
        {
          if (expr->evaluate (res))
            count++;
        }
        break;
      }

    case 1:
      {
        std::vector <GAME::Mga::FCO>::iterator
          xit = coll.begin (), xit_end = coll.end ();

        for (;xit != xit_end; ++xit)
        {
          res.locals[decl[0]] = new Object_Value (*(xit));
          if (expr->evaluate (res))
            count++;
        }
        break;
      }
    case 2:
      {
        for (size_t i = 0; i < coll.size (); i++)
        {
          for (size_t j = i+1; j < coll.size (); j++)
          {
            // Setting value for first variable
            res.locals[decl[0]] = new Object_Value (coll[i]);

            // Setting value for second variable
            res.locals[decl[1]] = new Object_Value (coll[j]);

            if (expr->evaluate (res))
              count++;
          }
        }
        break;
      }
    default:
      return new Boolean_Value (false);
    }
  }

  if (count >= 1)
    return new Boolean_Value (true);

  return new Boolean_Value (false);
}

//
// dummy evaluate (as ForAll gets Boolean expression)
//
Value * Exists_Iterator::evaluate(Ocl_Context & res, 
                                  std::vector<GAME::Mga::FCO> & coll, 
                                  std::vector<std::string> & decl, 
                                  std::string & decltype, 
                                  Value_Expr * valexpr)
{
  return new Boolean_Value (false);
}

//
// is_association
//
bool Exists_Iterator::is_association (void)
{
  return true;
}

//
// is_containment
//
bool Exists_Iterator::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool Exists_Iterator::is_reference (void)
{
  return false;
}