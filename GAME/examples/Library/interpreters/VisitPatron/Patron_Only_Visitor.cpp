// $Id$

#include "StdAfx.h"
#include "Patron_Only_Visitor.h"

#include "Library/Library/Patron.h"
#include "Library/Library/Library.h"

#include "boost/bind.hpp"
#include <algorithm>

//
// Patron_Only_Visitor
//
Patron_Only_Visitor::Patron_Only_Visitor (void)
{

}

//
// ~Patron_Only_Visitor
//
Patron_Only_Visitor::~Patron_Only_Visitor (void)
{

}

//
// visit_RootFolder
//
void Patron_Only_Visitor::
visit_RootFolder (GAME::Mga::RootFolder_in r)
{
  // Visit all the chilren in the root folder.
  std::vector <GAME::Mga::Object> objs;
  r->children (objs);

  std::for_each (objs.begin (),
                 objs.end (),
                 boost::bind (&GAME::Mga::Object::impl_type::accept,
                              boost::bind (&GAME::Mga::Object::get, _1),
                              this));
}


//
// visit_Patron
//
void Patron_Only_Visitor::visit_Library (Library::Library_in l)
{
  // Get all the patrons in this model.
  std::vector <Library::Patron> patrons;
  l->get_Patrons (patrons);

  std::for_each (patrons.begin (),
                 patrons.end (),
                 boost::bind (&Library::Patron::impl_type::accept,
                              boost::bind (&Library::Patron::get, _1),
                              this));
}

//
// visit_Patron
//
void Patron_Only_Visitor::visit_Patron (Library::Patron_in p)
{
  ::AfxMessageBox (p->path ("/").c_str ());
}
