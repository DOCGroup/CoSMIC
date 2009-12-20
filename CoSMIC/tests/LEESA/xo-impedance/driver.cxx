#include <memory>   
#include <iostream>
#include <vector>
#include <exception>
#include <string>
#include <typeinfo>

#include "impedance.hxx"

using std::cerr;
using std::endl;
using namespace impedance;

int main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "usage: " << argv[0] << " impedance.xml" << endl;
    return 1;
  }

  try
  {
    // Read in the XML file and obtain its object model.
    //
    std::auto_ptr<Top> t (top (argv[1]));

    // Let's print what we've got.
    //
    


    // Prepare namespace mapping and schema location information.
    //
    xml_schema::namespace_infomap map;

    map["impedance"].name = "http://www.dre.vanderbilt.edu/impedance";
    map["impedancce"].schema = "impedance.xsd";


    // Write it out.
    //
    top (std::cout, *t, map);

  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}

