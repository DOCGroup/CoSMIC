// -*- C++ -*-

//============================================================================
/**
 * @file    Constant.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_CONSTANT_H_
#define _PICML_INTERFACEDEFINITION_CONSTANT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/IdTags/Taggable.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Constant_Impl;
  typedef Constant_Impl * Constant_in;
  typedef ::GAME::Mga::Smart_Ptr < Constant_Impl > Constant;

  // Forward decl.
  class Visitor;

  /**
   * @class Constant_Impl
   *
   * Implementation for the Constant model element.
   */
  class PICML_Export Constant_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual Taggable_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Constant _create (const Package_in parent);
    static Constant _create (const File_in parent);
    static Constant _create (const HasOperations_in parent);
    ///@}

    // Default constructor.
    Constant_Impl (void);

    // Initializing constructor.
    Constant_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~Constant_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Package parent_Package (void);
    File parent_File (void);
    HasOperations parent_HasOperations (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of value
    void value (const std::string & val);

    /// Get the value of value
    std::string value (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ConstantType_is_nil (void) const;
    ConstantType refers_to_ConstantType (void) const;
    void refers_to_ConstantType (ConstantType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Constant.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_CONSTANT
