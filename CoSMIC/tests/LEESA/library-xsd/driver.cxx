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

    virtual void visit_name(name & x) { ++i; show(x, "Entering: "); }
    virtual void leave_name(name & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_died(died & x) { ++i; show(x, "Entering: "); }
    virtual void leave_died(died & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_author(author & x) { ++i; show(x, "Entering: "); }
    virtual void leave_author(author & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_price(price & x) { ++i; show(x, "Entering: "); }
    virtual void leave_price(price & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_born(born & x) { ++i; show(x, "Entering: "); }
    virtual void leave_born(born & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_available(available & x) { ++i; show(x, "Entering: "); }
    virtual void leave_available(available & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_lang(lang & x) { ++i; show(x, "Entering: "); }
    virtual void leave_lang(lang & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_isbn(isbn & x) { ++i; show(x, "Entering: "); }
    virtual void leave_isbn(isbn & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_title(title & x) { ++i; show(x, "Entering: "); }
    virtual void leave_title(title & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_genre(genre & x) { ++i; show(x, "Entering: "); }
    virtual void leave_genre(genre & x) { ++i; show(x, "Leaving: "); }

    virtual void visit_book(book & x) 
    { 
      ++i; show(x, "Entering: "); 
      x.title("abcd");
    }
    virtual void leave_book(book & x) { ++i; show(x, "Leaving: "); }
};

void print_book (book & b)
{
  std::cout << b.title() << std::endl;
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
    // Read in the XML file and obtain its object model.
    //
    std::auto_ptr<catalog> c (catalog_ (argv[1]));

    // Let's print what we've got.
    //
    
    MyVisitor mv;
    using namespace LEESA;

    SchemaTraits<book>::Container book_seq = 
        evaluate (*c, catalog() >> book() >> mv);
      
    evaluate (*c, catalog() >> book() >> ForEach(book(), print_book));
      
    SchemaTraits<born>::Container born_seq = 
      evaluate (book_seq, book() >> author() >> born());
    
    SchemaTraits<name>::Container names =  
      evaluate(*c, catalog() >> LevelDescendantsOf(catalog(), _, _, name()));
      evaluate(*c, catalog() >> DescendantsOf(catalog(), name()));
    BOOST_FOREACH(name n, names)
    {
      std::cout << "#########    " << n << std::endl;
    }
/*
    evaluate(*c, catalog() >> AroundFullTD(catalog(), VisitStrategy(mv), LeaveStrategy(mv)));
    std::cout << "******** Count = " << mv.i << std::endl;
        
    catalog::book_sequence seq = evaluate (*c, catalog() >> book());
*/    catalog::book_sequence seq = c->book();

    for (catalog::book_const_iterator bi (seq.begin ());
         bi != seq.end ();
         ++bi)
    {
      cerr << endl
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
      }
      cerr  << "Available    : " << std::boolalpha << bi->available () << endl;
    }


    // Now we are going to modify the object model and serialize it
    // back to XML.
    //

    catalog::book_sequence  & books (c->book ());

    // Insert a new book.
    //
    book b (679776443,         // ISBN
            "Dead Souls",      // Title
            genre::philosophy, // Genre
            49.99);             // price

    b.author ().push_back (author ("Nikolai Gogol",
                                   xml_schema::date (1809, 3, 31)));

    books.insert (books.begin (), b);

    // Prepare namespace mapping and schema location information.
    //
    xml_schema::namespace_infomap map;

    map["lib"].name = "http://www.codesynthesis.com/library";
    map["lib"].schema = "library.xsd";


    // Write it out.
    //
    catalog_ (std::cout, *c, map);

  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}

