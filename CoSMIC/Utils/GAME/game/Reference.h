// -*- C++ -*-

//=============================================================================
/**
 * @file      Reference.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_REFERENCE_H_
#define _GME_REFERENCE_H_

#include "FCO.h"

namespace GME
{
  /**
   * @class Reference
   *
   * Wrapper class for the IMgaReference interface.
   */
  class GME_Export Reference : public FCO
  {
  public:
    /// Type definition of the COM interface.
    typedef IMgaReference interface_type;

    /**
     * Convert a FCO into an atom.
     *
     * @param[in]       fco           The source FCO object.
     * @return          The atom object.
     */
    static Reference _narrow (const GME::Object & object);

    /**
     * Create a new atom element.
     *
     * @param[in]       role          The role of the new object, i.e.,
     *                                its meta name.
     * @param[in]       parent        The parent model.
     * @return          The newly created atom.
     */
    static Reference _create (const std::string & role, Model & parent);

    /// Default constructor.
    Reference (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       ref         The source reference interface.
     */
    Reference (IMgaReference * ref);

    /**
     * Copy constructor.
     *
     * @param[in]       ref         The source object.
     */
    Reference (const Reference & ref);

    /// Destructor.
    virtual ~Reference (void);

    /**
     * Assignment operator
     *
     * @param[in]       ref         The source object.
     * @return          Reference to this object.
     */
    const Reference & operator = (const Reference & ref);

    /**
     * Attach to an preexisting reference interface.
     *
     * @param[in]       ref         The source interface.
     */
    void attach (IMgaReference * ref);

    /**
     * Get the FCO to which this reference refers to.
     *
     * @return          The FCO this reference refers to.
     */
    FCO refers_to (void) const;

    /**
     * Set the FCO to which this reference refers to.
     *
     * @param[in]       fco          The FCO this reference refers to.
     */
    void refers_to (const FCO & fco);

    /**
     * Convert the object to an IMgaReference pointer.
     *
     * @return          The COM interface pointer for this object.
     */
    operator IMgaReference * (void) const;

    virtual void accept (GME::Visitor & visitor);

  private:
    /// Helper method to get the correct implementation.
    IMgaReference * impl (void) const;

    /// Pointer to the underlying COM interface.
    mutable ATL::CComPtr <IMgaReference> ref_;
  };
}

#if defined (__GME_INLINE__)
#include "Reference.inl"
#endif

#endif  // !defined _GME_REFERENCE_H_
