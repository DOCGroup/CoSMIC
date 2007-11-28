// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaFCO.h
 *
 * Defines the GME::Meta::FCO object.
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_METAFCO_H_
#define _GME_METAFCO_H_

#include "MetaBase.h"

namespace GME
{
namespace Meta
{
  //===========================================================================
  /**
   * @class FCO
   *
   * Wrapper class for the IMgaMetaFCO interface.
   */
  //===========================================================================

  class GME_Export FCO : public Base
  {
  public:
    /// Type definition of the interface pointer.
    typedef IMgaMetaFCO _type;

    /// Default constructor.
    FCO (void);

    /**
     * Initializing constructor.
     *
     * @param[in]     meta        Pointer to the meta information.
     */
    FCO (IMgaMetaFCO * meta);

    /**
     * Copy constructor.
     *
     * @param[in]     meta        The source object.
     */
    FCO (const FCO & meta);

    /// Destructor.
    virtual ~FCO (void);

    /**
     * Assignment operator.
     *
     * @param[in]     meta        The source object.
     * @return        Reference to this object.
     */
    const FCO & operator = (const FCO & meta);

    /**
     * Convert this object into a IMgaMetaFCO pointer.
     *
     * @return        IMgaMetaFCO pointer.
     */
    operator IMgaMetaFCO * (void) const;

    /**
     * Get the meta object this FCO is defined in.
     *
     * @return        Base meta object.
     */
    Base defined_in (void) const;

  protected:
    /// Helper method to the correct implementation.
    IMgaMetaFCO * impl (void) const;

  private:
    /// Cached pointer to the implementation.
    mutable CComPtr <IMgaMetaFCO> meta_fco_;
  };
}
}

#if defined (__GME_INLINE__)
#include "MetaFCO.inl"
#endif

#endif  // !defined _GME_METAFCO_H_
