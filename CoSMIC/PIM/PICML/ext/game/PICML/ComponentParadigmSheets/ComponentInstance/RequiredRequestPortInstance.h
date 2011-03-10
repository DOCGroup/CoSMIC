// -*- C++ -*-

//============================================================================
/**
 * @file    RequiredRequestPortInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_REQUIREDREQUESTPORTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_REQUIREDREQUESTPORTINSTANCE_H_

#include "game/mga/Reference.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequiredRequestPortInstance_Impl;
  typedef RequiredRequestPortInstance_Impl * RequiredRequestPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <RequiredRequestPortInstance_Impl> RequiredRequestPortInstance;

  // Forward decl.
  class Visitor;

  class PICML_Export RequiredRequestPortInstance_Impl :
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
    RequiredRequestPortInstance_Impl (void);

    /// Initializing constructor
    RequiredRequestPortInstance_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~RequiredRequestPortInstance_Impl (void);

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
