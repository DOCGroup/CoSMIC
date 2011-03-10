// -*- C++ -*-

//============================================================================
/**
 * @file    InEventPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_INEVENTPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_INEVENTPORT_H_

#include "game/mga/Reference.h"
#include "PICML/ComponentParadigmSheets/ComponentType/EventPort.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InEventPort_Impl;
  typedef InEventPort_Impl * InEventPort_in;
  typedef ::GAME::Mga::Smart_Ptr <InEventPort_Impl> InEventPort;

  // Forward decl.
  class Visitor;

  class PICML_Export InEventPort_Impl :
    public virtual EventPort_Impl,
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
    InEventPort_Impl (void);

    /// Initializing constructor
    InEventPort_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~InEventPort_Impl (void);

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
    EventType refers_to_EventType (void) const;
    ///@}
  };
}

#endif
