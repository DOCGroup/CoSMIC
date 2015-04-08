// -*- C++ -*-

//============================================================================
/**
 * @file    Enum.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_ENUM_H_
#define _PICML_NAMEDTYPES_ENUM_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/Common/SimpleType.h"
#include "PICML/InterfaceDefinition/ConstantType.h"
#include "PICML/NamedTypes/NoInheritable.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Enum_Impl;
  typedef Enum_Impl * Enum_in;
  typedef ::GAME::Mga::Smart_Ptr < Enum_Impl > Enum;

  // Forward decl.
  class Visitor;

  /**
   * @class Enum_Impl
   *
   * Implementation for the Enum model element.
   */
  class PICML_Export Enum_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual SimpleType_Impl,
    public virtual ConstantType_Impl,
    public virtual NoInheritable_Impl
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
    static Enum _create (const HasOperations_in parent);
    static Enum _create (const Package_in parent);
    static Enum _create (const File_in parent);
    ///@}

    // Default constructor.
    Enum_Impl (void);

    // Initializing constructor.
    Enum_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Enum_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_EnumValues (std::vector <EnumValue> & items) const;
    ::GAME::Mga::Collection_T <EnumValue> get_EnumValues (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Enum.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_ENUM
