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

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class WorkerPackageBase_Impl;
  typedef WorkerPackageBase_Impl * WorkerPackageBase_in;
  typedef ::GAME::Mga::Smart_Ptr <WorkerPackageBase_Impl> WorkerPackageBase;

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

    /// Default constructor
    WorkerPackageBase_Impl (void);

    /// Initializing constructor
    WorkerPackageBase_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~WorkerPackageBase_Impl (void) = 0;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Workers (std::vector <Worker> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
