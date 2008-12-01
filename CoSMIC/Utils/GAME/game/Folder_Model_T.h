// -*- C++ -*-

//=============================================================================
/**
 * @file      Folder_Model_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_FOLDER_MODEL_T_H_
#define _GME_FOLDER_MODEL_T_H_

#include "GME_fwd.h"
#include "Exception.h"
#include "Collection_T.h"

namespace GME
{
  //=============================================================================
  /**
   * @class Folder_Model_T
   *
   * Template class that contains common methods for Folder and Model
   * elements in GME. This class helps reduce code duplication.
   */
  //=============================================================================

  template <typename T, typename BASE>
  class Folder_Model_T : public BASE
  {
  public:
    /// Destructor.
    virtual ~Folder_Model_T (void);

    /**
     * Attach to an existing object.
     *
     * @param[in]     type    Pointer to the object.
     */
    void attach (T * type);

    /**
     * Get all the FCOs of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @param[out]  fcos      Collection of FCOs of the specified \a type.
     * @return      Number of FCOs returned \a fcos.
     */
    size_t fcos (const std::string & type,
                 GME::Collection_T <FCO> & fcos) const;

    /**
     * Get all the atoms of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @return      Collection of atoms of the specified \a type.
     */
    size_t atoms (const std::string & type,
                  GME::Collection_T <Atom> & atoms) const;

    /**
     * Get all the models of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @param[out]  models    Collection of models of the specified \a type.
     * @return      Number of elements in \a models.
     */
    size_t models (const std::string & type,
                   GME::Collection_T <Model> & models) const;

    /**
     * Get all the sets of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @param[out]  sets      Collection of sets of the specified \a type.
     * @return      Number of elements in \a sets.
     */
    size_t sets (const std::string & type,
                 GME::Collection_T <Set> & sets) const;

    /**
     * Get all the references of a particular \a type.
     *
     * @param[in]   type      The target type.
     * @param[out]  refs      Collection of references of the specified \a type.
     * @return      Number of elements in \a refs.
     */
    size_t references (const std::string & type,
                       GME::Collection_T <Reference> & refs) const;

    /**
     * Helper method to get the correct implementation.
     *
     * @return          Pointer to the implementation.
     */
    T * impl (void) const;

  protected:
    /// Default constructor.
    Folder_Model_T (void);

    /**
     * Initializing constructor.
     *
     * @param[in]     type      Pointer to the object.
     */
    Folder_Model_T (T * type);

    /**
     * Copy constructor.
     *
     * @param[in]       type    The source object.
     */
    Folder_Model_T (const Folder_Model_T & type);

    /// Helper method that gets the children of a specified \a type
    /// and returns them as the specified GME type (i.e., Model, FCO,
    /// Atom, and etc). This function can only be used by folders and
    /// models. All other will not compile since they do not define
    /// the appropriate methods.
    template <typename T2>
    size_t get_children (const std::string & type,
                         GME::Collection_T <T2> & children) const;

    /// Cached pointer to the implementation.
    mutable ATL::CComPtr <T> type_;
  };
}

#if defined (__GME_INLINE__)
#include "Folder_Model_T.inl"
#endif

#include "Folder_Model_T.cpp"

#endif  // !defined _GME_FOLDER_MODEL_T_H_
