// -*- C++ -*-

//============================================================================
/**
 * @file    WorkerPackageBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERPACKAGEBASE_H_
#define _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERPACKAGEBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkerPackageBase_Impl;
  typedef WorkerPackageBase_Impl * WorkerPackageBase_in;
  typedef ::GAME::Mga::Smart_Ptr < WorkerPackageBase_Impl > WorkerPackageBase;

  /**
   * @class WorkerPackageBase_Impl
   *
   * Implementation for the WorkerPackageBase model element.
   */
  class PICML_Export WorkerPackageBase_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    WorkerPackageBase_Impl (void);

    // Initializing constructor.
    WorkerPackageBase_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~WorkerPackageBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Workers (std::vector <Worker> & items) const;
    ::GAME::Mga::Collection_T <Worker> get_Workers (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "WorkerPackageBase.inl"
#endif

#endif  // !defined _PICML_WORKLOADPARADIGMSHEETS_WML_WORKERPACKAGEBASE
