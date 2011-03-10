// -*- C++ -*-

//============================================================================
/**
 * @file    InEventPortInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_INEVENTPORTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_INEVENTPORTINSTANCE_H_

#include "game/mga/Reference.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InEventPortInstance_Impl;
  typedef InEventPortInstance_Impl * InEventPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <InEventPortInstance_Impl> InEventPortInstance;

  // Forward decl.
  class Visitor;

  class PICML_Export InEventPortInstance_Impl :
    public virtual PortInstance_Impl,
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
    InEventPortInstance_Impl (void);

    /// Initializing constructor
    InEventPortInstance_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~InEventPortInstance_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
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
