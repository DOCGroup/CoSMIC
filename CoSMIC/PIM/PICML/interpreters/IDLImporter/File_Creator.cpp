// $Id$

#include "File_Creator.h"
#include "game/utils/modelgen.h"
#include "boost/bind.hpp"
#include <functional>

//
// PICML_File_Creator_Item
//
PICML_File_Creator_Item::
PICML_File_Creator_Item (GAME::XME::Model & file)
: file_ (file)
{

}

//
// ~PICML_File_Creator_Item
//
PICML_File_Creator_Item::~PICML_File_Creator_Item (void)
{
  typedef
    ACE_Hash_Map_Manager <ACE_CString,
                          GAME::XME::Auto_Model_T <GAME::XME::Model> *,
                          ACE_Null_Mutex>::ITERATOR
                          ITERATOR;

  for (ITERATOR iter (this->modules_); !iter.done (); ++ iter)
    delete iter->item ();
}

//
// ~PICML_File_Creator
//
PICML_File_Creator::~PICML_File_Creator (void)
{
  for (item_map::ITERATOR iter (this->files_); !iter.done (); ++ iter)
    delete iter->item ();
}


//
// create_files
//
int PICML_File_Creator::
create_files (const char * const * files, size_t n_files, const char * dest)
{
  using GAME::XME::Folder;
  using GAME::XME::Model;

  Folder root_folder = this->proj_.root_folder ();
  static const ::Utils::XStr meta_InterfaceDefinitions ("InterfaceDefinitions");
  static const ::Utils::XStr dest_name (dest);

  // Locate the interface definitions folder.
  Folder idl_folder;
  if (GAME::create_if_not (root_folder, meta_InterfaceDefinitions, idl_folder,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                   dest_name,
                                   boost::bind (&GAME::XME::Folder::name, _1)))))
  {
    idl_folder.name (dest_name);
  }

  static const ::Utils::XStr meta_File ("File");

  // Locate all the IDL files in the IDL file folder.
  std::vector <Model> idl_files;
  idl_folder.children (meta_File, idl_files);

  ACE_CString fullname;

  for (size_t i = 0; i < n_files; ++ i)
  {
    const char * filename = files[i];
    Model idl_file;

    // Get the path and the name of the file.
    std::string tmp (filename);
    std::replace (tmp.begin (), tmp.end (), '\\', '/');

    tmp = tmp.substr (0, tmp.rfind ('.'));
    size_t pos = tmp.find_last_of ('/');

    std::string path;
    if (pos != std::string::npos)
      path = tmp.substr (0, pos);

    if (path.find_first_of ("./") == 0)
      path = path.substr (2);

    ::Utils::XStr name (tmp.substr (pos + 1));

    // Either, create a new element or get the existing one.
    if (GAME::create_if_not (idl_folder, meta_File, idl_files, idl_file,
        GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                     name,
                                     boost::bind (&Model::name, _1)))))
    {
      idl_file.name (name);
    }

    // Set the path attribute for this element.
    idl_file.attribute ("Path", true).value (path);

    // Get the fullpath of the current filename and put it into
    // a canonical format that we can understand.
    char abspath[MAXPATHLEN];
    fullname = ACE_OS::realpath (filename, abspath);
                  
    for (char * iter = abspath; *iter != '\0'; ++ iter)
    {
      if (*iter == '\\')
        *iter = '/';
    }

    // Store the file for later usage.
    PICML_File_Creator_Item * item = 0;
    ACE_NEW_RETURN (item,
                    PICML_File_Creator_Item (idl_file),
                    -1);

    if (0 != this->files_.bind (abspath, item))
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("*** failed to create %s file object; aborting..."),
                         abspath),
                         -1);
  }

  return 0;
}
