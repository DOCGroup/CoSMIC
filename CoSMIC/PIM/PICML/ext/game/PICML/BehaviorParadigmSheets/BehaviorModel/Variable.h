// -*- C++ -*-

//============================================================================
/**
 * @file    Variable.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_BEHAVIORMODEL_VARIABLE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_BEHAVIORMODEL_VARIABLE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Variable_Impl;
  typedef Variable_Impl * Variable_in;
  typedef ::GAME::Mga::Smart_Ptr <Variable_Impl> Variable;

  // Forward decl.
  class Visitor;

  class PICML_Export Variable_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Variable_Impl (void);

    /// Initializing constructor
    Variable_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~Variable_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Variable _create (const BehaviorModel_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of InitialValue
    void InitialValue (const std::string & val);

    /// Get the value of InitialValue
    std::string InitialValue (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    BehaviorModel parent_BehaviorModel (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
