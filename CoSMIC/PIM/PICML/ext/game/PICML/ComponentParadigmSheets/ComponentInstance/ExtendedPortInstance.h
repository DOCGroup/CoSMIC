// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendedPortInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_EXTENDEDPORTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_EXTENDEDPORTINSTANCE_H_

#include "game/mga/Reference.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedPortInstance_Impl;
  typedef ExtendedPortInstance_Impl * ExtendedPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedPortInstance_Impl> ExtendedPortInstance;

  // Forward decl.
  class Visitor;

  class PICML_Export ExtendedPortInstance_Impl :
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
    ExtendedPortInstance_Impl (void);

    /// Initializing constructor
    ExtendedPortInstance_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ExtendedPortInstance_Impl (void);

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
