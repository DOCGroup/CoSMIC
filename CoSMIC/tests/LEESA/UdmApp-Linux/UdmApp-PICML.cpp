#include "UdmApp-PICML.h"
#include "UdmConfig-PICML.h"
#include "Uml.h"

#include <string>

#include "PICML.h"

#define AfxMessageBox(...) 

#ifdef WITH_LEESA

#define DOMAIN_NAMESPACE PICML
#include "LEESA.h"

using namespace LEESA;

#endif

using namespace PICML;

class PICMLVisitor : public PICML::Visitor
{
};

std::vector<AttributeMember> 
get_member_child_axis(RootFolder rf)
{
#ifdef WITH_LEESA
  std::vector<AttributeMember> members =   
    evaluate (rf, RootFolder() >> InterfaceDefinitions()
                               >> File()
                               >> Package()
                               >> Component()
                               >> Attribute()
                               >> AttributeMember());
  return members;
#else
  std::vector<AttributeMember> members;   
  std::vector<InterfaceDefinitions> ifaces = rf.InterfaceDefinitions_kind_children();
  for(std::vector<InterfaceDefinitions>::iterator iface_iter(ifaces.begin());
      iface_iter != ifaces.end();
      ++iface_iter)
      {
        std::vector<File> files = iface_iter->File_kind_children();
        for(std::vector<File>::iterator file_iter(files.begin());
            file_iter != files.end();
            ++file_iter)
            {
              std::vector<Package> packages = file_iter->Package_kind_children();
              for(std::vector<Package>::iterator package_iter(packages.begin());
                  package_iter != packages.end();
                  ++package_iter)
                  {
                    std::vector<Component> components = package_iter->Component_kind_children();
                    for(std::vector<Component>::iterator component_iter(components.begin());
                        component_iter != components.end();
                        ++component_iter)
                        {
                          std::vector<Attribute> attrs = component_iter->Attribute_kind_children();
                          for(std::vector<Attribute>::iterator attr_iter(attrs.begin());
                              attr_iter != attrs.end();
                              ++attr_iter)
                              {
                                std::vector<AttributeMember> attr_mems = attr_iter->AttributeMember_kind_children();
                                for(std::vector<AttributeMember>::iterator attrmem_iter(attr_mems.begin());
                                    attrmem_iter != attr_mems.end();
                                    ++attrmem_iter)
                                    {
                                      members.push_back(*attrmem_iter);
                                    }
                              }
                        }
                  }
            }
      }
  return members;
#endif
}


std::vector<AttributeMember>
get_member_descendants(RootFolder rf)
{
#ifdef WITH_LEESA
  std::vector<AttributeMember> members =   
    evaluate (rf, RootFolder() >> DescendantsOf(RootFolder(), AttributeMember()));
  return members;
#else
//  PICML::AtrributeMember was found to be a descendant of 19
// elements. Moreover, one pair of elements is known to be recursive.
// We count 6 lines for each element and 10 lines for each member of
// mutually recursive elements. Finally, 1 line for push_back and 
// one line for return. So we get 6*19 + 10*2 + 2 = 136 lines. 
#endif
}

std::vector<AttributeMember>
get_member_level_descendants(RootFolder rf)
{
#ifdef WITH_LEESA
  std::vector<AttributeMember> members =   
    evaluate (rf, RootFolder() 
        >> LevelDescendantsOf(RootFolder(), _, _, _, _, AttributeMember()));
  return members;
#else
// There are 5 wildcards and 7 types in total. But AttributeMembers could be
// inside many types at that level. So we simply take an average of simple
// nested looping based solution and the recursive solution. 
// We get (39+136)/2 = 88 lines. This metric is highly schema-specific.
#endif
}


void CUdmApp::UdmMain( Udm::DataNetwork* p_backend,    // Backend pointer(already open!)
                       Udm::Object focusObject,      // Focus object
                       set<Udm::Object> selectedObjects,  // Selected objects
                       long param)            // Parameters
{  
  try {
          
    RootFolder rf = RootFolder::Cast (p_backend->GetRootObject());
    PICMLVisitor visitor;

    /********************* Warning: Takes long time ***********************
    evaluate (rf, RootFolder() >> AroundFullTD(RootFolder(), VisitStrategy(visitor), LeaveStrategy(visitor)));
    evaluate (rf, RootFolder() >> FullTD(RootFolder(), VisitStrategy(visitor)));
    */
    get_member_child_axis(rf);
    get_member_descendants(rf);
    get_member_level_descendants(rf);
/*   
    evaluate(rf, RootFolder() 
                  >> AP(VisitStrategy(visitor),
                        FROM(RootFolder),
                        TO(AttributeMember),
                        THROUGH(File)));
*/ 
      
  }
#ifdef WITH_LEESA
  catch (boost::regex_error & e)
  {
    std::string error = std::string("boost::regex_error = ") + e.what();
    AfxMessageBox(error.c_str());
  }
  catch (std::runtime_error & e)
  {
    AfxMessageBox(e.what());
  }
#endif // WITH_LEESA  
  catch(...)
  {
    AfxMessageBox("An unknown exception was caught!");
  }

}

