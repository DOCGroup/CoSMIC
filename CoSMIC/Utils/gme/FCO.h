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

#include "GME_fwd.h"
#include "Object.h"
#include "Collection_T.h"

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

    /**
     * Create a new atom element.
     *
     * @param[in]       role          The role of the new object, i.e.,
     *                                its meta name.
     * @param[in]       parent        The parent model.
     * @return          The newly created atom.
     */
    static FCO _create (const std::string & role, Model & parent);

    /**
     * Extract an FCO object from the GME object.
     *
     * @param[in]       object        The source object.
     * @return          The FCO version of the object, if applicable.
     */
    static FCO _narrow (const GME::Object & object);

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
     * Get the instance type.
     *
     * @retval        The instance's type. NULL if the object is
     *                not an instance.
     */
    FCO instance_type (void) const;

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

    /**
     * Get the meta information for this object.
     *
     * @return        Its meta information.
     */
    Meta::FCO meta (void) const;

    /**
     * Get the meta information about its role.
     *
     * @return        Its role's meta information.
     */
    Meta::Role role (void) const;

    /**
     * Helper method to return this IMgaFCO implementation from
     * the object interface. This operation then caches the interface
     * for future usage, as long as the underlying object doesn't
     * change. Otherwise, the interface has to be re-cached.
     *
     * @return      Pointer to the FCO implementation.
     */
    IMgaFCO * impl (void) const;

    /**
     * Create a new instance of the a model.
     *
     * @param[in]       role          The role of the new object, i.e.,
     *                                its meta name.
     * @param[in]       parent        The parent model.
     * @return          The newly created model.
     */
    FCO create_instance (Model & parent);

    /**
     * Create a new model element.
     *
     * @param[in]       role          The role of the new object, i.e.,
     *                                its meta name.
     * @param[in]       parent        The parent model.
     * @return          The newly created model.
     */
    FCO create_subtype (Model & parent);

    /**
     * Get the archetype for the object. The archetype is the top
     * most basetype in a multi-hierarchial derivation tree.
     *
     * @return      The archetype of the object.
     */
    FCO archetype (void) const;

    /**
     * Determine if the object is a subtype.
     *
     * @retval      true      It is a subtype.
     * @retval      false     It is not a subtype.
     */
    bool is_subtype (void) const;

    /**
     * Get the basetype for the object. The base type is the closet
     * object that the current object is derived from in a multi-
     * hierarchial derivation tree.
     *
     * @return      The basetype for the object.
     */
    FCO basetype (void) const;

    /**
     * Get a registry value.
     *
     * @param[in]   path      The path of the value.
     * @return      The value stored at \a path.
     */
    std::string registry_value (const std::string & path) const;

    /**
     * Set a registry value.
     *
     * @param[in]   path      The path of the value.
     * @param[in]   value     The new value of \a path.
     */
    void registry_value (const std::string & path, const std::string & value);

    /**
     * Get the attributes of the FCO.
     *
     * @param[out]  attrs     The attributes of the FCO.
     * @return      Number of attributes.
     */
    size_t attributes (Collection_T <Attribute> & attrs) const;

    /**
     * Get the parent of the FCO, which is a model.
     *
     * @return      Parent folder object.
     */
    Model parent_model (void) const;

    /**
     * Get the parent of the FCO, which is a folder.
     *
     * @return      Parent model object.
     */
    Folder parent_folder (void) const;

  private:
    /// The COM pointer for the FCO type.
    mutable CComPtr <IMgaFCO> fco_;
  };
}

#endif  // !define _GME_FCO_H_
