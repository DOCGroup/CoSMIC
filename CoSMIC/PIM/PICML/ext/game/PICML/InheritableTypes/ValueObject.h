// -*- C++ -*-

//============================================================================
/**
 * @file    ValueObject.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_VALUEOBJECT_H_
#define _PICML_INHERITABLETYPES_VALUEOBJECT_H_

#include "game/mga/Model.h"
#include "PICML/InheritableTypes/ObjectByValue.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ValueObject_Impl;
  typedef ValueObject_Impl * ValueObject_in;
  typedef ::GAME::Mga::Smart_Ptr <ValueObject_Impl> ValueObject;

  // Forward decl.
  class Visitor;

  class PICML_Export ValueObject_Impl :
    public virtual ObjectByValue_Impl,
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
    ValueObject_Impl (void);

    /// Initializing constructor
    ValueObject_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~ValueObject_Impl (void);

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
