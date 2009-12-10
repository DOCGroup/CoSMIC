// file      : examples/cxx/tree/library/driver.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : not copyrighted - public domain

#include <memory>   // std::auto_ptr
#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <typeinfo>

#include "library.hxx"
#include "library-meta.hxx"
#include "LEESA.h"

using std::cerr;
using std::endl;
using namespace library;

bool selector (library::catalog)
{
  return true;
}

template <class T>
void show (T const & t, std::string const & message)
{
   std::cout << message << typeid(t).name() << std::endl;
}

class MyVisitor : public library::visitor
{
  public:
    int i;
    MyVisitor() : i(0) { } 

    virtual void visit_catalog(catalog & x) { ++i; show(x, "Entering: "); }
    virtual void leave_catalog(catalog & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_author(author & x) { ++i; show(x, "Entering: "); }
    virtual void leave_author(author & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_person_name(person_name & x) { ++i; show(x, "Entering: "); }
    virtual void leave_person_name(person_name & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_book_id(book_id & x) { ++i; show(x, "Entering: "); }
    virtual void leave_book_id(book_id & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_person_died(person_died & x) { ++i; show(x, "Entering: "); }
    virtual void leave_person_died(person_died & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_person(person & x) { ++i; show(x, "Entering: "); }
    virtual void leave_person(person & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_book_price(book_price & x) { ++i; show(x, "Entering: "); }
    virtual void leave_book_price(book_price & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_person_born(person_born & x) { ++i; show(x, "Entering: "); }
    virtual void leave_person_born(person_born & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_book_available(book_available & x) { ++i; show(x, "Entering: "); }
    virtual void leave_book_available(book_available & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_title_lang(title_lang & x) { ++i; show(x, "Entering: "); }
    virtual void leave_title_lang(title_lang & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_isbn(isbn & x) { ++i; show(x, "Entering: "); }
    virtual void leave_isbn(isbn & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_title(title & x) { ++i; show(x, "Entering: "); }
    virtual void leave_title(title & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_author_recommends(author_recommends & x) { ++i; show(x, "Entering: "); }
    virtual void leave_author_recommends(author_recommends & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_genre(genre & x) { ++i; show(x, "Entering: "); }
    virtual void leave_genre(genre & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_book(book & x) { ++i; show(x, "Entering: "); }
    virtual void leave_book(book & x) { ++i; show(x, "Leaving: "); }
};

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
    // Read in the XML file and obtain its object model.
    //
    std::auto_ptr<catalog> c (catalog_ (argv[1]));

    // Let's print what we've got.
    //
    
    MyVisitor mv;
    using namespace LEESA;
    
    SchemaTraits<catalog>::Container author_name_seq = 
      evaluate (*c, catalog() >> Select(catalog(), selector));
      
    SchemaTraits<person_died>::Container person_died_seq = 
      evaluate (*c, catalog() >> book() >> author() >> person_died());
    
    SchemaTraits<author>::Container author_seq = 
      evaluate(*c, catalog() >> DescendantsOf(catalog(), author()));
    
    SchemaTraits<book_id>::Container book_id_seq = 
      evaluate (*c, catalog() >> book() >> book_id()[mv]);
    std::cout << "******** Count = " << mv.i << std::endl;
      
    SchemaTraits<book_available>::Container book_available_seq = 
      evaluate (*c, catalog() >> book() >> book_available());
      
    SchemaTraits<author_recommends>::Container author_recommends_seq = 
      evaluate (*c, catalog() >> book() >> author() >> author_recommends());

    evaluate(*c, catalog() >> AroundFullTD(catalog(), VisitStrategy(mv), LeaveStrategy(mv)));
    std::cout << "******** Count = " << mv.i << std::endl;
        
    catalog::book_sequence seq = evaluate (*c, catalog() >> book());
    //catalog::book_sequence seq = c->book();

    for (catalog::book_const_iterator bi (seq.begin ());
         bi != seq.end ();
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
/*
      cerr << "Iterating on person" << std::endl;
      for (book::person_const_iterator pi (bi->person ().begin ());
           pi != bi->person ().end ();
           ++pi)
      {
        cerr << "Person       : " << pi->name () << endl;
        cerr << "  Born       : " << pi->born () << endl;

        if (pi->died ())
          cerr << "  Died       : " << *pi->died () << endl;
          
        try {
          const person & p = *pi;
          const author & a = dynamic_cast<const author &> (p);
        }
        catch (std::bad_cast & e) {
          cerr << e.what() << std::endl;
        }
     }
*/
    }


    // Now we are going to modify the object model and serialize it
    // back to XML.
    //
/*
    catalog::book_sequence books (c->book ());


    // Get rid of all unavailable books.
    //
    for (catalog::book_iterator bi (books.begin ()); bi != books.end ();)
    {
      if (!bi->available ())
        bi = books.erase (bi);
      else
        ++bi;
    }


    // Insert a new book.
    //
    book b (679776443,         // ISBN
            "Dead Souls",      // Title
            genre::philosophy, // Genre
            "DS");             // ID

    b.author ().push_back (author ("Nikolai Gogol",
                                   xml_schema::date (1809, 3, 31)));

    books.insert (books.begin (), b);


    // Because we removed all unavailable books, some IDREFs might be
    // broken. Let's fix this.
    //
    for (catalog::book_iterator bi (books.begin ()); bi != books.end (); ++bi)
    {
      for (book::author_iterator ai (bi->author ().begin ());
           ai != bi->author ().end ();
           ++ai)
      {
        author::recommends_optional& c (ai->recommends ());

        if (c.present ())
        {
          author::recommends_type& ref (c.get ());

          if (!ref)
            c.reset ();
        }
      }
    }


    // Prepare namespace mapping and schema location information.
    //
    xml_schema::namespace_infomap map;

    map["lib"].name = "http://www.codesynthesis.com/library";
    map["lib"].schema = "library.xsd";


    // Write it out.
    //
    catalog_ (std::cout, *c, map);
*/
  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}

