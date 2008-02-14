// -*- C++ -*-

//=============================================================================
/**
 * @file        MetaModel.h
 *
 * Defines the GME::Meta::Model class
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_METAMODEL_H_
#define _GME_METAMODEL_H_

#include "MetaFCO.h"

namespace GME
{
namespace Meta
{
  /// Forward decl.
  class Role;

  //===========================================================================
  /**
   * @class Model
   *
   * Wrapper class for the IMgaMetaModel COM interface.
   */
  //===========================================================================

  class GME_Export Model : public FCO
  {
  public:
    /// Type definition of COM type.
    typedef IMgaMetaModel interface_type;

    /**
     * Extract the meta model object from the base meta object.
     *
     * @param[in]       meta        Source meta object.
     * @return          Extracted meta model object.
     */
    static Model _narrow (Base & meta);

    /// Default constructor.
    Model (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       meta        Pointer to the COM interface.
     */
    Model (IMgaMetaModel * meta);

    /**
     * Copy constructor.
     *
     * @param[in]       model       Source object.
     */
    Model (const Model & model);

    /// Destructor.
    virtual ~Model (void);

    /**
     * Asssignment operator.
     *
     * @param[in]       meta        Source object.
     * @return          Reference to self.
     */
    const Model & operator = (const Model & meta);

    /**
     * Conversion operator.
     *
     * @return          Pointer to the COM interface.
     */
    operator IMgaMetaModel * (void) const;

    /**
     * Get the role by name.
     *
     * @param[in]       name        Name of the role.
     * @return          The role for the specified \a name.
     */
    Role role (const std::string & name) const;

    /**
     * Get the underlying COM interface pointer.
     *
     * @return          COM interface pointer.
     */
    IMgaMetaModel * impl (void) const;

  private:
    /// Pointer to the raw COM interface.
    mutable CComPtr <IMgaMetaModel> metamodel_;
  };
}
}

#if defined (__GME_INLINE__)
#include "MetaModel.inl"
#endif

#endif  // !defined _GME_METAMODEL_H_
