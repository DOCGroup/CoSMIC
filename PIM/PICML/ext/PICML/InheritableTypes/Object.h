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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentType/Provideable.h"
#include "PICML/IdTags/Prefixable.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Object_Impl;
  typedef Object_Impl * Object_in;
  typedef ::GAME::Mga::Smart_Ptr < Object_Impl > Object;

  // Forward decl.
  class Visitor;

  /**
   * @class Object_Impl
   *
   * Implementation for the Object model element.
   */
  class PICML_Export Object_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual Provideable_Impl,
    public virtual Prefixable_Impl,
    public virtual HasOperations_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Object _create (const Package_in parent);
    static Object _create (const File_in parent);
    ///@}

    // Default constructor.
    Object_Impl (void);

    // Initializing constructor.
    Object_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Object_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of InterfaceSemantics
    void InterfaceSemantics (const std::string & val);

    /// Get the value of InterfaceSemantics
    std::string InterfaceSemantics (void) const;

    /// Set the value of SupportsAsync
    void SupportsAsync (bool val);

    /// Get the value of SupportsAsync
    bool SupportsAsync (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Object.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_OBJECT
