// -*- C++ -*-

//============================================================================
/**
 * @file    RequiredRequestPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_REQUIREDREQUESTPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_REQUIREDREQUESTPORT_H_

#include "game/mga/Reference.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequiredRequestPort_Impl;
  typedef RequiredRequestPort_Impl * RequiredRequestPort_in;
  typedef ::GAME::Mga::Smart_Ptr <RequiredRequestPort_Impl> RequiredRequestPort;

  // Forward decl.
  class Visitor;

  class PICML_Export RequiredRequestPort_Impl :
    public virtual ObjectPort_Impl,
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
    RequiredRequestPort_Impl (void);

    /// Initializing constructor
    RequiredRequestPort_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~RequiredRequestPort_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of AsyncCommunication
    void AsyncCommunication (bool val);

    /// Get the value of AsyncCommunication
    bool AsyncCommunication (void) const;

    /// Set the value of multiple_connections
    void multiple_connections (bool val);

    /// Get the value of multiple_connections
    bool multiple_connections (void) const;
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
    Provideable refers_to_Provideable (void) const;
    ///@}
  };
}

#endif
