// -*- C++ -*-

//=============================================================================
/**
 * @file      MetaBase.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_METABASE_H_
#define _GME_METABASE_H_

#include "Exception.h"
#include "Mga.h"

namespace GME
{
  //===========================================================================
  /**
   * @class MetaBase
   *
   * Wrapper class for the IMgaMetaBase interface.
   */
  //===========================================================================

  class GME_Export MetaBase
  {
  public:
    /// Default constructor.
    MetaBase (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       meta        Pointer to the source interface.
     */
    MetaBase (IMgaMetaBase * meta);

    /**
     * Copy constructor.
     *
     * @param[in]       meta        The source object.
     */
    MetaBase (const MetaBase & meta);

    /// Destructor.
    virtual ~MetaBase (void);

    /**
     * Get the actual meta name.
     *
     * @return          The name of the meta object.
     */
    std::string name (void) const;

    /**
     * Get the displayed name for the meta.
     *
     * @return          The displayed name.
     */
    std::string displayed_name (void) const;

    /**
     * Attach to an existing interface.
     *
     * @param[in]       meta        Pointer to the source object.
     */
    void attach (IMgaMetaBase * meta);

    /**
     * Assignment operator.
     *
     * @param[in]       meta        The source meta.
     * @return          Reference to this object.
     */
    const MetaBase & operator = (const MetaBase & meta);

    /**
     * Convert the object to a IMgaMetaBase pointer.
     *
     * @return          Pointer to a IMgaMetaBase object.
     */
    operator IMgaMetaBase * (void) const;

  protected:
    /// The underlying interface pointer.
    CComPtr <IMgaMetaBase> metabase_;
  };
}

#endif  // !defined _GME_METABASE_H_
