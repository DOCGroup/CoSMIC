// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaFCO.h
 *
 * Defines the GAME::Meta::FCO object.
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_METAFCO_H_
#define _GME_METAFCO_H_

#include "MetaAttribute.h"

namespace GAME
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

  class GAME_Export FCO : public Base
  {
  public:
    /// Type definition of the interface pointer.
    typedef IMgaMetaFCO interface_type;

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
     * Get the meta object this FCO is defined in.
     *
     * @return        Base meta object.
     */
    Base defined_in (void) const;

    /**
     * Get an attributes meta information by its name.
     *
     * @param[in]       name        Name of the attribute.
     * @return          Meta information about the attribute.
     */
    Attribute attribute (const std::string & name) const;

    /**
     * Get an attributes meta information by its display name.
     *
     * @param[in]       name        Display name.
     * @return          Meta information about the attribute.
     */
    Attribute attribute_by_display_name (const std::string & name) const;

    /// Helper method to the correct implementation.
    IMgaMetaFCO * impl (void) const;

  private:
    /// Cached pointer to the implementation.
    mutable CComPtr <IMgaMetaFCO> meta_fco_;
  };
}
}

#if defined (__GAME_INLINE__)
#include "MetaFCO.inl"
#endif

#endif  // !defined _GME_METAFCO_H_
