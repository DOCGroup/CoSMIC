#ifndef MPCSTREAM_H
#define MPCSTREAM_H

#include <ostream>
#include <string>
#include <vector>
#include "PICML.h"

#include "MPC_Export.h"

// A dummy structure to inform TAO_OutStream's << operator to  put a newline
// and use the current indentation for the succeeding line
struct NL
{
  NL (void);
};

struct INDENT
{
  //   Increase the indentation level, if the "do_now" parameter is
  //   not zero then the <indent> method is called on the stream.
  //
  INDENT (int do_now = 0);

  const int do_now_;
};

struct UNINDENT
{
  //   Decrease the indentation level, if the "do_now" parameter is
  //   not zero then the <indent> method is called on the stream.
  //
  UNINDENT (int do_now = 0);

  const int do_now_;
};

extern const NL nl;
extern const INDENT idt;
extern const INDENT idt_nl;
extern const UNINDENT uidt;
extern const UNINDENT uidt_nl;

class MPC_Export MPCStream
{
public:
  MPCStream (std::ostream& strm, std::string output_path_);
  // constructor.

  virtual ~MPCStream (void);
  // destructor.

  void incr_indent (unsigned short flag = 1);
  // increment the indentation level and by default actually indent the output
  // accordingly

  void decr_indent (unsigned short flag = 1);
  // decrease the indentation level and by default actually indent the output
  // accordingly

  inline void reset (void);
  // reset indentation level to 0

  void indent (void);
  // indent starting next line

  void nl (void);
  // put a newline and indent on the next line

  // Workspace definitions
  void create_workspace (const PICML::Workspaces &workspace);
  void write_mwc_footer ();
  void write_mwc_header ();

  // Project related definitions
  void create_project (const PICML::Project &project);
  void create_stub_definition (const PICML::StubProject &);
  void create_skeleton_definition (const PICML::ServantProject &);
  void create_executor_definition (const PICML::ExecutorProject &);
  bool dependent_project (PICML::ImplementationArtifact &artifact, 
						  std::string &dependent_proj);
  void create_project_defn (std::string& proj_name, 
							std::string root_proj);
  void create_after_defn (std::string& deo_proj_name);
  void create_shared_defn (std::string& name);
  void create_export_defn (std::string& shared_name);
  void create_close_proj_defn ();
  void create_dynamic_flags_defn (std::string& shared_name);
  void create_idl_file_defn (std::vector<std::string>& idl_files);
  void create_source_file_defn (std::vector<std::string>& idl_c_files);
  void create_lib_path_defn (std::string& lib_path);
  void create_cidl_defn (PICML::ImplementationArtifact& artifact);
  void create_export_macro (std::string& shared_name);
  std::string skel_export_macro (PICML::Project project);
  std::vector<std::string> generate_dependant_libs (std::set<PICML::ArtifactDependsOn>& art_refs);
  void create_dependant_libs_defn (std::vector<std::string>& list);

  MPCStream &operator<< (const std::string &);
  MPCStream &operator<< (const char *);
  MPCStream &operator<< (const long &);
  MPCStream &operator<< (const unsigned long &);
  MPCStream &operator<< (const double &);
  MPCStream &operator<< (const char &);

  // = MANIPULATORS
  MPCStream &operator<< (const NL &);
  MPCStream &operator<< (const INDENT &);
  MPCStream &operator<< (const UNINDENT &);

private:
  std::ostream& strm_;
  std::string output_path_;
  std::string stub_project_;
  std::string servant_project_;
  int indent_level_;
  std::vector<std::string> cidl_file_;
  std::vector<std::string> idl_files_;
  
private:
  void upcase (const char *);
};

#endif // MPCStream_H