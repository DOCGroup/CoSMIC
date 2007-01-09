#ifndef _CUTS_BE_FILE_TRAITS_H_
#define _CUTS_BE_FILE_TRAITS_H_

#include "BE_Traits.h"
#include <iosfwd>
#include <memory>

//=============================================================================
/**
 *
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_File_Traits :
  public CUTS_BE_Traits
{
public:
  /// Default constructor.
  CUTS_BE_File_Traits (void);

  /// Destructor.
  virtual ~CUTS_BE_File_Traits (void);

  virtual void close_file (
    const PICML::ComponentImplementationContainer & container);

protected:
  /**
   * Get a reference to the output file. This method will segfault
   * if called before one of the init () methods is called.
   *
   * @return      Reference to output file stream.
   */
  std::ofstream & outfile (void);

private:
  /// Flag specifying if this object owns \outfile_.
  bool outfile_owner_;

  /// Pointer to the output file stream.
  std::auto_ptr <std::ofstream> outfile_;

};

#if defined (__CUTS_INLINE__)
#include "BE_File_Traits.inl"
#endif

#endif  // !defined _CUTS_BE_FILE_TRAITS_H_
