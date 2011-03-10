// -*- C++ -*-

//============================================================================
/**
 * @file    Object.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_OBJECT_H_
#define _PICML_INHERITABLETYPES_OBJECT_H_

#include "game/mga/Model.h"
#include "PICML/InheritableTypes/HasOperations.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Object_Impl;
  typedef Object_Impl * Object_in;
  typedef ::GAME::Mga::Smart_Ptr <Object_Impl> Object;

  // Forward decl.
  class Visitor;

  class PICML_Export Object_Impl :
    public virtual HasOperations_Impl,
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
    Object_Impl (void);

    /// Initializing constructor
    Object_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Object_Impl (void);

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

    /// Set the value of SupportsAsync
    void SupportsAsync (bool val);

    /// Get the value of SupportsAsync
    bool SupportsAsync (void) const;

    /// Set the value of InterfaceSemantics
    void InterfaceSemantics (const std::string & val);

    /// Get the value of InterfaceSemantics
    std::string InterfaceSemantics (void) const;
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
