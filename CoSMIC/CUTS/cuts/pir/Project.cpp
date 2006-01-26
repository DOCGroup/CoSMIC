#include "cuts/pir/Project.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/Project.inl"
#endif

#include "cuts/pir/File.h"

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
    for ( Files::iterator iter = this->files_.begin ();
          iter != this->files_.end ();
          iter ++)
    {
      delete (*iter);
    }
  }
}
