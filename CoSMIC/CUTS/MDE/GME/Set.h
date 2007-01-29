#ifndef _GME_SET_H_
#define _GME_SET_H_

#include "FCO.h"

namespace GME
{
  //===========================================================================
  /**
   * @class Folder
   */
  //===========================================================================

  class GME_Export Set : public FCO
  {
  public:
    typedef IMgaSet _type;

    /// Default constructor.
    Set (void);

    Set (IMgaSet * set);

    /**
     * Copy constructor.
     *
     * @param[in]       set       The source set.
     */
    Set (const Set & set);

    /// Destructor.
    virtual ~Set (void);

    /**
     * Assignment operator.
     *
     * @param[in]     set         The source set.
     * @return        Reference to this object.
     */
    const Set & operator = (const Set & set);

    void insert (const FCO & fco);
    void remove (const FCO & fco);

    bool contains (const FCO & fco);

    void clear (void);

    std::vector <FCO> members (void) const;

  protected:
    IMgaSet * impl (void) const;
    mutable CComPtr <IMgaSet> set_;
  };
}
#endif  // !defined _GME_SET_H_
