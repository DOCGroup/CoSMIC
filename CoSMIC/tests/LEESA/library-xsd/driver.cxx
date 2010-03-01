#include <memory>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <exception>
#include <string>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <sys/time.h>

#include "library.hxx"

using std::cerr;
using std::endl;
using boost::cref;
using namespace library;
using namespace boost::tuples;

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

#include <vector>

//#if(!defined TEST1 && !defined TEST2 && !defined TEST3 && !defined TEST4 && !defined TEST5 && \
//    !defined TEST6 && !defined TEST7 && !defined TEST8 && !defined TEST9 && !defined TEST10)
//#define TEST1
//#endif 

#ifdef TEST1
// Get a sequence of books.
SeqType<book>::type
get_books(catalog & c)
{
#ifdef WITH_LEESA  
  SeqType<book>::type book_seq = 
    evaluate (c, catalog() >> book());
  Carrier<book> book_carrier = 
    evaluate (c, catalog() >> book());
/*  std::cout << "Carrier size = "  << book_carrier.size() << std::endl;
  for(Carrier<book>::iterator iter (book_carrier.begin());
      iter != book_carrier.end();
      ++iter)
  {
    std::cout << *iter << std::endl;
  }*/

#endif 
#ifdef WITHOUT_LEESA
  SeqType<book>::type book_seq = 
    c.book();
#endif
  
  return book_seq;
};
#endif // TEST1 

#ifdef TEST2
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
#endif // TEST2

#ifdef TEST3
// Get a sequence of author names.
SeqType<name>::type
//unsigned int
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
#endif // TEST3

#ifdef TEST4
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
#endif // TEST4

#ifdef TEST5

bool comparator(library::name const & n)
{
  return n=="Leo Tolstoy";
}

// Get a sequence of author names.
SeqType<name>::type
get_author_names_level_descendants_of (catalog & c)
{
#ifdef WITH_LEESA  
  SeqType<name>::type name_seq = 
    evaluate (c, catalog() >> LevelDescendantsOf(catalog(), _, _, name()));
/*
    evaluate (c, catalog() >> LevelDescendantsOf(catalog(), _, _, name())
                           >> Select(name(), comparator));
*/
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
#endif // TEST5

#ifdef TEST6
// Get a sequence of tuples of author names and born.
typedef tuple<name *, died *> PtrTuple;
std::vector<PtrTuple>
get_tuples (catalog & c)
{
#ifdef WITH_LEESA  
  std::vector<PtrTuple> tuple_seq =
    evaluate (c, catalog() >> book() 
                           >> author() 
                           >> MembersAsTupleOf(author(), PtrTuple()));
#endif
#ifdef WITHOUT_LEESA
  std::vector<tuple<name *, born *> > tuple_seq;
  for (catalog::book_iterator bi (c.book().begin ());
       bi != c.book().end ();
       ++bi)
  {
    for (book::author_iterator ai (bi->author().begin ());
         ai != bi->author().end ();
         ++ai)
    {
      tuple_seq.push_back(make_tuple(&ai->name(), &ai->born()));
    }
  }
#endif 
  return tuple_seq;
}
#endif // TEST6

#ifdef TEST7
// Get a sequence of "died" date, which is optional.
SeqType<died>::type
get_died (catalog & c)
{
#ifdef WITH_LEESA  
  SeqType<died>::type died_seq =
    evaluate (c, catalog() >> DescendantsOf(catalog(), died()));
#endif
#ifdef WITHOUT_LEESA
  SeqType<died>::type died_seq; 
  for (catalog::book_const_iterator bi (c.book().begin ());
       bi != c.book().end ();
       ++bi)
  {
    for (book::author_const_iterator ai (bi->author().begin ());
         ai != bi->author().end ();
         ++ai)
    {
      if(ai->died().present())
        died_seq.push_back(ai->died().get());
    }
  }
#endif 
  return died_seq;
}
#endif // TEST7

#ifdef TEST8
// Nesting test
void visit (catalog & c, visitor & v)
{
#ifdef WITH_LEESA  
  BOOST_AUTO(inner_author, author() >>= born() >> v >> Leave(born(), v));
  BOOST_AUTO(inner_book, book() >>= author() >> v
                                             >> Call(author(), inner_author)
                                             >> Leave(author(), v));
  BOOST_AUTO(inner_catalog, catalog() >>= book() >> v 
                                                 >> Call(book(), inner_book)
                                                 >> Leave(book(), v));
  evaluate (c, catalog() >> v 
                         >> Call(catalog(), inner_catalog) 
                         >> Leave(catalog(), v));
#endif
}
#endif // TEST8

#ifdef TEST9
// Nesting test
void pair_caller_many (catalog & c, visitor & v)
{
#ifdef WITH_LEESA  

  BOOST_AUTO(inner_author, author() >>= born() >> Visit(born(), v) >> Leave(born(), v));
  BOOST_AUTO(inner_book, book() >>= author() >> VisitLeave(author(), v, inner_author));
  BOOST_AUTO(inner_catalog, catalog() >>= book() >> VisitLeave(book(), v, inner_book));
  evaluate(c, catalog() >> VisitLeave(catalog(), v, inner_catalog));

#endif
}
#endif // TEST9

#ifdef TEST10
// Nesting test
void pair_caller_single (catalog & c, visitor & v)
{
#ifdef WITH_LEESA  
  evaluate(c, catalog() 
              >> VisitLeave(catalog(), v, 
                 catalog() >>= book() 
                 >> VisitLeave(book(), v,
                    book() >>= author() 
                    >> VisitLeave(author(), v, 
                       author() >>= born() 
                       >> VisitLeave(born(), v)))));

#endif
}
#endif // TEST10

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
  //o << t.tv_sec << " " << t.tv_usec;
  return o;
}

#ifdef WITH_LEESA
class MyVisitor : public visitor
{
  public:

    virtual void visit_catalog(catalog & x) {
      std::cout << "Catalog:" << std::endl;  
    }
    virtual void visit_author(author & x) {
      std::cout << "Author: " << x.name() << std::endl;  
    }
    virtual void visit_book(book & x) {
      std::cout << "Book: " << x.title() << std::endl;  
    }
    virtual void visit_born(born & x) {
      std::cout << "Born: " << x << std::endl;  
    }
    
    virtual void leave_catalog(catalog & x) {
      std::cout << "Leave Catalog:" << std::endl;  
    }
    virtual void leave_author(author & x) {
      std::cout << "Leave Author: " << x.name() << std::endl;  
    }
    virtual void leave_book(book & x) {
      std::cout << "Leave Book: " << x.title() << std::endl;  
    }
    virtual void leave_born(born & x) {
      std::cout << "Leave Born: " << x << std::endl;  
    }
};
#endif // WITH_LEESA

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "usage: " << argv[0] << "<xml filename>" << endl;
    return 1;
  }

  try
  {
    timeval start, end;
    
    gettimeofday(&start, 0);
    std::auto_ptr<catalog> c (catalog_ (argv[1]));
    gettimeofday(&end, 0);
    
    std::cout << "Parsing time = " << end-start << std::endl;

    gettimeofday(&start, 0);

#ifdef TEST1
    std::cout << "Size = " << get_books(*c).size() << std::endl; 
#endif
#ifdef TEST2
    std::cout << "Size = " << get_authors(*c).size() << std::endl; 
#endif
#ifdef TEST3
    std::cout << "Size = " << get_author_names(*c).size() << std::endl; 
#endif
#ifdef TEST4
    std::cout << "Size = " << get_author_names_descendants_of(*c).size() << std::endl; 
#endif
#ifdef TEST5
    std::cout << "Size = " << get_author_names_level_descendants_of(*c).size() << std::endl; 
#endif
#ifdef TEST6
    typedef std::vector<PtrTuple> TupleVector;
    TupleVector tuple_vec = get_tuples(*c);
    std::cout << "Size = " << tuple_vec.size() << std::endl; 
    for(TupleVector::const_iterator iter(tuple_vec.begin());
        iter != tuple_vec.end();
        ++iter)
    {
      if (get<0>(*iter) && get<1>(*iter))
        std::cout << "[" << *get<0>(*iter) << ", " << *get<1>(*iter) << "]\n";
      else if (!get<0>(*iter) && get<1>(*iter))
        std::cout << "[0, " << *get<1>(*iter) << "]\n";
      else if (get<0>(*iter) && !get<1>(*iter))
        std::cout << "[" << *get<0>(*iter) << ", 0]\n";
      else
        std::cout << "[0, 0]\n";
      
    }
#endif
#ifdef TEST7
    SeqType<died>::type died_seq = get_died(*c);
    std::cout << "Size = " << died_seq.size() << std::endl; 
    //std::copy(died_seq.begin(), died_seq.end(), std::ostream_iterator<died> (std::cout, "\n"));
#endif
#ifdef TEST8
    MyVisitor v;
    visit(*c, v);
#endif
#ifdef TEST9
    MyVisitor v;
    pair_caller_many(*c, v);
#endif
#ifdef TEST10
    MyVisitor v;
    pair_caller_single(*c, v);
#endif

    gettimeofday(&end, 0);

    std::cout << "Query-time = " << end-start << std::endl;

  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}

