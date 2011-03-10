// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendedPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EXTENDEDPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EXTENDEDPORT_H_

#include "game/mga/Reference.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPortBase.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedPort_Impl;
  typedef ExtendedPort_Impl * ExtendedPort_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedPort_Impl> ExtendedPort;

  // Forward decl.
  class Visitor;

  class PICML_Export ExtendedPort_Impl :
    public virtual ExtendedPortBase_Impl,
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
    ExtendedPort_Impl (void);

    /// Initializing constructor
    ExtendedPort_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ExtendedPort_Impl (void);

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
