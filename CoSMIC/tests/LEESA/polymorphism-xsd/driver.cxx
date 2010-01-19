// file      : examples/cxx/tree/polymorphism/driver.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : not copyrighted - public domain

#include <memory>   // std::auto_ptr
#include <iostream>

#include "supermen.hxx"
#include "supermen-meta.hxx"
#include "LEESA.h"

using std::cerr;
using std::endl;
using std::auto_ptr;

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "usage: " << argv[0] << " supermen.xml" << endl;
    return 1;
  }

  try
  {
    auto_ptr<supermen> sm (supermen_ (argv[1]));

    supermen copy (*sm); // Dynamic types are preserved in copies.

    // Print what we've got.
    //
    using namespace LEESA;
    
    supermen::person_sequence person_seq = evaluate(copy, supermen() >> person());
    for (supermen::person_const_iterator i (person_seq.begin ());
         i != person_seq.end ();
         ++i)
    {
      cerr << i->name ();

      if (const superman* s = dynamic_cast<const superman*> (&*i))
      {
        if (s->can_fly ())
          cerr << ", flying superman";
        else
          cerr << ", superman";
      }

      cerr << endl;
    }

    ::ContainerTraits<superman>::Container superman_seq; 
      evaluate(copy, supermen() >> person() >> CastFromTo(person(), superman()));
    person_seq = copy.person();
    for (::ContainerTraits<superman>::Container::const_iterator i (superman_seq.begin ());
         i != superman_seq.end ();
         ++i)
    {
      cerr << i->name ();
      if (i->can_fly ())
        cerr << ", flying superman";
      else
        cerr << ", superman";

      cerr << endl;
    }

    // Serialize back to XML.
    //
    xml_schema::namespace_infomap map;
    map[""].schema = "supermen.xsd";

    supermen_ (std::cout, copy, map);
  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}
