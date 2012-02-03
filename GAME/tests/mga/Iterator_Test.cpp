// $Id$

#include "stdafx.h"
#include "game/mga/Model.h"

#define BOOST_TEST_MODULE Template_Engine_Configuration_File_Test

#include "Test_Configuration.hpp"
//DECLARE_BOOST_TEST_CONFIG ("../logs");

//
// default_constructor
//
BOOST_AUTO_TEST_CASE (default_constructor)
{
  GAME::Mga::Iterator <GAME::Mga::Model> iter;
}

//
// model_children
//
BOOST_AUTO_TEST_CASE (model_children)
{
  GAME::Mga::Model m;
  GAME::Mga::Iterator <GAME::Mga::Model> iter = m->children <GAME::Mga::Model> ();
}

//
// copy_constructor
//
BOOST_AUTO_TEST_CASE (copy_constructor)
{
  GAME::Mga::Model m;
  GAME::Mga::Iterator <GAME::Mga::Model> iter = m->children <GAME::Mga::Model> ();
  GAME::Mga::Iterator <GAME::Mga::Model> iter2 (iter);
}

//
// operator_equal
//
BOOST_AUTO_TEST_CASE (operator_equal)
{
  GAME::Mga::Model m;
  GAME::Mga::Iterator <GAME::Mga::Model> iter = m->children <GAME::Mga::Model> ();
  GAME::Mga::Iterator <GAME::Mga::Model> iter2;

  iter2 = iter;
}

//
// item
//
BOOST_AUTO_TEST_CASE (item)
{
  GAME::Mga::Model m;
  GAME::Mga::Iterator <GAME::Mga::Model> iter = m->children <GAME::Mga::Model> ();

  GAME::Mga::Model m1 = iter.item ();
}

//
// items
//
BOOST_AUTO_TEST_CASE (items)
{
  GAME::Mga::Model m;
  GAME::Mga::Iterator <GAME::Mga::Model> iter = m->children <GAME::Mga::Model> ();

  std::vector <GAME::Mga::Model> v;
  iter.items (v);
}

//
// increment
//
BOOST_AUTO_TEST_CASE (increment)
{
  GAME::Mga::Model m;
  GAME::Mga::Iterator <GAME::Mga::Model> iter = m->children <GAME::Mga::Model> ();

  // Test prefix increment.
  ++ iter;

  // Test postfix increment.
  iter ++;
}

//
// dereference
//
BOOST_AUTO_TEST_CASE (dereference)
{
  GAME::Mga::Model m;
  GAME::Mga::Iterator <GAME::Mga::Model> iter = m->children <GAME::Mga::Model> ();

  const std::string name = (*iter)->name ();
  GAME::Mga::Model::impl_type * impl = iter->get ();
}

//
// equality
//
BOOST_AUTO_TEST_CASE (equality)
{
  GAME::Mga::Model m;
  GAME::Mga::Iterator <GAME::Mga::Model> iter1, iter2;

  bool r1 = iter1 == iter2;
  bool r2 = iter1 != iter2;
}
