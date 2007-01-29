// -*- C++ -*-

#ifndef _GME_OBJECT_H_
#define _GME_OBJECT_H_

#include "MetaBase.h"
#include <vector>

namespace GME
{
  class GME_Export Object
  {
  public:
    Object (void);
    Object (IMgaObject * object);
    Object (const Object & obj);
    virtual ~Object (void);

    void attach (IMgaObject * object);
    const Object & operator = (const Object & object);

    std::string id (void) const;

    long relative_id (void) const;
    void relative_id (long relid);

    bool is_writable (void) const;
    bool is_lib_object (void) const;

    long status (void) const;

    void check (void);
    void check_tree (void);

    std::string name (void) const;
    void name (const std::string & name);

    std::string path (const std::string & separator,
                      bool leading_separator = true) const;

    std::string absolute_path (void) const;

    bool exempt (void) const;
    void exempt (bool exempt);

    void readonly_access (bool readonly, bool propagate);
    bool readonly_access (void) const;

    MetaBase meta (void) const;

    objtype_enum type (void) const;

    operator bool (void);

    Object parent (void) const;

  protected:
    CComPtr <IMgaObject> object_;
  };
}

#endif  // !defined _GME_OBJECT_H_
