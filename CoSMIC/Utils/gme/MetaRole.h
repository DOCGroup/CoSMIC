// -*- C++ -*-

//=============================================================================
/**
 * @file        MetaRole.h
 *
 * Defines the GME::Meta::Role class
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_METAROLE_H_
#define _GME_METAROLE_H_

#include "MetaBase.h"

namespace GME
{
namespace Meta
{
  // Forward decl.
  class Model;

  // Forward decl.
  class FCO;

  //===========================================================================
  /**
   * @class Role
   *
   * Wrapper class for the IMgaMetaRole interface.
   */
  //===========================================================================

  class GME_Export Role : public Base
  {
  public:
    /// Type definition of the COM interface.
    typedef IMgaMetaRole _type;

    /// Default constructor.
    Role (void);

    /**
     * Initializing constructor.
     *
     * @param[in]     role        Pointer to a COM interface.
     */
    Role (IMgaMetaRole * role);

    /**
     * Copy constructor.
     *
     * @param[in]     role        The source object.
     */
    Role (const Role & role);

    /// Destructor.
    virtual ~Role (void);

    /**
     * Assignment operator.
     *
     * @param[in]       role      The source role.
     * @return          Reference to self.
     */
    const Role & operator = (const Role & role);

    /**
     * Get the meta FCO for the role.
     *
     * @return          The meta FCO of the role.
     */
    FCO kind (void) const;

    /**
     * Conversion operator.
     *
     * @return          Pointer to the COM interface.
     */
    operator IMgaMetaRole * (void) const;

    /**
     * Get a raw pointer to the underlying COM object.
     *
     * @return        Pointer to the raw COM object.
     */
    IMgaMetaRole * impl (void) const;

    /**
     * Get the parent model of the role.
     *
     * @return        Parent model of the role.
     */
    Model parent (void) const;

  private:
    /// Pointer to the COM object.
    mutable CComPtr <IMgaMetaRole> metarole_;
  };
}
}

#if defined (__GME_INLINE__)
#include "MetaRole.inl"
#endif

#endif  // !defined _GME_METAROLE_H_
