// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_ATTRIBUTEINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_ATTRIBUTEINSTANCE_H_

#include "game/mga/Reference.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeInstance_Impl;
  typedef AttributeInstance_Impl * AttributeInstance_in;
  typedef ::GAME::Mga::Smart_Ptr <AttributeInstance_Impl> AttributeInstance;

  // Forward decl.
  class Visitor;

  class PICML_Export AttributeInstance_Impl :
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
    AttributeInstance_Impl (void);

    /// Initializing constructor
    AttributeInstance_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~AttributeInstance_Impl (void);

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
