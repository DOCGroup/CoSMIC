// -*- C++ -*-

//============================================================================
/**
 * @file    ProvidedRequestPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PROVIDEDREQUESTPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PROVIDEDREQUESTPORT_H_

#include "game/mga/Reference.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ObjectPort.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ProvidedRequestPort_Impl;
  typedef ProvidedRequestPort_Impl * ProvidedRequestPort_in;
  typedef ::GAME::Mga::Smart_Ptr <ProvidedRequestPort_Impl> ProvidedRequestPort;

  // Forward decl.
  class Visitor;

  class PICML_Export ProvidedRequestPort_Impl :
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
    ProvidedRequestPort_Impl (void);

    /// Initializing constructor
    ProvidedRequestPort_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ProvidedRequestPort_Impl (void);

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
    Provideable refers_to_Provideable (void) const;
    ///@}
  };
}

#endif
