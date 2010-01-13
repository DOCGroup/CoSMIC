// file      : examples/cxx/tree/library/driver.cxx
// author    : Boris Kolpackov <boris@codesynthesis.com>
// copyright : not copyrighted - public domain

#include <memory>   // std::auto_ptr
#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <typeinfo>

#include <sys/time.h>
#include <boost/typeof/typeof.hpp>

#include "library.hxx"
#include "library-meta.hxx"
#include "LEESA_SingleStage.h"

using std::cerr;
using std::endl;
using namespace library;

struct MyVisitor : library::visitor
{
  virtual void visit_book(book & b) 
  {
    std::cout << "visit_book: " << b.title() << std::endl;  
  }
  
  virtual void visit_price(price & p) 
  {
    std::cout << "visit_price: " << p << std::endl;  
  }
};

void print_book(book const & b)
{
  cerr << endl
       << "ISBN         : " << b.isbn () << endl
       << "Title        : " << b.title () << endl
       << "Genre        : " << b.genre () << endl;

  for (book::author_const_iterator ai (b.author ().begin ());
       ai != b.author ().end ();
       ++ai)
  {
    cerr << "Author       : " << ai->name () << endl;
    cerr << "  Born       : " << ai->born () << endl;

    if (ai->died ())
      cerr << "  Died       : " << *ai->died () << endl;
  }
  cerr  << "Available    : " << std::boolalpha << b.available () << endl;
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

template <class Sequence>
int count(Sequence const & seq)
{
  int i = 0;
  for (typename Sequence::const_iterator iter (seq.begin ());
       iter != seq.end ();
       ++iter)
  {
    //print_book(bi);
    ++i;
  }
  return i;
}

int main (int argc, char* argv[])
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
    
    MyVisitor mv;
    timeval start, end;
    
    gettimeofday(&start, 0);
    std::auto_ptr<catalog> c (catalog_ (argv[1]));
    gettimeofday(&end, 0);
    
    std::cout << "Parsing time = " << end-start << std::endl;
    
    using namespace LEESA;
    using namespace LEESA::SingleStage;
    int num = 0;
    
    ContainerTraits<book>::Container seq_leesa1 = Carrier<catalog>(*c) >> book();
    
    gettimeofday(&start, 0);
    Carrier<catalog> carrier2 = *c;
    num = count(carrier2 >> book() >> author() >> RemoveConst(author()) >> mv);
    gettimeofday(&end, 0);
    
    std::cout << "LEESA Count = " << num << ", query-time = " << end-start << std::endl;
    
    num = 0;
    gettimeofday(&start, 0);
    catalog::book_sequence & seq = c->book(); 
    BOOST_FOREACH(book & b, seq)
    {
      BOOST_FOREACH(author & a, b.author()) 
      {
        ++num;
      }
    }
    gettimeofday(&end, 0);
    
    std::cout << "Origanl Count = " << num << ", query-time = " << end-start << std::endl;

  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}

