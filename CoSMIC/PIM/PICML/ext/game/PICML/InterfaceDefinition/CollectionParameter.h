// -*- C++ -*-

//============================================================================
/**
 * @file    CollectionParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_COLLECTIONPARAMETER_H_
#define _PICML_INTERFACEDEFINITION_COLLECTIONPARAMETER_H_

#include "game/mga/Reference.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CollectionParameter_Impl;
  typedef CollectionParameter_Impl * CollectionParameter_in;
  typedef ::GAME::Mga::Smart_Ptr <CollectionParameter_Impl> CollectionParameter;

  // Forward decl.
  class Visitor;

  class PICML_Export CollectionParameter_Impl :
    public virtual TemplateParameter_Impl,
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
    CollectionParameter_Impl (void);

    /// Initializing constructor
    CollectionParameter_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~CollectionParameter_Impl (void);

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
    NameParameter refers_to_NameParameter (void) const;
    ///@}
  };
}

#endif
