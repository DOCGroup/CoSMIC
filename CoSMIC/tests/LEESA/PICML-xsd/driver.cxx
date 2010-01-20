#include <memory>
#include <iostream>

#include "PICML.hxx"

using std::cerr;
using std::endl;
using std::auto_ptr;

#ifdef WITH_LEESA

#include "PICML-meta.hxx"
#include "LEESA.h"

using namespace LEESA;

#endif // WITH_LEESA

template <class T>
struct SeqType
{
  typedef ::xsd::cxx::tree::sequence< T > type;
};

::SeqType<AttributeMemberType>::type
get_member_child_axis(RootFolderType & rf)
{
#ifdef WITH_LEESA
  ::SeqType<AttributeMemberType>::type members =   
    evaluate (rf, RootFolderType() >> InterfaceDefinitionsType()
                                   >> FileType()
                                   >> PackageType()
                                   >> ComponentType()
                                   >> AttributeType()
                                   >> AttributeMemberType());
  return members;
#else
  ::SeqType<AttributeMemberType>::type members;   
  ::SeqType<InterfaceDefinitionsType>::type ifaces = rf.InterfaceDefinitions();
  for(::SeqType<InterfaceDefinitionsType>::type::iterator iface_iter(ifaces.begin());
      iface_iter != ifaces.end();
      ++iface_iter)
      {
        ::SeqType<FileType>::type files = iface_iter->File();
        for(::SeqType<FileType>::type::iterator file_iter(files.begin());
            file_iter != files.end();
            ++file_iter)
            {
              ::SeqType<PackageType>::type packages = file_iter->Package();
              for(::SeqType<PackageType>::type::iterator package_iter(packages.begin());
                  package_iter != packages.end();
                  ++package_iter)
                  {
                    ::SeqType<ComponentType>::type components = package_iter->Component();
                    for(::SeqType<ComponentType>::type::iterator component_iter(components.begin());
                        component_iter != components.end();
                        ++component_iter)
                        {
                          ::SeqType<AttributeType>::type attrs = component_iter->Attribute();
                          for(::SeqType<AttributeType>::type::iterator attr_iter(attrs.begin());
                              attr_iter != attrs.end();
                              ++attr_iter)
                              {
                                members.push_back(attr_iter->AttributeMember());
                              }
                        }
                  }
            }
      }
  return members;
#endif
}

/*
::SeqType<AttributeMemberType>::type
get_member_descendants(RootFolderType & rf)
{
#ifdef WITH_LEESA
  ::SeqType<AttributeMemberType>::type members =   
    evaluate (rf, RootFolderType() >> DescendantsOf(RootFolderType(), AttributeMemberType()));
  return members;
#else
// AtrributeMemberType was found to be a descendant of 19
// elements. Moreover, one pair of elements is known to be recursive.
// We count 6 lines for each element and 10 lines for each member of
// mutually recursive elements. Finally, 1 line for push_back and 
// one line for return. So we get 6*19 + 10*2 + 2 = 136 lines. 
#endif
}

::SeqType<AttributeMemberType>::type
get_member_level_descendants(RootFolderType & rf)
{
#ifdef WITH_LEESA
  ::SeqType<AttributeMemberType>::type members =   
    evaluate (rf, RootFolderType() 
        >> LevelDescendantsOf(RootFolderType(), _, _, _, _, AttributeMemberType()));
  return members;
#else
// There are 5 wildcards and 7 types in total. But AttributeMembers could be
// inside many types at that level. So we simply take an average of simple
// nested looping based solution and the recursive solution. 
// We get (39+136)/2 = 88 lines. This metric is highly schema-specific.
#endif
}
*/

int
main (int argc, char* argv[])
{
  if (argc != 2)
  {
    cerr << "usage: " << argv[0] << " PICML.xml" << endl;
    return 1;
  }

  try
  {
    auto_ptr<RootFolderType> rf_root (RootFolder (argv[1]));

    get_member_child_axis(*rf_root);
    //get_member_descendants(*rf_root);
    //get_member_level_descendants(*rf_root);

  }
  catch (const xml_schema::exception& e)
  {
    cerr << e << endl;
    return 1;
  }
}


