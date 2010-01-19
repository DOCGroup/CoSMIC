#include <memory>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "rss2.hxx"
#include "rss2-meta.hxx"
#include "LEESA.h"

using std::cerr;
using std::endl;
using std::auto_ptr;

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "usage: " << argv[0] << " rss2.xml" << endl;
    return 1;
  }

  try
  {
    using namespace LEESA;
    
    auto_ptr<rss> rss_root (rss_ (argv[1]));
    
    ::ContainerTraits<description>::Container desc = 
      evaluate(*rss_root, rss() >> DescendantsOf(rss(), description()));

    std::copy(desc.begin(), desc.end(), std::ostream_iterator<description>(std::cout,"\n\n"));
  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}
