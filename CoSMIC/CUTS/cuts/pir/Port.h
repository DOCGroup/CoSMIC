#ifndef _CUTS_PIR_PORT_H_
#define _CUTS_PIR_PORT_H_

#include "cuts/pir/Reference_Element.h"

namespace CUTS_PIR
{
  //===========================================================================
  /**
   *
   */
  //===========================================================================

  class CUTS_Export Port :
    virtual public Reference_Element
  {
  public:
    /// Constructor.
    Port (void);

    /// Destructor.
    virtual ~Port (void);

  private:
    Port (const Port & port);
    const Port & operator = (const Port & port);
  };
}

#endif  // !defined _CUTS_PIR_PORT_H_
