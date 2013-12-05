#ifndef FILE_H
#define FILE_H

#include "windows.h"
#include "commdlg.h"
#include <fstream>

#include <algorithm>

namespace CFILE{
class CFile{

public:
  CFile();
  CFile(std::string file_name);
  ~CFile();
  
  BOOL set_path (const std::string& description);
  void add_content(const std::string data);
  BOOL save_file();
  BOOL open_file();
  void close_file();
  void add_include();
  void add_left_brace();
  void add_aspect_key_name(std::string aspect_name);
  void add_right_brace();
  static const std::string include_contents_;   
  static const std::string aspect_key_;
  static const std::string left_brace_;
  static const std::string right_brace_;
  static const std::string semi_colon_;

private:
  void set_file_name(std::string file_name);
  void put_in_file();
  std::ofstream aspect_file_;
  std::string file_name_;
  std::string output_path_;
  std::string file_data_;
};
}

#endif // FILE_H
