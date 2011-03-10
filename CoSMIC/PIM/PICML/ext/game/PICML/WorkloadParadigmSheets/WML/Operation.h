// -*- C++ -*-

//============================================================================
/**
 * @file    Operation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_WORKLOADPARADIGMSHEETS_WML_OPERATION_H_
#define _PICML_WORKLOADPARADIGMSHEETS_WML_OPERATION_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Operation_Impl;
  typedef Operation_Impl * Operation_in;
  typedef ::GAME::Mga::Smart_Ptr <Operation_Impl> Operation;

  // Forward decl.
  class Visitor;

  class PICML_Export Operation_Impl :
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
    Operation_Impl (void);

    /// Initializing constructor
    Operation_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Operation_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Operation _create (const Worker_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    ReturnType get_ReturnType (void) const;
    size_t get_ParameterTypes (std::vector <ParameterType> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    Worker parent_Worker (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
