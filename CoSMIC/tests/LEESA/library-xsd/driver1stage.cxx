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
    timeval start, end;
    
    gettimeofday(&start, 0);
    std::auto_ptr<catalog> c (catalog_ (argv[1]));
    gettimeofday(&end, 0);
    
    std::cout << "Parsing time = " << end-start << std::endl;
    
    using namespace LEESA::SingleStage;
    int num = 0;
    
    gettimeofday(&start, 0);
    Carrier<catalog> carrier = *c;
    BOOST_AUTO(seq_leesa, carrier >> book() >> author());
    num = count(seq_leesa);
    gettimeofday(&end, 0);
    
    std::cout << "LEESA Count = " << num << ", query-time = " << end-start << std::endl;
    
    num = 0;
    gettimeofday(&start, 0);
    BOOST_FOREACH(book const & b, c->book())
    {
      BOOST_FOREACH(author const & a, b.author()) 
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

