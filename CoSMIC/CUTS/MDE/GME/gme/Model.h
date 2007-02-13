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

#include "Folder_Model_T.h"

namespace GME
{
  //===========================================================================
  /**
   * @class Model
   *
   * Wrapper class for the IMgaModel interface.
   */
  //===========================================================================

  class GME_Export Model :
    public Folder_Model_T <IMgaModel, FCO>
  {
    /// Type definition of the base type.
    typedef Folder_Model_T <IMgaModel, FCO> _base_type;

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

    /**
     * Assignment operator.
     *
     * @param[in]       model       The source object.
     * @return          Reference to this object.
     */
    const Model & operator = (const Model & model);
  };
}

#endif // !defined _GME_MODEL_H_
