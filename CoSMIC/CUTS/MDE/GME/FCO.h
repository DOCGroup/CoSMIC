// -*- C++ -*-

//=============================================================================
/**
 * @file      FCO.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_FCO_H_
#define _GME_FCO_H_

#include "Object.h"

namespace GME
{
  //=============================================================================
  /**
   * @class FCO
   *
   * Wrapper class for the IMgaFCO interface.
   */
  //=============================================================================
  class GME_Export FCO : public Object
  {
  public:
    /// Type definition of the COM pointer type.
    typedef IMgaFCO _type;

    /// Default constructor.
    FCO (void);

    /**
     * Initializing constructor.
     *
     * @param[in]     fco         Pointer to the source FCO.
     */
    FCO (IMgaFCO * fco);

    /**
     * Copy constructor.
     *
     * @param[in]     fco         Reference to the source FCO.
     */
    const FCO (const FCO & fco);

    /// Destructor.
    virtual ~FCO (void);

    /**
     * Determine if the FCO is an instance.
     *
     * @retval        true        FCO is an instance.
     * @retval        false       FCO is not an instance.
     */
    bool is_instance (void) const;

    /**
     * Determine if the FCO is the first derivation of anohter
     * object. If there object is not a subtype, this will always
     * return \a false.
     *
     * @retval        true        FCO is a first derivation.
     * @retval        false       FCO is not a first derivation.
     */
    bool is_primary_derived (void) const;

    /**
     * Assignment operator.
     *
     * @param[in]     fco         The source FCO object.
     * @return        Reference to this object.
     */
    const FCO & operator = (const FCO & fco);

    /**
     * Attach the object to another interface.
     *
     * @param[in]     fco         The source FCO.
     */
    void attach (IMgaFCO * fco);

    /**
     * Convert this object into a IMgaFCO pointer.
     *
     * @return        IMgaFCO pointer of this object.
     */
    operator IMgaFCO * (void) const;

  protected:
    /**
     * Helper method to return this IMgaFCO implementation from
     * the object interface. This operation then caches the interface
     * for future usage, as long as the underlying object doesn't
     * change. Otherwise, the interface has to be re-cached.
     *
     * @return      Pointer to the FCO implementation.
     */
    IMgaFCO * impl (void) const;

    /// The COM pointer for the FCO type.
    mutable CComPtr <IMgaFCO> fco_;
  };
}

#endif  // !define _GME_FCO_H_
