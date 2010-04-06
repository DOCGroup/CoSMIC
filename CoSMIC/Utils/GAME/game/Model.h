// -*- C++ -*-

//=============================================================================
/**
 * @file      Model.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_MODEL_H_
#define _GME_MODEL_H_

#include "GME_fwd.h"
#include "FCO.h"
#include "Collection_T.h"

namespace GME
{
  /**
   * @class Model
   *
   * Wrapper class for the IMgaModel interface.
   */
  class GME_Export Model : public GME::FCO
  {
  public:
    /// Type definition of the COM interface.
    typedef IMgaModel interface_type;

    /**
     * Convert a FCO into a Model.
     *
     * @param[in]       fco           The source FCO object.
     * @return          The model object.
     */
    static Model _narrow (const GME::Object & object);

    /**
     * Create a new model element.
     *
     * @param[in]       type          The role of the new object, i.e.,
     *                                its meta name.
     * @param[in]       parent        The parent model.
     * @return          The newly created model.
     */
    static Model _create (Model & parent, const std::string & type);

    static Model _create (Model & parent, const Meta::Role & role);

    /**
     * Create a new model element.
     *
     * @param[in]       type          The model's type.
     * @param[in]       parent        Parent folder of the model.
     * @return          The newly created model.
     */
    static Model _create (Folder & parent, const std::string & type);

    static Model _create (Folder & parent, const Meta::FCO & type);

    /// Default constructor.
    Model (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       model       The source interface.
     */
    Model (IMgaModel * model);

    /**
     * Copy constructor.
     *
     * @param[in]       model       The source model.
     */
    Model (const Model & model);

    /// Destructor.
    virtual ~Model (void);

    /**
     * Assignment operator.
     *
     * @param[in]       model       The source object.
     * @return          Reference to this object.
     */
    const Model & operator = (const Model & model);

    /**
     * Get the meta information for this model.
     *
     * @return      The meta information for the model.
     */
    Meta::Model meta (void) const;

    virtual void accept (GME::Visitor & visitor);

    /**
     * Get all the first-level child folders of this folder.
     *
     * @return      Collection of folder objects.
     */
    size_t children (const std::string & type,
                     std::vector <GME::Folder> & folders) const;

    size_t children (std::vector <GME::FCO> & children) const;

    size_t children (const std::string & type,
                     std::vector <GME::FCO> & children) const;

    size_t children (const std::string & type,
                     std::vector <GME::Atom> & children) const;

    size_t children (const std::string & type,
                     std::vector <GME::Model> & children) const;

    size_t children (const std::string & type,
                     std::vector <GME::Reference> & children) const;

    size_t children (const std::string & type,
                     std::vector <GME::Set> & children) const;

    void Model::attach (IMgaModel * model);

    /// Helper method to get the correct implementation.
    IMgaModel * impl (void) const;

  private:
    /// Pointer to the underlying COM interface.
    mutable ATL::CComPtr <IMgaModel> model_;
  };
}

#if defined (__GME_INLINE__)
#include "Model.inl"
#endif

#endif // !defined _GME_MODEL_H_
