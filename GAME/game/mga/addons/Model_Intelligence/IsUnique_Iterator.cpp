// $Id$

#include "StdAfx.h"
#include "IsUnique_Iterator.h"
#include "Boolean_Value.h"
#include "Object_Value.h"

//
// Constructor
//
IsUnique_Iterator::IsUnique_Iterator (void)
{
}

//
// Destructor
//
IsUnique_Iterator::~IsUnique_Iterator (void)
{
}

//
// dummy evaluate (as IsUnique uses value expressions)
//
Value * IsUnique_Iterator::evaluate(Ocl_Context & res, 
                                    std::vector <GAME::Mga::FCO> & coll, 
                                    std::vector <std::string> & decl, 
                                    std::string & decltype, 
                                    Boolean_Expr * expr)
{
  return new Boolean_Value (false);
}

//
// evaluate
//
Value * IsUnique_Iterator::evaluate (Ocl_Context & res,
                                     std::vector <GAME::Mga::FCO> & coll,
                                     std::vector <std::string> & decl,
                                     std::string & decltype,
                                     Value_Expr * valexpr)
{
  std::vector <Value *> allvalues;

  if (coll.size() == 0)
    return new Boolean_Value (true);
  else
  {
    switch (decl.size ())
    {
    case 0:
      {
        std::vector <GAME::Mga::FCO>::iterator
          xit = coll.begin (), xit_end = coll.end ();

        for (;xit != xit_end; ++xit)
        {
          allvalues.push_back (valexpr->evaluate (res));
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
          allvalues.push_back (valexpr->evaluate (res));
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

            allvalues.push_back (valexpr->evaluate (res));
          }
        }
        break;
      }
    default:
      return new Boolean_Value (false);
    }
  }

  // Checking the vector for duplicate values
  // Sorting is not an option as the vector can contain 
  // strings, booleans etc.
  for (int i = 0; i < allvalues.size (); ++i)
  {
    for (int j = i + 1; j < allvalues.size (); ++j)
    {
      if (allvalues[i]->is_equal (allvalues[j]))
        return new Boolean_Value (false);
    }
  }

  return new Boolean_Value (true);
}

//
// is_association
//
bool IsUnique_Iterator::is_association (void)
{
  return false;
}

//
// is_containment
//
bool IsUnique_Iterator::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool IsUnique_Iterator::is_reference (void)
{
  return false;
}