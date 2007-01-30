#ifndef ZIP_CREATE_H
#define ZIP_CREATE_H

#include <string>
#include <vector>

#include "PICML/PICML.h"
#include "zip.h"

/**
 * @class ZIP_create
 *
 * This class provides the functions required to create the zip file.
 */
class ZIP_create
{
public:
  bool check_if_file_exists(const std::string filename);

  void get_filenames(const std::string dir,
                     const std::string dir_bak);

  int compress(const std::string filename,
               const std::string dir,
               int compression_level = 5,
               int append = 0);

private:
   std::vector<std::string> files_;
   std::vector<std::string> dirs_;
};

#endif /* ZIP_CREATE_H */
