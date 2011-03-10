// -*- C++ -*-

//============================================================================
/**
 * @file    SupportsInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_SUPPORTSINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_SUPPORTSINSTANCE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SupportsInstance_Impl;
  typedef SupportsInstance_Impl * SupportsInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <SupportsInstance_Impl> SupportsInstance;

  // Forward decl.
  class Visitor;

  class PICML_Export SupportsInstance_Impl :
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
    SupportsInstance_Impl (void);

    /// Initializing constructor
    SupportsInstance_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~SupportsInstance_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static SupportsInstance _create (const ComponentInstance_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentInstance parent_ComponentInstance (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
