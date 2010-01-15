#include <memory>   // std::auto_ptr
#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <sys/time.h>

#include "boost/tuple/tuple.hpp"

#include "library.hxx"

using std::cerr;
using std::endl;
using namespace boost::tuples;
using namespace library;

#ifdef WITH_LEESA

#include "library-meta.hxx"
#include "LEESA.h"
using namespace LEESA;

#endif // WITH_LEESA

template <class T>
struct SeqType
{
  typedef ::xsd::cxx::tree::sequence< T > type;
};

// Get a sequence of books.
SeqType<book>::type 
get_books(catalog & c)
{
#ifdef WITH_LEESA  
  SeqType<book>::type book_seq = 
    evaluate (c, catalog() >> book());
#endif 
#ifdef WITHOUT_LEESA
  SeqType<book>::type book_seq = 
    c.book();
#endif
  
  return book_seq;
};

// Get a sequence of authors.
SeqType<author>::type
get_authors (catalog & c)
{
#ifdef WITH_LEESA  
  SeqType<author>::type author_seq = 
    evaluate (c, catalog() >> book() >> author());
#endif 
#ifdef WITHOUT_LEESA
  SeqType<author>::type author_seq; 
  for (catalog::book_const_iterator bi (c.book().begin ());
       bi != c.book().end ();
       ++bi)
  {
    author_seq.insert(author_seq.end(), bi->author().begin(), bi->author().end());
  }
#endif 
  return author_seq;
}

// Get a sequence of author names.
SeqType<name>::type 
get_author_names (catalog & c)
{
#ifdef WITH_LEESA  
  SeqType<name>::type name_seq = 
    evaluate (c, catalog() >> book() >> author() >> name());
#endif 
#ifdef WITHOUT_LEESA
  SeqType<name>::type name_seq; 
  for (catalog::book_const_iterator bi (c.book().begin ());
       bi != c.book().end ();
       ++bi)
  {
    for (book::author_const_iterator ai (bi->author().begin ());
         ai != bi->author().end ();
         ++ai)
    {
      name_seq.push_back(ai->name());
    }
  }
#endif
  return name_seq;
}

// Get a sequence of author names.
SeqType<name>::type 
get_author_names_descendants_of (catalog & c)
{
#ifdef WITH_LEESA  
  SeqType<name>::type name_seq = 
    evaluate (c, catalog() >> DescendantsOf(catalog(), name()));
#endif 
#ifdef WITHOUT_LEESA
  SeqType<name>::type name_seq; 
  for (catalog::book_const_iterator bi (c.book().begin ());
       bi != c.book().end ();
       ++bi)
  {
    for (book::author_const_iterator ai (bi->author().begin ());
         ai != bi->author().end ();
         ++ai)
    {
      name_seq.push_back(ai->name());
    }
  }
#endif
  return name_seq;
}


// Get a sequence of author names.
SeqType<name>::type 
get_author_names_level_descendants_of (catalog & c)
{
#ifdef WITH_LEESA  
  SeqType<name>::type name_seq = 
    evaluate (c, catalog() >> LevelDescendantsOf(catalog(), _, _, name()));
#endif 
#ifdef WITHOUT_LEESA
  SeqType<name>::type name_seq; 
  for (catalog::book_const_iterator bi (c.book().begin ());
       bi != c.book().end ();
       ++bi)
  {
    for (book::author_const_iterator ai (bi->author().begin ());
         ai != bi->author().end ();
         ++ai)
    {
      name_seq.push_back(ai->name());
    }
  }
#endif
  return name_seq;
}

timeval operator - (timeval t1, timeval t2)
{
  if (t1.tv_usec < t2.tv_usec)
  {
    t1.tv_sec--;
    t1.tv_usec += 1000000;
  }
  time_t sec = t1.tv_sec - t2.tv_sec; 
  suseconds_t usec = t1.tv_usec - t2.tv_usec;

  timeval retval;
  retval.tv_sec = sec;
  retval.tv_usec = usec;
  return retval;
}

std::ostream & operator << (std::ostream & o, timeval const & t)
{
  o << "[" << t.tv_sec << ", " << t.tv_usec << "]";
  return o;
}

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "usage: " << argv[0] << "<xml filename>" << endl;
    return 1;
  }

  try
  {
    // Read in the XML file and obtain its object model.
    //
    timeval start, end;
    
    gettimeofday(&start, 0);
    std::auto_ptr<catalog> c (catalog_ (argv[1]));
    gettimeofday(&end, 0);
    
    std::cout << "Parsing time = " << end-start << std::endl;

    gettimeofday(&start, 0);

    get_books(*c); 
    get_authors(*c); 
    get_author_names(*c); 
    get_author_names_descendants_of(*c); 
    get_author_names_level_descendants_of(*c); 

    gettimeofday(&end, 0);

    std::cout << "Query-time = " << end-start << std::endl;

  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}

