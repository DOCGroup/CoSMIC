#include <memory>
#include <iostream>
#include <iterator>
#include <algorithm>

#include "g2sMessage.hxx"
//#include "g2sMessage-meta.hxx"
//#include "LEESA.h"

using std::cerr;
using std::endl;
using std::auto_ptr;

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "usage: " << argv[0] << " g2s.xml" << endl;
    return 1;
  }

  try
  {
    using namespace G2Sv1_0_3;
    auto_ptr<c_message> g2s_root (g2sMessage (argv[1]));

  /*  
    using namespace LEESA;
    
    ::ContainerTraits<description>::Container desc = 
      evaluate(*rss_root, rss() >> DescendantsOf(rss(), description()));

    std::copy(desc.begin(), desc.end(), std::ostream_iterator<description>(std::cout,"\n\n"));
  */  
  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}
