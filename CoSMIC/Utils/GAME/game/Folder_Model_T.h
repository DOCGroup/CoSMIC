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
     * Get all the FCOs contained by this element.
     */
    size_t fcos (GME::Collection_T <FCO> & fcos);

    template <typename CHILD>
    size_t children (const std::string & type,
                     GME::Collection_T <CHILD> & children) const;

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

    /// Cached pointer to the implementation.
    mutable ATL::CComPtr <T> type_;
  };
}

#if defined (__GME_INLINE__)
#include "Folder_Model_T.inl"
#endif

#include "Folder_Model_T.cpp"

#endif  // !defined _GME_FOLDER_MODEL_T_H_
