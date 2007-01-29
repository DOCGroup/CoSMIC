// -*- C++ -*-

#ifndef _GME_FOLDER_H_
#define _GME_FOLDER_H_

#include "GME_fwd.h"
#include "Object.h"
#include <vector>

namespace GME
{
  //===========================================================================
  /**
   * @class Folder
   */
  //===========================================================================

  class GME_Export Folder : public Object
  {
  public:
    Folder (void);
    Folder (IMgaFolder * folder);
    Folder (const Folder & folder);
    virtual ~Folder (void);

    const Folder & operator = (const Folder & folder);
    void attach (IMgaFolder * folder);

    std::vector <FCO> fcos (void) const;
    std::vector <Folder> folders (void) const;

    std::vector <FCO> fcos (const std::string & type) const;
    std::vector <Atom> atoms (const std::string & type) const;
    std::vector <Model> models (const std::string & type) const;
    std::vector <Set> sets (const std::string & type) const;

  private:
    IMgaFolder * impl (void) const;

    /// Helper method that gets the children of a specified \a type
    /// and returns them as the specified GME type (i.e., Model, FCO,
    /// Atom, and etc). This function can only be used by folders and
    /// models. All other will not compile since they do not define
    /// the appropriate methods.
    template <typename T>
    std::vector <T> get_children (const std::string & type) const;

    mutable CComPtr <IMgaFolder> folder_;
  };
}

#endif  // !defined _GME_FOLDER_H_
