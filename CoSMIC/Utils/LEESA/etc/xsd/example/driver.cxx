// file      : examples/cxx/tree/library/driver.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : not copyrighted - public domain

#include <memory>   // std::auto_ptr
#include <iostream>

#include "library.hpp"

#define SCHEMA_NAMESPACE_FOR_LEESA library
#include "LEESA.h"

using std::cerr;
using std::endl;

library::catalog::book_sequence
foo (const library::catalog & c)
{
  using namespace LEESA;
  using namespace library;
  BOOST_AUTO(expr, catalog() >> book());
  catalog::book_sequence b = evaluate(c, expr);
  return b;
}

bool starts_with_s (library::name const & n)
{
  return (n[0] == 'S');
}

void print (library::name const & n)
{
  std::cout << n << endl;
}

LEESA::ContainerGen<library::name>::type
bar (const library::catalog & c)
{
  using namespace LEESA;
  using namespace library;
  BOOST_AUTO(expr, catalog() >> book() >> author() >> name() 
                   >> ForEach(name(), print)
                   >> Select(name(), starts_with_s));
  ContainerGen<name>::type names = evaluate(c, expr);
  return names;
}

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "usage: " << argv[0] << " library.xml" << endl;
    return 1;
  }

  try
  {
    using namespace library;

    // Read in the XML file and obtain its object model.
    //
    std::auto_ptr<catalog> c (catalog_ (argv[1]));
    catalog::book_sequence b1 = foo (*c);

    // Let's print what we've got.
    //
    for (catalog::book_const_iterator bi (b1.begin ());
         bi != b1.end ();
         ++bi)
    {
      cerr << endl
           << "ID           : " << bi->id () << endl
           << "ISBN         : " << bi->isbn () << endl
           << "Title        : " << bi->title () << endl
           << "Genre        : " << bi->genre () << endl;

      for (book::author_const_iterator ai (bi->author ().begin ());
           ai != bi->author ().end ();
           ++ai)
      {
        cerr << "Author       : " << ai->name () << endl;
        cerr << "  Born       : " << ai->born () << endl;

        if (ai->died ())
          cerr << "  Died       : " << *ai->died () << endl;

        //if (ai->recommends ())
        //  cerr << "  Recommends : " << (*ai->recommends ())->title () << endl;
      }

      cerr  << "Available    : " << std::boolalpha << bi->available () << endl;
    }

    LEESA::ContainerGen<name>::type names = bar(*c);
    for (LEESA::ContainerGen<name>::type::const_iterator i(names.begin());
         i != names.end(); ++i)
    {
      std::cout << *i << endl;
    }   

    return 0;  
  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}
