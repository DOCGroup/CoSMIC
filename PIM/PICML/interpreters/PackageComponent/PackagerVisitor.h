#ifndef PACKAGER_VISITOR_H
#define PACKAGER_VISITOR_H

#include "ace/OS_NS_sys_stat.h"
#include "ace/OS_NS_fcntl.h"
#include "ace/OS_NS_unistd.h"
#include "ace/Message_Block.h"

#include "PICML/PICML.h"
#include "Packager_Export.h"

namespace PICML
{
  class Packager_Export PackagerVisitor: public Visitor
  {
  public:
    PackagerVisitor::PackagerVisitor (const std::string& descriptorDir,
                                      const std::string& implementationDir,
                                      const std::string& packageDir);

    virtual void Visit_RootFolder(const RootFolder&);
    virtual void Visit_TopLevelPackages(const TopLevelPackages&);
    virtual void Visit_TopLevelPackageContainer(const TopLevelPackageContainer&);
    virtual void Visit_TopLevelPackage(const TopLevelPackage&);
    virtual void Visit_package(const package&);
    virtual void Visit_PackageConfigurationReference(const PackageConfigurationReference&);
    virtual void Visit_PackageConfiguration(const PackageConfiguration&);
    virtual void Visit_PackageConfReference(const PackageConfReference& pkgconfref);
    virtual void Visit_ComponentPackageReference(const ComponentPackageReference&);
    virtual void Visit_ComponentPackage(const ComponentPackage& cp);
    virtual void Visit_Implementation(const Implementation& impl);
    virtual void Visit_PackageInterface(const PackageInterface& pi);
    virtual void Visit_ComponentImplementationReference(const ComponentImplementationReference&);
    virtual void Visit_ComponentRef(const ComponentRef& cr);
    virtual void Visit_MonolithicImplementation(const MonolithicImplementation&);
    virtual void Visit_MonolithprimaryArtifact(const MonolithprimaryArtifact& mpa);
    virtual void Visit_ImplementationArtifact(const ImplementationArtifact& iare);

  private:
    void copy_from_disk_to_disk(const std::string& from_path, const std::string& to_path);
    void copy_implementation_files(const ImplementationArtifact& iare);
    void remove_dir(const std::string& path);

    string         descriptorDir_;
    string         implementationDir_;
    string         packageDir_;
    string         curr_implementationDir_;
    string         curr_descriptorDir_;
    string         default_version_;
  };
}

#endif /* PACKAGER_VISITOR_H */
