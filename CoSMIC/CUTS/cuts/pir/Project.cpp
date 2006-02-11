#include "cuts/pir/Project.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/Project.inl"
#endif

#include "cuts/pir/File.h"
#include "cuts/utils/Functor_T.h"
#include <algorithm>

namespace CUTS_PIR
{
  //
  // instance_
  //
  Project * Project::instance_ = 0;

  //
  // instance
  //
  Project * Project::instance (void)
  {
    if (Project::instance_ == 0)
    {
      Project::instance_ = new Project ();
    }
    return Project::instance_;
  }

  //
  // close
  //
  void Project::close (void)
  {
    if (Project::instance_ != 0)
    {
      delete Project::instance_;
      Project::instance_ = 0;
    }
  }

  //
  // Project
  //
  Project::Project (void)
  {

  }

  //
  // ~Project
  //
  Project::~Project (void)
  {
    std::for_each (
      this->files_.begin (),
      this->files_.end (),
      Delete_Element_T <Files::value_type> ());
  }
}
