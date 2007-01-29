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

namespace GME
{
  //===========================================================================
  /**
   * @class Model
   *
   * Wrapper class for the IMgaModel interface.
   */
  //===========================================================================

  class GME_Export Model : public FCO
  {
  public:
    /// Type definition of the COM interface.
    typedef IMgaModel _type;

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

    const Model & operator = (const Model & model);

    /**
     * Attach to an existing model interface.
     *
     * @param[in]       model       The source interface.
     */
    void attach (IMgaModel * model);

    /**
     * Get all the FCOs of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @return      Collection of FCOs of the specified \a type.
     */
    std::vector <FCO> fcos (const std::string & type) const;

    /**
     * Get all the atoms of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @return      Collection of atoms of the specified \a type.
     */
    std::vector <Atom> atoms (const std::string & type) const;

    /**
     * Get all the models of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @return      Collection of models of the specified \a type.
     */
    std::vector <Model> models (const std::string & type) const;

    /**
     * Get all the sets of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @return      Collection of sets of the specified \a type.
     */
    std::vector <Set> sets (const std::string & type) const;

    /**
     * Get all the references of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @return      Collection of references of the specified \a type.
     */
    std::vector <Reference> references (const std::string & type) const;

  protected:
    /// Helper method that gets the children of a specified \a type
    /// and returns them as the specified GME type (i.e., Model, FCO,
    /// Atom, and etc). This function can only be used by folders and
    /// models. All other will not compile since they do not define
    /// the appropriate methods.
    template <typename T>
    std::vector <T> get_children (const std::string & type) const;

    /// Helper method to return the correct implementation.
    IMgaModel * impl (void) const;

    /// The underlying COM interface pointer.
    mutable CComPtr <IMgaModel> model_;
  };
}

#endif // !defined _GME_MODEL_H_
