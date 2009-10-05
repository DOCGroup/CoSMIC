// $Id$

#include "PackagerVisitor.h"
#include "ZIP_create.h"
#include "ace/SString.h"           //for ACE_CString
#include "ace/Dirent.h"

namespace PICML
{
  PackagerVisitor::PackagerVisitor (const std::string& descriptorDir,
                                    const std::string& implementationDir,
                                    const std::string& packageDir)
    : descriptorDir_ (descriptorDir),
      implementationDir_ (implementationDir),
      packageDir_ (packageDir),
      curr_implementationDir_ (""),
      curr_descriptorDir_ (""),
      default_version_ ("")
  {
  }

  void PackagerVisitor::Visit_RootFolder(const RootFolder& rf)
  {
    ACE_TCHAR full_path[MAXPATHLEN];
    if (ACE_OS::getcwd (full_path, sizeof(full_path)) == NULL)
      throw udm_exception (string ("Get cwd failed: " + string (full_path)));

    if (ACE_OS::chdir (packageDir_.c_str ()) == -1)
      throw udm_exception (string ("chdir failed: " + packageDir_));

    string pkg = rf.name ();
    ACE_OS::mkdir (pkg.c_str ());

    this->packageDir_ += "\\";
    this->packageDir_ += pkg;

    std::set<TopLevelPackages> tps = rf.TopLevelPackages_children();
    for (std::set<TopLevelPackages>::iterator iter = tps.begin();
         iter != tps.end();
         ++iter)
      {
        TopLevelPackages tp = *iter;
        tp.Accept (*this);
      }

    if (ACE_OS::chdir (full_path) == -1)
      throw udm_exception (string ("chdir failed: ") + full_path);
  }

  void PackagerVisitor::Visit_TopLevelPackages(const TopLevelPackages& tp)
  {
    set<TopLevelPackageContainer> tpcs = tp.TopLevelPackageContainer_kind_children();
    for (std::set<TopLevelPackageContainer>::iterator iter = tpcs.begin();
         iter != tpcs.end();
         ++iter)
      {
        TopLevelPackageContainer tpc = *iter;
        tpc.Accept (*this);
      }
  }

  void PackagerVisitor::Visit_TopLevelPackageContainer(const TopLevelPackageContainer& tpc)
  {
    TopLevelPackage tp = tpc.TopLevelPackage_child();
    tp.Accept (*this);
  }

  void PackagerVisitor::Visit_TopLevelPackage(const TopLevelPackage& tp)
  {
    string package_dir = this->packageDir_ + "\\";
    package_dir += tp.name ();
    ACE_OS::mkdir(package_dir.c_str ());
    curr_implementationDir_ = package_dir + "\\implementations";
    ACE_OS::mkdir(curr_implementationDir_.c_str ());
    curr_descriptorDir_ = package_dir + "\\descriptors";
    ACE_OS::mkdir(curr_descriptorDir_.c_str ());

    string tpd_from_dir = this->descriptorDir_;
    tpd_from_dir += "\\";
    tpd_from_dir += tp.name();
    tpd_from_dir += ".tpd";

    string tpd_to_dir = curr_descriptorDir_;
    tpd_to_dir += "\\";
    tpd_to_dir += tp.name();
    tpd_to_dir += ".tpd";

    this->copy_from_disk_to_disk (tpd_from_dir, tpd_to_dir);

    package pkg = tp.dstpackage();
    pkg.Accept (*this);

    // compress
    if (ACE_OS::chdir (packageDir_.c_str ()) == -1)
      throw udm_exception (string ("chdir failed: " + package_dir));

    ZIP_create z;
    string filename = tp.name ();
    filename += ".cpk";
    z.compress(filename, tp.name ());

    remove_dir (package_dir);
  }

  void PackagerVisitor::Visit_package(const package& pkg)
  {
    PackageConfigurationReference pcr = pkg.dstpackage_end();
    pcr.Accept (*this);
  }

  void PackagerVisitor::Visit_PackageConfigurationReference(const PackageConfigurationReference& pcr)
  {
    PackageConfiguration pc = pcr.ref();
    pc.Accept (*this);
  }

  void PackagerVisitor::Visit_PackageConfiguration(const PackageConfiguration& pc)
  {
    string pcd_from_dir = this->descriptorDir_;
    pcd_from_dir += "\\";
    pcd_from_dir += pc.name();
    pcd_from_dir += ".pcd";

    string pcd_to_dir = curr_descriptorDir_;
    pcd_to_dir += "\\";
    pcd_to_dir += pc.name();
    pcd_to_dir += ".pcd";

    this->copy_from_disk_to_disk (pcd_from_dir, pcd_to_dir);

    PackageConfReference pcr = pc.dstPackageConfReference();
    pcr.Accept (*this);
  }

  void PackagerVisitor::Visit_PackageConfReference(const PackageConfReference& pkgconfref)
  {
    ComponentPackageReference pkgref = pkgconfref.dstPackageConfReference_end();
    pkgref.Accept (*this);
  }

  void PackagerVisitor::Visit_ComponentPackageReference(const ComponentPackageReference& pkgref)
  {
    ComponentPackage pkg = pkgref.ref();
    pkg.Accept (*this);
  }

  void PackagerVisitor::Visit_ComponentPackage(const ComponentPackage& cp)
  {
    string cpd_from_dir = this->descriptorDir_;
    cpd_from_dir += "\\";
    cpd_from_dir += cp.name();
    cpd_from_dir += ".cpd";

    string cpd_to_dir = curr_descriptorDir_;
    cpd_to_dir += "\\";
    cpd_to_dir += cp.name();
    cpd_to_dir += ".cpd";

    this->copy_from_disk_to_disk (cpd_from_dir, cpd_to_dir);

    set<Implementation> impls = cp.dstImplementation();
    for (std::set<Implementation>::iterator iter = impls.begin();
         iter != impls.end();
         ++iter)
      {
        Implementation impl = *iter;
        impl.Accept (*this);
      }

    PackageInterface pi = cp.dstPackageInterface();
    pi.Accept (*this);
  }

  void PackagerVisitor::Visit_Implementation(const Implementation& impl)
  {
    ComponentImplementationReference cir = impl.dstImplementation_end();
    cir.Accept (*this);
  }

  void PackagerVisitor::Visit_PackageInterface(const PackageInterface& pi)
  {
    ComponentRef cr = pi.dstPackageInterface_end();
    cr.Accept (*this);
  }

  void PackagerVisitor::Visit_ComponentImplementationReference(const ComponentImplementationReference& cir)
  {
    ComponentImplementation ci = cir.ref();
    MonolithicImplementation& mi = MonolithicImplementation::Cast(ci);
    mi.Accept (*this);
  }

  void PackagerVisitor::Visit_ComponentRef(const ComponentRef& cr)
  {
    string ccd_from_dir = this->descriptorDir_;
    ccd_from_dir += "\\";
    ccd_from_dir += cr.name();
    ccd_from_dir += ".ccd";

    string ccd_to_dir = curr_descriptorDir_;
    ccd_to_dir += "\\";
    ccd_to_dir += cr.name();
    ccd_to_dir += ".ccd";

    this->copy_from_disk_to_disk (ccd_from_dir, ccd_to_dir);
  }

  void PackagerVisitor::Visit_MonolithicImplementation(const MonolithicImplementation& mimpl)
  {
    string cid_from_dir = this->descriptorDir_;
    cid_from_dir += "\\";
    cid_from_dir += mimpl.name();
    cid_from_dir += ".cid";

    string cid_to_dir = curr_descriptorDir_;
    cid_to_dir += "\\";
    cid_to_dir += mimpl.name();
    cid_to_dir += ".cid";

    this->copy_from_disk_to_disk (cid_from_dir, cid_to_dir);

    default_version_ = mimpl.defaultVersion ();
    string impl_dir = curr_implementationDir_ + "\\";
    impl_dir += "default";
    ACE_OS::mkdir(impl_dir.c_str ());

    set<MonolithprimaryArtifact> mpas = mimpl.dstMonolithprimaryArtifact();
    for (std::set<MonolithprimaryArtifact>::iterator iter = mpas.begin();
         iter != mpas.end();
         ++iter)
      {
        MonolithprimaryArtifact mpa = *iter;
        mpa.Accept (*this);
      }
  }

  void PackagerVisitor::Visit_MonolithprimaryArtifact(const MonolithprimaryArtifact& mpa)
  {
    ImplementationArtifactReference iaref = mpa.dstMonolithprimaryArtifact_end();
    ImplementationArtifact iare = iaref.ref();
    iare.Accept (*this);
  }

  void PackagerVisitor::Visit_ImplementationArtifact(const ImplementationArtifact& iare)
  {
    string iad_from_dir = this->descriptorDir_;
    iad_from_dir += "\\";
    iad_from_dir += iare.name();
    iad_from_dir += ".iad";

    string iad_to_dir = curr_descriptorDir_;
    iad_to_dir += "\\";
    iad_to_dir += iare.name();
    iad_to_dir += ".iad";

    this->copy_from_disk_to_disk (iad_from_dir, iad_to_dir);

    this->copy_implementation_files (iare);
  }

  void PackagerVisitor::copy_implementation_files(const ImplementationArtifact& iare)
  {
    string version = iare.artifactVersion ();
    string os = iare.operatingSystem ();
    string arch = iare.architecture ();
    string configuration = iare.configuration ();

    string impl_dir = curr_implementationDir_ + "\\";
    impl_dir += version;
    ACE_OS::mkdir(impl_dir.c_str ());
    impl_dir += "\\";
    impl_dir += os;
    ACE_OS::mkdir(impl_dir.c_str ());
    impl_dir += "\\";
    impl_dir += arch;
    ACE_OS::mkdir(impl_dir.c_str ());

    string prefix;
    string suffix;
    if (!os.compare ("Win32") || !os.compare ("Win64"))
      {
        suffix = ".dll";
        prefix = "";
      }
    else
      {
        prefix = "lib";
        suffix = ".so";
      }

    string name (iare.name ());
    name = prefix + name;
    if ((!os.compare ("Win32") || !os.compare ("Win64")) && (configuration.compare ("Release")))
      {
        string decorator = "d";
        name += decorator;
      }
    name += suffix;

    string impl_from_dir = this->implementationDir_;
    impl_from_dir += "\\";
    impl_from_dir += os;
    impl_from_dir += "\\";
    impl_from_dir += name;

    string impl_to_dir = impl_dir;
    impl_to_dir += "\\";
    impl_to_dir += name;

    this->copy_from_disk_to_disk (impl_from_dir, impl_to_dir);

    if (!version.compare (default_version_))
      {
        impl_dir = curr_implementationDir_ + "\\" + "default";
        impl_dir += "\\";
        impl_dir += os;
        ACE_OS::mkdir(impl_dir.c_str ());
        impl_dir += "\\";
        impl_dir += arch;
        ACE_OS::mkdir(impl_dir.c_str ());

        impl_to_dir = impl_dir;
        impl_to_dir += "\\";
        impl_to_dir += name;

        this->copy_from_disk_to_disk (impl_from_dir, impl_to_dir);
      }

    set<ArtifactDependsOn> ads = iare.dstArtifactDependsOn();
    for (std::set<ArtifactDependsOn>::iterator iter = ads.begin();
      iter != ads.end();
      ++iter)
    {
      ArtifactDependsOn ad = *iter;

      ImplementationArtifactReference iaf = ad.dstArtifactDependsOn_end();
      ImplementationArtifact ia = iaf.ref();
      ia.Accept (*this);
    }
  }

  void PackagerVisitor::copy_from_disk_to_disk(const std::string& from_path, const std::string& to_path)
  {
    // Open the files
    ACE_HANDLE from_handle = ACE_OS::open (from_path.c_str (), O_RDONLY);
    if (from_handle == ACE_INVALID_HANDLE)
      throw udm_exception (string ("File open error: " + from_path));

    ACE_stat file_info;
    ACE_OS::fstat (from_handle, &file_info);
    ACE_UINT64 file_length = file_info.st_size;

    ACE_HANDLE to_handle = ACE_OS::open (to_path.c_str (), O_CREAT | O_TRUNC | O_WRONLY);
    if (to_handle == ACE_INVALID_HANDLE)
      throw udm_exception (string ("File creation error: " + to_path));

    // Read the contents of the file into the buffer and write the data to another file
    ACE_Message_Block *mb = 0;
    size_t length;
    size_t number = 0;
    bool last = false;

    while (true)
    {
      if ((file_length - BUFSIZ*number) > BUFSIZ)
        length = BUFSIZ;
      else
        {
          length = static_cast<size_t> (file_length - BUFSIZ*number);
          last = true;
        }

      mb = new ACE_Message_Block (length);

      if (ACE_OS::read_n (from_handle, mb->wr_ptr (), length) == -1)
        throw udm_exception (string ("File read error: " + from_path));

      ++number;

      mb->length (length);

      for (ACE_Message_Block *curr = mb; curr != 0; curr = curr->cont ())
        if (ACE_OS::write_n (to_handle, curr->rd_ptr (), curr->length ()) == -1)
          {
            mb->release ();
            throw udm_exception (string ("File write error: " + to_path));
          }

      mb->release ();

      if (last)
        break;
    }

    // Close the files
    ACE_OS::close (from_handle);
    ACE_OS::close (to_handle);
  }

  void PackagerVisitor::remove_dir(const std::string& path)
  {
    ACE_TCHAR full_path[MAXPATHLEN];
    if (ACE_OS::getcwd (full_path, sizeof(full_path)) == NULL)
      throw udm_exception (string ("Get cwd failed: " + string (full_path)));

    if (ACE_OS::chdir (path.c_str ()) == -1)
      throw udm_exception (string ("chdir failed: " + path));

    ACE_Dirent dir (path.c_str ());

    for (ACE_DIRENT *directory; (directory = dir.read ()) != 0;)
    {
      if (ACE_OS::strcmp (directory->d_name, ".") == 0
          || ACE_OS::strcmp (directory->d_name, "..") == 0)
        continue;

      ACE_stat stat_buf;
      if (ACE_OS::lstat (directory->d_name, &stat_buf) == -1)
        throw udm_exception (string ("lstat failed: ") + string (directory->d_name));

      std::string temp = path;
      temp += "\\";
      temp += directory->d_name;
      switch (stat_buf.st_mode & S_IFMT)
        {
        case S_IFREG: // Either a regular file or an executable.
          if (remove (temp.c_str ()))
            throw udm_exception (string ("delete file failed: ") + string (directory->d_name));
          break;

        case S_IFDIR:
          remove_dir (temp);
          break;

        default:
          break;
        }
    }

    if (ACE_OS::chdir (full_path) == -1)
      throw udm_exception (string ("chdir failed: ") + full_path);

    if (ACE_OS::rmdir (path.c_str ()) == -1)
      throw udm_exception (string ("remove dir failed: ") + path);
  }
}
