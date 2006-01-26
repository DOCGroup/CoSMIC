#include "cuts/pir/Scope.h"

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Scope.inl"
#endif

#include <algorithm>

namespace CUTS_PIR
{
  struct Scope_Creator
  {
    //
    // Scope_Creator
    //
    Scope_Creator (std::string & dest, const std::string & seperator)
      : dest_ (dest),
        seperator_ (seperator)
    {

    }

    //
    // operator ()
    //
    void operator () (const std::string & scope)
    {
      this->dest_ += scope + this->seperator_;
    }

  private:
    /// Destination string for the output.
    std::string dest_;

    /// Seperator string between each scope.
    const std::string & seperator_;
  };

  //
  // str_
  //
  std::string Scope::str_;

  //
  // Scope
  //
  Scope::Scope (void)
  {

  }

  //
  // ~Scope
  //
  Scope::~Scope (void)
  {

  }

  //
  // c_str
  //
  const char * Scope::c_str (const char * seperator)
  {
    // Verify the static <str_> is empty.
    if (!Scope::str_.empty ())
      Scope::str_.clear ();

    // Create a <Scope_Creator> functor and convert <this>
    // to a readable string.
    Scope_Creator scope_creator (Scope::str_, seperator);
    std::for_each (this->c.begin (), this->c.end (), scope_creator);

    // Return the string.
    return Scope::str_.c_str ();
  }
}