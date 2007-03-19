// -*- C++ -*-

#ifndef _GME_METAFCO_H_
#define _GME_METAFCO_H_

#include "MetaBase.h"

namespace GME
{
  class GME_Export MetaFCO : public MetaBase
  {
  public:
    /// Type definition of the interface pointer.
    typedef IMgaMetaFCO _type;

    /// Default constructor.
    MetaFCO (void);

    /**
     * Initializing constructor.
     *
     * @param[in]     meta        Pointer to the meta information.
     */
    MetaFCO (IMgaMetaFCO * meta);

    /**
     * Copy constructor.
     *
     * @param[in]     meta        The source object.
     */
    MetaFCO (const MetaFCO & meta);

    /// Destructor.
    virtual ~MetaFCO (void);

    /**
     * Assignment operator.
     *
     * @param[in]     meta        The source object.
     * @return        Reference to this object.
     */
    const MetaFCO & operator = (const MetaFCO & meta);

    /**
     * Convert this object into a IMgaMetaFCO pointer.
     *
     * @return        IMgaMetaFCO pointer.
     */
    operator IMgaMetaFCO * (void) const;

    MetaBase defined_in (void) const;

  protected:
    /// Helper method to the correct implementation.
    IMgaMetaFCO * impl (void) const;

  private:
    /// Cached pointer to the implementation.
    mutable CComPtr <IMgaMetaFCO> meta_fco_;
  };
}

#if defined (__GME_INLINE__)
#include "MetaFCO.inl"
#endif

#endif  // !defined _GME_METAFCO_H_
