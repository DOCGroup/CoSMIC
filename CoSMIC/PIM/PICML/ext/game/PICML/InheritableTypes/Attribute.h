// -*- C++ -*-

//============================================================================
/**
 * @file    Attribute.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_ATTRIBUTE_H_
#define _PICML_INHERITABLETYPES_ATTRIBUTE_H_

#include "game/mga/Model.h"
#include "PICML/InheritableTypes/ReadonlyAttribute.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Attribute_Impl;
  typedef Attribute_Impl * Attribute_in;
  typedef ::GAME::Mga::Smart_Ptr <Attribute_Impl> Attribute;

  // Forward decl.
  class Visitor;

  class PICML_Export Attribute_Impl :
    public virtual ReadonlyAttribute_Impl,
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Attribute_Impl (void);

    /// Initializing constructor
    Attribute_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Attribute_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_SetExceptions (std::vector <SetException> & items) const;
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
