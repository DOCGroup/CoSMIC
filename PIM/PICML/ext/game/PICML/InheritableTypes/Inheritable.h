// -*- C++ -*-

//============================================================================
/**
 * @file    Inheritable.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_INHERITABLE_H_
#define _PICML_INHERITABLETYPES_INHERITABLE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/NamedType.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Inheritable_Impl;
  typedef Inheritable_Impl * Inheritable_in;
  typedef ::GAME::Mga::Smart_Ptr < Inheritable_Impl > Inheritable;

  /**
   * @class Inheritable_Impl
   *
   * Implementation for the Inheritable model element.
   */
  class PICML_Export Inheritable_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual NamedType_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    Inheritable_Impl (void);

    // Initializing constructor.
    Inheritable_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Inheritable_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const;
    ::GAME::Mga::Iterator <ReadonlyAttribute> get_ReadonlyAttributes (void) const;

    size_t get_Attributes (std::vector <Attribute> & items) const;
    ::GAME::Mga::Iterator <Attribute> get_Attributes (void) const;

    size_t get_Inheritss (std::vector <Inherits> & items) const;
    ::GAME::Mga::Iterator <Inherits> get_Inheritss (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Inheritable.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_INHERITABLE
